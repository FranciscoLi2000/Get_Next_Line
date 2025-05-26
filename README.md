# 📄 Get Next Line – 42 Barcelona Project

Welcome to my implementation of the `get_next_line` function, a core project at [42 Barcelona](https://42barcelona.com/). This project focuses on reading a file line by line, handling various edge cases, and managing memory efficiently in C.

---

## 🧠 Project Overview

The `get_next_line` function reads a line from a file descriptor and returns it, including the newline character (`\n`) if present. It must handle:

- Reading from multiple file descriptors simultaneously.
- Lines of unknown length.
- Efficient memory allocation and deallocation.
- Error handling and end-of-file conditions.

This project enhances understanding of file I/O operations, dynamic memory management, and string manipulation in C.

---

## 🗂️ Repository Structure

Get_Next_Line/
├── includes/
│ ├── get_next_line.h
│ ├── get_next_line_bonus.h
│ └── libft.h
├── libft/
│ └── [Libft utility functions]
├── srcs/
│ └── get_next_line.c
├── bonus/
│ ├── get_next_line_bonus.c
│ └── get_next_line_utils_bonus.c
├── en.getnextline.pdf
├── en.born2beroot.pdf
├── LICENSE
└── README.md


- `includes/`: Header files for the main and bonus implementations.
- `libft/`: Custom implementations of standard C library functions.
- `srcs/`: Source file for the main `get_next_line` function.
- `bonus/`: Bonus implementation supporting multiple file descriptors.
- `en.getnextline.pdf`: Project subject PDF.
- `en.born2beroot.pdf`: The documentation for the Virtual Machine Installation.

---

## 🔍 Algorithmic Approach

### Main Implementation (`get_next_line.c`)

1. **Reading Buffer**: Continuously read from the file descriptor into a buffer until a newline character is found or EOF is reached.
2. **Extracting Line**: Identify and extract the line up to and including the newline character.
3. **Updating Buffer**: Adjust the buffer to remove the extracted line, preparing it for the next read.
4. **Memory Management**: Ensure all allocated memory is properly managed to prevent leaks.

### Bonus Implementation (`get_next_line_bonus.c`)

- Utilizes a linked list (`t_list`) to manage buffers for multiple file descriptors.
- Each node in the list corresponds to a file descriptor and its associated buffer.
- Ensures simultaneous reading from multiple file descriptors without data collision.

---

## Usage

To compile and use the `get_next_line` function:

1. **Clone the Repository**:
```
   git clone https://github.com/FranciscoLi2000/Get_Next_Line.git
   cd Get_Next_Line
```

2. Compile:
```
gcc -Wall -Wextra -Werror -Iincludes srcs/get_next_line.c libft/*.c -o get_next_line
```

3. Run:
```
./get_next_line
```

For the bonus version supporting multiple file descriptors:
```
gcc -Wall -Wextra -Werror -Iincludes bonus/get_next_line_bonus.c libft/*.c -o get_next_line_bonus
./get_next_line_bonus
```

## 🧪 Testing
To test the get_next_line function:

1. Create a Test File:
```
echo -e "Line 1\nLine 2\nLine 3" > test.txt
```

2. Run the Program:
```
./get_next_line test.txt
```
Ensure to handle various edge cases, such as empty files, files without newline characters, and large files.

## 📚 Resources

42 Get Next Line Guide(https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line)

Understanding File Descriptors and I/O in C(https://dev.to/aerrfig/get-next-line-a-42-project-to-learn-how-to-deal-with-file-descriptors-and-io-of-system-3652)

Memory Management in C(https://medium.com/@ayogun/master-file-i-o-operations-with-42s-get-next-line-project-5fb001d1fff5)

## 🧑‍💻 Author: yufli

Email: liyufeng577@gmail.com

Feel free to reach out for collaboration or feedback!

## 📄 License

This project is licensed under the MIT License. See the LICENSE file for details.

---

Feel free to customize this `README.md` further to reflect your personal experiences, challenges faced, and lessons learned during the project. Including such details can provide deeper insights into your problem-solving approach and dedication.

If you need assistance with other projects or further enhancements to your GitHub profile, feel free to ask!
::contentReference[oaicite:0]{index=0}

