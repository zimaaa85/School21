#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_decimal.h"

Suite *decimalSuite();

START_TEST(get_bit_dec) {
  s21_decimal number;
  s21_init_dec(&number);
  ck_assert_int_eq(s21_get_bit_dec(number, 1), 0);
  ck_assert_int_eq(s21_get_bit_dec(number, 12), 0);
  ck_assert_int_eq(s21_get_bit_dec(number, 35), 0);
  ck_assert_int_eq(s21_get_bit_dec(number, 120), 0);
}
END_TEST

START_TEST(set_bit_dec) {
  s21_decimal number;
  s21_init_dec(&number);
  s21_set_bit_dec(&number, 12, 1);
  ck_assert_int_eq(s21_get_bit_dec(number, 12), 1);
  ck_assert_int_eq(s21_get_bit_dec(number, 13), 0);
}
END_TEST

START_TEST(get_sign_dec) {
  s21_decimal number;
  s21_init_dec(&number);
  s21_set_bit_dec(&number, 127, 1);
  ck_assert_int_eq(s21_get_sign_dec(number), 1);
}
END_TEST

START_TEST(get_sign_dec2) {
  s21_decimal number;
  s21_init_dec(&number);
  s21_set_bit_dec(&number, 127, 0);
  ck_assert_int_eq(s21_get_sign_dec(number), 0);
}
END_TEST

START_TEST(set_bit_dec2) {
  s21_decimal number;
  s21_init_dec(&number);
  s21_set_bit_dec(&number, 40, 1);
  ck_assert_int_eq(s21_get_bit_dec(number, 40), 1);
  ck_assert_int_eq(s21_get_bit_dec(number, 13), 0);
}
END_TEST

START_TEST(set_bit_dec3) {
  s21_decimal number;
  s21_init_dec(&number);
  s21_set_bit_dec(&number, 112, 1);
  ck_assert_int_eq(s21_get_bit_dec(number, 112), 1);
  ck_assert_int_eq(s21_get_bit_dec(number, 13), 0);
}
END_TEST

START_TEST(set_sign_dec) {
  s21_decimal number;
  s21_init_dec(&number);
  s21_set_sign_dec(&number, 1);
  ck_assert_int_eq(s21_get_sign_dec(number), 1);
}
END_TEST

START_TEST(set_sign_dec2) {
  s21_decimal number;
  s21_init_dec(&number);
  s21_set_bit_dec(&number, 127, 1);
  s21_set_sign_dec(&number, 0);
  ck_assert_int_eq(s21_get_sign_dec(number), 0);
}
END_TEST

START_TEST(get_scale_dec) {
  s21_decimal number;
  s21_init_dec(&number);
  ck_assert_int_eq(s21_get_scale_dec(number), 0);
  int shift = 3 * 32 + 16;
  s21_set_bit_dec(&number, shift, 1);
  ck_assert_int_eq(s21_get_scale_dec(number), 1);
  s21_set_bit_dec(&number, shift + 1, 1);
  ck_assert_int_eq(s21_get_scale_dec(number), 3);
  s21_set_bit_dec(&number, shift + 2, 1);
  ck_assert_int_eq(s21_get_scale_dec(number), 7);
  s21_set_bit_dec(&number, shift + 1, 0);
  // 101
  ck_assert_int_eq(s21_get_scale_dec(number), 5);
  s21_set_bit_dec(&number, shift + 3, 1);
  // 1101
  ck_assert_int_eq(s21_get_scale_dec(number), 13);
  s21_set_bit_dec(&number, shift, 0);
  // 1100
  ck_assert_int_eq(s21_get_scale_dec(number), 12);
  s21_set_bit_dec(&number, shift, 1);
  s21_set_bit_dec(&number, shift + 1, 1);
  s21_set_bit_dec(&number, shift + 4, 1);
  // 11111
  ck_assert_int_eq(s21_get_scale_dec(number), 31);
}
END_TEST

START_TEST(init_bcd) {
  s21_bcd value;
  s21_init_bcd(&value);
  ck_assert_int_eq(value.bits[0], 0);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
  ck_assert_int_eq(value.sign_exp, 0);
}
END_TEST

