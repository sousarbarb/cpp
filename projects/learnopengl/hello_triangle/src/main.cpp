#include <iostream>

#include <glad/glad.h>  // must be before GLFW...
#include <GLFW/glfw3.h>





void framebufferSizeCallback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);





/**
 * @brief source of the vertex shader (saved as a global const C string var for
 *        now)
 *
 * #version 330 core
 * since OpengGL3.3, versions of GLSL (OpenGL Shading Language) match OpengGL
 *
 * declare all input vertex attributes in vertex shader with in keyword
 * (for now, we only care about position data)
 *
 * GLSL has vector datatype containing 1 to 4 floats
 *
 * vector in GLSL has a maximum size of 4 and each of its values can be
 * retrieved via vec.x, vec.y, vec.z and vec.w respectively where each of them
 * represents a coordinate in space
 * vec.w not used in position in space >>> using for perspective division!
 *
 * predefined gl_Position variable which is a vec4 behind the scenes
 *
 * given that GPU do not have any default shader, we need to specify. And
 * vertexShaderSrc is the most basic one probably, because we did not process
 * whatsoever on the input data, and simply forwarded it to the shader's output
 *
 * in real applications where the input data is usually not already in NDC, we
 * first have to transform the input data to coordinates that fall within
 * OpenGL's visible region...
 */
const char* vertexShaderSrc =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "  gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";





/**
 * @brief fragment shader to calculate the color output of the pixels
 *
 * to keep it simple, we put the shader to always output the orange color
 *
 * color in computer graphics are array of 4 values: red, green, blue, alpha
 * (opacity component), commonly abbreviated to RGBA.
 *
 * when defining a colot in OpenGL or GLSL, set strenght of each component
 * between 0.0 and 1.0
 *
 * we can declare output values with th out keyword
 */
const char* fragmentShaderSrc =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "  FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\0";





/**
 * @brief hello_triangle
 *
 * one of the main jobs of opengl:
 * - transform 3D coordinates to 2D pixels +
 * - transform 2D coordinates into actual colored pixels
 *
 * graphics pipeline can be easily parallelized >>> GPUs nowdays have thousands
 * of small processing cores to quickly process our date >>> processing cores
 * run small programs on the GPU for each step of the pipeline >>> !!!SHADERS!!!
 *
 * input: vertex data
 * 1. vertex shader
 * 2. geometry shader
 * 3. shape assembly
 * 4. rasterization
 * 5. fragment shader
 * 6. tests and blending
 * where 1, 2, and 5 we can inject our own shaders!
 *
 * vertex = collection of data per 3D coordinate
 * - can be anything we want
 * - represented using vertex attributes
 * - for simplicity, consider for now just as 3D position and some color value
 *
 * rendering hints: render data as collection of points / triangles / or just a
 * long line?...
 * - GL_POINTS
 * - GL_TRIANGLES
 * - GL_LINE_STRIP
 *
 * fragment in OpengGL: all data required to render a single pixel
 */
