#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *flagsSuite();

START_TEST(flagsTest1) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "Hello world! - %5d|";
  sprintf(str1, format, 0);
  s21_sprintf(str2, format, 0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest2) {
  char str1[400] = "__________________________";
  char str2[400] = "__________________________";
  const char format[] = "Hello world! - %3d|";
  sprintf(str1, format, 155555);
  s21_sprintf(str2, format, 155555);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest3) {
  char str1[400] = "\0";
  char str2[400] = "\0";
  const char format[] = "%-78u Hello world! - %3d|";
  sprintf(str1, format, 4, -155555);
  s21_sprintf(str2, format, 4, -155555);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest4) {
  char str1[400] = "Hello world\n\0";
  char str2[400] = "Hello world\n\0";
  const char format[] = "% d%c Hello world! - %3.5f";
  sprintf(str1, format, 4, 'r', 5.32432432);
  s21_sprintf(str2, format, 4, 'r', 5.32432432);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest5) {
  char str1[400] = " \0";
  char str2[400] = " \0";
  const char format[] = "%s%6d Hello world!\n";
  sprintf(str1, format, "\0", 456);
  s21_sprintf(str2, format, "\0", 456);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest6) {
  char str1[400] = "\n\0";
  char str2[400] = "\n\0";
  const char format[] = "%s%-12d Hello %+f world!\n";
  sprintf(str1, format, "Hello world\n\0", 456311, 0.42343);
  s21_sprintf(str2, format, "Hello world\n\0", 456311, 0.42343);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest7) {
  char str1[400] = "\n\0";
  char str2[400] = "\n\0";
  const char format[] = "%s%-12u Hello %+0.1f world!\n";
  sprintf(str1, format, " \0", 0, 0.42343);
  s21_sprintf(str2, format, " \0", 0, 0.42343);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest8) {
  char str1[400] = "\n\0";
  char str2[400] = "\n\0";
  const char format[] = "%s%-12u Hello %+0.1f world!\n";
  sprintf(str1, format, " \0", 0, -0.42343);
  s21_sprintf(str2, format, " \0", 0, -0.42343);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest9) {
  char str1[400] = "\n\0";
  char str2[400] = "\n\0";
  const char format[] = "%s%-12u Hello %+3.1f world!\n";
  sprintf(str1, format, " \0", 0, -0.42343);
  s21_sprintf(str2, format, " \0", 0, -0.42343);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest10) {
  char str1[400] = "\n\0";
  char str2[400] = "\n\0";
  const char format[] = "%s%-12u Hello %-+3.1f world!\n";
  sprintf(str1, format, " \0", 0, -0.42343);
  s21_sprintf(str2, format, " \0", 0, -0.42343);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest11) {
  char str1[400] = "\n\0";
  char str2[400] = "\n\0";
  const char format[] = "%s%-12u Hello %+-3.1f world!\n";
  sprintf(str1, format, " \0", 0, -0.42343);
  s21_sprintf(str2, format, " \0", 0, -0.42343);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest12) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] = "%s%-12u%c Hello %+-3.1f world!\n";
  sprintf(str1, format, " \0", 0, 3, 0.42343);
  s21_sprintf(str2, format, " \0", 0, 3, 0.42343);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest13) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] = "%c%c%c%-+d";
  sprintf(str1, format, '2', 2, '!', 35555);
  s21_sprintf(str2, format, '2', 2, '!', 35555);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest14) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] = "%c%c%c%-+d";
  sprintf(str1, format, '1', 1, ']', -35555);
  s21_sprintf(str2, format, '1', 1, ']', -35555);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest15) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] = "%cHi%c%c%+54d";
  sprintf(str1, format, '\n', 55, '|', 0);
  s21_sprintf(str2, format, '\n', 55, '|', 0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest16) {
  char str1[400] = "a\n\0";
  char str2[400] = "a\n\0";
  const char format[] = "%sgo go%s%3u%d%f";
  sprintf(str1, format, "Hello world\0", "", 4255, -352, 456.2343432423);
  s21_sprintf(str2, format, "Hello world\0", "", 4255, -352, 456.2343432423);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest17) {
  char str1[400] = " \0";
  char str2[400] = " \0";
  const char format[] = "%sgo go%s%-60u%+d%5f";
  sprintf(str1, format, " \0", "\n", 4255, -352, 456.2343432423);
  s21_sprintf(str2, format, " \0", "\n", 4255, -352, 456.2343432423);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest18) {
  char str1[400] = "a\n\0";
  char str2[400] = "a\n\0";
  const char format[] = "%sgo\n\n\n go%s%-3u%+-6d%+-3.3f";
  sprintf(str1, format, "", "_______________", 4255, -352, 456.2343432423);
  s21_sprintf(str2, format, "", "_______________", 4255, -352, 456.2343432423);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest19) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] = "%c%s%c%sHello printf/n\n %f Bye = \n%4c";
  sprintf(str1, format, '\0', "", 2, "\n", 333.3, 'g');
  s21_sprintf(str2, format, '\0', "", 2, "\n", 333.3, 'g');
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest20) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] = "%3c%s%2c%sHello printf/n\n %5f Bye = \n%1c";
  sprintf(str1, format, '4', "hello", 56, "567", 333.3, 'a');
  s21_sprintf(str2, format, '4', "hello", 56, "567", 333.3, 'a');
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest21) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] = "%-5c%s%-7c%sHello printf/n\n %5.5f Bye = \n%34c";
  sprintf(str1, format, 'h', "hello\n", 188, "", 100.03, '~');
  s21_sprintf(str2, format, 'h', "hello\n", 188, "", 100.03, '~');
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest22) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] = "%-5c%s%-7c%sHello printf/n\n %-5.5f Bye = \n%34c";
  sprintf(str1, format, 'h', "hello\n", 188, "", 100.03, '~');
  s21_sprintf(str2, format, 'h', "hello\n", 188, "", 100.03, '~');
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest23) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] = "%s%+-50d%s";
  sprintf(str1, format, "hello\n", 18888, "\nbye\n");
  s21_sprintf(str2, format, "hello\n", 18888, "\nbye\n");
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest24) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] = "%s%-50u%s";
  sprintf(str1, format, "hello\n", 18888, "\nbye\n");
  s21_sprintf(str2, format, "hello\n", 18888, "\nbye\n");
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest25) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] = "%s%-50c%s";
  sprintf(str1, format, "hello\n", 10, "\nbye\n");
  s21_sprintf(str2, format, "hello\n", 10, "\nbye\n");
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest26) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] = "%s%+-50.3f%s";
  sprintf(str1, format, "hello\n", 3210.33322323, "\nbye\n");
  s21_sprintf(str2, format, "hello\n", 3210.33322323, "\nbye\n");
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest27) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] = "%s%+-50d%s";
  sprintf(str1, format, "hello\n", -18888, "\nbye\n");
  s21_sprintf(str2, format, "hello\n", -18888, "\nbye\n");
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flagsTest28) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] = "%s%+-50.3f%s";
  sprintf(str1, format, "hello\n", -3210.33322323, "\nbye\n");
  s21_sprintf(str2, format, "hello\n", -3210.33322323, "\nbye\n");
  ck_assert_str_eq(str1, str2);
}
END_TEST