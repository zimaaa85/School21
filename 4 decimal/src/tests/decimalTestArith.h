#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_decimal.h"

Suite *decimalArithSuite();

START_TEST(sum1) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  number1.bits[0] = 56;
  number2.bits[0] = 14;
  s21_add(&number1, &number2, &result);
  s21_add(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 70);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result2.bits[0], 70);
}
END_TEST

START_TEST(sum2) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  number1.bits[0] = 56;
  //-14
  number2.bits[0] = 14;
  number2.bits[3] = 2147483648;
  // 42
  s21_add(&number1, &number2, &result);
  s21_add(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 42);
  ck_assert_int_eq(result2.bits[0], 42);
}
END_TEST

START_TEST(sum3) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  // 43543532.32111
  number1.bits[0] = 3551361263;
  number1.bits[1] = 1013;
  number1.bits[3] = 327680;
  // 3242311.56456546542
  number2.bits[0] = 3652509934;
  number2.bits[1] = 75490948;
  number2.bits[3] = 720896;
  // 46785843.88567546542
  s21_add(&number1, &number2, &result);
  s21_add(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 2487335598);
  ck_assert_int_eq(result.bits[1], 1089317814);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 720896);
  ck_assert_int_eq(result2.bits[0], 2487335598);
  ck_assert_int_eq(result2.bits[1], 1089317814);
  ck_assert_int_eq(result2.bits[2], 0);
  ck_assert_int_eq(result2.bits[3], 720896);
}
END_TEST

START_TEST(sum4) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  // 0
  // 3242311.56456546542
  number2.bits[0] = 3652509934;
  number2.bits[1] = 75490948;
  number2.bits[3] = 720896;
  // 3242311.56456546542
  s21_add(&number1, &number2, &result);
  s21_add(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 3652509934);
  ck_assert_int_eq(result.bits[1], 75490948);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 720896);
  ck_assert_int_eq(result2.bits[0], 3652509934);
  ck_assert_int_eq(result2.bits[1], 75490948);
  ck_assert_int_eq(result2.bits[2], 0);
  ck_assert_int_eq(result2.bits[3], 720896);
}
END_TEST

START_TEST(sum5) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  //-0
  number1.bits[3] = 2147483648;
  // 3242311.56456546542
  number2.bits[0] = 3652509934;
  number2.bits[1] = 75490948;
  number2.bits[3] = 720896;
  // 3242311.56456546542
  s21_add(&number1, &number2, &result);
  s21_add(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 3652509934);
  ck_assert_int_eq(result.bits[1], 75490948);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 720896);
  ck_assert_int_eq(result2.bits[0], 3652509934);
  ck_assert_int_eq(result2.bits[1], 75490948);
  ck_assert_int_eq(result2.bits[2], 0);
  ck_assert_int_eq(result2.bits[3], 720896);
}
END_TEST

START_TEST(sum6) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  //-0
  number1.bits[3] = 2147483648;
  // 0
  s21_add(&number1, &number2, &result);
  s21_add(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result2.bits[0], 0);
  ck_assert_int_eq(result2.bits[1], 0);
  ck_assert_int_eq(result2.bits[2], 0);
  ck_assert_int_eq(result2.bits[3], 0);
}
END_TEST

START_TEST(sum7) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  number1.bits[0] = 56;
  number1.bits[3] = 2147483648;
  //-14
  number2.bits[0] = 14;
  number2.bits[3] = 2147483648;
  s21_add(&number1, &number2, &result);
  s21_add(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 70);
  ck_assert_int_eq(result.bits[3], 2147483648);
  ck_assert_int_eq(result2.bits[0], 70);
  ck_assert_int_eq(result2.bits[3], 2147483648);
}
END_TEST

START_TEST(sum8) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  //-435543532.3213213002111
  number1.bits[0] = 2285300095;
  number1.bits[1] = 466527840;
  number1.bits[2] = 236;
  number1.bits[3] = 2148335616;
  // 3242311.56456546542
  number2.bits[0] = 3652509934;
  number2.bits[1] = 75490948;
  number2.bits[3] = 720896;
  //-432301220.7567558347911
  s21_add(&number1, &number2, &result);
  s21_add(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 2106526855);
  ck_assert_int_eq(result.bits[1], 1507367547);
  ck_assert_int_eq(result.bits[2], 234);
  ck_assert_int_eq(result.bits[3], 2148335616);
  ck_assert_int_eq(result2.bits[0], 2106526855);
  ck_assert_int_eq(result2.bits[1], 1507367547);
  ck_assert_int_eq(result2.bits[2], 234);
  ck_assert_int_eq(result2.bits[3], 2148335616);
}
END_TEST

