/* This is just a test programm to check the
   maps generated with memmap.

   September, 2001.

   Filipi Vianna<filipi@technologist.com>
   */
#include<stdio.h>
#include<stdlib.h>

#define SIMULL_VERSION "0.01"

void usage(void);
void printversion(void);

int main(int argc, char *argv[]) {
  char *file_name = argv[1];
  char read_char[1];
  int i = 0;
  FILE *input_file;

  if (!file_name){
    usage();
    return 1;
    exit(1);
  }

  fprintf(stderr, "file_name: %s\n", file_name);
  input_file = fopen(file_name, "r");
  if (input_file){
    fprintf(stderr, "Success!!\nFile opened!\n");

    while(!feof(input_file)){
      i = fgetc(input_file);
      printf("%02X\n", i);
    }

    if (!fclose(input_file))
      fprintf(stderr, "Success!!\nFile closed!\n");
  }
  else
    fprintf(stderr, "Failed!!\nFile not opened!\n");

  return 0;
}

/*
 * Usage
 */
void usage(void) {
  fprintf(stderr, "\nsimull - Filipi <filipi@em.pucrs.com>  http://www.em.pucrs.br/~filipi\n\n");
  fprintf(stderr, "usage:\n");
  fprintf(stderr, "\tsiumll <input_file>\n");
  fprintf(stderr, "\n");
}

/*
 * printversion
 */
void printversion(void) {
  fprintf(stderr, "simull v%s\n", SIMULL_VERSION);
}
