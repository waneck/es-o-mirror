#include<stdio.h>

typedef struct {
  unsigned int _1 : 1;
  unsigned int _2 : 1;
  unsigned int _3 : 1;
  unsigned int _4 : 1;
  unsigned int _5 : 1;
  unsigned int _6 : 1;
  unsigned int _7 : 1;
  unsigned int _8 : 1;
  unsigned int _9 : 1;
  unsigned int _10 : 1;
  unsigned int _11 : 1;
  unsigned int _12 : 1;
  unsigned int _13 : 1;
  unsigned int _14 : 1;
  unsigned int _15 : 1;
  unsigned int _16 : 1;
  unsigned int _17 : 1;
  unsigned int _18 : 1;
  unsigned int _19 : 1;
  unsigned int _20 : 1;
  unsigned int _21 : 1;
  unsigned int _22 : 1;
  unsigned int _23 : 1;
  unsigned int _24 : 1;
  unsigned int _25 : 1;
  unsigned int _26 : 1;
  unsigned int _27 : 1;
  unsigned int _28 : 1;
  unsigned int _29 : 1;
  unsigned int _30 : 1;
  unsigned int _31 : 1;
  unsigned int _32 : 1;
} bit_field;

bit_field zera_bits(bit_field bits);

int main (void){
  bit_field bits;
  unsigned int var1;
  char var2;
  int tamanho = sizeof(bits);
  int tamanho2 = sizeof(var1);
  int tamanho3 = sizeof(var2);

  bits = zera_bits(bits);

  printf("Size of structure:\t%d\n\n", tamanho);
  printf("Size of var:\t\t%d\n\n", tamanho2);
  printf("Size of var2:\t\t%d\n\n", tamanho3);

  bits._1 = 1;

  var1 = (int)(bits);


  printf("-----------------------\r\n");
  printf("32 31 30 29 28 27 26 25\r\n");
  printf("%02d %02d %02d %02d %02d %02d %02d %02d\n",
	 bits._32, bits._31, bits._30, bits._29,
	 bits._28, bits._27, bits._26, bits._25);
  printf("-----------------------\r\n");
  printf("24 23 22 21 20 19 18 17\r\n");
  printf("%02d %02d %02d %02d %02d %02d %02d %02d\n",
	 bits._24, bits._23, bits._22, bits._21,
	 bits._20, bits._19, bits._18, bits._17);
  printf("-----------------------\r\n");
  printf("16 15 14 13 12 11 10 09\r\n");
  printf("%02d %02d %02d %02d %02d %02d %02d %02d\n",
	 bits._16, bits._15, bits._14, bits._13,
	 bits._12, bits._11, bits._10, bits._9);
  printf("-----------------------\r\n");
  printf("08 07 06 05 04 03 02 01\r\n");
  printf("%02d %02d %02d %02d %02d %02d %02d %02d\n",
	 bits._8, bits._7, bits._6, bits._5,
	 bits._4, bits._3, bits._2, bits._1);
  printf("-----------------------\r\n");
  printf("Conteudo:\t%X\n",bits);
  return 0;
}

bit_field zera_bits(bit_field bits){
  bits._1=0;
  bits._2=0;
  bits._3=0;
  bits._4=0;
  bits._5=0;
  bits._6=0;
  bits._7=0;
  bits._8=0;
  bits._9=0;
  bits._10=0;
  bits._11=0;
  bits._12=0;
  bits._13=0;
  bits._14=0;
  bits._15=0;
  bits._16=0;
  bits._17=0;
  bits._18=0;
  bits._19=0;
  bits._20=0;
  bits._21=0;
  bits._22=0;
  bits._23=0;
  bits._24=0;
  bits._25=0;
  bits._26=0;
  bits._27=0;
  bits._28=0;
  bits._29=0;
  bits._30=0;
  bits._31=0;
  bits._32=0;
  return bits;
}
