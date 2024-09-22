#ifndef PRINT_DECIMAL_H
#define PRINT_DECIMAL_H

#include "s21_decimal.h"

#define PDB(A) print_bits(&A, sizeof A)
#define PDI(A) print_ints(&A, sizeof A)

void print_bits(const void *value, int val_size);
void print_ints(const void *value, int val_size);

s21_decimal decimal_from_string(const char *value);
void decimal_to_string(s21_decimal value, char *str);
void print_decimal(s21_decimal value);

#endif
