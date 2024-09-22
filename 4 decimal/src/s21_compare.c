#include "s21_decimal.h"

// проверяет равен ли децимал 0
int s21_is_zero(s21_decimal value) {
  int result = 0;
  if (value.bits[0] == 0 && value.bits[1] == 0 && value.bits[2] == 0) {
    result = 1;
  }
  return result;
}

// проверяет больше ли мантиса бцд1 мантисы бдц2. возращает 1 если больше и 0
// если равны и -1 если меньше
int s21_greater_mant_bcd(s21_bcd value1, s21_bcd value2) {
  int result = 0;
  int stop = 0;
  for (int i = 3; i >= 0 && stop == 0; --i) {
    for (int j = 31; j >= 0 && stop == 0; --j) {
      if (s21_get_bit(value1.bits[i], j) != s21_get_bit(value2.bits[i], j)) {
        result =
            s21_get_bit(value1.bits[i], j) - s21_get_bit(value2.bits[i], j);
        stop = 1;
      }
    }
  }
  return result;
}

// проверяет равны ли мантисы бцд1 и бдц2. возращает 1 если равны и 0 если не
// равны
int s21_equal_mant_bcd(s21_bcd value1, s21_bcd value2) {
  int result = 1;
  int stop = 0;
  for (int i = 3; i >= 0 && stop == 0; --i) {
    for (int j = 31; j >= 0 && stop == 0; --j) {
      if (s21_get_bit(value1.bits[i], j) != s21_get_bit(value2.bits[i], j)) {
        result = 0;
        stop = 1;
      }
    }
  }
  return result;
}

// сравнивает два децимала, и возвращает 1 если дец1 больше дец2, иначе 0
int s21_is_greater(s21_decimal value1, s21_decimal value2) {
  int result = 1;
  int sign1 = s21_get_sign_dec(value1);
  int sign2 = s21_get_sign_dec(value2);
  //-0 и +0 бывает ли?
  if (s21_is_zero(value1) && s21_is_zero(value2)) {
    result = 0;
  } else if (sign1 == 1 && sign2 == 0) {
    result = 0;
  } else if (sign1 == sign2) {
    s21_bcd value_bcd1, value_bcd2;
    s21_convert_norm_to_bcd(&value1, &value2, &value_bcd1, &value_bcd2);
    result = s21_greater_mant_bcd(value_bcd1, value_bcd2);
    if (sign1 == 1) {
      result = result == -1 ? 1 : 0;
    } else {
      result = result == -1 ? 0 : result;
    }
  }
  return result;
}

// сравнивает два децимала, и возвращает 1 если они равны, иначе 0
int s21_is_equal(s21_decimal value1, s21_decimal value2) {
  int result = 1;
  int sign1 = s21_get_sign_dec(value1);
  int sign2 = s21_get_sign_dec(value2);
  if (s21_is_zero(value1) && s21_is_zero(value2)) {
    result = 1;
  } else if (sign1 != sign2) {
    result = 0;
  } else {
    s21_bcd value_bcd1, value_bcd2;
    s21_convert_norm_to_bcd(&value1, &value2, &value_bcd1, &value_bcd2);
    result = s21_equal_mant_bcd(value_bcd1, value_bcd2);
  }
  return result;
}

// сравнивает два децимала, и возвращает 1 если они не равны, 0 если равны
int s21_is_not_equal(s21_decimal value1, s21_decimal value2) {
  return !s21_is_equal(value1, value2);
}

// сравнивает два децимала, и возвращает 1 если децимал1 больше или равен
// децималу 2, иначе 0
int s21_is_greater_or_equal(s21_decimal value1, s21_decimal value2) {
  int result = 0;
  if (s21_is_equal(value1, value2) || s21_is_greater(value1, value2)) {
    result = 1;
  }
  return result;
}

// Сравнивает два децимала, возвращает 1 если децимал1 меньше децимала2, иначе 0
int s21_is_less(s21_decimal value1, s21_decimal value2) {
  return !s21_is_greater_or_equal(value1, value2);
}

// Сравнивает два децимала, возвращает 1 если децимал1 меньше или равен
// децимала2, иначе 0
int s21_is_less_or_equal(s21_decimal value1, s21_decimal value2) {
  int result = 0;
  if (s21_is_equal(value1, value2) || s21_is_less(value1, value2)) {
    result = 1;
  }
  return result;
}