int main(int, char*[])
{

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  int width = 800;
  int height = 600;

  GLFWwindow* window = glfwCreateWindow(width, height,
                                        "LearnOpenGL: Hello Triangle",
                                        NULL, NULL);
  if (window == NULL)
  {
    std::cerr << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

  glfwGetWindowSize(window, &width, &height);
  std::cout << "LearnOpenGL: Hello Window" << std::endl
            << "- width : " << width  << " px" << std::endl
            << "- height: " << height << " px" << std::endl;

  if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
  {
    std::cerr << "Failed to initialize GLAD" << std::endl;
    return -1;
  }





  /****************************************************************************
   * @brief BUILD AND COMPILE SHADER PROGRAM
   ****************************************************************************/
  /**
   * @brief VERTEX SHADER
   */
  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

  glShaderSource(vertexShader, 1, &vertexShaderSrc, NULL);
  glCompileShader(vertexShader);

  int success;
  char infoLog[512];

  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

  if (!success)
  {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED" << std::endl
              << infoLog << std::endl;
    return -1;
  }





  /**
   * @brief FRAGMENT SHADER
   */
  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

  glShaderSource(fragmentShader, 1, &fragmentShaderSrc, NULL);
  glCompileShader(fragmentShader);

  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

  if (!success)
  {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED" << std::endl
              << infoLog << std::endl;
    return -1;
  }





  /**
   * @brief SHADER PROGRAM
   *
   * linked version of multiple shaders combined. To use the recently compiled
   * shaders,
   * 1. link them to a shader program
   * 2. activate shader program when rendering objects
   */
  unsigned int shaderProgram = glCreateProgram();

  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

  if (!success)
  {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED" << std::endl
              << infoLog << std::endl;
    return -1;
  }

  glUseProgram(shaderProgram);



  /**
   * @brief delete the shader objs once we have linked them into the program
   *        object (no longer need them anymore)
   */
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);







  /****************************************************************************
   * @brief SET UP VERTEX DATA (AND BUFFER(S)) AND CONFIGURE VERTEX ATTRIBUTES
   ****************************************************************************/
  /**
   * @brief OpenGL only processes 3D coordinates when they are in a specific
   *        range between -1.0f and 1.0f on ALL 3 axes (x, y, and z)
   *
   * all coordinates on the normalized device coordinates are the ones that will
   * end up in the visible screen (and all coordinates outside of it won't!)
   *
   * UNLIKE usual screen coordinates
   * (0,0) is at the center of the graph
   * y is on the up direction
   *
   * Then, the normalized device coordinates (NDC) will be transformed to
   * screen-space coordinates via the viewport transform using the data provided
   * with glViewport.
   */
  float vertices[] = {
    -0.5f, -0.5f, 0.0f, // x, y, z
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
  };





  /**
   * @brief vertex array object (VAO)
   *
   * has the advantage that when configuring vertex attribute pointers you only
   * have to make those calls once and wheneveer we want to draw the object, we
   * can just bind the corresponding VAO.
   *
   * OpenGL Core requires that we use VAO so it knows what to do with out vertex
   * inputs
   */
  unsigned int VAO;
  glGenVertexArrays(1, &VAO);





  /**
   * @brief vertex buffer objects (VBO)
   *
   * manage GPU's memory via VBOs that can store a large number or vertices
   * advantage is that we can send large batches of data all at once to the
   * graphics card and keep it there (if there is enough memory)
   *
   * preferable sending batches of data instead of vertex one by one
   * (sending data to the graphics card from the CPU relatively slow...)
   *
   */
  unsigned int VBO;       //!< any OpenGL object must have a unique ID
  glGenBuffers(1, &VBO);  //!< this variable will hold the ID (1 = #buffers)



  /**
   * @brief bind VAO so that any subsequent glVertexAttribPointer and
   *        glEnableVertexAttribArray calls will be stored inside the VAO
   *        currently bound
   *
   * **NOTE**: bind the Vertex Array Object first, then bind and set vertex
   * buffer(s), and then configure vertex attributes(s).
   */
  glBindVertexArray(VAO);



  /**
   * @brief bind a buffer object to the CURRENT BUFFER TYPE TARGET
   *
   * only a single buffer can be bound for each buffer type.
   * binding 0 as a buffer resets the currently bound buffer to a NULL-like
   * state.
   */
  glBindBuffer(GL_ARRAY_BUFFER, VBO);



  /**
   * @brief copy user-defined data into the currently bound buffer
   *
   * GL_ARRAY_BUFFER : type of the buffer we want to copy to
   * sizeof(vertices): size of the data (IN BYTES)
   * vertices        : actual data we waant to send
   *
   * then, specify how we want the graphics card to manage the given data:
   * - GL_STREAM_DRAW : data sent only once and used by the GPU at most few times
   * - GL_STATIC_DRAW : data sent only once and used many times
   * - GL_DYNAMIC_DRAW: data changed a lot and used many times
   *
   * e.g., if we have one buffer with data that is likelly to change frequently,
   * GL_DYNAMIC_DRAW would ensure that the GPU will place the data in memory
   * that allows for faster writes
   */
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);





  /**
   * @brief tell OpenGL how it should interpret the vertex data (per vertex
   *        attribute)
   *
   * 0       : specifies which vertex attribute we want to configure
   *           remember that position location was layout (location = 0)
   * 3       : size of the vertex attribute (vec3 <=> 3 values)
   * GL_FLOAT: type of data (vec* in GLSL is floating point values)
   * GL_FALSE: specifies if we want the data to be normalized (e.g., with
   *           integer data types)
   * .sizeof.: stide <=> space between consecutive vertex attributes
   *           (could be 0 and OpenGL would determine the stride by itself,
   *           only works when vertex attributes data is tightly packed)
   * 0       : offset to determine where the position data begins in the buffer
   */
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
  glEnableVertexAttribArray(0);



  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);





  // uncomment this call to draw in wireframe polygons.
  //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);





  /****************************************************************************
   * @brief RENDER LOOP
   ****************************************************************************/
  while (!glfwWindowShouldClose(window))
  {
    processInput(window);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }





  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteProgram(shaderProgram);

  glfwTerminate();

  return 0;

}





void framebufferSizeCallback(GLFWwindow*, int width, int height)
{
  glViewport(0, 0, width, height);

  std::cout << "Changing the frame buffer size to ("
                << width << "," << height << ")..." << std::endl;
}

void processInput(GLFWwindow *window)
{
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
  {
    std::cout << "ESC key was pressed. Closing the window..." << std::endl;

    glfwSetWindowShouldClose(window, GLFW_TRUE);
  }
}
