#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const char *temp = (const char *)str;
  void *result = s21_NULL;
  int flag = 0;
  for (s21_size_t i = 0; i < n && n != 0 && flag == 0; i++) {
    if (*(temp + i) == c) {
      flag = 1;
      result = (void *)(temp + i);
    }
  }
  return result;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const char *temp1 = (const char *)str1;
  const char *temp2 = (const char *)str2;
  for (size_t i = 1; *temp1 && *temp1 == *temp2 && i < n;
       temp1++, temp2++, i++) {
    continue;
  }
  int result = 0;
  if (n != 0) {
    result = *temp1 - *temp2;
  }
  return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned int cnt = 0;
  for (; cnt < n; src++, dest++, cnt++) {
    *((char *)dest) = *((char *)src);
  }
  dest -= cnt;
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  s21_size_t cnt = 0;
  for (; cnt < n; cnt++, str++) {
    *((char *)str) = (char)c;
  }
  str -= n;
  return str;
}

char *s21_strncat(char *dest, const char *append, s21_size_t n) {
  unsigned int destLen = 0;
  while (*dest != '\0') {
    dest++;
    destLen++;
  }
  unsigned int cnt = 0;
  for (; cnt < n && *append != '\0' && n != 0; append++, dest++, cnt++)
    *dest = *append;

  if (s21_strlen(append) > n && n != 0) {
    *(dest + 1) = '\0';
  }
  dest -= (cnt + destLen);
  return dest;
}

