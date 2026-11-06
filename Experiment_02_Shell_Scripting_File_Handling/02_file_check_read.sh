#!/bin/bash
# Program 2: Example Shell Script for File Handling
# Prompts for file name, checks if it exists, and displays contents.

echo "Enter file name:"
read filename

if [ -f "$filename" ]
then
    echo "File exists"
    echo "Contents of file:"
    cat "$filename"
else
    echo "File does not exist"
fi

