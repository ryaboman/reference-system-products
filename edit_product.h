
#ifndef edit_product_h
#define edit_product_h

void kor_name(struct TOVAR *M);
void kor_kol(struct TOVAR *M);
void kor_price(struct TOVAR *M);
void kor_date(struct TOVAR *M);
void kor_sup(struct TOVAR *M);
void switch_kor_tovar(int g, struct TOVAR *M);
void Korrected_tovar(struct TOVAR *M, int N);
void poisk_kol(struct TOVAR *M, int B);
void poisk_price(struct TOVAR *M, int B);
void poisk_sup(struct TOVAR *M, int B);
void poisk_kps(struct TOVAR *M, int B);

#endif
