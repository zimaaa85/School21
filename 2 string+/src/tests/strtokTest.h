#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *strtokSuite();

START_TEST(strtokTest1) {
  char str1[12] = "Hello world\0";
  char str2[12] = "Hello world\0";
  const char *delim = " ";
  ck_assert_int_eq(strcmp(s21_strtok(str1, delim), strtok(str2, delim)), 0);
  ck_assert_int_eq(strcmp(s21_strtok(NULL, delim), strtok(NULL, delim)), 0);
  if (!strtok(NULL, delim)) {
    ck_assert_int_eq((long int)s21_strtok(s21_NULL, delim), 0);
  }
}
END_TEST

START_TEST(strtokTest2) {
  char str1[12] = "Hello world\0";
  char str2[12] = "Hello world\0";
  const char *delim = "@";
  ck_assert_int_eq(strcmp(s21_strtok(str1, delim), strtok(str2, delim)), 0);
  if (strtok(NULL, delim) == NULL) {
    ck_assert_int_eq((long int)s21_strtok(s21_NULL, delim), 0);
  }
}
END_TEST

START_TEST(strtokTest3) {
  char str1[12] = "Hello world\0";
  char str2[12] = "Hello world\0";
  const char *delim = "eo@";
  ck_assert_int_eq(strcmp(s21_strtok(str1, delim), strtok(str2, delim)), 0);
  ck_assert_int_eq(strcmp(s21_strtok(s21_NULL, delim), strtok(NULL, delim)), 0);
  ck_assert_int_eq(strcmp(s21_strtok(s21_NULL, delim), strtok(NULL, delim)), 0);
  ck_assert_int_eq(strcmp(s21_strtok(s21_NULL, delim), strtok(NULL, delim)), 0);
  if (strtok(NULL, delim) == NULL) {
    ck_assert_int_eq((long int)s21_strtok(s21_NULL, delim), 0);
  }
}
END_TEST

START_TEST(strtokTest4) {
  char str1[40] = "Hello world\n\0";
  char str2[40] = "Hello world\n\0";
  const char *delim = "\n";
  ck_assert_int_eq(strcmp(s21_strtok(str1, delim), strtok(str2, delim)), 0);
  if (!strtok(NULL, delim)) {
    ck_assert_int_eq((long int)s21_strtok(s21_NULL, delim), 0);
  }
}
END_TEST

START_TEST(strtokTest5) {
  char str1[40] = "Hello world\n\0";
  char str2[40] = "Hello world\n\0";
  const char *delim = "$-=";
  ck_assert_int_eq(strcmp(s21_strtok(str1, delim), strtok(str2, delim)), 0);
  if (!strtok(NULL, delim)) {
    ck_assert_int_eq((long int)s21_strtok(s21_NULL, delim), 0);
  }
}
END_TEST

START_TEST(strtokTest6) {
  char str1[40] = "Hello world\n\0";
  char str2[40] = "Hello world\n\0";
  const char *delim = "e \n+";
  ck_assert_int_eq(strcmp(s21_strtok(str1, delim), strtok(str2, delim)), 0);
  ck_assert_int_eq(strcmp(s21_strtok(s21_NULL, delim), strtok(NULL, delim)), 0);
  ck_assert_int_eq(strcmp(s21_strtok(s21_NULL, delim), strtok(NULL, delim)), 0);
  if (!strtok(NULL, delim)) {
    ck_assert_int_eq((long int)s21_strtok(s21_NULL, delim), 0);
  }
}
END_TEST

START_TEST(strtokTest7) {
  char str1[40] = "a\n\0";
  char str2[40] = "a\n\0";
  const char *delim = "a";
  ck_assert_int_eq(strcmp(s21_strtok(str1, delim), strtok(str2, delim)), 0);
  if (!strtok(NULL, delim)) {
    ck_assert_int_eq((long int)s21_strtok(s21_NULL, delim), 0);
  }
}
END_TEST

START_TEST(strtokTest8) {
  char str1[40] = "a\n\0";
  char str2[40] = "a\n\0";
  const char *delim = "4";
  ck_assert_int_eq(strcmp(s21_strtok(str1, delim), strtok(str2, delim)), 0);
  if (!strtok(NULL, delim)) {
    ck_assert_int_eq((long int)s21_strtok(s21_NULL, delim), 0);
  }
}
END_TEST

START_TEST(strtokTest9) {
  char str1[40] = "a\n\0";
  char str2[40] = "a\n\0";
  const char *delim = "\na";
  if (!strtok(str2, delim)) {
    ck_assert_int_eq((long int)s21_strtok(str1, delim), 0);
  }
}
END_TEST

START_TEST(strtokTest10) {
  char str1[40] = "\0";
  const char *delim = "a";
  ck_assert_int_eq((long int)s21_strtok(str1, delim), 0);
}
END_TEST

START_TEST(strtokTest11) {
  char str1[40] = "\0";
  const char *delim = "\0";
  ck_assert_int_eq((long int)s21_strtok(str1, delim), 0);
}
END_TEST

START_TEST(strtokTest12) {
  char str1[40] = "\0";
  const char *delim = "\n$s1";
  ck_assert_int_eq((long int)s21_strtok(str1, delim), 0);
}
END_TEST

START_TEST(strtokTest13) {
  char str1[12] = "Hello world";
  char str2[12] = "Hello world";
  const char *delim = " ";
  ck_assert_int_eq(strcmp(s21_strtok(str1, delim), strtok(str2, delim)), 0);
  ck_assert_int_eq(strcmp(s21_strtok(NULL, delim), strtok(NULL, delim)), 0);
  if (!strtok(NULL, delim)) {
    ck_assert_int_eq((long int)s21_strtok(s21_NULL, delim), 0);
  }
}
END_TEST

START_TEST(strtokTest14) {
  char str1[40] = " Hello world ";
  char str2[40] = " Hello world ";
  const char *delim = " ";
  ck_assert_int_eq(strcmp(s21_strtok(str1, delim), strtok(str2, delim)), 0);
  ck_assert_int_eq(strcmp(s21_strtok(NULL, delim), strtok(NULL, delim)), 0);
  ck_assert_int_eq((long int)s21_strtok(s21_NULL, delim), 0);
  ck_assert_int_eq((long int)s21_strtok(s21_NULL, delim), 0);
}
END_TEST
