#!/bin/bash
# ==============================================================================
# Experiment 03 - Part 4: Combined Example in a Shell Script
# Directly from the Operating Systems Lab Manual
# ==============================================================================

DATA_DIR="./data"

echo "========================================================"
echo "          COMBINED TEXT PROCESSING DEMONSTRATION        "
echo "========================================================"

echo "Lines containing 'error':"
grep "error" "$DATA_DIR/log.txt"

echo -e "\nFirst column of file:"
awk '{print $1}' "$DATA_DIR/students.txt"

echo -e "\nReplacing word 'cat' with 'dog':"
sed 's/cat/dog/g' "$DATA_DIR/animals.txt"

echo "========================================================"

