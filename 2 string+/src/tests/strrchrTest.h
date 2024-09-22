#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *strrchrSuite();

START_TEST(strrchrTest1) {
  const char *str = "Hello world\0";
  int c = 'o';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 'H';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '7';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\0';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 'h';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 1;
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = ' ';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\n';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchrTest2) {
  const char *str = "Hello world\n\0";
  int c = 'o';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 'H';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '7';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\0';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 'h';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 1;
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = ' ';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\n';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchrTest3) {
  const char *str = "a\n\0";
  int c = 'a';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 'H';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '7';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\0';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 1;
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = ' ';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\n';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchrTest4) {
  const char *str = " \n\0";
  int c = 'a';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '7';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\0';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 1;
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = ' ';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\n';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchrTest5) {
  const char *str = " \0";
  int c = 'a';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '7';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\0';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 1;
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = ' ';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\n';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchrTest6) {
  const char *str = "\n\0";
  int c = 'a';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '7';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\0';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 1;
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = ' ';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\n';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchrTest7) {
  const char *str = "\0";
  int c = 'a';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '7';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\0';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 1;
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = ' ';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\n';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchrTest8) {
  const char *str = "";
  int c = 'a';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '7';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\0';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 1;
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = ' ';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\n';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchrTest9) {
  const char *str = "Hello world";
  int c = 'o';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 'H';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '7';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\0';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 'h';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 1;
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = ' ';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\n';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchrTest10) {
  const char *str = "Hello\0 world\0";
  int c = 'o';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 'H';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '7';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\0';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 'h';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 1;
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = ' ';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\n';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchrTest11) {
  const char *str = "Hello\0 \nworld\0";
  int c = 'o';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 'H';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '7';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\0';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 'h';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 1;
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = ' ';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\n';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchrTest12) {
  const char str[1] = {5};
  int c = 'o';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 'H';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 5;
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = '\0';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  c = 2;
}
END_TEST