#!/bin/bash
# Program 7: Program to Display File Content Line by Line
# Uses a while-read loop redirected from the target file.

echo "Enter file name:"
read fname

if [ -f "$fname" ]
then
    while IFS= read -r line
    do
        echo "$line"
    done < "$fname"
else
    echo "File not found."
fi

