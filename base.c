#include <stdio.h>
#include <time.h>
#include <string.h>


#include "base.h"


void printf_date(struct tm *t) //функция вывода срока реализации товара на экран
 {
   int tj;                    
   if (9 >= t->tm_mday)                  
      printf("  0%d.",t->tm_mday); 
   else  
      printf("  %d.",t->tm_mday); 
   if (9 >= t->tm_mon)
      printf("0%d.",t->tm_mon); 
   else       
      printf("%d.",t->tm_mon);
   tj=t->tm_year+1900; 
   printf("%d\n",tj);                  
 }
 
/**************************/ 

void printf_kptovar(struct kp_tovar *f) //функция вывода на экран цены и количества товара
 {
    printf("  %f", f->kp);
    printf(" %s\n", f->A); 
 }
 
/**************************/

void printf_post_tovar(struct post_tovar *N) //функция вывода поставщиков на экран
{
   int i;
   for( i=0; i<N->number; i++)
     printf("  %s\n", N->post[i]);
   return ;  
}

/**************************/ 
 
int printf_name_tovar(struct TOVAR *M, int i)
{
      printf("_______________");   
      printf("\n товар\n  %s\n", M[i].name);         
      puts(" количество"); 
      printf_kptovar( &M[i].kol);
      printf(" цена за %s\n", M[i].kol.A);
      printf_kptovar( &M[i].price);
      puts(" срок реализации"); 
      printf_date(&M[i].date);
      puts(" поставщик(и)");  
      printf_post_tovar(&M[i].sup);
      return 1;  
}

/*******************************************************************************/

void scanf_kptovar(struct kp_tovar *f)  //функция ввода цены и количества товара
 {
    do
    { 
      fflush(stdin); 
      scanf("%f", &f->kp); 
      scanf("%s", &f->A);
      if(f->kp < 0)
        printf(" значение не должно быть отрицательным!\n  повторите\n");   
    }
    while(f->kp < 0);
    return ;         
 }

/*******************************************************************************/

void scanf_post_tovar(struct post_tovar *N) //функция ввода поставщиков
{
   int i, n;
   N->number = 0; 
   for (i=0; i<80; i++)
    {
       fflush(stdin); // очистить буфер
       gets(N->post[i]);
       N->number ++;
       n=2; 
       while(n < 0 || n > 1)
        {  
          printf("\n1 > ЕЩЕ ПОСТАВЩИК\n");   
          printf("0 > ХВАТИТ\n");
          printf("? > ");
          fflush(stdin); 
          scanf("%d",&n); 
          printf("\n");
          if (n == 0)
            return ; 
        } 
    }   
                          
}

/*******************************************************************************/

int sravneniya(struct kp_tovar *H, struct kp_tovar *N) //функция сравнения двух цен или двух количеств товара
{
   if( 0 == strcmp(H->A, N->A))
    if(  N->kp == H->kp )
      return 0; //одинаковы вернуть 0
   return 1;    //разные вернуть 1
} 

/*******************************************************************************/ 
 
int Soarch_Element(struct TOVAR *M, int B)     
  {
     int L = 0, R = B-1, m, flag = 0; // переменная-флаг, нашли (1) или нет (0)
     char A[80];
     printf("\n Введите название товара\n");
     fflush(stdin);
     gets( A );
     while ( L <= R ) 
       { 
         m = (L + R) / 2; // середина интервала
         if ( 0 == strcmp(A,M[m].name ))// нашли нужный элемент
           { 
             flag = 1; // установить флаг
             return m; //индекс найденного элемента
           } 
         if ( 0 > strcmp(A,M[m].name) ) 
             R = m - 1; // сужаем границы области поиска
         else 
             L = m + 1;
       }
     if ( flag == 0 )
      { 
        printf ( "Такой товар не найден!\n\n" ); 
        return -1;
      }   
   }   

/*******************************************************************************/

int prov_date(struct tm *t) //функция проверки правильного ввода срока реализации
 {
    int n=0, i;
    if( t->tm_mon > 12 || t->tm_mon < 1 && t->tm_mday < 1 || t->tm_mday > 31 )
      n=1;            
    switch(t->tm_mon)
        { 
          case 2:
           {
              if( t->tm_mday > 28)
               {
                i = t->tm_year%4;
                if(i != 0 || t->tm_mday != 29)
                  n=1;
               }   
              break;    
           }                               
          case 4:
          case 6:
          case 9:
          case 11:
            {  
              if(t->tm_mday > 30)   
                n=1;
              break;
            } 
          default : break;                                    
         }
    if(n)
      {
       printf(" Ошибка срока реализации!\n повторите\n");
       return 1;
      } 
    return 0;       
 }
 
/*******************************************************************************/

int scanf_date(struct tm *t) //функция ввода срока реализации товара
 {
   int tj, i=1; 
   do 
     {                                 
      puts("    Введите число месяца (от 1 до 31)");
      scanf("%d",&t->tm_mday); //Число месяца(1,31)
      puts("    Введите месяц (от 1 до 12)");
      scanf("%d",&t->tm_mon);  // Месяцы после января(0,11)
      puts("    Введите год");
      scanf("%d",&tj);
      t->tm_year=tj-1900;  //Годы с 1900(в Windows), с 1970(в Unix)
      i=prov_date(t);
     }
   while(i);  
   return 0;
 }

/*******************************************************************************/

int Vyxod(void)
 {
    int i=2; 
    while(i < 0 || i > 1)
    {  
      printf("\n1 > ПОВТОРИТЬ\n");   
      printf("0 > НАЗАД\n");
      printf("? > "); 
      fflush(stdin);  
      scanf("%d",&i);  
    }  
    return i;
 }

/*******************************************************************************/ 
