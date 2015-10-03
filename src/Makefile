
all: $(TARGET_DIR)/kernel

TARGETS := vga kernel utils
TARGETS := $(addprefix $(TARGET_DIR)/, $(TARGETS))
TARGETS := $(addsuffix .o, $(TARGETS))

CFLAGS := $(CFLAGS) -Iinclude

$(TARGET_DIR)/kernel: $(TARGET_DIR)/$(ARCH)/entry.o $(TARGETS)
	$(LD) $(LDFLAGS) -T arch/$(ARCH)/link.ld $^ -o $@

$(TARGET_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
