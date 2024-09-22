#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *memchrSuite();

START_TEST(memchrTest1) {
  const char *str1 = "Hello world!\0";
  ck_assert_ptr_eq(s21_memchr(str1, 111, 0), memchr(str1, 111, 0));
  ck_assert_ptr_eq(s21_memchr(str1, 111, 3), memchr(str1, 111, 3));
  ck_assert_ptr_eq(s21_memchr(str1, 111, 14), memchr(str1, 111, 14));
  ck_assert_ptr_eq(s21_memchr(str1, 111, 10), memchr(str1, 111, 10));
  ck_assert_ptr_eq(s21_memchr(str1, 111, 13), memchr(str1, 111, 13));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 0), memchr(str1, 2, 0));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 3), memchr(str1, 2, 3));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 14), memchr(str1, 2, 14));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 10), memchr(str1, 2, 10));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 13), memchr(str1, 2, 13));
}
END_TEST

START_TEST(memchrTest2) {
  const char *str1 = "Hello world\n\0";
  ck_assert_ptr_eq(s21_memchr(str1, 111, 0), memchr(str1, 111, 0));
  ck_assert_ptr_eq(s21_memchr(str1, 111, 3), memchr(str1, 111, 3));
  ck_assert_ptr_eq(s21_memchr(str1, 111, 13), memchr(str1, 111, 13));
  ck_assert_ptr_eq(s21_memchr(str1, 111, 10), memchr(str1, 111, 10));
  ck_assert_ptr_eq(s21_memchr(str1, 111, 14), memchr(str1, 111, 14));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 0), memchr(str1, 2, 0));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 3), memchr(str1, 2, 3));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 13), memchr(str1, 2, 13));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 10), memchr(str1, 2, 10));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 14), memchr(str1, 2, 14));
}
END_TEST

START_TEST(memchrTest3) {
  const char *str1 = "a\n\0";
  ck_assert_ptr_eq(s21_memchr(str1, 97, 0), memchr(str1, 97, 0));
  ck_assert_ptr_eq(s21_memchr(str1, 97, 3), memchr(str1, 97, 3));
  ck_assert_ptr_eq(s21_memchr(str1, 97, 1), memchr(str1, 97, 1));
  ck_assert_ptr_eq(s21_memchr(str1, 97, 2), memchr(str1, 97, 2));
  ck_assert_ptr_eq(s21_memchr(str1, 97, 4), memchr(str1, 97, 4));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 0), memchr(str1, 2, 0));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 3), memchr(str1, 2, 3));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 1), memchr(str1, 2, 1));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 2), memchr(str1, 2, 2));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 4), memchr(str1, 2, 4));
}
END_TEST

START_TEST(memchrTest4) {
  const char *str1 = " \n\0";
  ck_assert_ptr_eq(s21_memchr(str1, 10, 0), memchr(str1, 10, 0));
  ck_assert_ptr_eq(s21_memchr(str1, 10, 3), memchr(str1, 10, 3));
  ck_assert_ptr_eq(s21_memchr(str1, 10, 1), memchr(str1, 10, 1));
  ck_assert_ptr_eq(s21_memchr(str1, 10, 2), memchr(str1, 10, 2));
  ck_assert_ptr_eq(s21_memchr(str1, 10, 4), memchr(str1, 10, 4));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 0), memchr(str1, 2, 0));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 3), memchr(str1, 2, 3));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 1), memchr(str1, 2, 1));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 2), memchr(str1, 2, 2));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 4), memchr(str1, 2, 4));
}
END_TEST

START_TEST(memchrTest5) {
  const char *str1 = " \0";
  ck_assert_ptr_eq(s21_memchr(str1, 32, 0), memchr(str1, 32, 0));
  ck_assert_ptr_eq(s21_memchr(str1, 32, 3), memchr(str1, 32, 3));
  ck_assert_ptr_eq(s21_memchr(str1, 32, 1), memchr(str1, 32, 1));
  ck_assert_ptr_eq(s21_memchr(str1, 32, 2), memchr(str1, 32, 2));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 0), memchr(str1, 2, 0));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 3), memchr(str1, 2, 3));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 1), memchr(str1, 2, 1));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 2), memchr(str1, 2, 2));
}
END_TEST

START_TEST(memchrTest6) {
  const char *str1 = "\n\0";
  ck_assert_ptr_eq(s21_memchr(str1, 10, 0), memchr(str1, 10, 0));
  ck_assert_ptr_eq(s21_memchr(str1, 10, 3), memchr(str1, 10, 3));
  ck_assert_ptr_eq(s21_memchr(str1, 10, 1), memchr(str1, 10, 1));
  ck_assert_ptr_eq(s21_memchr(str1, 10, 2), memchr(str1, 10, 2));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 0), memchr(str1, 2, 0));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 3), memchr(str1, 2, 3));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 1), memchr(str1, 2, 1));
  ck_assert_ptr_eq(s21_memchr(str1, 2, 2), memchr(str1, 2, 2));
}
END_TEST

START_TEST(memchrTest7) {
  const char *str1 = "\0";
  ck_assert_ptr_eq(s21_memchr(str1, 10, 0), memchr(str1, 10, 0));
  ck_assert_ptr_eq(s21_memchr(str1, 10, 1), memchr(str1, 10, 1));
  ck_assert_ptr_eq(s21_memchr(str1, 10, 2), memchr(str1, 10, 2));
}
END_TEST

START_TEST(memchrTest8) {
  const char str1[1] = {5};
  ck_assert_ptr_eq(s21_memchr(str1, 5, 1), memchr(str1, 5, 1));
  ck_assert_ptr_eq(s21_memchr(str1, 10, 1), memchr(str1, 10, 1));
}
END_TEST