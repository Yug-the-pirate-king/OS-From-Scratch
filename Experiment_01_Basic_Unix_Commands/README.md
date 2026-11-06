# Experiment 1: Basic and Essential Unix Commands

> **Author:** Yug Shah (TYCSE)  
> **Repository:** Os from scratch  
> **Course:** Operating Systems Lab  

## 1. Aim
To learn and practice basic and essential Unix commands.

## 2. Course Outcome & Learning Objectives
- **Course Outcome:** Understand the working of a Unix-based operating system.
- **Learning Objectives:**
  - Understand the hierarchical Unix file system tree.
  - Master essential directory management commands (`pwd`, `cd`, `mkdir`, `rmdir`).
  - Perform file manipulation operations (`touch`, `cp`, `mv`, `rm`).
  - View, inspect, and paginate file content (`cat`, `more`, `less`).
  - Configure file and directory permissions (`chmod`).
  - Monitor and control processes (`ps`, `ps -ef`, `kill`, `kill -9`).
  - Monitor disk space and storage utilization (`df -h`, `du -sh`).

---

## 3. Related Theory

Unix is a powerful multi-user, multitasking operating system designed with simplicity, modularity, and clean abstraction. In Unix, **"Everything is a file"**—including regular text documents, directories, hardware device interfaces, and inter-process communication sockets.

Users interact with the Unix kernel via a **command-line shell** (such as Bash). Commands are entered at the shell prompt, parsed, and executed.

### Command Categories Overview
1. **Directory Operations**: Navigating and structuring directory trees.
2. **File Operations**: Creating, duplicating, relocating, and removing files.
3. **File Listing**: Inspecting file metadata, timestamps, and hidden files.
4. **File Viewing**: Displaying text with pagination and scrolling.
5. **Permissions Management**: Controlling read (`r=4`), write (`w=2`), and execute (`x=1`) bits for User, Group, and Others.
6. **Process Management**: Tracking active process IDs (PID) and dispatching termination signals (`SIGTERM`, `SIGKILL`).
7. **Disk and System Information**: Tracking filesystem block consumption and directory size footprints.

---

## 4. Comprehensive Command Reference

### 4.1 Directory Operations

| Command | Syntax | Description | Example |
| :--- | :--- | :--- | :--- |
| `pwd` | `pwd` | Prints the absolute path of the current working directory. | `$ pwd` &rarr; `/home/user/Documents` |
| `cd` | `cd [directory]` | Changes current directory. `cd ..` goes up one level; `cd ~` goes to home. | `$ cd test_folder` |
| `mkdir` | `mkdir [options] <dir>` | Creates one or more directories. Flag `-p` creates nested parent directories. | `$ mkdir -p project/src` |
| `rmdir` | `rmdir <dir>` | Removes empty directories only. | `$ rmdir old_folder` |

### 4.2 File Operations

| Command | Syntax | Description | Example |
| :--- | :--- | :--- | :--- |
| `touch` | `touch <file>` | Creates an empty file or updates the access/modification timestamps of an existing file. | `$ touch sample.txt` |
| `cp` | `cp [options] <src> <dest>` | Copies files or directories (use `-r` for recursive directory copy). | `$ cp file1.txt backup.txt` |
| `mv` | `mv <source> <dest>` | Renames a file or moves it to a different directory. | `$ mv old.txt new.txt` |
| `rm` | `rm [options] <file>` | Deletes files. Use `-r` for recursive directory deletion, `-f` for force. | `$ rm sample.txt` |

### 4.3 Listing Files

| Command | Syntax | Description | Example |
| :--- | :--- | :--- | :--- |
| `ls` | `ls [options] [path]` | Lists directory contents. Common flags: `-l` (long format), `-a` (all including hidden), `-h` (human-readable sizes). | `$ ls -lah` |

### 4.4 Viewing File Contents

| Command | Syntax | Description | Example |
| :--- | :--- | :--- | :--- |
| `cat` | `cat [options] <file>` | Concatenates and displays file contents on standard output. | `$ cat notes.txt` |
| `more` | `more <file>` | Paginates file output (spacebar scrolls forward, `q` exits). | `$ more system.log` |
| `less` | `less <file>` | Advanced pager with both forward and backward navigation, search, and memory efficiency. | `$ less access.log` |
| `head` | `head -n <lines> <file>`| Shows the first $N$ lines (default 10). | `$ head -n 5 file.txt` |
| `tail` | `tail -n <lines> <file>`| Shows the last $N$ lines. Flag `-f` streams new lines dynamically. | `$ tail -f server.log` |

### 4.5 File Permissions (`chmod`)

In Unix, each file has three sets of permissions:
1. **User (Owner)** (`u`)
2. **Group** (`g`)
3. **Others** (`o`)

