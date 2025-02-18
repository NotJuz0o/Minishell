# MiniShell1

A UNIX command interpreter based on TCSH shell, implemented in C. This project is a stepping stone towards the 42sh project, focusing on basic shell functionality.

## Description

MiniShell1 is a simple shell implementation that provides basic command-line interface functionality. It displays a prompt and executes basic commands found in the PATH or with direct paths.

### Features

- Command prompt display (`$>`)
- Command execution with PATH handling
- Environment management using dynamic array
- Builtin commands management using hash table
- Error handling with appropriate messages
- Built-in commands implementation:
  - `cd`: Change directory
  - `setenv`: Set environment variable
  - `unsetenv`: Unset environment variable
  - `env`: Display environment variables
  - `exit`: Exit the shell

### Limitations

- No pipes
- No redirections
- No advanced features
- `env` builtin doesn't accept arguments
- `unsetenv` builtin doesn't support "*" wildcard

## Implementation Details

### Hash Table for Builtins
The hash table implementation is used to store function pointers for builtin commands, providing:
- Efficient O(1) lookup of builtin commands
- Easy registration of new builtin commands
- Clean separation between command lookup and execution

### Dynamic Array for Environment
A dynamic array structure is used to manage environment variables, allowing:
- Creation of a modifiable copy of the initial environment
- Dynamic modification of environment variables (setenv/unsetenv)
- Efficient memory management for environment changes

## Project Structure

```
.
├── includes
│   ├── minishell.h    # Main shell header
│   ├── my.h           # Utility functions header
│   └── secured.h      # Security-related definitions
├── lib
│   ├── hash           # Hash table for builtin commands
│   │   ├── includes
│   │   ├── src
│   │   └── Makefile
│   └── my             # Custom utility library
│       ├── includes
│       ├── src
│       └── Makefile
├── Makefile
└── src
    ├── builtins       # Shell builtin commands
    │   ├── cd.c
    │   ├── env.c
    │   ├── exit.c
    │   ├── setenv.c
    │   └── unsetenv.c
    ├── concat.c       # String concatenation utilities
    ├── dynamic_array.c # Environment variables management
    ├── errors_management.c
    ├── executor.c     # Command execution
    ├── init.c         # Shell initialization
    ├── main.c
    ├── minishell.c    # Core shell implementation
    └── parser.c       # Command parsing
```

## Libraries

### Hash Library
Custom hash table implementation for storing builtin command function pointers:
- Efficient command lookup
- Function pointer storage and retrieval
- Memory management for command table

### My Library
Custom utility functions:
- String manipulation (strlen, strcpy, strcat, etc.)
- Memory operations (memcpy, memset, realloc)
- String parsing and tokenization
- Character type checking

## Getting Started

### Prerequisites

- GCC compiler
- Make build system
- UNIX-like operating system

### Installation

1. Clone the repository:
```bash
git clone [repository-url]
cd minishell1
```

2. Build the project:
```bash
make
```

This will compile both libraries and the main shell executable.

### Usage

Run the shell:
```bash
./mysh
```

Example commands:
```bash
$> pwd
/tmp
$> cd test
$> pwd
/tmp/test
$> setenv MY_VAR value
$> env
MY_VAR=value
[...]
$> exit
```

## Technical Details

### Return Values

The minishell returns the same exit status as the executed command:
- Success (0): Command executed successfully
- Error (various non-zero values): Command failed
- Error (84): Internal minishell error

### Environment Management

The shell maintains a dynamic copy of the environment variables that can be:
- Modified using setenv/unsetenv builtins
- Expanded/shrunk as needed
- Restored to its initial state when required

### Builtin Commands

Builtin commands are stored in a hash table for efficient lookup and execution. Each builtin is registered with:
- Command name as the key
- Function pointer as the value
- Consistent function signature for all builtins

### Compilation

The project includes Makefiles at different levels:
- Root Makefile: Builds the entire project
- Library Makefiles: Build individual libraries

Commands:
- `make`: Build the project
- `make clean`: Remove object files
- `make fclean`: Remove object files and executable
- `make re`: Rebuild the project

### Error Handling

All error messages are written to the error output (stderr). The program exits with:
- Code 84: When an error occurs
- Code 0: Normal execution
- Command's exit status: When executing external commands

## Contributors

- NotJuz0o

## License

This project is part of the EPITECH curriculum.
