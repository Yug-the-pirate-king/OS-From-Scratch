#!/bin/bash
# ==============================================================================
# Experiment 03 - Part 3: SED (Stream Editor) Command Demonstration
# ==============================================================================

DATA_DIR="./data"

echo "========================================================"
echo "                SED COMMAND DEMONSTRATION               "
echo "========================================================"

echo "Original animals.txt:"
cat "$DATA_DIR/animals.txt"

echo -e "\n1. Replace first occurrence of 'cat' with 'dog' per line (sed 's/cat/dog/'):"
sed 's/cat/dog/' "$DATA_DIR/animals.txt"

echo -e "\n2. Replace ALL occurrences of 'cat' with 'dog' globally (sed 's/cat/dog/g'):"
sed 's/cat/dog/g' "$DATA_DIR/animals.txt"

echo -e "\n3. Delete the 3rd line of the file (sed '3d'):"
sed '3d' "$DATA_DIR/animals.txt"

echo -e "\n4. Delete lines matching a pattern (delete lines containing 'dog'):"
sed '/dog/d' "$DATA_DIR/animals.txt"

echo "========================================================"

