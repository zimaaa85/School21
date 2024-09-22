#include "s21_string.h"

s21_size_t s21_width_parse(const char ***format) {
  char *numS = (char *)**format;
  for (; ***format >= '0' && ***format <= '9'; **format += 1) {
    continue;
  }
  s21_size_t number = (s21_size_t)s21_atoi(numS);
  return number;
}

void s21_format_char(char **buf, int sym, Flags flags) {
  int space = (flags.star > flags.wide) ? flags.star : flags.wide;
  int skip = (space - 1);
  if (space > 1) {
    while (skip > 0) {
      if (!flags.minus) {
        **buf = ' ';
        *buf += 1;
        --skip;
      } else
        break;
    }
  }
  **buf = sym;
  if (flags.minus && space > 1) {
    while (skip > 0) {
      *buf += 1;
      **buf = ' ';
      --skip;
    }
  }
}

void s21_etoa(long double num, char *str, Flags flags) {
  int sign = 0, exponent = (int)log10((fabsl(num)));
  char *sMant1 = calloc(1900, 1900);
  char *sMant = sMant1;
  double mantissa = num / pow(10, exponent);
  if (num == 0) {
    mantissa = 0;
    exponent = 0;
  }
  char *sExp = calloc(150, 150);
  if (flags.g_flag) {
    if (flags.precision)
      s21_ftoa(mantissa, sMant, flags.prec_value - 1);
    else if (fabsl(num) > 1000000) {
      int cnt = 0, inum = 0;
      if (num >= 0)
        inum = (int)num;
      else
        inum = (int)-num;
      while (inum > 1000000) {
        inum /= 10;
        cnt++;
      }
      s21_gftoa(mantissa, sMant, 5 + cnt);
    }
  } else {
    if (!flags.precision) {
      flags.prec_value = 6;
    }
    s21_ftoa(mantissa, sMant, flags.prec_value);
  }
  s21_itoa(exponent, sExp);
  if (flags.sharp && !flags.prec_value) s21_strncat(sMant, ".", 100);
  char e_char[1] = "";
  if (flags.e_big)
    e_char[0] = 'E';
  else
    e_char[0] = 'e';
  s21_strncat(sMant, e_char, 100);
  if (exponent >= 0) s21_strncat(sMant, "+", 100);
  if (abs(exponent) < 10) s21_strncat(sMant, "0", 100);
  s21_strncat(sMant, sExp, 100);
  free(sExp);
  if (sMant[0] == '-' && flags.zero) {
    sMant++;
    sign = 1;
  }
  s21_size_t space = (flags.wide > flags.star) ? flags.wide : flags.star;
  int skip = space - s21_strlen(sMant);
  if (!sign && (flags.space || flags.plus)) skip--;
  if (flags.zero && sign == 1) {
    str[0] = '-';
    str++;
    --skip;
  }
  while (flags.zero && skip > 0) {
    *str = '0';
    str++;
    --skip;
  }
  s21_strcpy(str, sMant);
  free(sMant1);
}

void s21_format_scient(char **buf, long double num, Flags flags) {
  s21_size_t space = (flags.wide > flags.star) ? flags.wide : flags.star;
  char *sMant = calloc(520, 520);
  s21_etoa(num, sMant, flags);
  int skip = space - s21_strlen(sMant);
  while (!flags.minus && skip > 0) {
    if (!flags.zero) {
      **buf = ' ';
      *buf += 1;
      skip--;
    } else
      break;
  }
  s21_strcpy(*buf, sMant);
  *buf += s21_strlen(sMant) - 1;
  while (flags.minus && skip > 0 && !flags.zero) {
    *buf += 1;
    **buf = ' ';
    skip--;
  }
  free(sMant);
}

