#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *memcmpSuite();

START_TEST(memcmpTest1) {
  const char *str1 = "Hello world!\0";
  const char *str2 = "Hello world!\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 10), memcmp(str1, str2, 10));
  ck_assert_int_eq(s21_memcmp(str1, str2, 2), memcmp(str1, str2, 2));
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
  ck_assert_int_eq(s21_memcmp(str1, str2, 14), memcmp(str1, str2, 14));
  ck_assert_int_eq(s21_memcmp(str1, str2, 13), memcmp(str1, str2, 13));
}
END_TEST

START_TEST(memcmpTest2) {
  const char *str1 = "Hello world\n\0";
  const char *str2 = "Hello world\n\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 10), memcmp(str1, str2, 10));
  ck_assert_int_eq(s21_memcmp(str1, str2, 2), memcmp(str1, str2, 2));
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
  ck_assert_int_eq(s21_memcmp(str1, str2, 14), memcmp(str1, str2, 14));
  ck_assert_int_eq(s21_memcmp(str1, str2, 13), memcmp(str1, str2, 13));
}
END_TEST

START_TEST(memcmpTest3) {
  const char *str1 = "a\n\0";
  const char *str2 = "a\n\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 1), memcmp(str1, str2, 1));
  ck_assert_int_eq(s21_memcmp(str1, str2, 2), memcmp(str1, str2, 2));
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
  ck_assert_int_eq(s21_memcmp(str1, str2, 3), memcmp(str1, str2, 3));
  ck_assert_int_eq(s21_memcmp(str1, str2, 4), memcmp(str1, str2, 4));
}
END_TEST

START_TEST(memcmpTest4) {
  const char *str1 = " \n\0";
  const char *str2 = " \n\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 1), memcmp(str1, str2, 1));
  ck_assert_int_eq(s21_memcmp(str1, str2, 2), memcmp(str1, str2, 2));
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
  ck_assert_int_eq(s21_memcmp(str1, str2, 3), memcmp(str1, str2, 3));
  ck_assert_int_eq(s21_memcmp(str1, str2, 4), memcmp(str1, str2, 4));
}
END_TEST

START_TEST(memcmpTest5) {
  const char *str1 = " \0";
  const char *str2 = " \0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 1), memcmp(str1, str2, 1));
  ck_assert_int_eq(s21_memcmp(str1, str2, 2), memcmp(str1, str2, 2));
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
  ck_assert_int_eq(s21_memcmp(str1, str2, 3), memcmp(str1, str2, 3));
}
END_TEST

START_TEST(memcmpTest6) {
  const char *str1 = "\n\0";
  const char *str2 = "\n\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 1), memcmp(str1, str2, 1));
  ck_assert_int_eq(s21_memcmp(str1, str2, 2), memcmp(str1, str2, 2));
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
  ck_assert_int_eq(s21_memcmp(str1, str2, 3), memcmp(str1, str2, 3));
}
END_TEST

START_TEST(memcmpTest7) {
  const char *str1 = "\0";
  const char *str2 = "\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 1), memcmp(str1, str2, 1));
  ck_assert_int_eq(s21_memcmp(str1, str2, 2), memcmp(str1, str2, 2));
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
}
END_TEST

START_TEST(memcmpTest8) {
  const char *str1 = "Hello Wworld!\0";
  const char *str2 = "Hello world!\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 10), memcmp(str1, str2, 10));
  ck_assert_int_eq(s21_memcmp(str1, str2, 2), memcmp(str1, str2, 2));
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
  ck_assert_int_eq(s21_memcmp(str1, str2, 14), memcmp(str1, str2, 14));
  ck_assert_int_eq(s21_memcmp(str1, str2, 13), memcmp(str1, str2, 13));
  ck_assert_int_eq(s21_memcmp(str2, str1, 10), memcmp(str2, str1, 10));
  ck_assert_int_eq(s21_memcmp(str2, str1, 2), memcmp(str2, str1, 2));
  ck_assert_int_eq(s21_memcmp(str2, str1, 0), memcmp(str2, str1, 0));
  ck_assert_int_eq(s21_memcmp(str2, str1, 14), memcmp(str2, str1, 14));
  ck_assert_int_eq(s21_memcmp(str2, str1, 13), memcmp(str2, str1, 13));
}

START_TEST(memcmpTest9) {
  const char *str1 = "Hello world\n\0";
  const char *str2 = "!ello jhworld\n\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 10), memcmp(str1, str2, 10));
  ck_assert_int_eq(s21_memcmp(str1, str2, 2), memcmp(str1, str2, 2));
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
  ck_assert_int_eq(s21_memcmp(str1, str2, 14), memcmp(str1, str2, 14));
  ck_assert_int_eq(s21_memcmp(str1, str2, 13), memcmp(str1, str2, 13));
  ck_assert_int_eq(s21_memcmp(str2, str1, 10), memcmp(str2, str1, 10));
  ck_assert_int_eq(s21_memcmp(str2, str1, 2), memcmp(str2, str1, 2));
  ck_assert_int_eq(s21_memcmp(str2, str1, 0), memcmp(str2, str1, 0));
  ck_assert_int_eq(s21_memcmp(str2, str1, 14), memcmp(str2, str1, 14));
  ck_assert_int_eq(s21_memcmp(str2, str1, 13), memcmp(str2, str1, 13));
}

START_TEST(memcmpTest10) {
  const char *str1 = "a\n\0";
  const char *str2 = "az\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 1), memcmp(str1, str2, 1));
  ck_assert_int_eq(s21_memcmp(str1, str2, 2), memcmp(str1, str2, 2));
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
  ck_assert_int_eq(s21_memcmp(str1, str2, 4), memcmp(str1, str2, 4));
  ck_assert_int_eq(s21_memcmp(str1, str2, 3), memcmp(str1, str2, 3));
  ck_assert_int_eq(s21_memcmp(str2, str1, 1), memcmp(str2, str1, 1));
  ck_assert_int_eq(s21_memcmp(str2, str1, 2), memcmp(str2, str1, 2));
  ck_assert_int_eq(s21_memcmp(str2, str1, 0), memcmp(str2, str1, 0));
  ck_assert_int_eq(s21_memcmp(str2, str1, 4), memcmp(str2, str1, 4));
  ck_assert_int_eq(s21_memcmp(str2, str1, 3), memcmp(str2, str1, 3));
}

START_TEST(memcmpTest11) {
  const char *str1 = " \n\0";
  const char *str2 = "1111 \n\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 1), memcmp(str1, str2, 1));
  ck_assert_int_eq(s21_memcmp(str1, str2, 2), memcmp(str1, str2, 2));
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
  ck_assert_int_eq(s21_memcmp(str1, str2, 4), memcmp(str1, str2, 4));
  ck_assert_int_eq(s21_memcmp(str1, str2, 3), memcmp(str1, str2, 3));
  ck_assert_int_eq(s21_memcmp(str2, str1, 1), memcmp(str2, str1, 1));
  ck_assert_int_eq(s21_memcmp(str2, str1, 2), memcmp(str2, str1, 2));
  ck_assert_int_eq(s21_memcmp(str2, str1, 0), memcmp(str2, str1, 0));
  ck_assert_int_eq(s21_memcmp(str2, str1, 4), memcmp(str2, str1, 4));
  ck_assert_int_eq(s21_memcmp(str2, str1, 3), memcmp(str2, str1, 3));
}

START_TEST(memcmpTest12) {
  const char *str1 = " \0";
  const char *str2 = "\n\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 1), memcmp(str1, str2, 1));
  ck_assert_int_eq(s21_memcmp(str1, str2, 2), memcmp(str1, str2, 2));
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
  ck_assert_int_eq(s21_memcmp(str1, str2, 3), memcmp(str1, str2, 3));
  ck_assert_int_eq(s21_memcmp(str2, str1, 1), memcmp(str2, str1, 1));
  ck_assert_int_eq(s21_memcmp(str2, str1, 2), memcmp(str2, str1, 2));
  ck_assert_int_eq(s21_memcmp(str2, str1, 0), memcmp(str2, str1, 0));
  ck_assert_int_eq(s21_memcmp(str2, str1, 3), memcmp(str2, str1, 3));
}

START_TEST(memcmpTest13) {
  const char *str1 = "\n\0";
  const char *str2 = "d\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 1), memcmp(str1, str2, 1));
  ck_assert_int_eq(s21_memcmp(str1, str2, 2), memcmp(str1, str2, 2));
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
  ck_assert_int_eq(s21_memcmp(str1, str2, 3), memcmp(str1, str2, 3));
  ck_assert_int_eq(s21_memcmp(str2, str1, 1), memcmp(str2, str1, 1));
  ck_assert_int_eq(s21_memcmp(str2, str1, 2), memcmp(str2, str1, 2));
  ck_assert_int_eq(s21_memcmp(str2, str1, 0), memcmp(str2, str1, 0));
  ck_assert_int_eq(s21_memcmp(str2, str1, 3), memcmp(str2, str1, 3));
}

START_TEST(memcmpTest14) {
  const char *str1 = "\0";
  const char *str2 = "\n\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 1), memcmp(str1, str2, 1));
  ck_assert_int_eq(s21_memcmp(str1, str2, 2), memcmp(str1, str2, 2));
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
  ck_assert_int_eq(s21_memcmp(str2, str1, 1), memcmp(str2, str1, 1));
  ck_assert_int_eq(s21_memcmp(str2, str1, 2), memcmp(str2, str1, 2));
  ck_assert_int_eq(s21_memcmp(str2, str1, 0), memcmp(str2, str1, 0));
}

START_TEST(memcmpTest15) {
  const char str1[1] = {5};
  const char str2[1] = {5};
  ck_assert_int_eq(s21_memcmp(str1, str2, 1), memcmp(str1, str2, 1));
  ck_assert_int_eq(s21_memcmp(str2, str1, 1), memcmp(str2, str1, 1));
}
