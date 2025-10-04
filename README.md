# Brainfuck_translator

## Table of Contents

- [PROJECT OVERVIEW](#project-overview)
  - [BASICS](#basics)
    - [Some rules](#some-rules)
  - [USAGE](#usage)
  - [DEPENDENCIES](#dependencies)
  - [LIMITATIONS](#limitations)
  - [EXAMPLE](#example)
  - [AUTHOR](#author)



## PROJECT OVERVIEW

This project is a Brainfuck-to-C translator, written in C. It takes a Brainfuck source file and converts it into an equivalent C source file that, when compiled, will execute the same logic as the original Brainfuck program.

The goal is not to interpret Brainfuck directly at runtime, but rather to translate Brainfuck instructions into C, enabling you to compile the output into a native executable using any standard C compiler (e.g., gcc or clang).

----
<br>

### BASICS

The idea behind `brainfuck` is memory manipulation. Basically you are given an array of 30,000 1byte memory blocks. The array size is actually dependent upon the implementation used in the compiler or interpretor, but standard brainfuck states 30,000. Within this array, you can increase the memory pointer, increase the value at the memory pointer, etc. Let me first present to you the 8 operators available to us.

```brainfuck
> = increases memory pointer, or moves the pointer to the right 1 block.
< = decreases memory pointer, or moves the pointer to the left 1 block.
+ = increases value stored at the block pointed to by the memory pointer
- = decreases value stored at the block pointed to by the memory pointer
[ = like c while(cur_block_value != 0) loop.
] = if block currently pointed to's value is not zero, jump back to [
, = like c getchar(). input 1 character.
. = like c putchar(). print 1 character to the console
```

#### Some rules:

- Any arbitrary character besides the 8 listed above should be ignored by the
compiler or interpretor. Characters besides the 8 operators should be con-
sidered comments.

- All memory blocks on the "array" are set to zero at the beginning of the
program. And the memory pointer starts out on the very left most memory
block.

- Loops may be nested as many times as you want. But all [ must have a corre-
sponding ].

----
<br>

#### USAGE

To compile the translator:

```sh
make
```

To run the translator:

```sh
./bf2c input.bf output.c
```

Where:

`input.bf` is your Brainfuck source code file. <br>
`output.c` is the name of the generated C file.

📍 info: `input.bf` needs to exist, but `output.c` is created automatically<br>

Then compile the generated C file:

```sh
gcc output.c -o output
```

And finally run the compiled program:

```sh
./output
```

#### DEPENDENCIES

This project uses a custom libft which must contain at least:

`ft_printf()`
`ft_printf_fd()`
`get_next_line()`

Ensure these functions are correctly implemented and available in your libft directory. You can use your own version of libft or adapt an existing one.

#### LIMITATIONS

 - This translator assumes valid Brainfuck code. It does not perform syntax checks such as matching brackets ([ and ]).

 - Memory overflows are not checked. It is your responsibility to ensure your Brainfuck code does not exceed array boundaries.

 - The array is statically allocated to 3,000,000 bytes. You can change this in the write_opening() function if needed.

 #### EXAMPLE

Brainfuck Input (`example.bf`):

```sh
++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.
```

Run Translator:

```sh
./bf2c example.bf example.c
```

Compile and Run Output:

```sh
gcc example.c -o example
./example
```

Output:

```sh
Hello World!
```

#### AUTHOR

Project by mmiguelo.
This project is part of a personal initiative to uncover the secret message behind the 42project ft_printf encrypted message
