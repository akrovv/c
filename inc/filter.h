#ifndef __FILTER_H__
#define __FILTER_H__

#define MEMORRY_ERROR 6
#define POINTER_ERROR 8
#define NOT_NULL_POINTERS 9
#define EMPTY_ARRAY 10

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pend_dst);

#endif
