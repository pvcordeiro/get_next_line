# Get Next Line

This project is part of the 42 School curriculum and aims to implement a function that reads a line from a file descriptor.

## 📚 Project Overview

The goal of this project is to create a function `get_next_line` that reads a line from a file descriptor and returns it. This function should be able to handle multiple file descriptors and manage memory efficiently.

## 🚀 Features

- Read a line from a file descriptor
- Efficient memory management
- The bonus function can handles multiple file descriptors at once

## 🛠️ Usage

To use the `get_next_line` function, include the header file and call the function with a file descriptor:

```c
#include "get_next_line.h"

int fd = open("file.txt", O_RDONLY);
char *line = get_next_line(fd);
while (line)
{
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
}
close(fd);
```

## 📁 Files

- `get_next_line.c`: Contains the implementation of the `get_next_line` function.
- `get_next_line.h`: Header file with function prototypes and necessary includes.
- `get_next_line_utils.c`: Utility functions used by `get_next_line`.
- `*bonus`: Same as above but can handle multiple file descriptors at once.

## 📝 License

This project is part of the 42 School curriculum and is intended for educational purposes.

Happy coding! 💻