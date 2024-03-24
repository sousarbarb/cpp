#include <iostream>
#include <string>





/**
 * @brief all C / C++ executables must have a main function
 *
 * the main has 2 arguments. In the previous examples, these arguments were not
 * used. That is why we did not specify the variable's name in the main
 * function's header.
 *
 * @param[in] argc count of arguments that follow in argv (always greater or
 *                 equal to 1)
 * @param[in] argv array of null-terminated strings (C-style) representing the
 *                 command-line arguments entered by the user of the program
 *                 (argv[argc] is always NULL!)
 * @return int
 */
int main(int argc, char* argv[])
{

  /**
   * @brief there are more output streams than std::cout (will be aboarded
   *        later)
   *
   * usually:
   * - std::cout: normal output
   * - std::cerr: errors
   * - std::clog: logging
   *
   * see more advanced examples related to output streams...
   */

  if (argc <= 1)
  {
    std::cerr << "you only called the program execution. try to add some "
                 "arguments after the execution argument" << std::endl
              << std::endl
              << "  ./cmd_args <argument 1> <argument 2> ..." << std::endl;
    return -1;
  }

  std::cout << "List of arguments you specified when executing the program:"
            << std::endl;

  for (int idx_arg = 0; idx_arg < argc; ++idx_arg)
  {
    std::cout << "[" << idx_arg << "] " << argv[idx_arg] << std::endl;
  }



  /**
   * @brief note that if you want to use command line arguments in your program,
   *        you need to parse them, interpret which action / input the user
   *        wants / specifies!
   */

  std::cout << std::endl
            << "Try to test the following program call, to see how would you "
               "handle the parsing of the arguments' list for your program:"
                << std::endl
            << std::endl
            << "  ./cmd_args --option0 value0 -opt1 value1 --opt2:=value2 "
               "--option3 'value 3' -opt4 \"value 4\"" << std::endl << std::endl;

  std::cout << "Also, try to call the program execution in a multiple line "
               "fashion way:"
                << std::endl
            << "  ./cmd_args --option0 value0 \\" << std::endl
            << "      -opt1 value1            \\" << std::endl
            << "      --opt2:=value2          \\" << std::endl
            << "      --option3 'value 3'     \\" << std::endl
            << "      -opt4 \"value 4\""          << std::endl;



  return 0;

}
