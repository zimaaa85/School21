#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *to_lowerSuite();

START_TEST(to_lowerTest1) {
  const char *str1 = "Hello world!\0";
  const char *str2 = "hello world!\0";
  char *result = (char *)s21_to_lower(str1);
  ck_assert_int_eq(strcmp(str2, result), 0);
  free(result);
}
END_TEST

START_TEST(to_lowerTest2) {
  const char *str1 = "Hello world\n\0";
  const char *str2 = "hello world\n\0";
  char *result = (char *)s21_to_lower(str1);
  ck_assert_int_eq(strcmp(str2, result), 0);
  free(result);
}
END_TEST

START_TEST(to_lowerTest3) {
  const char *str1 = "A\n\0";
  const char *str2 = "a\n\0";
  char *result = (char *)s21_to_lower(str1);
  ck_assert_int_eq(strcmp(str2, result), 0);
  free(result);
}
END_TEST

START_TEST(to_lowerTest4) {
  const char *str1 = " \n\0";
  const char *str2 = " \n\0";
  char *result = (char *)s21_to_lower(str1);
  ck_assert_int_eq(strcmp(str2, result), 0);
  free(result);
}
END_TEST

START_TEST(to_lowerTest5) {
  const char *str1 = " \0";
  const char *str2 = " \0";
  char *result = (char *)s21_to_lower(str1);
  ck_assert_int_eq(strcmp(str2, result), 0);
  free(result);
}
END_TEST

START_TEST(to_lowerTest6) {
  const char *str1 = "\n\0";
  const char *str2 = "\n\0";
  char *result = (char *)s21_to_lower(str1);
  ck_assert_int_eq(strcmp(str2, result), 0);
  free(result);
}
END_TEST

START_TEST(to_lowerTest7) {
  const char *str1 = "\0";
  char *result = (char *)s21_to_lower(str1);
  ck_assert_int_eq((long int)result, 0);
  free(result);
}
END_TEST

START_TEST(to_lowerTest8) {
  const char *str1 = "!`~@><?|[];:<>,./+=-_";
  const char *str2 = "!`~@><?|[];:<>,./+=-_";
  char *result = (char *)s21_to_lower(str1);
  ck_assert_int_eq(strcmp(str2, result), 0);
  free(result);
}
END_TEST

START_TEST(to_lowerTest9) {
  const char *str1 = "Q!`~@>GFd<?|[];A:<>,./+=-_";
  const char *str2 = "q!`~@>gfd<?|[];a:<>,./+=-_";
  char *result = (char *)s21_to_lower(str1);
  ck_assert_int_eq(strcmp(str2, result), 0);
  free(result);
}
END_TEST

START_TEST(to_lowerTest10) {
  const char *str1 = "hello";
  const char *str2 = "hello";
  char *result = (char *)s21_to_lower(str1);
  ck_assert_int_eq(strcmp(str2, result), 0);
  free(result);
}
END_TEST