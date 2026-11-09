#!/bin/bash
# Lab 1: Basic Unix commands
cd "$(dirname "$0")" || exit

pwd
mkdir -p demo
cd demo

touch a.txt
echo "Hello OS" > a.txt
cat a.txt
cp a.txt b.txt
mv b.txt c.txt
ls -l
wc -l a.txt
head -n 1 a.txt
grep "OS" a.txt
chmod 755 a.txt
ls -l a.txt

ps
df -h .
du -sh .

# kill <PID>        terminate process
# kill -9 <PID>     force kill

cd ..
rm -rf demo
