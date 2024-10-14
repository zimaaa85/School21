#include "s21_grep.h"

int main(int argc, char **argv) {
  s21_grep_programm(argc, argv);
  return 0;
}

void s21_grep_programm(int argc, char **argv) {
  if (argc > 1) {
    char *temp = NULL;
    flags config = {0};

    for (int x = parser(argc, argv, &config, &temp); x < argc; x += 1)
      grep_s21(argv[x], config, temp);

    if (temp != NULL) free(temp);
  }
}

int parser(int argc, char **argv, flags *config, char **template) {
  for (int sym = 0; (sym = getopt(argc, argv, "e:ivclnhsf:o")) != (-1);) {
    switch (sym) {
      case 'i':
        config->flag_i = 1;  //Игнорирует различия регистра.
        break;
      case 'v':
        config->flag_v = 1;  //Инвертирует смысл поиска соответствий.
        break;
      case 'c':
        config->flag_c = 1;  //Выводит только количество совпадающих строк.
        break;
      case 'l':
        config->flag_l = 1;  //Выводит только совпадающие файлы.
        break;
      case 'n':
        config->flag_n =
            1;  //Предваряет каждую строку вывода номером строки из файла ввода.
        break;
      case 'h':
        config->flag_h =
            1;  //Выводит совпадающие строки, не предваряя их именами файлов.
        break;
      case 's':
        config->flag_s = 1;  //Подавляет сообщения об ошибках о несуществующих
                             //или нечитаемых файлах.
        break;
      case 'o':
        config->flag_o =
            1;  //Печатает только совпадающие (непустые) части совпавшей строки.
        break;
      case 'e':
        config_E_flag(config, template, optarg);  //Шаблон.
        break;
      case 'f':
        config_F_flag(config, template,
                      optarg);  //Получает регулярные выражения из файла.
        break;
    }
  }
  if ((config->flag_e || config->flag_f) == 0) {
    create_template(template, argv[optind]);
    optind += 1;
  }
  setup_config(config, argc);
  return optind;
}

void grep_s21(char *path, flags config, char *template) {
  FILE *file = fopen(path, "r");
  if (file != NULL) {
    for (char sym = '0'; (sym = getc(file)) != EOF;) {
      char *line = calloc(256, 1);
      config.numberLine += 1;
      int length = 0;

      for (line[length] = '\0'; sym != EOF && sym != '\n'; sym = getc(file)) {
        line[length] = sym;
        line[length += 1] = '\0';
        if (length % 255 == 0) line = increase_length_str(line, length + 256);
      }

      print_data_line(line, &config, template, path);
      free(line);
    }
    printf_aux_data(config, path);
    fclose(file);
  } else if (config.flag_s == 0) {
    fprintf(stderr, ERROR, path);
  }
}

void config_F_flag(flags *config, char **template, char *optarg) {
  FILE *file = fopen(optarg, "r");
  if (file != NULL) {
    for (char sym = '0'; (sym = getc(file)) != EOF;) {
      int length = 0;
      char *line = calloc(256, 1);

      for (line[length] = '\0'; sym != EOF && sym != '\n'; sym = getc(file)) {
        line[length] = sym;
        line[length += 1] = '\0';
        if (length % 255 == 0)
          line = (char *)increase_length_str(line, length + 256);
      }

      if (!(config->flag_e || config->flag_f))
        config->flag_f = create_template(template, line);
      else
        add_template(template, line);
      free(line);
    }
    fclose(file);
  } else if (config->flag_s == 0) {
    fprintf(stderr, ERROR, optarg);
  }
}

void config_E_flag(flags *config, char **template, char *optarg) {
  if (!(config->flag_e || config->flag_f))
    config->flag_e = create_template(template, optarg);
  else
    add_template(template, optarg);
}

void printf_aux_data(flags config, char *path) {
  if (config.flag_c) {
    if (config.flag_l) {
      config.countFiles > 1 ? printf("%s:1\n", path) : printf("1\n");
    } else {
      if (config.countFiles > 1) printf("%s:", path);
      printf("%i\n", config.countMatches);
    }
  }
  if (config.flag_l && config.countMatches) printf("%s\n", path);
}

void print_data_line(char *line, flags *config, char *template, char *path) {
  regex_t regex;
  if (regcomp(&regex, template, config->flag_i ? REG_ICASE : REG_EXTENDED) ==
      0) {
    if (regexec(&regex, line, 0, NULL, 0) == config->flag_v) {
      config->countMatches += 1;
      if ((config->flag_c || config->flag_l) == 0) {
        if (!(config->flag_o)) {
          if (config->countFiles > 1 && !(config->flag_h)) printf("%s:", path);
          if (config->flag_n) printf("%i:", config->numberLine);
          printf("%s\n", line);
        } else
          config_O_flag(line, regex, config, path);
      }
    }
    regfree(&regex);
  }
}

int config_O_flag(char *string, regex_t regex, flags *config, char *path) {
  regmatch_t pmatch[1];
  regex_t preg = regex;
  int found = 0;
  while (regexec(&preg, string, 1, pmatch, 0) == 0) {
    if (config->countFiles > 1 && !(config->flag_h)) printf("%s:", path);
    if ((config->flag_n)) printf("%i:", config->numberLine);
    for (int j = 0; j < pmatch->rm_eo; j++) {
      if (j >= pmatch->rm_so) {
        printf("%c", string[j]);
      }
      string[j] = 127;
    }
    printf("\n");
    found = 1;
  }
  return found;
}

void setup_config(flags *config, int argc) {
  if (config->flag_o && (config->flag_l || config->flag_v || config->flag_c))
    config->flag_o = 0;
  config->countFiles = argc - optind;
}

int create_template(char **str, char *optarg) {
  *str = calloc(strlen(optarg) + 1, 1);
  if (*str) strcpy(*str, optarg);
  return str ? 1 : 0;
}

void add_template(char **str, char *optarg) {
  *str = increase_length_str(*str, strlen(*str) + strlen(optarg) + 2);
  if (*str) strcat(strcat(*str, "|"), optarg);
}

void *increase_length_str(void *str, int size) {
  char *aux = realloc(str, size);
  return aux;
}
