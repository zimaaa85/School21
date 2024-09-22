#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../print_s21_decimal.h"
#include "../s21_decimal.h"

Suite *decimalPrintSuite();

START_TEST(decimalTestPrint) {
  s21_decimal value = decimal_from_string("-0.0000000000017679");
  print_decimal(value);
  print_ints(&value, sizeof value);
  print_bits(&value, sizeof value);
  ck_assert_int_eq(0, 0);
}
END_TEST
