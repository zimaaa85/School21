#include "s21_decimal.h"

// возвращает бит из децимала по его позиции (0-127)
int s21_get_bit_dec(s21_decimal value, int position) {
  int result = 0;
  int index = position / 32;
  int shift = position % 32;
  if ((value.bits[index] & (1 << shift)) != 0) {
    result = 1;
  }
  return result;
}

// задает бит в децимале по его позиции (0-127)
void s21_set_bit_dec(s21_decimal* value, int position, int bit) {
  int index = position / 32;
  int shift = position % 32;
  if (bit == 1) {
    value->bits[index] = value->bits[index] | (1 << shift);
  } else if (bit == 0) {
    value->bits[index] = value->bits[index] & ~(1 << shift);
  }
}

// задает бит в инте по его позиции
void s21_set_bit(unsigned int* byte, int position, int bit) {
  if (bit == 1) {
    *byte |= bit << position;
  } else if (bit == 0) {
    bit = 1;
    *byte &= ~(bit << position);
  }
}

// возвразащает бит из инта по его позиции
int s21_get_bit(unsigned int byte, int position) {
  int mask = RIGHT;
  byte = byte >> position;
  mask &= byte;
  return mask;
}

// инициализирует децимал 0-ми, с 0-127 бит
void s21_init_dec(s21_decimal* value) {
  for (int i = 0; i < 128; i++) {
    s21_set_bit_dec(value, i, 0);
  }
}

// возвращает знак децимала 0 - положительный, 1 - отрицательный
int s21_get_sign_dec(s21_decimal value) {
  int result = 1;
  if ((value.bits[3] & (1 << 31)) == 0) {
    result = 0;
  }
  return result;
}

// устанавливает знак децимала 0 - положительный, 1 - отрицательный
void s21_set_sign_dec(s21_decimal* value, int sign) {
  if (sign == 1) {
    value->bits[3] = value->bits[3] | (1 << 31);
  } else if (sign == 0) {
    value->bits[3] = value->bits[3] & ~(1 << 31);
  }
}

// возвращает знак децимала 0 - положительный, 1 - отрицательный
int s21_get_sign_bcd(const s21_bcd* value) {
  int result = 1;
  if ((value->sign_exp & (1 << 31)) == 0) {
    result = 0;
  }
  return result;
}

// устанавливает знак децимала 0 - положительный, 1 - отрицательный
void s21_set_sign_bcd(s21_bcd* value, int sign) {
  if (sign == 1) {
    value->sign_exp = value->sign_exp | (1 << 31);
  } else if (sign == 0) {
    value->sign_exp = value->sign_exp & ~(1 << 31);
  }
}

// возвращает степень децимала, которая хранится в битах с 16-23
// Нужно ли устанавливать ограничение, что степень до 28????
// В 8 битов можно сохранить бОльшую степень
int s21_get_scale_dec(s21_decimal value) {
  int result = 0;
  int shift = 16;
  for (int i = 0; shift < 24; ++i) {
    int bit = ((value.bits[3] & (1 << shift)) != 0);
    result += bit * pow(2, i);
    shift++;
  }
  return result;
}

// устанавливает степень децимала, которая хранится в битах с 16-23
void s21_set_scale_dec(s21_decimal* value, int scale) {
  int shift = 16;
  for (int i = 0; shift < 24; ++i) {
    if (scale % 2 == 1 && scale != 0) {
      value->bits[3] = value->bits[3] | (1 << shift);
    } else {
      value->bits[3] = value->bits[3] & ~(1 << shift);
    }
    shift++;
    scale /= 2;
  }
}

// сдвигает инт влево
int s21_left_shift_int(unsigned int* value) {
  int result = 0;
  result |= s21_get_bit(*value, 31);
  *value = *value << 1;
  return result;
}

// сдвигает инт вправо
int s21_right_shift_int(unsigned int* value) {
  int result = 0;
  result |= s21_get_bit(*value, 0);
  *value = *value >> 1;
  return result;
}

// копирует децимал в другой децимал
void s21_copy_dec(s21_decimal* src_value, s21_decimal* dest_value) {
  for (int i = 0; i < 4; i++) {
    dest_value->bits[i] = src_value->bits[i];
  }
}

