# PIPEX

```text
██████╗ ██╗██████╗ ███████╗██╗  ██╗
██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝
██████╔╝██║██████╔╝█████╗   ╚███╔╝ 
██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗ 
██║     ██║██║     ███████╗██╔╝ ██╗
╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝
```

> **Pipex** is a 42 school project that replicates the behavior of the shell pipe `|` operator. It explores inter-process communication (IPC) using `pipe()`, process creation with `fork()`, and command execution with `execve()`, while properly managing file descriptors and environment variables.

---

## 🛠️ Compilation

Use the provided `Makefile` to compile the project.

**Mandatory version:**
```bash
make
```

**Bonus version (Multiple pipes & here_doc):**
```bash
make bonus
```

**Other available rules:**
* `make clean` : Removes object files.
* `make fclean` : Removes object files and the executable.
* `make re` : Recompiles the entire project.

---

## 🚀 Usage & Execution

### Mandatory Part
The program takes 4 arguments: an input file, two commands, and an output file.
It behaves exactly like the shell command: `< infile cmd1 | cmd2 > outfile`

```bash
./pipex infile "cmd1" "cmd2" outfile
```
**Example:**
```bash
./pipex infile "ls -l" "wc -l" outfile
```

### Bonus Part
The bonus handles multiple pipes and the `here_doc` feature.

**Multiple pipes:**
It behaves like: `< infile cmd1 | cmd2 | cmd3 ... | cmdn > outfile`
```bash
./pipex infile "cmd1" "cmd2" "cmd3" ... "cmdn" outfile
```

**Here_doc (`<<` and `>>`):**
It behaves like: `cmd1 << LIMITER | cmd2 >> outfile`
```bash
./pipex here_doc LIMITER "cmd1" "cmd2" outfile
```

---

## 🐛 Debugging & File Descriptor Check

For `pipex`, it is crucial to check for both memory leaks **and** open file descriptors (to ensure all your pipes and files are properly closed).

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./pipex infile "ls -l" "wc -l" outfile
```

---

## 📝 Evaluation

Useful links for the correction:
* [42 Evaluation Sheet - Pipex](https://wormav.github.io/42_eval/Cursus/Pipex/index.html)
