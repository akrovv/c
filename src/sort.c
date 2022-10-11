#include "utils.h"
#include "sort.h"
#include "read_print.h"

void swap(void *a, void *b, size_t size)
{
    char buff[size];
    
    memcpy(buff, a, size);
    memcpy(a, b, size);
    memcpy(b, buff, size);
}

void mysort(void *array, size_t num, size_t size, int (*comparator)(const void *, const void *))
{
    char *pb = (char *)array;
    char *pe = pb + (num - 1) * size;

    for (; pe >= pb; pe -= size)
        for (char *cur = array; cur < pe; cur += size)
        {
            char *next = cur + size;
            if (comparator(cur, next) > 0)
                swap(cur, next, size);
        }
}

int funccmp(const void *val1, const void *val2)
{
    return *((int *) val1) - *((int *) val2);
}
