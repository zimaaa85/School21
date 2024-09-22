#include "s21_decimal.h"

void s21_floor_bcd(s21_bcd value, s21_bcd* result) {
  int scale = s21_get_scale_bcd(&value);
  int sign = s21_get_sign_bcd(&value);
  int cur_rank = 0, next_rank_plus = 0;
  for (int i = 0; i < scale; i++) {
    cur_rank = s21_get_rank(&value, 0) + next_rank_plus;
    if (sign == 1 && cur_rank > 0) {
      next_rank_plus = 1;
    } else {
      next_rank_plus = 0;
    }
    for (int j = 0; j < 4; j++) s21_right_shift_bcd(&value);
  }
  cur_rank = s21_get_rank(&value, 0);
  s21_set_rank(&value, 0, cur_rank + next_rank_plus);

  s21_set_scale_bcd(&value, 0);
  s21_copy_bcd(&value, result);
}

int s21_floor(s21_decimal value, s21_decimal* result) {
  int res = 0;
  s21_bcd value_bcd, result_bcd;
  s21_init_bcd(&value_bcd);
  s21_init_bcd(&result_bcd);
  s21_dec_to_bcd(&value, &value_bcd);
  s21_floor_bcd(value_bcd, &result_bcd);
  s21_bcd_to_dec(result, &result_bcd);
  return res;
}

void s21_round_bcd(s21_bcd value, s21_bcd* result) {
  int scale = s21_get_scale_bcd(&value);
  int sign = s21_get_sign_bcd(&value);
  int cur_rank = 0, next_rank_plus = 0;
  for (int i = 0; i < scale; i++) {
    cur_rank = s21_get_rank(&value, 0) + next_rank_plus;
    if (sign == 0 && cur_rank > 0) {
      next_rank_plus = 1;
    } else {
      next_rank_plus = 0;
    }
    for (int j = 0; j < 4; j++) s21_right_shift_bcd(&value);
  }
  cur_rank = s21_get_rank(&value, 0);
  s21_set_rank(&value, 0, cur_rank + next_rank_plus);

  s21_set_scale_bcd(&value, 0);
  s21_copy_bcd(&value, result);
}

int s21_round(s21_decimal value, s21_decimal* result) {
  int res = 0;
  s21_bcd value_bcd, result_bcd;
  s21_init_bcd(&value_bcd);
  s21_init_bcd(&result_bcd);
  s21_dec_to_bcd(&value, &value_bcd);
  s21_round_bcd(value_bcd, &result_bcd);
  s21_bcd_to_dec(result, &result_bcd);
  return res;
}

void s21_truncate_bcd(s21_bcd value, s21_bcd* result) {
  int scale = s21_get_scale_bcd(&value);
  for (int i = 0; i < scale; i++) {
    for (int j = 0; j < 4; j++) s21_right_shift_bcd(&value);
  }
  s21_set_scale_bcd(&value, 0);
  s21_copy_bcd(&value, result);
}

int s21_truncate(s21_decimal value, s21_decimal* result) {
  int res = 0;
  s21_bcd value_bcd, result_bcd;
  s21_init_bcd(&value_bcd);
  s21_init_bcd(&result_bcd);
  s21_dec_to_bcd(&value, &value_bcd);
  s21_truncate_bcd(value_bcd, &result_bcd);
  s21_bcd_to_dec(result, &result_bcd);
  return res;
}

int s21_negate(s21_decimal value, s21_decimal* result) {
  int res = 0;
  int sign = 0;
  sign = s21_get_sign_dec(value);
  s21_copy_dec(&value, result);
  if (sign == 0) {
    s21_set_sign_dec(result, 1);
  } else {
    s21_set_sign_dec(result, 0);
  }
  return res;
}