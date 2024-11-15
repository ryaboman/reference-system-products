#include <stdio.h>
#include <string.h>

#include "base.h"

/*******************************************************************************/

static char* korrect[] = 
     {
          " 1 > имени товара",
          " 2 > количества товара",
          " 3 > цены товара",
          " 4 > срока реализации товара",
          " 5 > поставщиков товара",
          " 0 > назад",
          " ? > "
     };
 
/*******************************************************************************/     

void kor_name(struct TOVAR *M) 
{
   puts(" ђведите новое им§ товара");
   fflush(stdin);
   gets(M->name);
}      

/**************************/ 

void kor_kol(struct TOVAR *M)
{
   puts(" ђведите новое количества товара (например: 12 кг или 15 шт)");
   scanf_kptovar(&M->kol);
} 
 
/**************************/  
 
void kor_price(struct TOVAR *M) 
{
   puts(" ђведите новую цену товара (например: 15 $ или 180 руб)");
   scanf_kptovar(&M->price);
}  

/**************************/ 

void kor_date(struct TOVAR *M) 
{
   puts(" ђведите новый срок реализации товара");
   scanf_date(&M->date);
}

/**************************/  
 
void kor_sup(struct TOVAR *M)  
{
   puts(" ђведите новых поставщиков товара");
   scanf_post_tovar(&M->sup);
}

/**************************/

void switch_kor_tovar(int g, struct TOVAR *M)
{
    switch(g)
     {
         case 1:
           {
             kor_name(M);
             break;
           }
         case 2:
           {
             kor_kol(M);
             break;
           }    
         case 3:
           {
             kor_price(M);
             break;
           }        
         case 4:
           {
             kor_date(M);
             break;
           }     
         case 5:
             kor_sup(M);  
     }        
}

/**************************/

void Korrected_tovar(struct TOVAR *M, int N)
{
    int m, g=-1, i;
    do
     {
       m=Soarch_Element(M, N);
       if(m >= 0)
       {
         while(g<0 || g>5)   
         {
          puts("\nкорректировка:");
          for(i=0; i<7; i++)
            printf("\n%s", korrect[i]);
          scanf("%d",&g);
          if(g == 0)
            return ;
          printf("\n");
         }                
       switch_kor_tovar(g,&M[m]);  
       puts("     Уовар успешно от корректирован!");   
       }     
      m=Vyxod(); 
    }
    while(m == 1);  
     
}

/*******************************************************************************/

void poisk_kol(struct TOVAR *M, int B) //функци§ поиска товара по его количеству
{
    int i, n=0;
    struct kp_tovar A;
    printf(" ђведите количество товара (например: 12 кг или 15 шт)\n");
    scanf_kptovar(&A);
    for(i=0; i<B; i++)
        if( sravneniya(&M[i].kol, &A) == 0)
           n = printf_name_tovar(M, i);            
    if(n!=1)
       printf(" товар не найден!\n");             
}  

/**************************/   

void poisk_price(struct TOVAR *M, int B)  //функци§ поиска товара по его цене
{
    int i, n=0;
    struct kp_tovar A;
    printf(" ђведите цену товара (например: 12 $ или 180 руб)\n");
    scanf_kptovar(&A);    
    for(i=0; i<B; i++)
      if(sravneniya(&M[i].price, &A) == 0 )
         n = printf_name_tovar(M, i);         
    if(n!=1)
       printf(" товар не найден!\n");              
}    

/**************************/ 

void poisk_sup(struct TOVAR *M, int B)  //функци§ поиска товара по его поставщику
{
    int j, i, n=0;
    char A[80];
    printf(" ђведите поставщика товара\n");
    fflush(stdin);
    gets(A);    
    for(i=0; i<B; i++)
      for(j=0; j<M[i].sup.number; j++)
        if(0 == strcmp(A,M[i].sup.post[j]))
           n = printf_name_tovar(M, i);             
    if(n!=1)
       printf(" товар не найден!\n");           
}    

/**************************/ 

void poisk_kps(struct TOVAR *M, int B)  //функци§ поиска товара по его количеству, цене и поставщику
 {
    int j=0, i, l=1, h=0, m, n;
    struct kp_tovar a, A;
    char  S[80];
    printf(" ђведите количество товара (например: 12 кг или 15 шт)\n");
    scanf_kptovar(&a);
    printf(" ђведите цену товара за %s (например: 15 $ или 180 руб)\n", a.A);
    scanf_kptovar(&A);
    printf(" ђведите поставщика товара\n");
    fflush(stdin);
    gets(S);
    for(i=0; i<B; i++)
     {
      n = sravneniya(&M[i].kol, &a);
      m = sravneniya(&M[i].price, &A);
      while(l!=0 && j<M[i].sup.number)
        { 
        l = strcmp(S,M[i].sup.post[j]);
        j++;
        }
      if( n == 0 && m == 0 && l == 0)
        h = printf_name_tovar(M, i);
     }  
    if (h == 0)
      printf(" товар не найден!\n");                   
 }
 
/**************************/

