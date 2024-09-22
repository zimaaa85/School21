#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *strstrSuite();

START_TEST(strstrTest1) {
  const char *str1 = "Hello world\0";
  const char *str2 = "Hello world\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "Hello\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "lo wo";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "world\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "55\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "55";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "Hello W";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "Hello world\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstrTest2) {
  const char *str1 = "Hello world\n\0";
  const char *str2 = "Hello world\n\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "Hello\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "lo wo";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "world\n\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "55\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "55";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "Hello W";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "Hello world\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstrTest3) {
  const char *str1 = "a\n\0";
  const char *str2 = "a\n\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "a\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "\n";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "\n\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "55\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "55fsdfsfdsfds";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "A\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "a\n";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstrTest4) {
  const char *str1 = " \n\0";
  const char *str2 = " \n\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = " \0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "\n\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "q\n\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "55\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "55fsdfsfdsfds";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "@\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstrTest5) {
  const char *str1 = " \0";
  const char *str2 = " \0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = " ";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "\n\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "q\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "55\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "55fsdfsfdsfds";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "@\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstrTest6) {
  const char *str1 = "\n\0";
  const char *str2 = "\n\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "\n";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "?\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "q\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "55\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "55fsdfsfdsfds";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "@\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstrTest7) {
  const char *str1 = "\0";
  const char *str2 = "\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "\n";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "?\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "q\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "55\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "55fsdfsfdsfds";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  str2 = "@\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstrTest8) {
  const char str1[2] = {5, '\0'};
  char str2[2] = {5, '\0'};
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  char str3[2] = {2, '\0'};
  ck_assert_ptr_eq(s21_strstr(str1, str3), strstr(str1, str3));
}
END_TEST