#!/bin/bash
# Program 5: Program to Count Lines, Words, and Characters
# Uses the 'wc' command to count lines (-l), words (-w), and characters (-m/-c).

echo "Enter file name:"
read fname

if [ -f "$fname" ]
then
    wc "$fname"
else
    echo "File not found."
fi

