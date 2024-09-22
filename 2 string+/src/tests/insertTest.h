#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *insertSuite();

START_TEST(insertTest1) {
  const char *str1 = "Hello world!\0";
  const char *str2 = "GG\0";
  const char *result = "HelloGG world!\0";
  char *s21_result = (char *)s21_insert(str1, str2, 5);
  ck_assert_int_eq(strcmp(result, s21_result), 0);
  free(s21_result);
}
END_TEST

START_TEST(insertTest2) {
  const char *str1 = "Hello world!\0";
  const char *str2 = "dsfjdskfhdskhfkdshfjkdshfjkdshfjkhds\0";
  const char *result = "dsfjdskfhdskhfkdshfjkdshfjkdshfjkhdsHello world!\0";
  char *s21_result = (char *)s21_insert(str1, str2, 0);
  ck_assert_int_eq(strcmp(result, s21_result), 0);
  free(s21_result);
}
END_TEST

START_TEST(insertTest3) {
  const char *str1 = "Hello world!\0";
  const char *str2 = "\n\n\0";
  const char *result = "Hello world!\n\n\0";
  char *s21_result = (char *)s21_insert(str1, str2, 12);
  ck_assert_int_eq(strcmp(result, s21_result), 0);
  free(s21_result);
}
END_TEST

START_TEST(insertTest4) {
  const char *str1 = "Hello world\n\0";
  const char *str2 = "\0";
  const char *result = "Hello world\n\0";
  char *s21_result = (char *)s21_insert(str1, str2, 2);
  ck_assert_int_eq(strcmp(result, s21_result), 0);
  free(s21_result);
}
END_TEST

START_TEST(insertTest5) {
  const char *str1 = "a\n\0";
  const char *str2 = "Hello world\n";
  const char *result = "a\nHello world\n\0";
  char *s21_result = (char *)s21_insert(str1, str2, 2);
  ck_assert_int_eq(strcmp(result, s21_result), 0);
  free(s21_result);
}
END_TEST

START_TEST(insertTest6) {
  const char *str1 = " \n\0";
  const char *str2 = "*";
  const char *result = " *\n\0";
  char *s21_result = (char *)s21_insert(str1, str2, 1);
  ck_assert_int_eq(strcmp(result, s21_result), 0);
  free(s21_result);
}
END_TEST

START_TEST(insertTest7) {
  const char *str1 = " \0";
  const char *str2 = "";
  const char *result = " \0";
  char *s21_result = (char *)s21_insert(str1, str2, 0);
  ck_assert_int_eq(strcmp(result, s21_result), 0);
  free(s21_result);
}
END_TEST

START_TEST(insertTest8) {
  const char *str1 = "\n\0";
  const char *str2 = "Hello world\n\0";
  const char *result = "\nHello world\n\0";
  char *s21_result = (char *)s21_insert(str1, str2, 1);
  ck_assert_int_eq(strcmp(result, s21_result), 0);
  free(s21_result);
}
END_TEST

START_TEST(insertTest9) {
  const char *str1 = "\0";
  const char *str2 = "Hello world\n\0";
  const char *result = "Hello world\n\0";
  char *s21_result = (char *)s21_insert(str1, str2, 0);
  ck_assert_int_eq(strcmp(result, s21_result), 0);
  free(s21_result);
}
END_TEST
