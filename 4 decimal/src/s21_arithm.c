#include "s21_decimal.h"

int s21_add(s21_decimal* value1, s21_decimal* value2, s21_decimal* value3) {
  int result = 0;
  s21_bcd value_bcd1 = {{0, 0, 0, 0}, 0};
  s21_bcd value_bcd2 = {{0, 0, 0, 0}, 0};
  s21_bcd value_bcd3 = {{0, 0, 0, 0}, 0};
  s21_init_bcd(&value_bcd3);
  s21_init_dec(value3);
  s21_convert_norm_to_bcd(value1, value2, &value_bcd1, &value_bcd2);
  result = s21_sum_bcd(value_bcd1, value_bcd2, &value_bcd3);
  if (result == 0) s21_bcd_to_dec(value3, &value_bcd3);
  return result;
}

int s21_sub(s21_decimal* value1, s21_decimal* value2, s21_decimal* value3) {
  int result = 0;
  s21_bcd value_bcd1 = {{0, 0, 0, 0}, 0};
  s21_bcd value_bcd2 = {{0, 0, 0, 0}, 0};
  s21_bcd value_bcd3 = {{0, 0, 0, 0}, 0};
  s21_init_bcd(&value_bcd3);
  s21_init_dec(value3);
  s21_convert_norm_to_bcd(value1, value2, &value_bcd1, &value_bcd2);
  result = s21_sub_bcd(value_bcd1, value_bcd2, &value_bcd3);
  s21_bcd_to_dec(value3, &value_bcd3);
  return result;
}

int s21_mul(s21_decimal* value1, s21_decimal* value2, s21_decimal* value3) {
  int result = 0;
  s21_bcd value_bcd1 = {{0, 0, 0, 0}, 0};
  s21_bcd value_bcd2 = {{0, 0, 0, 0}, 0};
  s21_bcd value_bcd3 = {{0, 0, 0, 0}, 0};
  s21_init_dec(value3);
  s21_convert_norm_to_bcd(value1, value2, &value_bcd1, &value_bcd2);
  result = s21_mult_bcd(value_bcd1, value_bcd2, &value_bcd3);
  s21_bcd_to_dec(value3, &value_bcd3);
  return result;
}

int s21_div(s21_decimal* value1, s21_decimal* value2, s21_decimal* value3) {
  int result = 0;
  s21_bcd value_bcd1 = {{0, 0, 0, 0}, 0};

  s21_bcd value_bcd2 = {{0, 0, 0, 0}, 0};

  s21_bcd value_bcd3 = {{0, 0, 0, 0}, 0};

  s21_init_dec(value3);
  s21_dec_to_bcd(value1, &value_bcd1);
  s21_dec_to_bcd(value2, &value_bcd2);
  result = s21_div_bcd(value_bcd1, value_bcd2, &value_bcd3);
  s21_bcd_to_dec(value3, &value_bcd3);
  return result;
}

void s21_reverse_bcd(const s21_bcd* value, s21_bcd* new_value) {
  s21_copy_bcd(value, new_value);
  int cur_rank = 0;
  for (int i = 0; i < ((int)sizeof(new_value->bits) * BYTE / 4) - 3; i++) {
    cur_rank = s21_get_rank(value, i);
    if (i == 0) {
      cur_rank = 10 - cur_rank;
    } else {
      cur_rank = 9 - cur_rank;
    }
    s21_set_rank(new_value, i, cur_rank);
  }
  s21_rank_full_bcd(new_value);
}

int s21_sum_bcd(s21_bcd value_bcd1, s21_bcd value_bcd2, s21_bcd* value_bcd3) {
  int result = 0;
  s21_bcd res_bcd = {{0, 0, 0, 0}, 0};
  s21_normalize_bcd(&value_bcd1, &value_bcd2);
  s21_init_bcd(value_bcd3);
  if (s21_get_sign_bcd(&value_bcd1) == s21_get_sign_bcd(&value_bcd2)) {
    res_bcd.sign_exp = value_bcd2.sign_exp;
    result = s21_mant_sum_bcd(&value_bcd1, &value_bcd2, &res_bcd);
  } else {
    s21_bcd buf_bcd = {{0, 0, 0, 0}, 0};
    if (s21_greater_mant_bcd(value_bcd1, value_bcd2) == 1) {
      res_bcd.sign_exp = value_bcd1.sign_exp;
      s21_reverse_bcd(&value_bcd2, &buf_bcd);
      result = s21_mant_sum_bcd(&buf_bcd, &value_bcd1, &res_bcd);
    } else {
      res_bcd.sign_exp = value_bcd2.sign_exp;
      s21_reverse_bcd(&value_bcd1, &buf_bcd);
      result = s21_mant_sum_bcd(&buf_bcd, &value_bcd2, &res_bcd);
    }
  }
  s21_zero_bcd(&res_bcd);
  if (result == 0) s21_copy_bcd(&res_bcd, value_bcd3);
  return result;
}

int s21_sub_bcd(s21_bcd value_bcd1, s21_bcd value_bcd2, s21_bcd* value_bcd3) {
  int result = 0;
  s21_bcd res = {{0, 0, 0, 0}, 0};
  s21_normalize_bcd(&value_bcd1, &value_bcd2);
  s21_init_bcd(value_bcd3);
  if (s21_get_sign_bcd(&value_bcd1) != s21_get_sign_bcd(&value_bcd2)) {
    res.sign_exp = value_bcd1.sign_exp;
    result = s21_mant_sum_bcd(&value_bcd1, &value_bcd2, &res);
  } else {
    s21_bcd buf_bcd = {{0, 0, 0, 0}, 0};
    if (s21_greater_mant_bcd(value_bcd1, value_bcd2) == 1) {
      res.sign_exp = value_bcd1.sign_exp;
      s21_reverse_bcd(&value_bcd2, &buf_bcd);
      result = s21_mant_sum_bcd(&buf_bcd, &value_bcd1, &res);
    } else {
      res.sign_exp = value_bcd2.sign_exp;
      s21_negate_bcd(&res);
      s21_reverse_bcd(&value_bcd1, &buf_bcd);
      result = s21_mant_sum_bcd(&buf_bcd, &value_bcd2, &res);
    }
  }
  s21_zero_bcd(&res);
  s21_drop_zeros(&res);
  if (result == 0) {
    s21_copy_bcd(&res, value_bcd3);
  }

  return result;
}

// Добавить обработку ошибок переполнения децимала
int s21_mant_sum_bcd(const s21_bcd* value_bcd1, const s21_bcd* value_bcd2,
                     s21_bcd* res_value_bcd3) {
  int result = 0;
  int cur_rank1 = 0, cur_rank2 = 0, cur_rank3 = 0, next_rank_plus = 0;
  s21_bcd value_bcd3 = {{0, 0, 0, 0}, 0};
  for (int i = 0; i < (int)sizeof(value_bcd1->bits) * BYTE / 4 - 3; i++) {
    cur_rank1 = s21_get_rank(value_bcd1, i);
    cur_rank2 = s21_get_rank(value_bcd2, i);
    cur_rank3 = cur_rank1 + cur_rank2 + next_rank_plus;
    next_rank_plus = 0;
    if (cur_rank3 >= 10) {
      cur_rank3 -= 10;
      next_rank_plus++;
    }
    s21_set_rank(&value_bcd3, i, cur_rank3);
  }
  result = s21_bank_round_bcd(&value_bcd3, LEFT_RANK);
  if (result == 0) {
    s21_copy_mant_bcd(&value_bcd3, res_value_bcd3);
  }

  return result;
}

int s21_mult_num_bcd(const s21_bcd* value_bcd1, s21_bcd* res, int num) {
  int result;
  s21_bcd value_bcd2 = {{0, 0, 0, 0}, 0};
  value_bcd2.sign_exp = res->sign_exp;
  int cur_rank = 0, next_rank_plus = 0;
  for (int i = 0; i < (int)sizeof(value_bcd1->bits) * BYTE / 4 - 3; i++) {
    cur_rank = s21_get_rank(value_bcd1, i);
    cur_rank = cur_rank * num + next_rank_plus;
    next_rank_plus = 0;
    for (int i = 0; i < cur_rank / 10; i++) {
      next_rank_plus++;
    }
    cur_rank -= next_rank_plus * 10;
    s21_set_rank(&value_bcd2, i, cur_rank);
  }
  result = s21_bank_round_bcd(&value_bcd2, LEFT_RANK);
  if (result == 0) s21_copy_bcd(&value_bcd2, res);

  return result;
}

