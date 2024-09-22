#include <check.h>
#include <string.h>

Suite *specifSuite();

START_TEST(specTest1) {
  char format[] = "Hello world! - 0";
  int a = -1;
  int b = -1;
  char str1[400] = {'\0'};
  char str2[400] = {'\0'};
  ;
  sscanf(format, "%s%d", str1, &a);
  s21_sscanf(format, "%s%d", str2, &b);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(specTest2) {
  char format[] = "Hello world!-5";
  int a = -1;
  int b = -1;
  char str1[400] = {'\0'};
  char str2[400] = {'\0'};
  ;
  sscanf(format, "%s%d", str1, &a);
  s21_sscanf(format, "%s%d", str2, &b);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(specTest3) {
  char format[] = "100 Hello world!";
  int a = -1;
  int b = -1;
  char str1[400] = {'\0'};
  char str2[400] = {'\0'};
  ;
  sscanf(format, "%d %s", &a, str1);
  s21_sscanf(format, "%d %s", &b, str2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(specTest4) {
  char format[] = " 4 \n -4";
  int a1 = -1, a2 = -1, b1 = -1, b2 = -1;
  char str1[400] = {'\0'};
  char str2[400] = {'\0'};
  ;
  sscanf(format, " %d%s%d", &a1, str1, &a2);
  s21_sscanf(format, " %d%s%d", &b1, str2, &b2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(specTest5) {
  char format[] = "Hello -4353465654 world!";
  int a1 = -1, b1 = -1;
  char stra1[400] = {'\0'};
  char stra2[400] = {'\0'};
  char strb1[400] = {'\0'};
  char strb2[400] = {'\0'};
  sscanf(format, "%s %d %s", stra1, &a1, stra2);
  s21_sscanf(format, "%s %d %s", strb1, &b1, strb2);

  ck_assert_str_eq(stra1, strb1);
  ck_assert_str_eq(stra2, strb2);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(specTest6) {
  char format[] = "45 3 3 -32";
  int a1 = -1, b1 = -1, a2 = -1, b2 = -1, a3 = -1, b3 = -1, a4 = -1, b4 = -1;
  sscanf(format, "%d %d %d %d", &a1, &a2, &a3, &a4);
  s21_sscanf(format, "%d %d %d %d", &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
}
END_TEST

START_TEST(specTest7) {
  char format[] = "Hello world! - t";
  char c1 = 1, d1 = 1;
  sscanf(format, "Hello world! - %c", &c1);
  s21_sscanf(format, "Hello world! - %c", &d1);
  ck_assert_int_eq(c1, d1);
}
END_TEST

START_TEST(specTest8) {
  char format[] = "Hello world! - 5";
  char c1 = 1, d1 = 1;
  sscanf(format, "Hello world! - %c", &c1);
  s21_sscanf(format, "Hello world! - %c", &d1);
  ck_assert_int_eq(c1, d1);
}
END_TEST

START_TEST(specTest9) {
  char format[] = "! Hello world!";
  char c1 = 1, d1 = 1;
  sscanf(format, "%c Hello world!", &c1);
  s21_sscanf(format, "%c Hello world!", &d1);
  ck_assert_int_eq(c1, d1);
}
END_TEST

START_TEST(specTest10) {
  char format[] = " 4\n>";
  char c1 = 1, d1 = 1, c2 = 1, d2 = 1;
  sscanf(format, " %c\n%c", &c1, &c2);
  s21_sscanf(format, " %c\n%c", &d1, &d2);
  ck_assert_int_eq(c1, d1);
  ck_assert_int_eq(c2, d2);
}
END_TEST

START_TEST(specTest11) {
  char format[] = " 4f|";
  char c1 = 1, d1 = 1, c2 = 1, d2 = 1, c3 = 1, d3 = 1, c4 = 1, d4 = 1;
  sscanf(format, "%c%c%c%c", &c1, &c2, &c3, &c4);
  s21_sscanf(format, "%c%c%c%c", &d1, &d2, &d3, &d4);
  ck_assert_int_eq(c1, d1);
  ck_assert_int_eq(c2, d2);
  ck_assert_int_eq(c3, d3);
  ck_assert_int_eq(c4, d4);
}
END_TEST

START_TEST(specTest12) {
  char format[] = "Hello world! - 5.5";
  float dl1 = 0.0, fl1 = 0.0;
  sscanf(format, "Hello world! - %f", &dl1);
  s21_sscanf(format, "Hello world! - %f", &fl1);
  ck_assert_double_eq(dl1, fl1);
}
END_TEST

START_TEST(specTest13) {
  char format[] = "-100.34 Hello world!";
  float dl1 = 0.0, fl1 = 0.0;
  sscanf(format, "%f Hello world!", &dl1);
  s21_sscanf(format, "%f Hello world!", &fl1);
  ck_assert_double_eq(dl1, fl1);
}
END_TEST

START_TEST(specTest14) {
  char format[] = " 5345.5\n-234.0";
  float dl1 = 0.0, fl1 = 0.0, dl2 = 0.0, fl2 = 0.0;
  sscanf(format, " %f\n%f", &dl1, &dl2);
  s21_sscanf(format, " %f\n%f", &fl1, &fl2);
  ck_assert_double_eq(dl1, fl1);
  ck_assert_double_eq(dl2, fl2);
}
END_TEST

START_TEST(specTest15) {
  char format[] = "Hello 3.023432 world!";
  float dl1 = 0.0, fl1 = 0.0;
  sscanf(format, "Hello %f world!", &dl1);
  s21_sscanf(format, "Hello %f world!", &fl1);
  ck_assert_double_eq(dl1, fl1);
}
END_TEST

START_TEST(specTest16) {
  char format[] = "-3.3 313.0432 0.0 1.12";
  float dl1 = 0.0, fl1 = 0.0, dl2 = 0.0, fl2 = 0.0, dl4 = 0.0, fl4 = 0.0,
        dl3 = 0.0, fl3 = 0.0;
  sscanf(format, "%f %f %f %f", &dl1, &dl2, &dl3, &dl4);
  s21_sscanf(format, "%f %f %f %f", &fl1, &fl2, &fl3, &fl4);
  ck_assert_double_eq(dl1, fl1);
  ck_assert_double_eq(dl2, fl2);
  ck_assert_double_eq(dl3, fl3);
  ck_assert_double_eq(dl4, fl4);
}
END_TEST

START_TEST(specTest17) {
  char format[] = "Hello world! - School21";
  char strRes1[400] = "";
  char str1[400] = "";
  sscanf(format, "Hello world! - %s", strRes1);
  s21_sscanf(format, "Hello world! - %s", str1);
  ck_assert_str_eq(strRes1, str1);
}
END_TEST

START_TEST(specTest18) {
  char format[] = "School21 Hello world!";
  char strRes1[400] = "";
  char str1[400] = "";
  sscanf(format, "%s Hello world!", strRes1);
  s21_sscanf(format, "%s Hello world!", str1);
  ck_assert_str_eq(strRes1, str1);
}
END_TEST

START_TEST(specTest19) {
  char format[] = " Giga \n School";
  char strRes1[400] = "";
  char str1[400] = "";
  char strRes2[400] = "";
  char str2[400] = "";
  sscanf(format, " %s \n %s", strRes1, strRes2);
  s21_sscanf(format, " %s \n %s", str1, str2);
  ck_assert_str_eq(strRes1, str1);
  ck_assert_str_eq(strRes2, str2);
}
END_TEST

START_TEST(specTest20) {
  char format[] = "Giga \n School 125553||?AZ!~";
  char strRes1[400] = "";
  char str1[400] = "";
  char strRes2[400] = "";
  char str2[400] = "";
  char strRes3[400] = "";
  char str3[400] = "";
  char strRes4[400] = "";
  char str4[400] = "";
  sscanf(format, "%s %s %s %s", strRes1, strRes2, strRes3, strRes4);
  s21_sscanf(format, " %s %s %s %s", str1, str2, str3, str4);
  ck_assert_str_eq(strRes1, str1);
  ck_assert_str_eq(strRes2, str2);
  ck_assert_str_eq(strRes3, str3);
  ck_assert_str_eq(strRes4, str4);
}
END_TEST

START_TEST(specTest21) {
  char format[] = "Hello world! - 4";
  unsigned int a1 = 0, b1 = 0;
  sscanf(format, "Hello world! - %u", &a1);
  s21_sscanf(format, "Hello world! - %u", &b1);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(specTest22) {
  char format[] = "45 Hello world!";
  unsigned int a1 = 0, b1 = 0;
  sscanf(format, "%u Hello world!", &a1);
  s21_sscanf(format, "%u Hello world!", &b1);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(specTest23) {
  char format[] = " 0 \n 32432";
  unsigned int a1 = 0, b1 = 0, a2 = 0, b2 = 0;
  sscanf(format, " %u \n %u", &a1, &a2);
  s21_sscanf(format, " %u \n %u", &b1, &b2);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(specTest24) {
  char format[] = "4 45 123 12355";
  unsigned int a1 = 0, b1 = 0, a2 = 0, b2 = 0, a3 = 0, b3 = 0, a4 = 0, b4 = 0;
  sscanf(format, "%u %u %u %u", &a1, &a2, &a3, &a4);
  s21_sscanf(format, "%u %u %u %u", &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
}
END_TEST

START_TEST(specTest25) {
  char format[] = "e 34 Hello world! - -456";
  char c1 = 3, cRes1 = 3;
  int u1 = 0, uRes1 = 0, d1 = 0, dRes1 = 0;
  char str1[40] = "";
  char strRes1[40] = "";
  sscanf(format, "%c %u %s world! - %d", &c1, &u1, str1, &d1);
  s21_sscanf(format, "%c %u %s world! - %d", &cRes1, &uRes1, strRes1, &dRes1);
  ck_assert_int_eq(c1, cRes1);
  ck_assert_int_eq(u1, uRes1);
  ck_assert_int_eq(d1, dRes1);
  ck_assert_str_eq(str1, strRes1);
}
END_TEST

START_TEST(specTest26) {
  char format[] = "-155\n0j=String";
  char c1 = 3, cRes1 = 3, c2 = 3, cRes2 = 3;
  int d1 = 0, dRes1 = 0, d2 = 0, dRes2 = 0;
  char str1[40] = "";
  char strRes1[40] = "";
  sscanf(format, "%d\n%d%c%c%s", &d1, &d2, &c1, &c2, str1);
  s21_sscanf(format, "%d\n%d%c%c%s", &dRes1, &dRes2, &cRes1, &cRes2, strRes1);
  ck_assert_int_eq(c1, cRes1);
  ck_assert_int_eq(c2, cRes2);
  ck_assert_int_eq(d1, dRes1);
  ck_assert_int_eq(d2, dRes2);
  ck_assert_str_eq(str1, strRes1);
}
END_TEST

START_TEST(specTest27) {
  char format[] = "%dHello String%f world!%u";
  int d1 = 0, dRes1 = 0, u1 = 0, uRes1 = 0;
  float f1 = 0.0, fRes1 = 0.0;
  char str1[40] = "";
  char strRes1[40] = "";
  sscanf(format, "%dHello %s%f world!%u", &d1, str1, &f1, &u1);
  s21_sscanf(format, "%dHello %s%f world!%u", &dRes1, strRes1, &fRes1, &uRes1);
  ck_assert_int_eq(d1, dRes1);
  ck_assert_int_eq(u1, uRes1);
  ck_assert_str_eq(str1, strRes1);
  ck_assert_float_eq(f1, fRes1);
}
END_TEST
