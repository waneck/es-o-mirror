/* Test program to automaticaly generates the memory
   maps to be used in GDS.

   GDS = Generic Digital System

   September, 2001.

   Filipi Vianna<filipi@em.pucrs.br>
   */
#include<stdio.h>
#include<stdlib.h>

#define MEMMAP_VERSION "0.01"

void usage(void);
void printversion(void);
void showmemmap(int resolution, char *file_name);

int s = 0; // Indicates to show the memory map

int main(int argc, char *argv[]) {
  int resolution = 0, i, j;  
  char *file_name = 0;
  char *arg = 0;

  //  strcpy(file_name, "");

  /* Parse Command Line */
  
  for (i=1; i<argc; i++) {
    arg = argv[i];

    if (*arg=='-') {
      switch (arg[1]) {
      case 'r':
	if (argc > (i+1)) {
	  resolution = atoi(argv[i+1]);
	  i++;
	}
	break;
      case 'o':
	if (argc > (i+1)) {
          file_name = argv[i+1];
          fprintf(stderr, "File_name: %s\n", file_name);
	  i++;
	}
	break;
      case 's':
	s = 1;
	break;
      case 'v' :
	printversion();
	exit(0);
	break;
      default:
	usage();
	exit(0);
	break;
      }
    }
  }
  if (!resolution)
    usage();
  else
    showmemmap(resolution, file_name);
  return 0;
}

void showmemmap(int resolution, char *file_name){
  int tamanho, i, j, linhas, valor;
  int linha[16];

  FILE *output_file; 
  output_file = fopen(file_name, "w");

  if (resolution>12){
    fprintf(stderr, "The resolution can't be greater than 12.\n");
    fprintf(stderr, "Seting word size to 12 bits.\n");
    resolution = 12;
  }
  tamanho = potencia(2, resolution);
  linhas =  tamanho / 16;

  fprintf(stderr, "Resolution: %d\n", resolution);
  fprintf(stderr, "Size: %d\n", tamanho);
  fprintf(stderr, "Lines: %d\n", linhas);

  if (s) printf("\t");
  for(i=0;i<16;i++) if (s) printf(" %3X", i);
  if (s) printf("\t");
  for(i=0;i<16;i++) if (s) printf("%x", i);
  if (s) printf("\n");

  for(j=0;j<tamanho;j+=16){
    for(i=j;i<j+16;i++) linha[i-j]=i;
    if (s) printf("\t");
    for(i=0;i<16;i++) if (s) printf(" %03X", linha[i]);

    for(i=0;i<16;i++)
      if (output_file) fprintf(output_file, "%1c", linha[i]);

    if (s) printf("\t");
    for(i=0;i<16;i++){
      valor = linha[i];
      if (valor>0xFF){
        while(valor>0xFF){
          valor = valor / 0xFF;
        }
        valor = valor * 0x100;
        valor = linha[i] - valor;
      }
      if ((valor > 0 && valor < 0x20) || (valor > 0x7E && valor < 0xB0)){
        if (s) printf(".");
      }
      else
        if (s) printf("%c", linha[i]);
    }
    if (s) printf("\n");
  }

  if (output_file) fclose(output_file);
}

int potencia(int valor, int potencia){
  int retorno = valor;
  int i;

  for(i=1;i<potencia;i++){
      retorno = retorno * valor;
  }
  return retorno;
}

/*
 * Usage
 */
void usage(void) {
  fprintf(stderr, "\nmemmap - Filipi <filipi@em.pucrs.br>  http://www.em.pucrs.br/~filipi\n\n");
  fprintf(stderr, "usage:\n");
  fprintf(stderr, "    -r n\tuse ``n'' as the bit resolution of your addres bus.\n");
  fprintf(stderr, "\t\tthe maximum value for n is 12.\n");
  fprintf(stderr, "    -s\t\tshow memmap using HEX mode.\n");
  fprintf(stderr, "    -o filename\tsave file conatining the memory map as ``filename''\n");
  fprintf(stderr, "    -v\t\tshow memmap version\n");
  fprintf(stderr, "\n");
}

/*
 * printversion
 */
void printversion(void) {
  fprintf(stderr, "memmap v%s\n", MEMMAP_VERSION);
}
