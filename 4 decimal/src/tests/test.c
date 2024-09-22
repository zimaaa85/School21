#include "decimalTests.h"
// удалить
#include "decimalTestArith.h"
#include "decimalTestPrint.h"
#include "decimalTestsubfunc.h"

// тесты для конверта
#include "from_decimal_to_float.h"
#include "from_decimal_to_int.h"
#include "from_float_to_decimal.h"
#include "from_int_to_decimal.h"

// тесты на сравнение чисел 111112 111113
// тесты на вычисления с переполнением

int main() {
  int failed = 0;

  Suite *s = decimalSuite();

  // удалить
  Suite *s1 = decimalPrintSuite();

  Suite *s2 = decimalSuitesubfunc();
  Suite *s3 = decimalArithSuite();

  Suite *s4 = from_decimal_to_floatSuite();
  Suite *s5 = from_decimal_to_intSuite();
  Suite *s6 = from_float_to_decimalSuite();
  Suite *s7 = from_int_to_decimalSuite();

  SRunner *sr = srunner_create(s);

  // удалить
  srunner_add_suite(sr, s1);
  srunner_add_suite(sr, s2);
  srunner_add_suite(sr, s3);
  srunner_add_suite(sr, s4);
  srunner_add_suite(sr, s5);
  srunner_add_suite(sr, s6);
  srunner_add_suite(sr, s7);

  srunner_run_all(sr, CK_NORMAL);
  failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

Suite *decimalSuite() {
  Suite *s = NULL;
  TCase *tDecimal = NULL;
  s = suite_create("decimalBase");
  tDecimal = tcase_create("decCase");
  tcase_add_test(tDecimal, get_bit_dec);
  tcase_add_test(tDecimal, set_bit_dec);
  tcase_add_test(tDecimal, get_sign_dec);
  tcase_add_test(tDecimal, get_sign_dec2);
  tcase_add_test(tDecimal, set_bit_dec2);
  tcase_add_test(tDecimal, set_bit_dec3);
  tcase_add_test(tDecimal, set_sign_dec);
  tcase_add_test(tDecimal, set_sign_dec2);
  tcase_add_test(tDecimal, get_scale_dec);
  tcase_add_test(tDecimal, init_bcd);
  tcase_add_test(tDecimal, set_scale_dec);
  tcase_add_test(tDecimal, set_scale_dec2);
  tcase_add_test(tDecimal, set_scale_dec3);
  tcase_add_test(tDecimal, left_shift_int);
  tcase_add_test(tDecimal, left_shift_int2);
  tcase_add_test(tDecimal, left_shift_int3);
  tcase_add_test(tDecimal, left_shift_int4);
  tcase_add_test(tDecimal, left_shift_int5);
  tcase_add_test(tDecimal, right_shift_int);
  tcase_add_test(tDecimal, right_shift_int2);
  tcase_add_test(tDecimal, right_shift_int3);
  tcase_add_test(tDecimal, right_shift_int4);
  tcase_add_test(tDecimal, copy_dec);
  tcase_add_test(tDecimal, left_shift_dec);
  tcase_add_test(tDecimal, right_shift_dec);
  tcase_add_test(tDecimal, logic_test);
  tcase_add_test(tDecimal, convert_dec_to_bcd);
  tcase_add_test(tDecimal, convert_dec_to_bcd_to_dec);
  tcase_add_test(tDecimal, convert_dec_to_bcd_to_dec2);
  tcase_add_test(tDecimal, convert_dec_to_bcd_to_dec3);
  tcase_add_test(tDecimal, convert_dec_to_bcd_to_dec4);
  tcase_add_test(tDecimal, convert_dec_to_bcd_to_dec5);
  tcase_add_test(tDecimal, convert_dec_to_bcd_to_dec6);
  tcase_add_test(tDecimal, greater1);
  tcase_add_test(tDecimal, greater2);
  tcase_add_test(tDecimal, greater3);
  tcase_add_test(tDecimal, greater4);
  tcase_add_test(tDecimal, greater5);
  tcase_add_test(tDecimal, greater6);
  tcase_add_test(tDecimal, greater7);
  tcase_add_test(tDecimal, greater8);
  tcase_add_test(tDecimal, greater9);
  tcase_add_test(tDecimal, greater10);
  tcase_add_test(tDecimal, greater11);
  tcase_add_test(tDecimal, greater12);
  tcase_add_test(tDecimal, greater13);
  tcase_add_test(tDecimal, greater14);
  tcase_add_test(tDecimal, equal1);
  tcase_add_test(tDecimal, equal2);
  tcase_add_test(tDecimal, equal3);
  tcase_add_test(tDecimal, equal4);
  tcase_add_test(tDecimal, equal5);
  tcase_add_test(tDecimal, equal6);
  tcase_add_test(tDecimal, equal7);
  tcase_add_test(tDecimal, equal8);
  tcase_add_test(tDecimal, equal9);
  tcase_add_test(tDecimal, equal10);
  tcase_add_test(tDecimal, equal11);
  tcase_add_test(tDecimal, equal12);
  tcase_add_test(tDecimal, equal13);
  tcase_add_test(tDecimal, equal14);
  tcase_add_test(tDecimal, not_equal1);
  tcase_add_test(tDecimal, not_equal2);
  tcase_add_test(tDecimal, not_equal3);
  tcase_add_test(tDecimal, not_equal4);
  tcase_add_test(tDecimal, not_equal5);
  tcase_add_test(tDecimal, not_equal6);
  tcase_add_test(tDecimal, not_equal7);
  tcase_add_test(tDecimal, not_equal8);
  tcase_add_test(tDecimal, not_equal9);
  tcase_add_test(tDecimal, not_equal10);
  tcase_add_test(tDecimal, not_equal11);
  tcase_add_test(tDecimal, not_equal12);
  tcase_add_test(tDecimal, not_equal13);
  tcase_add_test(tDecimal, not_equal14);
  tcase_add_test(tDecimal, greater_or_equal1);
  tcase_add_test(tDecimal, greater_or_equal2);
  tcase_add_test(tDecimal, greater_or_equal3);
  tcase_add_test(tDecimal, greater_or_equal4);
  tcase_add_test(tDecimal, greater_or_equal5);
  tcase_add_test(tDecimal, greater_or_equal6);
  tcase_add_test(tDecimal, greater_or_equal7);
  tcase_add_test(tDecimal, greater_or_equal8);
  tcase_add_test(tDecimal, greater_or_equal9);
  tcase_add_test(tDecimal, greater_or_equal10);
  tcase_add_test(tDecimal, greater_or_equal11);
  tcase_add_test(tDecimal, greater_or_equal12);
  tcase_add_test(tDecimal, greater_or_equal13);
  tcase_add_test(tDecimal, greater_or_equal14);
  tcase_add_test(tDecimal, less1);
  tcase_add_test(tDecimal, less2);
  tcase_add_test(tDecimal, less3);
  tcase_add_test(tDecimal, less4);
  tcase_add_test(tDecimal, less5);
  tcase_add_test(tDecimal, less6);
  tcase_add_test(tDecimal, less7);
  tcase_add_test(tDecimal, less8);
  tcase_add_test(tDecimal, less9);
  tcase_add_test(tDecimal, less10);
  tcase_add_test(tDecimal, less11);
  tcase_add_test(tDecimal, less12);
  tcase_add_test(tDecimal, less13);
  tcase_add_test(tDecimal, less14);
  tcase_add_test(tDecimal, less_or_equal1);
  tcase_add_test(tDecimal, less_or_equal2);
  tcase_add_test(tDecimal, less_or_equal3);
  tcase_add_test(tDecimal, less_or_equal4);
  tcase_add_test(tDecimal, less_or_equal5);
  tcase_add_test(tDecimal, less_or_equal6);
  tcase_add_test(tDecimal, less_or_equal7);
  tcase_add_test(tDecimal, less_or_equal8);
  tcase_add_test(tDecimal, less_or_equal9);
  tcase_add_test(tDecimal, less_or_equal10);
  tcase_add_test(tDecimal, less_or_equal11);
  tcase_add_test(tDecimal, less_or_equal12);
  tcase_add_test(tDecimal, less_or_equal13);
  tcase_add_test(tDecimal, less_or_equal14);
  suite_add_tcase(s, tDecimal);
  return s;
}

Suite *decimalPrintSuite() {
  Suite *s = NULL;
  TCase *tPrint = NULL;
  s = suite_create("decimalPrint");
  tPrint = tcase_create("decPrint");
  tcase_add_test(tPrint, decimalTestPrint);

  suite_add_tcase(s, tPrint);
  return s;
}

Suite *decimalSuitesubfunc() {
  Suite *s = NULL;
  TCase *tDecimal = NULL;
  s = suite_create("decimalSub");
  tDecimal = tcase_create("decCase");
  tcase_add_test(tDecimal, dec_floor_test);
  tcase_add_test(tDecimal, dec_floor_test1);
  tcase_add_test(tDecimal, dec_floor_test2);
  tcase_add_test(tDecimal, dec_floor_test3);
  tcase_add_test(tDecimal, dec_floor_test4);

  tcase_add_test(tDecimal, dec_round_test);
  tcase_add_test(tDecimal, dec_round_test1);
  tcase_add_test(tDecimal, dec_round_test2);
  tcase_add_test(tDecimal, dec_round_test3);
  tcase_add_test(tDecimal, dec_round_test4);

  tcase_add_test(tDecimal, dec_truncate_test);
  tcase_add_test(tDecimal, dec_truncate_test1);
  tcase_add_test(tDecimal, dec_truncate_test2);
  tcase_add_test(tDecimal, dec_truncate_test3);
  tcase_add_test(tDecimal, dec_truncate_test4);

  tcase_add_test(tDecimal, dec_negate_test);
  tcase_add_test(tDecimal, dec_negate_test1);
  tcase_add_test(tDecimal, dec_negate_test2);
  tcase_add_test(tDecimal, dec_negate_test3);

  suite_add_tcase(s, tDecimal);
  return s;
}

Suite *decimalArithSuite() {
  Suite *s = NULL;
  TCase *tDecimal = NULL;
  s = suite_create("decimalArithmetic");
  tDecimal = tcase_create("decCase");
  tcase_add_test(tDecimal, sum1);
  tcase_add_test(tDecimal, sum2);
  tcase_add_test(tDecimal, sum3);
  tcase_add_test(tDecimal, sum4);
  tcase_add_test(tDecimal, sum5);
  tcase_add_test(tDecimal, sum6);
  tcase_add_test(tDecimal, sum7);
  tcase_add_test(tDecimal, sum8);
  tcase_add_test(tDecimal, sum9);
  tcase_add_test(tDecimal, sum10);
  tcase_add_test(tDecimal, sum11);
  tcase_add_test(tDecimal, sum12);

  tcase_add_test(tDecimal, sub1);
  tcase_add_test(tDecimal, sub2);
  tcase_add_test(tDecimal, sub3);
  tcase_add_test(tDecimal, sub4);
  tcase_add_test(tDecimal, sub5);
  tcase_add_test(tDecimal, sub6);
  tcase_add_test(tDecimal, sub7);
  tcase_add_test(tDecimal, sub8);
  tcase_add_test(tDecimal, sub9);
  tcase_add_test(tDecimal, sub10);
  tcase_add_test(tDecimal, sub11);
  tcase_add_test(tDecimal, sub12);

  tcase_add_test(tDecimal, mul1);
  tcase_add_test(tDecimal, mul2);
  tcase_add_test(tDecimal, mul3);
  tcase_add_test(tDecimal, mul4);
  tcase_add_test(tDecimal, mul5);
  tcase_add_test(tDecimal, mul6);
  tcase_add_test(tDecimal, mul7);
  tcase_add_test(tDecimal, mul8);
  tcase_add_test(tDecimal, mul9);
  tcase_add_test(tDecimal, mul10);
  tcase_add_test(tDecimal, mul11);
  tcase_add_test(tDecimal, mul12);

  // бесконечный цикл в делении
  tcase_add_test(tDecimal, div1);
  tcase_add_test(tDecimal, div2);
  // tcase_add_test(tDecimal, div3);
  // case_add_test(tDecimal, div4);
  // case_add_test(tDecimal, div5);
  // case_add_test(tDecimal, div6);
  // case_add_test(tDecimal, div7);
  // case_add_test(tDecimal, div8);
  // case_add_test(tDecimal, div9);
  // case_add_test(tDecimal, div10);
  // case_add_test(tDecimal, div11);
  // case_add_test(tDecimal, div12);

  suite_add_tcase(s, tDecimal);
  return s;
}

Suite *from_decimal_to_floatSuite() {
  Suite *s = NULL;
  TCase *tc = NULL;
  s = suite_create("s21_from_decimal_to_float");
  tc = tcase_create("case_from_decimal_to_float");

  tcase_add_test(tc, s21_from_decimal_to_float_1);
  tcase_add_test(tc, s21_from_decimal_to_float_2);
  tcase_add_test(tc, s21_from_decimal_to_float_3);
  tcase_add_test(tc, s21_from_decimal_to_float_4);
  tcase_add_test(tc, s21_from_decimal_to_float_5);
  tcase_add_test(tc, s21_from_decimal_to_float_6);
  tcase_add_test(tc, s21_from_decimal_to_float_7);
  tcase_add_test(tc, s21_from_decimal_to_float_8);
  tcase_add_test(tc, s21_from_decimal_to_float_9);
  tcase_add_test(tc, s21_from_decimal_to_float_10);
  tcase_add_test(tc, s21_from_decimal_to_floatTest1);
  tcase_add_test(tc, s21_from_decimal_to_floatTest2);
  tcase_add_test(tc, s21_from_decimal_to_floatTest3);
  tcase_add_test(tc, s21_from_decimal_to_floatTest4);
  tcase_add_test(tc, s21_from_decimal_to_floatTest5);
  tcase_add_test(tc, s21_from_decimal_to_floatTest6);
  tcase_add_test(tc, s21_from_decimal_to_floatTest7);

  suite_add_tcase(s, tc);
  return s;
}

Suite *from_decimal_to_intSuite() {
  Suite *s = NULL;
  TCase *tc = NULL;
  s = suite_create("s21_from_decimal_to_int");
  tc = tcase_create("case_from_decimal_to_int");

  tcase_add_test(tc, s21_from_decimal_to_int_1);
  tcase_add_test(tc, s21_from_decimal_to_int_2);
  tcase_add_test(tc, s21_from_decimal_to_int_3);
  tcase_add_test(tc, s21_from_decimal_to_int_4);
  tcase_add_test(tc, s21_from_decimal_to_int_5);
  tcase_add_test(tc, s21_from_decimal_to_int_6);

  tcase_add_test(tc, s21_test_from_decimal_to_int_0);
  tcase_add_test(tc, s21_test_from_decimal_to_int_1);
  tcase_add_test(tc, s21_test_from_decimal_to_int_2);
  tcase_add_test(tc, s21_test_from_decimal_to_int_3);
  tcase_add_test(tc, s21_test_from_decimal_to_int_4);
  tcase_add_test(tc, s21_test_from_decimal_to_int_5);
  tcase_add_test(tc, s21_test_from_decimal_to_int_6);
  tcase_add_test(tc, s21_from_decimal_to_int_new);
  tcase_add_test(tc, s21_test_from_decimal_to_int_7);
  tcase_add_test(tc, s21_test_from_decimal_to_int_8);
  tcase_add_test(tc, s21_test_from_decimal_to_int_9);
  tcase_add_test(tc, s21_test_from_decimal_to_int_10);
  tcase_add_test(tc, s21_test_from_decimal_to_int_11);
  tcase_add_test(tc, s21_test_from_decimal_to_int_12);
  tcase_add_test(tc, s21_test_from_decimal_to_int_14);
  tcase_add_test(tc, s21_test_from_decimal_to_int_15);
  tcase_add_test(tc, s21_test_from_decimal_to_int_16);
  tcase_add_test(tc, s21_test_from_decimal_to_int_17);
  tcase_add_test(tc, s21_from_decimal_to_intTest1);
  tcase_add_test(tc, s21_from_decimal_to_intTest2);
  tcase_add_test(tc, s21_from_decimal_to_intTest3);
  tcase_add_test(tc, s21_from_decimal_to_intTest4);
  tcase_add_test(tc, s21_from_decimal_to_intTest5);
  tcase_add_test(tc, s21_from_decimal_to_intTest6);
  tcase_add_test(tc, s21_from_decimal_to_intTest7);
  tcase_add_test(tc, s21_from_decimal_to_intTest8);
  tcase_add_test(tc, s21_from_decimal_to_intTest9);
  tcase_add_test(tc, s21_from_decimal_to_intTest10);
  tcase_add_test(tc, s21_from_decimal_to_intTest11);
  tcase_add_test(tc, s21_from_decimal_to_intTest12);
  tcase_add_test(tc, s21_from_decimal_to_intTest13);
  tcase_add_test(tc, s21_from_decimal_to_intTest14);
  tcase_add_test(tc, s21_from_decimal_to_intTest15);

  suite_add_tcase(s, tc);
  return s;
}

Suite *from_float_to_decimalSuite() {
  Suite *s = NULL;
  TCase *tc = NULL;
  s = suite_create("s21_from_float_to_decimal");
  tc = tcase_create("case_from_float_to_decimal");

  tcase_add_test(tc, s21_from_float_to_decimal_1);
  tcase_add_test(tc, s21_from_float_to_decimal_2);
  tcase_add_test(tc, s21_from_float_to_decimal_3);
  tcase_add_test(tc, s21_from_float_to_decimal_4);
  tcase_add_test(tc, s21_from_float_to_decimal_5);
  tcase_add_test(tc, s21_from_float_to_decimal_6);
  tcase_add_test(tc, s21_from_float_to_decimal_7);
  tcase_add_test(tc, s21_from_float_to_decimal_8);
  tcase_add_test(tc, s21_from_float_to_decimal_10);
  tcase_add_test(tc, s21_from_float_to_decimal_11);
  tcase_add_test(tc, s21_from_float_to_decimal_12);
  tcase_add_test(tc, s21_from_float_to_decimal_13);
  tcase_add_test(tc, s21_from_float_to_decimal_14);
  tcase_add_test(tc, s21_from_float_to_decimal_15);
  tcase_add_test(tc, s21_from_float_to_decimal_16);
  tcase_add_test(tc, s21_from_float_to_decimal_17);
  tcase_add_test(tc, s21_from_float_to_decimal_18);

  suite_add_tcase(s, tc);
  return s;
}

Suite *from_int_to_decimalSuite() {
  Suite *s = NULL;
  TCase *tc = NULL;
  s = suite_create("s21_from_int_to_decimal");
  tc = tcase_create("case_from_int_to_decimal");

  tcase_add_test(tc, s21_from_int_to_decimal_1);

  tcase_add_test(tc, s21_test_from_int_to_decimal_0);
  tcase_add_test(tc, s21_test_from_int_to_decimal_1);
  tcase_add_test(tc, s21_test_from_int_to_decimal_2);
  tcase_add_test(tc, s21_test_from_int_to_decimal_3);
  tcase_add_test(tc, s21_test_from_int_to_decimal_4);
  tcase_add_test(tc, s21_test_from_int_to_decimal_5);
  tcase_add_test(tc, s21_from_int_to_decimalTest1);
  tcase_add_test(tc, s21_from_int_to_decimalTest2);
  tcase_add_test(tc, s21_from_int_to_decimalTest3);
  tcase_add_test(tc, s21_from_int_to_decimalTest4);
  tcase_add_test(tc, s21_from_int_to_decimalTest5);
  tcase_add_test(tc, s21_from_int_to_decimalTest6);
  tcase_add_test(tc, s21_from_int_to_decimalTest7);
  tcase_add_test(tc, s21_from_int_to_decimalTest8);
  tcase_add_test(tc, s21_from_int_to_decimalTest9);
  tcase_add_test(tc, from_int_to_decimal_0);
  tcase_add_test(tc, from_int_to_decimal_1);

  suite_add_tcase(s, tc);
  return s;
}
