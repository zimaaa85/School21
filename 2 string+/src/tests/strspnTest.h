#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *strspnSuite();

START_TEST(strspnTest1) {
  const char *str1 = "Hello world!\0";
  const char *str2 = "Hello world!\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
}
END_TEST

START_TEST(strspnTest2) {
  const char *str1 = "Hello world\n\0";
  const char *str2 = "Hello world\n\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
}
END_TEST

START_TEST(strspnTest3) {
  const char *str1 = "a\n\0";
  const char *str2 = "a\n\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
}
END_TEST

START_TEST(strspnTest4) {
  const char *str1 = " \n\0";
  const char *str2 = " \n\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
}
END_TEST

START_TEST(strspnTest5) {
  const char *str1 = " \0";
  const char *str2 = " \0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
}
END_TEST

START_TEST(strspnTest6) {
  const char *str1 = "\n\0";
  const char *str2 = "\n\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
}
END_TEST

START_TEST(strspnTest7) {
  const char *str1 = "\0";
  const char *str2 = "\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
}
END_TEST

START_TEST(strspnTest8) {
  const char *str1 = "Hello world!\0";
  const char *str2 = "____Hello world!\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
}
END_TEST

START_TEST(strspnTest9) {
  const char *str1 = "Hello world\n\0";
  const char *str2 = "____________Hello world\n\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
}
END_TEST

START_TEST(strspnTest10) {
  const char *str1 = "a\n\0";
  const char *str2 = "__a\n\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
}
END_TEST

START_TEST(strspnTest11) {
  const char *str1 = " \n\0";
  const char *str2 = "_ \n\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
}
END_TEST

START_TEST(strspnTest12) {
  const char *str1 = " \0";
  const char *str2 = "__________ \0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
}
END_TEST

START_TEST(strspnTest13) {
  const char *str1 = "\n\0";
  const char *str2 = "________\n\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
}
END_TEST

START_TEST(strspnTest14) {
  const char *str1 = "\0";
  const char *str2 = "_______\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
}
END_TEST

START_TEST(strspnTest15) {
  const char *str1 = "Hello world!\0";
  const char *str2 = "777\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
}
END_TEST

START_TEST(strspnTest16) {
  const char *str1 = " \n\0";
  const char *str2 = "777\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
}
END_TEST

START_TEST(strspnTest17) {
  const char *str1 = "";
  const char *str2 = "";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
}
END_TEST

START_TEST(strspnTest18) {
  const char str1[2] = {5, '\0'};
  const char str2[2] = {5, '\0'};
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
}
END_TEST