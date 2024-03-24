#include <iostream>
#include <string>





int main(int, char*[])
{

  /**
   * @brief string literals in C (also works in C++)
   *
   * defined as null-terminated ('\0') character arrays
   */

  char hello_world[] = "Hello World!";

  std::cout << hello_world << std::endl;





  /**
   * @brief string class: STL container class for strings in C++
   *
   * basic_string defines the container class template for different types of
   * strings:
   * - string
   * - wstring (elements of wchar_t)
   * - u16string
   * - u32string
   *
   * If you access the string library in your local computer
   * (/usr/include/c++/9/string):
   *
   *   using string    = basic_string<char>;
   *   using u8string  = basic_string<char8_t>;
   *   using u16string = basic_string<char16_t>;
   *   using u32string = basic_string<char32_t>;
   *   using wstring   = basic_string<wchar_t>;
   */

  std::string hello_world_cpp = "Hello Brave New World with C++!";

  //!< also a valid initialization of the string
  std::string hello_world_cpp_alt("Hello Brave New World with C++!");

  std::cout << hello_world_cpp << std::endl;





  /**
   * @brief iteration over the string's characters
   */

  std::cout << "iteration over the string's characters" << std::endl;
  std::cout << "index with []" << std::endl;

  for (size_t idx = 0; idx < hello_world_cpp.length(); idx++)
  {
    std::cout << "[" << idx << "] " << hello_world_cpp[idx] << std::endl;
  }

  std::cout << "index with at() "
               "(advantage of throwin out of range exceptions)" << std::endl;

  for (size_t idx = 0; idx < hello_world_cpp.length(); idx++)
  {
    std::cout << "[" << idx << "] " << hello_world_cpp.at(idx) << std::endl;
  }

  std::cout << "forward iterator" << std::endl;
  size_t idx = 0;

  for (std::string::iterator it = hello_world_cpp.begin();
       it != hello_world_cpp.end(); ++it)
  {
    std::cout << "[" << idx++ << "] " << *it << std::endl;
  }

  std::cout << "reverse iterator" << std::endl;
  idx = 0;

  for (std::string::reverse_iterator it = hello_world_cpp.rbegin();
       it != hello_world_cpp.rend(); ++it)
  {
    std::cout << "[" << idx++ << "] " << *it << std::endl;
  }

  std::cout << "auto for iterator (equivalent to the forward it)" << std::endl;
  idx = 0;

  for (const auto& ch : hello_world_cpp)
  {
    std::cout << "[" << idx++ << "] " << ch << std::endl;
  }





  /**
   * @brief string properties
   */

  std::cout << "string properties:" << std::endl
            << "- is empty: " << (hello_world_cpp.empty()? "true" : "false") << std::endl
            << "- length  : " << hello_world_cpp.length() << std::endl
            << "- size    : " << hello_world_cpp.size() << std::endl
            << "- max size: " << hello_world_cpp.max_size() << std::endl
            << "- capacity: " << hello_world_cpp.capacity() << std::endl;





  /**
   * @brief string searchers
   *
   * note that std::string::npos, in this case, means that the search string was
   * not found in the original one.
   *
   * however, this constant may have different meanings in different contexts...
   */

  std::cout << "string search:" << std::endl
            << "- 'world': " << hello_world_cpp.find("World") << std::endl
            << "- ' '    : " << hello_world_cpp.find(" ") << " (first occurrence)" << std::endl
            << "- ' '    : " << hello_world_cpp.rfind(" ") << " (last occurrence)" << std::endl
            << "- 'N/A'  : "
                << ( hello_world_cpp.find("world") == std::string::npos ?
                        "not found" : "found" ) << std::endl;





  /**
   * @brief sub string
   */

  std::cout << "string sub:" << std::endl
            << "- start at 6, get 5 characters: " << hello_world_cpp.substr(6, 5) << std::endl
            << "- start at 22, get remaining  : " << hello_world_cpp.substr(22, std::string::npos) << std::endl;





  /**
   * @brief string modifiers
   */

  std::cout << "string insert: " << std::endl
            << hello_world_cpp.insert(29, " (simply the best ;) )") << std::endl
            << hello_world_cpp.append(" What about C? Well, it is an ok (very good but no OOP buuuhhh) ancient parent ;) !") << std::endl
            << hello_world_cpp.replace(6, 5, "Brave (really?)") << std::endl
            << hello_world_cpp.append(" Bye?") << std::endl
            << hello_world_cpp.erase(hello_world_cpp.find(" Bye?"), std::string::npos) << std::endl;





  /**
   * @brief note the newer capacity of the string. this behaviour is due to the
   *        default allocator of the string object...
   *        (more advanced topics is you creating your own allocator)
   */

  std::cout << "string properties:" << std::endl
            << "- is empty: " << (hello_world_cpp.empty()? "true" : "false") << std::endl
            << "- length  : " << hello_world_cpp.length() << std::endl
            << "- size    : " << hello_world_cpp.size() << std::endl
            << "- max size: " << hello_world_cpp.max_size() << std::endl
            << "- capacity: " << hello_world_cpp.capacity() << std::endl;

  idx = 0;

  std::cout << hello_world_cpp << std::endl;

  for (const auto& ch : hello_world_cpp)
  {
    std::cout << "[" << idx++ << "] " << ch << std::endl;
  }





  /**
   * @brief string comparators
   */

  std::cout << "sub str 0,5 == 'Hello'? ";

  if (hello_world_cpp.substr(0, 5) == "Hello")
  {
    std::cout << "yes" << std::endl;
  }
  else
  {
    std::cout << "no" << std::endl;
  }

  std::cout << "sub str 0,5.compare('Hello')? ";

  if (hello_world_cpp.substr(0, 5).compare("Hello") == 0)
  {
    std::cout << "yes" << std::endl;
  }
  else
  {
    std::cout << "no" << std::endl;
  }

}
