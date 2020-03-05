# Cross-compiling (e.g., on Mac OS X)
# TOOLPREFIX = i386-jos-elf

# Using native tools (e.g., on X86 Linux)
#TOOLPREFIX =


CC = $(TOOLPREFIX)gcc
LD = $(TOOLPREFIX)ld
CFLAGS = -I../ -I./headers -Wno-incompatible-library-redeclaration -Wno-builtin-declaration-mismatch -c
CFLAGS += -fno-pic -static -fno-builtin -fno-strict-aliasing -O2 -Wall -MD -ggdb -m32 -Werror -fno-omit-frame-pointer
CFLAGS += $(shell $(CC) -fno-stack-protector -E -x c /dev/null >/dev/null 2>&1 && echo -fno-stack-protector)
BINPATH = ../build/bin/
LDFLAGS += -m $(shell $(LD) -V | grep elf_i386 2>/dev/null | head -n 1)

# Disable PIE when possible (for Ubuntu 16.10 toolchain)
ifneq ($(shell $(CC) -dumpspecs 2>/dev/null | grep -e '[^f]no-pie'),)
CFLAGS += -fno-pie -no-pie
endif
ifneq ($(shell $(CC) -dumpspecs 2>/dev/null | grep -e '[^f]nopie'),)
CFLAGS += -fno-pie -nopie
endif

SUBTOOLS := $(wildcard */.)

-include $(BINPATH)*.d

FORCE:

$(SUBTOOLS): FORCE
	#$(MAKE) -C $@

userland: cat echo grep init kill ln ls mkdir ps rm rmdir sh wc zombie $(SUBTOOLS)
	rm $(BINPATH)*.d
	rm $(BINPATH)*.o

ULIB = $(BINPATH)ulib.o $(BINPATH)usys.o $(BINPATH)printf.o $(BINPATH)umalloc.o

ulibc:
	$(CC) $(CFLAGS) ulib.c -o $(BINPATH)ulibc.o

usys:
	$(CC) $(CFLAGS) usys.S -o $(BINPATH)usys.o

printf:
	$(CC) $(CFLAGS) printf.c -o $(BINPATH)printf.o

umalloc:
	$(CC) $(CFLAGS) umalloc.c -o $(BINPATH)umalloc.o

cat: ulibc usys printf umalloc
	$(CC) $(CFLAGS) cat.c -o $(BINPATH)cat.o
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $(BINPATH)$@ $(BINPATH)cat.o $(BINPATH)ulibc.o $(BINPATH)usys.o $(BINPATH)printf.o $(BINPATH)umalloc.o

echo:
	$(CC) $(CFLAGS) echo.c -o $(BINPATH)echo.o
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $(BINPATH)$@ $(BINPATH)echo.o $(BINPATH)ulibc.o $(BINPATH)usys.o $(BINPATH)printf.o $(BINPATH)umalloc.o

grep:
	$(CC) $(CFLAGS) grep.c -o $(BINPATH)grep.o
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $(BINPATH)$@ $(BINPATH)grep.o $(BINPATH)ulibc.o $(BINPATH)usys.o $(BINPATH)printf.o $(BINPATH)umalloc.o

init:
	$(CC) $(CFLAGS) init.c -o $(BINPATH)init.o
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $(BINPATH)$@ $(BINPATH)init.o $(BINPATH)ulibc.o $(BINPATH)usys.o $(BINPATH)printf.o $(BINPATH)umalloc.o

kill:
	$(CC) $(CFLAGS) kill.c -o $(BINPATH)kill.o
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $(BINPATH)$@ $(BINPATH)kill.o $(BINPATH)ulibc.o $(BINPATH)usys.o $(BINPATH)printf.o $(BINPATH)umalloc.o

ln:
	$(CC) $(CFLAGS) ln.c -o $(BINPATH)ln.o
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $(BINPATH)$@ $(BINPATH)ln.o $(BINPATH)ulibc.o $(BINPATH)usys.o $(BINPATH)printf.o $(BINPATH)umalloc.o

ls:
	$(CC) $(CFLAGS) ls.c -o $(BINPATH)ls.o
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $(BINPATH)$@ $(BINPATH)ls.o $(BINPATH)ulibc.o $(BINPATH)usys.o $(BINPATH)printf.o $(BINPATH)umalloc.o

mkdir:
	$(CC) $(CFLAGS) mkdir.c -o $(BINPATH)mkdir.o
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $(BINPATH)$@ $(BINPATH)mkdir.o $(BINPATH)ulibc.o $(BINPATH)usys.o $(BINPATH)printf.o $(BINPATH)umalloc.o

ps:
	$(CC) $(CFLAGS) ps.c -o $(BINPATH)ps.o
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $(BINPATH)$@ $(BINPATH)ps.o $(BINPATH)ulibc.o $(BINPATH)usys.o $(BINPATH)printf.o $(BINPATH)umalloc.o

rm:
	$(CC) $(CFLAGS) rm.c -o $(BINPATH)rm.o
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $(BINPATH)$@ $(BINPATH)rm.o $(BINPATH)ulibc.o $(BINPATH)usys.o $(BINPATH)printf.o $(BINPATH)umalloc.o

rmdir:
	$(CC) $(CFLAGS) rmdir.c -o $(BINPATH)rmdir.o
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $(BINPATH)$@ $(BINPATH)rmdir.o $(BINPATH)ulibc.o $(BINPATH)usys.o $(BINPATH)printf.o $(BINPATH)umalloc.o

sh:
	$(CC) $(CFLAGS) sh.c -o $(BINPATH)sh.o
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $(BINPATH)$@ $(BINPATH)sh.o $(BINPATH)ulibc.o $(BINPATH)usys.o $(BINPATH)printf.o $(BINPATH)umalloc.o

wc:
	$(CC) $(CFLAGS) wc.c -o $(BINPATH)wc.o
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $(BINPATH)$@ $(BINPATH)wc.o $(BINPATH)ulibc.o $(BINPATH)usys.o $(BINPATH)printf.o $(BINPATH)umalloc.o

zombie:
	$(CC) $(CFLAGS) zombie.c -o $(BINPATH)zombie.o
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $(BINPATH)$@ $(BINPATH)zombie.o $(BINPATH)ulibc.o $(BINPATH)usys.o $(BINPATH)printf.o $(BINPATH)umalloc.o
