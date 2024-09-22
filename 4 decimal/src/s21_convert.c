#include <limits.h>
#include <stdlib.h>

#include "s21_decimal.h"

//Конверт инт в децимал
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int result = 0;
  if (!dst)
    result = 0;
  else if (abs(src) <= INT_MAX) {
    s21_init_dec(dst);
    int sign = src;
    if (src < 0) src = -src;
    dst->bits[0] = src;
    if (sign < 0) s21_set_sign_dec(dst, 1);
    result = 1;
  }
  return result;
}

//Конверт децимал в инт
int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int result = 0;
  if (!dst)
    result = 0;
  else if (src.bits[1] || src.bits[2] == 0) {
    int scale = s21_get_scale_dec(src);
    *dst = src.bits[0];
    if (scale) *dst /= pow(10, scale);
    if (s21_get_sign_dec(src) == 1) *dst = -(*dst);
    result = 1;
  }
  return result;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int result = 0;
  if (!dst) {
    result = 0;
  } else if (isinf(src) || isnan(src))
    result = 0;
  else if (src <= 79228157791897854723898736640.0f &&
           src >= 0.0000000000000000000000000001) {
    float sign = src;
    if (sign < 0) src = -src;
    s21_init_dec(dst);
    float mantissa = 0;
    int scale = 0;
    while (modff(src, &mantissa) != 0) {
      scale++;
      src *= 10;
    }
    while (src >= 10000000) {
      src /= 10;
      scale--;
    }
    dst->bits[0] = (int)src;
    s21_set_scale_dec(dst, scale);
    if (sign < 0) s21_set_sign_dec(dst, 1);
    result = 1;
  }
  return result;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int result = 0;
  if (!dst)
    result = 0;
  else {
    for (int i = 0; i <= 96; ++i) {
      *dst += (s21_get_bit_dec(src, i) * pow(2.0, i));
    }
    *dst = *dst / pow(10, s21_get_scale_dec(src));
    if (s21_get_sign_dec(src)) *dst = *dst * -1;
    result = 1;
  }
  return result;
}