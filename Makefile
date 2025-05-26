CC = gcc
CFLAGS = -Wall -Wextra -lpthread
BIN_DIR = bin
TERMINAL = xterm -e
TESTS_DIR = tests

all: dirs master_integral worker_integral

dirs:
	@mkdir -p $(BIN_DIR)

master_integral: master_integral.c
	@$(CC) $(CFLAGS) $< -o $(BIN_DIR)/$@

worker_integral: worker_integral.c
	@$(CC) $(CFLAGS) $< -o $(BIN_DIR)/$@


test: all
	@echo "Running test scenarios..."
	@chmod +x $(TESTS_DIR)/run_tests.sh
	@$(TESTS_DIR)/run_tests.sh

clean:
	@rm -rf $(BIN_DIR)

.PHONY: all clean test
