#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *strncmpSuite();

START_TEST(strncmpTest1) {
  const char *str1 = "Hello world!\0";
  const char *str2 = "Hello world!\0";
  ck_assert_int_eq(s21_strncmp(str1, str2, 2), strncmp(str1, str2, 2));
  ck_assert_int_eq(s21_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
  ck_assert_int_eq(s21_strncmp(str1, str2, 100), strncmp(str1, str2, 100));
  ck_assert_int_eq(s21_strncmp(str1, str2, 12), strncmp(str1, str2, 12));
  ck_assert_int_eq(s21_strncmp(str1, str2, 11), strncmp(str1, str2, 11));
}
END_TEST

START_TEST(strncmpTest2) {
  const char *str1 = "Hello world\n\0";
  const char *str2 = "Hello world\n\0";
  ck_assert_int_eq(s21_strncmp(str1, str2, 2), strncmp(str1, str2, 2));
  ck_assert_int_eq(s21_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
  ck_assert_int_eq(s21_strncmp(str1, str2, 100), strncmp(str1, str2, 100));
  ck_assert_int_eq(s21_strncmp(str1, str2, 13), strncmp(str1, str2, 13));
  ck_assert_int_eq(s21_strncmp(str1, str2, 12), strncmp(str1, str2, 12));
}
END_TEST

START_TEST(strncmpTest3) {
  const char *str1 = "a\n\0";
  const char *str2 = "a\n\0";
  ck_assert_int_eq(s21_strncmp(str1, str2, 2), strncmp(str1, str2, 2));
  ck_assert_int_eq(s21_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
  ck_assert_int_eq(s21_strncmp(str1, str2, 100), strncmp(str1, str2, 100));
  ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
  ck_assert_int_eq(s21_strncmp(str1, str2, 1), strncmp(str1, str2, 1));
}
END_TEST

START_TEST(strncmpTest4) {
  const char *str1 = " \n\0";
  const char *str2 = " \n\0";
  ck_assert_int_eq(s21_strncmp(str1, str2, 2), strncmp(str1, str2, 2));
  ck_assert_int_eq(s21_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
  ck_assert_int_eq(s21_strncmp(str1, str2, 100), strncmp(str1, str2, 100));
  ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
  ck_assert_int_eq(s21_strncmp(str1, str2, 1), strncmp(str1, str2, 1));
}
END_TEST

START_TEST(strncmpTest5) {
  const char *str1 = " \0";
  const char *str2 = " \0";
  ck_assert_int_eq(s21_strncmp(str1, str2, 1), strncmp(str1, str2, 1));
  ck_assert_int_eq(s21_strncmp(str1, str2, 2), strncmp(str1, str2, 2));
  ck_assert_int_eq(s21_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
  ck_assert_int_eq(s21_strncmp(str1, str2, 100), strncmp(str1, str2, 100));
}
END_TEST

START_TEST(strncmpTest6) {
  const char *str1 = "\n\0";
  const char *str2 = "\n\0";
  ck_assert_int_eq(s21_strncmp(str1, str2, 1), strncmp(str1, str2, 1));
  ck_assert_int_eq(s21_strncmp(str1, str2, 2), strncmp(str1, str2, 2));
  ck_assert_int_eq(s21_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
  ck_assert_int_eq(s21_strncmp(str1, str2, 100), strncmp(str1, str2, 100));
}
END_TEST

START_TEST(strncmpTest7) {
  const char *str1 = "\0";
  const char *str2 = "\0";
  ck_assert_int_eq(s21_strncmp(str1, str2, 1), strncmp(str1, str2, 1));
  ck_assert_int_eq(s21_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
  ck_assert_int_eq(s21_strncmp(str1, str2, 100), strncmp(str1, str2, 100));
}
END_TEST

START_TEST(strncmpTest8) {
  const char *str1 = "\0";
  const char *str2 = "Hello world!\0";
  ck_assert_int_le(s21_strncmp(str1, str2, 2), 0);
  ck_assert_int_le(s21_strncmp(str1, str2, 0), 0);
  ck_assert_int_le(s21_strncmp(str1, str2, 12), 0);
  ck_assert_int_le(s21_strncmp(str1, str2, 11), 0);
}
END_TEST

START_TEST(strncmpTest9) {
  const char *str1 = "Hello world!\0";
  const char *str2 = "\0";
  ck_assert_int_ge(s21_strncmp(str1, str2, 2), 0);
  ck_assert_int_ge(s21_strncmp(str1, str2, 0), 0);
  ck_assert_int_ge(s21_strncmp(str1, str2, 12), 0);
  ck_assert_int_ge(s21_strncmp(str1, str2, 11), 0);
}
END_TEST

START_TEST(strncmpTest10) {
  const char *str1 = "Hello world!\0";
  const char *str2 = "Hello world\n\0";
  ck_assert_int_ge(s21_strncmp(str1, str2, 2), 0);
  ck_assert_int_ge(s21_strncmp(str1, str2, 0), 0);
  ck_assert_int_ge(s21_strncmp(str1, str2, 12), 0);
  ck_assert_int_ge(s21_strncmp(str1, str2, 11), 0);
}
END_TEST

START_TEST(strncmpTest11) {
  const char *str1 = "Hello world\n\0";
  const char *str2 = "Hello world\0";
  ck_assert_int_ge(s21_strncmp(str1, str2, 2), 0);
  ck_assert_int_ge(s21_strncmp(str1, str2, 0), 0);
  ck_assert_int_ge(s21_strncmp(str1, str2, 12), 0);
  ck_assert_int_ge(s21_strncmp(str1, str2, 11), 0);
  ck_assert_int_ge(s21_strncmp(str1, str2, 13), 0);
  ck_assert_int_ge(s21_strncmp(str1, str2, 14), 0);
  ck_assert_int_ge(s21_strncmp(str1, str2, 15), 0);
}
END_TEST

START_TEST(strncmpTest12) {
  const char *str1 = "Hello world!\0";
  const char *str2 = "HellO world!\0";
  ck_assert_int_ge(s21_strncmp(str1, str2, 2), 0);
  ck_assert_int_ge(s21_strncmp(str1, str2, 0), 0);
  ck_assert_int_ge(s21_strncmp(str1, str2, 12), 0);
  ck_assert_int_ge(s21_strncmp(str1, str2, 11), 0);
}
END_TEST

START_TEST(strncmpTest13) {
  const char *str1 = "HellO World!\0";
  const char *str2 = "Hello world!\0";
  ck_assert_int_le(s21_strncmp(str1, str2, 2), 0);
  ck_assert_int_le(s21_strncmp(str1, str2, 0), 0);
  ck_assert_int_le(s21_strncmp(str1, str2, 12), 0);
  ck_assert_int_le(s21_strncmp(str1, str2, 11), 0);
}
END_TEST

START_TEST(strncmpTest14) {
  const char *str1 = " \n\0";
  const char *str2 = "\n\0";
  ck_assert_int_ge(s21_strncmp(str1, str2, 2), 0);
  ck_assert_int_ge(s21_strncmp(str1, str2, 0), 0);
  ck_assert_int_ge(s21_strncmp(str1, str2, 12), 0);
  ck_assert_int_ge(s21_strncmp(str1, str2, 11), 0);
}
END_TEST

START_TEST(strncmpTest15) {
  const char str1[1] = {5};
  const char str2[1] = {5};
  ck_assert_int_eq(s21_strncmp(str1, str2, 1), strncmp(str1, str2, 1));
  ck_assert_int_eq(s21_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
}
END_TEST
