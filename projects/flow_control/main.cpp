#include <iostream>
#include <limits>

#define CHAR_ID_ESC 27





/**
 * @brief main function
 *
 * just a brief explanation on why the arguments does not have name.
 *
 * so, if all warnings are enabled, when there is a variable and/or function
 * argument that you do not use, the compiler will show up the following error:
 *
 * Scanning dependencies of target flow_control
 * [ 50%] Building CXX object CMakeFiles/flow_control.dir/main.cpp.o
 * /home/sousarbarb97/dev/phd/cpp/projects/flow_control/main.cpp: In function ‘int main(int, char**)’:
 * /home/sousarbarb97/dev/phd/cpp/projects/flow_control/main.cpp:7:14: warning: unused parameter ‘argc’ [-Wunused-parameter]
 *     7 | int main(int argc, char* argv[])
 *       |          ~~~~^~~~
 * /home/sousarbarb97/dev/phd/cpp/projects/flow_control/main.cpp:7:26: warning: unused parameter ‘argv’ [-Wunused-parameter]
 *     7 | int main(int argc, char* argv[])
 *
 * Notice the unused parameter ‘...’ [-Wunused-parameter].
 *
 * To avoid this, even though C++17 has atributtes to specify, the easiest way
 * is to just declare the arguments but remove the variables names.
 */
