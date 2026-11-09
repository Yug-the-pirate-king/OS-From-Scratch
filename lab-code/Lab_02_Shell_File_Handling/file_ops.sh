#!/bin/bash
# Lab 2: File handling operations (menu)
while true; do
    echo "1.Exists 2.Create 3.Read 4.Count 5.Append 6.Lines 7.Copy 8.Search 9.Delete 0.Exit"
    read -p "Choice: " ch || exit
    case $ch in
        0) exit ;;
        1) read -p "File: " f; [ -f "$f" ] && echo "Exists" || echo "Not found" ;;
        2) read -p "File: " f; read -p "Text: " t; echo "$t" > "$f" ;;
        3) read -p "File: " f; cat "$f" ;;
        4) read -p "File: " f; wc -l -w -c "$f" ;;
        5) read -p "File: " f; read -p "Text: " t; echo "$t" >> "$f" ;;
        6) read -p "File: " f; while IFS= read -r line; do echo "$line"; done < "$f" ;;
        7) read -p "Source: " s; read -p "Dest: " d; cp "$s" "$d" ;;
        8) read -p "File: " f; read -p "Word: " w; grep "$w" "$f" ;;
        9) read -p "File: " f; rm "$f" ;;
        *) echo "Invalid" ;;
    esac
done
