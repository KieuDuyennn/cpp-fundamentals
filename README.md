# C++ Fundamentals

My C++ coursework from the first two years of my Information Systems degree at the University of Science, VNU-HCM (2023–2024).

I wrote this code for class, and I uploaded it in November 2026 from my original course submissions. Each commit uses the date I submitted that assignment, so the history shows when the code was written, not when it was uploaded. Exam submissions are not included.

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

Most of this code was written in Visual Studio on Windows. Many exercises build with g++ as they are, for example:

```bash
cd 03-object-oriented-programming/lab08-polymorphism/Shapes
g++ -std=c++17 -I./ -o ShapesApp ./models/*.cpp ./services/business/*.cpp ./services/data-access/*.cpp ./services/factory/*.cpp ./utils/*.cpp main.cpp
```

Some exercises still need MSVC, because they rely on case-insensitive include names or on headers that MSVC includes implicitly (`<cstring>`, `<cmath>`). I kept the code as I submitted it. A few Vietnamese strings were saved in a legacy encoding and now show as `?`.
