#
# Kernel build
#

PWD := $(abspath $(dir .))

CC ?= clang
ASM ?= nasm
LD ?= ld

CFLAGS := -std=c99 -Wall -pedantic -O0 -ffreestanding -fno-builtin
LDFLAGS := -nostdlib

export CC
export CFLAGS
export ASM
export LDFLAGS
export LD

.PHONY: all
all:
	$(error Run `make ARCH`)
	@echo > /dev/null

.PHONY: i386
i386: ARCH := i386
i386: CC := i386-elf-gcc
i386: LD := i386-elf-ld
i386: kernel

.PHONY: x86_64
x86_64: ARCH := x86_64
x86_64: kernel

.PHONY: kernel
kernel:
	mkdir -p bin/$(ARCH)
	$(MAKE) -C src/arch/$(ARCH) TARGET_DIR=$(PWD)/bin/$(ARCH)
	$(MAKE) -C src TARGET_DIR=$(PWD)/bin ARCH=$(ARCH)

.PHONY: autoformat
autoformat:
	for i in `find . -name '*.c'`; do echo "$$i"; clang-format-3.6 "$$i" > "$$i.formatted"; mv "$$i.formatted" "$$i"; done
	for i in `find . -name '*.h'`; do echo "$$i"; clang-format-3.6 "$$i" > "$$i.formatted"; mv "$$i.formatted" "$$i"; done

.PHONY: clean
clean:
	rm -r bin
