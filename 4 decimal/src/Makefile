cc = gcc
cFlags = -Wall -Wextra -std=c11
#tFlags = -lcheck
tFlags = -lcheck -lsubunit -pthread
valg = valgrind --leak-check=full --track-origins=yes --log-file=valgrind.txt

all: s21_decimal.a

s21_decimal.a: s21_functions.o s21_compare.o s21_arithm.o s21_subfunc.o s21_convert.o
	ar rc s21_decimal.a s21_functions.o s21_compare.o s21_arithm.o s21_subfunc.o s21_convert.o
	ranlib s21_decimal.a

s21_functions.o: s21_functions.c
	$(cc) $(cFlags) -c s21_functions.c

s21_compare.o: s21_compare.c
	$(cc) $(cFlags) -c s21_compare.c

s21_arithm.o: s21_arithm.c
	$(cc) $(cFlags) -c s21_arithm.c

s21_convert.o: s21_convert.c
	$(cc) $(cFlags) -c s21_convert.c

s21_subfunc.o: s21_subfunc.c
	$(cc) $(cFlags) -c s21_subfunc.c

clean:
	rm -rf *.o *.a gcovReport/* *.gcda *.gcno *.gcov *.info tests/test tests/*.gcda tests/*.gcno tests/*.gcov tests/gcov_test

rebuild: clean all

test: all tests/test.c
	$(cc) $(cFlags) -o tests/test tests/test.c $(tFlags) s21_decimal.a print_s21_decimal.o -lm 
	./tests/test

test_valg: all tests/test.c
	$(cc) $(cFlags) -o tests/test tests/test.c $(tFlags) s21_decimal.a print_s21_decimal.o -lm 
	$(valg) ./tests/test
	grep -f tests/reg_valg.txt -i valgrind.txt

gcov_report: s21_functions.c s21_compare.c s21_subfunc.c s21_convert.c s21_arithm.c
	$(cc) $(cFlags) --coverage s21_functions.c s21_compare.c s21_subfunc.c s21_convert.c s21_arithm.c tests/test.c -o tests/gcov_test $(tFlags) print_s21_decimal.o -lm 
	./tests/gcov_test
	lcov -t tests/gcov_test -o gcov_test.info -c -d .
	genhtml -o gcovReport gcov_test.info

cformat:
	clang-format -i *.c tests/*.c
	clang-format -n *.c tests/*.c
	clang-format -i *.h tests/*.h
	clang-format -n *.h tests/*.h
