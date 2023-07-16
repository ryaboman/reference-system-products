
#include <time.h>

#ifndef base_h
#define base_h

struct kp_tovar //структура дл€ количества и цены товара
 {
   float kp;   //значени
   char A[20];  //единицы измерени€
 };
 
struct post_tovar // структура дл€ поставщиков
 {
   int number; //количество поставщиков товара, max 80
   char post[80][80];    // поставщики
 };
 
struct TOVAR{	
   char name[80]; //название товара
   struct kp_tovar kol;  //количество товара
   struct kp_tovar price;//цена за единицу
   struct tm date; //срок реализации
   struct post_tovar sup;  //поставщики товара
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
