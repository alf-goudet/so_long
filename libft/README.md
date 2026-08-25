_This project has been created as part of the 42 curriculum by agoudet-._

## Description

The `ft_printf` project is a challenge to write functional code for a handmade
version of `printf()`, one of the most popular and versatile functions in C.

The main goal is to explore how to write an effective **variadic function**,
which is a kind of function that takes a variable number of arguments, unlike
regular non-variadic functions whose number of parameters is fixed.

### Overview

My `ft_printf` structure is composed as follows:

- __ft_printf.c__: Main source file with the `ft_printf()` definition and
  format-parsing helper functions.
- __ft_printf_convs.c__: Modular functions for individual conversion
  specifiers (`chr_str_conv()`, `dec_int_conv()`, `uint_conv()`, etc.).
  - _NOTE_: Some functions handle two specifiers instead of just one.
- __ft_printf_utils.c__: Helper functions for memory allocation and base
  calculation operations.
- __ft_printf.h__: Main header with prototypes for `ft_printf()`, conversion
  modules, and helper functions.
- __libft__: Folder with my `libft` functions, used by `ft_printf` logic.
- __Makefile__: Instructions for `make` in the current directory. This
  `Makefile` automates compilation and archiving into `libftprintf.a`.

Additionally, the following sources and headers were added for extensibility
and structure:

- __ft_printf_long.h__: Header with prototypes for conversions and helper
  functions modified for handling `long` number arguments.
- __ft_printf_convs_long.c__ and __ft_printf_utils_long.c__: Modified versions
  of `ft_printf_convs.c` and `ft_printf_utils.c` with functions for handling
  `long` type numbers (`dec_int_conv_long()`, `hex_conv_long()`,
  `get_hex_digits_long()`, etc.).

## Instructions

### 1. Compilation

To compile, start by running the following command in the terminal:

```bash
make
```

This compiles all source files (including those in `libft`) into object files
(`.o` files), then archives all objects into `libftprintf.a` at repository root.

If you want to recompile everything from scratch, run:

```bash
make re
```

This deletes everything produced by `make` and compiles again immediately.

To delete all individual `.o` files (root and `libft`), run:

```bash
make clean
```

This cleans the environment while keeping `libftprintf.a` for executable
compilation.

### 2. Execution

Once `libftprintf.a` is present, include `ft_printf.h` in your tester source
with the `main()` function:

```C
#include "ft_printf.h"
#include <stdio.h> // To compare with printf()

int main(void)
{
    // Code to test ft_printf
    return (0);
}
```

Then compile your tester source with `libftprintf.a` into an executable:

```bash
cc -Wall -Wextra -Werror [your_tester].c libftprintf.a -o test
./test
```

After testing, delete all compilation outputs, including `libftprintf.a`:

```bash
make fclean
```

## Resources

### Classic References

- printf(3) Linux man page ([online here][man-printf]): Build `ft_printf()`
  from this definition of `printf()`.
- [printf - Wikipedia][wiki-printf]: Learn about the history and precedents of
  `printf`.
- [GNU make manual][gnu-make]: Learn about `make` and Makefiles, including
  compiling subdirectories like `libft`.

### AI Usage

I have used AI assistance for the following tasks:

- **Researching**: I used Google's AI Overviews, AI Mode, and NotebookLM for
  researching and understanding new concepts such as **variadic functions** and
  ***Makefiles that compile subdirectories***. I always cross-checked and tested
  source validity for generated outputs.
  
- **Learning**: I used a Gemini Gem predesigned by Google called
  *Learning coach* for a guided learning session on **variadic functions**.
  
- **`README` reformatting**: I used Github Copilot in VS Code to rewrite this
  `README` for _up to 80 columns per line_. ***Reasons why***:

   1. When a peer opens a `README`, the default visualizer in most
   cases (Linux / Text Editor) has no text wrapping by default, resulting in
   lines too long to read comfortably. I considered formatting my `README` to
   prevent this by having the max number of columns per line permitted by the
   Norm, even though it doesn't specifically apply to `README.md` files.

   2. The manual job of reformatting my `README` when it was over 200
   lines long, turned out to be too tedious, monotonous and prone to human
   error. I considered automating this job necessary to avoid consuming lots of
   time and energy on a low-level, repetitive, un-stimulating task. ***I made
   sure to check every change made by AI to make sure I both understand why it
   works and agree with it.***

I also used AI on the following parts of the project:

- **Parsing**: During creation of the format-parsing logic, using `write()`
  directly on literals and after converting arguments to printable format
  started as an AI-generated idea.
- **Tester ideas**: I used Google Gemini to generate an initial tester idea for
  basic and edge cases across required conversion specifiers.
- **Algorithm justification**: I wrote a draft of my justification of my
  project's algorithm, and passed it over to Gemini to make it sound more
  professional and courteous. I then made several manual edits to the AI rewrite
  to reflect my tone as best as possible, while maintaining keywords that are
  likely to increase my employability (e.g. "original" vs "my own").

## Algorithm and Data Structure

### Algorithm

The overall `ft_printf` algorithm checks edge cases with format and arguments,
then parses the format for literal chars and format specifications, including
handling of the `'l'` length modifier for `long` type numbers.

