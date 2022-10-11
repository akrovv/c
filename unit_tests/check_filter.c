
#include "../inc/check_filter.h"
#include "../inc/filter.h"

int unfiltered[] = {123, 58, -3, -5, -12, 43, 53};
int filtered[] = {123, 58};
int same_data[] = {123, 123, 123, 123, 123, 123, 123};

START_TEST(filter_params_error_neg)
{
    int *arr_begin = unfiltered;
    int *arr_end = arr_begin + 6;
    int *filtered_begin = NULL;
    int *filtered_end = NULL;
    int rc = 0;

    rc = key(NULL, arr_end, &filtered_begin, &filtered_end); // TEST 1
    ck_assert_int_eq(rc, NOT_NULL_POINTERS); 
    free(filtered_begin);
    filtered_begin = NULL;
    filtered_end = NULL;

    rc = key(arr_begin, NULL, &filtered_begin, &filtered_end); // TEST 2

    ck_assert_int_eq(rc, NOT_NULL_POINTERS); 
    free(filtered_begin);
    filtered_begin = NULL;
    filtered_end = NULL;

    arr_end = arr_begin;

    rc = key(arr_begin, arr_end, &filtered_begin, &filtered_end); // TEST 3

    ck_assert_int_eq(rc, POINTER_ERROR); 
    free(filtered_begin);
    filtered_begin = NULL;
    filtered_end = NULL;

    arr_begin += 1;

    rc = key(arr_begin, arr_end, &filtered_begin, &filtered_end); // TEST 4

    ck_assert_int_eq(rc, POINTER_ERROR); 
    free(filtered_begin);
    filtered_begin = NULL;
    filtered_end = NULL;
}
END_TEST

Suite *filter_suite(void)
{
    Suite *st_filter;
    TCase *tc_neg;
   // TCase *tc_pos;

    st_filter = suite_create("__FILTER__");

    tc_neg = tcase_create("__NEG_TEST__");
    tcase_add_test(tc_neg, filter_params_error_neg);
    suite_add_tcase(st_filter, tc_neg);

    return st_filter;
}
