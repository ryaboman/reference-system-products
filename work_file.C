#include <stdio.h>
#include <string.h>

#include "edit_product.h"
#include "comandy.h"
#include "user_interface.h"
#include "base.h"

/*******************************************************************************/

int kolstrok(FILE *fp) //������� ��� �������� �������� � ����� ���������
 {   
   struct TOVAR G;           
   int kolst=0; //kol-���������� �����
   while (fread ( &G, sizeof(struct TOVAR),1 , fp )!=0) 
      kolst++;    
   return kolst;
 }

/**************************/

int KOL_STR(void)  //������� �������� � �������� ����� ��� �������� � ��� �������� ���� struct TOVAR
 {
      int N;
      FILE *f; 
      f=fopen("tovar","rb");
      if (f == NULL)
        N=0;
      else  
        N=kolstrok(f);
      fclose(f);
      return N; 
 } 
 
/*******************************************************************************/  

int menu_2(struct TOVAR *M, int N, int k) 
 {
     int a=1;
     int B;
     B=N;
     switch(k)
       {       
          case 1 : 
           { 
            Dobavit_Element(M, B);   
            break;    
           } 
          case 2 :
           {
            InfoTovar(M, N);   
            break;   
           } 
          case 3 :
           {
            SrokRealiz(M, N);
            break;   
           } 
          case 4 : 
           {
            Postavshik(M, N);
            break;   
           } 
          case 5 : 
           {
            Zakaz(M, N);
            break;
           } 
          case 6 :
           {   
            Delete_Element(M, B);
            break;
           } 
          case 7 :
           {   
            Korrected_tovar(M, N); 
            break;
           }  
          case 8 :
           {      
            Poisk_tovar(M, N); 
            break; 
           }       
          default: break;
       }
     return B;  
 }

/**************************/
 
int menu_1(struct TOVAR *M, int N, int k)
 {
     int a=1;
     int B;
     B=N;
     switch(k)
      {
         case 1 :
           {   
            Dobavit_Element(M, B);
            break;
           } 
         default: break;  
      }   
     return B;
 } 
 
/**************************/

int panel(struct TOVAR *M, int N, int k)
 {
     int B;            
     if(N!=0)   
        B=menu_2(M, N, k);
      else
        B=menu_1(M, N, k); 
      return B;             
 }

/*******************************************************************************/
 
int sort_tovar (struct TOVAR *M, unsigned int n ) 
{
   struct TOVAR p;
   int i, j;
   if (n == 0)
     return 0;
   for ( i = 0; i < n-1; i ++ )
     for ( j = n-1; j > i; j -- )
       if ( strcmp(M[j-1].name,M[j].name) > 0 )
        {
          p = M[j]; 
          M[j] = M[j-1]; // ������������ ������
          M[j-1] = p;
        }
}

/*******************************************************************************/

int fwrite_tovar(struct TOVAR *M, int B)
{
      FILE *fp;
      fp=fopen("tovar","wb"); 
      if (fp == NULL)
       {
        printf("������ �������� �����\n");
        return 0;
       }       
      fwrite(M, sizeof(struct TOVAR), B, fp);
      fclose(fp);
      return 1;    
}

/*******************************************************************************/

int call_func(void) //����� �-��
 { 
    int N, k, B, d;
    struct TOVAR *M;
    printf_info();    //����� ���� � ���������
    do
     {
       N=KOL_STR();    
       M=new struct TOVAR[N+11];//�������� ������������ ������
       
	   if (M == NULL)
       {
         printf("������ ��������� ������\n");    
         break;
       }
	   
       k=menu_f(M, N);     //����� ��������� � ����
       B=panel(M, N, k);  //������� ���������� �����������
       sort_tovar(M, B);  //��������� ����� � ���������� �������
       d=fwrite_tovar(M, B);
       delete M;     //�������� ������    
     }
    while(k != 0 && d != 0);
    return 0;
                   
 }

/*******************************************************************************/
