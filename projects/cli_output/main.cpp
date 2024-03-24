#include <iostream>

/**
 * @brief Sources ANSI Escape codes
 *
 * https://en.wikipedia.org/wiki/ANSI_escape_code
 * https://gist.github.com/Kielx/2917687bc30f567d45e15a4577772b02
 * https://gitlab.com/srrg-software/srrg2_core/-/blob/main/srrg2_core/src/srrg_system_utils/shell_colors.h
 *
 * Note: these constants definitions could be further automatized and
 * summarized....
 * also, you can even make more combinations with these...
 */

#define RESET "\033[0m"

//! standard colors

#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define BRIGHT_BLACK   "\033[90m"
#define BRIGHT_RED     "\033[91m"
#define BRIGHT_GREEN   "\033[92m"
#define BRIGHT_YELLOW  "\033[93m"
#define BRIGHT_BLUE    "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN    "\033[96m"
#define BRIGHT_WHITE   "\033[97m"

//! bold

#define BBLACK   "\033[1;30m"   // or "\033[1m\033[30m"
#define BRED     "\033[1;31m"   // or "\033[1m\033[31m"
#define BGREEN   "\033[1;32m"   // or "\033[1m\033[32m"
#define BYELLOW  "\033[1;33m"   // or "\033[1m\033[33m"
#define BBLUE    "\033[1;34m"   // or "\033[1m\033[34m"
#define BMAGENTA "\033[1;35m"   // or "\033[1m\033[35m"
#define BCYAN    "\033[1;36m"   // or "\033[1m\033[36m"
#define BWHITE   "\033[1;37m"   // or "\033[1m\033[37m"

#define BBRIGHT_BLACK   "\033[1;90m"
#define BBRIGHT_RED     "\033[1;91m"
#define BBRIGHT_GREEN   "\033[1;92m"
#define BBRIGHT_YELLOW  "\033[1;93m"
#define BBRIGHT_BLUE    "\033[1;94m"
#define BBRIGHT_MAGENTA "\033[1;95m"
#define BBRIGHT_CYAN    "\033[1;96m"
#define BBRIGHT_WHITE   "\033[1;97m"

//! italic

#define IBLACK   "\033[3;30m"
#define IRED     "\033[3;31m"
#define IGREEN   "\033[3;32m"
#define IYELLOW  "\033[3;33m"
#define IBLUE    "\033[3;34m"
#define IMAGENTA "\033[3;35m"
#define ICYAN    "\033[3;36m"
#define IWHITE   "\033[3;37m"

#define IBRIGHT_BLACK   "\033[3;90m"
#define IBRIGHT_RED     "\033[3;91m"
#define IBRIGHT_GREEN   "\033[3;92m"
#define IBRIGHT_YELLOW  "\033[3;93m"
#define IBRIGHT_BLUE    "\033[3;94m"
#define IBRIGHT_MAGENTA "\033[3;95m"
#define IBRIGHT_CYAN    "\033[3;96m"
#define IBRIGHT_WHITE   "\033[3;97m"

//! underline

#define UBLACK   "\033[4;30m"
#define URED     "\033[4;31m"
#define UGREEN   "\033[4;32m"
#define UYELLOW  "\033[4;33m"
#define UBLUE    "\033[4;34m"
#define UMAGENTA "\033[4;35m"
#define UCYAN    "\033[4;36m"
#define UWHITE   "\033[4;37m"

#define UBRIGHT_BLACK   "\033[4;90m"
#define UBRIGHT_RED     "\033[4;91m"
#define UBRIGHT_GREEN   "\033[4;92m"
#define UBRIGHT_YELLOW  "\033[4;93m"
#define UBRIGHT_BLUE    "\033[4;94m"
#define UBRIGHT_MAGENTA "\033[4;95m"
#define UBRIGHT_CYAN    "\033[4;96m"
#define UBRIGHT_WHITE   "\033[4;97m"

//! blink

#define BLINK_BLACK   "\033[5;30m"
#define BLINK_RED     "\033[5;31m"
#define BLINK_GREEN   "\033[5;32m"
#define BLINK_YELLOW  "\033[5;33m"
#define BLINK_BLUE    "\033[5;34m"
#define BLINK_MAGENTA "\033[5;35m"
#define BLINK_CYAN    "\033[5;36m"
#define BLINK_WHITE   "\033[5;37m"

#define BLINK_BRIGHT_BLACK   "\033[5;90m"
#define BLINK_BRIGHT_RED     "\033[5;91m"
#define BLINK_BRIGHT_GREEN   "\033[5;92m"
#define BLINK_BRIGHT_YELLOW  "\033[5;93m"
#define BLINK_BRIGHT_BLUE    "\033[5;94m"
#define BLINK_BRIGHT_MAGENTA "\033[5;95m"
#define BLINK_BRIGHT_CYAN    "\033[5;96m"
#define BLINK_BRIGHT_WHITE   "\033[5;97m"

