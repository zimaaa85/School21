#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *memcpySuite();

START_TEST(memcpyTest1) {
  char dest1[] = "                  ";
  char dest2[] = "                  ";
  const char *str = "Hello world!\0";
  s21_memcpy(dest1, str, 5);
  memcpy(dest2, str, 5);
  ck_assert_int_eq(strcmp(dest1, dest2), 0);
  s21_memcpy(dest1, str, 0);
  memcpy(dest2, str, 0);
  ck_assert_int_eq(strcmp(dest1, dest2), 0);
  s21_memcpy(dest1, str, 14);
  memcpy(dest2, str, 14);
  ck_assert_int_eq(strcmp(dest1, dest2), 0);
  s21_memcpy(dest1, str, 13);
  memcpy(dest2, str, 13);
  ck_assert_int_eq(strcmp(dest1, dest2), 0);
}
END_TEST

START_TEST(memcpyTest2) {
  char dest1[60];
  char dest2[60];
  const char *str = "Hello world\n\0";
  s21_memcpy(dest1, str, 5);
  memcpy(dest2, str, 5);
  ck_assert_int_eq(memcmp(dest1, dest2, 5), 0);
  s21_memcpy(dest1, str, 0);
  memcpy(dest2, str, 0);
  ck_assert_int_eq(memcmp(dest1, dest2, 0), 0);
  s21_memcpy(dest1, str, 14);
  memcpy(dest2, str, 14);
  ck_assert_int_eq(memcmp(dest1, dest2, 14), 0);
  s21_memcpy(dest1, str, 13);
  memcpy(dest2, str, 13);
  ck_assert_int_eq(memcmp(dest1, dest2, 13), 0);
}
END_TEST

