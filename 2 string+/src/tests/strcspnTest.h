#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *strcspnSuite();

START_TEST(strcspnTest1) {
  const char *str1 = "Hello world!\0";
  const char *str2 = "Hello world!\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_int_eq(s21_strcspn(str2, str1), strcspn(str2, str1));
}
END_TEST

START_TEST(strcspnTest2) {
  const char *str1 = "Hello world\n\0";
  const char *str2 = "Hello world\n\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_int_eq(s21_strcspn(str2, str1), strcspn(str2, str1));
}
END_TEST

START_TEST(strcspnTest3) {
  const char *str1 = "a\n\0";
  const char *str2 = "a\n\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_int_eq(s21_strcspn(str2, str1), strcspn(str2, str1));
}
END_TEST

START_TEST(strcspnTest4) {
  const char *str1 = " \n\0";
  const char *str2 = " \n\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_int_eq(s21_strcspn(str2, str1), strcspn(str2, str1));
}
END_TEST

START_TEST(strcspnTest5) {
  const char *str1 = " \0";
  const char *str2 = " \0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_int_eq(s21_strcspn(str2, str1), strcspn(str2, str1));
}
END_TEST

START_TEST(strcspnTest6) {
  const char *str1 = "\n\0";
  const char *str2 = "\n\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_int_eq(s21_strcspn(str2, str1), strcspn(str2, str1));
}
END_TEST

START_TEST(strcspnTest7) {
  const char *str1 = "\0";
  const char *str2 = "\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_int_eq(s21_strcspn(str2, str1), strcspn(str2, str1));
}
END_TEST

START_TEST(strcspnTest8) {
  const char *str1 = "Hello world!\0";
  const char *str2 = "____Hello world!\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_int_eq(s21_strcspn(str2, str1), strcspn(str2, str1));
}
END_TEST

START_TEST(strcspnTest9) {
  const char *str1 = "Hello world\n\0";
  const char *str2 = "____________Hello world\n\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_int_eq(s21_strcspn(str2, str1), strcspn(str2, str1));
}
END_TEST

START_TEST(strcspnTest10) {
  const char *str1 = "a\n\0";
  const char *str2 = "__a\n\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_int_eq(s21_strcspn(str2, str1), strcspn(str2, str1));
}
END_TEST

START_TEST(strcspnTest11) {
  const char *str1 = " \n\0";
  const char *str2 = "_ \n\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_int_eq(s21_strcspn(str2, str1), strcspn(str2, str1));
}
END_TEST

START_TEST(strcspnTest12) {
  const char *str1 = " \0";
  const char *str2 = "__________ \0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_int_eq(s21_strcspn(str2, str1), strcspn(str2, str1));
}
END_TEST

START_TEST(strcspnTest13) {
  const char *str1 = "\n\0";
  const char *str2 = "________\n\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_int_eq(s21_strcspn(str2, str1), strcspn(str2, str1));
}
END_TEST

START_TEST(strcspnTest14) {
  const char *str1 = "\0";
  const char *str2 = "_______\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_int_eq(s21_strcspn(str2, str1), strcspn(str2, str1));
}
END_TEST

START_TEST(strcspnTest15) {
  const char *str1 = "Hello world!\0";
  const char *str2 = "777\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_int_eq(s21_strcspn(str2, str1), strcspn(str2, str1));
}
END_TEST

START_TEST(strcspnTest16) {
  const char *str1 = " \n\0";
  const char *str2 = "777\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_int_eq(s21_strcspn(str2, str1), strcspn(str2, str1));
}
END_TEST

START_TEST(strcspnTest17) {
  const char *str1 = "";
  const char *str2 = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_int_eq(s21_strcspn(str2, str1), strcspn(str2, str1));
}
END_TEST

START_TEST(strcspnTest18) {
  const char str1[2] = {5, '\0'};
  const char str2[2] = {5, '\0'};
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_int_eq(s21_strcspn(str2, str1), strcspn(str2, str1));
}
END_TEST

START_TEST(strcspnTest19) {
  const char str1[2] = {5, '\0'};
  const char str2[2] = {2, '\0'};
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_int_eq(s21_strcspn(str2, str1), strcspn(str2, str1));
}
END_TEST