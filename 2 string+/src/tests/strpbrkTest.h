#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *strpbrkSuite();

START_TEST(strpbrkTest1) {
  const char *str1 = "Hello world!\0";
  const char *str2 = "Hello world!\0";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_ptr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST

START_TEST(strpbrkTest2) {
  const char *str1 = "Hello world\n\0";
  const char *str2 = "world\n\0";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_ptr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST

START_TEST(strpbrkTest3) {
  const char *str1 = "a\n\0";
  const char *str2 = "\n";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_ptr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST

START_TEST(strpbrkTest4) {
  const char *str1 = " \n\0";
  const char *str2 = " \0";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_ptr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST

START_TEST(strpbrkTest5) {
  const char *str1 = " \0";
  const char *str2 = " \0";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_ptr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST

START_TEST(strpbrkTest6) {
  const char *str1 = "\n\0";
  const char *str2 = "\n\0";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_ptr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST

START_TEST(strpbrkTest7) {
  const char *str1 = "\0";
  const char *str2 = "\0";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_ptr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST

START_TEST(strpbrkTest8) {
  const char *str1 = "";
  const char *str2 = "";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_ptr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST

START_TEST(strpbrkTest9) {
  const char *str1 = "Hello world\n\0";
  const char *str2 = "";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_ptr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST

START_TEST(strpbrkTest10) {
  const char *str1 = "Hello world\n\0";
  const char *str2 = "7777\0";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_ptr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST

START_TEST(strpbrkTest11) {
  const char *str1 = "Hello\0 world\n\0";
  const char *str2 = "Hello world\n\0";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_ptr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST

START_TEST(strpbrkTest12) {
  const char *str1 = "\0";
  const char *str2 = "2";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_ptr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST

START_TEST(strpbrkTest13) {
  const char *str1 = "123123\0";
  const char *str2 = "2";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_ptr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST

START_TEST(strpbrkTest14) {
  const char *str1 = "HELLO hello\0";
  const char *str2 = "E\ne\0";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_ptr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST

START_TEST(strpbrkTest15) {
  const char str1[1] = {5};
  const char str2[1] = {5};
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_ptr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST

START_TEST(strpbrkTest16) {
  const char str1[1] = {5};
  const char str2[1] = {2};
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_ptr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
}
END_TEST