int main(int, char*[])
{
  char key = 0;

  std::cout << "FLOW CONTROL C++ EXAMPLE:" << std::endl << std::endl
            << "This example demonstrates different flow control statements "
                "that you can use in C++.\nLet's start!"
                << std::endl << std::endl;





  /**
   * @brief if-statements
   */
  std::cout << "IF-ELSE IF-ELSE STATEMENTS" << std::endl;
  std::cout << "press one of the following keys and press enter:" << std::endl
            << "w: " << std::endl
            << "s: " << std::endl
            << "d: " << std::endl
            << "a: " << std::endl
            << "q: quit and proceed to the next example (esc also works)"
                << std::endl;

  //! ok this one WHILE will be exemplified later... sorry...
  while ((static_cast<int>(key) != CHAR_ID_ESC) && (key != 'q'))
  {

    std::cin >> key;

    //! another valid option: key = std::cin.get();



    /**
     * @brief feedback for the user, to know which key it was read...
     *
     * static_cast<type>(variable) casts in compile time (not in runtime) the
     * variable to the desired type
     * (e.g., here we are casting the character to show in the std::cout as its
     * integer ASCII code)
     *
     * logic condition? <expression if true> : <expression if false>;
     *
     * the ? operator is very useful to make an if inside a regular expression.
     * the disadvantage making less clear to the ouside developer what is going
     * on (e.g., imagin ? expresions inside ? expressions.... buaw)
     *
     * std::string(1,key) just to make compatible types, given that both
     * expressions inside an ? operator should return the same type of data
     * (in this case, a string)
     */
    std::cout << (static_cast<int>(key) == CHAR_ID_ESC?
                      "Esc" : std::string(1,key))
                  << " pressed (ASCII code: "<< static_cast<int>(key)
                  <<")" << std::endl;



    /**
     * @brief allows to read only the first character before pressing the ENTER
     *        key (note that ENTER is equivalent to the end-of-the-line '\n'
     *        literal...)
     *
     * if you analyse https://cplusplus.com/reference/istream/istream/ignore/,
     * the fact that we are using std::numeric_limits<std::streamsize>::max()
     * to define the maximum number of characters to extract and ignore makes
     * that the function only stops until the delimeter character '\n'...
     */
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');



    //! finally if-statements

    if (key == 'w')
    {
      std::cout << "forward" << std::endl;
    }
    else if (key == 'a')
    {
      std::cout << "left" << std::endl;
    }
    else if (key == 's')
    {
      std::cout << "backwards" << std::endl;
    }
    else if (key == 'd')
    {
      std::cout << "right" << std::endl;
    }
    else if ((static_cast<int>(key) == CHAR_ID_ESC) || (key == 'q'))
    {
      std::cout << "you are a quiter... ok, let's move on..."
                    << std::endl << std::endl;
      continue;
    }
    else
    {
      std::cout << "you dumbass... follow the f****ing instructions!"
                    << std::endl;
    }
  }





  /**
   * @brief reset the key to avoid skipping the next example
   *
   * note that key variable is defined in the main scope, not inside the while
   * scope.
   * thus, it is necessary to reset the variable, giving that it continuous with
   * the last value inputted by you (you pressed q or ESC to get out the
   * example, so, is as if you would exit all next examples without reseting the
   * key variable)...
   */
  key = 0;





  /**
   * @brief switch case statements
   */
  std::cout << "SWITCH-CASE STATEMENTS" << std::endl;
  std::cout << "press one of the following keys and press enter:" << std::endl
            << "w: " << std::endl
            << "s: " << std::endl
            << "d: " << std::endl
            << "a: " << std::endl
            << "q: quit and proceed to the next example (esc also works)"
                << std::endl;

  while ((static_cast<int>(key) != CHAR_ID_ESC) && (key != 'q'))
  {

    std::cin >> key;

    std::cout << (static_cast<int>(key) == CHAR_ID_ESC?
                      "Esc" : std::string(1,key))
                  << " pressed (ASCII code: "<< static_cast<int>(key)
                  <<")" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (key)
    {
    case 'w':
    {
      std::cout << "forward" << std::endl;
      break;
    }
    case 'a':
    {
      std::cout << "left" << std::endl;
      break;
    }
    case 's':
    {
      std::cout << "backwards" << std::endl;
      break;
    }
    case 'd':
    {
      std::cout << "right" << std::endl;
      break;
    }
    /**
     * @brief two cases without a break makes an OR logical operation
     *
     * if both happen or one of which, the code is executed
     *
     * also, in terms of computational performance, without the break, you are
     * telling the compiler to check all case statements, even if you know that
     * only one can happen at a time... dumbass....
     */
    case 'q':
    case CHAR_ID_ESC:
    {
      std::cout << "you are a quiter... ok, let's move on..."
                    << std::endl << std::endl;
      break;
    }
    default:
    {
      std::cout << "you dumbass... follow the f****ing instructions!"
                    << std::endl;
      break;
    }
    }
  }





  key = 0;





  /**
   * @brief while loop statements
   */
  std::cout << "WHILE LOOP STATEMENTS" << std::endl;

  int idx = 0;

  while (idx < 5)
  {
    std::cout << "idx: " << idx << std::endl;

    idx++;

    //! ++idx also valid (but, in diff circunstances, may behave different!)
    //! idx += 1 also valid
  }

  std::cout << std::endl;



  idx = 0;
  while (idx < 5)
  {
    std::cout << "idx: " << idx++ << std::endl;
  }
  std::cout << std::endl;



  idx = 0;
  while (idx < 5)
  {
    std::cout << "idx: " << ++idx << std::endl;
  }
  std::cout << std::endl;





  /**
   * @brief do-while loop statements
   */
  std::cout << "DO-WHILE LOOP STATEMENTS" << std::endl;

  idx = 0;

  do
  {
    std::cout << "idx: " << idx++ << std::endl;
  }
  while (idx < 5);

  std::cout << std::endl;



  /**
   * @brief note that even though idx is 5, do-while ensures that the code is
   *        executed at least once!
   *        (note that 5 < 5 = FALSE you stupid!!!)
   */
  std::cout << "curr idx: " << idx << std::endl;
  do
  {
    std::cout << "idx: " << idx++ << std::endl;
  }
  while (idx < 5);
  std::cout << std::endl;





  /**
   * @brief for loop statements
   *
   * for (<initialization>; <condition>; <increment/decrement>)
   */
  std::cout << "FOR LOOP STATEMENTS" << std::endl;

  for (int idx = 0; idx < 5; idx++)
  {
    std::cout << "idx: " << idx << std::endl;
  }

  std::cout << std::endl;





  /**
   * @brief break, continue, goto statements
   *
   * allows to break / control the flow...
   *
   * goto usually not used (also difficults understanding the code, kind-off
   * reminescent of Assembly code... with the go to labels...)
   *
   * break interrupts the loop no matter what
   *
   * continue skips the remaining of the code inside the loop and checks again
   * the condition in the loop
   */
  std::cout << "BREAK, CONTINUE, GOTO FLOW CONTROL STATEMENTS" << std::endl;

  int num_sequences = 0;

label_goto:

  for (int idx = 0; idx < 5; idx++)
  {
    if (num_sequences >= 2)
    {
      std::cout << "what is the value of idx?... " << idx << std::endl;
      std::cout << "finally this stupid loop ended..." << std::endl;
      break;
    }

    if (idx == 2)
    {
      continue;
    }

    std::cout << "idx: " << idx << std::endl;

    if (idx == 4)
    {
      num_sequences++;
      goto label_goto;
    }
  }





  return 0;
}