// сдвигает влево бцд
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!(по-моему неправильно)
int s21_left_shift_bcd(s21_bcd* value) {
  int bit = 0, bit_buf = 0;
  for (int i = 0; i < (int)(sizeof(value->bits) / sizeof(int)); i++) {
    bit_buf = s21_left_shift_int(&value->bits[i]);
    if (i > 0) {
      s21_set_bit(&value->bits[i], 0, bit);
    }
    bit = bit_buf;
  }
  return bit_buf;
}

// сдвигает вправо бцд
int s21_right_shift_bcd(s21_bcd* value) {
  int bit = 0, bit_buf = 0;
  for (int i = (sizeof(value->bits) / sizeof(int)) - 1; i >= 0; i--) {
    bit_buf = s21_right_shift_int(&value->bits[i]);
    if (i < (int)(sizeof(value->bits) / sizeof(int)) - 1) {
      s21_set_bit(&value->bits[i], 31, bit);
    }
    bit = bit_buf;
  }
  return bit_buf;
}

// Сдвиг децимала влево
int s21_left_shift_dec(s21_decimal* value) {
  int bit = 0, bit_buf = 0;
  for (int i = 0; i < (int)(sizeof(value->bits) / sizeof(int)) - 1; i++) {
    bit_buf = s21_left_shift_int(&value->bits[i]);
    if (i > 0) {
      s21_set_bit(&value->bits[i], 0, bit);
    }
    bit = bit_buf;
  }
  return bit;
}

// Сдвиг децимала враво
int s21_right_shift_dec(s21_decimal* value) {
  int bit = 0, bit_buf = 0, result = 0;
  for (int i = (int)(sizeof(value->bits) / sizeof(int)) - 2; i >= 0; i--) {
    bit_buf = s21_right_shift_int(&value->bits[i]);
    if (i < (int)(sizeof(value->bits) / sizeof(int)) * BYTE - 1) {
      s21_set_bit(&value->bits[i], 31, bit);
    }
    // потеря бита с права, надо ли выбрасывать ошибку?
    if (i == 0 && bit_buf == 1) {
      result = -1;
    }
    bit = bit_buf;
  }
  return result;
}

void s21_set_bit_bcd(s21_bcd* value, int new_bit) {
  // int bit_buf = s21_left_shift_bcd(value); full
  s21_left_shift_bcd(value);
  value->bits[0] |= new_bit;
}

int s21_get_rank(const s21_bcd* value, int rank_index) {
  int cur_rank_byte = rank_index / BYTE;
  int cur_rank_bit = rank_index % BYTE;
  int mask = (RANK) << (cur_rank_bit * 4);
  int result = (value->bits[cur_rank_byte] & mask) >> (cur_rank_bit * 4);
  return result;
}
void s21_set_rank(s21_bcd* value, int rank_index, int rank_value) {
  int cur_rank_byte = rank_index / BYTE;
  int cur_rank_bit = rank_index % BYTE;
  int mask = RANK << (cur_rank_bit * 4);
  rank_value = rank_value << (cur_rank_bit * 4);
  value->bits[cur_rank_byte] &= ~mask;
  value->bits[cur_rank_byte] |= rank_value;
}

void s21_chek_bcd_conv_to(s21_bcd* value) {
  int num_buff = 0;
  for (int i = ((int)sizeof(value->bits) / sizeof(int)) * 8 - 1; i >= 0; i--) {
    num_buff = s21_get_rank(value, i);
    if (num_buff > 4) {
      num_buff += 3;
    }
    s21_set_rank(value, i, num_buff);
  }
}

void s21_chek_bcd_conv_from(s21_bcd* value) {
  int num_buff = 0;
  for (int i = ((int)sizeof(value->bits) / sizeof(int)) * 8 - 1; i >= 0; i--) {
    num_buff = s21_get_rank(value, i);
    if (num_buff >= 8) {
      num_buff -= 3;
    }
    s21_set_rank(value, i, num_buff);
  }
}

void s21_init_bcd(s21_bcd* value) {
  for (int i = 0; i < (int)(sizeof(value->bits) / sizeof(int)); i++) {
    value->bits[i] = 0;
  }
  value->sign_exp = 0;
}

int s21_dec_to_bcd(s21_decimal* value, s21_bcd* new_value) {
  int res = 0;
  s21_decimal value_dec;
  s21_copy_dec(value, &value_dec);
  s21_init_bcd(new_value);
  new_value->sign_exp = value_dec.bits[3];
  int bit_buf = 0;
  for (int i = 0; i < (((int)sizeof(value_dec.bits) - 4) * BYTE); i++) {
    bit_buf = s21_left_shift_dec(&value_dec);
    s21_set_bit_bcd(new_value, bit_buf);
    if (i < (((int)sizeof(value_dec.bits) - 4) * BYTE) - 1)
      s21_chek_bcd_conv_to(new_value);
  }
  return res;
}