int s21_mult_bcd(s21_bcd value_bcd1, s21_bcd value_bcd2, s21_bcd* value_bcd3) {
  int res = 0;
  res = s21_normalize_bcd(&value_bcd1, &value_bcd2);
  s21_bcd buff_bcd = {{0, 0, 0, 0}, 0}, buff_bcd2 = {{0, 0, 0, 0}, 0};
  s21_init_bcd(&buff_bcd);
  s21_init_bcd(&buff_bcd2);
  s21_bcd result = {{0, 0, 0, 0}, 0};
  s21_init_bcd(&result);
  int new_scale =
      s21_get_scale_bcd(&value_bcd1) + s21_get_scale_bcd(&value_bcd2);
  int new_sign = s21_get_sign_bcd(&value_bcd1) ^ s21_get_sign_bcd(&value_bcd2);
  s21_set_scale_bcd(&buff_bcd, new_scale);
  s21_set_scale_bcd(&buff_bcd2, new_scale);
  s21_set_sign_bcd(&buff_bcd, new_sign);
  s21_set_sign_bcd(&buff_bcd2, new_sign);
  int cur_rank_value_2 = 0;
  for (int i = 0; i < (int)sizeof(value_bcd1.bits) * BYTE / 4 - 3 && res == 0;
       i++) {
    s21_set_scale_bcd(&buff_bcd, new_scale);
    cur_rank_value_2 = s21_get_rank(&value_bcd2, i);
    if (cur_rank_value_2 == 0) continue;
    res = s21_mult_num_bcd(&value_bcd1, &buff_bcd, cur_rank_value_2);
    for (int j = 0; j < i * 4 && res == 0; j++) {
      if (j % 4 == 0) {
        res = s21_bank_round_bcd(&buff_bcd, LEFT_RANK);
      }
      s21_left_shift_bcd(&buff_bcd);
    }
    s21_drop_zeros(&buff_bcd);
    res = s21_sum_bcd(buff_bcd, buff_bcd2, &result);
    s21_drop_zeros(&result);
    s21_copy_bcd(&result, &buff_bcd2);
  }
  s21_drop_zeros(&result);
  if (res == 0) s21_copy_bcd(&result, value_bcd3);
  return res;
}

int s21_div_bcd(s21_bcd value_bcd1, s21_bcd value_bcd2, s21_bcd* value_bcd3) {
  int res = 0;
  if (s21_zero_bcd(&value_bcd2) == 1) {
    res = 3;
    return res;
  }
  s21_bcd buff_bcd1 = {{0, 0, 0, 0}, 0};
  s21_bcd buff_bcd2 = {{0, 0, 0, 0}, 0};
  s21_bcd result = {{0, 0, 0, 0}, 0};
  s21_init_bcd(&result);
  int new_scale =
      s21_get_scale_bcd(&value_bcd1) - s21_get_scale_bcd(&value_bcd2);
  int new_sign = s21_get_sign_bcd(&value_bcd1) ^ s21_get_sign_bcd(&value_bcd2);
  s21_set_scale_bcd(&buff_bcd1, 0);
  s21_set_sign_bcd(&buff_bcd1, 0);
  s21_set_sign_bcd(&value_bcd2, 0);
  s21_set_sign_bcd(&value_bcd1, 0);
  s21_set_scale_bcd(&value_bcd1, 0);
  s21_set_scale_bcd(&value_bcd2, 0);
  s21_set_scale_bcd(&result, 0);
  int cur_num = 0, cur_scale = 0, is_v1_more_v2 = 0;
  int is_stop = 1;
  for (int i = 0;
       i < (int)sizeof(value_bcd1.bits) * BYTE / 4 - 3 && is_stop && res == 0;
       i++) {
    while (s21_greater_mant_bcd(value_bcd2, value_bcd1) == 1) {
      for (int j = 0; j < 4; j++) s21_left_shift_bcd(&value_bcd1);
      cur_scale++;
    }
    while (s21_greater_mant_bcd(value_bcd1, value_bcd2) == 1) {
      for (int j = 0; j < 4; j++) s21_left_shift_bcd(&value_bcd2);
      is_v1_more_v2++;
    }
    if (is_v1_more_v2 > 0) {
      for (int j = 0; j < 4; j++) s21_right_shift_bcd(&value_bcd2);
      is_v1_more_v2--;
    }

    for (int j = 9; j >= 0; j--) {
      s21_copy_bcd(&value_bcd2, &buff_bcd2);
      res = s21_mult_num_bcd(&buff_bcd2, &buff_bcd2, j);
      if (s21_equal_mant_bcd(buff_bcd2, value_bcd1)) {
        cur_num = j;
        is_stop = 0;
        break;
      }
      if (s21_greater_mant_bcd(value_bcd1, buff_bcd2) == 1) {
        cur_num = j;
        break;
      }
    }

    while (is_v1_more_v2 > 0) {
      for (int j = 0; j < 4; j++) s21_right_shift_bcd(&value_bcd2);
      is_v1_more_v2--;
    }

    res = s21_sub_bcd(value_bcd1, buff_bcd2, &value_bcd1);
    new_scale += cur_scale;
    if (new_scale == 28) {
      is_stop = 0;
    }
    if (new_scale > 28) {
      cur_scale = 28 - (new_scale - cur_scale);
      new_scale = 28;
      cur_num = 0;
      is_stop = 0;
    }
    if (cur_scale == 0) cur_scale++;
    for (int j = 0; j < 4 * cur_scale; j++) s21_left_shift_bcd(&result);
    result.bits[0] = result.bits[0] + cur_num;
    cur_scale = 0;
    cur_num = 0;
    s21_rank_full_bcd(&result);
  }

  s21_set_sign_bcd(&result, new_sign);
  s21_set_scale_bcd(&result, new_scale);
  if (res == 0) s21_copy_bcd(&result, value_bcd3);
  return res;
}