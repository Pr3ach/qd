CC=gcc
CFLAGS=-s -std=c99 -m32
LDFLAGS=-s -std=c99 -m32
SOURCES=src/qd.c src/qvm.c color_shell/color_shell.c src/common.c
OBJECTS=$(SOURCES:.c=.o)

KERNEL=$(shell uname -s)

ifeq ($(OS), Windows_NT)
  PLATFORM=win32
else ifeq ($(KERNEL), Linux)
  PLATFORM=unix
else ifeq ($(KERNEL), Darwin)
  PLATFORM=unix
else ifeq ($(KERNEL), FreeBSD)
  PLATFORM=unix
else ifeq ($(KERNEL), OpenBSD)
  PLATFORM=unix
else
  PLATFORM=unsupported
  @echo "Supported platform: unix/win32"
endif

ifeq ($(PLATFORM), unix)
  BIN=build/unix/qd
else ifeq ($(PLATFORM), win32)
  BIN=build/win32/qd.exe
endif

ifneq ($(PLATFORM), unsupported)
all: $(BIN)

$(BIN): $(OBJECTS)
	$(CC) $^ -o $@ $(LDFLAGS)

src/common.c: inc/common.h inc/qd.h color_shell/color_shell.h
src/qd.c: inc/qd.h inc/qvm.h inc/common.h color_shell/color_shell.h
src/qvm.c: inc/qvm.h inc/opcodes.h inc/common.h

src/%.o: src/%.c
	$(CC) $< -c -o $@ $(CFLAGS)

color_shell/%.o: color_shell/%.c
	$(CC) $< -c -o $@ $(CFLAGS)

clean:
	rm -f $(BIN)
	rm -f $(OBJECTS)
endif