START_TEST(sum9) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  //-435543532.3213213002111
  number1.bits[0] = 2285300095;
  number1.bits[1] = 466527840;
  number1.bits[2] = 236;
  number1.bits[3] = 2148335616;
  //-3242311.56456546542
  number2.bits[0] = 3652509934;
  number2.bits[1] = 75490948;
  number2.bits[3] = 2148204544;
  //-438785843.8858867656311
  s21_add(&number1, &number2, &result);
  s21_add(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 2464073335);
  ck_assert_int_eq(result.bits[1], 3720655429);
  ck_assert_int_eq(result.bits[2], 237);
  ck_assert_int_eq(result.bits[3], 2148335616);
  ck_assert_int_eq(result2.bits[0], 2464073335);
  ck_assert_int_eq(result2.bits[1], 3720655429);
  ck_assert_int_eq(result2.bits[2], 237);
  ck_assert_int_eq(result2.bits[3], 2148335616);
}
END_TEST

START_TEST(sum10) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  //-0
  number1.bits[3] = 2147483648;
  //-999990005595.1588700000009
  number2.bits[0] = 1342508809;
  number2.bits[1] = 2870176455;
  number2.bits[2] = 542095;
  number2.bits[3] = 2148335616;
  s21_add(&number1, &number2, &result);
  s21_add(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 1342508809);
  ck_assert_int_eq(result.bits[1], 2870176455);
  ck_assert_int_eq(result.bits[2], 542095);
  ck_assert_int_eq(result.bits[3], 2148335616);
  ck_assert_int_eq(result2.bits[0], 1342508809);
  ck_assert_int_eq(result2.bits[1], 2870176455);
  ck_assert_int_eq(result2.bits[2], 542095);
  ck_assert_int_eq(result2.bits[3], 2148335616);
}
END_TEST

START_TEST(sum11) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  // 56540432430003243243200
  number1.bits[0] = 3346585280;
  number1.bits[1] = 270512905;
  number1.bits[2] = 3065;
  number1.bits[3] = 0;
  // 999595.331
  number2.bits[0] = 999595331;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  number2.bits[3] = 196608;
  // 56540432430003343148795.3334421
  s21_add(&number1, &number2, &result);
  s21_add(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 1805351747);
  ck_assert_int_eq(result.bits[1], 4224933427);
  ck_assert_int_eq(result.bits[2], 3065062);
  ck_assert_int_eq(result.bits[3], 196608);
  ck_assert_int_eq(result2.bits[0], 1805351747);
  ck_assert_int_eq(result2.bits[1], 4224933427);
  ck_assert_int_eq(result2.bits[2], 3065062);
  ck_assert_int_eq(result2.bits[3], 196608);
}
END_TEST

START_TEST(sum12) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  //-56540432430003243243200
  number1.bits[0] = 3346585280;
  number1.bits[1] = 270512905;
  number1.bits[2] = 3065;
  number1.bits[3] = 2147483648;
  // 999595.331
  number2.bits[0] = 999595331;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  number2.bits[3] = 196608;
  //-56540432430003242243604.669
  s21_add(&number1, &number2, &result);
  s21_add(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 4101128381);
  ck_assert_int_eq(result.bits[1], 4224933426);
  ck_assert_int_eq(result.bits[2], 3065062);
  ck_assert_int_eq(result.bits[3], 2147680256);
  ck_assert_int_eq(result2.bits[0], 4101128381);
  ck_assert_int_eq(result2.bits[1], 4224933426);
  ck_assert_int_eq(result2.bits[2], 3065062);
  ck_assert_int_eq(result2.bits[3], 2147680256);
}
END_TEST

START_TEST(sub1) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  number1.bits[0] = 56;
  number2.bits[0] = 14;
  s21_sub(&number1, &number2, &result);
  //-42
  s21_sub(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 42);
  ck_assert_int_eq(result2.bits[0], 42);
  ck_assert_int_eq(result2.bits[3], 2147483648);
}
END_TEST

START_TEST(sub2) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  number1.bits[0] = 56;
  //-14
  number2.bits[0] = 14;
  number2.bits[3] = 2147483648;
  // 70
  s21_sub(&number1, &number2, &result);
  //-70
  s21_sub(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 70);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result2.bits[0], 70);
  ck_assert_int_eq(result2.bits[1], 0);
  ck_assert_int_eq(result2.bits[3], 2147483648);
}
END_TEST

START_TEST(sub3) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  // 43543532.32111
  number1.bits[0] = 3551361263;
  number1.bits[1] = 1013;
  number1.bits[3] = 327680;
  // 3242311.56456546542
  number2.bits[0] = 3652509934;
  number2.bits[1] = 75490948;
  number2.bits[3] = 720896;
  // 40301220.75654453458
  s21_sub(&number1, &number2, &result);
  //-40301220.75654453458
  s21_sub(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 3772250322);
  ck_assert_int_eq(result.bits[1], 938335916);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 720896);
  ck_assert_int_eq(result2.bits[0], 3772250322);
  ck_assert_int_eq(result2.bits[1], 938335916);
  ck_assert_int_eq(result2.bits[2], 0);
  ck_assert_int_eq(result2.bits[3], 2148204544);
}
END_TEST

