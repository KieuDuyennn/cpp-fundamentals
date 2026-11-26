# C++ Fundamentals

My C++ coursework from the first two years of my Information Systems degree at the University of Science, VNU-HCM (2023–2024).

I wrote this code for class, and I uploaded it in November 2026 from my original course submissions. Each `feat` commit dated 2023–2024 holds the code exactly as I submitted it, on the date I submitted it. In November 2026 I went back over the code and fixed the bugs I found; those fixes are separate commits with their real dates (see [Revisited in November 2026](#revisited-in-november-2026)). Exam submissions are not included.

## Courses

| Folder | Course | When | Topics |
|---|---|---|---|
| `01-introduction-to-programming` | Introduction to Programming (CSC10001) | Fall 2023 | I/O, conditions, loops, functions, 1D/2D arrays, structs |
| `02-programming-techniques` | Programming Techniques | Spring 2024 | Pointers, dynamic arrays, binary files, recursion, linked lists, stacks and queues |
| `03-object-oriented-programming` | Object-Oriented Programming | Fall 2024 | Classes, templates, inheritance, polymorphism, SOLID, Factory Method, dependency injection, parsing objects from text |

Folder names inside each course:

- `lab-wNN-inclass` and `lab-wNN-homework`: lab exercises for week NN
- `theory-hwNN` and `theory-wNN`: homework from the theory class
- `labNN-<topic>`: OOP lab projects

## Worth a look

- **BMP file reader** (`02-programming-techniques/theory-w07/bmp.cpp`): reads the BMP header, DIB header, color table and pixel array from a binary file with `fread`/`fseek`.
- **Linked lists, stacks and queues** (`02-programming-techniques/lab-w08-*`, `theory-w10-stack-queue`): built by hand with structs and raw pointers, including allocation and cleanup.
- **Polymorphism with a parser factory** (`03-object-oriented-programming/lab08-polymorphism`): employees and shapes parsed from text through an `IParsable` interface, a `ParserFactory`, and mock and real data-access objects.
- **Tax collecting mini project** (`03-object-oriented-programming/lab09-mini-projects/Project_TaxCollecting`): booth and fee hierarchies, a DAO that reads a text file, and table formatting for the report.

## Building

Every exercise builds with g++ on Linux, with warnings treated as errors:

```bash
python3 tools/build_all.py --strict
```

The script treats each folder with one `main()` as a program. GitHub Actions runs it on every push.

To build one program by hand, for example:

```bash
cd 03-object-oriented-programming/lab08-polymorphism/Shapes
g++ -std=c++17 -I./ -o ShapesApp ./models/*.cpp ./services/business/*.cpp ./services/data-access/*.cpp ./services/factory/*.cpp ./utils/*.cpp main.cpp
```

## Revisited in November 2026

Most of this code was first written in Visual Studio on Windows. When I moved it to g++ on Linux, ran it with `-Wall -Wextra` and AddressSanitizer, I found these problems and fixed them:

**Logic bugs**
- `ucln` (GCD) and the power-of-3 check looped forever; GCD now uses Euclid's algorithm (intro, lab week 6).
- N-queens backtracking recursed on the wrong branch and never undid a placement (programming techniques, lab week 7).
- The plantation bounding box picked whole points instead of the smallest x and largest y separately (programming techniques, week 1).
- The tax report sorted booth pointers by memory address, lost every booth ID, and printed a leading separator in totals (OOP, lab 9).
- Matrix border rotation mixed up rows and columns, and the symmetry check compared loop counters instead of matrix cells (intro, lab week 8).
- The taxi fare had an incomplete condition, a linear-equation check used `&` instead of `&&`, and the student comparators never returned 0 for equal keys.
- The monkey food report never read its input before computing (programming techniques, lab week 3).

**Memory and input safety**
- `bmp.h` was empty in my submission; I rewrote it from how `bmp.cpp` uses it, with packed structs checked by `static_assert`, and the tool now rejects files that are not uncompressed 24-bit BMPs.
- Fixed a buffer overflow in student input (`cin.get` read 105 chars into a 100-char array) and an unsigned underflow in table padding.
- Freed linked lists, stacks and tax booths that were leaking, and passed the stack by reference so popped nodes are deleted.
- Menus and input loops now stop at end of input instead of spinning forever.

**Portability and cleanup**
- Fixed include names that only worked on case-insensitive Windows filesystems, added missing `<cmath>` and `<cstring>` includes, and removed commented-out code and unused variables.
- Linked list input now appends through a tail pointer instead of walking the list for every node.
