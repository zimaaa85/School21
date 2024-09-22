#include "s21_cat.h"

int main(int argc, char *argv[]) {
  int name_of_files;
  flags option = {0};
  name_of_files = parser(argc, argv, &option);

  if (option.flag_err == 1) {
    fprintf(stderr, "not option");
  } else {
    while (name_of_files < argc) {
      char *path;
      path = argv[name_of_files];
      cat(path, option);
      name_of_files++;
    }
  }
  return 0;
}

int parser(int argc, char *argv[], flags *flag) {
  const struct option long_options[] = {{"number-nonblank", 0, NULL, 'b'},
                                        {"number", 0, NULL, 'n'},
                                        {"squeeze-blank", 0, NULL, 's'},
                                        {NULL, 0, NULL, 0}};

  int opt = 0;

  while ((opt = getopt_long(argc, argv, "benstvET?", long_options, NULL)) !=
         -1) {
    switch (opt) {
      case 'b':  // нумерует только непустые строки
        flag->flag_b = 1;
        break;
      case 'e':  // также отображает символы конца строки как $
        flag->flag_e = flag->flag_v = 1;
        break;
      case 'n':  // нумерует все выходные строки
        flag->flag_n = 1;
        break;
      case 's':  //сжимает несколько смежных пустых строк
        flag->flag_s = 1;
        break;
      case 't':  // также отображает табы как ^I
        flag->flag_t = flag->flag_v = 1;
        break;
      case 'v':
        flag->flag_v = 1;
        break;
      case 'E':
        flag->flag_e = 1;
        break;
      case 'T':
        flag->flag_t = 1;
        break;
      case '?':
        flag->flag_err = 1;
        break;
    }
  }
  return optind;
}

void cat(char *path, flags flag) {
  if (access(path, F_OK) == 0) {
    FILE *filename;
    filename = fopen(path, "r");

    char ch, prev;

    int current_line = 1;
    int squeeze = 0;
    for (prev = '\n'; (ch = getc(filename)) != EOF; prev = ch) {
      if (flag.flag_s == 1) {
        if (ch == '\n' && prev == '\n') {
          if (squeeze == 1) {
            continue;
          }
          squeeze++;
        } else
          squeeze = 0;
      }

      if (flag.flag_b == 1) {
        if (prev == '\n' && ch != '\n') {
          printf("%*d\t", 6, current_line);
          current_line++;
        }
      }

      if (flag.flag_n == 1 && flag.flag_b == 0 && prev == '\n') {
        printf("%*d\t", 6, current_line);
        current_line++;
      }

      if (flag.flag_e == 1 && ch == '\n') {
        putchar('$');
      }

      if (flag.flag_t == 1 && ch == '\t') {
        printf("^");
        ch = 'I';
      }

      if (flag.flag_v == 1) {
        if ((ch >= 0 && ch <= 31) && ch != '\t' && ch != '\n') {
          printf("^");
          ch = ch + 64;

        } else if (ch == 127) {
          printf("^");
          ch = ch - 64;
        }
      }
      putchar(ch);
    }
    fclose(filename);
  } else {
    fprintf(stderr, "Нет такого файла или каталога: %s\n", path);
  }
}
