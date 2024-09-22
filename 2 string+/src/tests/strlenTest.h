#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *strlenSuite();

START_TEST(strlenTest1) {
  const char *str1 = "Hello world!\0";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlenTest2) {
  const char *str1 = "Hello world\n\0";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlenTest3) {
  const char *str1 = "a\n\0";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlenTest4) {
  const char *str1 = " \n\0";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlenTest5) {
  const char *str1 = " \0";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlenTest6) {
  const char *str1 = "\n\0";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlenTest7) {
  const char *str1 = "\0";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlenTest8) {
  const char *str1 = "";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlenTest9) {
  const char *str1 = "asdas\0 dsfds d\0";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlenTest10) {
  const char str1[2] = {5, '\0'};
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST
