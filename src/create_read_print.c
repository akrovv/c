#include "utils.h"
#include "read_print.h"

int get_array_len(FILE *f, size_t *n)
{
    size_t i = 0;
    int temp;
    while (fscanf(f, "%d", &temp) == 1)
        i++;

    if (!i)
        return EMPTY_FILE;
    else if (i && !feof(f)) 
        return SCAN_DIGIT_ERROR;
    
    *n = i;

    return EXIT_SUCCESS;
}

int create_array(FILE *f, int **array, int **after_lasts)
{
    int *p = NULL;
    size_t len = 0;
    int rc = EXIT_SUCCESS;

    if (!(rc = get_array_len(f, &len)))
    {
        p = malloc(sizeof(int) * len);
        if (!p)
            return MEMORRY_ERROR;

        *after_lasts = p + len;

        rewind(f);

        if (!(rc = read_array(f, p, *after_lasts)))
            *array = p;
        else
        {
            free(p);
            p = NULL;
        }
    }

    return rc;
}

int read_array(FILE *f, int *array, int *after_last)
{
    for (int *cur = array; cur < after_last; cur++)
        if (fscanf(f, "%d", cur) != 1)
            return SCAN_DIGIT_ERROR;
    return EXIT_SUCCESS;
}

void print_array(FILE *f, int *array, int *after_last)
{
    for (int *cur = array; cur < after_last; cur++)
        if (cur == after_last - 1)
            fprintf(f, "%d", *cur);
        else
            fprintf(f, "%d ", *cur);
}