//! reverse colors (background <> foreground)

#define REVERSE_BLACK   "\033[7;30m"
#define REVERSE_RED     "\033[7;31m"
#define REVERSE_GREEN   "\033[7;32m"
#define REVERSE_YELLOW  "\033[7;33m"
#define REVERSE_BLUE    "\033[7;34m"
#define REVERSE_MAGENTA "\033[7;35m"
#define REVERSE_CYAN    "\033[7;36m"
#define REVERSE_WHITE   "\033[7;37m"

#define REVERSE_BRIGHT_BLACK   "\033[7;90m"
#define REVERSE_BRIGHT_RED     "\033[7;91m"
#define REVERSE_BRIGHT_GREEN   "\033[7;92m"
#define REVERSE_BRIGHT_YELLOW  "\033[7;93m"
#define REVERSE_BRIGHT_BLUE    "\033[7;94m"
#define REVERSE_BRIGHT_MAGENTA "\033[7;95m"
#define REVERSE_BRIGHT_CYAN    "\033[7;96m"
#define REVERSE_BRIGHT_WHITE   "\033[7;97m"



//! std::cout << FG_<style>(string) << std::endl;

#define FG_BLACK(str) BLACK << str << RESET
#define FG_RED(str) RED << str << RESET
#define FG_GREEN(str) GREEN << str << RESET
#define FG_YELLOW(str) YELLOW << str << RESET
#define FG_BLUE(str) BLUE << str << RESET
#define FG_MAGENTA(str) MAGENTA << str << RESET
#define FG_CYAN(str) CYAN << str << RESET
#define FG_WHITE(str) WHITE << str << RESET
#define FG_BRIGHT_BLACK(str) BRIGHT_BLACK << str << RESET
#define FG_BRIGHT_RED(str) BRIGHT_RED << str << RESET
#define FG_BRIGHT_GREEN(str) BRIGHT_GREEN << str << RESET
#define FG_BRIGHT_YELLOW(str) BRIGHT_YELLOW << str << RESET
#define FG_BRIGHT_BLUE(str) BRIGHT_BLUE << str << RESET
#define FG_BRIGHT_MAGENTA(str) BRIGHT_MAGENTA << str << RESET
#define FG_BRIGHT_CYAN(str) BRIGHT_CYAN << str << RESET
#define FG_BRIGHT_WHITE(str) BRIGHT_WHITE << str << RESET
#define FG_BBLACK(str) BBLACK << str << RESET
#define FG_BRED(str) BRED << str << RESET
#define FG_BGREEN(str) BGREEN << str << RESET
#define FG_BYELLOW(str) BYELLOW << str << RESET
#define FG_BBLUE(str) BBLUE << str << RESET
#define FG_BMAGENTA(str) BMAGENTA << str << RESET
#define FG_BCYAN(str) BCYAN << str << RESET
#define FG_BWHITE(str) BWHITE << str << RESET
#define FG_BBRIGHT_BLACK(str) BBRIGHT_BLACK << str << RESET
#define FG_BBRIGHT_RED(str) BBRIGHT_RED << str << RESET
#define FG_BBRIGHT_GREEN(str) BBRIGHT_GREEN << str << RESET
#define FG_BBRIGHT_YELLOW(str) BBRIGHT_YELLOW << str << RESET
#define FG_BBRIGHT_BLUE(str) BBRIGHT_BLUE << str << RESET
#define FG_BBRIGHT_MAGENTA(str) BBRIGHT_MAGENTA << str << RESET
#define FG_BBRIGHT_CYAN(str) BBRIGHT_CYAN << str << RESET
#define FG_BBRIGHT_WHITE(str) BBRIGHT_WHITE << str << RESET
#define FG_IBLACK(str) IBLACK << str << RESET
#define FG_IRED(str) IRED << str << RESET
#define FG_IGREEN(str) IGREEN << str << RESET
#define FG_IYELLOW(str) IYELLOW << str << RESET
#define FG_IBLUE(str) IBLUE << str << RESET
#define FG_IMAGENTA(str) IMAGENTA << str << RESET
#define FG_ICYAN(str) ICYAN << str << RESET
#define FG_IWHITE(str) IWHITE << str << RESET
#define FG_IBRIGHT_BLACK(str) IBRIGHT_BLACK << str << RESET
#define FG_IBRIGHT_RED(str) IBRIGHT_RED << str << RESET
#define FG_IBRIGHT_GREEN(str) IBRIGHT_GREEN << str << RESET
#define FG_IBRIGHT_YELLOW(str) IBRIGHT_YELLOW << str << RESET
#define FG_IBRIGHT_BLUE(str) IBRIGHT_BLUE << str << RESET
#define FG_IBRIGHT_MAGENTA(str) IBRIGHT_MAGENTA << str << RESET
#define FG_IBRIGHT_CYAN(str) IBRIGHT_CYAN << str << RESET
#define FG_IBRIGHT_WHITE(str) IBRIGHT_WHITE << str << RESET
#define FG_UBLACK(str) UBLACK << str << RESET
#define FG_URED(str) URED << str << RESET
#define FG_UGREEN(str) UGREEN << str << RESET
#define FG_UYELLOW(str) UYELLOW << str << RESET
#define FG_UBLUE(str) UBLUE << str << RESET
#define FG_UMAGENTA(str) UMAGENTA << str << RESET
#define FG_UCYAN(str) UCYAN << str << RESET
#define FG_UWHITE(str) UWHITE << str << RESET
#define FG_UBRIGHT_BLACK(str) UBRIGHT_BLACK << str << RESET
#define FG_UBRIGHT_RED(str) UBRIGHT_RED << str << RESET
#define FG_UBRIGHT_GREEN(str) UBRIGHT_GREEN << str << RESET
#define FG_UBRIGHT_YELLOW(str) UBRIGHT_YELLOW << str << RESET
#define FG_UBRIGHT_BLUE(str) UBRIGHT_BLUE << str << RESET
#define FG_UBRIGHT_MAGENTA(str) UBRIGHT_MAGENTA << str << RESET
#define FG_UBRIGHT_CYAN(str) UBRIGHT_CYAN << str << RESET
#define FG_UBRIGHT_WHITE(str) UBRIGHT_WHITE << str << RESET
#define FG_BLINK_BLACK(str) BLINK_BLACK << str << RESET
#define FG_BLINK_RED(str) BLINK_RED << str << RESET
#define FG_BLINK_GREEN(str) BLINK_GREEN << str << RESET
#define FG_BLINK_YELLOW(str) BLINK_YELLOW << str << RESET
#define FG_BLINK_BLUE(str) BLINK_BLUE << str << RESET
#define FG_BLINK_MAGENTA(str) BLINK_MAGENTA << str << RESET
#define FG_BLINK_CYAN(str) BLINK_CYAN << str << RESET
#define FG_BLINK_WHITE(str) BLINK_WHITE << str << RESET
#define FG_BLINK_BRIGHT_BLACK(str) BLINK_BRIGHT_BLACK << str << RESET
#define FG_BLINK_BRIGHT_RED(str) BLINK_BRIGHT_RED << str << RESET
#define FG_BLINK_BRIGHT_GREEN(str) BLINK_BRIGHT_GREEN << str << RESET
#define FG_BLINK_BRIGHT_YELLOW(str) BLINK_BRIGHT_YELLOW << str << RESET
#define FG_BLINK_BRIGHT_BLUE(str) BLINK_BRIGHT_BLUE << str << RESET
#define FG_BLINK_BRIGHT_MAGENTA(str) BLINK_BRIGHT_MAGENTA << str << RESET
#define FG_BLINK_BRIGHT_CYAN(str) BLINK_BRIGHT_CYAN << str << RESET
#define FG_BLINK_BRIGHT_WHITE(str) BLINK_BRIGHT_WHITE << str << RESET
#define FG_REVERSE_BLACK(str) REVERSE_BLACK << str << RESET
#define FG_REVERSE_RED(str) REVERSE_RED << str << RESET
#define FG_REVERSE_GREEN(str) REVERSE_GREEN << str << RESET
#define FG_REVERSE_YELLOW(str) REVERSE_YELLOW << str << RESET
#define FG_REVERSE_BLUE(str) REVERSE_BLUE << str << RESET
#define FG_REVERSE_MAGENTA(str) REVERSE_MAGENTA << str << RESET
#define FG_REVERSE_CYAN(str) REVERSE_CYAN << str << RESET
#define FG_REVERSE_WHITE(str) REVERSE_WHITE << str << RESET
#define FG_REVERSE_BRIGHT_BLACK(str) REVERSE_BRIGHT_BLACK << str << RESET
#define FG_REVERSE_BRIGHT_RED(str) REVERSE_BRIGHT_RED << str << RESET
#define FG_REVERSE_BRIGHT_GREEN(str) REVERSE_BRIGHT_GREEN << str << RESET
#define FG_REVERSE_BRIGHT_YELLOW(str) REVERSE_BRIGHT_YELLOW << str << RESET
#define FG_REVERSE_BRIGHT_BLUE(str) REVERSE_BRIGHT_BLUE << str << RESET
#define FG_REVERSE_BRIGHT_MAGENTA(str) REVERSE_BRIGHT_MAGENTA << str << RESET
#define FG_REVERSE_BRIGHT_CYAN(str) REVERSE_BRIGHT_CYAN << str << RESET
#define FG_REVERSE_BRIGHT_WHITE(str) REVERSE_BRIGHT_WHITE << str << RESET





