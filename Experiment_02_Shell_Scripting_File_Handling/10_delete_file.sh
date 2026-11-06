#!/bin/bash
# Program 10: Program to Delete a File
# Uses rm command to delete specified file if it exists.

echo "Enter file name to delete:"
read fname

if [ -f "$fname" ]
then
    rm "$fname"
    echo "File deleted successfully."
else
    echo "File not found."
fi

