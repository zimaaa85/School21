cc = gcc
cFlags = -Wall -Wextra -Werror -std=c11
#tFlags = -lcheck -lm
tFlags = -pthread -lcheck -lsubunit -lrt -lm
gFlags = -fprofile-arcs -ftest-coverage
valg = valgrind --tool=memcheck --leak-check=yes --quiet

all: s21_string.a

s21_string.a: s21_string.o s21_sprintf.o s21_strerror.o s21_sscanf.o
	ar rc s21_string.a s21_string.o s21_sprintf.o s21_strerror.o s21_sscanf.o
	ranlib s21_string.a

test: rebuild testprint testscan tests/test.c 
	$(cc) -L. -I. tests/test.c s21_string.a $(tFlags) $(cFlags) $(gFlags) -o tests/test
	./tests/test

testV: rebuild tests/test.c testprint testscan
	$(cc) -L. -I. tests/test.c s21_string.a $(tFlags) $(cFlags) $(gFlags) -o tests/test
	$(valg) ./tests/test

testprint: rebuild tests/testSprintf.c
	$(cc) -L. -I. tests/testSprintf.c s21_string.a $(tFlags) $(cFlags) $(gFlags) -o tests/testSprintf
	./tests/testSprintf

testprintV: rebuild tests/testSprintf.c
	$(cc) -L. -I. tests/testSprintf.c s21_string.a $(tFlags) $(cFlags) $(gFlags) -o tests/testSprintf
	$(valg) ./tests/testSprintf

testscan: rebuild tests/testSscanf.c
	$(cc) -L. -I. tests/testSscanf.c s21_string.a $(tFlags) $(cFlags) $(gFlags) -o tests/testSscanf
	./tests/testSscanf

testscanV: rebuild tests/testSscanf.c
	$(cc) -L. -I. tests/testSscanf.c s21_string.a $(tFlags) $(cFlags) $(gFlags) -o tests/testSscanf
	$(valg) ./tests/testSscanf

gcov_report: test testscan
	lcov --directory . --capture --output-file tests/test.info
	genhtml -o gcovReport tests/test.info
	rm -rf tests/test tests/*.gcda tests/*.gcno tests/*.gcov tests/*.info *.gcda *.gcno *.gcov

clean:
	rm -rf *.o *.a gcovReport/* *.gcda *.gcno *.gcov *.info tests/test tests/testFtoa tests/testSprintf tests/testSscanf tests/*.gcda tests/*.gcno tests/*.gcov

rebuild: clean all

s21_string.o: s21_string.c
	$(cc) $(cFlags) $(gFlags) -c s21_string.c

s21_strerror.o: s21_strerror.c
	$(cc) $(cFlags) $(gFlags) -c s21_strerror.c

s21_sprintf.o: s21_sprintf.c
	$(cc) $(cFlags) $(gFlags) -c s21_sprintf.c

s21_sscanf.o: s21_sscanf.c
	$(cc) $(cFlags) $(gFlags) -c s21_sscanf.c

cformat:
	clang-format -i *.c tests/*.c
	clang-format -n *.c tests/*.c
	clang-format -i *.h tests/*.h
	clang-format -n *.h tests/*.h

	
