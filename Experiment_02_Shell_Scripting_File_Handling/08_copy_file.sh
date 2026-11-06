#!/bin/bash
# Program 8: Program to Copy Content from One File to Another
# Uses cp command to duplicate source file into destination file.

echo "Enter source file:"
read source
echo "Enter destination file:"
read dest

if [ -f "$source" ]
then
    cp "$source" "$dest"
    echo "File copied successfully."
else
    echo "Source file not found."
fi

