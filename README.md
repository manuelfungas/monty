# Monty Interpreter in C

## Overview

This is a simple Monty interpreter implemented in C. Monty is a minimalistic programming language that is similar to Python, designed for learning and teaching purposes. This interpreter reads Monty code from a file and executes it line by line.

## Features

- Supports basic stack operations: push and pop.
- Arithmetic operations: add, subtract, multiply, divide, and modulo.
- Command to print all values currently in the stack (pall).

## Usage

### Compilation

To compile the Monty interpreter, run the following command:

```bash
 gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

### Execution

To execute a Monty program, run the compiled executable with the Monty code file as an argument:

```bash
monty <filename>
```

Replace `<filename>` with the path to your Monty code file.

## Monty Code Syntax

The Monty language uses a stack data structure for its operations. Each operation is written on a separate line in the Monty code file.

### Example Monty Code:

```monty
push 1
push 2
push 3
pall
add
pall
```

### Output:

```
3
2
1
5
2
1
```

## Supported Operations

- **push \<value\>**: Pushes an integer onto the stack.
- **pop**: Removes the top element from the stack.
- **add**: Adds the top two elements of the stack.
- **sub**: Subtracts the top element of the stack from the second top element.
- **mul**: Multiplies the top two elements of the stack.
- **div**: Divides the second top element of the stack by the top element.
- **mod**: Computes the modulo of the second top element of the stack divided by the top element.
- **pall**: Prints all the values on the stack, starting from the top.

## Error Handling

- The interpreter handles errors such as stack underflow, division by zero, and unknown instructions.
- Proper error messages are displayed for easier debugging.

## Contributing
