
#include <time.h>

#ifndef base_h
#define base_h

struct kp_tovar //��������� ��� ���������� � ���� ������
 {
   float kp;   //�������
   char A[20];  //������� ���������
 };
 
struct post_tovar // ��������� ��� �����������
 {
   int number; //���������� ����������� ������, max 80
   char post[80][80];    // ����������
 };
 
struct TOVAR{	
   char name[80]; //�������� ������
   struct kp_tovar kol;  //���������� ������
   struct kp_tovar price;//���� �� �������
   struct tm date; //���� ����������
   struct post_tovar sup;  //���������� ������
};
 
void printf_date(struct tm *t);
void printf_kptovar(struct kp_tovar *f);
void printf_post_tovar(struct post_tovar *N);
int printf_name_tovar(struct TOVAR *M, int i);
void scanf_kptovar(struct kp_tovar *f);
void scanf_post_tovar(struct post_tovar *N);
int sravneniya(struct kp_tovar *H, struct kp_tovar *N);
int Soarch_Element(struct TOVAR *M, int B);
int prov_date(struct tm *t);
int scanf_date(struct tm *t);
int Vyxod(void);

#endif
