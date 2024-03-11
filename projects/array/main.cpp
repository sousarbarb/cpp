#include <iostream>





int main(int, char*[])
{
  //! initialization of a char vector with a string literal
  char str[] = "Example of a vector of characters, equivalent to a string";



  /**
   * @brief this example shows a vector of characters equivalent to a C-like
   *        string
   *
   * how to find the string size?
   * in this case, given that the array is not received as a parameter of a
   * function, we can use the sizeof funcion.
   *
   * Also, do not forget that the C-like string must always have the \0
   * termination character at the end of the string!!!!!
   */

  std::cout << "Original string = vector of chatecters (C-like vector): "
                << str << std::endl
            << "characters:" << std::endl;

  for (size_t idx = 0; str[idx] != '\0'; ++idx)
  {
    std::cout << "[" << idx << "] " << str[idx] << std::endl;
  }

  std::cout << "[size] " << sizeof(str) / sizeof(str[0]) << std::endl << std::endl;





  /**
   * @brief notice the compilation warnings that underline that sizeof does not
   *        work inside functions >>> you need to always pass the vector size as
   *        argument in order to know the size of C-like (underline C-like!)
   *        arrays
   *
   * Scanning dependencies of target array
   * [ 50%] Building CXX object CMakeFiles/array.dir/main.cpp.o
   * /home/sousarbarb97/dev/phd/cpp/projects/array/main.cpp: In lambda function:
   * /home/sousarbarb97/dev/phd/cpp/projects/array/main.cpp:61:43: warning: division ‘sizeof (const int*) / sizeof (const int)’ does not compute the number of array elements [-Wsizeof-pointer-div]
   *    61 |     std::cout << "[size] " << sizeof(vec) / sizeof(vec[0]) << " (sizeof) "
   *       |                               ~~~~~~~~~~~~^~~~~~~~~~~~~~~~
   * /home/sousarbarb97/dev/phd/cpp/projects/array/main.cpp:48:40: note: first ‘sizeof’ operand was declared here
   *    48 |   auto print_int_array = [](const int* vec, size_t n,
   *       |                             ~~~~~~~~~~~^~~
   * /home/sousarbarb97/dev/phd/cpp/projects/array/main.cpp: In lambda function:
   * /home/sousarbarb97/dev/phd/cpp/projects/array/main.cpp:83:43: warning: division ‘sizeof (const short int*) / sizeof (const short int)’ does not compute the number of array elements [-Wsizeof-pointer-div]
   *    83 |     std::cout << "[size] " << sizeof(vec) / sizeof(vec[0]) << " (sizeof) "
   *       |                               ~~~~~~~~~~~~^~~~~~~~~~~~~~~~
   * /home/sousarbarb97/dev/phd/cpp/projects/array/main.cpp:70:44: note: first ‘sizeof’ operand was declared here
   *    70 |   auto print_short_array = [](const short* vec, size_t n,
   *       |                               ~~~~~~~~~~~~~^~~
   * [100%] Linking CXX executable array
   * [100%] Built target array
   *
   */

  //! initialization of int arrays with an initialization list
  int int_array[10] = {0,1,2,3,4,5,6,7,8,9};
  short short_array[6] = {1,2,3};



  //! C++ lambda declaration (will be introduced later)
  auto print_int_array = [](const int* vec, size_t n,
                            std::string dbg = "")
  {
    if (!dbg.empty())
    {
      std::cout << dbg << std::endl;
    }

    for (size_t idx = 0; idx < n; ++idx)
    {
      std::cout << "[" << idx << "]" << vec[idx] << std::endl;
    }

    std::cout << "[size] " << sizeof(vec) / sizeof(vec[0]) << " (sizeof) "
                 "versus " << n << " (real)" << std::endl << std::endl;
  };

  print_int_array(int_array, sizeof(int_array) / sizeof(int_array[0]),
                  "int_array:");



  auto print_short_array = [](const short* vec, size_t n,
                              std::string dbg = "")
  {
    if (!dbg.empty())
    {
      std::cout << dbg << std::endl;
    }

    for (size_t idx = 0; idx < n; ++idx)
    {
      std::cout << "[" << idx << "]" << vec[idx] << std::endl;
    }

    std::cout << "[size] " << sizeof(vec) / sizeof(vec[0]) << " (sizeof) "
                 "versus " << n << " (real)" << std::endl << std::endl;
  };

  print_short_array(short_array, sizeof(short_array) / sizeof(short_array[0]),
                    "short_array:");
}
