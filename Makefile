TARGET = TripleTriad
OBJS = main.o graphics.o framebuffer.o game.o

CFLAGS = -O2 -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)
LIBDIR =
LIBS = -lpspgu -lpsppower -lpng -lz -lm
LDFLAGS =

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Triple Triad

PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak