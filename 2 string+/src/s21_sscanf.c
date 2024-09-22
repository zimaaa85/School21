#include "s21_string.h"

void s21_spec_parse(const char *format, int *format_start_index,
                    Specifier *spec) {
  int format_cur_index = *format_start_index, int_len = 9;
  format_cur_index++;
  char num[] = "0123456789";
  char spec_name_mas[] = "cdieEfgGosuXxpn%";
  char spec_len_mas[] = "lLh";
  char *wide = calloc(int_len, sizeof(char));
  char cur_let = format[format_cur_index];
  while (cur_let != '\0' && s21_strchr(spec_name_mas, cur_let) == s21_NULL) {
    char *ptr = s21_NULL;
    switch (cur_let) {
      case '%':
        break;
      case '*':
        spec->star = '*';
        break;
      default:
        if ((ptr = s21_strchr(num, cur_let)) != s21_NULL) {
          wide = s21_strncat(wide, ptr, 1);
        }
        if ((ptr = s21_strchr(spec_len_mas, cur_let)) != s21_NULL) {
          spec->len = *ptr;
        }
        break;
    }
    format_cur_index++;
    cur_let = format[format_cur_index];
  }
  spec->name = cur_let;
  spec->wide = (int)s21_atoi(wide);
  if (spec->wide == 0) spec->wide = -1;
  free(wide);
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list varg;
  va_start(varg, format);
  Specifier spec = {0, 0, 0, -1};
  int el_count = 0, stop = 0, format_cur_index = 0, str_cur_index = 0;
  while (format[format_cur_index] != '\0' && stop == 0) {
    switch (format[format_cur_index]) {
      case '%':
        spec.len = 0;
        spec.name = 0;
        spec.star = 0;
        spec.wide = -1;
        s21_spec_parse(format, &format_cur_index, &spec);
        stop = s21_aply_spec(str, &str_cur_index, &spec, varg);
        if (stop == 0 && spec.name != '%' && spec.name != 'n' &&
            spec.star == 0) {
          el_count++;
        }
        break;
      default:
        if (format[format_cur_index] == str[str_cur_index]) {
          str_cur_index++;
        }
        break;
    }
    format_cur_index++;
  }
  va_end(varg);
  return el_count;
}

int s21_aply_spec(const char *str, int *start_index, Specifier *spec,
                  va_list varg) {
  int stop = 0;
  switch (spec->name) {
    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G':
      s21_skip_char(str, start_index);
      int cur_el = -1;
      cur_el = s21_double_find(str, start_index, spec);
      if (cur_el != -1) {
        stop = s21_get_element_double(str, start_index, spec, varg);
      } else {
        stop = -1;
      }
      break;
    case 'c':
      if (str[*start_index] == '\0')
        stop = 1;
      else {
        if (spec->star == 0) *(va_arg(varg, char *)) = str[*start_index];
        (*start_index)++;
      }
      break;
    case 'd':
      s21_skip_char(str, start_index);
      stop = s21_get_element_sing_int(str, start_index, spec, varg, 'd');
      break;
    case 'i':
      s21_skip_char(str, start_index);
      if (s21_integer_find(str, start_index, 'h', spec) != -1) {
        stop = s21_get_element_sing_int(str, start_index, spec, varg, 'h');
      } else if (s21_integer_find(str, start_index, 'o', spec) != -1) {
        stop = s21_get_element_sing_int(str, start_index, spec, varg, 'o');
      } else if (s21_integer_find(str, start_index, 'd', spec) != -1) {
        stop = s21_get_element_sing_int(str, start_index, spec, varg, 'd');
      } else {
        stop = 1;
      }
      break;
    case 'o':
      s21_skip_char(str, start_index);
      stop = s21_get_element_unsing_int(str, start_index, spec, varg, 'o');
      break;
    case 's':
      s21_skip_char(str, start_index);
      int cur_index = *start_index;
      while (str[cur_index] != '\0' && str[cur_index] != ' ' &&
             str[cur_index] != '\t' &&
             (((cur_index - *start_index) < spec->wide) || spec->wide == -1)) {
        cur_index++;
      }
      if (spec->star == 0)
        s21_strncpy((va_arg(varg, char *)), str + *start_index,
                    cur_index - *start_index);
      *start_index = cur_index;
      break;
    case 'u':
      s21_skip_char(str, start_index);
      stop = s21_get_element_unsing_int(str, start_index, spec, varg, 'd');
      break;
    case 'X':
    case 'x':
      s21_skip_char(str, start_index);
      stop = s21_get_element_unsing_int(str, start_index, spec, varg, 'h');
      break;
    case 'p':
      if (s21_integer_find(str, start_index, 'h', spec) != -1) {
        spec->len = 'l';
        stop = s21_get_element_unsing_int(str, start_index, spec, varg, 'h');
      }
      break;
    case 'n':
      s21_skip_char(str, start_index);
      *(va_arg(varg, int *)) = *start_index;
      break;
    case '%':
      s21_skip_char(str, start_index);
      (*start_index)++;
      break;
    default:
      stop = 1;
      break;
  }
  return stop;
}

