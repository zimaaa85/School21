CFLAGS      = -Wall -Werror -Wextra -std=c11
clang_path = ../../materials/build/scripts/


all: s21_cat

s21_cat: s21_cat.c
	gcc $(CFLAGS) s21_cat.c -o s21_cat

rebuild: clean all

clean:
	rm -rf s21_cat

test: s21_cat
	mv s21_cat ./tests
	cd ./tests; chmod u=rwx test_func_cat.sh ; ./test_func_cat.sh
	rm ./tests/s21_cat

testLeaks:
	gcc $(CFLAGS) s21_cat.c -o s21_cat
	valgrind --leak-check=full ./s21_cat -n -b -s -e s21_cat.c
	
	
clang:
	cp $(clang_path).clang-format ./
	clang-format -n *.c *.h

clang-correction:
	cp $(clang_path).clang-format ./
	clang-format -i *.c *.h