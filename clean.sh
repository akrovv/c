#!/bin/bash

objs=./out/

rm -rf ./*.exe 
rm -rf $objs/*.o $objs/*.gcda $objs/*.gcno $objs/*.c.gcov $objs/*.out
rm -rf ./func_tests/scripts/program_out.txt