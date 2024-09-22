#!/bin/bash

valg="valgrind --tool=memcheck --leak-check=yes"
for opt in -nf -cf -lf -if -f -hf -of; do
    echo "TestSingleFile $opt result:"
    $valg ./s21_grep $opt temps.txt tests/1.txt
    echo "TestMultiFile $opt result:"
    $valg ./s21_grep $opt temps.txt tests/1.txt tests/2.txt
done
echo "TestNoFlags result:"
$valg ./s21_grep ^Well tests/1.txt
$valg ./s21_grep ^Well tests/1.txt tests/2.txt tests/3.txt 
for opt in -n -c -l -i -h -ci -o -vn -vo -nc -vi; do
    echo "TestSeveral $opt result:"
    $valg ./s21_grep $opt tests/1.txt tests/2.txt
done
echo "Test -s result:"
$valg ./s21_grep -sf temps.txt tests/NONE.txt tests/NONE2.txt 
echo "Test ASCI result:"
$valg ./s21_grep -vf temps.txt tests/10.txt
echo "Test ASCI result:"
$valg ./s21_grep -vf temps.txt tests/11.txt tests/11.txt