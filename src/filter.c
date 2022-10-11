#include "utils.h"
#include "filter.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pend_dst)
{    
    if (pb_src == NULL || pe_src == NULL)
        return NOT_NULL_POINTERS; 
    
    if (pb_src >= pe_src)
    {
        *pb_dst = NULL;
        *pend_dst = NULL;
        return POINTER_ERROR;
    }

    int *p_end_neg = (int *)pe_src - 1;

    for (int *cur = (int *)pb_src; cur < pe_src; cur++)
        if (*cur < 0 && cur != pb_src)
        {
            p_end_neg = cur - 1;
            break;
        }
        else if (*cur < 0 && cur == pb_src)
            return EMPTY_ARRAY;
    
    size_t len = p_end_neg - pb_src + 1;
    *pb_dst = malloc(len * sizeof(int));

    if (!*pb_dst)
        return MEMORRY_ERROR;

    *pend_dst = *pb_dst + len;
    size_t i = 0;

    for (int *cur = (int *)pb_src; cur <= p_end_neg; cur++)
    {
        *(*pb_dst + i) = *cur;
        i++;
    }

    return EXIT_SUCCESS;
}
