#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *to_upperSuite();

START_TEST(to_upperTest1) {
  const char *str1 = "Hello world!\0";
  const char *str2 = "HELLO WORLD!\0";
  char *result = (char *)s21_to_upper(str1);
  ck_assert_int_eq(strcmp(str2, result), 0);
  free(result);
}
END_TEST

START_TEST(to_upperTest2) {
  const char *str1 = "Hello world\n\0";
  const char *str2 = "HELLO WORLD\n\0";
  char *result = (char *)s21_to_upper(str1);
  ck_assert_int_eq(strcmp(str2, result), 0);
  free(result);
}
END_TEST

START_TEST(to_upperTest3) {
  const char *str1 = "a\n\0";
  const char *str2 = "A\n\0";
  char *result = (char *)s21_to_upper(str1);
  ck_assert_int_eq(strcmp(str2, result), 0);
  free(result);
}
END_TEST

START_TEST(to_upperTest4) {
  const char *str1 = " \n\0";
  const char *str2 = " \n\0";
  char *result = (char *)s21_to_upper(str1);
  ck_assert_int_eq(strcmp(str2, result), 0);
  free(result);
}
END_TEST

START_TEST(to_upperTest5) {
  const char *str1 = " \0";
  const char *str2 = " \0";
  char *result = (char *)s21_to_upper(str1);
  ck_assert_int_eq(strcmp(str2, result), 0);
  free(result);
}
END_TEST

START_TEST(to_upperTest6) {
  const char *str1 = "\n\0";
  const char *str2 = "\n\0";
  char *result = (char *)s21_to_upper(str1);
  ck_assert_int_eq(strcmp(str2, result), 0);
  free(result);
}
END_TEST

START_TEST(to_upperTest7) {
  const char *str1 = "\0";
  char *result = (char *)s21_to_upper(str1);
  ck_assert_int_eq((long int)result, 0);
  free(result);
}
END_TEST

START_TEST(to_upperTest8) {
  const char *str1 = "!`~@><?|[];:<>,./+=-_";
  const char *str2 = "!`~@><?|[];:<>,./+=-_";
  char *result = (char *)s21_to_upper(str1);
  ck_assert_int_eq(strcmp(str2, result), 0);
  free(result);
}
END_TEST

START_TEST(to_upperTest9) {
  const char *str1 = "q!`~@>gfd<?|[];a:<>,./+=-_";
  const char *str2 = "Q!`~@>GFD<?|[];A:<>,./+=-_";
  char *result = (char *)s21_to_upper(str1);
  ck_assert_int_eq(strcmp(str2, result), 0);
  free(result);
}
END_TEST

START_TEST(to_upperTest10) {
  const char *str1 = "HELLO";
  const char *str2 = "HELLO";
  char *result = (char *)s21_to_upper(str1);
  ck_assert_int_eq(strcmp(str2, result), 0);
  free(result);
}
END_TEST