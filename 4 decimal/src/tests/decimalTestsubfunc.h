#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../print_s21_decimal.h"
#include "../s21_decimal.h"

Suite *decimalSuitesubfunc();

START_TEST(dec_floor_test) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 100
  value_dec = decimal_from_string("100.1");

  // 100
  value_dec2 = decimal_from_string("100");
  s21_floor(value_dec, &value_dec);
  ck_assert_int_eq(value_dec.bits[0], value_dec2.bits[0]);
}
END_TEST

START_TEST(dec_floor_test1) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 100
  value_dec = decimal_from_string("-100.1");

  // 100
  value_dec2 = decimal_from_string("-101");
  s21_floor(value_dec, &value_dec);
  ck_assert_int_eq(value_dec.bits[0], value_dec2.bits[0]);
}
END_TEST

START_TEST(dec_floor_test2) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 100
  value_dec = decimal_from_string("-100.6");

  // 100
  value_dec2 = decimal_from_string("-101");
  s21_floor(value_dec, &value_dec);
  ck_assert_int_eq(value_dec.bits[0], value_dec2.bits[0]);
}
END_TEST

START_TEST(dec_floor_test3) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 100
  value_dec = decimal_from_string("-1000000000000.6");

  // 100
  value_dec2 = decimal_from_string("-1000000000001");
  s21_floor(value_dec, &value_dec);
  ck_assert_int_eq(value_dec.bits[0], value_dec2.bits[0]);
}
END_TEST

START_TEST(dec_floor_test4) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 100
  value_dec = decimal_from_string("1000000000000.6");

  // 100
  value_dec2 = decimal_from_string("1000000000000");
  s21_floor(value_dec, &value_dec);
  ck_assert_int_eq(value_dec.bits[0], value_dec2.bits[0]);
}
END_TEST

START_TEST(dec_round_test) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 100
  value_dec = decimal_from_string("100.1");

  // 100
  value_dec2 = decimal_from_string("101");
  s21_round(value_dec, &value_dec);
  ck_assert_int_eq(value_dec.bits[0], value_dec2.bits[0]);
}
END_TEST

START_TEST(dec_round_test1) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 100
  value_dec = decimal_from_string("-100.1");

  // 100
  value_dec2 = decimal_from_string("-100");
  s21_round(value_dec, &value_dec);
  ck_assert_int_eq(value_dec.bits[0], value_dec2.bits[0]);
}
END_TEST

START_TEST(dec_round_test2) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 100
  value_dec = decimal_from_string("-100.6");

  // 100
  value_dec2 = decimal_from_string("-100");
  s21_round(value_dec, &value_dec);
  ck_assert_int_eq(value_dec.bits[0], value_dec2.bits[0]);
}
END_TEST

START_TEST(dec_round_test3) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 100
  value_dec = decimal_from_string("-1000000000000.6");

  // 100
  value_dec2 = decimal_from_string("-1000000000000");
  s21_round(value_dec, &value_dec);
  ck_assert_int_eq(value_dec.bits[0], value_dec2.bits[0]);
}
END_TEST

START_TEST(dec_round_test4) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 100
  value_dec = decimal_from_string("1000000000000.6");

  // 100
  value_dec2 = decimal_from_string("1000000000001");
  s21_round(value_dec, &value_dec);
  ck_assert_int_eq(value_dec.bits[0], value_dec2.bits[0]);
}
END_TEST

START_TEST(dec_truncate_test) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 100
  value_dec = decimal_from_string("100.1");

  // 100
  value_dec2 = decimal_from_string("100");
  s21_truncate(value_dec, &value_dec);
  ck_assert_int_eq(value_dec.bits[0], value_dec2.bits[0]);
}
END_TEST

START_TEST(dec_truncate_test1) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 100
  value_dec = decimal_from_string("-100.1");

  // 100
  value_dec2 = decimal_from_string("-100");
  s21_truncate(value_dec, &value_dec);
  ck_assert_int_eq(value_dec.bits[0], value_dec2.bits[0]);
}
END_TEST

START_TEST(dec_truncate_test2) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 100
  value_dec = decimal_from_string("-100.6");

  // 100
  value_dec2 = decimal_from_string("-100");
  s21_truncate(value_dec, &value_dec);
  ck_assert_int_eq(value_dec.bits[0], value_dec2.bits[0]);
}
END_TEST

START_TEST(dec_truncate_test3) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 100
  value_dec = decimal_from_string("-1000000000000.6");

  // 100
  value_dec2 = decimal_from_string("-1000000000000");
  s21_truncate(value_dec, &value_dec);
  ck_assert_int_eq(value_dec.bits[0], value_dec2.bits[0]);
}
END_TEST

START_TEST(dec_truncate_test4) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 100
  value_dec = decimal_from_string("1000000000000.6");

  // 100
  value_dec2 = decimal_from_string("1000000000000");
  s21_truncate(value_dec, &value_dec);
  ck_assert_int_eq(value_dec.bits[0], value_dec2.bits[0]);
}
END_TEST

START_TEST(dec_negate_test) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 100
  value_dec = decimal_from_string("-1000000000000");

  // 100
  value_dec2 = decimal_from_string("1000000000000");
  s21_negate(value_dec, &value_dec);
  ck_assert_int_eq(value_dec.bits[3], value_dec2.bits[3]);
}
END_TEST

START_TEST(dec_negate_test1) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 100
  value_dec = decimal_from_string("0");

  // 100
  value_dec2 = decimal_from_string("-0");
  s21_negate(value_dec, &value_dec);
  ck_assert_int_eq(value_dec.bits[3], value_dec2.bits[3]);
}
END_TEST

START_TEST(dec_negate_test2) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 100
  value_dec = decimal_from_string("-1234.567");

  // 100
  value_dec2 = decimal_from_string("1234.567");
  s21_negate(value_dec, &value_dec);
  ck_assert_int_eq(value_dec.bits[3], value_dec2.bits[3]);
}
END_TEST

START_TEST(dec_negate_test3) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 100
  value_dec = decimal_from_string("1000000000000");

  // 100
  value_dec2 = decimal_from_string("-1000000000000");
  s21_negate(value_dec, &value_dec);
  ck_assert_int_eq(value_dec.bits[3], value_dec2.bits[3]);
}
END_TEST