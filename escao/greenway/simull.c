/* This is just a test programm to check the
   maps generated with memmap.

   September, 2001.

   Filipi Vianna<filipi@technologist.com>
   */
#include<stdio.h>

#define SIMULL_VERSION "0.01"

void usage(void);
void printversion(void);
void char_to_strbits(int arg1);

int main(int argc, char *argv[]) {
  char *file_name = argv[1];
  char *strbits = 0;
  char read_char[1];
  int i = 0;
  FILE *input_file;

  strbits = "\0";
  if (!file_name){
    usage();
    return 1;
    exit(1);
  }

  fprintf(stderr, "file_name: %s\n", file_name);
  input_file = fopen(file_name, "r");
  if (input_file){
    fprintf(stderr, "Success!!\nFile opened!\n");

    printf("12345678\n");
    while(!feof(input_file)){
      i = fgetc(input_file);
      char_to_strbits(i);
      printf("%s\n", strbits);
    }
    if (!fclose(input_file))
      fprintf(stderr, "Success!!\nFile closed!\n");
  }
  else
    fprintf(stderr, "Failed!!\nFile not opened!\n");

  return 0;
}

/*
 * Converts one char (1 byte) into one string (8 bytes + null)
 * containing 0s and 1s.
 */
void char_to_strbits(int arg1){
  int x = 0;
  /*
  printf( "INTEGER: %i\n", arg1 );
  printf( "    HEX: %x\n", arg1 );
  printf( " BINARY:" );
  */
  for( x = 15; x > 7; x-- )
    printf( " %i ", (arg1 & 1 << x ) > 0 ? 1 : 0 );

  printf( "  " );

  for( x = 7; x > -1; x-- )
    printf( " %i ", (arg1 & 1 << x ) > 0 ? 1 : 0 );
  /*
  puts( "" );
  puts( " 16 bit:15 14 13 12 11 10  9  8    7  6  5  4  3  2  1  0" );
  puts( "  8 bit: 7  6  5  4  3  2  1  0    7  6  5  4  3  2  1  0" );
  puts( "    Hex: |----4---|  |----3---|    |----2---|  |----1---|" );
  puts( "    Sum: 3  1                                            " );
  puts( "         2  6  8  4  2  1                                " );
  puts( "         7  3  1  0  0  0  5  2    1                     " );
  puts( "         6  8  9  9  4  2  1  5    2  6  3  1            " );
  puts( "         8  4  2  6  8  4  2  6    8  4  2  6  8  4  2  1" );
  */
}

/*
 * Usage
 */
void usage(void) {
  fprintf(stderr, "\nsimull - Filipi <filipi@em.pucrs.com>  http://www.em.pucrs.br/~filipi\n\n");
  fprintf(stderr, "usage:\n");
  fprintf(stderr, "\tsimull <input_file>\n");
  fprintf(stderr, "\n");
}

/*
 * printversion
 */
void printversion(void) {
  fprintf(stderr, "simull v%s\n", SIMULL_VERSION);
}

/* Garbage **************
 * I'm puting some junk code inside this area!!!
 *
  int i;
  //  strbits="\0";
  
  printf("Value\tMOD2\tMOD2+48\tposition\tstrbits\n");
  for (i=9;i>0;i--){
    position = (value%2) + 48;
    position[8] = 0;
    printf("%d\t%d\t%c\t%s\t%s\n", value, value%2, (value%2)+48, position, strbits);
    strbits = position;
    value = value / 2;
  }
  printf("\n");
*/
