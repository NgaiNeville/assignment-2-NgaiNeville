ifeq ($(CROSS_COMPILE),)
	CC := gcc
else	
	CC := $(CROSS_COMPILE)gcc
endif
CFLAGS= -g -Wall -Wextra -Werror
TARGET=writer
LDFLAGS= -lrt
OBJECT=writer.o

all: $(TARGET)


$(TARGET): $(OBJECT)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECT) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -f $(OBJECT) $(TARGET)
