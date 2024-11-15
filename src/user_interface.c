#include "base.h"

#include <stdio.h>

/*******************************************************************************/  
 
static char* menu[]=
 {
   " 1 > добавление товара",
   " 2 > вывод информации по заданному названию товара",
   " 3 > вывод списка товаров с истекшим сроком реализации",
   " 4 > формирование списка поставщиков указанной продукции",
   " 5 > выполнение заказа на приобретение товара",
   " 6 > удаление товара",
   " 7 > корректировка товара",
   " 8 > поиск товара",
   " 0 > выход",
   " ? > "    
 };
 
/**************************/  
 
void printf_info(void)
 { 
   printf("Программа \"справочная система товары\"\n");
   printf("Автор: Рябов  А.А.\n");
   printf("_______________\n");
 }  

/**************************/ 
 
void Menu_Printf(struct TOVAR *M, int N) //функция вывода имен товара
 {
   int i;
   for(i=0; i<N; i++)
     printf("   | %s;\n", M[i].name);
   printf("\n");
   return ;
 }
 
/**************************/ 
  
int menu_f(struct TOVAR *M, int N) 
 {    
      int i, number;    
      FILE *fp;
      do 
       {
         printf("\nКоличество продукции в магазине %d\n",N);
         if(N==0)
           printf("%s\n", menu[0]);
         else 
          { 
           fp=fopen("tovar","rb");   
           fread(M ,sizeof(struct TOVAR), N, fp);
           fclose(fp);
           printf(" Список продукции нашего магазина\n\n");
           Menu_Printf(M,N);   
           for(i=0; i<8; i++)
             printf("%s\n",menu[i]);
          } 
         printf("%s\n", menu[8]);
         printf("%s\a", menu[9]);
         fflush(stdin);
         scanf("%d",&number);
       }
      while(number < 0 || number > 8);
      return number; 
 }

/*******************************************************************************/ 
 
void Delete_Element(struct TOVAR *M, int &N)
{
  int i;
  while(N != 0)
   {
    i=Soarch_Element(M, N);
    if(i >= 0)
        {
          M[i] = M[N-1];
          N --;
          puts("     товар успешно удален!");
        }
    if(N != 0 && Vyxod() == 0 )                   
      break; 
   }  
}

/*******************************************************************************/

void Dobavit_Element(struct TOVAR *M, int &B)
{
    int j, N;
    N=B;
    do
     {
		 
       if((B-N) == 11)
       {
         printf("  невозможно добавить товар!\n  Попробуйте повторить\n");
         break; 
       }    
	   
       M+=B; 
       B++;     
       puts("Введите:");
       puts("  название товара");
       fflush(stdin);
       gets(M->name);
       puts("  количество товара (например: 12 кг или 15 шт)");
       scanf_kptovar(&M->kol);
       printf("  цену  товара за %s (например: 15 $ или 180 руб)\n", M->kol.A);
       scanf_kptovar(&M->price);
       puts("  срок реализации товара");
       scanf_date(&M->date);
       puts("  поставщика товара");
       scanf_post_tovar(&M->sup);
       puts("     товар успешно добавлен!");
       j=Vyxod();
     } 
     while(j == 1);        
}  
 
/*******************************************************************************/ 

 
