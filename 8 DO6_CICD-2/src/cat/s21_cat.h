#ifndef S21_CAT_H_
#define S21_CAT_H_

#include <ctype.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 1024

typedef struct {
  int flag_b;
  int flag_e;
  int flag_n;
  int flag_s;
  int flag_t;
  int flag_v;
  int flag_err;
} flags;

int parser(int argc, char *argv[], flags *flag);
void cat(char *path, flags flag);

#endif  // S21_CAT_H_