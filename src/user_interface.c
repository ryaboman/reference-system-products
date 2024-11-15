#include "base.h"

#include <stdio.h>

/*******************************************************************************/  
 
static char* menu[]=
 {
   " 1 > ���������� ������",
   " 2 > ����� ���������� �� ��������� �������� ������",
   " 3 > ����� ������ ������� � �������� ������ ����������",
   " 4 > ������������ ������ ����������� ��������� ���������",
   " 5 > ���������� ������ �� ������������ ������",
   " 6 > �������� ������",
   " 7 > ������������� ������",
   " 8 > ����� ������",
   " 0 > �����",
   " ? > "    
 };
 
/**************************/  
 
void printf_info(void)
 { 
   printf("��������� \"���������� ������� ������\"\n");
   printf("�����: �����  �.�.\n");
   printf("_______________\n");
 }  

/**************************/ 
 
void Menu_Printf(struct TOVAR *M, int N) //������� ������ ���� ������
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
         printf("\n���������� ��������� � �������� %d\n",N);
         if(N==0)
           printf("%s\n", menu[0]);
         else 
          { 
           fp=fopen("tovar","rb");   
           fread(M ,sizeof(struct TOVAR), N, fp);
           fclose(fp);
           printf(" ������ ��������� ������ ��������\n\n");
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
          puts("     ����� ������� ������!");
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
         printf("  ���������� �������� �����!\n  ���������� ���������\n");
         break; 
       }    
	   
       M+=B; 
       B++;     
       puts("�������:");
       puts("  �������� ������");
       fflush(stdin);
       gets(M->name);
       puts("  ���������� ������ (��������: 12 �� ��� 15 ��)");
       scanf_kptovar(&M->kol);
       printf("  ����  ������ �� %s (��������: 15 $ ��� 180 ���)\n", M->kol.A);
       scanf_kptovar(&M->price);
       puts("  ���� ���������� ������");
       scanf_date(&M->date);
       puts("  ���������� ������");
       scanf_post_tovar(&M->sup);
       puts("     ����� ������� ��������!");
       j=Vyxod();
     } 
     while(j == 1);        
}  
 
/*******************************************************************************/ 

 
