#!/bin/bash

n=1
nFile=10
while [ $n -lt $nFile ]; do
    for opt in -n -c -l -i -h -v -ci -o -vn -nc -nl -ni -il -hv -no -co -lo -io; do
        echo "TestSingleFile $opt $n result:"
        grep $opt temps.txt tests/$n.txt > grepRes
        ./s21_grep $opt temps.txt tests/$n.txt > s21_grepRes
        diff -s grepRes s21_grepRes
    done
    n=$((n + 1))
done

n=1
while [ $n -lt $(($nFile-1)) ]; do
    for opt in -n -c -l -i -h -v -ci -o -vn -nc -nl -ni -il -hv -no -co -lo -io; do
        y=$(($n+1))
        echo "TestMultiFile $opt $n result:"
        grep $opt temps.txt tests/$n.txt tests/$y.txt > grepRes
        ./s21_grep $opt temps.txt tests/$n.txt tests/$y.txt > s21_grepRes
        diff -s grepRes s21_grepRes
    done
    n=$((n + 1))
done

n=1
while [ $n -lt $(($nFile-1)) ]; do
    y=$(($n+1))
    echo "TestNoFlags $n result:"
    grep ^Well tests/$n.txt > grepRes
    ./s21_grep ^Well tests/$n.txt > s21_grepRes
    diff -s grepRes s21_grepRes
    n=$((n + 1))
done

echo "Test -s result:"
grep -sf temps.txt tests/NONE.txt tests/NONE2.txt > grepRes
./s21_grep -sf temps.txt tests/NONE.txt tests/NONE2.txt > s21_grepRes
diff -s grepRes s21_grepRes

echo "Test ASCII result:"
grep -vf temps.txt tests/11.txt > grepRes
./s21_grep -vf temps.txt tests/11.txt > s21_grepRes
diff -s grepRes s21_grepRes

for opt in -nf -cf -lf -if -f -hf -of; do
    echo "TestSingleFile ASCII $opt result:"
    grep $opt temps.txt tests/11.txt tests/11.txt > grepRes
    ./s21_grep $opt temps.txt tests/11.txt tests/11.txt > s21_grepRes
    diff -s grepRes s21_grepRes
done

rm -rf grepRes
rm -rf s21_grepRes