void s21_format_string(char **buf, char *string, Flags flags) {
  s21_size_t space = (flags.star > flags.wide) ? flags.star : flags.wide;
  int skip = (space - s21_strlen(string));
  if (skip > 0 && !flags.minus) {
    while (skip > 0) {
      **buf = ' ';
      *buf += 1;
      --skip;
    }
  }
  s21_strcpy(*buf, string);
  *buf = *buf + (s21_strlen(string) - 1);
  if (flags.minus) {
    while (skip > 0) {
      *buf += 1;
      **buf = ' ';
      --skip;
    }
  }
}

void s21_format_float(char **buf, double floatNum, Flags flags) {
  double sign = floatNum;
  if (floatNum < 0 && flags.zero) floatNum = -floatNum;
  char *snum = calloc(1590, 1590);
  int e_flag = 0, space = (flags.star > flags.wide) ? flags.star : flags.wide;
  if ((flags.plus || flags.space) && floatNum >= 0 && !flags.zero) snum++;
  if (flags.g_flag) {
    if (fabs(floatNum) >= 1000000 || flags.precision) {
      e_flag = 1;
      s21_etoa(floatNum, snum, flags);
    } else
      s21_gftoa(floatNum, snum, flags.prec_value);
  } else if (flags.precision) {
    s21_ftoa(floatNum, snum, flags.prec_value);
  } else
    s21_ftoa(floatNum, snum, 6);
  if (((flags.plus || flags.space)) && floatNum >= 0 && !flags.zero) {
    snum--;
    *snum = (flags.plus > flags.space) ? '+' : ' ';
  }
  if (!s21_strchr(snum, '.') && flags.sharp && !e_flag)
    s21_strncat(snum, ".", 100);
  int skip = (space - (s21_strlen(snum)));
  if (space > skip && !flags.zero) {
    while (skip > 0) {
      if (!flags.minus) {
        **buf = ' ';
        *buf += 1;
        --skip;
      } else
        break;
    }
  }
  if (sign < 0 && flags.zero) {
    **buf = '-';
    *buf += 1;
    --skip;
  } else if (sign >= 0 && flags.plus && flags.zero) {
    **buf = '+';
    *buf += 1;
    --skip;
  } else if (sign >= 0 && flags.space && flags.zero) {
    **buf = ' ';
    *buf += 1;
    --skip;
  }
  while (skip > 0 && flags.zero) {
    **buf = '0';
    *buf += 1;
    --skip;
  }
  s21_strcpy(*buf, snum);
  *buf = *buf + (s21_strlen(snum) - 1);
  if (flags.minus && !flags.zero) {
    while (skip > 0) {
      *buf += 1;
      **buf = ' ';
      --skip;
    }
  }
  if (snum) free(snum);
}

void s21_format_long_float(char **buf, long double floatNum, Flags flags) {
  long double sign = floatNum;
  if (floatNum < 0 && flags.zero) floatNum = -floatNum;
  char *snum = calloc(1590, 1590);
  int space = (flags.star > flags.wide) ? flags.star : flags.wide;
  if ((flags.plus || flags.space) && floatNum >= 0 && !flags.zero) {
    snum++;
  }
  if (flags.g_flag) {
    if (fabsl(floatNum) >= 1000000 || flags.precision) {
      s21_etoa(floatNum, snum, flags);
    } else
      s21_ftoa(floatNum, snum, flags.prec_value);
  } else if (flags.precision) {
    s21_ftoa(floatNum, snum, flags.prec_value);
  } else
    s21_ftoa(floatNum, snum, 6);
  if ((flags.plus || flags.space) && floatNum >= 0 && !flags.zero) {
    snum--;
    *snum = (flags.plus > flags.space) ? '+' : ' ';
  }
  if (!s21_strchr(snum, '.') && flags.sharp) s21_strncat(snum, ".", 100);
  int skip = (space - (s21_strlen(snum)));
  if (space > skip && !flags.zero) {
    while (skip > 0) {
      if (!flags.minus) {
        **buf = ' ';
        *buf += 1;
        --skip;
      } else
        break;
    }
  }
  if (sign < 0 && flags.zero) {
    **buf = '-';
    *buf += 1;
    --skip;
  } else if (sign >= 0 && flags.plus && flags.zero) {
    **buf = '+';
    *buf += 1;
    --skip;
  } else if (sign >= 0 && flags.space && flags.zero) {
    **buf = ' ';
    *buf += 1;
    --skip;
  }
  while (skip > 0 && flags.zero) {
    **buf = '0';

    *buf += 1;
    --skip;
  }
  s21_strcpy(*buf, snum);
  *buf = *buf + (s21_strlen(snum) - 1);
  if (flags.minus && !flags.zero) {
    while (skip > 0) {
      *buf += 1;
      **buf = ' ';

      --skip;
    }
  }
  if (snum) free(snum);
}