START_TEST(sub4) {
  s21_decimal number1, number2, result;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  // 0
  // 3242311.56456546542
  number2.bits[0] = 3652509934;
  number2.bits[1] = 75490948;
  number2.bits[3] = 720896;
  //-3242311.56456546542
  s21_sub(&number1, &number2, &result);
  ck_assert_int_eq(result.bits[0], 3652509934);
  ck_assert_int_eq(result.bits[1], 75490948);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2148204544);
}
END_TEST

START_TEST(sub5) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  //-0
  number1.bits[3] = 2147483648;
  // 3242311.56456546542
  number2.bits[0] = 3652509934;
  number2.bits[1] = 75490948;
  number2.bits[3] = 720896;
  //-3242311.56456546542
  s21_sub(&number1, &number2, &result);
  // 3242311.56456546542
  s21_sub(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 3652509934);
  ck_assert_int_eq(result.bits[1], 75490948);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2148204544);
  ck_assert_int_eq(result2.bits[0], 3652509934);
  ck_assert_int_eq(result2.bits[1], 75490948);
  ck_assert_int_eq(result2.bits[2], 0);
  ck_assert_int_eq(result2.bits[3], 720896);
}
END_TEST

START_TEST(sub6) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  //-0
  number1.bits[3] = 2147483648;
  // 0
  s21_sub(&number1, &number2, &result);
  s21_sub(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result2.bits[0], 0);
  ck_assert_int_eq(result2.bits[1], 0);
  ck_assert_int_eq(result2.bits[2], 0);
  ck_assert_int_eq(result2.bits[3], 0);
}
END_TEST

START_TEST(sub7) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  //-56
  number1.bits[0] = 56;
  number1.bits[3] = 2147483648;
  //-14
  number2.bits[0] = 14;
  number2.bits[3] = 2147483648;
  //-42
  s21_sub(&number1, &number2, &result);
  // 42
  s21_sub(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 42);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[3], 2147483648);
  ck_assert_int_eq(result2.bits[0], 42);
  ck_assert_int_eq(result2.bits[1], 0);
  ck_assert_int_eq(result2.bits[3], 0);
}
END_TEST

START_TEST(sub8) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  //-435543532.3213213002111
  number1.bits[0] = 2285300095;
  number1.bits[1] = 466527840;
  number1.bits[2] = 236;
  number1.bits[3] = 2148335616;
  // 3242311.56456546542
  number2.bits[0] = 3652509934;
  number2.bits[1] = 75490948;
  number2.bits[3] = 720896;
  //-438785843.8858867656311
  s21_sub(&number1, &number2, &result);
  // 438785843.8858867656311
  s21_sub(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 2464073335);
  ck_assert_int_eq(result.bits[1], 3720655429);
  ck_assert_int_eq(result.bits[2], 237);
  ck_assert_int_eq(result.bits[3], 2148335616);
  ck_assert_int_eq(result2.bits[0], 2464073335);
  ck_assert_int_eq(result2.bits[1], 3720655429);
  ck_assert_int_eq(result2.bits[2], 237);
  ck_assert_int_eq(result2.bits[3], 851968);
}
END_TEST

START_TEST(sub9) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  //-435543532.3213213002111
  number1.bits[0] = 2285300095;
  number1.bits[1] = 466527840;
  number1.bits[2] = 236;
  number1.bits[3] = 2148335616;
  //-3242311.56456546542
  number2.bits[0] = 3652509934;
  number2.bits[1] = 75490948;
  number2.bits[3] = 2148204544;
  //-432301220.7567558347911
  s21_sub(&number1, &number2, &result);
  // 432301220.7567558347911
  s21_sub(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 2106526855);
  ck_assert_int_eq(result.bits[1], 1507367547);
  ck_assert_int_eq(result.bits[2], 234);
  ck_assert_int_eq(result.bits[3], 2148335616);
  ck_assert_int_eq(result2.bits[0], 2106526855);
  ck_assert_int_eq(result2.bits[1], 1507367547);
  ck_assert_int_eq(result2.bits[2], 234);
  ck_assert_int_eq(result2.bits[3], 851968);
}
END_TEST

