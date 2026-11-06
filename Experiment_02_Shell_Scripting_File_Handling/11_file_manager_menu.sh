#!/bin/bash
# ==============================================================================
# Comprehensive Menu-Driven Shell Program for File Handling
# ==============================================================================

while true
do
    echo "========================================================"
    echo "         FILE HANDLING OPERATIONS MENU                  "
    echo "========================================================"
    echo "1. Check if a File Exists"
    echo "2. Create and Write into a File"
    echo "3. Read File Contents (cat)"
    echo "4. Count Lines, Words, and Characters (wc)"
    echo "5. Append Content to an Existing File"
    echo "6. Display File Content Line by Line"
    echo "7. Copy File to Another Location"
    echo "8. Search for a Word in a File (grep)"
    echo "9. Delete a File (rm)"
    echo "10. Exit"
    echo "========================================================"
    echo -n "Enter your choice [1-10]: "
    read choice

    case $choice in
        1)
            echo -n "Enter file name: "
            read fname
            if [ -f "$fname" ]; then
                echo "Result: File '$fname' exists."
            else
                echo "Result: File '$fname' does not exist."
            fi
            ;;
        2)
            echo -n "Enter file name: "
            read fname
            echo "Enter content to write:"
            read content
            echo "$content" > "$fname"
            echo "Success: Content written to '$fname'."
            ;;
        3)
            echo -n "Enter file name: "
            read fname
            if [ -f "$fname" ]; then
                echo "--- Content of $fname ---"
                cat "$fname"
                echo "-------------------------"
            else
                echo "Error: File '$fname' not found."
            fi
            ;;
        4)
            echo -n "Enter file name: "
            read fname
            if [ -f "$fname" ]; then
                echo "Lines Words Characters File:"
                wc "$fname"
            else
                echo "Error: File '$fname' not found."
            fi
            ;;
        5)
            echo -n "Enter file name: "
            read fname
            if [ -f "$fname" ]; then
                echo "Enter content to append:"
                read content
                echo "$content" >> "$fname"
                echo "Success: Content appended to '$fname'."
            else
                echo "Error: File '$fname' not found."
            fi
            ;;
        6)
            echo -n "Enter file name: "
            read fname
            if [ -f "$fname" ]; then
                line_no=1
                echo "--- Line by Line Reading ---"
                while IFS= read -r line; do
                    echo "[$line_no] $line"
                    ((line_no++))
                done < "$fname"
                echo "----------------------------"
            else
                echo "Error: File '$fname' not found."
            fi
            ;;
        7)
            echo -n "Enter source file: "
            read src
            echo -n "Enter destination file: "
            read dst
            if [ -f "$src" ]; then
                cp "$src" "$dst"
                echo "Success: Copied '$src' to '$dst'."
            else
                echo "Error: Source file '$src' does not exist."
            fi
            ;;
        8)
            echo -n "Enter file name: "
            read fname
            echo -n "Enter word to search: "
            read word
            if [ -f "$fname" ]; then
                echo "Matching occurrences:"
                grep --color=auto -n "$word" "$fname" || echo "Word '$word' not found in '$fname'."
            else
                echo "Error: File '$fname' not found."
            fi
            ;;
        9)
            echo -n "Enter file name to delete: "
            read fname
            if [ -f "$fname" ]; then
                rm "$fname"
                echo "Success: File '$fname' deleted."
            else
                echo "Error: File '$fname' does not exist."
            fi
            ;;
        10)
            echo "Exiting program. Goodbye!"
            exit 0
            ;;
        *)
            echo "Invalid option. Please choose between 1 and 10."
            ;;
    esac
    echo ""
done

