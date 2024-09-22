#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *strchrSuite();

START_TEST(strchrTest1) {
  const char *str1 = "Hello world!\0";
  int c1 = 'o';
  ck_assert_ptr_eq(s21_strchr(str1, c1), strchr(str1, c1));
  int c2 = '1';
  ck_assert_ptr_eq(s21_strchr(str1, c2), strchr(str1, c2));
  int c3 = '\0';
  ck_assert_ptr_eq(s21_strchr(str1, c3), strchr(str1, c3));
  int c4 = 'l';
  ck_assert_ptr_eq(s21_strchr(str1, c4), strchr(str1, c4));
  int c5 = 'H';
  ck_assert_ptr_eq(s21_strchr(str1, c5), strchr(str1, c5));
}
END_TEST

START_TEST(strchrTest2) {
  const char *str1 = "Hello world\n\0";
  int c1 = 'o';
  ck_assert_ptr_eq(s21_strchr(str1, c1), strchr(str1, c1));
  int c2 = '1';
  ck_assert_ptr_eq(s21_strchr(str1, c2), strchr(str1, c2));
  int c3 = '\0';
  ck_assert_ptr_eq(s21_strchr(str1, c3), strchr(str1, c3));
  int c4 = '\n';
  ck_assert_ptr_eq(s21_strchr(str1, c4), strchr(str1, c4));
  int c5 = 'H';
  ck_assert_ptr_eq(s21_strchr(str1, c5), strchr(str1, c5));
}
END_TEST

START_TEST(strchrTest3) {
  const char *str1 = "a\n\0";
  int c1 = 'a';
  ck_assert_ptr_eq(s21_strchr(str1, c1), strchr(str1, c1));
  int c2 = '1';
  ck_assert_ptr_eq(s21_strchr(str1, c2), strchr(str1, c2));
  int c3 = '\0';
  ck_assert_ptr_eq(s21_strchr(str1, c3), strchr(str1, c3));
  int c4 = '\n';
  ck_assert_ptr_eq(s21_strchr(str1, c4), strchr(str1, c4));
  int c5 = 'H';
  ck_assert_ptr_eq(s21_strchr(str1, c5), strchr(str1, c5));
}
END_TEST

START_TEST(strchrTest4) {
  const char *str1 = " \n\0";
  int c1 = ' ';
  ck_assert_ptr_eq(s21_strchr(str1, c1), strchr(str1, c1));
  int c2 = '1';
  ck_assert_ptr_eq(s21_strchr(str1, c2), strchr(str1, c2));
  int c3 = '\0';
  ck_assert_ptr_eq(s21_strchr(str1, c3), strchr(str1, c3));
  int c4 = '\n';
  ck_assert_ptr_eq(s21_strchr(str1, c4), strchr(str1, c4));
  int c5 = 'H';
  ck_assert_ptr_eq(s21_strchr(str1, c5), strchr(str1, c5));
}
END_TEST

START_TEST(strchrTest5) {
  const char *str1 = " \0";
  int c1 = ' ';
  ck_assert_ptr_eq(s21_strchr(str1, c1), strchr(str1, c1));
  int c2 = '1';
  ck_assert_ptr_eq(s21_strchr(str1, c2), strchr(str1, c2));
  int c3 = '\0';
  ck_assert_ptr_eq(s21_strchr(str1, c3), strchr(str1, c3));
  int c4 = '\n';
  ck_assert_ptr_eq(s21_strchr(str1, c4), strchr(str1, c4));
  int c5 = 'H';
  ck_assert_ptr_eq(s21_strchr(str1, c5), strchr(str1, c5));
}
END_TEST

START_TEST(strchrTest6) {
  const char *str1 = "\n\0";
  int c1 = ' ';
  ck_assert_ptr_eq(s21_strchr(str1, c1), strchr(str1, c1));
  int c2 = '>';
  ck_assert_ptr_eq(s21_strchr(str1, c2), strchr(str1, c2));
  int c3 = '\0';
  ck_assert_ptr_eq(s21_strchr(str1, c3), strchr(str1, c3));
  int c4 = '\n';
  ck_assert_ptr_eq(s21_strchr(str1, c4), strchr(str1, c4));
  int c5 = '@';
  ck_assert_ptr_eq(s21_strchr(str1, c5), strchr(str1, c5));
}
END_TEST

START_TEST(strchrTest7) {
  const char *str1 = "\0";
  int c1 = ' ';
  ck_assert_ptr_eq(s21_strchr(str1, c1), strchr(str1, c1));
  int c2 = '`';
  ck_assert_ptr_eq(s21_strchr(str1, c2), strchr(str1, c2));
  int c3 = '\0';
  ck_assert_ptr_eq(s21_strchr(str1, c3), strchr(str1, c3));
  int c4 = '\n';
  ck_assert_ptr_eq(s21_strchr(str1, c4), strchr(str1, c4));
  int c5 = 'H';
  ck_assert_ptr_eq(s21_strchr(str1, c5), strchr(str1, c5));
}
END_TEST

START_TEST(strchrTest8) {
  const char str1[1] = {5};
  int c1 = ' ';
  ck_assert_ptr_eq(s21_strchr(str1, c1), strchr(str1, c1));
  int c2 = '`';
  ck_assert_ptr_eq(s21_strchr(str1, c2), strchr(str1, c2));
  int c3 = '\0';
  ck_assert_ptr_eq(s21_strchr(str1, c3), strchr(str1, c3));
  int c4 = 5;
  ck_assert_ptr_eq(s21_strchr(str1, c4), strchr(str1, c4));
  int c5 = 2;
  ck_assert_ptr_eq(s21_strchr(str1, c5), strchr(str1, c5));
}
END_TEST