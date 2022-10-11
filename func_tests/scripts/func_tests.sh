#!/bin/bash

length_for_pos=$(($(find ../data/ -name "pos_[0-9][0-9]*_args.txt" | wc -l)+1))
length_for_neg=$(($(find ../data/ -name "neg_[0-9][0-9]*_args.txt" | wc -l)+1))

for ((i=1; i < length_for_pos; i++)); do

	if [ -f "../../func_tests/data/pos_0${i}_args.txt" ]; then
		bash pos_case.sh "../../func_tests/data/pos_0${i}_in.txt" "../../func_tests/data/pos_0${i}_out.txt" "../../func_tests/data/pos_0${i}_args.txt"
	else
		bash pos_case.sh "../../func_tests/data/pos_0${i}_in.txt" "../../func_tests/data/pos_0${i}_out.txt"
	fi

	if test "$?" -eq 0; then
		echo -e TEST "$i":'\033[32m PASSED\033[37m'
	else
		echo -e TEST "$i":'\033[31m FAIL\033[37m'
	fi
done

counter=$i
for ((i=1; i < length_for_neg; i++)); do
	if [ -f "../../func_tests/data/neg_0${i}_args.txt" ]; then
		bash neg_case.sh "../../func_tests/data/neg_0${i}_in.txt" "../../func_tests/data/neg_0${i}_args.txt"
	else
		bash neg_case.sh "../../func_tests/data/neg_0${i}_in.txt"
	fi

	if test "$?" -eq 0; then
		echo -e TEST "$counter":'\033[32m PASSED\033[37m'
	else
		echo -e TEST "$counter":'\033[31m FAIL\033[37m'
	fi
	counter=$((counter+1))
done