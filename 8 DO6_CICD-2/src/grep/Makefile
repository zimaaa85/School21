CFLAGS      = -Wall -Werror -Wextra -std=c11
clang_path = ../../materials/build/scripts/


all: s21_grep

s21_grep: s21_grep.c
	gcc $(CFLAGS) s21_grep.c -o s21_grep

rebuild: clean all

clean:
	rm -rf s21_grep

test: rebuild testScript.sh
	sh testScript.sh

testLeaks: rebuild testScriptLeaks.sh
	sh testScriptLeaks.sh
	
clang:
#	cp $(clang_path).clang-format ./
	clang-format -n *.c *.h

clang-correction:
#	cp $(clang_path).clang-format ./
	clang-format -i *.c *.h