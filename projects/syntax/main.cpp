#include <iostream>
#include <limits>



int main(int, char*[])
{
  /**
   * @brief sizeof is an operator that queries size of the object or type
   *        (returns the number of Bytes of the object)
   */
  std::cout << "SIZE OF THE FUNDAMENTAL TYPES:" << std::endl
            << "- char: "           << sizeof(char) << std::endl
            << "- unsigned char: "  << sizeof(unsigned char) << std::endl
            << "- int: "            << sizeof(int) << std::endl
            << "- unsigned int: "   << sizeof(unsigned int) << std::endl
            << "- short: "          << sizeof(short) << std::endl
            << "- unsigned short: " << sizeof(unsigned short) << std::endl
            << "- long: "           << sizeof(long) << std::endl
            << "- unsigned long: "  << sizeof(unsigned long) << std::endl
            << "- bool: "           << sizeof(bool) << std::endl
            << "- float: "          << sizeof(float) << std::endl
            << "- double: "         << sizeof(double) << std::endl;

  /**
   * @brief numeric_limits is a function from the <limits> library that allows
   *        to check the minimum and maximum limits of a data type in a certain
   *        architecture
   */
  std::cout << "LIMITS OF THE FUNDAMENTAL TYPES:" << std::endl
            << "- char: "           << (int)          std::numeric_limits<char>::min()           << ".." << (int)          std::numeric_limits<char>::max() << std::endl
            << "- unsigned char: "  << (unsigned int) std::numeric_limits<unsigned char>::min()  << ".." << (unsigned int) std::numeric_limits<unsigned char>::max() << std::endl
            << "- int: "            << std::numeric_limits<int>::min()            << ".." << std::numeric_limits<int>::max() << std::endl
            << "- unsigned int: "   << std::numeric_limits<unsigned int>::min()   << ".." << std::numeric_limits<unsigned int>::max() << std::endl
            << "- short: "          << std::numeric_limits<short>::min()          << ".." << std::numeric_limits<short>::max() << std::endl
            << "- unsigned short: " << std::numeric_limits<unsigned short>::min() << ".." << std::numeric_limits<unsigned short>::max() << std::endl
            << "- long: "           << std::numeric_limits<long>::min()           << ".." << std::numeric_limits<long>::max() << std::endl
            << "- unsigned long: "  << std::numeric_limits<unsigned long>::min()  << ".." << std::numeric_limits<unsigned long>::max() << std::endl
            << "- bool: "           << std::numeric_limits<bool>::min()           << ".." << std::numeric_limits<bool>::max() << std::endl
            << "- float: "          << std::numeric_limits<float>::min()          << ".." << std::numeric_limits<float>::max() << std::endl
            << "- double: "         << std::numeric_limits<double>::min()         << ".." << std::numeric_limits<double>::max() << std::endl;
}
