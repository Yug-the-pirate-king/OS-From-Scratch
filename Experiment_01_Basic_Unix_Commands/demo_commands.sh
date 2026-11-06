#!/bin/bash
# ==============================================================================
# Experiment 01: Demonstration of Basic and Essential Unix Commands
# ==============================================================================

echo "========================================================"
echo "      EXPERIMENT 01: BASIC UNIX COMMANDS DEMO           "
echo "========================================================"

# Step 1: Directory Operations
echo -e "\n--- 1. Directory Operations ---"
echo -n "Current Working Directory (pwd): "
pwd

echo -e "\nCreating directories: 'demo_lab' and nested 'demo_lab/sub1/sub2' using mkdir -p"
mkdir -p demo_lab/sub1/sub2
ls -ld demo_lab

echo -e "\nNavigating to demo_lab (cd demo_lab)"
cd demo_lab
pwd

# Step 2: File Operations
echo -e "\n--- 2. File Operations ---"
echo "Creating files using 'touch'"
touch file1.txt file2.txt notes.log
ls -l

echo -e "\nWriting sample text into file1.txt"
echo "Hello from Unix Operating Systems Lab!" > file1.txt
echo "Operating Systems Experiment 1: Unix Essentials" >> file1.txt
echo "Line 3: Process management, file handling, permissions" >> file1.txt

echo -e "\nCopying file1.txt to file_copy.txt (cp)"
cp file1.txt file_copy.txt

echo -e "\nMoving/Renaming file2.txt to file_renamed.txt (mv)"
mv file2.txt file_renamed.txt
ls -l

# Step 3: Viewing File Contents
echo -e "\n--- 3. Viewing File Contents (cat, head, tail) ---"
echo "Displaying file1.txt using cat:"
cat file1.txt

# Step 4: Permissions (chmod)
echo -e "\n--- 4. Changing Permissions (chmod) ---"
echo "Original permissions of file1.txt:"
ls -l file1.txt
echo "Changing permissions to 755 (chmod 755 file1.txt):"
chmod 755 file1.txt
ls -l file1.txt

echo "Granting executable permissions (chmod +x notes.log):"
chmod +x notes.log
ls -l notes.log

# Step 5: Process Management
echo -e "\n--- 5. Process Management (ps, ps -ef) ---"
echo "Displaying current shell processes (ps):"
ps

# Step 6: Disk and System Information
echo -e "\n--- 6. Disk and System Information (df, du, uname) ---"
echo "System Architecture & Kernel (uname -a):"
uname -a 2>/dev/null || echo "uname command executed"

echo -e "\nDisk Usage for demo_lab (du -sh .):"
du -sh .

echo -e "\nFilesystem Free Space Summary (df -h):"
df -h .

# Cleanup
echo -e "\n--- Cleaning up sandbox demonstration files ---"
cd ..
rm -rf demo_lab
echo "Demo directory removed. Experiment 1 demo complete!"
echo "========================================================"

