#include <iostream>

/**
 * @brief main function
 *
 * each C++ executable must contain a main function, similar to C
 *
 * two possible signatures for the main function:
 * - int main()
 * - int main(int argc, char *argv[])
 *
 * @note this code documentation is made with Doxygen
 *
 * @param[in] argc integer that contains the count of arguments in argv
 *                 (>= 1)
 * @param[in] argv array of null-terminated strings representing command-line
 *                 arguments entered by the user of the program.
 *                 by convention, argv[0] is the command with which the program
 *                 is invoked
 * @return int return of the main executable / program
 *             (usually, 0 indicates successful execution, and -1 or other error
 *             values may indicate that something went wrong)
 */
int main(int, char*[])
{
  std::cout << "Hello World!" << std::endl;
  return 0;
}
