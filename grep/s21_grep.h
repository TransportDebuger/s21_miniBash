#ifndef S21_GREP_H
#define S21_GREP_H

#define PROGNAME "s21_grep"

#define WRONG_OPT "%s: unrecognized option \'%s\'\n"
#define WRONG_FILE "%s: %s: No such file or directory\n"
#define REGEX_COMP_ERR "Regex compilation error\n"
#define USAGE_MSG \
  "usage: grep [-ivclnhso]]\n \
        [-e pattern] [-f file] \n \
        [pattern] [file ...]\n"

#endif