int s21_bcd_to_dec(s21_decimal* value, const s21_bcd* new_value) {
  int res = 0;
  s21_init_dec(value);
  value->bits[3] = new_value->sign_exp;
  s21_bcd value_bcd;
  s21_copy_bcd(new_value, &value_bcd);
  int bit_buf = 0;
  for (int i = 0; i < (((int)sizeof(value->bits) - 4) * BYTE); i++) {
    bit_buf = s21_right_shift_bcd(&value_bcd);
    s21_right_shift_dec(value);
    s21_set_bit(&value->bits[2], 31, bit_buf);
    s21_chek_bcd_conv_from(&value_bcd);
  }
  return res;
}

// функция для исправление каждого разряда бцд
void s21_rank_full_bcd(s21_bcd* value) {
  int cur_rank = 0, next_rank = 0;
  for (int i = 0; i < (int)sizeof(value->bits) * BYTE / 4; i++) {
    cur_rank = s21_get_rank(value, i) + next_rank;
    if (cur_rank > 10) {
      cur_rank -= 10;
      next_rank = 1;
    } else {
      next_rank = 0;
    }
    s21_set_rank(value, i, cur_rank);
  }
}

// Проверка на переполнение старших 3 разрядов(4 бита)
int s21_check_full_bcd(s21_bcd* value, int indx) {
  int result = 0;
  for (int i = ((int)sizeof(value->bits) * BYTE) / 4 - 1; i > 31 - indx; i--) {
    result = s21_get_rank(value, i);
    if (result != 0) {
      result = i;
      break;
    }
  }
  return result;
}

// Банковское округление бцд
int s21_bank_round_bcd(s21_bcd* cur_value, int indx) {
  s21_bcd value;
  s21_copy_bcd(cur_value, &value);
  int cur_rank = 0, last_rank = 0, first_index_rank = 0, scale = 0, result = 0;
  int full_bcd = s21_check_full_bcd(&value, indx);
  while (full_bcd != 0) {
    cur_rank = s21_get_rank(&value, full_bcd);
    if (cur_rank > 0) {
      first_index_rank = s21_get_rank(&value, 1);
      last_rank = s21_get_rank(&value, 0);
      if ((last_rank == 5 && first_index_rank % 2 == 1) && last_rank > 5) {
        first_index_rank++;
        s21_rank_full_bcd(&value);
        s21_set_rank(&value, 1, first_index_rank);
      }
    }
    scale = s21_get_scale_bcd(&value);
    if (scale == 0) {
      if (s21_get_sign_bcd(&value) == 0)
        result = 1;
      else
        result = 2;
      break;
    }
    scale--;
    s21_set_scale_bcd(&value, scale);
    // Сдвигаем на разряд
    for (int i = 0; i < 4; i++) {
      s21_right_shift_bcd(&value);
    }
    full_bcd = s21_check_full_bcd(&value, LEFT_RANK);
  }
  if (result == 0) s21_copy_bcd(&value, cur_value);

  return result;
}

// возвращает степень бцд, которая хранится в битах с 16-23
int s21_get_scale_bcd(const s21_bcd* value) {
  int result = 0;
  int shift = 16;
  for (int i = 0; shift < 24; ++i) {
    int bit = ((value->sign_exp & (1 << shift)) != 0);
    result += bit * pow(2, i);
    shift++;
  }
  return result;
}

// устанавливает степень бцд, которая хранится в битах с 16-23
void s21_set_scale_bcd(s21_bcd* value, int scale) {
  int shift = 16;
  for (int i = 0; shift < 24; ++i) {
    if (scale % 2 == 1 && scale != 0) {
      value->sign_exp = value->sign_exp | (1 << shift);
    } else {
      value->sign_exp = value->sign_exp & ~(1 << shift);
    }
    shift++;
    scale /= 2;
  }
}