void s21_format_int(char **buf, long int integer, Flags flags) {
  char *snum = calloc(1000, 1000);
  char *number = calloc(1000, 1000);
  long int sign = integer;
  if (!flags.long_int) sign = (int)sign;
  int snumCounter = 0;
  if (sign < 0) integer = -integer;
  if (flags.long_int)
    s21_litoa(integer, number);
  else
    s21_itoa(integer, number);
  s21_size_t space = (flags.star > flags.wide) ? flags.star : flags.wide;
  int skip = flags.prec_value - s21_strlen(number);
  if (flags.zero && (int)(space - (int)s21_strlen(number)) > skip)
    skip = space - (int)s21_strlen(number) - 1;
  if (sign < 0) {
    *snum = '-';
    snum++;
    snumCounter++;
  } else if (flags.plus && sign >= 0) {
    *snum = '+';
    snum++;
    snumCounter++;
  } else if (flags.space && sign >= 0) {
    *snum = ' ';
    snum++;
    snumCounter++;
  }
  while (skip > 0) {
    *snum = '0';
    snum++;
    --skip;
    snumCounter++;
  }
  s21_strcpy(snum, number);
  snum -= snumCounter;
  free(number);
  int bufSkip = space - s21_strlen(snum);
  while (bufSkip > 0 && !flags.minus && !flags.zero) {
    **buf = ' ';
    *buf += 1;
    bufSkip--;
  }
  s21_strcpy(*buf, snum);
  *buf = *buf + (s21_strlen(snum) - 1);
  if (flags.minus && !flags.zero) {
    while (bufSkip > 0) {
      *buf += 1;
      **buf = ' ';
      --bufSkip;
    }
  }
  if (snum) free(snum);
}

void s21_format_unsigned_int(char **buf, unsigned int integer, Flags flags,
                             char *snum) {
  s21_uitoa(integer, snum);
  int space = (flags.star > flags.wide) ? flags.star : flags.wide;
  int skip = (space - s21_strlen(snum));
  if (space > (int)s21_strlen(snum)) {
    while (skip > 0) {
      if (flags.precision || flags.zero) {
        **buf = '0';
        *buf += 1;
        --skip;
      } else if (!flags.minus && !flags.precision) {
        **buf = ' ';
        *buf += 1;
        --skip;
      } else
        break;
    }
  }
  s21_strcpy(*buf, snum);
  *buf = *buf + (s21_strlen(snum) - 1);
  if (flags.minus && space > (int)s21_strlen(snum) && !flags.precision) {
    while (skip > 0) {
      *buf += 1;
      **buf = ' ';
      --skip;
    }
  }
}

void s21_int_to_oct(char *str, unsigned long int num, Flags flags) {
  if (!flags.long_int) num = (unsigned int)num;
  char temp = 1;
  int i = 0;
  if (num != 0) {
    while (num != 0) {
      temp = num % 8;
      temp = temp + 48;
      *str = temp;
      num = num / 8;
      str++;
      i++;
    }
    s21_size_t space = (flags.star > flags.wide) ? flags.star : flags.wide;
    int skip = space - i;
    if (flags.sharp) skip -= 2;
    while (flags.zero && skip > 0) {
      *str = '0';
      str++;
      --skip;
      i++;
    }
    if (flags.sharp) {
      *str = '0';
      i++;
      str++;
    }
    str -= i;
    s21_reverse(str);
  } else
    *str = '0';
}

