*This project has been created as part of the 42 curriculum by Mohamed ENNIH.*

# 📄 get_next_line — Line-Oriented File Descriptor Reader

## Description

**get_next_line** is a systems programming project that consists of implementing a function capable of reading a file descriptor **one line at a time**, preserving internal state across successive calls. While seemingly simple, this problem exposes fundamental operating system concepts and enforces rigorous discipline in memory management, static state handling, and debugging practices.

This project is designed as a technical introduction to:

- **Operating System fundamentals**
- **UNIX file descriptors and system calls**
- **Persistent state through static variables**
- **Dynamic memory management and leak prevention**
- **Low-level debugging methodologies**
- **Streaming algorithms and buffered I/O design**

It bridges theoretical OS concepts and real-world systems programming by recreating a core runtime abstraction: *incremental, buffered file reading*.

---

## 🧠 Core Learning Objectives

### 🏗️ 1. Introduction to Operating Systems

This project builds a foundational understanding of how programs interact with the OS kernel:

#### 🔹 Dual Mode Operation
- **User mode:** Application code executes without direct hardware access.
- **Kernel mode:** System calls transition execution into privileged OS code.

`get_next_line` operates entirely in user mode but interacts with kernel resources through controlled transitions using system calls.

---

#### 🔹 System Calls

The project revolves around these key system calls:

 `open()` : Opens a file and returns a file descriptor 
 `read()` : Transfers bytes from kernel buffers to user memory 
 `lseek()`: Changes file offset (forbidden in this project) 

By using `read()` only, this project enforces **sequential stream processing**, mirroring real-world buffered I/O design.

---

#### 🔹 File Descriptors

A **file descriptor (fd)** is a small integer representing an open file, pipe, socket, or device. It abstracts all I/O resources behind a uniform interface.  
`get_next_line(fd)` must behave correctly regardless of whether `fd` refers to:

- A regular file
- Standard input (`stdin`)
- Pipes or redirected streams

This reinforces the OS principle that *everything is a file*.

---

### 🧠 2. Static Variables — Persistent State Across Calls

This project introduces **static variables** as a mechanism for maintaining memory across function invocations:

```c
static char *stash;
```
Unlike automatic variables:

They persist for the program’s entire lifetime

They retain values between calls

They enable stateful streaming algorithms

Here, static storage preserves unread data across calls to get_next_line, enabling partial reads to be resumed correctly.

### 💾 3. Memory Persistence, Ownership & Leak Prevention

This project demands:

Safe heap allocation and deallocation

Clear ownership transfer of returned buffers

Cleanup on errors and EOF

Avoidance of:

Memory leaks

Dangling pointers

Double frees

Since get_next_line repeatedly allocates memory for lines and internal buffers, it becomes a practical laboratory for mastering memory lifecycle discipline.

### 🛠️ 4. Introduction to Debugging

This project is specifically designed to strengthen debugging skills using:

🔹 Valgrind

Detects memory leaks

Reports invalid reads/writes

Identifies double frees

🔹 GDB

Steps through buffer evolution

Inspects pointer states

Tracks segmentation faults and undefined behavior

Due to the persistent state and dynamic allocation involved, get_next_line provides a realistic environment for learning professional debugging workflows.

### 🧩 Algorithm Design & Justification
🎯 Problem Constraints

The function must:

Read from a file descriptor incrementally

Return exactly one line per call

Preserve unread data across calls

Handle arbitrarily long lines

Work with any BUFFER_SIZE

Avoid lseek()

Avoid global variables

#### 🏗️ Chosen Algorithm: Persistent Buffer Accumulation

The solution is based on a stateful buffered stream parser built around a persistent static buffer (often called stash):

🔄 Algorithm Steps

Persistent Storage

A static buffer stores leftover bytes from previous reads.

Buffered Reading Loop

Read BUFFER_SIZE bytes from fd into a temporary buffer.

Append the result to the persistent buffer.

Stop when:

A newline is found

EOF is reached

An error occurs

Line Extraction

Extract the substring up to and including \n (if present).

Allocate and return this line.

Remainder Preservation

Store leftover bytes after the newline back into the static buffer.

Termination

On EOF with no remaining data, return NULL.

## Instructions

### Compilation :

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

### 🧹 Cleanup Rules

Caller must free() each returned line.

Function internally frees persistent buffers on EOF or error.

## Resources

📖 Documentation & References

man 2 read

man 2 open

man 2 close

man 3 malloc

man 3 free

man 3 static

Advanced Programming in the UNIX Environment — Stevens & Rago

Operating Systems: Three Easy Pieces — Remzi Arpaci-Dusseau

## 🏁 Conclusion

This project establishes mastery of:

UNIX file descriptor I/O

Static memory persistence across calls

Streaming buffer algorithms

Dynamic memory ownership

Debugging memory errors in real systems code

get_next_line becomes both a reusable utility and a critical stepping stone toward advanced systems programming, preparing students for real-world I/O pipelines, parsers, and runtime library development.

👤 Mohamed ENNIH