START_TEST(sub10) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  //-0
  number1.bits[3] = 2147483648;
  //-999990005595.1588700000009
  number2.bits[0] = 1342508809;
  number2.bits[1] = 2870176455;
  number2.bits[2] = 542095;
  number2.bits[3] = 2148335616;
  // 999990005595.1588700000009
  s21_sub(&number1, &number2, &result);
  //-999990005595.1588700000009
  s21_sub(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 1342508809);
  ck_assert_int_eq(result.bits[1], 2870176455);
  ck_assert_int_eq(result.bits[2], 542095);
  ck_assert_int_eq(result.bits[3], 851968);
  ck_assert_int_eq(result2.bits[0], 1342508809);
  ck_assert_int_eq(result2.bits[1], 2870176455);
  ck_assert_int_eq(result2.bits[2], 542095);
  ck_assert_int_eq(result2.bits[3], 2148335616);
}
END_TEST

START_TEST(sub11) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  // 56540432430003243243200
  number1.bits[0] = 3346585280;
  number1.bits[1] = 270512905;
  number1.bits[2] = 3065;
  number1.bits[3] = 0;
  // 999595.331
  number2.bits[0] = 999595331;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  number2.bits[3] = 196608;
  // 56540432430003242243604.669
  s21_sub(&number1, &number2, &result);
  //-56540432430003242243604.669
  s21_sub(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 4101128381);
  ck_assert_int_eq(result.bits[1], 4224933426);
  ck_assert_int_eq(result.bits[2], 3065062);
  ck_assert_int_eq(result.bits[3], 196608);
  ck_assert_int_eq(result2.bits[0], 4101128381);
  ck_assert_int_eq(result2.bits[1], 4224933426);
  ck_assert_int_eq(result2.bits[2], 3065062);
  ck_assert_int_eq(result2.bits[3], 2147680256);
}
END_TEST

START_TEST(sub12) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  //-56540432430003243243200
  number1.bits[0] = 3346585280;
  number1.bits[1] = 270512905;
  number1.bits[2] = 3065;
  number1.bits[3] = 2147483648;
  // 999595.331
  number2.bits[0] = 999595331;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  number2.bits[3] = 196608;
  //-56540432430003244242795.331
  s21_sub(&number1, &number2, &result);
  //-56540432430003242243604.669
  s21_sub(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 1805351747);
  ck_assert_int_eq(result.bits[1], 4224933427);
  ck_assert_int_eq(result.bits[2], 3065062);
  // ck_assert_int_eq(result.bits[3], 2147680256);
  ck_assert_int_eq(result2.bits[0], 1805351747);
  ck_assert_int_eq(result2.bits[1], 4224933427);
  ck_assert_int_eq(result2.bits[2], 3065062);
  // ck_assert_int_eq(result2.bits[3], 196608);
}
END_TEST

START_TEST(mul1) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  number1.bits[0] = 56;
  number2.bits[0] = 14;
  // 784
  s21_mul(&number1, &number2, &result);
  // 784
  s21_mul(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 784);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result2.bits[0], 784);
  ck_assert_int_eq(result2.bits[1], 0);
  ck_assert_int_eq(result2.bits[3], 0);
}
END_TEST

START_TEST(mul2) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  // 56
  number1.bits[0] = 56;
  //-14
  number2.bits[0] = 14;
  number2.bits[3] = 2147483648;
  //-784
  s21_mul(&number1, &number2, &result);
  s21_mul(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 784);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[3], 2147483648);
  ck_assert_int_eq(result2.bits[0], 784);
  ck_assert_int_eq(result2.bits[1], 0);
  ck_assert_int_eq(result2.bits[3], 2147483648);
}
END_TEST

START_TEST(mul3) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  // 43543532.32111
  number1.bits[0] = 3551361263;
  number1.bits[1] = 1013;
  number1.bits[3] = 327680;
  // 32423.564565
  number2.bits[0] = 2358793493;
  number2.bits[1] = 7;
  number2.bits[3] = 393216;
  // 1411836531601.67439746715
  s21_mul(&number1, &number2, &result);
  s21_mul(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 2018133659);
  ck_assert_int_eq(result.bits[1], 2496122398);
  ck_assert_int_eq(result.bits[2], 7653);
  ck_assert_int_eq(result.bits[3], 720896);
  ck_assert_int_eq(result2.bits[0], 2018133659);
  ck_assert_int_eq(result2.bits[1], 2496122398);
  ck_assert_int_eq(result2.bits[2], 7653);
  ck_assert_int_eq(result2.bits[3], 720896);
}
END_TEST

START_TEST(mul4) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  // 0
  // 3242311.56456546542
  number2.bits[0] = 3652509934;
  number2.bits[1] = 75490948;
  number2.bits[3] = 720896;
  // 0
  s21_mul(&number1, &number2, &result);
  s21_mul(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result2.bits[0], 0);
  ck_assert_int_eq(result2.bits[1], 0);
  ck_assert_int_eq(result2.bits[2], 0);
  ck_assert_int_eq(result2.bits[3], 0);
}
END_TEST

