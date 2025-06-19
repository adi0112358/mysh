# 🐚 MyShell - A Unix-like Shell in C++

A lightweight, custom-built shell written in C++.  
Supports basic command execution, background jobs (`&`), and signal handling (`Ctrl+C`, `Ctrl+Z`).  

> 🚀 Built from scratch to understand OS internals and terminal process control.

---

## ⚙️ Features

- ✅ Run external commands (e.g. `ls`, `pwd`, `sleep 10`)
- ✅ Built-in `cd` command
- ✅ Background process execution (`sleep 5 &`)
- ✅ `Ctrl+C` to kill foreground processes
- ✅ `Ctrl+Z` to suspend foreground processes
- ✅ Suspended jobs are tracked in memory (`std::map`)
- 🔜 Upcoming: `jobs`, `fg`, `bg`, I/O redirection, piping

---

## 🏗️ Build Instructions

### Requirements
- Linux/macOS (UNIX-like terminal)
- `g++` installed
- `make`

### Build
```bash
make
```
### Run
```bash
./mysh
```
### Project Structure

```
mysh/
├── src/
│   └── main.cpp         # Shell logic
├── Makefile             # Build script
├── README.md            # Project info
```
## 📜 License

MIT License — feel free to use or contribute!

---

## 🪄 Want Extras?

Let me know if you'd like:
- A project **logo or banner**
- A GitHub Actions workflow (CI build/test)
- A `.gif` demo of the shell in action
- GitHub tags (`system-programming`, `cpp-shell`, etc.)
- A simple `LICENSE` file to go with MIT license

I'll generate them for you!
