#include "utils.h"
#include "read_print.h"
#include "filter.h"
#include "sort.h"

int main(int argc, char **argv)
{
	if (argc < 3)
		return TOO_FEW_ARG;
	else if (argc > 4)
		return TOO_MANY_ARG;

	FILE *f_src, *f_dst;

	int *array = NULL;
	int *after_last = NULL;

	f_src = fopen(argv[1], "r");
	f_dst = fopen(argv[2], "w");

	if (f_src == NULL)
		return FILE_OPEN_ERROR;

	if (f_dst == NULL)
	{
		fclose(f_src);
		return FILE_OPEN_ERROR;
	}

	int rc = create_array(f_src, &array, &after_last);
	fclose(f_src);
	if (rc)
	{
		if (array != NULL)
			free(array);
		fclose(f_dst);
		return rc;
	}

	size_t len = 0;
	if (argc == 4 && !strcmp(argv[3], "f"))
	{
		int *filtered_array_begin = NULL;
		int *filtered_array_end = NULL;
		if (!(rc = key(array, after_last, &filtered_array_begin, &filtered_array_end)))
		{
			len = filtered_array_end - filtered_array_begin;
			mysort(filtered_array_begin, len, sizeof(int), &funccmp);
			print_array(f_dst, filtered_array_begin, filtered_array_end);
		}
		free(filtered_array_begin);
		filtered_array_end = NULL;
	}
	else if (argc == 3)
	{
		len = after_last - array;
		mysort(array, len, sizeof(int), funccmp);
		print_array(f_dst, array, after_last);
	}
	else
	{
		free(array);
		after_last = NULL;
		fclose(f_dst);
		return PARAMS_ERROR;
	}

	free(array);
	after_last = NULL;
	fclose(f_dst);

	return rc;
}