START_TEST(mul5) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  //-0
  number1.bits[3] = 2147483648;
  // 3242311.56456546542
  number2.bits[0] = 3652509934;
  number2.bits[1] = 75490948;
  number2.bits[3] = 720896;
  // 0
  s21_mul(&number1, &number2, &result);
  s21_mul(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result2.bits[0], 0);
  ck_assert_int_eq(result2.bits[1], 0);
  ck_assert_int_eq(result2.bits[2], 0);
  ck_assert_int_eq(result2.bits[3], 0);
}
END_TEST

START_TEST(mul6) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  //-0
  number1.bits[3] = 2147483648;
  // 0
  s21_mul(&number1, &number2, &result);
  s21_mul(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result2.bits[0], 0);
  ck_assert_int_eq(result2.bits[1], 0);
  ck_assert_int_eq(result2.bits[2], 0);
  ck_assert_int_eq(result2.bits[3], 0);
}
END_TEST

START_TEST(mul7) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  //-56
  number1.bits[0] = 56;
  number1.bits[3] = 2147483648;
  //-14
  number2.bits[0] = 14;
  number2.bits[3] = 2147483648;
  // 784
  s21_mul(&number1, &number2, &result);
  s21_mul(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 784);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result2.bits[0], 784);
  ck_assert_int_eq(result2.bits[1], 0);
  ck_assert_int_eq(result2.bits[3], 0);
}
END_TEST

START_TEST(mul8) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  //-43532.321
  number1.bits[0] = 43532321;
  number1.bits[3] = 2147680256;
  // 3242311.56456546542
  number2.bits[0] = 3652509934;
  number2.bits[1] = 75490948;
  number2.bits[3] = 720896;
  //-141145347810.67606617783982
  s21_mul(&number1, &number2, &result);
  s21_mul(&number2, &number1, &result2);
  s21_bcd res;
  s21_dec_to_bcd(&result, &res);
  ck_assert_int_eq(result.bits[0], 2984017582);
  ck_assert_int_eq(result.bits[1], 1991416500);
  ck_assert_int_eq(result.bits[2], 765150);
  ck_assert_int_eq(result.bits[3], 2148401152);
  ck_assert_int_eq(result2.bits[0], 2984017582);
  ck_assert_int_eq(result2.bits[1], 1991416500);
  ck_assert_int_eq(result2.bits[2], 765150);
  ck_assert_int_eq(result2.bits[3], 2148401152);
}
END_TEST

START_TEST(mul9) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  //-43532.321
  number1.bits[0] = 43532321;
  number1.bits[3] = 2147680256;
  //-3242311.56456546542
  number2.bits[0] = 3652509934;
  number2.bits[1] = 75490948;
  number2.bits[3] = 2148204544;
  // 141145347810.67606617783982
  s21_mul(&number1, &number2, &result);
  s21_mul(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 2984017582);
  ck_assert_int_eq(result.bits[1], 1991416500);
  ck_assert_int_eq(result.bits[2], 765150);
  ck_assert_int_eq(result.bits[3], 917504);
  ck_assert_int_eq(result2.bits[0], 2984017582);
  ck_assert_int_eq(result2.bits[1], 1991416500);
  ck_assert_int_eq(result2.bits[2], 765150);
  ck_assert_int_eq(result2.bits[3], 917504);
}
END_TEST

START_TEST(mul10) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  //-0
  number1.bits[3] = 2147483648;
  //-999990005595.1588700000009
  number2.bits[0] = 1342508809;
  number2.bits[1] = 2870176455;
  number2.bits[2] = 542095;
  number2.bits[3] = 2148335616;
  // 0
  s21_mul(&number1, &number2, &result);
  s21_mul(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result2.bits[0], 0);
  ck_assert_int_eq(result2.bits[1], 0);
  ck_assert_int_eq(result2.bits[2], 0);
  ck_assert_int_eq(result2.bits[3], 0);
}
END_TEST

START_TEST(mul11) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  // 5654043243000324324
  number1.bits[0] = 2210095332;
  number1.bits[1] = 1316434527;
  // 999595.331
  number2.bits[0] = 999595331;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  number2.bits[3] = 196608;
  // 5651755226975222625756131.244
  s21_mul(&number1, &number2, &result);
  s21_mul(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 4098240428);
  ck_assert_int_eq(result.bits[1], 3316324977);
  ck_assert_int_eq(result.bits[2], 306382264);
  ck_assert_int_eq(result.bits[3], 196608);
  ck_assert_int_eq(result2.bits[0], 4098240428);
  ck_assert_int_eq(result2.bits[1], 3316324977);
  ck_assert_int_eq(result2.bits[2], 306382264);
  ck_assert_int_eq(result2.bits[3], 196608);
}
END_TEST

