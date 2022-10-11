#ifndef __SORT_H__
#define __SORT_H__

#include <string.h>

void mysort(void *array, size_t num, size_t size, int (*comparator)(const void *, const void *));
int funccmp(const void *val1, const void *val2);
void swap(void *a, void *b, size_t size);

#endif
