#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *strerrorSuite();

START_TEST(strerrorTest1) {
#if defined(__APPLE__)
  for (int i = 1; i < 107; i++) {
    ck_assert_str_eq((const char *)strerror(i), (const char *)s21_strerror(i));
  }
#elif defined(__linux__)
  for (int i = 1; i < 134; i++) {
    ck_assert_str_eq((const char *)strerror(i), (const char *)s21_strerror(i));
  }
#endif
}
END_TEST