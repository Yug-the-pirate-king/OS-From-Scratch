#!/bin/bash
# ==============================================================================
# Experiment 03 - Part 2: AWK Command Demonstration
# ==============================================================================

DATA_DIR="./data"

echo "========================================================"
echo "                AWK COMMAND DEMONSTRATION               "
echo "========================================================"

echo "1. Printing the first column (\$1) of students.txt:"
awk '{print $1}' "$DATA_DIR/students.txt"

echo -e "\n2. Printing employee ID (\$1) and Name (\$2) from employees.txt:"
awk '{print $1, $2}' "$DATA_DIR/employees.txt"

echo -e "\n3. Filtering records with condition (\$3 > 50 in marks.txt):"
echo "Students scoring marks > 50:"
awk '$3 > 50 {print "Student: " $1, "| Marks: " $3}' "$DATA_DIR/marks.txt"

echo -e "\n4. Formatting output with BEGIN and END blocks:"
awk 'BEGIN {print "NAME\t\tDEPARTMENT\n---------------------------------"} {print $1 "\t\t" $3} END {print "---------------------------------\nTotal Records:", NR}' "$DATA_DIR/students.txt"

echo "========================================================"

