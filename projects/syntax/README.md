# syntax

## Getting started

### C++ Core Guidelines

https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines.html

### Header files

```cpp
#include <iostream>   // header in standard library
#include <stdlib.h>   // C-style header include (usually, .h refers to C libs)

#include "my_class.h" // header located in the local directory
```

The standard naming of the header files is not consensual among C++ developers.
Some observations can be taken into account:
- `.h` for C headers, `.hpp` for C++ headers
  - though ,the ISO C++ Guidelines supposedly say to use `.cpp` and `.h`
- `.tpp` / `.tcc` for template implementation

### Namespaces

Define the scope of the identifiers, such as functions, classes, types, and
variables are declared into.
Helps to avoid ambiguity, e.g., when two identifiers (a function or a class)
have the same name, but are implemented in two different libraries (and,
possibly, completly different and incompatible implementations!).

```cpp

using namespace std;

int main(int argc, char* argv[])
{
  cout << "Hello World" << endl;
  return 0;
}
```

**Note:** never use using namespace in a global scope (e.g., never put using
namespace in an header file!).

### Operators

**Assignment operator**
- `=`: assigns a value to a variable

**Arithmetic operators**
- `+`: addition
- `-`: subtraction
- `*`: multiplication
- `/`: division
- `%`: modulus (return the division remainder)
- `++`: increment (increase the variable's value by 1)
- `--`: decrement (increase the variable's value by 1)

**Bitwise operators**
- `~`: bitwise NOT
- `&`: bitwise AND
- `^`: bitwise XOR
- `|`: bitwise OR
- `>>`: bitwise left right
- `<<`: bitwise left shift

**Compound assignment**
- `+=`: `a += b` eq. `a = a + b`
- `-=`: `a -= b` eq. `a = a - b`
- `*=`: `a *= b` eq. `a = a * b`
- `/=`: `a /= b` eq. `a = a / b`
- `%=`: `a %= b` eq. `a = a % b`
- `>>=`: `a >>= b` eq. `a = a >> b` (bitwise left right)
- `<<=`: `a <<= b` eq. `a = a << b` (bitwise left shift)
- `&=`: `a &= b` eq. `a = a & b` (bitwise AND)
- `^=`: `a ^= b` eq. `a = a ^ b` (bitwise XOR)
- `|=`: `a |= b` eq. `a = a | b` (bitwise OR)

**Comparison operators**
- `a == b`: a equal to b
- `a != b`: a not equal to b
- `a > b`: a greater than b
- `a < b`: a less than b
- `a <= b`: a less than or equal to b
- `a >= b`: a greater than or equal to b

**Logical operators**
- `!a`: logical negation
- `a && b`: logical AND
- `a || b`: logical OR

### Data types

| Data type | Size (bytes) | Value Limits |
| :--- | :---: | :---: |
| char | 1B | -128..127 |
| unsigned char | 1B | 0..255 |
| int | 4B | -2147483648..2147483647 |
| unsigned int | 4B | 0..4294967295 |
| short | 2B | -32768..32767 |
| unsigned short | 2B | 0..65535 |
| long | 8B | -9223372036854775808..9223372036854775807 |
| unsigned long | 8B | 0..18446744073709551615 |
| bool | 1B | {0,1} |
| float | 4B | 1.17549e-38..3.40282e+38 |
| double | 8B | 2.22507e-308..1.79769e+308 |

**Additional observations**
- although usually the bool represents either a 0 or a 1 integer (false and
  true, respectivelly), the more correct defiinition is the following one:
  - if the source type is bool, the value false is converted to zero and the
    value true is converted to one
  - however, a non-zero value is assumed in a logical operation as a true
    condition!
- some data types may vary in its size depending on the compiler/architecture
  - that is why there is the possibility of using fixed width integer types
  - `#incldue <cstdint>`
  - https://en.cppreference.com/w/cpp/types/integer

## Build

```sh
mkdir build

# Linux
cmake -G "Unix Makefiles" -B build/

# Windows
cmake -G "Visual Studio 17 2022" -B build/
# if you want to specify the target platform, use -A <Win32|x64|ARM|ARM64>

cd build/
make
```

## Run

```sh
$ ./syntax
SIZE OF THE FUNDAMENTAL TYPES:
- char: 1
- unsigned char: 1
- int: 4
- unsigned int: 4
- short: 2
- unsigned short: 2
- long: 8
- unsigned long: 8
- bool: 1
- float: 4
- double: 8
LIMITS OF THE FUNDAMENTAL TYPES:
- char: -128..127
- unsigned char: 0..255
- int: -2147483648..2147483647
- unsigned int: 0..4294967295
- short: -32768..32767
- unsigned short: 0..65535
- long: -9223372036854775808..9223372036854775807
- unsigned long: 0..18446744073709551615
- bool: 0..1
- float: 1.17549e-38..3.40282e+38
- double: 2.22507e-308..1.79769e+308
```
