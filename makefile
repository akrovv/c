SRC_DIR := ./src
INC_DIR := ./inc
OUT_DIR := ./out

CC := gcc
C_VERSION := 99
CFLAGS := -std=c$(C_VERSION) -Wall -Werror -pedantic -I $(INC_DIR)

FTESTS_DIR := ./func_tests/scripts
UTESTS_DIR := ./unit_tests
U_CFLAGS := -lcheck

OBJS_ALL := $(OUT_DIR)/create_read_print.o $(OUT_DIR)/filter.o $(OUT_DIR)/sort.o
OBJS_MAIN := $(OUT_DIR)/main.o
OBJS_TESTS_UNIT := $(OUT_DIR)/check_filter.o# $(OUT_DIR)/check_main.o $(OUT_DIR)/check_sort.o $(OUT_DIR)/check_read.o

unit_tests.exe: $(OBJS_TESTS_UNIT) $(OBJS_ALL)
	$(CC) -o $@ $^ $(U_CFLAGS)

$(OUT_DIR)/check_%.o: $(UTESTS_DIR)/check_%.c $(INC_DIR)/*.h object_dir
	$(CC) $(CFLAGS) -c $< -o $@

app.exe: $(OBJS_MAIN) $(OBJS_ALL)
	$(CC) -o $@ $^

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/*.h object_dir
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: func clean object_dir unit

object_dir:
	@mkdir -p $(OUT_DIR)

func:
	cd $(FTESTS_DIR) && bash ./func_tests.sh

clean:
	@$(RM) ./*.exe
	@$(RM) $(OUT_DIR)/*.o $(OUT_DIR)/*.gcda $(OUT_DIR)/*.gcno $(OUT_DIR)/*.c.gcov $(OUT_DIR)/*.out
	@$(RM) $(FTESTS_DIR)/program_out.txt
	@rm -rf $(OUT_DIR)