char *s21_strchr(const char *str, int c) {
  s21_size_t cnt = 0;
  char *result = s21_NULL;
  int flag = 0;
  if (c == '\0') {
    result = (char *)(str + s21_strlen(str));
  } else {
    for (; *str != '\0' && flag == 0; str++, cnt++) {
      if (*(char *)str == c) {
        result = (char *)str;
        flag = 1;
      }
    }
  }
  return result;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  for (size_t i = 1; *str1 && *str1 == *str2 && i < n; str1++, str2++, i++) {
    continue;
  }
  int result = 0;
  if (n != 0) {
    result = *str1 - *str2;
  }
  return result;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t cnt = 0;
  if (*src == '\0') {
    *dest = '\0';
  }
  while (src[cnt] != '\0' && cnt < n) {
    dest[cnt] = src[cnt];
    cnt++;
  }
  if (n > s21_strlen(dest)) {
    dest[cnt] = '\0';
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = s21_strlen(str1);
  int flag = 0;
  for (int i = 0; *(str1 + i) != '\0' && flag == 0; ++i) {
    for (int j = 0; *(str2 + j) != '\0' && flag == 0; ++j) {
      if (*(str1 + i) == *(str2 + j)) {
        flag = 1;
        result = i;
      }
    }
  }
  return result;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  int cnt2 = 0;
  for (; *str1 != '\0'; str1++) {
    for (; *str2 != '\0'; str2++, cnt2++) {
      if (*str1 == *str2) return (char *)str1;
    }
    str2 -= cnt2;
    cnt2 = 0;
  }
  return s21_NULL;
}

char *s21_strrchr(const char *str, int c) {
  char *ptr = s21_NULL;
  for (; *str != '\0'; str++) {
    if (*str == (char)c) ptr = (char *)str;
  }
  if (c == '\0') {
    ptr = (char *)str;
  }
  return ptr;
}

char *s21_strstr(const char *haystack, const char *needle) {
  int cnt = 0, flag = 0;
  char *result = s21_NULL;
  if (s21_strlen(needle) == 0) {
    result = (char *)haystack;
    flag = 1;
  }
  for (; *haystack != '\0' && flag == 0; haystack++) {
    if (*needle == *haystack) {
      for (; needle != s21_NULL && flag == 0; needle++, haystack++, cnt++) {
        if (*haystack != *needle && *needle != '\0') {
          needle -= cnt;
          haystack -= cnt;
          cnt = 0;
          break;
        }
        if (*needle == '\0') {
          flag = 1;
          result = (char *)(haystack - cnt);
        }
      }
    }
  }
  return result;
}

char *s21_strtok(char *s, const char *delim) {
  static char *olds = s21_NULL;
  char *token = s21_NULL;
  char *result = s21_NULL;
  if (s == s21_NULL) s = olds;
  s += s21_strspn(s, delim);
  if (*s == '\0') {
    olds = s;
  } else {
    token = s;
    s = s21_strpbrk(token, delim);
    if (s == s21_NULL)
      olds = s21_strchr(token, '\0');
    else {
      *s = '\0';
      olds = s + 1;
    }
    result = token;
  }
  return result;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t cnt = 0;
  int s1len = 0;
  int s2len = 0;
  for (; *str1 != '\0'; str1++) {
    for (; *str2 != '\0'; str2++, s2len++) {
      if (*str1 == *str2) {
        str2 -= s2len;
        s2len = 0;
        cnt++;
        break;
      }
    }
  }
  str1 -= s1len;
  return cnt;
}

void *s21_to_upper(const char *str) {
  s21_size_t size = s21_strlen(str);
  void *result = s21_NULL;
  if (size >= 1) {
    char *nstr = (char *)calloc(size + 1, size + 1);
    s21_strncpy(nstr, str, s21_strlen(str));
    s21_size_t i = 0;
    for (; i < size; ++i) {
      if (nstr[i] >= 97 && nstr[i] <= 122) {
        nstr[i] = nstr[i] - 32;
      }
    }
    nstr[size] = '\0';
    result = (void *)nstr;
  }
  return result;
}

void *s21_to_lower(const char *str) {
  s21_size_t size = s21_strlen(str);
  void *result = s21_NULL;
  if (size > 0) {
    char *nstr = (char *)calloc(size + 1, size + 1);
    s21_strncpy(nstr, str, s21_strlen(str));
    s21_size_t i = 0;
    for (; i < size; ++i) {
      if (nstr[i] >= 65 && nstr[i] <= 90) {
        nstr[i] = nstr[i] + 32;
      }
    }
    nstr[i] = '\0';
    result = (void *)nstr;
  }
  return result;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t size = s21_strlen(str) + s21_strlen(src);
  void *result = s21_NULL;
  int flag = 1;
  if (size > 0) {
    char *nstr = (char *)calloc(size + 1, size + 1);
    s21_strncpy(nstr, src, start_index);
    s21_size_t i = start_index;
    for (; i < s21_strlen(str) + start_index && flag == 1; ++i) {
      if (str[i - start_index] == '\0') {
        flag = 0;
      } else {
        nstr[i] = str[i - start_index];
      }
    }
    s21_size_t j = 0;
    for (; i < size && flag == 1; ++i, ++j) {
      nstr[i] = src[start_index + j];
    }
    nstr[i] = '\0';
    result = (void *)nstr;
  }
  return result;
}

void *s21_trim(const char *src, const char *trim_chars) {
  s21_size_t size = s21_strlen(src);
  void *result = (void *)src;
  int flag = 1;
  if (s21_strlen(trim_chars) == 0) {
    flag = 0;
    result = s21_NULL;
  }
  if (size > 0 && flag) {
    char *nstr = (char *)calloc(size + 1, size + 1);
    size_t indexStart = 0;
    while (flag && indexStart < s21_strlen(src)) {
      if (s21_strrchr(trim_chars, src[indexStart])) {
        indexStart++;
      } else {
        flag = 0;
      }
    }
    flag = 1;
    size_t indexEnd = s21_strlen(src) - 1;
    while (flag && indexEnd > indexStart) {
      if (s21_strrchr(trim_chars, src[indexEnd])) {
        indexEnd--;
      } else {
        flag = 0;
      }
    }
    s21_strncpy(nstr, src + indexStart, indexEnd - indexStart + 1);
    nstr[indexEnd - indexStart + 1] = '\0';
    result = nstr;
  } else {
    result = s21_NULL;
  }
  return result;
}

void s21_strcpy(char *buf, char *str) {
  int n = 0;
  for (; *str != '\0'; str++, n++) {
    *buf = *str;
    buf++;
  }
  buf -= n;
}

void s21_reverse(char s[]) {
  int i = 0, j = 0;
  char c = 1;
  for (i = 0, j = s21_strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void s21_itoa(int n, char s[]) {
  int i = 0, sign = 0;
  if ((sign = n) < 0) n = -n;
  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0) s[i++] = '-';
  s[i] = '\0';
  s21_reverse(s);
}

void s21_litoa(long int n, char s[]) {
  long int i = 0, sign = 0;
  if ((sign = n) < 0) n = -n;
  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0) s[i++] = '-';
  s[i] = '\0';
  s21_reverse(s);
}

void s21_uitoa(unsigned int n, char s[]) {
  int i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  s[i] = '\0';
  s21_reverse(s);
}

int s21_atoi(char *str) {
  int res = 0, sign = 1, i = 0;
  if (str[0] == '-') {
    sign = -1;
    i++;
  }
  for (; str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; ++i)
    res = res * 10 + str[i] - '0';
  return sign * res;
}

static const long double rounders[15] = {
    0.5,               // 0
    0.05,              // 1
    0.005,             // 2
    0.0005,            // 3
    0.00005,           // 4
    0.000005,          // 5
    0.0000005,         // 6
    0.00000005,        // 7
    0.000000005,       // 8
    0.0000000005,      // 9
    0.00000000005,     // 10
    0.000000000005,    // 11
    0.0000000000005,   // 12
    0.00000000000005,  // 13
    0.000000000000005  // 14
};

void s21_ftoa(long double n, char *s, unsigned int prec) {
  long double abs = n;
  int iterator = 0;
  if (abs < 0) {
    abs = -n;
    s[iterator] = '-';
    iterator++;
  }
  prec++;
  int64_t delim = 10;
  int64_t x = (int64_t)abs / 1.0;
  int count = 1;
  while (x / delim >= 1) {
    count++;
    delim *= 10;
  }
  int64_t print = 0;
  long double part = abs;
  for (int i = count - 1; i >= 0; i--) {
    print = (x / (int64_t)powl(10, i));
    x -= print * (int64_t)powl(10, i);
    part -= print * (int64_t)powl(10, i);
    s[iterator] = print + 48;
    iterator++;
  }
  if (1 < prec) {
    s[iterator] = '.';
    iterator++;
    if (prec > 0 && prec < 14) {
      part += rounders[prec - 1];
    }
    for (int i = 1; i < (int)prec; i++) {
      part *= 10;
      print = (int)part % (int64_t)powl(10, i);
      part -= print;
      s[iterator] = print + 48;
      iterator++;
    }
  }
}

void s21_gftoa(double n, char *s, unsigned int prec) {
  if (n == 0) {
    *s = '0';
    s++;
  } else {
    int count_zeroes = 0;
    double sign = n;
    if (sign < 0) n = -n;
    double finteger, part;
    part = modf(n, &finteger);
    double nepart = part;
    if (part < 0.1 && part > 0) {
      for (; nepart < 0.1; nepart *= 10, count_zeroes++) {
        continue;
      }
    }
    long long integer = (long long)finteger;
    char integerS[500] = {"0"};
    char partS[500] = {"0"};
    s21_itoa(integer, integerS);
    if (s21_strlen(integerS) <= 6) {
      prec = abs(6 - (int)s21_strlen(integerS));
    } else
      prec = 1;
    part *= pow(10, (int)prec);
    part += 0.5;
    long long ipart = (long long)part;
    s21_itoa(ipart, partS);
    if (sign < 0) {
      *s = '-';
      s++;
    }
    s21_strcpy(s, integerS);
    if (prec > 0 && part != 0.5) {
      s += s21_strlen(s);
      *s = '.';
      s++;
      if (count_zeroes > 0) {
        for (; count_zeroes != 0; count_zeroes--, s++) {
          *s = '0';
        }
      }
      if (part == 0.5) {
        for (; prec != 0; s++, prec--) {
          *s = '0';
        }
      } else {
        s21_strcpy(s, partS);
        s += s21_strlen(partS) - 1;
      }
    }
    while (*s == '0') {
      *s = '\0';
      s--;
    }
  }
}

void s21_ptrtoa(intptr_t *p, char *str) {
  for (int i = 2 * sizeof(*p) - 1; i >= 0; --i) {
    str[i] = "0123456789abcdef"[(*p) & 0x0F];
    *p >>= 4;
  }
  str[3] = 'x';
}