Each set has 3 permission bits:
- Read (`r` = 4)
- Write (`w` = 2)
- Execute (`x` = 1)

**Octal Representation:**
- `755` = `rwxr-xr-x` (Owner: read/write/execute, Group: read/execute, Others: read/execute)
- `644` = `rw-r--r--` (Owner: read/write, Group: read, Others: read)
- `700` = `rwx------` (Owner: full access, Others: no access)

**Examples:**
```bash
chmod 755 script.sh     # Set numeric permissions
chmod +x script.sh      # Make executable for all
chmod u=rwx,go=rx app   # Symbolic notation
```

### 4.6 Process Management

| Command | Description | Example |
| :--- | :--- | :--- |
| `ps` | Displays processes running in the current terminal session. | `$ ps` |
| `ps -ef` / `ps aux` | Lists all active processes across the entire operating system in full format. | `$ ps -ef` |
| `kill <pid>` | Sends `SIGTERM` (signal 15) politely asking the process to terminate and flush buffers. | `$ kill 1234` |
| `kill -9 <pid>` | Sends `SIGKILL` (signal 9) which unconditionally terminates the process immediately. | `$ kill -9 1234` |
| `top` / `htop` | Real-time interactive system process and resource monitor. | `$ top` |

### 4.7 Disk & System Information

| Command | Syntax | Description | Example |
| :--- | :--- | :--- | :--- |
| `df -h` | `df -h` | "Disk Free" – Displays mounted filesystem disk usage in human-readable units (GB, MB). | `$ df -h` |
| `du -sh <dir>`| `du -sh <dir>` | "Disk Usage" – Calculates total space occupied by a directory (`-s` summary, `-h` human readable). | `$ du -sh mydir` |
| `free -m` | `free -m` | Displays total, used, and free RAM and swap memory in megabytes. | `$ free -m` |
| `uname -a` | `uname -a` | Displays OS kernel name, version, host architecture, and build timestamp. | `$ uname -a` |

---

## 5. Lab Demonstration Script

A bash script `demo_commands.sh` is provided in this folder. It automatically creates a sandbox environment, demonstrates each command family step by step, and cleans up afterwards.

### Execution Instructions
```bash
# Make script executable
chmod +x demo_commands.sh

# Run the demonstration
./demo_commands.sh
```

---

## 6. Viva Voce & Interview Questions with Answers

### Q1: What is the difference between an absolute path and a relative path in Unix?
**Answer:**
- **Absolute Path:** Starts from the root directory (`/`) and specifies the complete directory chain regardless of current working directory (e.g., `/home/student/lab/exp1.txt`).
- **Relative Path:** Starts from the current working directory without a leading slash (e.g., `lab/exp1.txt` or `../exp2.txt`).

### Q2: What is the difference between `kill <pid>` and `kill -9 <pid>`?
**Answer:**
- `kill <pid>` sends `SIGTERM` (Signal 15). The process can intercept/catch this signal, perform cleanup routines (such as flushing buffers, closing sockets, and saving state), and terminate cleanly.
- `kill -9 <pid>` sends `SIGKILL` (Signal 9). It cannot be caught, blocked, or ignored by the process. The operating system kernel immediately reclaims the process resources, potentially leaving child processes orphaned or files half-written.

### Q3: What do the permission bits `755` and `644` mean?
**Answer:**
Permissions are broken down into triplets: User, Group, Others.
- `755` = `(4+2+1)(4+0+1)(4+0+1)` = `rwxr-xr-x`. The owner has read, write, and execute permissions; group and others have read and execute permissions.
- `644` = `(4+2+0)(4+0+0)(4+0+0)` = `rw-r--r--`. The owner has read and write permissions; group and others have read-only permissions.

### Q4: What is the purpose of the `-p` flag in `mkdir`?
**Answer:**
The `-p` (parents) flag creates parent directories as needed without throwing an error if they already exist. For example, `mkdir -p a/b/c` creates `a`, `a/b`, and `a/b/c` in a single command.

### Q5: What is the difference between `more` and `less`?
**Answer:**
- `more` is a primitive pager that only allows forward navigation line by line or page by page.
- `less` allows forward and backward navigation, fast searching with `/`, and does not read the entire file before starting, making it vastly faster and more memory efficient for large logs.

### Q6: What is the difference between `df` and `du`?
**Answer:**
- `df` (disk free) reports the total, used, and available space on mounted filesystems by inspecting filesystem superblock metadata.
- `du` (disk usage) tracks disk space used by a specific directory or file by traversing its sub-directories and summing up file sizes.

---

## 7. Conclusion
This experiment provided hands-on experience with fundamental Unix command-line utilities. Proficiency in directory navigation, file manipulation, permission configuration, and process management forms the bedrock for advanced shell scripting and system programming.

