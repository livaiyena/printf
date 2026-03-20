_This project has been created as part of the 42 curriculum by kapaydin._

## Description
The **ft_printf** project is a core assignment at Ecole 42. The main goal of this project is to recode the fundamental functionality of the standard C library's `printf()` function. This project introduces the concept of **variadic arguments** in C, teaching how functions can accept an indefinite number of parameters. This lightweight version of `printf` handles the formatting of characters, strings, pointers, decimal and hexadecimal numbers without managing the internal buffer of the original `printf`.

Supported Conversions:
- `%c` - Prints a single character
- `%s` - Prints a string
- `%p` - Prints a void * pointer argument in hexadecimal format
- `%d` - Prints a decimal (base 10) number
- `%i` - Prints an integer in base 10
- `%u` - Prints an unsigned decimal (base 10) number
- `%x` - Prints a number in lowercase hexadecimal (base 16) format
- `%X` - Prints a number in uppercase hexadecimal (base 16) format
- `%%` - Prints a literal percent sign

## Instructions

### Compilation
To compile the library, simply run:
```bash
make
```
This will compile the `libft` dependency and generate the `libftprintf.a` static library at the root of the repository.

Other available Makefile rules:
- `make clean`: Removes all `.o` object files.
- `make fclean`: Removes the object files and the `libftprintf.a` library.
- `make re`: Fully recompiles the library from scratch.

### Execution
To use this custom printf library in your own code:
1. Include the header in your C file: 
```c
#include "ft_printf.h"
```
2. Compile your program along with the newly created library:
```bash
cc my_program.c libftprintf.a -o my_program
./my_program
```

## Algorithm and Data Structure
**Parsing System:**
The core algorithm relies on sequential string parsing using **pointer arithmetic** (`*str` and `*++str`). As we iterate over the format string, we evaluate characters one by one. If the `%` character is encountered, the pointer is physically advanced to read the format specifier, the corresponding function is dispatched via `va_arg`, and the pointer advances again to skip it. This approach avoids creating an unnecessary length index (`i`) and results in an elegant, minimal O(n) parser.

**Number Conversion & Printing:**
A **Recursive Algorithm** was deliberately chosen for number conversion (`ft_print_nbr`, `ft_print_hex`, `ft_print_ptr`). When converting bases (10 or 16), the function recursively calls itself with `number / base` until it reaches a single digit, then prints `number % base` sequentially. 

*Justification:* Since the project subject strictly forbids managing our own buffer (like the original `printf` does), using recursion eliminates the need to `malloc` memory or define static arrays to reverse the digits. The Call Stack itself acts as our natural buffer, thus maintaining extreme memory efficiency, simplifying the logic, and perfectly fulfilling the constraints of the subject.

## Resources
- **C Standard Library Documentation:** `<stdarg.h>` (`va_start`, `va_arg`, `va_end`, `va_copy`) to understand and implement variadic functions functionality.
- **Manual Pages:** `man stdarg` and `man printf` for native implementation details.
- **Tutorials & Articles:** [GeeksforGeeks - Variadic functions in C](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)
- **AI Usage:** An AI coding assistant was used during this project strictly for the following tasks:
  - Formatting and generating sections of this `README.md` documentation.
  - Explaining theoretical C concepts and the underlying mechanisms of the chosen algorithms and functions.