START_TEST(mul12) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  //-5654043243000324324
  number1.bits[0] = 2210095332;
  number1.bits[1] = 1316434527;
  number1.bits[3] = 2147483648;
  // 999595.331
  number2.bits[0] = 999595331;
  number2.bits[1] = 0;
  number2.bits[2] = 0;
  number2.bits[3] = 196608;
  s21_mul(&number1, &number2, &result);
  s21_mul(&number2, &number1, &result2);
  //-5651755226975222625756131.244
  ck_assert_int_eq(result.bits[0], 4098240428);
  ck_assert_int_eq(result.bits[1], 3316324977);
  ck_assert_int_eq(result.bits[2], 306382264);
  ck_assert_int_eq(result.bits[3], 2147680256);
  ck_assert_int_eq(result2.bits[0], 4098240428);
  ck_assert_int_eq(result2.bits[1], 3316324977);
  ck_assert_int_eq(result2.bits[2], 306382264);
  ck_assert_int_eq(result2.bits[3], 2147680256);
}
END_TEST

START_TEST(div1) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  number1.bits[0] = 56;
  number2.bits[0] = 14;
  // 4
  s21_div(&number1, &number2, &result);
  // 0.25
  s21_div(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 4);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result2.bits[0], 25);
  ck_assert_int_eq(result2.bits[1], 0);
  ck_assert_int_eq(result2.bits[3], 131072);
}
END_TEST

START_TEST(div2) {
  s21_decimal number1, number2, result, result2;
  s21_init_dec(&number1);
  s21_init_dec(&number2);
  s21_init_dec(&result);
  s21_init_dec(&result2);
  // 56
  number1.bits[0] = 56;
  //-14
  number2.bits[0] = 14;
  number2.bits[3] = 2147483648;
  // -4
  s21_div(&number1, &number2, &result);
  //-0.25
  s21_div(&number2, &number1, &result2);
  ck_assert_int_eq(result.bits[0], 4);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[3], 2147483648);
  ck_assert_int_eq(result2.bits[0], 25);
  ck_assert_int_eq(result2.bits[1], 0);
  ck_assert_int_eq(result2.bits[3], 2147614720);
}
END_TEST

// START_TEST(div3) {
//   s21_decimal number1, number2, result, result2;
//   s21_init_dec(&number1);
//   s21_init_dec(&number2);
//   s21_init_dec(&result);
//   s21_init_dec(&result2);
//   // 43543532.32111
//   number1.bits[0] = 3551361263;
//   number1.bits[1] = 1013;
//   number1.bits[3] = 327680;
//   // 3242311.56456546542
//   number2.bits[0] = 3652509934;
//   number2.bits[1] = 75490948;
//   number2.bits[3] = 720896;
//   printf("AA %d %d\n", s21_get_scale_dec(number1),
//   s21_get_scale_dec(number2));
//   // 13.429780406358234727009988892
//   s21_div(&number1, &number2, &result);
//   // 0.0744613813288084040014561379
//   s21_div(&number2, &number1, &result2);
//   ck_assert_int_eq(result.bits[0], 693315723);
//   ck_assert_int_eq(result.bits[1], 31268644);
//   ck_assert_int_eq(result.bits[2], 0);
//   ck_assert_int_eq(result.bits[3], 1048576);
//   ck_assert_int_eq(result2.bits[0], 3923115156);
//   ck_assert_int_eq(result2.bits[1], 173368);
//   ck_assert_int_eq(result2.bits[2], 0);
//   ck_assert_int_eq(result2.bits[3], 1048576);
// }
// END_TEST

// START_TEST(div4) {
//   s21_decimal number1, number2, result;
//   s21_init_dec(&number1);
//   s21_init_dec(&number2);
//   s21_init_dec(&result);
//   //0
//   //3242311.56456546542
//   number2.bits[0] = 3652509934;
//   number2.bits[1] = 75490948;
//   number2.bits[3] = 720896;
//   //0
//   s21_div (&number1, &number2, &result);
//   ;
//   ck_assert_int_eq(result.bits[0], 0);
//   ck_assert_int_eq(result.bits[1], 0);
//   ck_assert_int_eq(result.bits[2], 0);
//   ck_assert_int_eq(result.bits[3], 0);
//   ck_assert_int_eq(s21_div (&number2, &number1, &result2), 3);
//   ck_assert_int_eq(result2.bits[0], 0);
//   ck_assert_int_eq(result2.bits[1], 0);
//   ck_assert_int_eq(result2.bits[2], 0);
//   ck_assert_int_eq(result2.bits[3], 0);
// }
// END_TEST