void s21_int_to_hex(char *str, unsigned long int num, Flags flags) {
  int temp = 0, i = 0;
  if (flags.short_int) temp = (short int)temp;
  if (num != 0) {
    while (num != 0) {
      temp = num % 16;
      if (temp < 10) {
        temp = temp + 48;
      } else {
        if (flags.x_big)
          temp += 55;
        else
          temp += 87;
      }
      *str = temp;
      num = num / 16;
      str++;
      i++;
    }
    s21_size_t space = (flags.star > flags.wide) ? flags.star : flags.wide;
    int skip = space - i;
    if (flags.sharp) skip -= 2;
    while (flags.zero && skip > 0) {
      *str = '0';
      str++;
      --skip;
      i++;
    }
    if (flags.sharp) {
      if (!flags.x_big)
        *str = 'x';
      else
        *str = 'X';
      *(str + 1) = '0';
      i += 2;
      str += 2;
    }
    str -= i;
    s21_reverse(str);
  } else
    *str = '0';
}

void s21_format_hex(char **buf, unsigned long int num, Flags flags) {
  if (!flags.long_int && !flags.short_int)
    num = (unsigned int)num;
  else if (!flags.long_int && flags.short_int)
    num = (unsigned short int)num;
  char *str = calloc(100, 100);
  s21_int_to_hex(str, num, flags);
  s21_size_t space = (flags.wide > flags.star) ? flags.wide : flags.star;
  int skip = space - s21_strlen(str);
  while (skip > 0 && !flags.minus && !flags.zero) {
    **buf = ' ';
    *buf += 1;
    skip--;
  }
  s21_strcpy(*buf, str);
  *buf += s21_strlen(str) - 1;
  while (skip > 0 && flags.minus && !flags.zero) {
    *buf += 1;
    **buf = ' ';
    skip--;
  }
  free(str);
}

void s21_format_oct(char **buf, unsigned long int num, Flags flags) {
  char *str = calloc(100, 100);
  s21_int_to_oct(str, num, flags);
  s21_size_t space = (flags.wide > flags.star) ? flags.wide : flags.star;
  int skip = space - s21_strlen(str);
  while (skip > 0 && !flags.minus) {
    **buf = ' ';
    *buf += 1;
    skip--;
  }
  s21_strcpy(*buf, str);
  *buf += s21_strlen(str) - 1;
  while (skip > 0 && flags.minus) {
    *buf += 1;
    **buf = ' ';
    skip--;
  }
  free(str);
}

void s21_format_ptr(char **buf, intptr_t *ptr, Flags flags) {
  char *str = calloc(100, 100);
  s21_ptrtoa(ptr, str);
  str += 2;
  s21_size_t space = (flags.wide > flags.star) ? flags.wide : flags.star;
  int skip = space - s21_strlen(str);
  while (skip > 0 && !flags.minus) {
    **buf = ' ';
    *buf += 1;
    skip--;
  }
  s21_strcpy(*buf, str);
  *buf += s21_strlen(str) - 1;
  str -= 2;
  free(str);
  while (skip > 0 && flags.minus) {
    *buf += 1;
    **buf = ' ';
    skip--;
  }
}

void s21_search_for_modifiers(const char **format, Flags *flags,
                              va_list *factor) {
  *format += 1;
  for (; s21_strchr("-+ #0", **format); *format += 1) {
    if (**format == '+') {
      if (*(*format + 1) == '+' || *(*format + 1) == ' ') exit(1);
      flags->plus = true;
    }
    if (**format == '-') flags->minus = true;
    if (**format == ' ') flags->space = true;
    if (**format == '#') flags->sharp = true;
    if (**format == '0') flags->zero = true;
  }
  for (; s21_strchr(".*1234567890", **format); *format += 1) {
    if (**format == '*') {
      flags->star = va_arg(*factor, s21_size_t);
    }
    if (**format >= 48 && **format <= 57 && *(*format - 1) != '.') {
      flags->wide = s21_width_parse(&format);
      *format -= 1;
    }
    if (**format == '.') {
      *format += 1;
      flags->precision = true;
      if (**format == '*') {
        flags->prec_value = va_arg(*factor, s21_size_t);
      } else {
        flags->prec_value = s21_width_parse(&format);
        *format -= 1;
      }
    }
  }
}

