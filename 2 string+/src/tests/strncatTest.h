#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *strncatSuite();

START_TEST(strncatTest1) {
  char str1[40] = "1234567890123456";
  char str2[40] = "1234567890123456";
  const char *source = "Hello world!\0";
  s21_strncat(str1, source, 0);
  strncat(str2, source, 0);
  ck_assert_int_eq(strcmp(str1, str2), 0);
  s21_strncat(str1, source, 5);
  strncat(str2, source, 5);
  ck_assert_int_eq(strcmp(str1, str2), 0);
  char str3[40] = "1234567890123456";
  char str4[40] = "1234567890123456";
  s21_strncat(str3, source, 14);
  strncat(str4, source, 14);
  ck_assert_int_eq(strcmp(str3, str4), 0);
}
END_TEST

START_TEST(strncatTest2) {
  char str1[40] = "";
  char str2[40] = "";
  const char *source = "Hello world\n\0";
  s21_strncat(str1, source, 0);
  strncat(str2, source, 0);
  ck_assert_int_eq(strcmp(str1, str2), 0);
  s21_strncat(str1, source, 5);
  strncat(str2, source, 5);
  ck_assert_int_eq(strcmp(str1, str2), 0);
  s21_strncat(str1, source, 14);
  strncat(str2, source, 14);
  ck_assert_int_eq(strcmp(str1, str2), 0);
}
END_TEST

START_TEST(strncatTest3) {
  char str1[40] = "";
  char str2[40] = "";
  const char *source = "a\n\0";
  s21_strncat(str1, source, 0);
  strncat(str2, source, 0);
  ck_assert_int_eq(strcmp(str1, str2), 0);
  s21_strncat(str1, source, 2);
  strncat(str2, source, 2);
  ck_assert_int_eq(strcmp(str1, str2), 0);
  s21_strncat(str1, source, 4);
  strncat(str2, source, 4);
  ck_assert_int_eq(strcmp(str1, str2), 0);
}
END_TEST

START_TEST(strncatTest4) {
  char str1[40] = "Hello world\0";
  char str2[40] = "Hello world\0";
  const char *source = " \n\0";
  s21_strncat(str1, source, 0);
  strncat(str2, source, 0);
  ck_assert_int_eq(strcmp(str1, str2), 0);
  s21_strncat(str1, source, 2);
  strncat(str2, source, 2);
  ck_assert_int_eq(strcmp(str1, str2), 0);
  s21_strncat(str1, source, 3);
  strncat(str2, source, 3);
  ck_assert_int_eq(strcmp(str1, str2), 0);
}
END_TEST

START_TEST(strncatTest5) {
  char str1[40] = "\0";
  char str2[40] = "\0";
  const char *source = " \0";
  s21_strncat(str1, source, 0);
  strncat(str2, source, 0);
  ck_assert_int_eq(strcmp(str1, str2), 0);
  s21_strncat(str1, source, 1);
  strncat(str2, source, 1);
  ck_assert_int_eq(strcmp(str1, str2), 0);
  s21_strncat(str1, source, 2);
  strncat(str2, source, 2);
  ck_assert_int_eq(strcmp(str1, str2), 0);
}
END_TEST

START_TEST(strncatTest6) {
  char str1[40] = "Hello world\n\0";
  char str2[40] = "Hello world\n\0";
  const char *source = "\n\0";
  s21_strncat(str1, source, 0);
  strncat(str2, source, 0);
  ck_assert_int_eq(strcmp(str1, str2), 0);
  s21_strncat(str1, source, 1);
  strncat(str2, source, 1);
  ck_assert_int_eq(strcmp(str1, str2), 0);
  s21_strncat(str1, source, 2);
  strncat(str2, source, 2);
  ck_assert_int_eq(strcmp(str1, str2), 0);
}
END_TEST

START_TEST(strncatTest7) {
  char str1[40] = "Hello world\n\0";
  char str2[40] = "Hello world\n\0";
  const char *source = "\0";
  s21_strncat(str1, source, 0);
  strncat(str2, source, 0);
  ck_assert_int_eq(strcmp(str1, str2), 0);
  s21_strncat(str1, source, 1);
  strncat(str2, source, 1);
  ck_assert_int_eq(strcmp(str1, str2), 0);
}
END_TEST

START_TEST(strncatTest8) {
  char str1[40] = "\0";
  char str2[40] = "\0";
  const char *source = "\0";
  s21_strncat(str1, source, 0);
  strncat(str2, source, 0);
  ck_assert_int_eq(strcmp(str1, str2), 0);
  s21_strncat(str1, source, 1);
  strncat(str2, source, 1);
  ck_assert_int_eq(strcmp(str1, str2), 0);
}
END_TEST

START_TEST(strncatTest9) {
  char str1[5] = {5, '\0'};
  char str2[5] = {5, '\0'};
  const char source[2] = {2, '\0'};
  s21_strncat(str1, source, 0);
  strncat(str2, source, 0);
  ck_assert_int_eq(strcmp(str1, str2), 0);
  s21_strncat(str1, source, 1);
  strncat(str2, source, 1);
  ck_assert_int_eq(strcmp(str1, str2), 0);
}
END_TEST