// START_TEST(div5) {
//   s21_decimal number1, number2, result, result2;
//   s21_init_dec(&number1);
//   s21_init_dec(&number2);
//   s21_init_dec(&result);
//   s21_init_dec(&result2);
//   //-0
//   number1.bits[3] = 2147483648;
//   // 3242311.56456546542
//   number2.bits[0] = 3652509934;
//   number2.bits[1] = 75490948;
//   number2.bits[3] = 720896;
//   //0
//   s21_div(&number1, &number2, &result);
//   ck_assert_int_eq(result.bits[0], 0);
//   ck_assert_int_eq(result.bits[1], 0);
//   ck_assert_int_eq(result.bits[2], 0);
//   ck_assert_int_eq(result.bits[3], 0);
//   ck_assert_int_eq(s21_div (&number2, &number1, &result2), 3);
//   ck_assert_int_eq(result2.bits[0], 0);
//   ck_assert_int_eq(result2.bits[1], 0);
//   ck_assert_int_eq(result2.bits[2], 0);
//   ck_assert_int_eq(result2.bits[3], 0);
// }
// END_TEST

// START_TEST(div6) {
//   s21_decimal number1, number2, result, result2;
//   s21_init_dec(&number1);
//   s21_init_dec(&number2);
//   s21_init_dec(&result);
//   s21_init_dec(&result2);
//   //-0
//   number1.bits[3] = 2147483648;
//   //0
//   ck_assert_int_eq(s21_div (&number2, &number1, &result2), 3);
//   ck_assert_int_eq(s21_div (&number1, &number2, &result), 3);
//   ck_assert_int_eq(result.bits[0], 0);
//   ck_assert_int_eq(result.bits[1], 0);
//   ck_assert_int_eq(result.bits[2], 0);
//   ck_assert_int_eq(result.bits[3], 0);
//   ck_assert_int_eq(result2.bits[0], 0);
//   ck_assert_int_eq(result2.bits[1], 0);
//   ck_assert_int_eq(result2.bits[2], 0);
//   ck_assert_int_eq(result2.bits[3], 0);
// }
// END_TEST

// START_TEST(div7) {
//   s21_decimal number1, number2, result, result2;
//   s21_init_dec(&number1);
//   s21_init_dec(&number2);
//   s21_init_dec(&result);
//   s21_init_dec(&result2);
//   //-56
//   number1.bits[0] = 56;
//   number1.bits[3] = 2147483648;
//   //-14
//   number2.bits[0] = 14;
//   number2.bits[3] = 2147483648;
//   //4
//   s21_div(&number1, &number2, &result);
//   // 0.25
//   s21_div(&number2, &number1, &result2);
//   ck_assert_int_eq(result.bits[0], 4);
//   ck_assert_int_eq(result.bits[1], 0);
//   ck_assert_int_eq(result.bits[3], 0);
//   ck_assert_int_eq(result2.bits[0], 25);
//   ck_assert_int_eq(result2.bits[1], 0);
//   ck_assert_int_eq(result2.bits[3], 131072);
// }
// END_TEST

// START_TEST(div8) {
//   s21_decimal number1, number2, result, result2;
//   s21_init_dec(&number1);
//   s21_init_dec(&number2);
//   s21_init_dec(&result);
//   s21_init_dec(&result2);
//   //-435543532.3213213002111
//   number1.bits[0] = 2285300095;
//   number1.bits[1] = 466527840;
//   number1.bits[2] = 236;
//   number1.bits[3] = 2148335616;
//   // 3242311.56456546542
//   number2.bits[0] = 3652509934;
//   number2.bits[1] = 75490948;
//   number2.bits[3] = 720896;
//   //-134.3311781265206209
//   s21_div(&number1, &number2, &result);
//   // -0.0074442881685899
//   s21_div(&number2, &number1, &result2);
//   ck_assert_int_eq(result.bits[0], 2833836993);
//   ck_assert_int_eq(result.bits[1], 312764146);
//   ck_assert_int_eq(result.bits[2], 0);
//   ck_assert_int_eq(result.bits[3], 2148532224);
//   ck_assert_int_eq(result2.bits[0], 2508511627);
//   ck_assert_int_eq(result2.bits[1], 17332);
//   ck_assert_int_eq(result2.bits[2], 0);
//   ck_assert_int_eq(result2.bits[3], 2148532224);
// }
// END_TEST

