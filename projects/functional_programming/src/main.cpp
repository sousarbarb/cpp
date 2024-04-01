#include <iostream>
#include <sstream>

//! include your file here for the compile to know where to look for the
//! implementations of the functions
#include "simple_math.h"





/**
 * @brief function to print a c-style vector with a known size
 *
 * @param[in] res vector
 * @param[in] n   number of elements
 * @return std::string string with the result elements
 */
std::string printRes(int   res[], size_t n);

/**
 * @brief function to print a c-style vector with a known size (function
 *        overloading)
 *
 * @param[in] res vector
 * @param[in] n   number of elements
 * @return std::string string with the result elements
 */
std::string printRes(float res[], size_t n);





int main(int, char*[])
{
  /**
   * @brief take attention to the result of the int division of 1 by 2
   *
   * note that the it division of 1 / 2 will be 0! This result is expected and
   * can led to code bugs if you not take into attention this behavior in your
   * implementations
   */
  std::cout << "EXAMPLE INTEGER VARIABLES WITH FUNCTIONS" << std::endl;
  std::cout << "add : " << add(1,2)    << std::endl;
  std::cout << "sub : " << minus(1,2)  << std::endl;
  std::cout << "mult: " << mult(1,2)   << std::endl;
  std::cout << "div : " << divide(1,2) << std::endl << std::endl;



  constexpr size_t n=5;

  /**
   * @brief it is possible to define the size of the vector by n given that n is
   *        a constant expression variable
   */
  int   a1[n]={1,2,3,4,5}, b1[n]={5,4,3,2,1}, c1[n];
  float a2[n]={1,2,3,4,5}, b2[n]={5,4,3,2,1}, c2[n];

  std::cout << "EXAMPLE INTEGER VECTORS WITH FUNCTIONS" << std::endl;
  add(a1,b1,c1,n);      std::cout << "add : " << printRes(c1,n) << std::endl;
  minus(a1,b1,c1,n);    std::cout << "sub : " << printRes(c1,n) << std::endl;
  mult(a1,b1,c1,n);     std::cout << "mult: " << printRes(c1,n) << std::endl;
  divide(a1,b1,c1,n);   std::cout << "div : " << printRes(c1,n) << std::endl << std::endl;

  std::cout << "EXAMPLE FLOAT VECTORS WITH FUNCTIONS" << std::endl;
  add(a2,b2,c2,n);      std::cout << "add : " << printRes(c2,n) << std::endl;
  minus(a2,b2,c2,n);    std::cout << "sub : " << printRes(c2,n) << std::endl;
  mult(a2,b2,c2,n);     std::cout << "mult: " << printRes(c2,n) << std::endl;
  divide(a2,b2,c2,n);   std::cout << "div : " << printRes(c2,n) << std::endl << std::endl;
}





std::string printRes(int res[], size_t n)
{
  std::stringstream str;

  for (size_t idx = 0; idx < n-1; idx++)
  {
    str << res[idx] << " ";
  }

  str << res[n-1];

  return str.str();
}





std::string printRes(float res[], size_t n)
{
  std::stringstream str;

  for (size_t idx = 0; idx < n-1; idx++)
  {
    str << res[idx] << " ";
  }

  str << res[n-1];

  return str.str();
}
