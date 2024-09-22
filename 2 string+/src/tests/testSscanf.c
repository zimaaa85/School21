// #include "sscanfSpecTestD.h"
#include "../s21_string.h"
#include "sscanfFlagsTest.h"
#include "sscanfSpecTest.h"

int main() {
  int failed = 0;
  Suite *s = specifSuite();
  Suite *s1 = sflagsSuite();
  SRunner *sr = srunner_create(s);
  srunner_add_suite(sr, s1);
  srunner_run_all(sr, CK_NORMAL);
  failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

Suite *specifSuite() {
  Suite *s = NULL;
  TCase *tSpec = NULL;
  s = suite_create("Sscanf specifiers");
  tSpec = tcase_create("specCase");
  tcase_add_test(tSpec, specTest1);
  tcase_add_test(tSpec, specTest2);
  tcase_add_test(tSpec, specTest3);
  tcase_add_test(tSpec, specTest4);
  tcase_add_test(tSpec, specTest5);
  tcase_add_test(tSpec, specTest6);
  tcase_add_test(tSpec, specTest7);
  tcase_add_test(tSpec, specTest8);
  tcase_add_test(tSpec, specTest9);
  tcase_add_test(tSpec, specTest10);
  tcase_add_test(tSpec, specTest11);
  tcase_add_test(tSpec, specTest12);
  tcase_add_test(tSpec, specTest13);
  tcase_add_test(tSpec, specTest14);
  tcase_add_test(tSpec, specTest15);
  tcase_add_test(tSpec, specTest16);
  tcase_add_test(tSpec, specTest17);
  tcase_add_test(tSpec, specTest18);
  tcase_add_test(tSpec, specTest19);
  tcase_add_test(tSpec, specTest20);
  tcase_add_test(tSpec, specTest21);
  tcase_add_test(tSpec, specTest22);
  tcase_add_test(tSpec, specTest23);
  tcase_add_test(tSpec, specTest24);
  tcase_add_test(tSpec, specTest25);
  tcase_add_test(tSpec, specTest26);
  tcase_add_test(tSpec, specTest27);
  suite_add_tcase(s, tSpec);
  return s;
}

Suite *sflagsSuite() {
  Suite *s = NULL;
  TCase *tFlags = NULL;
  s = suite_create("Sscanf flags");
  tFlags = tcase_create("flasCase");
  tcase_add_test(tFlags, flagsTest1);
  tcase_add_test(tFlags, flagsTest2);
  tcase_add_test(tFlags, flagsTest3);
  tcase_add_test(tFlags, flagsTest4);
  tcase_add_test(tFlags, flagsTest5);
  tcase_add_test(tFlags, flagsTest6);
  tcase_add_test(tFlags, flagsTest7);
  tcase_add_test(tFlags, flagsTest8);
  tcase_add_test(tFlags, flagsTest9);
  tcase_add_test(tFlags, flagsTest10);
  tcase_add_test(tFlags, flagsTest11);
  tcase_add_test(tFlags, flagsTest12);
  tcase_add_test(tFlags, flagsTest13);
  tcase_add_test(tFlags, flagsTest14);
  tcase_add_test(tFlags, flagsTest15);
  tcase_add_test(tFlags, flagsTest16);
  tcase_add_test(tFlags, flagsTest17);
  tcase_add_test(tFlags, flagsTest18);
  tcase_add_test(tFlags, flagsTest19);
  tcase_add_test(tFlags, flagsTest20);
  tcase_add_test(tFlags, flagsTest21);
  suite_add_tcase(s, tFlags);
  return s;
}