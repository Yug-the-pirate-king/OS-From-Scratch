#!/bin/bash
# Program 6: Program to Append Content to an Existing File
# Appends user input to the specified file using the >> append redirection operator.

echo "Enter file name:"
read fname

if [ -f "$fname" ]
then
    echo "Enter content to append:"
    read content
    echo "$content" >> "$fname"
    echo "Content appended successfully."
else
    echo "File not found."
fi

