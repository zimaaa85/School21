#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *trimSuite();

START_TEST(trimTest1) {
  const char *str = "!*Hello world*!\0";
  const char *chars = "!*\0";
  const char *result = "Hello world\0";
  char *s21_result = (char *)s21_trim(str, chars);
  ck_assert_int_eq(strcmp(result, s21_result), 0);
  free(s21_result);
}
END_TEST

START_TEST(trimTest2) {
  const char *str = "!*Hello world\0";
  const char *chars = "!*5\0";
  const char *result = "Hello world\0";
  char *s21_result = (char *)s21_trim(str, chars);
  ck_assert_int_eq(strcmp(result, s21_result), 0);
  free(s21_result);
}
END_TEST

START_TEST(trimTest3) {
  const char *str = "***!*Hello world*\n***\0";
  const char *chars = "*zasd";
  const char *result = "!*Hello world*\n\0";
  char *s21_result = (char *)s21_trim(str, chars);
  ck_assert_int_eq(strcmp(result, s21_result), 0);
  free(s21_result);
}
END_TEST

START_TEST(trimTest4) {
  const char *str = "a\n\0";
  const char *chars = "*zsd";
  const char *result = "a\n\0";
  char *s21_result = (char *)s21_trim(str, chars);
  ck_assert_int_eq(strcmp(result, s21_result), 0);
  free(s21_result);
}
END_TEST

START_TEST(trimTest5) {
  const char *str = " \n\0";
  const char *chars = "";
  char *s21_result = (char *)s21_trim(str, chars);
  ck_assert_int_eq((long int)s21_result, 0);
  free(s21_result);
}
END_TEST

START_TEST(trimTest6) {
  const char *str = " \0";
  const char *chars = " iohrerekl3234()";
  char *s21_result = (char *)s21_trim(str, chars);
  ck_assert_int_eq(strlen(s21_result), 0);
  free(s21_result);
}
END_TEST

START_TEST(trimTest7) {
  const char *str = "\n \0";
  const char *chars = " iohrerekl3234()";
  const char *result = "\n\0";
  char *s21_result = (char *)s21_trim(str, chars);
  ck_assert_int_eq(strcmp(result, s21_result), 0);
  free(s21_result);
}
END_TEST

START_TEST(trimTest8) {
  const char *str = "\0";
  const char *chars = " iohrerekl3234()";
  char *s21_result = (char *)s21_trim(str, chars);
  ck_assert_int_eq((long int)s21_result, 0);
  free(s21_result);
}
END_TEST

START_TEST(trimTest9) {
  const char *str = "Hello 123456789 world\n\0";
  const char *chars = "123456789";
  const char *result = "Hello 123456789 world\n\0";
  char *s21_result = (char *)s21_trim(str, chars);
  ck_assert_int_eq(strcmp(result, s21_result), 0);
  free(s21_result);
}
END_TEST