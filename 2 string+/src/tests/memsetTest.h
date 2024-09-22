#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *memsetSuite();

START_TEST(memsetTest1) {
  char str1[] = "                  ";
  char str2[] = "                  ";
  char c = '\n';
  s21_memset(str1, c, 1);
  memset(str2, c, 1);
  ck_assert_int_eq(memcmp(str1, str2, 1), 0);
  s21_memset(str1, c, 5);
  memset(str2, c, 5);
  ck_assert_int_eq(memcmp(str1, str2, 5), 0);
  s21_memset(str1, c, 19);
  memset(str2, c, 19);
  ck_assert_int_eq(memcmp(str1, str2, 19), 0);
}
END_TEST

START_TEST(memsetTest2) {
  char str1[60];
  char str2[60];
  char c = 'e';
  s21_memset(str1, c, 1);
  memset(str2, c, 1);
  ck_assert_int_eq(memcmp(str1, str2, 1), 0);
  s21_memset(str1, c, 5);
  memset(str2, c, 5);
  ck_assert_int_eq(memcmp(str1, str2, 5), 0);
  s21_memset(str1, c, 60);
  memset(str2, c, 60);
  ck_assert_int_eq(memcmp(str1, str2, 60), 0);
}
END_TEST

START_TEST(memsetTest3) {
  void *str1 = malloc(sizeof(void *) * 50);
  void *str2 = malloc(sizeof(void *) * 50);
  char c = '^';
  s21_memset(str1, c, 1);
  memset(str2, c, 1);
  ck_assert_int_eq(memcmp(str1, str2, 1), 0);
  free(str1);
  free(str2);
  str1 = malloc(sizeof(void *) * 50);
  str2 = malloc(sizeof(void *) * 50);
  s21_memset(str1, c, 5);
  memset(str2, c, 5);
  ck_assert_int_eq(memcmp(str1, str2, 5), 0);
  free(str1);
  free(str2);
  str1 = malloc(sizeof(void *) * 50);
  str2 = malloc(sizeof(void *) * 50);
  s21_memset(str1, c, 50);
  memset(str2, c, 50);
  ck_assert_int_eq(memcmp(str1, str2, 50), 0);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(memsetTest4) {
  void *str1 = malloc(sizeof(void *) * 50);
  void *str2 = malloc(sizeof(void *) * 50);
  char c = '\0';
  s21_memset(str1, c, 1);
  memset(str2, c, 1);
  ck_assert_int_eq(memcmp(str1, str2, 1), 0);
  s21_memset(str1, c, 5);
  memset(str2, c, 5);
  ck_assert_int_eq(memcmp(str1, str2, 5), 0);
  s21_memset(str1, c, 50);
  memset(str2, c, 50);
  ck_assert_int_eq(memcmp(str1, str2, 50), 0);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(memsetTest5) {
  char str1[] = "\0";
  char str2[] = "\0";
  char c = '\n';
  s21_memset(str1, c, 1);
  memset(str2, c, 1);
  ck_assert_int_eq(memcmp(str1, str2, 1), 0);
  s21_memset(str1, c, 2);
  memset(str2, c, 2);
  ck_assert_int_eq(memcmp(str1, str2, 2), 0);
}
END_TEST

START_TEST(memsetTest6) {
  char str1[] = "\0";
  char str2[] = "\0";
  char c = '\0';
  s21_memset(str1, c, 1);
  memset(str2, c, 1);
  ck_assert_int_eq(memcmp(str1, str2, 1), 0);
  s21_memset(str1, c, 2);
  memset(str2, c, 2);
  ck_assert_int_eq(memcmp(str1, str2, 2), 0);
}
END_TEST

START_TEST(memsetTest7) {
  char str1[] = "\0Hello\0 world\n\0";
  char str2[] = "\0Hello\0 world\n\0";
  char c = '\n';
  s21_memset(str1, c, 1);
  memset(str2, c, 1);
  ck_assert_int_eq(memcmp(str1, str2, 1), 0);
  s21_memset(str1, c, 8);
  memset(str2, c, 8);
  ck_assert_int_eq(memcmp(str1, str2, 8), 0);
  s21_memset(str1, c, 16);
  memset(str2, c, 16);
  ck_assert_int_eq(memcmp(str1, str2, 16), 0);
}
END_TEST

START_TEST(memsetTest8) {
  char str1[] = "\0Hello\0 world\n\0";
  char str2[] = "\0Hello\0 world\n\0";
  char c = '\0';
  s21_memset(str1, c, 1);
  memset(str2, c, 1);
  ck_assert_int_eq(memcmp(str1, str2, 1), 0);
  s21_memset(str1, c, 8);
  memset(str2, c, 8);
  ck_assert_int_eq(memcmp(str1, str2, 8), 0);
  s21_memset(str1, c, 16);
  memset(str2, c, 16);
  ck_assert_int_eq(memcmp(str1, str2, 16), 0);
}
END_TEST

START_TEST(memsetTest9) {
  char str1[] = "Hello world\0";
  char str2[] = "Hello world\0";
  char c = '9';
  s21_memset(str1, c, 1);
  memset(str2, c, 1);
  ck_assert_int_eq(memcmp(str1, str2, 1), 0);
  s21_memset(str1, c, 8);
  memset(str2, c, 8);
  ck_assert_int_eq(memcmp(str1, str2, 8), 0);
  s21_memset(str1, c, 13);
  memset(str2, c, 13);
  ck_assert_int_eq(memcmp(str1, str2, 13), 0);
}
END_TEST

START_TEST(memsetTest10) {
  char str1[] = "a\n\0";
  char str2[] = "a\n\0";
  char c = 'd';
  s21_memset(str1, c, 1);
  memset(str2, c, 1);
  ck_assert_int_eq(memcmp(str1, str2, 1), 0);
  s21_memset(str1, c, 2);
  memset(str2, c, 2);
  ck_assert_int_eq(memcmp(str1, str2, 2), 0);
  s21_memset(str1, c, 4);
  memset(str2, c, 4);
  ck_assert_int_eq(memcmp(str1, str2, 4), 0);
}
END_TEST

START_TEST(memsetTest11) {
  char str1[] = " \n\0";
  char str2[] = " \n\0";
  char c = '>';
  s21_memset(str1, c, 1);
  memset(str2, c, 1);
  ck_assert_int_eq(memcmp(str1, str2, 1), 0);
  s21_memset(str1, c, 2);
  memset(str2, c, 2);
  ck_assert_int_eq(memcmp(str1, str2, 2), 0);
  s21_memset(str1, c, 4);
  memset(str2, c, 4);
  ck_assert_int_eq(memcmp(str1, str2, 4), 0);
}
END_TEST

START_TEST(memsetTest12) {
  char str1[] = " \0";
  char str2[] = " \0";
  char c = ' ';
  s21_memset(str1, c, 1);
  memset(str2, c, 1);
  ck_assert_int_eq(memcmp(str1, str2, 1), 0);
  s21_memset(str1, c, 2);
  memset(str2, c, 2);
  ck_assert_int_eq(memcmp(str1, str2, 2), 0);
  s21_memset(str1, c, 3);
  memset(str2, c, 3);
  ck_assert_int_eq(memcmp(str1, str2, 3), 0);
}
END_TEST

START_TEST(memsetTest13) {
  char str1[] = "\n\0";
  char str2[] = "\n\0";
  char c = '+';
  s21_memset(str1, c, 1);
  memset(str2, c, 1);
  ck_assert_int_eq(memcmp(str1, str2, 1), 0);
  s21_memset(str1, c, 2);
  memset(str2, c, 2);
  ck_assert_int_eq(memcmp(str1, str2, 2), 0);
  s21_memset(str1, c, 3);
  memset(str2, c, 3);
  ck_assert_int_eq(memcmp(str1, str2, 3), 0);
}
END_TEST

START_TEST(memsetTest14) {
  char str1[] = "\0";
  char str2[] = "\0";
  int c = 1;
  s21_memset(str1, c, 1);
  memset(str2, c, 1);
  ck_assert_int_eq(memcmp(str1, str2, 1), 0);
  s21_memset(str1, c, 2);
  memset(str2, c, 2);
  ck_assert_int_eq(memcmp(str1, str2, 2), 0);
}
END_TEST

START_TEST(memsetTest15) {
  char str1[] = "\0";
  char str2[] = "\0";
  int c = 199;
  s21_memset(str1, c, 1);
  memset(str2, c, 1);
  ck_assert_int_eq(memcmp(str1, str2, 1), 0);
  s21_memset(str1, c, 2);
  memset(str2, c, 2);
  ck_assert_int_eq(memcmp(str1, str2, 2), 0);
}
END_TEST

START_TEST(memsetTest16) {
  char str1[1] = {5};
  char str2[1] = {5};
  int c = 199;
  s21_memset(str1, c, 1);
  memset(str2, c, 1);
  ck_assert_int_eq(memcmp(str1, str2, 1), 0);
}
END_TEST
