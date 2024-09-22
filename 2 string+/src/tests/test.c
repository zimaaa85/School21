#include "insertTest.h"
#include "memchrTest.h"
#include "memcmpTest.h"
#include "memcpyTest.h"
#include "memsetTest.h"
#include "strchrTest.h"
#include "strcspnTest.h"
#include "strerrorTest.h"
#include "strlenTest.h"
#include "strncatTest.h"
#include "strncmpTest.h"
#include "strncpyTest.h"
#include "strpbrkTest.h"
#include "strrchrTest.h"
#include "strspnTest.h"
#include "strstrTest.h"
#include "strtokTest.h"
#include "to_lowerTest.h"
#include "to_upperTest.h"
#include "trimTest.h"

int main() {
  int failed = 0;

  Suite *s = strlenSuite();
  Suite *s1 = strncmpSuite();
  Suite *s2 = strcspnSuite();
  Suite *s3 = memchrSuite();
  Suite *s4 = memcmpSuite();
  Suite *s5 = memcpySuite();
  Suite *s6 = memsetSuite();
  Suite *s7 = strncatSuite();
  Suite *s8 = strchrSuite();
  Suite *s9 = strncpySuite();
  Suite *s10 = strpbrkSuite();
  Suite *s11 = strrchrSuite();
  Suite *s12 = strstrSuite();
  Suite *s13 = strtokSuite();
  Suite *s14 = strspnSuite();
  Suite *s15 = to_upperSuite();
  Suite *s16 = to_lowerSuite();
  Suite *s17 = insertSuite();
  Suite *s18 = trimSuite();
  Suite *s19 = strerrorSuite();

  SRunner *sr = srunner_create(s);
  srunner_add_suite(sr, s1);
  srunner_add_suite(sr, s2);
  srunner_add_suite(sr, s3);
  srunner_add_suite(sr, s4);
  srunner_add_suite(sr, s5);
  srunner_add_suite(sr, s6);
  srunner_add_suite(sr, s7);
  srunner_add_suite(sr, s8);
  srunner_add_suite(sr, s9);
  srunner_add_suite(sr, s10);
  srunner_add_suite(sr, s11);
  srunner_add_suite(sr, s12);
  srunner_add_suite(sr, s13);
  srunner_add_suite(sr, s14);
  srunner_add_suite(sr, s15);
  srunner_add_suite(sr, s16);
  srunner_add_suite(sr, s17);
  srunner_add_suite(sr, s18);
  srunner_add_suite(sr, s19);

  srunner_run_all(sr, CK_NORMAL);
  failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

Suite *strlenSuite() {
  Suite *s = NULL;
  TCase *tStrlen = NULL;
  s = suite_create("strlen");
  tStrlen = tcase_create("strlenCase");
  tcase_add_test(tStrlen, strlenTest1);
  tcase_add_test(tStrlen, strlenTest2);
  tcase_add_test(tStrlen, strlenTest3);
  tcase_add_test(tStrlen, strlenTest4);
  tcase_add_test(tStrlen, strlenTest5);
  tcase_add_test(tStrlen, strlenTest6);
  tcase_add_test(tStrlen, strlenTest7);
  tcase_add_test(tStrlen, strlenTest8);
  tcase_add_test(tStrlen, strlenTest9);
  tcase_add_test(tStrlen, strlenTest10);
  suite_add_tcase(s, tStrlen);
  return s;
}

Suite *strncmpSuite() {
  Suite *s = NULL;
  TCase *tStrncmp = NULL;
  s = suite_create("strncmp");
  tStrncmp = tcase_create("strncmpCase");
  tcase_add_test(tStrncmp, strncmpTest1);
  tcase_add_test(tStrncmp, strncmpTest2);
  tcase_add_test(tStrncmp, strncmpTest3);
  tcase_add_test(tStrncmp, strncmpTest4);
  tcase_add_test(tStrncmp, strncmpTest5);
  tcase_add_test(tStrncmp, strncmpTest6);
  tcase_add_test(tStrncmp, strncmpTest7);
  tcase_add_test(tStrncmp, strncmpTest8);
  tcase_add_test(tStrncmp, strncmpTest9);
  tcase_add_test(tStrncmp, strncmpTest10);
  tcase_add_test(tStrncmp, strncmpTest11);
  tcase_add_test(tStrncmp, strncmpTest12);
  tcase_add_test(tStrncmp, strncmpTest13);
  tcase_add_test(tStrncmp, strncmpTest14);
  tcase_add_test(tStrncmp, strncmpTest15);
  suite_add_tcase(s, tStrncmp);
  return s;
}

Suite *strcspnSuite() {
  Suite *s = NULL;
  TCase *tStrcspn = NULL;
  s = suite_create("strcspn");
  tStrcspn = tcase_create("strcspnCase");
  tcase_add_test(tStrcspn, strcspnTest1);
  tcase_add_test(tStrcspn, strcspnTest2);
  tcase_add_test(tStrcspn, strcspnTest3);
  tcase_add_test(tStrcspn, strcspnTest4);
  tcase_add_test(tStrcspn, strcspnTest5);
  tcase_add_test(tStrcspn, strcspnTest6);
  tcase_add_test(tStrcspn, strcspnTest7);
  tcase_add_test(tStrcspn, strcspnTest8);
  tcase_add_test(tStrcspn, strcspnTest9);
  tcase_add_test(tStrcspn, strcspnTest10);
  tcase_add_test(tStrcspn, strcspnTest11);
  tcase_add_test(tStrcspn, strcspnTest12);
  tcase_add_test(tStrcspn, strcspnTest13);
  tcase_add_test(tStrcspn, strcspnTest14);
  tcase_add_test(tStrcspn, strcspnTest15);
  tcase_add_test(tStrcspn, strcspnTest16);
  tcase_add_test(tStrcspn, strcspnTest17);
  tcase_add_test(tStrcspn, strcspnTest18);
  tcase_add_test(tStrcspn, strcspnTest19);
  suite_add_tcase(s, tStrcspn);
  return s;
}

Suite *memchrSuite() {
  Suite *s = NULL;
  TCase *tMemchr = NULL;
  s = suite_create("memchr");
  tMemchr = tcase_create("memchrCase");
  tcase_add_test(tMemchr, memchrTest1);
  tcase_add_test(tMemchr, memchrTest2);
  tcase_add_test(tMemchr, memchrTest3);
  tcase_add_test(tMemchr, memchrTest4);
  tcase_add_test(tMemchr, memchrTest5);
  tcase_add_test(tMemchr, memchrTest6);
  tcase_add_test(tMemchr, memchrTest7);
  tcase_add_test(tMemchr, memchrTest8);
  suite_add_tcase(s, tMemchr);
  return s;
}

Suite *memcmpSuite() {
  Suite *s = NULL;
  TCase *tMemcmp = NULL;
  s = suite_create("memcmp");
  tMemcmp = tcase_create("memcmpCase");
  tcase_add_test(tMemcmp, memcmpTest1);
  tcase_add_test(tMemcmp, memcmpTest2);
  tcase_add_test(tMemcmp, memcmpTest3);
  tcase_add_test(tMemcmp, memcmpTest4);
  tcase_add_test(tMemcmp, memcmpTest5);
  tcase_add_test(tMemcmp, memcmpTest6);
  tcase_add_test(tMemcmp, memcmpTest7);
  tcase_add_test(tMemcmp, memcmpTest8);
  tcase_add_test(tMemcmp, memcmpTest9);
  tcase_add_test(tMemcmp, memcmpTest10);
  tcase_add_test(tMemcmp, memcmpTest11);
  tcase_add_test(tMemcmp, memcmpTest12);
  tcase_add_test(tMemcmp, memcmpTest13);
  tcase_add_test(tMemcmp, memcmpTest14);
  tcase_add_test(tMemcmp, memcmpTest15);
  suite_add_tcase(s, tMemcmp);
  return s;
}

Suite *memcpySuite() {
  Suite *s = NULL;
  TCase *tMemcpy = NULL;
  s = suite_create("memcpy");
  tMemcpy = tcase_create("memcpyCase");
  tcase_add_test(tMemcpy, memcpyTest1);
  tcase_add_test(tMemcpy, memcpyTest2);
  tcase_add_test(tMemcpy, memcpyTest3);
  tcase_add_test(tMemcpy, memcpyTest4);
  tcase_add_test(tMemcpy, memcpyTest5);
  tcase_add_test(tMemcpy, memcpyTest6);
  tcase_add_test(tMemcpy, memcpyTest7);
  tcase_add_test(tMemcpy, memcpyTest8);
  tcase_add_test(tMemcpy, memcpyTest9);
  tcase_add_test(tMemcpy, memcpyTest10);
  tcase_add_test(tMemcpy, memcpyTest11);
  suite_add_tcase(s, tMemcpy);
  return s;
}

Suite *memsetSuite() {
  Suite *s = NULL;
  TCase *tMemset = NULL;
  s = suite_create("memset");
  tMemset = tcase_create("memsetCase");
  tcase_add_test(tMemset, memsetTest1);
  tcase_add_test(tMemset, memsetTest2);
  tcase_add_test(tMemset, memsetTest3);
  tcase_add_test(tMemset, memsetTest4);
  tcase_add_test(tMemset, memsetTest5);
  tcase_add_test(tMemset, memsetTest6);
  tcase_add_test(tMemset, memsetTest7);
  tcase_add_test(tMemset, memsetTest8);
  tcase_add_test(tMemset, memsetTest9);
  tcase_add_test(tMemset, memsetTest10);
  tcase_add_test(tMemset, memsetTest11);
  tcase_add_test(tMemset, memsetTest12);
  tcase_add_test(tMemset, memsetTest13);
  tcase_add_test(tMemset, memsetTest14);
  tcase_add_test(tMemset, memsetTest15);
  tcase_add_test(tMemset, memsetTest16);
  suite_add_tcase(s, tMemset);
  return s;
}

Suite *strncatSuite() {
  Suite *s = NULL;
  TCase *tStrncat = NULL;
  s = suite_create("strncat");
  tStrncat = tcase_create("strncatCase");
  tcase_add_test(tStrncat, strncatTest1);
  tcase_add_test(tStrncat, strncatTest2);
  tcase_add_test(tStrncat, strncatTest3);
  tcase_add_test(tStrncat, strncatTest4);
  tcase_add_test(tStrncat, strncatTest5);
  tcase_add_test(tStrncat, strncatTest6);
  tcase_add_test(tStrncat, strncatTest7);
  tcase_add_test(tStrncat, strncatTest8);
  tcase_add_test(tStrncat, strncatTest9);

  suite_add_tcase(s, tStrncat);
  return s;
}

Suite *strchrSuite() {
  Suite *s = NULL;
  TCase *tStrchr = NULL;
  s = suite_create("strchr");
  tStrchr = tcase_create("strchrCase");
  tcase_add_test(tStrchr, strchrTest1);
  tcase_add_test(tStrchr, strchrTest2);
  tcase_add_test(tStrchr, strchrTest3);
  tcase_add_test(tStrchr, strchrTest4);
  tcase_add_test(tStrchr, strchrTest5);
  tcase_add_test(tStrchr, strchrTest6);
  tcase_add_test(tStrchr, strchrTest7);
  tcase_add_test(tStrchr, strchrTest8);
  suite_add_tcase(s, tStrchr);
  return s;
}

Suite *strncpySuite() {
  Suite *s = NULL;
  TCase *tStrncpy = NULL;
  s = suite_create("strncpy");
  tStrncpy = tcase_create("strncpyCase");
  tcase_add_test(tStrncpy, strncpyTest1);
  tcase_add_test(tStrncpy, strncpyTest2);
  tcase_add_test(tStrncpy, strncpyTest3);
  tcase_add_test(tStrncpy, strncpyTest4);
  tcase_add_test(tStrncpy, strncpyTest5);
  tcase_add_test(tStrncpy, strncpyTest6);
  tcase_add_test(tStrncpy, strncpyTest7);
  tcase_add_test(tStrncpy, strncpyTest8);
  tcase_add_test(tStrncpy, strncpyTest9);
  suite_add_tcase(s, tStrncpy);
  return s;
}

Suite *strpbrkSuite() {
  Suite *s = NULL;
  TCase *tStrpbrk = NULL;
  s = suite_create("strpbrk");
  tStrpbrk = tcase_create("strpbrkCase");
  tcase_add_test(tStrpbrk, strpbrkTest1);
  tcase_add_test(tStrpbrk, strpbrkTest2);
  tcase_add_test(tStrpbrk, strpbrkTest3);
  tcase_add_test(tStrpbrk, strpbrkTest4);
  tcase_add_test(tStrpbrk, strpbrkTest5);
  tcase_add_test(tStrpbrk, strpbrkTest6);
  tcase_add_test(tStrpbrk, strpbrkTest7);
  tcase_add_test(tStrpbrk, strpbrkTest8);
  tcase_add_test(tStrpbrk, strpbrkTest9);
  tcase_add_test(tStrpbrk, strpbrkTest10);
  tcase_add_test(tStrpbrk, strpbrkTest11);
  tcase_add_test(tStrpbrk, strpbrkTest12);
  tcase_add_test(tStrpbrk, strpbrkTest13);
  tcase_add_test(tStrpbrk, strpbrkTest14);
  tcase_add_test(tStrpbrk, strpbrkTest15);
  tcase_add_test(tStrpbrk, strpbrkTest16);
  suite_add_tcase(s, tStrpbrk);
  return s;
}

Suite *strrchrSuite() {
  Suite *s = NULL;
  TCase *tStrrchr = NULL;
  s = suite_create("strrchr");
  tStrrchr = tcase_create("strrchrCase");
  tcase_add_test(tStrrchr, strrchrTest1);
  tcase_add_test(tStrrchr, strrchrTest2);
  tcase_add_test(tStrrchr, strrchrTest3);
  tcase_add_test(tStrrchr, strrchrTest4);
  tcase_add_test(tStrrchr, strrchrTest5);
  tcase_add_test(tStrrchr, strrchrTest6);
  tcase_add_test(tStrrchr, strrchrTest7);
  tcase_add_test(tStrrchr, strrchrTest8);
  tcase_add_test(tStrrchr, strrchrTest9);
  tcase_add_test(tStrrchr, strrchrTest10);
  tcase_add_test(tStrrchr, strrchrTest11);
  tcase_add_test(tStrrchr, strrchrTest12);
  suite_add_tcase(s, tStrrchr);
  return s;
}

Suite *strstrSuite() {
  Suite *s = NULL;
  TCase *tStrstr = NULL;
  s = suite_create("strstr");
  tStrstr = tcase_create("strstrCase");
  tcase_add_test(tStrstr, strstrTest1);
  tcase_add_test(tStrstr, strstrTest2);
  tcase_add_test(tStrstr, strstrTest3);
  tcase_add_test(tStrstr, strstrTest4);
  tcase_add_test(tStrstr, strstrTest5);
  tcase_add_test(tStrstr, strstrTest6);
  tcase_add_test(tStrstr, strstrTest7);
  tcase_add_test(tStrstr, strstrTest8);
  suite_add_tcase(s, tStrstr);
  return s;
}

Suite *strtokSuite() {
  Suite *s = NULL;
  TCase *tStrtok = NULL;
  s = suite_create("strtok");
  tStrtok = tcase_create("strtokCase");
  tcase_add_test(tStrtok, strtokTest1);
  tcase_add_test(tStrtok, strtokTest2);
  tcase_add_test(tStrtok, strtokTest3);
  tcase_add_test(tStrtok, strtokTest4);
  tcase_add_test(tStrtok, strtokTest5);
  tcase_add_test(tStrtok, strtokTest6);
  tcase_add_test(tStrtok, strtokTest7);
  tcase_add_test(tStrtok, strtokTest8);
  tcase_add_test(tStrtok, strtokTest9);
  tcase_add_test(tStrtok, strtokTest10);
  tcase_add_test(tStrtok, strtokTest11);
  tcase_add_test(tStrtok, strtokTest12);
  tcase_add_test(tStrtok, strtokTest13);
  tcase_add_test(tStrtok, strtokTest14);
  suite_add_tcase(s, tStrtok);
  return s;
}

Suite *strspnSuite() {
  Suite *s = NULL;
  TCase *tStrspn = NULL;
  s = suite_create("strspn");
  tStrspn = tcase_create("strspnCase");
  tcase_add_test(tStrspn, strspnTest1);
  tcase_add_test(tStrspn, strspnTest2);
  tcase_add_test(tStrspn, strspnTest3);
  tcase_add_test(tStrspn, strspnTest4);
  tcase_add_test(tStrspn, strspnTest5);
  tcase_add_test(tStrspn, strspnTest6);
  tcase_add_test(tStrspn, strspnTest7);
  tcase_add_test(tStrspn, strspnTest8);
  tcase_add_test(tStrspn, strspnTest9);
  tcase_add_test(tStrspn, strspnTest10);
  tcase_add_test(tStrspn, strspnTest11);
  tcase_add_test(tStrspn, strspnTest12);
  tcase_add_test(tStrspn, strspnTest13);
  tcase_add_test(tStrspn, strspnTest14);
  tcase_add_test(tStrspn, strspnTest15);
  tcase_add_test(tStrspn, strspnTest16);
  tcase_add_test(tStrspn, strspnTest17);
  tcase_add_test(tStrspn, strspnTest18);
  suite_add_tcase(s, tStrspn);
  return s;
}

Suite *to_upperSuite() {
  Suite *s = NULL;
  TCase *tTo_upper = NULL;
  s = suite_create("to_upper");
  tTo_upper = tcase_create("to_upperCase");
  tcase_add_test(tTo_upper, to_upperTest1);
  tcase_add_test(tTo_upper, to_upperTest2);
  tcase_add_test(tTo_upper, to_upperTest3);
  tcase_add_test(tTo_upper, to_upperTest4);
  tcase_add_test(tTo_upper, to_upperTest5);
  tcase_add_test(tTo_upper, to_upperTest6);
  tcase_add_test(tTo_upper, to_upperTest7);
  tcase_add_test(tTo_upper, to_upperTest8);
  tcase_add_test(tTo_upper, to_upperTest9);
  tcase_add_test(tTo_upper, to_upperTest10);
  suite_add_tcase(s, tTo_upper);
  return s;
}

Suite *to_lowerSuite() {
  Suite *s = NULL;
  TCase *tTo_lower = NULL;
  s = suite_create("to_lower");
  tTo_lower = tcase_create("to_lowerCase");
  tcase_add_test(tTo_lower, to_lowerTest1);
  tcase_add_test(tTo_lower, to_lowerTest2);
  tcase_add_test(tTo_lower, to_lowerTest3);
  tcase_add_test(tTo_lower, to_lowerTest4);
  tcase_add_test(tTo_lower, to_lowerTest5);
  tcase_add_test(tTo_lower, to_lowerTest6);
  tcase_add_test(tTo_lower, to_lowerTest7);
  tcase_add_test(tTo_lower, to_lowerTest8);
  tcase_add_test(tTo_lower, to_lowerTest9);
  tcase_add_test(tTo_lower, to_lowerTest10);
  suite_add_tcase(s, tTo_lower);
  return s;
}

Suite *insertSuite() {
  Suite *s = NULL;
  TCase *tInsert = NULL;
  s = suite_create("insert");
  tInsert = tcase_create("insert");
  tcase_add_test(tInsert, insertTest1);
  tcase_add_test(tInsert, insertTest2);
  tcase_add_test(tInsert, insertTest3);
  tcase_add_test(tInsert, insertTest4);
  tcase_add_test(tInsert, insertTest5);
  tcase_add_test(tInsert, insertTest6);
  tcase_add_test(tInsert, insertTest7);
  tcase_add_test(tInsert, insertTest8);
  tcase_add_test(tInsert, insertTest9);
  suite_add_tcase(s, tInsert);
  return s;
}

Suite *trimSuite() {
  Suite *s = NULL;
  TCase *tTrim = NULL;
  s = suite_create("trim");
  tTrim = tcase_create("trim");
  tcase_add_test(tTrim, trimTest1);
  tcase_add_test(tTrim, trimTest2);
  tcase_add_test(tTrim, trimTest3);
  tcase_add_test(tTrim, trimTest4);
  tcase_add_test(tTrim, trimTest5);
  tcase_add_test(tTrim, trimTest6);
  tcase_add_test(tTrim, trimTest7);
  tcase_add_test(tTrim, trimTest8);
  tcase_add_test(tTrim, trimTest9);
  suite_add_tcase(s, tTrim);
  return s;
}

Suite *strerrorSuite() {
  Suite *s = NULL;
  TCase *tStrerror = NULL;
  s = suite_create("strerror");
  tStrerror = tcase_create("strerror");
  tcase_add_test(tStrerror, strerrorTest1);

  suite_add_tcase(s, tStrerror);
  return s;
}