***Why this algorithm?***

- **Personal Implementation**: I chose to build a custom algorithm to ensure the
  project remains entirely original and best reflects my understanding of it.

- **Iterative Learning**: Rather than collecting and integrating external
  algorithm ideas, I focused on developing and refining a solution internally,
  which effectively meets the project's current needs.

#### Starter Algorithm

1. Check whether the given `format` pointer is `NULL`.
   - If so, end immediately with an error, because there is no format string.
2. Check whether a percent sign `%` exists in the format string.
   - If not, write the full string to `stdout` and end, because there are no
     format specifications and no need for `va_*` utilities.
3. Initialize the variable argument list (`va_list`) with `va_start`.
4. Begin the Format Parsing Algorithm [.1].
5. Clean up the `va_list` pointer with `va_end`.
6. Return the total number of printed bytes.

#### [.1] Format Parsing Algorithm (`parse_and_write()`)

1. Traverse the `format` string until the null terminator (`\0`).
2. If the current character is `%`, begin Format Handling Algorithm [.2].
3. Otherwise, write each character literal to `stdout` until `%` or string end.
4. Return the number of bytes printed to `stdout`<sup>1</sup>.

<sup>1</sup> Bytes written in steps 2 and 3 are accumulated in `byte_count`.

#### [.2] Format Handling Algorithm (`handle_format()`)

1. Check if the character next to `%` is a length modifier (for example, `'l'`).
   - NOTE: This `ft_printf()` version only handles `'l'` for now. I have checked
     this build is the minimal functional one across integer type lengths,
     including `short` and `char`.
2. If it is, begin the Length Handling Algorithm [.3].
3. Otherwise, begin the Standard Specifier Handling Algorithm [.4].

#### [.3] Length Handling Algorithm (`handle_type_length()`)

1. Check if the current length modifier is `'l'`.
2. If so, begin the Long Specifier Handling Algorithm [.5].
3. Return the number of printed bytes from that algorithm.

#### [.4] Standard Specifier Handling Algorithm (`handle_specifier()`)

1. Check if current specifier `spec` is in _`cspdiuxX%`_.
   - Specifiers `cspdiuxX` use modular functions in `ft_printf_convs.c`
     (`*_conv()` functions) for argument retrieval, conversion, and printing.
   - Each conversion prints to `stdout` with `write()` once extracted and
     converted. The return from `write()` is stored in `bytes` for accumulation
     and final use as the return value of `ft_printf()`.
   - Specifier `%` just writes a percent sign to standard output.
2. If `spec` does not match any valid specifier, write an error message and
   return `-1` to signal an `ft_printf()` error.
3. If everything succeeds, return written byte count for the final accumulator.

#### [.5] Long Specifier Handling Algorithm (`handle_long_specs()`)

_This version of Specifier Handling triggers when `'l'` appears_
_before specifier._

1. Check if current specifier `spec` is in _`diuxX`_.
   - Specifiers `diuxX` use modular functions in `ft_printf_convs_long.c`
     (`*_conv_long()` functions) for retrieval, conversion, and printing.
   - Each conversion prints to `stdout` with `write()` once extracted and
     converted. The return from `write()` is stored in `bytes` for accumulation
     and final use as the return value of `ft_printf()`.
2. If `spec` does not match any valid specifier, write an error message and
   return `-1` to signal an `ft_printf()` error.
3. If everything succeeds, return written byte count for the final accumulator.

### My chosen Data Structure

For this implementation, I am not using data structures such as Linked Lists.
Rather, I am using pointers to traverse the format string (which is an array of
characters, which is a simple, linear data structure).

***Why this Data Structure***

- **Custom Logic Implementation**: While I could have relied on traditional
  linked list structures (with the assistance of libft functions), I resorted to
  a management system designed specifically for this project, from scratch.

- **Creative Problem Solving**: This approach aimed to tackle the challenge of
  complex format parsing and diverse conversions with some pre-existing utility functions made by myself (`libft`) as well as a limited list of `libc`
  functions (`malloc()`, `free()`, `write()` and the `va_*` utilities), thus
  allowing me to gain a **foundational understanding** of how _memory/index
  management_ works under the hood and how to extract and manipulate a non-fixed. 
  
#### Data Structure Description

I'm using the following key pointers throughout the code structure:

- **`str`**: in `chr_str_conv()`, I use a character pointer named `str` to store
  a given string argument and print it.

- **`str_form`**: in `dec_int_conv*()`  and `uint_conv*()`. This stores the
  integer argument once converted to its printable string equivalent.

- **`hex_str`**: in `hex_conv*()`. This is a pointer to a dynamically allocated
  memory area within the heap, specifically for the given integer number to
  convert to hexadecimal. This string will have the length of the integer
  number, as calculated by `ft_uintlen()` or `ft_ulonglen()`.

[man-printf]: https://man7.org/linux/man-pages/man3/printf.3.html
[wiki-printf]: https://en.wikipedia.org/wiki/Printf
[gnu-make]: https://www.gnu.org/software/make/manual/html_node/index.html
