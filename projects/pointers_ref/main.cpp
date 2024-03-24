#include <iostream>





int main(int, char*[])
{

  int idx = 0;





  /****************************************************************************
   * @brief POINTERS... buuuhhh
   *
   * just kidding, very helpful, extremly powerful!
   ****************************************************************************/

  /**
   * @brief pointer to the variable idx
   *
   * variable idx_ptr now will store the memory address of idx
   */

  int* idx_ptr = &idx;

  std::cout << "(variable value   ) idx    : " << idx << std::endl
            << "(variable address ) idx    : " << (&idx) << std::endl
            << "(variable value   ) idx_ptr: " << idx_ptr << std::endl
            << "(value pointing at) idx_ptr: " << (*idx_ptr) << std::endl
            << "(variable address ) idx_ptr: " << (&idx_ptr) << std::endl << std::endl;



  ++idx;  //!< just because we can ;)



  /**
   * @brief example to show that the value pointing at by the pointer variable
   *        is automatically update, even though we only changed idx and not
   *        idx_ptr
   */

  std::cout << "now, let's check again:" << std::endl;
  std::cout << "(variable value   ) idx    : " << idx << std::endl
            << "(variable address ) idx    : " << (&idx) << std::endl
            << "(variable value   ) idx_ptr: " << idx_ptr << std::endl
            << "(value pointing at) idx_ptr: " << (*idx_ptr) << std::endl
            << "(variable address ) idx_ptr: " << (&idx_ptr) << std::endl << std::endl;



  /**
   * @brief note that now you are changing the value of idx through the pointer
   *        idx_ptr!
   */

  *idx_ptr += 5;  //!< because we can ;)



  /**
   * @brief hoewver, a pointer does not need to be initialized right away...
   *
   * note that the value *tmp_ptr is trash, we do not know what it means and to
   * where it is pointing at....
   *
   * For example, if you initialized int* tmp_ptr = nullptr;, you will get
   * segmentation fault!
   * (makes sense, because in that way, you told that, currently, tmp_ptr does
   * not point to anything!)
   * Even if you do not initialize, there maybe times that you get segmentation
   * fault.... (unsafe memory access...)
   */
  int* tmp_ptr;

  std::cout << "(variable value   ) tmp_ptr: " << tmp_ptr << std::endl
            // << "(value pointing at) tmp_ptr: " << (*tmp_ptr) << std::endl
            << "(variable address ) tmp_ptr: " << (&tmp_ptr) << std::endl << std::endl;



  /**
   * @brief this way we reassign tmp_ptr (that was point to hell, we do not
   *        know for sure) to pointing to idx int variable
   */

  tmp_ptr = idx_ptr;

  std::cout << "what about now?" << std::endl;
  std::cout << "(variable value   ) idx    : " << idx << std::endl
            << "(variable address ) idx    : " << (&idx) << std::endl
            << "(variable value   ) idx_ptr: " << idx_ptr << std::endl
            << "(value pointing at) idx_ptr: " << (*idx_ptr) << std::endl
            << "(variable address ) idx_ptr: " << (&idx_ptr) << std::endl
            << "(variable value   ) tmp_ptr: " << tmp_ptr << std::endl
            << "(value pointing at) tmp_ptr: " << (*tmp_ptr) << std::endl
            << "(variable address ) tmp_ptr: " << (&tmp_ptr) << std::endl << std::endl;



  int** ptr_idx_ptr = &idx_ptr;

  std::cout << "(variable value   ) idx        : " << idx << std::endl
            << "(variable address ) idx        : " << (&idx) << std::endl
            << "(variable value   ) idx_ptr    : " << idx_ptr << std::endl
            << "(value pointing at) idx_ptr    : " << (*idx_ptr) << std::endl
            << "(variable address ) idx_ptr    : " << (&idx_ptr) << std::endl
            << "(variable value   ) ptr_idx_ptr: " << ptr_idx_ptr << std::endl
            << "(value pointing at) ptr_idx_ptr: " << (*ptr_idx_ptr) << std::endl
            << "(...inception...  ) ptr_idx_ptr: " << (*(*ptr_idx_ptr)) << std::endl
            << "(variable address ) ptr_idx_ptr: " << (&ptr_idx_ptr) << std::endl << std::endl;



  /**
   * @brief only cool thing about pointers is casting them to interpret
   *        differently the data to where they where pointing at
   *
   * but note, the following example is not safe, given that it uses C-style
   * casting.
   *
   * the safest way of using casting would be with static_cast, to ensure if the
   * cast is possible / is defined in the original class / type...
   *
   * however, indeed, the C-cast is much more powerful that static/dynamic_cast.
   *
   * you will see that the memory s probably organized by the LSB to the MSB
   * (lowest significant byte to most significant one, respectively).
   *
   * note: a more appropriate way to interpret these results would be to put in
   * hexadecimal representation of the value...
   */

  int8_t* idx_ptr_int8 = (int8_t*)(&idx);   //!< C-style casting

  std::cout << "byte a byte contents of idx variable (LSB - MSB, 10 decimal base):" << std::endl;
  std::cout << static_cast<int>(idx_ptr_int8[0]) << std::endl
            << static_cast<int>(idx_ptr_int8[1]) << std::endl
            << static_cast<int>(idx_ptr_int8[2]) << std::endl
            << static_cast<int>(idx_ptr_int8[3]) << std::endl << std::endl;





  /****************************************************************************
   * @brief REFERENCES... yyyeeaaaaaaahhhhhhhh
   ****************************************************************************/

  /**
   * @brief you always need to initialize a reference
   */

  int&             idx_ref = idx;   //!< reference to non-const idx object
  const int& const_idx_ref = idx;   //!< reference to  const idx object

  ++idx_ref;        //!< you can do this, and will update idx
  // ++const_idx_ref;  //!< you cannot do this!

  /**
   * @brief also, note that a reference, in this particular case, does not
   *        occupy space in memory, it is a 'direct' reference to the idx object
   *        itself!
   *
   * one extremely very good use case of references is for function arguments!
   * (to avoid copies)
   *
   * https://www.geeksforgeeks.org/pointers-vs-references-cpp/
   * - "Tabular form of difference between References and Pointers in C++"
   * - "When to use What"
   *
   * So, reference is kind off an alias (does not make sense an alias be changed
   * to another value...)
   */

  std::cout << "are references cool? oh yeah!" << std::endl;
  std::cout << "(variable value   ) idx          : " << idx << std::endl
            << "(variable address ) idx          : " << (&idx) << std::endl
            << "(variable value   ) idx_ref      : " << idx_ref << std::endl
            << "(variable address ) idx_ref      : " << (&idx_ref) << std::endl
            << "(variable value   ) const_idx_ref: " << const_idx_ref << std::endl
            << "(variable address ) const_idx_ref: " << (&const_idx_ref) << std::endl << std::endl;



  /**
   * @brief see some additional examples of bad usage of references taken from
   *        the almighty cppreference
   *        (https://en.cppreference.com/w/cpp/language/reference)
   *
   * int& a[3]; // error (because the references were not initialized)
   * int&* p;   // error (reference does not hold a memory address, so ptr no sense)
   * int& &r;   // error reference to a reference not possible
   *
   * possible advancer examples will explore lvalue and rvlaue references...
   */

}
