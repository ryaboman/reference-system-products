#include <stdio.h>
#include <string.h>
#include <time.h>

#include "base.h"
#include "edit_product.h"

/*******************************************************************************/

static char* poisk[] = 
     {
          "  1 > поиск товара по его количеству",
          "  2 > поиск товара по его цене",
          "  3 > поиск товара по его поставщику",
          "  4 > поиск товара по всем выше перечисленным пунктам",
          "  0 > назад",
          "  ? > "
     };

/*******************************************************************************/

void InfoTovar(struct TOVAR *M, int N)     
 {
    int m;
    do
     {
       m=Soarch_Element(M, N); 
       if(m >= 0)  
         printf_name_tovar(M, m);      
       m=Vyxod();
     }
    while(m == 1);
 }  
  
/*******************************************************************************/

void Postavshik(struct TOVAR *M, int N)  //функция формирования поставщиков товара
 {
   int i;
   do
   {
     i = Soarch_Element(M, N);
     if (i >= 0) 
       printf_post_tovar(&M[i].sup);  
     i=Vyxod();
   }  
   while(i == 1);
 }                  

/*******************************************************************************/ 
              
void Zakaz(struct TOVAR *M, int N)
 {
   int i;
   struct kp_tovar f;
   do
    {
      i = Soarch_Element(M, N);
      if(i >= 0)
        {  
          puts(" \nВведите количество заказываемого товара (например: 12 кг или 15 шт)\n");
          scanf_kptovar(&f);   
          if (strcmp(M[i].kol.A, f.A) != 0 || M[i].kol.kp < f.kp)
            puts("\n Такого количества нет в наличии\n");
          else 
          { 
           M[i].kol.kp -=  f.kp;
           printf("вы заказали\n");
           printf("  %s", M[i].name);
           printf(" в количестве\n");
           printf_kptovar(&f);
         } 
        }
       else 
         printf("товар не найден!\n");  
       i = Vyxod();
     }  
    while(i == 1);   
 }                  
  
/*******************************************************************************/
  
void SrokRealiz(struct TOVAR *M, int N)
 {
   int i;                  
   struct tm t;
   time_t t1, t2;  //Значение time_t  количество секунд прошедших с некоторой конкретной реализации базы времени.
   do
    {
     scanf_date(&t);
     t1=mktime(&t);  //mktime преобразует местное время, заданное структурой *tp в тип данных time_t
     for (i=0; i<N; i++)
      {
        t2=mktime(&M->date);     
        if (0 > difftime(t2, t1)) //difftime(t2, t1)  выдает pазницу (в секундах) между t2 и t1, типа double.  
          printf("\n%s",M->name);
        M++;     
      } 
     i=Vyxod();
    }   
   while(i == 1); 
 }   
  
/*******************************************************************************/

void search_switch(struct TOVAR *M, int N, int k)
{
   switch(k)
    {
       case 1 :
         {   
           poisk_kol(M, N);
           break; 
         }  
       case 2 :
         {   
           poisk_price(M, N);
           break; 
         }  
       case 3 :
         {   
           poisk_sup(M, N); 
           break;   
         }    
       case 4 :
         {
           poisk_kps(M, N);
           break;     
         }   
      default :
           break;                                 
    }        
}

/**************************/

void Poisk_tovar(struct TOVAR *M, int B)
 {
   int  j;
   while(1)
    {  
      printf("\n");      
      for(j=0; j<6; j++)
        printf("\n%s", poisk[j]);   
      scanf("%d",&j);
      if (j == 0)
        break;
      if (j<1 || j>6)
        continue;
      search_switch(M, B, j);
    } 
 } 
    
/*******************************************************************************/