void s21_skip_char(const char *str, int *start_index) {
  while (str[*start_index] == ' ' || str[*start_index] == '\t' ||
         str[*start_index] == '\n') {
    (*start_index)++;
  }
}

int s21_integer_find(const char *str, int *start_index, char int_type,
                     Specifier *spec) {
  int is_stop = 0, last_index = -1, str_cur_index = *start_index;
  char *num = s21_NULL;
  char dec[] = "0987654321";
  char oct[] = "07654321";
  char hex[] = "0987654321ABCDEFabcdef";
  switch (int_type) {
    case 'd':
      num = dec;
      break;
    case 'o':
      num = oct;
      break;
    case 'h':
      num = hex;
      break;
    default:
      num = 0;
      break;
  }
  if (str[str_cur_index] == '+' || str[str_cur_index] == '-') str_cur_index++;
  if (spec->wide <= (str_cur_index - *start_index) && spec->wide != -1)
    is_stop = -1;
  int zero_in_start = 0;
  while (str[str_cur_index] == '0' && is_stop != -1) {
    str_cur_index++;
    zero_in_start++;
  }
  if (zero_in_start > 0) last_index = str_cur_index;
  if ((int_type == 'o' || int_type == 'h') && zero_in_start == 0) is_stop = 1;
  if (int_type == 'h' && zero_in_start > 0) {
    if (str[str_cur_index] == 'x' || str[str_cur_index] == 'X') {
      str_cur_index++;
    } else
      is_stop = 1;
  }
  while (s21_strchr(num, str[str_cur_index]) != s21_NULL && is_stop == 0 &&
         str[str_cur_index] != '\0') {
    str_cur_index++;
  }
  if (str_cur_index > *start_index && is_stop == 0) {
    last_index = str_cur_index;
  }
  if (is_stop == 1) last_index = -1;
  return last_index;
}

int s21_double_find(const char *str, int *start_index, Specifier *spec) {
  // proces :=  1(num)2(.)3(num)4(E/e)5(+-num)
  int str_cur_index = -1, index_end = -1;
  int index_point = s21_integer_find(str, start_index, 'd', spec);
  if (index_point != -1) str_cur_index = index_point;
  int index_after_point = -1;
  if (index_point != -1 && str[str_cur_index] == '.') {
    str_cur_index++;
    index_after_point = s21_integer_find(str, &str_cur_index, 'd', spec);
    if (index_after_point != -1) str_cur_index = index_after_point;
  }
  if (str[str_cur_index] == 'e' || str[str_cur_index] == 'E') {
    str_cur_index++;
    index_end = s21_integer_find(str, &str_cur_index, 'd', spec);
    if (index_end != -1) str_cur_index = index_end;
  }
  return str_cur_index;
}

long long int s21_get_int_num(const char *str, int *start_index, char int_type,
                              Specifier *spec) {
  long long int num = 0, sub_num = 0;
  int integer_system = 0;
  switch (int_type) {
    case 'o':
      integer_system = 8;
      break;
    case 'h':
      integer_system = 16;
      break;
    default:
      integer_system = 10;
      break;
  }
  int last_index = s21_integer_find(str, start_index, int_type, spec);
  if (((last_index - *start_index) > spec->wide) && (spec->wide != -1))
    last_index = spec->wide + *start_index;
  for (int i = *start_index; i < last_index; i++) {
    sub_num = (long long int)s21_char_to_num(str[i]);
    for (int j = i; j < last_index - 1 && sub_num != 0; j++) {
      sub_num = sub_num * integer_system;
    }
    num = num + sub_num;
    sub_num = 0;
  }
  if (str[*start_index] == '-') num *= -1;
  if (spec->wide != -1) spec->wide -= last_index;
  *start_index = last_index;
  return num;
}

