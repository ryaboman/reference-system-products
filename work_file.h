
#include <stdio.h>

#ifndef work_file_h
#define work_file_h

int kolstrok(FILE *fp);
int KOL_STR(void);
int menu_2(struct TOVAR *M, int N, int k);
int menu_1(struct TOVAR *M, int N, int k);
int panel(struct TOVAR *M, int N, int k);
int sort_tovar(struct TOVAR *M, unsigned int n );
int fwrite_tovar(struct TOVAR *M, int B);
int call_func(void);

#endif