START_TEST(memcpyTest3) {
  void *dest1 = malloc(sizeof(void *) * 16);
  void *dest2 = malloc(sizeof(void *) * 16);
  const char *str = "a\n\0";
  s21_memcpy(dest1, str, 1);
  memcpy(dest2, str, 1);
  ck_assert_int_eq(memcmp(dest1, dest2, 1), 0);
  free(dest1);
  free(dest2);

  dest1 = malloc(sizeof(void *) * 16);
  dest2 = malloc(sizeof(void *) * 16);
  s21_memcpy(dest1, str, 0);
  memcpy(dest2, str, 0);
  ck_assert_int_eq(memcmp(dest1, dest2, 0), 0);
  free(dest1);
  free(dest2);

  dest1 = malloc(sizeof(void *) * 16);
  dest2 = malloc(sizeof(void *) * 16);
  s21_memcpy(dest1, str, 4);
  memcpy(dest2, str, 4);
  ck_assert_int_eq(memcmp(dest1, dest2, 4), 0);
  free(dest1);
  free(dest2);

  dest1 = malloc(sizeof(void *) * 16);
  dest2 = malloc(sizeof(void *) * 16);
  s21_memcpy(dest1, str, 3);
  memcpy(dest2, str, 3);
  ck_assert_int_eq(memcmp(dest1, dest2, 3), 0);
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(memcpyTest4) {
  void *dest1 = malloc(sizeof(void *) * 16);
  void *dest2 = malloc(sizeof(void *) * 16);
  const char *str = " \n\0";
  s21_memcpy(dest1, str, 1);
  memcpy(dest2, str, 1);
  ck_assert_int_eq(memcmp(dest1, dest2, 1), 0);

  s21_memcpy(dest1, str, 0);
  memcpy(dest2, str, 0);
  ck_assert_int_eq(memcmp(dest1, dest2, 0), 0);

  s21_memcpy(dest1, str, 4);
  memcpy(dest2, str, 4);
  ck_assert_int_eq(memcmp(dest1, dest2, 4), 0);

  s21_memcpy(dest1, str, 3);
  memcpy(dest2, str, 3);
  ck_assert_int_eq(memcmp(dest1, dest2, 3), 0);

  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(memcpyTest5) {
  void *dest1 = malloc(sizeof(void *) * 16);
  void *dest2 = malloc(sizeof(void *) * 16);
  const char *str = " \0";
  dest1 = s21_memcpy(dest1, str, 1);
  dest2 = memcpy(dest2, str, 1);
  ck_assert_int_eq(memcmp(dest1, dest2, 1), 0);
  dest1 = s21_memcpy(dest1, str, 0);
  dest2 = memcpy(dest2, str, 0);
  ck_assert_int_eq(memcmp(dest1, dest2, 0), 0);
  dest1 = s21_memcpy(dest1, str, 2);
  dest2 = memcpy(dest2, str, 2);
  ck_assert_int_eq(memcmp(dest1, dest2, 2), 0);
  dest1 = s21_memcpy(dest1, str, 3);
  dest2 = memcpy(dest2, str, 3);
  ck_assert_int_eq(memcmp(dest1, dest2, 3), 0);
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(memcpyTest6) {
  char dest1[] = "\0 123456789";
  char dest2[] = "\0 123456789";
  const char *str = "\n\0";
  s21_memcpy(dest1, str, 1);
  memcpy(dest2, str, 1);
  ck_assert_int_eq(memcmp(dest1, dest2, 1), 0);
  s21_memcpy(dest1, str, 0);
  memcpy(dest2, str, 0);
  ck_assert_int_eq(memcmp(dest1, dest2, 0), 0);
  s21_memcpy(dest1, str, 2);
  memcpy(dest2, str, 2);
  ck_assert_int_eq(memcmp(dest1, dest2, 2), 0);
  s21_memcpy(dest1, str, 3);
  memcpy(dest2, str, 3);
  ck_assert_int_eq(memcmp(dest1, dest2, 3), 0);
}
END_TEST

START_TEST(memcpyTest7) {
  char dest1[] = "\0 123456789";
  char dest2[] = "\0 123456789";
  const char *str = "\0";
  s21_memcpy(dest1, str, 1);
  memcpy(dest2, str, 1);
  ck_assert_int_eq(memcmp(dest1, dest2, 1), 0);
  s21_memcpy(dest1, str, 0);
  memcpy(dest2, str, 0);
  ck_assert_int_eq(memcmp(dest1, dest2, 0), 0);
  s21_memcpy(dest1, str, 2);
  memcpy(dest2, str, 2);
  ck_assert_int_eq(memcmp(dest1, dest2, 2), 0);
}
END_TEST

START_TEST(memcpyTest8) {
  char dest1[] = "____________________";
  char dest2[] = "____________________";
  const char *str = "\0 1234567\n89";
  s21_memcpy(dest1, str, 5);
  memcpy(dest2, str, 5);
  ck_assert_int_eq(memcmp(dest1, dest2, 5), 0);
  s21_memcpy(dest1, str, 0);
  memcpy(dest2, str, 0);
  ck_assert_int_eq(memcmp(dest1, dest2, 0), 0);
  s21_memcpy(dest1, str, 11);
  memcpy(dest2, str, 11);
  ck_assert_int_eq(memcmp(dest1, dest2, 11), 0);
}
END_TEST

START_TEST(memcpyTest9) {
  char dest1[60];
  char dest2[60];
  const char *str = "\0 12345\0 67\n89";
  s21_memcpy(dest1, str, 5);
  memcpy(dest2, str, 5);
  ck_assert_int_eq(memcmp(dest1, dest2, 5), 0);
  s21_memcpy(dest1, str, 0);
  memcpy(dest2, str, 0);
  ck_assert_int_eq(memcmp(dest1, dest2, 0), 0);
  s21_memcpy(dest1, str, 15);
  memcpy(dest2, str, 15);
  ck_assert_int_eq(memcmp(dest1, dest2, 15), 0);
}
END_TEST

START_TEST(memcpyTest10) {
  void *dest1 = malloc(sizeof(void *) * 25);
  void *dest2 = malloc(sizeof(void *) * 25);
  const char *str = "\0 12345\0 67\n89";
  s21_memcpy(dest1, str, 5);
  memcpy(dest2, str, 5);
  ck_assert_int_eq(memcmp(dest1, dest2, 5), 0);
  s21_memcpy(dest1, str, 0);
  memcpy(dest2, str, 0);
  ck_assert_int_eq(memcmp(dest1, dest2, 0), 0);
  s21_memcpy(dest1, str, 15);
  memcpy(dest2, str, 15);
  ck_assert_int_eq(memcmp(dest1, dest2, 15), 0);
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(memcpyTest11) {
  void *dest1 = malloc(sizeof(void *) * 1);
  void *dest2 = malloc(sizeof(void *) * 1);
  const char str[1] = {5};
  s21_memcpy(dest1, str, 1);
  memcpy(dest2, str, 1);
  free(dest1);
  free(dest2);
}
END_TEST