void s21_format_specifier(char **buf, const char **format, va_list *factor,
                          Flags *flags) {
  for (; **(format) != '\0'; *format += 1) {
    if (**format == 'l') flags->long_int = true;

    if (**format == 'h') flags->short_int = true;

    if (**format == 'L') flags->long_double = true;

    if (**format == 'd') {
      long int integer = va_arg(*factor, long int);
      if (!flags->long_int && !flags->short_int)
        integer = (int)integer;
      else if (flags->short_int)
        integer = (short int)integer;
      s21_format_int(buf, integer, *flags);
      break;
    }
    if (**format == 'c') {
      int sym = va_arg(*factor, int);
      s21_format_char(buf, sym, *flags);
      break;
    }
    if (**format == 's') {
      char *string = va_arg(*factor, char *);
      s21_format_string(buf, string, *flags);
      break;
    }
    if (**format == '%') {
      *buf += 1;
      **buf = '%';
      break;
    }
    if (**format == 'u') {
      unsigned long int integer = va_arg(*factor, long int);
      char snum[1000];
      if (!flags->long_int && !flags->short_int)
        integer = (int)integer;
      else if (flags->short_int)
        integer = (short int)integer;
      s21_format_unsigned_int(buf, integer, *flags, snum);
      break;
    }
    if (**format == 'f' || **format == 'g' || **format == 'G' ||
        **format == 'e' || **format == 'E') {
      if (**format == 'g' || **format == 'G') flags->g_flag = true;
      if (**format == 'G') flags->e_big = true;
      if (!flags->long_double) {
        double floatNum = va_arg(*factor, double);
        if (**format == 'e' || **format == 'E') {
          if (**format == 'E') flags->e_big = true;
          s21_format_scient(buf, floatNum, *flags);
        } else {
          s21_format_float(buf, floatNum, *flags);
        }
      } else {
        long double floatNum = va_arg(*factor, long double);
        if (**format == 'e' || **format == 'E') {
          if (**format == 'E') flags->e_big = true;
          s21_format_scient(buf, floatNum, *flags);
        } else {
          s21_format_long_float(buf, floatNum, *flags);
        }
      }
      break;
    }
    if (**format == 'x' || **format == 'X' || **format == 'o') {
      if (**format == 'X') flags->x_big = true;
      unsigned long int num = va_arg(*factor, unsigned long int);
      if (**format == 'x' || **format == 'X')
        s21_format_hex(buf, num, *flags);
      else
        s21_format_oct(buf, num, *flags);
      break;
    }
    if (**format == 'p') {
      intptr_t num = 0;
      num = va_arg(*factor, intptr_t);
      s21_format_ptr(buf, &num, *flags);
      break;
    }
  }
}

int s21_sprintf(char *buf, const char *format, ...) {
  Flags flags = {false, false, false, false, false, 0,     0,    0,
                 false, false, false, false, false, false, false};
  va_list factor;
  va_start(factor, format);
  for (; *format != '\0'; format++) {
    *buf = *format;
    if (*format == '%') {
      s21_search_for_modifiers(&format, &flags, &factor);
      s21_format_specifier(&buf, &format, &factor, &flags);
    }
    flags.plus = false;
    flags.minus = false;
    flags.space = false;
    flags.sharp = false;
    flags.zero = false;
    flags.wide = 0;
    flags.star = 0;
    flags.prec_value = 0;
    flags.precision = false;
    flags.short_int = false;
    flags.long_int = false;
    flags.long_double = false;
    flags.e_big = false;
    flags.g_flag = false;
    flags.x_big = false;
    buf++;
  }
  *buf = '\0';
  return (int)s21_strlen(buf);
}