int main(int argc, char* argv[])
{

  std::cout << "./cli_output" << std::endl;

  for (int idx_arg = 0; idx_arg < argc; idx_arg++)
  {
    std::cout << "[" << idx_arg << "] " << argv[idx_arg] << std::endl;
  }

  std::cout << std::endl;



  /**
   * @brief test the program in the standard way and the way to redirect the
   *        stdout to a text file
   *
   * accordingly to https://en.cppreference.com/w/cpp/io/clog,
   * "The global objects std::clog ... associated with the standard C output
   * stream stderr..."
   *
   * (so, unless you reset the rdbug of clog, you can only redirect both streams
   * to another file...)
   */

  std::cout << "Test the program execution in the two following ways:" << std::endl
            << "./cli_output" << std::endl
            << "./cli_output > stdout.txt" << std::endl
            << "./cli_output > stdout.txt 2>stderr+log.txt" << std::endl << std::endl;



  /**
   * @brief brief explanantion of the three ostream stream standard outputs
   *
   * std::cout: buffered ostream stardard output stream (screen)
   *            normal output
   *
   * std::cerr: **unbuffered** standard error stream (screen) to output errors
   *            unbuffered is relative to display the error message IMMEDIATELY!
   *            (given that it cannot store the message)
   *
   * std::clog: buffered standard error stream to output errors, similar to cout
   *            error msg is inserted in the buffer and then it is displayed on
   *            the screen (indeed, can store the error message unlike cerr)
   *            commonly used for logging purposes
   */

  std::cout << "Say Hello to the World, std::cout" << std::endl;
  std::cerr << "Say Hello to the World, std::cerr" << std::endl;
  std::clog << "Say Hello to the World, std::clog" << std::endl;

  std::cout << std::endl;



  /**
   * @brief how to add colors and some format styling to your command line
   *        output? ESCAPE SEQUENCES
   *
   * https://en.cppreference.com/w/cpp/language/escape
   * https://en.wikipedia.org/wiki/ANSI_escape_code
   *
   * note that does not mean that it will work on all consoles
   * (check the behaviour on built-in terminal of VS Code vs Terminal!)
   */

  std::cout << BLUE   << "blue"   << RESET << std::endl;
  std::cout << YELLOW << "yellow" << RESET << std::endl << std::endl;

  std::cout << BRIGHT_BLUE   << "blue"   << RESET << std::endl;
  std::cout << BRIGHT_YELLOW << "yellow" << RESET << std::endl << std::endl;

  std::cout << BBLUE   << "bold blue"   << RESET << std::endl;
  std::cout << BYELLOW << "bold yellow" << RESET << std::endl << std::endl;

  std::cout << BBRIGHT_BLUE   << "bold bright blue"   << RESET << std::endl;
  std::cout << BBRIGHT_YELLOW << "bold bright yellow" << RESET << std::endl << std::endl;

  std::cout << IBLUE   << "italic blue"   << RESET << std::endl;
  std::cout << IYELLOW << "italic yellow" << RESET << std::endl << std::endl;

  std::cout << IBRIGHT_BLUE   << "italic bright blue"   << RESET << std::endl;
  std::cout << IBRIGHT_YELLOW << "italic bright yellow" << RESET << std::endl << std::endl;

  std::cout << UBLUE   << "underline blue"   << RESET << std::endl;
  std::cout << UYELLOW << "underline yellow" << RESET << std::endl << std::endl;

  std::cout << UBRIGHT_BLUE   << "underline bright blue"   << RESET << std::endl;
  std::cout << UBRIGHT_YELLOW << "underline bright yellow" << RESET << std::endl << std::endl;

  std::cout << BLINK_BLUE   << "blink blue"   << RESET << std::endl;
  std::cout << BLINK_YELLOW << "blink yellow" << RESET << std::endl << std::endl;

  std::cout << BLINK_BRIGHT_BLUE   << "blink bright blue"   << RESET << std::endl;
  std::cout << BLINK_BRIGHT_YELLOW << "blink bright yellow" << RESET << std::endl << std::endl;

  std::cout << REVERSE_BLUE   << "reverse blue"   << RESET << std::endl;
  std::cout << REVERSE_YELLOW << "reverse yellow" << RESET << std::endl << std::endl;

  std::cout << REVERSE_BRIGHT_BLUE   << "reverse bright blue"   << RESET << std::endl;
  std::cout << REVERSE_BRIGHT_YELLOW << "reverse bright yellow" << RESET << std::endl << std::endl;



  std::cout << FG_RED("cuco - simplified macro...") << std::endl;

}
