#include <check.h>
#include <string.h>

Suite *sflagsSuite();

START_TEST(flagsTest1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char fstr[] = "%ld %ld %ld %ld";
  const char str[] = "555 666 777 888";
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(flagsTest2) {
  short int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "3243 23432 3 322";
  const char fstr[] = "%hd %hd %hd %hi";
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(flagsTest3) {
  char s1[40] = "";
  char s2[40] = "";
  char s3[40] = "";
  char s4[40] = "";
  char sRes1[40] = "";
  char sRes2[40] = "";
  char sRes3[40] = "";
  char sRes4[40] = "";
  const char str[] = "StringS21 DecimalS21 Laggendas21 FinalExam21";
  const char fstr[] = "%4s%4s%4s%4s";
  int res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int res2 = sscanf(str, fstr, sRes1, sRes2, sRes3, sRes4);
  ck_assert_str_eq(s1, sRes1);
  ck_assert_str_eq(s2, sRes2);
  ck_assert_str_eq(s3, sRes3);
  ck_assert_str_eq(s4, sRes4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(flagsTest4) {
  int n1 = 5, n2 = 5;
  const char str[40] = "34 12 23 84";
  const char fstr[40] = "%n";
  int res1 = s21_sscanf(str, fstr, &n1);
  int res2 = sscanf(str, fstr, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(flagsTest5) {
  long double a1 = 0.0, a2 = 0.0, b1 = 0.0, b2 = 0.0, c1 = 0.0, c2 = 0.0,
              d1 = 0.0, d2 = 0.0;
  const char str[] = "5323.1 -2.15 62.334 +20.001";
  const char fstr[] = "%Lf %Lf %Lf %Lf";
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(flagsTest6) {
  float a1 = 0.0, a2 = 0.0, b1 = 0.0, b2 = 0.0, c1 = 0.0, c2 = 0.0, d1 = 0.0,
        d2 = 0.0;
  const char str[] = "5323.1 -2.15 62.334 +20.001";
  const char fstr[] = "%f %f %f %f";
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(flagsTest7) {
  float a1 = 0.0, a2 = 0.0, b1 = 0.0, b2 = 0.0, c1 = 0.0, c2 = 0.0;
  const char str[] = "+5323.1 -2.15 62.334 20.001";
  const char fstr[] = "%*f %f %f %f";
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(flagsTest8) {
  float a1 = 0.0, a2 = 0.0, b1 = 0.0, b2 = 0.0, c1 = 0.0, c2 = 0.0, d1 = 0.0,
        d2 = 0.0;
  const char str[] = "5.2255 0.12e+4 -321.01e-2 1.1223e-5";
  const char fstr[] = "%G %G %G %E";
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(flagsTest9) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-423 +333 -2 0";
  const char fstr[] = "%hu %hu %hu %hu";
  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(res1, res2);
}
END_TEST

START_TEST(flagsTest10) {
  unsigned long int a1 = 0, a2 = 0;
  const char str[] = "0xF";
  const char fstr[] = "%lX";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(flagsTest11) {
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%*X";
  int res1 = s21_sscanf(str, fstr);
  int res2 = sscanf(str, fstr);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(flagsTest12) {
  int a1 = 0, a2 = 0;
  const char str[] = "0xf";
  const char fstr[] = "%x";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(flagsTest13) {
  short unsigned int a1 = 0, a2 = 0;
  const char str[] = "0xfff";
  const char fstr[] = "%hx";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(flagsTest14) {
  unsigned long int a1, a2;
  const char str[] = "0xf";
  const char fstr[] = "%lx";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(flagsTest15) {
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%*x";
  int res1 = s21_sscanf(str, fstr);
  int res2 = sscanf(str, fstr);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(flagsTest16) {
  int a1 = 0, a2 = 0;
  const char str[] = "0x1331FFF";
  const char fstr[] = "%2X";
  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(flagsTest17) {
  int a1 = 0, a2 = 0;
  const char str[] = "043";
  const char fstr[] = "%o";
  s21_sscanf(str, fstr, &a1);
  sscanf(str, fstr, &a2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(flagsTest18) {
  short unsigned int a1 = 0, a2 = 0;
  const char str[] = "0832";
  const char fstr[] = "%ho";
  s21_sscanf(str, fstr, &a1);
  sscanf(str, fstr, &a2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(flagsTest19) {
  unsigned long int a1 = 0, a2 = 0;
  const char str[] = "0333333";
  const char fstr[] = "%lo";
  s21_sscanf(str, fstr, &a1);
  sscanf(str, fstr, &a2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(flagsTest20) {
  unsigned int a1 = 0, a2 = 0;
  const char str[] = "078532";
  const char fstr[] = "%2o";
  s21_sscanf(str, fstr, &a1);
  sscanf(str, fstr, &a2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(flagsTest21) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";
  s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST
