#!/bin/bash
# ==============================================================================
# Experiment 03 - Part 1: GREP (Global Regular Expression Print) Demonstration
# ==============================================================================

DATA_DIR="./data"

echo "========================================================"
echo "               GREP COMMAND DEMONSTRATION               "
echo "========================================================"

echo "1. Basic pattern match (searching for 'Swapna' in students.txt):"
grep "Swapna" "$DATA_DIR/students.txt"

echo -e "\n2. Case-insensitive search using -i (searching for 'error' in log.txt):"
grep -i "error" "$DATA_DIR/log.txt"

echo -e "\n3. Displaying matching line numbers using -n:"
grep -n "ERROR" "$DATA_DIR/log.txt"

echo -e "\n4. Counting number of matching occurrences using -c:"
grep -c "ERROR" "$DATA_DIR/log.txt"

echo -e "\n5. Inverting match using -v (lines NOT containing 'INFO'):"
grep -v "INFO" "$DATA_DIR/log.txt"

echo "========================================================"

