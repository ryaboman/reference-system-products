#include <stdio.h>
#include <string.h>

#include "base.h"

/*******************************************************************************/

static char* korrect[] = 
     {
          " 1 > ����� ������",
          " 2 > ���������� ������",
          " 3 > ���� ������",
          " 4 > ����� ���������� ������",
          " 5 > ����������� ������",
          " 0 > �����",
          " ? > "
     };
 
/*******************************************************************************/     

void kor_name(struct TOVAR *M) 
{
   puts(" ������� ����� �� ������");
   fflush(stdin);
   gets(M->name);
}      

/**************************/ 

void kor_kol(struct TOVAR *M)
{
   puts(" ������� ����� ���������� ������ (��������: 12 �� ��� 15 ��)");
   scanf_kptovar(&M->kol);
} 
 
/**************************/  
 
void kor_price(struct TOVAR *M) 
{
   puts(" ������� ����� ���� ������ (��������: 15 $ ��� 180 ���)");
   scanf_kptovar(&M->price);
}  

/**************************/ 

void kor_date(struct TOVAR *M) 
{
   puts(" ������� ����� ���� ���������� ������");
   scanf_date(&M->date);
}

/**************************/  
 
void kor_sup(struct TOVAR *M)  
{
   puts(" ������� ����� ����������� ������");
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
          puts("\n�������������:");
          for(i=0; i<7; i++)
            printf("\n%s", korrect[i]);
          scanf("%d",&g);
          if(g == 0)
            return ;
          printf("\n");
         }                
       switch_kor_tovar(g,&M[m]);  
       puts("     ����� ������� �� �������������!");   
       }     
      m=Vyxod(); 
    }
    while(m == 1);  
     
}

/*******************************************************************************/

void poisk_kol(struct TOVAR *M, int B) //������ ������ ������ �� ��� ����������
{
    int i, n=0;
    struct kp_tovar A;
    printf(" ������� ���������� ������ (��������: 12 �� ��� 15 ��)\n");
    scanf_kptovar(&A);
    for(i=0; i<B; i++)
        if( sravneniya(&M[i].kol, &A) == 0)
           n = printf_name_tovar(M, i);            
    if(n!=1)
       printf(" ����� �� ������!\n");             
}  

/**************************/   

void poisk_price(struct TOVAR *M, int B)  //������ ������ ������ �� ��� ����
{
    int i, n=0;
    struct kp_tovar A;
    printf(" ������� ���� ������ (��������: 12 $ ��� 180 ���)\n");
    scanf_kptovar(&A);    
    for(i=0; i<B; i++)
      if(sravneniya(&M[i].price, &A) == 0 )
         n = printf_name_tovar(M, i);         
    if(n!=1)
       printf(" ����� �� ������!\n");              
}    

/**************************/ 

void poisk_sup(struct TOVAR *M, int B)  //������ ������ ������ �� ��� ����������
{
    int j, i, n=0;
    char A[80];
    printf(" ������� ���������� ������\n");
    fflush(stdin);
    gets(A);    
    for(i=0; i<B; i++)
      for(j=0; j<M[i].sup.number; j++)
        if(0 == strcmp(A,M[i].sup.post[j]))
           n = printf_name_tovar(M, i);             
    if(n!=1)
       printf(" ����� �� ������!\n");           
}    

/**************************/ 

void poisk_kps(struct TOVAR *M, int B)  //������ ������ ������ �� ��� ����������, ���� � ����������
 {
    int j=0, i, l=1, h=0, m, n;
    struct kp_tovar a, A;
    char  S[80];
    printf(" ������� ���������� ������ (��������: 12 �� ��� 15 ��)\n");
    scanf_kptovar(&a);
    printf(" ������� ���� ������ �� %s (��������: 15 $ ��� 180 ���)\n", a.A);
    scanf_kptovar(&A);
    printf(" ������� ���������� ������\n");
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
      printf(" ����� �� ������!\n");                   
 }
 
/**************************/

