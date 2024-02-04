#ifndef S21_CAT_H
#define S21_CAT_H

#define PROGNAME "S21_CAT"

#ifdef APPLE
#define WRONG_OPT "%s: illegal option -- %s"
#else
#define WRONG_OPT "%s: invalid option -- \'%s\'\n"
#endif

#define WRONG_FILE "%s: %s: No such file or directory\n"

#endif