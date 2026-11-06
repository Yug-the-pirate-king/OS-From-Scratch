#!/bin/bash
# Program 3: Program to Check Whether a File Exists
# Uses test condition [ -f "$fname" ] to verify regular file existence.

echo "Enter file name:"
read fname

if [ -f "$fname" ]
then
    echo "File exists."
else
    echo "File does not exist."
fi

