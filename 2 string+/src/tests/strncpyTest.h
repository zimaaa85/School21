#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *strncpySuite();

START_TEST(strncpyTest1) {
  char dest1[60] = "";
  char dest2[60] = "";
  const char *str = "Hello world!\0";
  s21_strncpy(dest1, str, 5);
  strncpy(dest2, str, 5);
  ck_assert_int_eq(strcmp(dest1, dest2), 0);
  s21_strncpy(dest1, str, 14);
  strncpy(dest2, str, 14);
  ck_assert_int_eq(strcmp(dest1, dest2), 0);
  s21_strncpy(dest1, str, 13);
  strncpy(dest2, str, 13);
  ck_assert_int_eq(strcmp(dest1, dest2), 0);
  s21_strncpy(dest1, str, 20);
  strncpy(dest2, str, 20);
  ck_assert_int_eq(strcmp(dest1, dest2), 0);
}
END_TEST

START_TEST(strncpyTest2) {
  char dest1[60] = "Hello world!\0";
  char dest2[60] = "Hello world!\0";
  const char *str = "Hello world\n\0";
  s21_strncpy(dest1, str, 5);
  strncpy(dest2, str, 5);
  ck_assert_int_eq(strcmp(dest1, dest2), 0);
  char dest3[60] = "Hello world!\0";
  char dest4[60] = "Hello world!\0";
  s21_strncpy(dest3, str, 14);
  strncpy(dest4, str, 14);
  ck_assert_int_eq(strcmp(dest3, dest4), 0);
  char dest5[60] = "Hello world!\0";
  char dest6[60] = "Hello world!\0";
  s21_strncpy(dest5, str, 20);
  strncpy(dest6, str, 20);
  ck_assert_int_eq(strcmp(dest5, dest6), 0);
}
END_TEST

START_TEST(strncpyTest3) {
  char dest1[40] = "a\n\0";
  char dest2[40] = "a\n\0";
  const char *str = "Hello world\n\0";
  s21_strncpy(dest1, str, 5);
  strncpy(dest2, str, 5);
  ck_assert_int_eq(strcmp(dest1, dest2), 0);
  char dest3[40] = "a\n\0";
  char dest4[40] = "a\n\0";
  s21_strncpy(dest3, str, 14);
  strncpy(dest4, str, 14);
  ck_assert_int_eq(strcmp(dest3, dest4), 0);
  char dest5[40] = "a\n\0";
  char dest6[40] = "a\n\0";
  s21_strncpy(dest5, str, 20);
  strncpy(dest6, str, 20);
  ck_assert_int_eq(strcmp(dest5, dest6), 0);
}
END_TEST

START_TEST(strncpyTest4) {
  char dest1[40] = "";
  char dest2[40] = "";
  const char *str = "";
  s21_strncpy(dest1, str, 5);
  strncpy(dest2, str, 5);
  ck_assert_int_eq(strcmp(dest1, dest2), 0);
  char dest3[40] = "";
  char dest4[40] = "";
  s21_strncpy(dest3, str, 14);
  strncpy(dest4, str, 14);
  ck_assert_int_eq(strcmp(dest3, dest4), 0);
  char dest5[40] = "";
  char dest6[40] = "";
  s21_strncpy(dest5, str, 20);
  strncpy(dest6, str, 20);
  ck_assert_int_eq(strcmp(dest5, dest6), 0);
}
END_TEST

START_TEST(strncpyTest5) {
  char dest1[40] = "\n\0";
  char dest2[40] = "\n\0";
  const char *str = "\0";
  s21_strncpy(dest1, str, 1);
  strncpy(dest2, str, 1);
  ck_assert_int_eq(strcmp(dest1, dest2), 0);
  char dest3[40] = "\n\0";
  char dest4[40] = "\n\0";
  s21_strncpy(dest3, str, 2);
  strncpy(dest4, str, 2);
  ck_assert_int_eq(strcmp(dest3, dest4), 0);
  char dest5[40] = "\n\0";
  char dest6[40] = "\n\0";
  s21_strncpy(dest5, str, 20);
  strncpy(dest6, str, 20);
  ck_assert_int_eq(strcmp(dest5, dest6), 0);
}
END_TEST

START_TEST(strncpyTest6) {
  char dest1[40] = "\0";
  char dest2[40] = "\0";
  const char *str = "\n\0";
  s21_strncpy(dest1, str, 1);
  strncpy(dest2, str, 1);
  ck_assert_int_eq(strcmp(dest1, dest2), 0);
  char dest3[40] = "\0";
  char dest4[40] = "\0";
  s21_strncpy(dest3, str, 2);
  strncpy(dest4, str, 2);
  ck_assert_int_eq(strcmp(dest3, dest4), 0);
  char dest5[40] = "\0";
  char dest6[40] = "\0";
  s21_strncpy(dest5, str, 20);
  strncpy(dest6, str, 20);
  ck_assert_int_eq(strcmp(dest5, dest6), 0);
}
END_TEST

START_TEST(strncpyTest7) {
  char dest1[40] = "\n\0";
  char dest2[40] = "\n\0";
  const char *str = "\n\0";
  s21_strncpy(dest1, str, 1);
  strncpy(dest2, str, 1);
  ck_assert_int_eq(strcmp(dest1, dest2), 0);
  char dest3[40] = "\n\0";
  char dest4[40] = "\n\0";
  s21_strncpy(dest3, str, 2);
  strncpy(dest4, str, 2);
  ck_assert_int_eq(strcmp(dest3, dest4), 0);
  char dest5[40] = "\n\0";
  char dest6[40] = "\n\0";
  s21_strncpy(dest5, str, 20);
  strncpy(dest6, str, 20);
  ck_assert_int_eq(strcmp(dest5, dest6), 0);
}
END_TEST

START_TEST(strncpyTest8) {
  char dest1[40] = "\0";
  char dest2[40] = "\0";
  const char *str = "\0";
  s21_strncpy(dest1, str, 1);
  strncpy(dest2, str, 1);
  ck_assert_int_eq(strcmp(dest1, dest2), 0);
  char dest3[40] = "\0";
  char dest4[40] = "\0";
  s21_strncpy(dest3, str, 2);
  strncpy(dest4, str, 2);
  ck_assert_int_eq(strcmp(dest3, dest4), 0);
  char dest5[40] = "\0";
  char dest6[40] = "\0";
  s21_strncpy(dest5, str, 20);
  strncpy(dest6, str, 20);
  ck_assert_int_eq(strcmp(dest5, dest6), 0);
}
END_TEST

START_TEST(strncpyTest9) {
  char dest1[2] = {5};
  char dest2[2] = {5};
  const char str[1] = {2};
  s21_strncpy(dest1, str, 1);
  strncpy(dest2, str, 1);
  ck_assert_int_eq(strcmp(dest1, dest2), 0);
}
END_TEST