int s21_char_to_num(char c) {
  int num = 0;
  if (c < 58 && c > 47) num = c - 48;
  if (c < 72 && c > 64) num = c - 55;
  if (c < 103 && c > 97) num = c - 87;
  return num;
}

long double s21_get_double_num(const char *str, int *start_index,
                               Specifier *spec) {
  // proces :=  1(num)2(.)3(num)4(E/e)5(+-num)
  int process = 0, step = 1, mantice_start = 0;
  long long int ex_start = 0;
  long double result = 0, before_point = 0, after_point = 0;
  before_point = (long double)s21_get_int_num(str, start_index, 'd', spec);
  result += before_point;
  process = 1;
  while (step <= process && spec->wide == -1) {
    switch (str[*start_index]) {
      case '.':
        (*start_index)++;
        process = 2;
        break;
      case 'E':
      case 'e':
        (*start_index)++;
        process = 4;
        break;
      default:
        if (process == 2) {
          mantice_start = *start_index;
          after_point =
              (long double)s21_get_int_num(str, start_index, 'd', spec);
          for (int i = mantice_start; i < *start_index; i++) after_point /= 10;
          if (result >= 0) result += after_point;
          if (result < 0) result -= after_point;

          process = 3;
        }
        if (process == 4) {
          ex_start = s21_get_int_num(str, start_index, 'd', spec);
          if (ex_start > 0) {
            for (int i = 0; i < ex_start; i++) result *= 10;
          }
          if (ex_start < 0) {
            for (int i = 0; i > ex_start; i--) result /= 10;
          }
          process = 5;
        }
        break;
    }
    step++;
  }
  return result;
}

int s21_get_element_sing_int(const char *str, int *start_index, Specifier *spec,
                             va_list varg, char type_int) {
  int stop = 0, curent_el = -1;
  curent_el = s21_integer_find(str, start_index, type_int, spec);
  if (curent_el != -1) {
    if (spec->star == 0) {
      if (spec->len == 'h')
        *(va_arg(varg, short int *)) =
            (short int)s21_get_int_num(str, start_index, type_int, spec);
      else if (spec->len == 'l')
        *(va_arg(varg, long int *)) =
            (long int)s21_get_int_num(str, start_index, type_int, spec);
      else
        *(va_arg(varg, int *)) =
            (int)s21_get_int_num(str, start_index, type_int, spec);
    } else
      s21_get_int_num(str, start_index, type_int, spec);
  } else {
    stop = 1;
  }
  return stop;
}

int s21_get_element_unsing_int(const char *str, int *start_index,
                               Specifier *spec, va_list varg, char type_int) {
  int stop = 0, curent_el = -1;
  curent_el = s21_integer_find(str, start_index, type_int, spec);
  if (curent_el != -1) {
    if (spec->star == 0) {
      if (spec->len == 'h')
        *(va_arg(varg, unsigned short int *)) =
            (short int)s21_get_int_num(str, start_index, type_int, spec);
      else if (spec->len == 'l')
        *(va_arg(varg, unsigned long int *)) =
            (long int)s21_get_int_num(str, start_index, type_int, spec);
      else
        *(va_arg(varg, unsigned int *)) =
            (int)s21_get_int_num(str, start_index, type_int, spec);
    } else
      s21_get_int_num(str, start_index, type_int, spec);
  } else {
    stop = 1;
  }
  return stop;
}
int s21_get_element_double(const char *str, int *start_index, Specifier *spec,
                           va_list varg) {
  int stop = 0, curent_el = -1;
  curent_el = s21_double_find(str, start_index, spec);
  if (curent_el != -1) {
    if (spec->star == 0) {
      if (spec->len == 'L')
        *(va_arg(varg, long double *)) =
            (long double)s21_get_double_num(str, start_index, spec);
      else
        *(va_arg(varg, float *)) =
            (double)s21_get_double_num(str, start_index, spec);
    } else
      s21_get_double_num(str, start_index, spec);
  } else {
    stop = 1;
  }
  return stop;
}