// функция нормализации двух бцд - приводит к единой степени (к большей эксп)
int s21_normalize_bcd(s21_bcd* value1, s21_bcd* value2) {
  int result = 0;
  int scale1 = s21_get_scale_bcd(value1);
  int scale2 = s21_get_scale_bcd(value2);
  if (scale1 != scale2) {
    char toNormalize = '1';
    int scaleDff = 0;
    if (scale1 > scale2) {
      scaleDff = scale1 - scale2;
    } else {
      toNormalize = '2';
      scaleDff = scale2 - scale1;
    }
    if (toNormalize == '1') {
      // нужна проверка на переполнение и банковское округление
      while (scaleDff > 0) {
        if (s21_get_rank(value2, 28) == 0) {
          for (int i = 0; i < 4; i++) s21_left_shift_bcd(value2);
          s21_bank_round_bcd(value2, LEFT_RANK);
          scaleDff--;
        } else {
          s21_bank_round_bcd(value1, scaleDff + LEFT_RANK);
          scale1 = scale1 - scaleDff;
          scaleDff = 0;
        }
      }
      s21_set_scale_bcd(value1, scale1);
      s21_set_scale_bcd(value2, scale1);
    } else {
      // нужна проверка на переполнение и банковское округление
      while (scaleDff > 0) {
        if (s21_get_rank(value1, 28) == 0) {
          for (int i = 0; i < 4; i++) s21_left_shift_bcd(value1);
          s21_bank_round_bcd(value1, LEFT_RANK);
          scaleDff--;
        } else {
          s21_bank_round_bcd(value2, scaleDff + LEFT_RANK);
          scale2 = scale2 - scaleDff;
          scaleDff = 0;
        }
      }
      s21_set_scale_bcd(value1, scale2);
      s21_set_scale_bcd(value2, scale2);
    }
  }
  return result;
}

void s21_convert_norm_to_bcd(s21_decimal* value1, s21_decimal* value2,
                             s21_bcd* value_bcd1, s21_bcd* value_bcd2) {
  s21_init_bcd(value_bcd1);
  s21_init_bcd(value_bcd2);
  s21_dec_to_bcd(value1, value_bcd1);
  s21_dec_to_bcd(value2, value_bcd2);
  s21_normalize_bcd(value_bcd1, value_bcd2);
}

void s21_copy_bcd(const s21_bcd* value, s21_bcd* new_value) {
  for (int i = 0; i < (int)sizeof(value->bits) / 4; i++) {
    new_value->bits[i] = value->bits[i];
  }
  new_value->sign_exp = value->sign_exp;
}

void s21_copy_mant_bcd(const s21_bcd* value, s21_bcd* new_value) {
  for (int i = 0; i < (int)sizeof(value->bits) / 4; i++) {
    new_value->bits[i] = value->bits[i];
  }
}

// Возвращает 1 если 0
int s21_zero_bcd(s21_bcd* value) {
  int result = 1;
  for (int i = 0; i < (int)sizeof(value->bits) / 4; i++) {
    if (value->bits[i] != 0) {
      result = 0;
    }
  }
  if (result == 1) {
    s21_set_sign_bcd(value, 0);
  }
  return result;
}

int s21_negate_bcd(s21_bcd* value) {
  int sign = s21_get_sign_bcd(value);
  sign = 1 - sign;
  s21_set_sign_bcd(value, sign);
  return 0;
}

// если значение больше допустимого, то 1
int s21_great_max(const s21_bcd* value) {
  s21_decimal max_value_dec, cur_value;
  for (int i = 0; i < (int)sizeof(max_value_dec) / 4 - 1; i++) {
    max_value_dec.bits[i] = 0xffffffff;
  }
  s21_bcd_to_dec(&cur_value, value);
  int result = s21_is_greater(cur_value, max_value_dec);
  return result;
}

// если значение меньше допустимого, то 1
int s21_less_min(const s21_bcd* value) {
  s21_decimal min_value_dec, cur_value;
  for (int i = 0; i < (int)sizeof(min_value_dec) / 4 - 1; i++) {
    min_value_dec.bits[i] = 0xffffffff;
  }
  s21_set_scale_dec(&min_value_dec, 28);
  s21_set_sign_dec(&min_value_dec, 1);
  s21_bcd_to_dec(&cur_value, value);
  int result = s21_is_less(cur_value, min_value_dec);
  return result;
}

void s21_drop_zeros(s21_bcd* value) {
  int scale = s21_get_scale_bcd(value);
  while (s21_get_rank(value, 0) == 0 && scale > 0) {
    for (int i = 0; i < 4; i++) {
      s21_right_shift_bcd(value);
    }
    scale--;
  }
  s21_set_scale_bcd(value, scale);
}