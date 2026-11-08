# 蛋语言 · 五十例
#
# 用法：
#   make            编译全部 50 个 demo 到 build/
#   make run        编译并逐个运行
#   make clean      清理
#   make 列表       列出所有 demo

CC       := gcc
CFLAGS   ?= -std=c11 -O2 -Wall -Wextra
CPPFLAGS += -I. -Ichina++
BUILD    := build
DEMOS    := $(sort $(wildcard demo*.c))
BINS     := $(patsubst %.c,$(BUILD)/%.exe,$(DEMOS))

.PHONY: all run clean 列表

all: $(BINS)

$(BUILD)/%.exe: %.c | $(BUILD)
	@echo "build: $<"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@

$(BUILD):
	@mkdir -p $(BUILD)

run: all
	@sh run.sh

列表:
	@for f in $(DEMOS); do echo $$f; done

clean:
	@rm -rf $(BUILD)
	@echo "clean done."