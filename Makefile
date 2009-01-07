TARGET = TripleTriad
OBJS = main.o graphics.o framebuffer.o game.o

CFLAGS = -O2 -G0 -Wall -g
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)
LIBDIR =
LIBS = -lpspgu -lpsppower -lpng -lz -lm
LDFLAGS =

PSP_FW_VERSION=200
BUILD_PRX = 1
EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Triple Triad


PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak