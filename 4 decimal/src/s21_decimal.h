#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <math.h>
#include <stdio.h>

#include <check.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>


// Можно ли использовать unsigned?????
typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[4];
  unsigned int sign_exp;
} s21_bcd;

#define RANK 0x0000000F
#define RIGHT 0x00000001
#define BYTE 8
#define LEFT_RANK 3
#define LEFT_RANK 3

int s21_get_bit_dec(s21_decimal value, int position);
void s21_set_bit_dec(s21_decimal* value, int position, int bit);
void s21_set_bit(unsigned int* byte, int position, int bit);
int s21_get_bit(unsigned int byte, int position);
void s21_init_dec(s21_decimal* value);
int s21_get_sign_dec(s21_decimal value);
void s21_set_sign_dec(s21_decimal* value, int sign);
int s21_get_scale_dec(s21_decimal value);
void s21_set_scale_dec(s21_decimal* value, int scale);
void s21_copy_dec(s21_decimal* src_value, s21_decimal* dest_value);
int s21_left_shift_int(unsigned int* value);
int s21_right_shift_int(unsigned int* value);

int s21_zero_bcd(s21_bcd* value);
void s21_drop_zeros(s21_bcd* value);
int s21_negate_bcd(s21_bcd* value);
int s21_zero_bcd(s21_bcd* value);
int s21_negate_bcd(s21_bcd* value);
int s21_left_shift_bcd(s21_bcd* value);
int s21_right_shift_bcd(s21_bcd* value);
int s21_left_shift_dec(s21_decimal* value);
int s21_right_shift_dec(s21_decimal* value);
int s21_get_sign_bcd(const s21_bcd* value);
int s21_get_sign_bcd(const s21_bcd* value);
void s21_set_bit_bcd(s21_bcd* value, int new_bit);
int s21_get_rank(const s21_bcd* value, int rank_index);
void s21_set_rank(s21_bcd* value, int rank_index, int rank_value);
void s21_chek_bcd_conv_to(s21_bcd* value);
void s21_chek_bcd_conv_from(s21_bcd* value);
void s21_init_bcd(s21_bcd* value);
int s21_dec_to_bcd(s21_decimal* value, s21_bcd* new_value);
int s21_bcd_to_dec(s21_decimal* value, const s21_bcd* new_value);
int s21_bcd_to_dec(s21_decimal* value, const s21_bcd* new_value);
void s21_rank_full_bcd(s21_bcd* value);
int s21_check_full_bcd(s21_bcd* value, int indx);
int s21_bank_round_bcd(s21_bcd* value, int indx);
void s21_copy_mant_bcd(const s21_bcd* value, s21_bcd* new_value);
int s21_check_full_bcd(s21_bcd* value, int indx);
int s21_bank_round_bcd(s21_bcd* value, int indx);
void s21_copy_mant_bcd(const s21_bcd* value, s21_bcd* new_value);

int s21_get_scale_bcd(const s21_bcd* value);
void s21_set_scale_bcd(s21_bcd* value, int scale);
int s21_normalize_bcd(s21_bcd* value1, s21_bcd* value2);
int s21_normalize_bcd(s21_bcd* value1, s21_bcd* value2);
void s21_convert_norm_to_bcd(s21_decimal* value1, s21_decimal* value2,
                             s21_bcd* value_bcd1, s21_bcd* value_bcd2);

int s21_is_zero(s21_decimal value);
int s21_is_zero(s21_decimal value);
int s21_greater_mant_bcd(s21_bcd value1, s21_bcd value2);
int s21_equal_mant_bcd(s21_bcd value1, s21_bcd value2);
int s21_is_greater(s21_decimal value1, s21_decimal value2);
int s21_is_equal(s21_decimal value1, s21_decimal value2);
int s21_is_not_equal(s21_decimal value1, s21_decimal value2);
int s21_is_greater_or_equal(s21_decimal value1, s21_decimal value2);
int s21_is_less(s21_decimal value1, s21_decimal value2);
int s21_is_less_or_equal(s21_decimal value1, s21_decimal value2);

void s21_copy_bcd(const s21_bcd* value, s21_bcd* new_value);
void s21_sum_dec(s21_decimal* value1, s21_decimal* value2, s21_decimal* value3);
void s21_set_sign_bcd(s21_bcd* value, int sign);
void s21_reverse_bcd(const s21_bcd* value, s21_bcd* new_value);
int s21_sum_bcd(s21_bcd value_bcd1, s21_bcd value_bcd2, s21_bcd* value_bcd3);
int s21_sub_bcd(s21_bcd value_bcd1, s21_bcd value_bcd2, s21_bcd* value_bcd3);
int s21_mant_sum_bcd(const s21_bcd* value_bcd1, const s21_bcd* value_bcd2,
                     s21_bcd* value_bcd3);
int s21_mult_num_bcd(const s21_bcd* value_bcd1, s21_bcd* res, int num);
int s21_mult_bcd(s21_bcd value_bcd1, s21_bcd value_bcd2, s21_bcd* value_bcd3);
int s21_div_bcd(s21_bcd value_bcd1, s21_bcd value_bcd2, s21_bcd* value_bcd3);

int s21_div(s21_decimal* value1, s21_decimal* value2, s21_decimal* value3);
int s21_mul(s21_decimal* value1, s21_decimal* value2, s21_decimal* value3);
int s21_sub(s21_decimal* value1, s21_decimal* value2, s21_decimal* value3);
int s21_add(s21_decimal* value1, s21_decimal* value2, s21_decimal* value3);

int s21_floor(s21_decimal value, s21_decimal* result);
void s21_floor_bcd(s21_bcd value, s21_bcd* result);
int s21_round(s21_decimal value, s21_decimal* result);
void s21_round_bcd(s21_bcd value, s21_bcd* result);
int s21_truncate(s21_decimal value, s21_decimal* result);
void s21_truncate_bcd(s21_bcd value, s21_bcd* result);
int s21_negate(s21_decimal value, s21_decimal* result);

// функции конверта
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);


#endif
