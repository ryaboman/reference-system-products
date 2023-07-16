#include <stdio.h>
#include <time.h>
#include <string.h>


#include "base.h"


void printf_date(struct tm *t) //������� ������ ����� ���������� ������ �� �����
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

void printf_kptovar(struct kp_tovar *f) //������� ������ �� ����� ���� � ���������� ������
 {
    printf("  %f", f->kp);
    printf(" %s\n", f->A); 
 }
 
/**************************/

void printf_post_tovar(struct post_tovar *N) //������� ������ ����������� �� �����
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
      printf("\n �����\n  %s\n", M[i].name);         
      puts(" ����������"); 
      printf_kptovar( &M[i].kol);
      printf(" ���� �� %s\n", M[i].kol.A);
      printf_kptovar( &M[i].price);
      puts(" ���� ����������"); 
      printf_date(&M[i].date);
      puts(" ���������(�)");  
      printf_post_tovar(&M[i].sup);
      return 1;  
}

/*******************************************************************************/

void scanf_kptovar(struct kp_tovar *f)  //������� ����� ���� � ���������� ������
 {
    do
    { 
      fflush(stdin); 
      scanf("%f", &f->kp); 
      scanf("%s", &f->A);
      if(f->kp < 0)
        printf(" �������� �� ������ ���� �������������!\n  ���������\n");   
    }
    while(f->kp < 0);
    return ;         
 }

/*******************************************************************************/

void scanf_post_tovar(struct post_tovar *N) //������� ����� �����������
{
   int i, n;
   N->number = 0; 
   for (i=0; i<80; i++)
    {
       fflush(stdin); // �������� �����
       gets(N->post[i]);
       N->number ++;
       n=2; 
       while(n < 0 || n > 1)
        {  
          printf("\n1 > ��� ���������\n");   
          printf("0 > ������\n");
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

int sravneniya(struct kp_tovar *H, struct kp_tovar *N) //������� ��������� ���� ��� ��� ���� ��������� ������
{
   if( 0 == strcmp(H->A, N->A))
    if(  N->kp == H->kp )
      return 0; //��������� ������� 0
   return 1;    //������ ������� 1
} 

/*******************************************************************************/ 
 
int Soarch_Element(struct TOVAR *M, int B)     
  {
     int L = 0, R = B-1, m, flag = 0; // ����������-����, ����� (1) ��� ��� (0)
     char A[80];
     printf("\n ������� �������� ������\n");
     fflush(stdin);
     gets( A );
     while ( L <= R ) 
       { 
         m = (L + R) / 2; // �������� ���������
         if ( 0 == strcmp(A,M[m].name ))// ����� ������ �������
           { 
             flag = 1; // ���������� ����
             return m; //������ ���������� ��������
           } 
         if ( 0 > strcmp(A,M[m].name) ) 
             R = m - 1; // ������ ������� ������� ������
         else 
             L = m + 1;
       }
     if ( flag == 0 )
      { 
        printf ( "����� ����� �� ������!\n\n" ); 
        return -1;
      }   
   }   

/*******************************************************************************/

int prov_date(struct tm *t) //������� �������� ����������� ����� ����� ����������
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
       printf(" ������ ����� ����������!\n ���������\n");
       return 1;
      } 
    return 0;       
 }
 
/*******************************************************************************/

int scanf_date(struct tm *t) //������� ����� ����� ���������� ������
 {
   int tj, i=1; 
   do 
     {                                 
      puts("    ������� ����� ������ (�� 1 �� 31)");
      scanf("%d",&t->tm_mday); //����� ������(1,31)
      puts("    ������� ����� (�� 1 �� 12)");
      scanf("%d",&t->tm_mon);  // ������ ����� ������(0,11)
      puts("    ������� ���");
      scanf("%d",&tj);
      t->tm_year=tj-1900;  //���� � 1900(� Windows), � 1970(� Unix)
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
      printf("\n1 > ���������\n");   
      printf("0 > �����\n");
      printf("? > "); 
      fflush(stdin);  
      scanf("%d",&i);  
    }  
    return i;
 }

/*******************************************************************************/ 
