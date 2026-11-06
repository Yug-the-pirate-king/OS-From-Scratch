# Experiment 3: Text Processing and Pattern Matching Using Grep, Awk, and Sed

> **Author:** Yug Shah (TYCSE)  
> **Repository:** Os from scratch  
> **Course:** Operating Systems Lab  

## 1. Aim
To develop and execute shell scripts using `grep`, `awk`, and `sed` commands for efficient text processing and pattern matching in a Unix/Linux environment.

## 2. Course Outcome & Learning Objectives
- **Course Outcome:** Understand advanced text-processing tools in Unix/Linux. Apply `grep`, `awk`, and `sed` in shell scripts for data manipulation.
- **Learning Objectives:**
  - Master pattern matching and regular expression search using `grep`.
  - Perform columnar data extraction, arithmetic evaluation, and tabular reporting using `awk`.
  - Automate non-interactive stream editing, text substitution, and line deletion using `sed`.
  - Integrate these tools into composite pipeline scripts for system monitoring and log processing.

---

## 3. Related Theory

Unix offers a famous trio of filter tools designed under the Unix philosophy: *write programs that do one thing well and work together via streams*.

```mermaid
flowchart LR
    In[Input File / Stream] --> Grep[grep: Filter Lines by Pattern]
    Grep --> Sed[sed: Transform / Substitute Stream]
    Sed --> Awk[awk: Extract Fields / Summarize Data]
    Awk --> Out[Structured Report]
```

### 3.1 `grep` (Global Regular Expression Print)
`grep` searches input files or streams line-by-line for matches against a pattern or regular expression and outputs matching lines.

**Syntax:**
```bash
grep [options] "pattern" filename
```

**Common Options:**
- `-i` : Ignore case distinctions.
- `-n` : Prefix each line of output with its 1-based line number.
- `-c` : Suppress normal output; print a count of matching lines only.
- `-v` : Invert the sense of matching (select non-matching lines).
- `-r` / `-R` : Recursively read all files under each directory.
- `-E` : Interpret pattern as an Extended Regular Expression (ERE).

---

### 3.2 `awk` (Aho, Weinberger, and Kernighan)
`awk` is a complete pattern-scanning and text-processing programming language. It processes input line by line, automatically dividing each record (line) into fields (columns) delimited by whitespace or a designated field separator (`-F`).

**Special Built-in Variables:**
- `$0` : The entire current input line.
- `$1, $2, ... $NF` : First field, second field, ... and last field.
- `NF` : Number of fields in the current record.
- `NR` : Number of the current input record (line number).
- `FS` : Input field separator (default: space/tab).

**Syntax:**
```bash
awk 'pattern { action }' filename
```

**Special Action Blocks:**
- `BEGIN { ... }` : Executed once before any input files are read (great for table headers).
- `END { ... }` : Executed once after all input files have been processed (great for totals, averages).

---

### 3.3 `sed` (Stream Editor)
`sed` is a stream editor used to perform basic text transformations on an input stream. Unlike visual editors (such as `vim` or `nano`), `sed` is non-interactive and scriptable.

**Syntax:**
```bash
sed [options] 'command' filename
```

**Common Operations:**
- **Substitution / Replacement:**
  - `sed 's/old/new/' file` : Replaces the *first* occurrence of `old` with `new` on each line.
  - `sed 's/old/new/g' file` : Replaces *all* (global) occurrences of `old` with `new` on each line.
  - `sed -i 's/old/new/g' file` : Performs in-place file replacement.
- **Line Deletion:**
  - `sed '3d' file` : Deletes the 3rd line.
  - `sed '1,5d' file` : Deletes lines 1 through 5.
  - `sed '/pattern/d' file` : Deletes lines matching the regular expression.

---

## 4. Scripts & Data Files in this Experiment

### Data Files (`data/`)
- `students.txt`: Student records with Name, ID, Department, GPA.
- `marks.txt`: Student names, course names, and numerical scores.
- `employees.txt`: Employee ID, name, designation, and salary.
- `animals.txt`: Repeated words for substitution and line deletion testing.
- `log.txt`: System log file containing timestamps, `[INFO]`, `[WARNING]`, and `[ERROR]` levels.

### Demonstration Scripts
- `01_grep_demo.sh` – Demonstrates pattern matching, case insensitivity, line numbering, and counting.
- `02_awk_demo.sh` – Demonstrates field extraction (`$1`, `$2`), conditional filtering (`$3 > 50`), and `BEGIN`/`END` reporting.
- `03_sed_demo.sh` – Demonstrates single/global substitutions and line deletions.
- `04_combined_demo.sh` – Integrates `grep`, `awk`, and `sed` in a single master pipeline as shown in the OS manual.

---

## 5. How to Run

```bash
# Make scripts executable
chmod +x *.sh

# Run Grep Demonstration
./01_grep_demo.sh

# Run Awk Demonstration
./02_awk_demo.sh

# Run Sed Demonstration
./03_sed_demo.sh

# Run the Combined Script from the Lab Manual
./04_combined_demo.sh
```

---

## 6. Sample Output (from `04_combined_demo.sh`)

```text
========================================================
          COMBINED TEXT PROCESSING DEMONSTRATION        
========================================================
Lines containing 'error':
[ERROR] 2026-11-01 10:15:30 Database query timeout: error code 504.

First column of file:
Swapna
Rahul
Ananya
Swapna
Amit
Pooja

Replacing word 'cat' with 'dog':
dog and dog played in the park.
The black dog chased the small dog.
A dog sat on a mat.
dog barked at the dog.
Birds were flying over the dog and dog.
========================================================
```

---

## 7. Viva Voce & Interview Questions with Answers

### Q1: What is the main difference between `grep`, `awk`, and `sed`?
**Answer:**
- `grep` is a **search and filter** tool: it finds lines matching a pattern.
- `sed` is a **stream editor**: it parses text line-by-line and performs automated string replacements, insertions, and deletions.
- `awk` is a **full scripting language for column/field processing**: it breaks lines into variables (`$1`, `$2`), supports mathematical operations, loops, conditional branches, and generates formatted reports.

### Q2: What does the `g` flag at the end of `s/old/new/g` do in `sed`?
**Answer:**
The `g` flag stands for **global**. Without `g`, `sed` only replaces the *first* occurrence of `old` on each line. With `g`, *all* occurrences of `old` on that line are replaced.

### Q3: What is the difference between `$0` and `$1` in `awk`?
**Answer:**
- `$0` refers to the entire un-split line.
- `$1` refers to the first field (column) of the current line (default delimiter is whitespace).

### Q4: How can you specify a custom field delimiter in `awk` (e.g., colon `:` in `/etc/passwd`)?
**Answer:**
Use the `-F` flag:
```bash
awk -F':' '{print $1, $6}' /etc/passwd
```
Or set `FS=":"` in a `BEGIN` block.

### Q5: What does the command `grep -v "DEBUG"` do?
**Answer:**
The `-v` flag inverts match criteria. It prints every line that **does NOT** contain the string `"DEBUG"`.

---

## 8. Conclusion
The experiment provided thorough understanding and practical application of `grep`, `awk`, and `sed`. These utilities form the backbone of text and log stream processing in Unix/Linux environments.

