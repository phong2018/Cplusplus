/* scanf example */
#include <stdio.h>

int main ()
{
  unsigned int id,tonggio,sotienmotgio;
  printf("nhap ID, tong so gio lam, tien luong mot gio:\n");
  scanf("%u",&id);
  scanf("%u",&tonggio);
  scanf("%u",&sotienmotgio);
  printf("ID: %u. Tong tien tien luong la: %u",id,tonggio*sotienmotgio);


  return 0;
}
