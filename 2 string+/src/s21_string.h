#ifndef S21_STRING_H
#define S21_STRING_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long s21_size_t;
#define s21_NULL (void *)0

typedef struct Specifier {
  int star;
  char name;
  char len;
  int wide;
} Specifier;

s21_size_t s21_strlen(const char *str);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *append, s21_size_t n);
char *s21_strerror(int errnum);
char *s21_strchr(const char *str, int c);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *s, const char *delim);
s21_size_t s21_strspn(const char *str1, const char *str2);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

typedef struct Flags {
  bool plus;
  bool minus;
  bool space;
  bool sharp;
  bool zero;
  s21_size_t star;
  s21_size_t wide;
  s21_size_t prec_value;
  bool precision;
  bool long_int;
  bool short_int;
  bool long_double;
  bool e_big;
  bool g_flag;
  bool x_big;
} Flags;

void s21_strcpy(char *buf, char *str);
void s21_reverse(char s[]);
void s21_itoa(int n, char s[]);
void s21_litoa(long int n, char s[]);
void s21_uitoa(unsigned int n, char s[]);
int s21_atoi(char *str);
void s21_ftoa(long double n, char *s, unsigned int prec);
void s21_gftoa(double n, char *s, unsigned int prec);
int s21_sprintf(char *buf, const char *format, ...);
void s21_ptrtoa(intptr_t *p, char *str);

void s21_spec_parse(const char *format, int *format_start_index,
                    Specifier *spec);
int s21_sscanf(const char *str, const char *format, ...);
int s21_aply_spec(const char *str, int *start_index, Specifier *spec,
                  va_list varg);
int s21_integer_find(const char *str, int *start_index, char int_type,
                     Specifier *spec);
int s21_double_find(const char *str, int *start_index, Specifier *spec);
long long int s21_get_int_num(const char *str, int *start_index, char int_type,
                              Specifier *spec);
int s21_char_to_num(char c);
long double s21_get_double_num(const char *str, int *start_index,
                               Specifier *spec);
int s21_get_element_sing_int(const char *str, int *start_index, Specifier *spec,
                             va_list varg, char type_int);
int s21_get_element_unsing_int(const char *str, int *start_index,
                               Specifier *spec, va_list varg, char type_int);
int s21_get_element_double(const char *str, int *start_index, Specifier *spec,
                           va_list varg);
void s21_skip_char(const char *str, int *start_index);

#endif
