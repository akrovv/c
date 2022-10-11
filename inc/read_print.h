#ifndef __READ_PRINT_H__
#define __READ_PRINT_H__

int read_array(FILE *f, int *array, int *after_last);
int create_array(FILE *f, int **array, int **after_lasts);
void print_array(FILE *f, int *array, int *after_last);

#endif