START_TEST(set_scale_dec) {
  s21_decimal value;
  s21_init_dec(&value);
  value.bits[0] = 12345212;
  s21_set_scale_dec(&value, 3);
  ck_assert_int_eq(value.bits[3], 196608);
}
END_TEST

START_TEST(set_scale_dec2) {
  s21_decimal value;
  s21_init_dec(&value);
  value.bits[0] = 3276858702;
  value.bits[1] = 2694384412;
  value.bits[2] = 176087429;
  s21_set_sign_dec(&value, 1);
  s21_set_scale_dec(&value, 0);
  ck_assert_int_eq(value.bits[3], 2147483648);
}
END_TEST

START_TEST(set_scale_dec3) {
  s21_decimal value;
  s21_init_dec(&value);
  value.bits[0] = 2554751261;
  value.bits[1] = 2224880747;
  value.bits[2] = 426;
  s21_set_sign_dec(&value, 0);
  s21_set_scale_dec(&value, 8);
  ck_assert_int_eq(value.bits[3], 524288);
}
END_TEST

START_TEST(left_shift_int) {
  unsigned int value = 2721;
  s21_left_shift_int(&value);
  ck_assert_int_eq(value, 5442);
}
END_TEST

START_TEST(left_shift_int2) {
  unsigned int value = 0;
  int res = s21_left_shift_int(&value);
  ck_assert_int_eq(value, 0);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(left_shift_int3) {
  unsigned int value = 1;
  int res = s21_left_shift_int(&value);
  ck_assert_int_eq(value, 2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(left_shift_int4) {
  unsigned int value = 2869094422;
  int res = s21_left_shift_int(&value);
  ck_assert_int_eq(value, 1443221548);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(left_shift_int5) {
  unsigned int value = 4294967295;
  int res = s21_left_shift_int(&value);
  ck_assert_int_eq(value, 4294967294);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(right_shift_int) {
  unsigned int value = 9529;
  int res = s21_right_shift_int(&value);
  ck_assert_int_eq(value, 4764);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(right_shift_int2) {
  unsigned int value = 4764;
  int res = s21_right_shift_int(&value);
  ck_assert_int_eq(value, 2382);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(right_shift_int3) {
  unsigned int value = 4294967295;
  int res = s21_right_shift_int(&value);
  ck_assert_int_eq(value, 2147483647);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(right_shift_int4) {
  unsigned int value = 4294967294;
  int res = s21_right_shift_int(&value);
  ck_assert_int_eq(value, 2147483647);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(copy_dec) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  value_dec.bits[0] = 43533;
  value_dec.bits[1] = 3243242;
  value_dec.bits[2] = 43;
  s21_copy_dec(&value_dec, &value_dec2);
  ck_assert_int_eq(value_dec2.bits[0], 43533);
  ck_assert_int_eq(value_dec2.bits[1], 3243242);
  ck_assert_int_eq(value_dec2.bits[2], 43);
  ck_assert_int_eq(value_dec2.bits[3], 0);
}
END_TEST

START_TEST(left_shift_dec) {
  s21_decimal value_dec;
  s21_init_dec(&value_dec);
  value_dec.bits[0] = 2554751261;
  value_dec.bits[1] = 2224880747;
  value_dec.bits[2] = 426;
  value_dec.bits[3] = 524288;
  s21_left_shift_dec(&value_dec);
  ck_assert_int_eq(value_dec.bits[0], 814535226);
  ck_assert_int_eq(value_dec.bits[1], 154794199);
  ck_assert_int_eq(value_dec.bits[2], 853);
  ck_assert_int_eq(value_dec.bits[3], 524288);
}
END_TEST

START_TEST(right_shift_dec) {
  s21_decimal value_dec;
  s21_init_dec(&value_dec);
  value_dec.bits[0] = 2554751261;
  value_dec.bits[1] = 2224880747;
  value_dec.bits[2] = 426;
  value_dec.bits[3] = 524288;
  s21_right_shift_dec(&value_dec);
  ck_assert_int_eq(value_dec.bits[0], 3424859278);
  ck_assert_int_eq(value_dec.bits[1], 1112440373);
  ck_assert_int_eq(value_dec.bits[2], 213);
  ck_assert_int_eq(value_dec.bits[3], 524288);
}
END_TEST

START_TEST(logic_test) {
  int true = 1;
  int false = 0;
  ck_assert_int_eq(!true, 0);
  ck_assert_int_eq(!false, 1);
}
END_TEST

START_TEST(convert_dec_to_bcd) {
  s21_decimal value_dec;
  s21_init_dec(&value_dec);
  value_dec.bits[0] = 30;
  s21_bcd value_bcd;
  s21_init_bcd(&value_bcd);
  s21_dec_to_bcd(&value_dec, &value_bcd);
  ck_assert_int_eq(value_bcd.bits[0], 48);
  ck_assert_int_eq(value_bcd.bits[1], value_dec.bits[1]);
  ck_assert_int_eq(value_bcd.bits[2], value_dec.bits[2]);
  ck_assert_int_eq(value_bcd.bits[3], value_dec.bits[3]);
}
END_TEST

START_TEST(convert_dec_to_bcd_to_dec) {
  s21_decimal value_dec, value_dec2, value_res;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  s21_init_dec(&value_res);
  value_dec.bits[0] = 1564;
  s21_copy_dec(&value_dec, &value_dec2);
  s21_bcd value_bcd;
  s21_init_bcd(&value_bcd);
  s21_dec_to_bcd(&value_dec, &value_bcd);
  s21_bcd_to_dec(&value_res, &value_bcd);
  ck_assert_int_eq(value_dec2.bits[0], value_res.bits[0]);
  ck_assert_int_eq(value_dec2.bits[1], value_res.bits[1]);
  ck_assert_int_eq(value_dec2.bits[2], value_res.bits[2]);
  ck_assert_int_eq(value_dec2.bits[3], value_res.bits[3]);
}
END_TEST

START_TEST(convert_dec_to_bcd_to_dec2) {
  s21_decimal value_dec, value_dec2, value_res;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  s21_init_dec(&value_res);
  // 78678687654486.88789789
  value_dec.bits[0] = 2554751261;
  value_dec.bits[1] = 2224880747;
  value_dec.bits[2] = 426;
  value_dec.bits[3] = 524288;
  s21_copy_dec(&value_dec, &value_dec2);
  s21_bcd value_bcd;
  s21_init_bcd(&value_bcd);
  s21_dec_to_bcd(&value_dec, &value_bcd);
  s21_bcd_to_dec(&value_res, &value_bcd);
  ck_assert_int_eq(value_dec2.bits[0], value_res.bits[0]);
  ck_assert_int_eq(value_dec2.bits[1], value_res.bits[1]);
  ck_assert_int_eq(value_dec2.bits[2], value_res.bits[2]);
  ck_assert_int_eq(value_dec2.bits[3], value_res.bits[3]);
}
END_TEST

START_TEST(convert_dec_to_bcd_to_dec3) {
  s21_decimal value_dec, value_dec2, value_res;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  s21_init_dec(&value_res);
  //-0.00000
  value_dec.bits[3] = 2147811328;
  s21_copy_dec(&value_dec, &value_dec2);
  s21_bcd value_bcd;
  s21_init_bcd(&value_bcd);
  s21_dec_to_bcd(&value_dec, &value_bcd);
  s21_bcd_to_dec(&value_res, &value_bcd);
  ck_assert_int_eq(value_dec2.bits[0], value_res.bits[0]);
  ck_assert_int_eq(value_dec2.bits[1], value_res.bits[1]);
  ck_assert_int_eq(value_dec2.bits[2], value_res.bits[2]);
  ck_assert_int_eq(value_dec2.bits[3], value_res.bits[3]);
}
END_TEST

START_TEST(convert_dec_to_bcd_to_dec4) {
  s21_decimal value_dec, value_dec2, value_res;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  s21_init_dec(&value_res);
  // 79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 0;
  s21_copy_dec(&value_dec, &value_dec2);
  s21_bcd value_bcd;
  s21_init_bcd(&value_bcd);
  s21_dec_to_bcd(&value_dec, &value_bcd);
  s21_bcd_to_dec(&value_res, &value_bcd);
  ck_assert_int_eq(value_dec2.bits[0], value_res.bits[0]);
  ck_assert_int_eq(value_dec2.bits[1], value_res.bits[1]);
  ck_assert_int_eq(value_dec2.bits[2], value_res.bits[2]);
  ck_assert_int_eq(value_dec2.bits[3], value_res.bits[3]);
}
END_TEST

START_TEST(convert_dec_to_bcd_to_dec5) {
  s21_decimal value_dec, value_dec2, value_res;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  s21_init_dec(&value_res);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  s21_copy_dec(&value_dec, &value_dec2);
  s21_bcd value_bcd;
  s21_init_bcd(&value_bcd);
  s21_dec_to_bcd(&value_dec, &value_bcd);
  s21_bcd_to_dec(&value_res, &value_bcd);
  ck_assert_int_eq(value_dec2.bits[0], value_res.bits[0]);
  ck_assert_int_eq(value_dec2.bits[1], value_res.bits[1]);
  ck_assert_int_eq(value_dec2.bits[2], value_res.bits[2]);
  ck_assert_int_eq(value_dec2.bits[3], value_res.bits[3]);
}
END_TEST

START_TEST(convert_dec_to_bcd_to_dec6) {
  s21_decimal value_dec, value_dec2, value_res;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  s21_init_dec(&value_res);
  //-0.15645648877200000087878700000
  value_dec.bits[0] = 1688374240;
  value_dec.bits[1] = 559555485;
  value_dec.bits[2] = 848152325;
  value_dec.bits[3] = 2149384192;
  s21_copy_dec(&value_dec, &value_dec2);
  s21_bcd value_bcd;
  s21_init_bcd(&value_bcd);
  s21_dec_to_bcd(&value_dec, &value_bcd);
  s21_bcd_to_dec(&value_res, &value_bcd);
  ck_assert_int_eq(value_dec2.bits[0], value_res.bits[0]);
  ck_assert_int_eq(value_dec2.bits[1], value_res.bits[1]);
  ck_assert_int_eq(value_dec2.bits[2], value_res.bits[2]);
  ck_assert_int_eq(value_dec2.bits[3], value_res.bits[3]);
}
END_TEST

START_TEST(greater1) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-0.156456488772
  value_dec.bits[0] = 1837666116;
  value_dec.bits[1] = 36;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 2148270080;

  //-45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 2147680256;
  ck_assert_int_eq(s21_is_greater(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_greater(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(greater2) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;

  //-79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 2147483648;
  ck_assert_int_eq(s21_is_greater(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_greater(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(greater3) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;

  // 0
  ck_assert_int_eq(s21_is_greater(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_greater(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(greater4) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;

  // 79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 0;
  ck_assert_int_eq(s21_is_greater(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_greater(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(greater5) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-3243243299999.0001
  value_dec.bits[0] = 1076527857;
  value_dec.bits[1] = 7551264;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 2147745792;

  //-32432432999990001
  value_dec2.bits[0] = 1076527857;
  value_dec2.bits[1] = 7551264;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 2147483648;

  ck_assert_int_eq(s21_is_greater(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_greater(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(greater6) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-0.156456488772000012512
  value_dec.bits[0] = 2616449248;
  value_dec.bits[1] = 2068126616;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 2148859904;

  //-45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 2147680256;
  ck_assert_int_eq(s21_is_greater(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_greater(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(greater7) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  //-0.79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 2149384192;
  ck_assert_int_eq(s21_is_greater(value_dec, value_dec2), 0);
}
END_TEST

START_TEST(greater8) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 0.156456488772
  value_dec.bits[0] = 1837666116;
  value_dec.bits[1] = 36;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 786432;
  // 45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 196608;
  ck_assert_int_eq(s21_is_greater(value_dec2, value_dec), 1);
  ck_assert_int_eq(s21_is_greater(value_dec, value_dec2), 0);
}
END_TEST

START_TEST(greater9) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 0;
  // 79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 0;
  ck_assert_int_eq(s21_is_greater(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_greater(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(greater10) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 0;
  // 0
  ck_assert_int_eq(s21_is_greater(value_dec2, value_dec), 0);
  ck_assert_int_eq(s21_is_greater(value_dec, value_dec2), 1);
}
END_TEST

START_TEST(greater11) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 3243243299999.0001
  value_dec.bits[0] = 1076527857;
  value_dec.bits[1] = 7551264;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 262144;
  // 32432432999990001
  value_dec2.bits[0] = 1076527857;
  value_dec2.bits[1] = 7551264;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 0;
  ck_assert_int_eq(s21_is_greater(value_dec2, value_dec), 1);
  ck_assert_int_eq(s21_is_greater(value_dec, value_dec2), 0);
}
END_TEST

START_TEST(greater12) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 0;
  // 0.79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 1900544;
  ck_assert_int_eq(s21_is_greater(value_dec, value_dec2), 1);
}
END_TEST

START_TEST(greater13) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 0.156456488772000012512
  value_dec.bits[0] = 2616449248;
  value_dec.bits[1] = 2068126616;
  value_dec.bits[2] = 8;
  value_dec.bits[3] = 1376256;
  // 45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 196608;
  ck_assert_int_eq(s21_is_greater(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_greater(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(greater14) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-0
  value_dec.bits[3] = 2147483648;
  // 0
  ck_assert_int_eq(s21_is_greater(value_dec2, value_dec), 0);
  ck_assert_int_eq(s21_is_greater(value_dec, value_dec2), 0);
}
END_TEST

START_TEST(equal1) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-0.156456488772
  value_dec.bits[0] = 1837666116;
  value_dec.bits[1] = 36;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 2148270080;
  //-45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 2147680256;
  ck_assert_int_eq(s21_is_equal(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_equal(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(equal2) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  //-79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 2147483648;
  ck_assert_int_eq(s21_is_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(equal3) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  // 0
  ck_assert_int_eq(s21_is_equal(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_equal(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(equal4) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  // 79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 0;
  ck_assert_int_eq(s21_is_equal(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_equal(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(equal5) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-3243243299999.0001
  value_dec.bits[0] = 1076527857;
  value_dec.bits[1] = 7551264;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 2147745792;
  //-32432432999990001
  value_dec2.bits[0] = 1076527857;
  value_dec2.bits[1] = 7551264;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 2147483648;
  ck_assert_int_eq(s21_is_equal(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_equal(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(equal6) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-0.156456488772000012512
  value_dec.bits[0] = 2616449248;
  value_dec.bits[1] = 2068126616;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 2148859904;
  //-45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 2147680256;
  ck_assert_int_eq(s21_is_equal(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_equal(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(equal7) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  //-0.79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 2149384192;
  ck_assert_int_eq(s21_is_equal(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_equal(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(equal8) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 0.156456488772
  value_dec.bits[0] = 1837666116;
  value_dec.bits[1] = 36;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 786432;
  // 45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 196608;
  ck_assert_int_eq(s21_is_equal(value_dec2, value_dec), 0);
  ck_assert_int_eq(s21_is_equal(value_dec, value_dec2), 0);
}
END_TEST

START_TEST(equal9) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 0;
  // 79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 0;
  ck_assert_int_eq(s21_is_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(equal10) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 0;
  // 0
  ck_assert_int_eq(s21_is_equal(value_dec2, value_dec), 0);
  ck_assert_int_eq(s21_is_equal(value_dec, value_dec2), 0);
}
END_TEST

START_TEST(equal11) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 3243243299999.0001
  value_dec.bits[0] = 1076527857;
  value_dec.bits[1] = 7551264;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 262144;
  // 32432432999990001
  value_dec2.bits[0] = 1076527857;
  value_dec2.bits[1] = 7551264;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 0;
  ck_assert_int_eq(s21_is_equal(value_dec2, value_dec), 0);
  ck_assert_int_eq(s21_is_equal(value_dec, value_dec2), 0);
}
END_TEST

START_TEST(equal12) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 0;
  // 0.79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 1900544;
  ck_assert_int_eq(s21_is_equal(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_equal(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(equal13) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 0.156456488772000012512
  value_dec.bits[0] = 2616449248;
  value_dec.bits[1] = 2068126616;
  value_dec.bits[2] = 8;
  value_dec.bits[3] = 1376256;
  // 45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 196608;
  ck_assert_int_eq(s21_is_equal(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_equal(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(equal14) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-0
  value_dec.bits[3] = 2147483648;
  // 0
  ck_assert_int_eq(s21_is_equal(value_dec2, value_dec), 1);
  ck_assert_int_eq(s21_is_equal(value_dec, value_dec2), 1);
}
END_TEST

START_TEST(not_equal1) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-0.156456488772
  value_dec.bits[0] = 1837666116;
  value_dec.bits[1] = 36;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 2148270080;
  //-45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 2147680256;
  ck_assert_int_eq(s21_is_not_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_not_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(not_equal2) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  //-79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 2147483648;
  ck_assert_int_eq(s21_is_not_equal(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_not_equal(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(not_equal3) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  // 0
  ck_assert_int_eq(s21_is_not_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_not_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(not_equal4) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  // 79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 0;
  ck_assert_int_eq(s21_is_not_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_not_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(not_equal5) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-3243243299999.0001
  value_dec.bits[0] = 1076527857;
  value_dec.bits[1] = 7551264;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 2147745792;
  //-32432432999990001
  value_dec2.bits[0] = 1076527857;
  value_dec2.bits[1] = 7551264;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 2147483648;
  ck_assert_int_eq(s21_is_not_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_not_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(not_equal6) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-0.156456488772000012512
  value_dec.bits[0] = 2616449248;
  value_dec.bits[1] = 2068126616;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 2148859904;
  //-45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 2147680256;
  ck_assert_int_eq(s21_is_not_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_not_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(not_equal7) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  //-0.79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 2149384192;
  ck_assert_int_eq(s21_is_not_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_not_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(not_equal8) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 0.156456488772
  value_dec.bits[0] = 1837666116;
  value_dec.bits[1] = 36;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 786432;
  // 45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 196608;
  ck_assert_int_eq(s21_is_not_equal(value_dec2, value_dec), 1);
  ck_assert_int_eq(s21_is_not_equal(value_dec, value_dec2), 1);
}
END_TEST

START_TEST(not_equal9) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 0;
  // 79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 0;
  ck_assert_int_eq(s21_is_not_equal(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_not_equal(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(not_equal10) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 0;
  // 0
  ck_assert_int_eq(s21_is_not_equal(value_dec2, value_dec), 1);
  ck_assert_int_eq(s21_is_not_equal(value_dec, value_dec2), 1);
}
END_TEST

START_TEST(not_equal11) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 3243243299999.0001
  value_dec.bits[0] = 1076527857;
  value_dec.bits[1] = 7551264;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 262144;
  // 32432432999990001
  value_dec2.bits[0] = 1076527857;
  value_dec2.bits[1] = 7551264;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 0;
  ck_assert_int_eq(s21_is_not_equal(value_dec2, value_dec), 1);
  ck_assert_int_eq(s21_is_not_equal(value_dec, value_dec2), 1);
}
END_TEST

START_TEST(not_equal12) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 0;
  // 0.79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 1900544;
  ck_assert_int_eq(s21_is_not_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_not_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(not_equal13) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 0.156456488772000012512
  value_dec.bits[0] = 2616449248;
  value_dec.bits[1] = 2068126616;
  value_dec.bits[2] = 8;
  value_dec.bits[3] = 1376256;
  // 45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 196608;
  ck_assert_int_eq(s21_is_not_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_not_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(not_equal14) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-0
  value_dec.bits[3] = 2147483648;
  // 0
  ck_assert_int_eq(s21_is_not_equal(value_dec2, value_dec), 0);
  ck_assert_int_eq(s21_is_not_equal(value_dec, value_dec2), 0);
}
END_TEST

START_TEST(greater_or_equal1) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-0.156456488772
  value_dec.bits[0] = 1837666116;
  value_dec.bits[1] = 36;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 2148270080;
  //-45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 2147680256;
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(greater_or_equal2) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  //-79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 2147483648;
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(greater_or_equal3) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  // 0
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(greater_or_equal4) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  // 79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 0;
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(greater_or_equal5) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-3243243299999.0001
  value_dec.bits[0] = 1076527857;
  value_dec.bits[1] = 7551264;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 2147745792;
  //-32432432999990001
  value_dec2.bits[0] = 1076527857;
  value_dec2.bits[1] = 7551264;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 2147483648;
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(greater_or_equal6) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-0.156456488772000012512
  value_dec.bits[0] = 2616449248;
  value_dec.bits[1] = 2068126616;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 2148859904;
  //-45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 2147680256;
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(greater_or_equal7) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  //-0.79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 2149384192;
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(greater_or_equal8) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 0.156456488772
  value_dec.bits[0] = 1837666116;
  value_dec.bits[1] = 36;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 786432;
  // 45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 196608;
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec2, value_dec), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec, value_dec2), 0);
}
END_TEST

START_TEST(greater_or_equal9) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 0;
  // 79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 0;
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(greater_or_equal10) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 0;
  // 0
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec2, value_dec), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec, value_dec2), 1);
}
END_TEST

START_TEST(greater_or_equal11) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 3243243299999.0001
  value_dec.bits[0] = 1076527857;
  value_dec.bits[1] = 7551264;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 262144;
  // 32432432999990001
  value_dec2.bits[0] = 1076527857;
  value_dec2.bits[1] = 7551264;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 0;
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec2, value_dec), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec, value_dec2), 0);
}
END_TEST

START_TEST(greater_or_equal12) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 0;
  //0.79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 1900544;
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(greater_or_equal13) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 0.156456488772000012512
  value_dec.bits[0] = 2616449248;
  value_dec.bits[1] = 2068126616;
  value_dec.bits[2] = 8;
  value_dec.bits[3] = 1376256;
  // 45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 196608;
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(greater_or_equal14) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-0
  value_dec.bits[3] = 2147483648;
  // 0
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec2, value_dec), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(value_dec, value_dec2), 1);
}
END_TEST

START_TEST(less1) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-0.156456488772
  value_dec.bits[0] = 1837666116;
  value_dec.bits[1] = 36;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 2148270080;
  //-45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 2147680256;
  ck_assert_int_eq(s21_is_less(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_less(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(less2) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  //-79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 2147483648;
  ck_assert_int_eq(s21_is_less(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_less(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(less3) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  // 0
  ck_assert_int_eq(s21_is_less(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_less(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(less4) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  // 79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 0;
  ck_assert_int_eq(s21_is_less(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_less(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(less5) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-3243243299999.0001
  value_dec.bits[0] = 1076527857;
  value_dec.bits[1] = 7551264;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 2147745792;
  //-32432432999990001
  value_dec2.bits[0] = 1076527857;
  value_dec2.bits[1] = 7551264;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 2147483648;
  ck_assert_int_eq(s21_is_less(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_less(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(less6) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-0.156456488772000012512
  value_dec.bits[0] = 2616449248;
  value_dec.bits[1] = 2068126616;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 2148859904;
  //-45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 2147680256;
  ck_assert_int_eq(s21_is_less(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_less(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(less7) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  //-0.79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 2149384192;
  ck_assert_int_eq(s21_is_less(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_less(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(less8) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 0.156456488772
  value_dec.bits[0] = 1837666116;
  value_dec.bits[1] = 36;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 786432;
  // 45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 196608;
  ck_assert_int_eq(s21_is_less(value_dec2, value_dec), 0);
  ck_assert_int_eq(s21_is_less(value_dec, value_dec2), 1);
}
END_TEST

START_TEST(less9) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 0;
  // 79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 0;
  ck_assert_int_eq(s21_is_less(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_less(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(less10) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 0;
  // 0
  ck_assert_int_eq(s21_is_less(value_dec2, value_dec), 1);
  ck_assert_int_eq(s21_is_less(value_dec, value_dec2), 0);
}
END_TEST

START_TEST(less11) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 3243243299999.0001
  value_dec.bits[0] = 1076527857;
  value_dec.bits[1] = 7551264;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 262144;
  // 32432432999990001
  value_dec2.bits[0] = 1076527857;
  value_dec2.bits[1] = 7551264;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 0;
  ck_assert_int_eq(s21_is_less(value_dec2, value_dec), 0);
  ck_assert_int_eq(s21_is_less(value_dec, value_dec2), 1);
}
END_TEST

START_TEST(less12) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 0;
  //0.79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 1900544;
  ck_assert_int_eq(s21_is_less(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_less(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(less13) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 0.156456488772000012512
  value_dec.bits[0] = 2616449248;
  value_dec.bits[1] = 2068126616;
  value_dec.bits[2] = 8;
  value_dec.bits[3] = 1376256;
  // 45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 196608;
  ck_assert_int_eq(s21_is_less(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_less(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(less14) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-0
  value_dec.bits[3] = 2147483648;
  // 0
  ck_assert_int_eq(s21_is_less(value_dec2, value_dec), 0);
  ck_assert_int_eq(s21_is_less(value_dec, value_dec2), 0);
}
END_TEST

START_TEST(less_or_equal1) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-0.156456488772
  value_dec.bits[0] = 1837666116;
  value_dec.bits[1] = 36;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 2148270080;
  //-45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 2147680256;
  ck_assert_int_eq(s21_is_less_or_equal(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(less_or_equal2) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  //-79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 2147483648;
  ck_assert_int_eq(s21_is_less_or_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(less_or_equal3) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  // 0
  ck_assert_int_eq(s21_is_less_or_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(less_or_equal4) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  // 79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 0;
  ck_assert_int_eq(s21_is_less_or_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(less_or_equal5) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-3243243299999.0001
  value_dec.bits[0] = 1076527857;
  value_dec.bits[1] = 7551264;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 2147745792;
  //-32432432999990001
  value_dec2.bits[0] = 1076527857;
  value_dec2.bits[1] = 7551264;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 2147483648;
  ck_assert_int_eq(s21_is_less_or_equal(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(less_or_equal6) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-0.156456488772000012512
  value_dec.bits[0] = 2616449248;
  value_dec.bits[1] = 2068126616;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 2148859904;
  //-45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 2147680256;
  ck_assert_int_eq(s21_is_less_or_equal(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(less_or_equal7) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 2147483648;
  //-0.79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 2149384192;
  ck_assert_int_eq(s21_is_less_or_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(less_or_equal8) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 0.156456488772
  value_dec.bits[0] = 1837666116;
  value_dec.bits[1] = 36;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 786432;
  // 45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 196608;
  ck_assert_int_eq(s21_is_less_or_equal(value_dec2, value_dec), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_dec, value_dec2), 1);
}
END_TEST

START_TEST(less_or_equal9) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 0;
  // 79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 0;
  ck_assert_int_eq(s21_is_less_or_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(less_or_equal10) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 0;
  // 0
  ck_assert_int_eq(s21_is_less_or_equal(value_dec2, value_dec), 1);
  ck_assert_int_eq(s21_is_less_or_equal(value_dec, value_dec2), 0);
}
END_TEST

START_TEST(less_or_equal11) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 3243243299999.0001
  value_dec.bits[0] = 1076527857;
  value_dec.bits[1] = 7551264;
  value_dec.bits[2] = 0;
  value_dec.bits[3] = 262144;
  // 32432432999990001
  value_dec2.bits[0] = 1076527857;
  value_dec2.bits[1] = 7551264;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 0;
  ck_assert_int_eq(s21_is_less_or_equal(value_dec2, value_dec), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_dec, value_dec2), 1);
}
END_TEST

START_TEST(less_or_equal12) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //79228162514264337593543950335
  value_dec.bits[0] = 4294967295;
  value_dec.bits[1] = 4294967295;
  value_dec.bits[2] = 4294967295;
  value_dec.bits[3] = 0;
  //0.79228162514264337593543950335
  value_dec2.bits[0] = 4294967295;
  value_dec2.bits[1] = 4294967295;
  value_dec2.bits[2] = 4294967295;
  value_dec2.bits[3] = 1900544;
  ck_assert_int_eq(s21_is_less_or_equal(value_dec, value_dec2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(value_dec2, value_dec), 1);
}
END_TEST

START_TEST(less_or_equal13) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  // 0.156456488772000012512
  value_dec.bits[0] = 2616449248;
  value_dec.bits[1] = 2068126616;
  value_dec.bits[2] = 8;
  value_dec.bits[3] = 1376256;
  // 45435435100001.321
  value_dec2.bits[0] = 2572801065;
  value_dec2.bits[1] = 10578761;
  value_dec2.bits[2] = 0;
  value_dec2.bits[3] = 196608;
  ck_assert_int_eq(s21_is_less_or_equal(value_dec, value_dec2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(value_dec2, value_dec), 0);
}
END_TEST

START_TEST(less_or_equal14) {
  s21_decimal value_dec, value_dec2;
  s21_init_dec(&value_dec);
  s21_init_dec(&value_dec2);
  //-0
  value_dec.bits[3] = 2147483648;
  // 0
  ck_assert_int_eq(s21_is_less_or_equal(value_dec2, value_dec), 1);
  ck_assert_int_eq(s21_is_less_or_equal(value_dec, value_dec2), 1);
}
END_TEST