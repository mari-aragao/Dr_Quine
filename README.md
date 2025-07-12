# Dr_Quine

The idea of this project is to create self-replicating programs by implementing quines in C and Assembly, without reading the source file or using any external input. These programs explore key concepts such as metaprogramming, recursion, and fixed-point theory, providing a practical introduction to more advanced topics like malware development.

## Programs
| Program       | Description                                 |
|---------------|---------------------------------------------|
| Colleen       | Prints its own source to standard output. Must include a `main` function, an additional function and two comments. |
| Grace         | Replicates itself into a new file. Must run using a macro, with no `main` function and exactly three `#defines`. |
| Sully         | Recursively replicates itself into new files by decrementing a counter. Each new file is compiled and executed until the counter is below zero. |

## Project Structure
```
.
├── ASM/
│ ├── Colleen.s
│ ├── Grace.s
│ ├── Sully.s
│ └── Makefile
├── C/
│ ├── Colleen.c
│ ├── Grace.c
│ ├── Sully.c
│ └── Makefile
└── README.md
```

## How to Compile and Run

```bash
cd C       # for C programs
# or
cd ASM     # for Assembly programs

# Compile all C programs
make

# Run Colleen and compare output
./Colleen > tmp_Colleen && diff tmp_Colleen Colleen.c

# Run Grace and compare output
./Grace && diff Grace.c Grace_kid.c

# Run Sully
./Sully
```