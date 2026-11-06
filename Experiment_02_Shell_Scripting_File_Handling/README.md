# Experiment 2: Shell Scripting for File Handling Operations

> **Author:** Yug Shah (TYCSE)  
> **Repository:** Os from scratch  
> **Course:** Operating Systems Lab  

## 1. Aim
To write and execute shell programs for performing file handling operations such as creating, reading, copying, moving, deleting files, and checking file properties in a Unix/Linux environment.

## 2. Course Outcome & Learning Objectives
- **Course Outcome:** Understand the basics of shell scripting in Unix/Linux. Develop shell programs to automate file handling tasks.
- **Learning Objectives:**
  - Learn the structure, syntax, and execution flow of shell scripts.
  - Implement conditional statements (`if-then-else-fi`) to inspect file attributes.
  - Automate file manipulation (creation, redirection `>`, append `>>`, copying `cp`, deleting `rm`).
  - Read files line-by-line using `while read` streams.
  - Search text using `grep` within scripted workflows.

---

## 3. Related Theory

### 3.1 What is a Shell?
A shell is a command language interpreter that executes commands entered by users or read from a script file. It acts as an interface between the user/application layer and the OS kernel.

Common shells include:
- `sh` (Bourne Shell) – original Unix shell.
- `bash` (Bourne Again Shell) – standard shell on most modern Linux distributions.
- `ksh` (Korn Shell) – combines features of C-shell and Bourne shell.
- `csh` / `tcsh` – C shell with C-like syntax.
- `zsh` (Z Shell) – extended bash with advanced themes and auto-completion.
- `fish` (Friendly Interactive Shell) – user-focused modern shell.

To check your active shell:
```bash
echo $0
```

To list all shells installed on the system:
```bash
cat /etc/shells
```

### 3.2 What is a Shell Script?
A shell script is an executable text file containing a sequence of commands executed sequentially by an interpreter.

The first line of a bash script typically starts with the **shebang**:
```bash
#!/bin/bash
```
The shebang tells the operating system kernel which program interpreter should be spawned to parse and run the script.

### 3.3 File Test Operators in Bash
When writing conditional checks (`[ condition ]` or `[[ condition ]]`):

| Test Operator | Meaning / Evaluation |
| :--- | :--- |
| `[ -e "$file" ]` | True if the file exists (regardless of type). |
| `[ -f "$file" ]` | True if the file exists and is a regular file. |
| `[ -d "$file" ]` | True if the file exists and is a directory. |
| `[ -s "$file" ]` | True if the file exists and its size is greater than zero bytes. |
| `[ -r "$file" ]` | True if the file exists and is readable. |
| `[ -w "$file" ]` | True if the file exists and is writable. |
| `[ -x "$file" ]` | True if the file exists and is executable. |

### 3.4 I/O Redirection
- `>` : Overwrites output to a file (creates if not existing).
- `>>` : Appends output to the end of an existing file.
- `<` : Reads standard input from a file.
- `2>` : Redirects standard error stream.

---

## 4. Program Index & Descriptions

| Filename | Purpose | Key Commands Used |
| :--- | :--- | :--- |
| `01_first.sh` | Introductory Hello World script | `echo` |
| `02_file_check_read.sh` | Checks if file exists; displays contents | `if [ -f ]`, `cat` |
| `03_check_file_exists.sh` | Basic existence verification | `if [ -f ]` |
| `04_create_write_file.sh` | Creates file and writes text into it | `read`, `echo >` |
| `05_count_lines_words_chars.sh` | Counts lines, words, and characters | `wc` |
| `06_append_file.sh` | Appends user content to end of file | `echo >>` |
| `07_display_line_by_line.sh` | Iterates over file line by line | `while read line; do ... done < file` |
| `08_copy_file.sh` | Copies content from source to destination | `cp` |
| `09_search_word.sh` | Searches for a pattern/keyword in file | `grep` |
| `10_delete_file.sh` | Safely removes/deletes a file | `rm` |
| `11_file_manager_menu.sh` | Integrated menu-driven interactive utility | `case`, `while true`, functions |

---

## 5. How to Run

### Step 1: Grant Execute Permissions
```bash
chmod +x *.sh
```

### Step 2: Execute Any Script
```bash
# Direct execution:
./01_first.sh

# Or invoke with bash explicitly:
bash 04_create_write_file.sh

# Run the all-in-one menu manager:
./11_file_manager_menu.sh
```

---

## 6. Sample Inputs & Outputs

### Running `04_create_write_file.sh`
```text
Enter file name:
notes.txt
Enter content to write:
Operating Systems Lab File Handling
Content written successfully.
```

### Running `05_count_lines_words_chars.sh`
```text
Enter file name:
notes.txt
 1  5 36 notes.txt
```
*(1 line, 5 words, 36 characters)*

### Running `08_copy_file.sh`
```text
Enter source file:
notes.txt
Enter destination file:
backup.txt
File copied successfully.
```

### Running `10_delete_file.sh`
```text
Enter file name to delete:
backup.txt
File deleted successfully.
```

---

## 7. Viva Voce & Interview Questions with Answers

### Q1: What is the significance of the first line `#!/bin/bash` in a shell script?
**Answer:**
This line is called the **shebang** or **hashbang**. The kernel reads the characters `#!` at the very beginning of an executable file to determine the absolute path of the interpreter to run (in this case `/bin/bash`), passing the script file path as an argument.

### Q2: What is the difference between `>` and `>>` operators?
**Answer:**
- `>` is the **overwrite** redirection operator. If the target file exists, its previous content is truncated to 0 bytes before writing.
- `>>` is the **append** redirection operator. It keeps the existing content intact and appends new content to the end of the file.

### Q3: What is the purpose of `IFS= read -r line` in bash?
**Answer:**
- `IFS=` (Internal Field Separator set to empty) prevents leading and trailing whitespace characters (tabs, spaces) from being trimmed.
- `-r` prevents backslash escapes from being interpreted (e.g., `\n` or `\t` won't be swallowed), preserving raw lines faithfully.

### Q4: How does `if [ -f "$file" ]` differ from `if [ -e "$file" ]`?
**Answer:**
- `-e` checks if any filesystem entity exists at that path, including directories, FIFOs, sockets, device nodes, or regular files.
- `-f` strictly checks that the entity exists AND is a **regular file** (not a directory or socket).

### Q5: How do you pass and read command-line arguments in a shell script?
**Answer:**
Positional parameters are used:
- `$0` = Name of the script
- `$1, $2, ... $9` = First, second, ... ninth argument
- `$#` = Total number of arguments passed
- `$*` and `$@` = All arguments as a string / array
- `$?` = Exit status of the most recent command (0 indicates success).

---

## 8. Conclusion
The experiment demonstrated the fundamentals of shell scripting in Unix/Linux. Students gain proficiency in conditional statements, file existence validation, stream redirection, and automating routine file management operations without manual interaction.

