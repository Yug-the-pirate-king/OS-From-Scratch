#!/bin/bash
# Program 4: Program to Create and Write into a File
# Reads content from user input and redirects it into the specified file.

echo "Enter file name:"
read fname

echo "Enter content to write:"
read content

echo "$content" > "$fname"
echo "Content written successfully."

