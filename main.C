#include <locale.h>
#include "work_file.h"

int main(void){
   char *locale = setlocale(LC_ALL, "");
   call_func();
   return 0;
 }