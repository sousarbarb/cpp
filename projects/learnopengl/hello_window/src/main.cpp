#include <iostream>

#include <glad/glad.h>  // must be before GLFW...
#include <GLFW/glfw3.h>





void framebufferSizeCallback(GLFWwindow* window, int width, int height);

void processInput(GLFWwindow *window);





int main(int argc, char* argv[])
{
  /**
   * @brief initialization of the GLFW library
   */
  glfwInit();



  /**
   * @brief https://www.glfw.org/docs/latest/window.html#window_hints
   * hints that can be set before the creation of a window and context.
   * These hints are set to their default values each time the library is
   * initialized with glfwInit.
   */
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



  /**
   * @brief create window and its associated context, but does not mean that
   * the window will have the desired size (some are hard constraints, other
   * hints and/or parameters are soft constraints)
   */
  int width = 800;
  int height = 600;

  GLFWwindow* window = glfwCreateWindow(width, height,
                                        "LearnOpenGL: Hello Window",
                                        NULL, NULL);

  if (window == NULL)
  {
    std::cerr << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  glfwGetWindowSize(window, &width, &height);

  std::cout << "LearnOpenGL: Hello Window" << std::endl
            << "- width : " << width  << " px" << std::endl
            << "- height: " << height << " px" << std::endl;



  /**
   * @brief initialize GLAD library (must be done before calling any
   * OpenGL function!)
   */
  if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
  {
    std::cerr << "Failed to initialize GLAD" << std::endl;
    return -1;
  }



  /**
   * @brief specify the size of the rendering window so OpenGL knows how we want
   * to display the data and coordinates with respect to the window.
   *
   * (0,0)     sets the location of the lower left corner of the window
   * (800,600) sets the size of the rendering window in pixels
   *
   * Behind the scenes OpenGL uses the data specified via glViewport to
   * transform the 2D coordinates it processed to coordinates on your screen.
   * For example, a processed point of location (-0.5,0.5) would (as its final
   * transformation) be mapped to (200,450) in screen coordinates.
   * Note that processed coordinates in OpenGL are between -1 and 1 so we
   * effectively map from the range (-1 to 1) to (0, 800) and (0, 600).
   */
  glViewport(0, 0, 800, 600);



  /**
   * @brief the moment a user resizes the window the viewport should be
   * adjusted as well!
   */
  glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);





  /**
   * @brief simple render loop that keeps on running until we tell GLFW to stop
   */
  while (!glfwWindowShouldClose(window))
  {
    /**
     * @brief input
     */
    processInput(window);



    /**
     * @brief render
     *
     * glClearColor clears the color buffer (_state-setting function_)
     *
     * glClear uses the current state to retrieve the clearing color from
     * (_state-using function_)
     */
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);



    /**
     * @brief swap the color buffer (a large 2D buffer that contains color
     * values for each pixel in GLFW's window) that is used to render to during
     * this render iteration and show it as output to the screen
     *
     * **DOUBLE BUFFER**
     * when single buffer, resulting image may display flickering issues (the
     * rendered image IS NOT displayed instantaneously, thus, may contain some
     * artifacts from the previous frame)
     * double buffer circunvents the flickering issues:
     * - front buffer contains final output image shown at the screen
     * - all rendering commands are drawn to the back buffer
     */
    glfwSwapBuffers(window);



    /**
     * @brief check if any events are triggered (keyboard input, mouse
     * movement), updates the window state, and calls the corresponding
     * functions (can be registered by callback methods)
     */
    glfwPollEvents();

  }





  /**
   * @brief exit the render environment in an appropriate way that cleans /
   * deletes all of GLFW's resources that were allocated
   */
  glfwTerminate();

  return 0;
}





void framebufferSizeCallback(GLFWwindow* window, int width, int height)
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
