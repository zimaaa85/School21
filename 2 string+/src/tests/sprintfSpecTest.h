#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *specSuite();

START_TEST(specTest1) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "Hello world! - %d";
  sprintf(str1, format, 0);
  s21_sprintf(str2, format, 0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest2) {
  char str1[40] = "1234567890987789678";
  char str2[40] = "1234567890987789678";
  const char format[] = "Hello world! - %d";
  sprintf(str1, format, 0);
  s21_sprintf(str2, format, 0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest3) {
  char str1[40] = "";
  char str2[40] = "";
  const char format[] = "%d Hello world!";
  sprintf(str1, format, 100);
  s21_sprintf(str2, format, 100);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest4) {
  char *str1 = (char *)malloc(sizeof(char) * 1024);
  char *str2 = (char *)malloc(sizeof(char) * 1024);
  const char format[] = " %d\n%d";
  sprintf(str1, format, 1, 1);
  s21_sprintf(str2, format, 1, 1);
  ck_assert_str_eq(str1, str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(specTest5) {
  char str1[40] = "";
  char str2[40] = "";
  const char format[] = "Hello %d world!";
  sprintf(str1, format, -100);
  s21_sprintf(str2, format, -100);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest6) {
  char str1[40] = "";
  char str2[40] = "";
  const char format[] = "%dHello %d%d world!%d";
  sprintf(str1, format, 4, 45, -4, 0);
  s21_sprintf(str2, format, 4, 45, -4, 0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest7) {
  char str1[40] = "";
  char str2[40] = "";
  const char format[] = {5, '%', 'd', '\0'};
  sprintf(str1, format, 4);
  s21_sprintf(str2, format, 4);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest8) {
  char str1[40] = "\0";
  char str2[40] = "\0";
  const char format[] = {'%', 'd', '\0'};
  sprintf(str1, format, 1024);
  s21_sprintf(str2, format, 1024);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest9) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "Hello world! - %c";
  sprintf(str1, format, 45);
  s21_sprintf(str2, format, 45);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest10) {
  char str1[40] = "1234567890987789678";
  char str2[40] = "1234567890987789678";
  const char format[] = "Hello world! - %c";
  sprintf(str1, format, 'r');
  s21_sprintf(str2, format, 'r');
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest11) {
  char str1[40] = "";
  char str2[40] = "";
  const char format[] = "%c Hello world!";
  sprintf(str1, format, 5);
  s21_sprintf(str2, format, 5);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest12) {
  char *str1 = (char *)malloc(sizeof(char) * 1024);
  char *str2 = (char *)malloc(sizeof(char) * 1024);
  const char format[] = " %c\n%c";
  sprintf(str1, format, '#', 'A');
  s21_sprintf(str2, format, '#', 'A');
  ck_assert_str_eq(str1, str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(specTest13) {
  char str1[40] = "";
  char str2[40] = "";
  const char format[] = "Hello %c world!";
  sprintf(str1, format, 11);
  s21_sprintf(str2, format, 11);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest14) {
  char str1[40] = "";
  char str2[40] = "";
  const char format[] = "%cHello %c%c world!%c";
  sprintf(str1, format, '3', 45, '?', 's');
  s21_sprintf(str2, format, '3', 45, '?', 's');
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest15) {
  char str1[40] = "";
  char str2[40] = "";
  const char format[] = {5, '%', 'c', '\0'};
  sprintf(str1, format, 4);
  s21_sprintf(str2, format, 4);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest16) {
  char str1[40] = "\0";
  char str2[40] = "\0";
  const char format[] = {'%', 'c', '\0'};
  sprintf(str1, format, '.');
  s21_sprintf(str2, format, '.');
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest17) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "Hello world! - %f";
  sprintf(str1, format, 0.0);
  s21_sprintf(str2, format, 0.0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest18) {
  char str1[40] = "1234567890987789678";
  char str2[40] = "1234567890987789678";
  const char format[] = "Hello world! - %f";
  sprintf(str1, format, 0.0);
  s21_sprintf(str2, format, 0.0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest19) {
  char str1[40] = "";
  char str2[40] = "";
  const char format[] = "%f Hello world!";
  sprintf(str1, format, 100.52345678942);
  s21_sprintf(str2, format, 100.52345678942);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest20) {
  char *str1 = (char *)malloc(sizeof(char) * 1024);
  char *str2 = (char *)malloc(sizeof(char) * 1024);
  const char format[] = " %f\n%f";
  sprintf(str1, format, 1.123, 542.0);
  s21_sprintf(str2, format, 1.123, 542.0);
  ck_assert_str_eq(str1, str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(specTest21) {
  char str1[40] = "";
  char str2[40] = "";
  const char format[] = "Hello %f world!";
  sprintf(str1, format, -100.2);
  s21_sprintf(str2, format, -100.2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest22) {
  char str1[1000] = "";
  char str2[1000] = "";
  const char format[] = "%fHello %f%f world!%f";
  sprintf(str1, format, 4.456, 45.0, -4.0, 0.545888);
  s21_sprintf(str2, format, 4.456, 45.0, -4.0, 0.545888);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest23) {
  char str1[1000] = "";
  char str2[1000] = "";
  const char format[] = {5, '%', 'f', '\0'};
  sprintf(str1, format, 4.0);
  s21_sprintf(str2, format, 4.0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest24) {
  char str1[40] = "\0";
  char str2[40] = "\0";
  const char format[] = {'%', 'f', '\0'};
  sprintf(str1, format, 1313.233);
  s21_sprintf(str2, format, 1313.233);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest25) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "Hello world! - %s";
  sprintf(str1, format, "Hello world\0");
  s21_sprintf(str2, format, "Hello world\0");
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest26) {
  char str1[400] = "1234567890987789678";
  char str2[400] = "1234567890987789678";
  const char format[] = "Hello world! - %s";
  sprintf(str1, format, "\0");
  s21_sprintf(str2, format, "\0");
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest27) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] = "%s Hello world!";
  sprintf(str1, format, " \n\0");
  s21_sprintf(str2, format, " \n\0");
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest28) {
  char *str1 = (char *)malloc(sizeof(char) * 1024);
  char *str2 = (char *)malloc(sizeof(char) * 1024);
  const char format[] = " %s\n%s";
  sprintf(str1, format, " \0", "\n\0");
  s21_sprintf(str2, format, " \0", "\n\0");
  ck_assert_str_eq(str1, str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(specTest29) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] = "Hello %s world!";
  sprintf(str1, format, "Hello world\0");
  s21_sprintf(str2, format, "Hello world\0");
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest30) {
  char str1[1000] = "";
  char str2[1000] = "";
  const char format[] = "%sHello %s%s world!%s";
  sprintf(str1, format, "Hi ", "\n", "dsfds1234", "!@#$$^&*");
  s21_sprintf(str2, format, "Hi ", "\n", "dsfds1234", "!@#$$^&*");
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest31) {
  char str1[1000] = "";
  char str2[1000] = "";
  const char format[] = {5, '%', 's', '\0'};
  sprintf(str1, format, "\0");
  s21_sprintf(str2, format, "\0");
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest32) {
  char str1[400] = "\0";
  char str2[400] = "\0";
  const char format[] = {'%', 's', '\0'};
  sprintf(str1, format,
          "1024123123.23213213dsfdsfsdfsdsfdsqedscsdsdfdsfwfewfdsfdsfdsfds");
  s21_sprintf(
      str2, format,
      "1024123123.23213213dsfdsfsdfsdsfdsqedscsdsdfdsfwfewfdsfdsfdsfds");
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest33) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "Hello world! - %u";
  sprintf(str1, format, 0);
  s21_sprintf(str2, format, 0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest34) {
  char str1[40] = "1234567890987789678";
  char str2[40] = "1234567890987789678";
  const char format[] = "Hello world! - %u";
  sprintf(str1, format, 0);
  s21_sprintf(str2, format, 0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest35) {
  char str1[40] = "";
  char str2[40] = "";
  const char format[] = "%u Hello world!";
  sprintf(str1, format, 100);
  s21_sprintf(str2, format, 100);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest36) {
  char *str1 = (char *)malloc(sizeof(char) * 1024);
  char *str2 = (char *)malloc(sizeof(char) * 1024);
  const char format[] = " %u\n%u";
  sprintf(str1, format, 1, 1);
  s21_sprintf(str2, format, 1, 1);
  ck_assert_str_eq(str1, str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(specTest37) {
  char str1[40] = "";
  char str2[40] = "";
  const char format[] = "Hello %u world!";
  sprintf(str1, format, 100000000);
  s21_sprintf(str2, format, 100000000);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest38) {
  char str1[40] = "";
  char str2[40] = "";
  const char format[] = "%uHello %u%u world!%u";
  sprintf(str1, format, 4, 45, 4, 0);
  s21_sprintf(str2, format, 4, 45, 4, 0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest39) {
  char str1[40] = "";
  char str2[40] = "";
  const char format[] = {5, '%', 'u', '\0'};
  sprintf(str1, format, 4);
  s21_sprintf(str2, format, 4);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest40) {
  char str1[40] = "\0";
  char str2[40] = "\0";
  const char format[] = {'%', 'u', '\0'};
  sprintf(str1, format, 1024);
  s21_sprintf(str2, format, 1024);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest41) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "%c %u %sHello world! - %d";
  sprintf(str1, format, 0, 0, "0", 0);
  s21_sprintf(str2, format, 0, 0, "0", 0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest42) {
  char str1[40] = "1234567890987789678";
  char str2[40] = "1234567890987789678";
  const char format[] = "%c %u %sHello world! - %d";
  sprintf(str1, format, '3', 345, "\n\n", -456);
  s21_sprintf(str2, format, '3', 345, "\n\n", -456);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest43) {
  char str1[40] = "";
  char str2[40] = "";
  const char format[] = "%d%c Hello world!";
  sprintf(str1, format, 100, 4);
  s21_sprintf(str2, format, 100, 4);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest44) {
  char *str1 = (char *)malloc(sizeof(char) * 1024);
  char *str2 = (char *)malloc(sizeof(char) * 1024);
  const char format[] = " %d\n%d%c%c%s";
  sprintf(str1, format, 1, 1, 'r', 10, "Hello Worldsadsadsadsadsadas");
  s21_sprintf(str2, format, 1, 1, 'r', 10, "Hello Worldsadsadsadsadsadas");
  ck_assert_str_eq(str1, str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(specTest45) {
  char str1[40] = "";
  char str2[40] = "";
  const char format[] = "Hello %d%u world!";
  sprintf(str1, format, -100, 100);
  s21_sprintf(str2, format, -100, 100);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest46) {
  char str1[40] = "";
  char str2[40] = "";
  const char format[] = "%dHello %s%f world!%u";
  sprintf(str1, format, 4, "45", -4.1564, 0);
  s21_sprintf(str2, format, 4, "45", -4.1564, 0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest47) {
  char str1[40] = "";
  char str2[40] = "";
  const char format[] = {5, '%', 'd', '%', 'f', '\0'};
  sprintf(str1, format, 4, 0.528);
  s21_sprintf(str2, format, 4, 0.528);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(specTest48) {
  char str1[40] = "\0";
  char str2[40] = "\0";
  const char format[] = {'%', 'd', '%', 'c', '\0'};
  ;
  sprintf(str1, format, 1024, 200);
  s21_sprintf(str2, format, 1024, 200);
  ck_assert_str_eq(str1, str2);
}
END_TEST