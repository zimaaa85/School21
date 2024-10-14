#ifndef S21_GREP_H_
#define S21_GREP_H_

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR "grep_s21: %s: No such file or directory\n"

typedef struct {
  int flag_e;
  int flag_i;
  int flag_v;
  int flag_c;
  int flag_l;
  int flag_n;
  int flag_h;
  int flag_s;
  int flag_f;
  int flag_o;
  int countFiles;  // подсчет колисества файлов
  int numberLine;  // номер строки
  int countMatches;  //количество найденных совпадений
} flags;

void s21_grep_programm(int argc, char **argv);

int parser(int argc, char **argv, flags *config,
           char **template);  //обрабатывает аргументы командной строки.
void print_data_line(
    char *str, flags *flags, char *tmpl,
    char
        *name);  // Функция для поиска совпадений в строке line с использованием
                 // регулярного выражения из шаблона. Выводит найденные
                 // совпадения в соответствии с установленными флагами.
void config_F_flag(flags *config, char **template, char *optarg);
void config_E_flag(flags *config, char **template, char *optarg);
int config_O_flag(
    char *start_point, regex_t regex, flags *config,
    char *path);  // Функция для обработки флага -o. Ищет все совпадения в
                  // строке и заменяет их символом ASCII 127.
void grep_s21(char *name, flags config,
              char *tmpl);  // Функция grep_s21 выполняет поиск в файле name с
                            // использованием шаблона tmpl и структуры config.
void printf_aux_data(flags config,
                     char *path);  // Функция для вывода вспомогательных данных
                                   // в зависимости от установленных флагов.
void *increase_length_str(void *str,
                          int size);  //Функция для увеличения размера строки.
int create_template(
    char **str,
    char *optarg);  //Функция для создания шаблона из переданного аргумента.
void setup_config(flags *config,
                  int argc);  //Функция для настройки конфигурации на основе
                              //переданных аргументов командной строки.
void add_template(
    char **str,
    char *optarg);  // Функция для добавления нового шаблона к существующему.

#endif  // S21_GREP_H
