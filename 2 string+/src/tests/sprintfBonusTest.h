#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *bonusSuite();

START_TEST(bonusTest1) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "Hello world! - %5e|";
  sprintf(str1, format, 43534.43534534);
  s21_sprintf(str2, format, 43534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest1a) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "%5eHello world! - %5e|";
  sprintf(str1, format, 0.0, 43534.43534534);
  s21_sprintf(str2, format, 0.0, 43534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest1b) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "%5eHello%e world! - %5e|";
  sprintf(str1, format, 0.0, -22.0, 43534.43534534);
  s21_sprintf(str2, format, 0.0, -22.0, 43534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest1c) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "%5e%e%12.2e";
  sprintf(str1, format, 0.0, -22.0, 43534.43534534);
  s21_sprintf(str2, format, 0.0, -22.0, 43534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest2) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "Hello world! - %5E|";
  sprintf(str1, format, 43534.43534534);
  s21_sprintf(str2, format, 43534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest2a) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "%5EHello world! - %5E|";
  sprintf(str1, format, 0.0, 43534.43534534);
  s21_sprintf(str2, format, 0.0, 43534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest2b) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "%5EHello%E world! - %5E|";
  sprintf(str1, format, 0.0, -22.0, 43534.43534534);
  s21_sprintf(str2, format, 0.0, -22.0, 43534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest2c) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "%5E%E%12.2E";
  sprintf(str1, format, 0.0, -22.0, 43534.43534534);
  s21_sprintf(str2, format, 0.0, -22.0, 43534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest3) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "Hello world! - %5g|";
  sprintf(str1, format, 43534.43534534);
  s21_sprintf(str2, format, 43534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest3a) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "%5gHello world! - %5g|";
  sprintf(str1, format, 0.0, 43534.43534534);
  s21_sprintf(str2, format, 0.0, 43534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest3b) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "%5gHello%g world! - %5g|";
  sprintf(str1, format, 0.0, -22.0, 43534.43534534);
  s21_sprintf(str2, format, 0.0, -22.0, 43534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest3c) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "%5g%g%12.2g";
  sprintf(str1, format, 0.0, -22.0, 43534.43534534);
  s21_sprintf(str2, format, 0.0, -22.0, 43534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest4) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "Hello world! - %5G|";
  sprintf(str1, format, 43534.43534534);
  s21_sprintf(str2, format, 43534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest4a) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "%5GHello world! - %5G|";
  sprintf(str1, format, 0.0, 43534.43534534);
  s21_sprintf(str2, format, 0.0, 43534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest4b) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "%5GHello%G world! - %5G|";
  sprintf(str1, format, 0.0, -22.0, 43534.43534534);
  s21_sprintf(str2, format, 0.0, -22.0, 43534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest4c) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "%5G%G%12.2G";
  sprintf(str1, format, 0.0, -22.0, 43534.43534534);
  s21_sprintf(str2, format, 0.0, -22.0, 43534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest5) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "Hello world! - %5g|";
  sprintf(str1, format, 324324343534.43534534);
  s21_sprintf(str2, format, 324324343534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest5a) {
  char str1[400] = "-";
  char str2[40] = "-";
  const char format[] = "%5gHello world! - %5g|";
  sprintf(str1, format, 0.0, 324324343534.43534534);
  s21_sprintf(str2, format, 0.0, 324324343534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest5b) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "%5gHello%g world! - %5g|";
  sprintf(str1, format, 0.0, -22.0, 324324343534.43534534);
  s21_sprintf(str2, format, 0.0, -22.0, 324324343534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest5c) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "%5g%g%12.2g";
  sprintf(str1, format, 0.0, -22.0, 324324343534.43534534);
  s21_sprintf(str2, format, 0.0, -22.0, 324324343534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest6) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "Hello world! - %5G|";
  sprintf(str1, format, 324324343534.43534534);
  s21_sprintf(str2, format, 324324343534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest6a) {
  char str1[400] = "-";
  char str2[40] = "-";
  const char format[] = "%5GHello world! - %5G|";
  sprintf(str1, format, 0.0, 324324343534.43534534);
  s21_sprintf(str2, format, 0.0, 324324343534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest6b) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "%5GHello%G world! - %5G|";
  sprintf(str1, format, 0.0, -22.0, 324324343534.43534534);
  s21_sprintf(str2, format, 0.0, -22.0, 324324343534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest6c) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "%5G%G%12.2G";
  sprintf(str1, format, 0.0, -22.0, 324324343534.43534534);
  s21_sprintf(str2, format, 0.0, -22.0, 324324343534.43534534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest7) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "Hello world! - %5x";
  sprintf(str1, format, 43534);
  s21_sprintf(str2, format, 43534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest7a) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "%5xHello world! - %1x|";
  sprintf(str1, format, 0, 3324);
  s21_sprintf(str2, format, 0, 3324);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest7b) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "%5xHello%x world! - %13x|";
  sprintf(str1, format, 0, -22, 43534324);
  s21_sprintf(str2, format, 0, -22, 43534324);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest7c) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "%5x%x%12.2x";
  sprintf(str1, format, 0, -226666, 33);
  s21_sprintf(str2, format, 0, -226666, 33);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest8) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "Hello world! - %5X";
  sprintf(str1, format, 43534);
  s21_sprintf(str2, format, 43534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest8a) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "%5XHello world! - %1X|";
  sprintf(str1, format, 0, 3324);
  s21_sprintf(str2, format, 0, 3324);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest8b) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "%5XHello%X world! - %13X|";
  sprintf(str1, format, 0, -22, 43534324);
  s21_sprintf(str2, format, 0, -22, 43534324);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest8c) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "%5X%X%12.2X";
  sprintf(str1, format, 0, -226666, 33);
  s21_sprintf(str2, format, 0, -226666, 33);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest9) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "Hello world! - %5o";
  sprintf(str1, format, 43534);
  s21_sprintf(str2, format, 43534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest9a) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "%5oHello world! - %1o|";
  sprintf(str1, format, 0, 3324);
  s21_sprintf(str2, format, 0, 3324);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest9b) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "%5oHello%o world! - %13o|";
  sprintf(str1, format, 0, -22, 43534324);
  s21_sprintf(str2, format, 0, -22, 43534324);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest9c) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "%5o%o%12.2o";
  sprintf(str1, format, 0, -226666, 33);
  s21_sprintf(str2, format, 0, -226666, 33);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest10) {
  char str1[400] = "-";
  char str2[400] = "-";
  int b = 100;
  const char format[] = "Hello world! - %p";
  sprintf(str1, format, &b);
  s21_sprintf(str2, format, &b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest10a) {
  char str1[400] = "-";
  char str2[400] = "-";
  double a = 10.0;
  float b = 0.0;
  const char format[] = "%5pHello world! - %1p|";
  sprintf(str1, format, &a, &b);
  s21_sprintf(str2, format, &a, &b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest10b) {
  char str1[400] = "-";
  char str2[400] = "-";
  double a = 10.0;
  float b = 0.0;
  int c = -2;
  const char format[] = "%5pHello%p world! - %13p|";
  sprintf(str1, format, &a, &b, &c);
  s21_sprintf(str2, format, &a, &b, &c);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest10c) {
  char str1[400] = "-";
  char str2[400] = "-";
  double a = 10.0;
  float b = 0.0;
  int c = -2;
  const char format[] = "%5p%p%12p";
  sprintf(str1, format, &a, &b, &c);
  s21_sprintf(str2, format, &a, &b, &c);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest11) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "Hello world - %#o, %#x, %#X";
  sprintf(str1, format, 44453, 23, -123);
  s21_sprintf(str2, format, 44453, 23, -123);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest12) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "%#o%#x%#XHello world - \n";
  sprintf(str1, format, 4443, 0, -435435);
  s21_sprintf(str2, format, 4443, 0, -435435);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest13) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "Hello world - %#e, %#E, %#f";
  sprintf(str1, format, 44453342.23213, 44453342.23, -123.0);
  s21_sprintf(str2, format, 44453342.23213, 44453342.23, -123.0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest14) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "Hello world - %#12.0e, %#3.0E, %#4.0f";
  sprintf(str1, format, 44453342.23213, 44453342.23, -123.0);
  s21_sprintf(str2, format, 44453342.23213, 44453342.23, -123.0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest15) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "%#12.0e, %#3.0E, %#4.0f Hello world";
  sprintf(str1, format, 44453342.23213, 44453342.23, -123.0);
  s21_sprintf(str2, format, 44453342.23213, 44453342.23, -123.0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest16) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "%#e, %#E, %#f Hello world";
  sprintf(str1, format, 44453342.23213, 44453342.23, -123.0);
  s21_sprintf(str2, format, 44453342.23213, 44453342.23, -123.0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest17) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "%0#12.0e, %0#3.0E, %0#4.0f Hello world";
  sprintf(str1, format, 44453342.23213, 44453342.23, -123.0);
  s21_sprintf(str2, format, 44453342.23213, 44453342.23, -123.0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest18) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "%0#12.0e, %0#3.0E, %0#f Hello world";
  sprintf(str1, format, 44453342.23213, 44453342.23, -123.0);
  s21_sprintf(str2, format, 44453342.23213, 44453342.23, -123.0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest19) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] = "%s%+-50.*f%s";
  sprintf(str1, format, "hello\n", 4, -3210.33322323, "\nbye\n");
  s21_sprintf(str2, format, "hello\n", 4, -3210.33322323, "\nbye\n");
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest20) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] = "%s%-*c%s";
  sprintf(str1, format, "hello\n", 5, 10, "\nbye\n");
  s21_sprintf(str2, format, "hello\n", 5, 10, "\nbye\n");
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest21) {
  char str1[400] = " \0";
  char str2[400] = " \0";
  const char format[] = "%sgo go%s%-*u%+d%*.*f";
  sprintf(str1, format, " \0", "\n", 50, 4255, -352, 5, 7, 456.2343432423);
  s21_sprintf(str2, format, " \0", "\n", 50, 4255, -352, 5, 7, 456.2343432423);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest22) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "Hello world! - %hd";
  sprintf(str1, format, 0);
  s21_sprintf(str2, format, 0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest23) {
  char str1[40] = "1234567890987789678";
  char str2[40] = "1234567890987789678";
  const char format[] = "Hello world! - %ld";
  sprintf(str1, format, 1561565561888860000);
  s21_sprintf(str2, format, 1561565561888860000);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest24) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "Hello world - %#ho, %#hx, %#hX";
  sprintf(str1, format, 44453, 23, -123);
  s21_sprintf(str2, format, 44453, 23, -123);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest25) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "Hello world - %#lo, %#lx, %#lX";
  sprintf(str1, format, 4445300000000000000, 2300000000000000000,
          -1230000000000000000);
  s21_sprintf(str2, format, 4445300000000000000, 2300000000000000000,
              -1230000000000000000);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest26) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "%#6.0Le, %#3.0LE, %#4.2Lf Hello world";
  sprintf(str1, format, (long double)44420.23213, (long double)44453.20003,
          (long double)-123.01);
  s21_sprintf(str2, format, (long double)44420.23213, (long double)44453.20003,
              (long double)-123.01);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest27) {
  char str1[400] = "-";
  char str2[400] = "-";
  const char format[] = "%5LG%LG%12.2Lg";
  sprintf(str1, format, (long double)1000.0, (long double)-20002.01,
          (long double)343534.4354534);
  s21_sprintf(str2, format, (long double)1000.0, (long double)-20002.01,
              (long double)343534.4354534);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest28) {
  char str1[40] = "-";
  char str2[40] = "-";
  const char format[] = "Hello world! - |% 2dc|";
  sprintf(str1, format, -55);
  s21_sprintf(str2, format, -55);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest29) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] = "%c %d %e %E %f %g %G %o %s %u %x %X %p";
  int x = 0;
  sprintf(str1, format, 3, 1000, 32423432.33, 2341111431.01, -45.4, 3243243.123,
          2312355.0, 32423, "\n\n", 4, 45, 53434, &x);
  s21_sprintf(str2, format, 3, 1000, 32423432.33, 2341111431.01, -45.4,
              3243243.123, 2312355.0, 32423, "\n\n", 4, 45, 53434, &x);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest30) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] = "%cd %dd %ee %Ef %fa %gf %Gu %os %sc %us %xc %Xx %ps";
  int x = 0;
  sprintf(str1, format, -3, -1000, -32432.33, -2331.01, 45.4, -33.123, -255.0,
          -3223, "f", -4, -45, -53434, &x);
  s21_sprintf(str2, format, -3, -1000, -32432.33, -2331.01, 45.4, -33.123,
              -255.0, -3223, "f", -4, -45, -53434, &x);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest31) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] =
      "%cd %hdd %Lee\n %Ef %fa %gf %Gu %hos %sc %hu%hx%hXxvccc%p\ns";
  int x = 0;
  sprintf(str1, format, 45, -1020, (long double)-3242332.3003, -2341431.01, 0.0,
          -3243243.123, 2312355.0, 32423, "f", 4, -45, 53434, &x);
  s21_sprintf(str2, format, 45, -1020, (long double)-3242332.3003, -2341431.01,
              0.0, -3243243.123, 2312355.0, 32423, "f", 4, -45, 53434, &x);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest32) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] =
      "%cdvd!@#$ %ldd %Lee\n %Ef %fa %gf %Gu %los %sc %lu%lx%lXxvccc%p\ns";
  int x = 0;
  sprintf(str1, format, 45, (long int)-10200000, (long double)-332.3003,
          -2331.01, 0.0, -3243.123, 255.0, (long unsigned int)324200, "f",
          (long unsigned int)4, (long unsigned int)45, (long unsigned int)53434,
          &x);
  s21_sprintf(str2, format, 45, (long int)-10200000, (long double)-332.3003,
              -2331.01, 0.0, -3243.123, 255.0, (long unsigned int)324200, "f",
              (long unsigned int)4, (long unsigned int)45,
              (long unsigned int)53434, &x);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest33) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] =
      "%2cdvd!@#$ %2ldd %1Lee\n %1Ef %1fa %2gf %3Gu %2los %sc "
      "%1lu%2lx%1lXxvccc%1p\ns";
  int x = 0;
  sprintf(str1, format, 45, (long int)-102000, (long double)-322.33, -2331.01,
          0.0, -33.123, 255.0, (long unsigned int)324230, "f",
          (long unsigned int)4, (long unsigned int)45, (long unsigned int)53434,
          &x);
  s21_sprintf(str2, format, 45, (long int)-102000, (long double)-322.33,
              -2331.01, 0.0, -33.123, 255.0, (long unsigned int)324230, "f",
              (long unsigned int)4, (long unsigned int)45,
              (long unsigned int)53434, &x);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest34) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] =
      "%12cdvd!@#$ %12ldd %11Lee\n %11Ef %11fa %12gf %13Gu %12los %sc "
      "%11lu%12lx%11lXxvccc%11p\ns";
  int x = 0;
  sprintf(str1, format, 45, (long int)-10200, (long double)-32.3003, -231.01,
          0.0, -343.123, 235.0, (long unsigned int)32000, "f",
          (long unsigned int)4, (long unsigned int)45, (long unsigned int)53434,
          &x);
  s21_sprintf(str2, format, 45, (long int)-10200, (long double)-32.3003,
              -231.01, 0.0, -343.123, 235.0, (long unsigned int)32000, "f",
              (long unsigned int)4, (long unsigned int)45,
              (long unsigned int)53434, &x);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest35) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] =
      "%*cdvd!@#$ %*ldd %*Lee\n %*Ef %*fa %*gf %*Gu %*los %11sc "
      "%*lu%*lx%*lXxvccc\ns";
  int c = 50;
  long double le = -3232.3003;
  long int ld = -102000;
  double e = -2341.01;
  float f = 11.22;
  double g = -3243.123, G = 2315.0;
  long int lo = 3242300;
  long unsigned int lu = 4, lx = 45, lX = 53434;
  sprintf(str1, format, 12, c, 20, ld, 11, le, 11, e, 13, f, 12, g, 13, G, 16,
          lo, "f", 9, lu, 18, lx, 15, lX);
  s21_sprintf(str2, format, 12, c, 20, ld, 11, le, 11, e, 13, f, 12, g, 13, G,
              16, lo, "f", 9, lu, 18, lx, 15, lX);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest37) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] =
      "%*cdvd!@#$ %*ldd %*.*Lee\n %*.*Ef %*.2fa %*.*gf %*.*Gu %*los %11sc "
      "%*lu%*lx%*lXxvccc\ns";
  int c = 50;
  long double le = -3242.33;
  long int ld = -1020000;
  double e = -231.01;
  float f = 11.23;
  double g = -3243.123, G = 23355.0;
  long int lo = 3242300;
  long unsigned int lu = 4, lx = 45, lX = 53434;
  sprintf(str1, format, 12, c, 20, ld, 11, 10, le, 11, 1, e, 13, f, 12, 2, g,
          13, 0, G, 16, lo, "f", 9, lu, 18, lx, 15, lX);
  s21_sprintf(str2, format, 12, c, 20, ld, 11, 10, le, 11, 1, e, 13, f, 12, 2,
              g, 13, 0, G, 16, lo, "f", 9, lu, 18, lx, 15, lX);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest38) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] =
      "%-*cdvd!@#$ %-*ldd %-*.*Lee\n %-*.*Ef %-*.2fa %-*.*gf %-*.*Gu %-*los "
      "%-11sc %-*lu%-*lx%-*lXxvccc\ns";
  int c = 50;
  long double le = -332.33;
  long int ld = -100000;
  double e = -23431.01;
  float f = 11.22;
  double g = -323.123, G = 2315.0;
  long int lo = 3240000;
  long unsigned int lu = 4, lx = 45, lX = 53434;
  sprintf(str1, format, 12, c, 20, ld, 11, 10, le, 11, 1, e, 13, f, 12, 2, g,
          13, 0, G, 16, lo, "f", 9, lu, 18, lx, 15, lX);
  s21_sprintf(str2, format, 12, c, 20, ld, 11, 10, le, 11, 1, e, 13, f, 12, 2,
              g, 13, 0, G, 16, lo, "f", 9, lu, 18, lx, 15, lX);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest39) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] =
      "%-*cdvd!@#$ %-+*ldd %-+*.*Lee\n %+-*.*Ef %+-*.2fa %-+*.*gf %+-*.*Gu "
      "%-*los %-11sc %-*lu%-*lx%-*lXxvccc\ns";
  int c = 50;
  long double le = -32.3003;
  long int ld = -1020000;
  double e = -23411.01;
  float f = 11.22;
  double g = -32243.123, G = 2355.0;
  long int lo = 3242000;
  long unsigned int lu = 4, lx = 45, lX = 53434;
  sprintf(str1, format, 12, c, 20, ld, 11, 10, le, 11, 1, e, 13, f, 12, 2, g,
          13, 0, G, 16, lo, "f", 9, lu, 18, lx, 15, lX);
  s21_sprintf(str2, format, 12, c, 20, ld, 11, 10, le, 11, 1, e, 13, f, 12, 2,
              g, 13, 0, G, 16, lo, "f", 9, lu, 18, lx, 15, lX);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest40) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] =
      "%-*cdvd!@#$ %-+*ldd %-+#*.*Lee\n %#+-*.*Ef %+#-*.2fa %#-+*.*gf "
      "%#+-*.*Gu %-*los %-11sc %-*lu%-#*lx%#-*lXxvccc\ns";
  int c = 50;
  long double le = -322.3003;
  long int ld = -100000;
  double e = -2341.01;
  float f = 11.22;
  double g = -3243.123, G = 2315.0;
  long int lo = 3242300;
  long unsigned int lu = 4, lx = 45, lX = 53434;
  sprintf(str1, format, 12, c, 20, ld, 11, 10, le, 11, 1, e, 13, f, 12, 2, g,
          13, 0, G, 16, lo, "f", 9, lu, 18, lx, 15, lX);
  s21_sprintf(str2, format, 12, c, 20, ld, 11, 10, le, 11, 1, e, 13, f, 12, 2,
              g, 13, 0, G, 16, lo, "f", 9, lu, 18, lx, 15, lX);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(bonusTest41) {
  char str1[400] = "";
  char str2[400] = "";
  const char format[] =
      "%-*cdvd!@#$ %+0*ldd %+#0*.*Lee\n %0#+*.*Ef %0+#*.2fa %#0+*.*gf "
      "%0#+*.*Gu %0*los %11sc %0*lu%0#*lx%0#*lXxvccc\ns";
  int c = 50;
  long double le = -32.3003;
  long int ld = -1020000;
  double e = -231.01;
  float f = 11.22;
  double g = 3243.323, G = 2315.324;
  long int lo = 324200;
  long unsigned int lu = 4, lx = 45, lX = 53434;
  sprintf(str1, format, 12, c, 20, ld, 11, 10, le, 11, 1, e, 13, f, 12, 2, g,
          13, 0, G, 16, lo, "\n f\0", 9, lu, 18, lx, 15, lX);
  s21_sprintf(str2, format, 12, c, 20, ld, 11, 10, le, 11, 1, e, 13, f, 12, 2,
              g, 13, 0, G, 16, lo, "\n f\0", 9, lu, 18, lx, 15, lX);
  ck_assert_str_eq(str1, str2);
}
END_TEST
