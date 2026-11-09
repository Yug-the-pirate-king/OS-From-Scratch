#!/bin/bash
# Lab 3: grep, awk, sed
cd "$(dirname "$0")/data" || exit

echo "--- grep ---"
grep "Swapna" students.txt
grep -in "error" log.txt
grep -c "ERROR" log.txt
grep -v "INFO" log.txt

echo "--- awk ---"
awk '{print $1}' students.txt
awk '$3 > 50 {print $1, $3}' marks.txt
awk 'BEGIN {print "Name Dept"} {print $1, $3} END {print NR " records"}' students.txt

echo "--- sed ---"
sed 's/cat/dog/' animals.txt
sed 's/cat/dog/g' animals.txt
sed '3d' animals.txt
sed '/dog/d' animals.txt