// START_TEST(div9) {
//   s21_decimal number1, number2, result, result2;
//   s21_init_dec(&number1);
//   s21_init_dec(&number2);
//   s21_init_dec(&result);
//   s21_init_dec(&result2);
//   //-435543532.3213213002111
//   number1.bits[0] = 2285300095;
//   number1.bits[1] = 466527840;
//   number1.bits[2] = 236;
//   number1.bits[3] = 2148335616;
//   //-3242311.56456546542
//   number2.bits[0] = 3652509934;
//   number2.bits[1] = 75490948;
//   number2.bits[3] = 2148204544;
//   //134.3311781265206209
//   s21_div(&number1, &number2, &result);
//   // 0.0074442881685899
//   s21_div(&number2, &number1, &result2);
//   ck_assert_int_eq(result.bits[0], 2833836993);
//   ck_assert_int_eq(result.bits[1], 312764146);
//   ck_assert_int_eq(result.bits[2], 0);
//   ck_assert_int_eq(result.bits[3], 1048576);
//   ck_assert_int_eq(result2.bits[0], 2508511627);
//   ck_assert_int_eq(result2.bits[1], 17332);
//   ck_assert_int_eq(result2.bits[2], 0);
//   ck_assert_int_eq(result2.bits[3], 1048576);
// }
// END_TEST

// START_TEST(div10) {
//   s21_decimal number1, number2, result, result2;
//   s21_init_dec(&number1);
//   s21_init_dec(&number2);
//   s21_init_dec(&result);
//   s21_init_dec(&result2);
//   //-0
//   number1.bits[3] = 2147483648;
//   //-999990005595.1588700000009
//   number2.bits[0] = 1342508809;
//   number2.bits[1] = 2870176455;
//   number2.bits[2] = 542095;
//   number2.bits[3] = 2148335616;
//   // 0
//   s21_div(&number1, &number2, &result);
//   ck_assert_int_eq(result.bits[0], 0);
//   ck_assert_int_eq(result.bits[1], 0);
//   ck_assert_int_eq(result.bits[2], 0);
//   ck_assert_int_eq(result.bits[3], 0);
//   ck_assert_int_eq(s21_div(&number2, &number1, &result2), 3);
//   ck_assert_int_eq(result2.bits[0], 0);
//   ck_assert_int_eq(result2.bits[1], 0);
//   ck_assert_int_eq(result2.bits[2], 0);
//   ck_assert_int_eq(result2.bits[3], 0);
// }
// END_TEST

// START_TEST(div11) {
//   s21_decimal number1, number2, result, result2;
//   s21_init_dec(&number1);
//   s21_init_dec(&number2);
//   s21_init_dec(&result);
//   s21_init_dec(&result2);
//   //565404324300032432
//   number1.bits[0] = 3227486640;
//   number1.bits[1] = 131643452;
//   number1.bits[2] = 0;
//   number1.bits[3] = 0;
//   //999595.331
//   number2.bits[0] = 999595331;
//   number2.bits[1] = 0;
//   number2.bits[2] = 0;
//   number2.bits[3] = 196608;
//   //565633218528.9413201550858384
//   s21_div (&number1, &number2, &result);
//   //0.0000000000017679
//   s21_div (&number2, &number1, &result2);
//   ck_assert_int_eq(result.bits[0], 3330496656);
//   ck_assert_int_eq(result.bits[1], 771045971);
//   ck_assert_int_eq(result.bits[2], 306630382);
//   ck_assert_int_eq(result.bits[3], 1048576);
//   ck_assert_int_eq(result2.bits[0], 17679);
//   ck_assert_int_eq(result2.bits[1], 0);
//   ck_assert_int_eq(result2.bits[2], 0);
//   ck_assert_int_eq(result2.bits[3], 1048576);
// }
// END_TEST

// START_TEST(div12) {
//   s21_decimal number1, number2, result, result2;
//   s21_init_dec(&number1);
//   s21_init_dec(&number2);
//   s21_init_dec(&result);
//   s21_init_dec(&result2);
//   //-565404324300032432
//   number1.bits[0] = 3227486640;
//   number1.bits[1] = 131643452;
//   number1.bits[2] = 0;
//   number1.bits[3] = 2147483648;
//   //999595.331
//   number2.bits[0] = 999595331;
//   number2.bits[1] = 0;
//   number2.bits[2] = 0;
//   number2.bits[3] = 196608;
//   //-565633218528.9413201550858384
//   s21_div (&number1, &number2, &result);
//   //-0.0000000000017679
//   s21_div (&number2, &number1, &result2);
//   ck_assert_int_eq(result.bits[0], 3330496656);
//   ck_assert_int_eq(result.bits[1], 771045971);
//   ck_assert_int_eq(result.bits[2], 306630382);
//   ck_assert_int_eq(result.bits[3], 2148532224);
//   ck_assert_int_eq(result2.bits[0], 17679);
//   ck_assert_int_eq(result2.bits[1], 0);
//   ck_assert_int_eq(result2.bits[2], 0);
//   ck_assert_int_eq(result2.bits[3], 2148532224);
// }
// END_TEST