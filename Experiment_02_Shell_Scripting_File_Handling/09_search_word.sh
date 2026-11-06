#!/bin/bash
# Program 9: Program to Search a Word in a File
# Uses grep to find and display matching lines containing the search string.

echo "Enter file name:"
read fname
echo "Enter word to search:"
read word

if [ -f "$fname" ]
then
    echo "--- Search Results ---"
    grep "$word" "$fname"
else
    echo "File not found."
fi

