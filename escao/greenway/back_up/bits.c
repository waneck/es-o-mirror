#include<stdio.h>

#define BIT1 0x01;
#define BIT2 0x02;
#define BIT3 0x04;
#define BIT4 0x08;
#define BIT5 0x10;
#define BIT6 0x20;
#define BIT7 0x40;
#define BIT8 0x80;

int changebit1(int bit);
int changebit2(int bit);
int changebit3(int bit);
int changebit4(int bit);
int changebit5(int bit);
int changebit6(int bit);
int changebit7(int bit);
int changebit8(int bit);

int main(void){
  int bit = 0;
  printf("0x%03X\n", bit);
  bit = changebit1(bit);
  printf("0x%03X\n", bit);
  bit = changebit2(bit);
  printf("0x%03X\n", bit);
  bit = changebit1(bit);
  printf("0x%03X\n", bit);
  bit = changebit3(bit);
  printf("0x%03X\n", bit);
  bit = changebit2(bit);
  printf("0x%03X\n", bit);
}

int changebit1(int bit){
  bit = bit ^ BIT1;
  return bit;
}

int changebit2(int bit){
  bit = bit ^ BIT2;
  return bit;
}

int changebit3(int bit){
  bit = bit ^ BIT3;
  return bit;
}

int changebit4(int bit){
  bit = bit ^ BIT4;
  return bit;
}

int changebit5(int bit){
  bit = bit ^ BIT5;
  return bit;
}

int changebit6(int bit){
  bit = bit ^ BIT6;
  return bit;
}

int changebit7(int bit){
  bit = bit ^ BIT7;
  return bit;
}

int changebit8(int bit){
  bit = bit ^ BIT8;
  return bit;
}
