#----------------------------------------------------------------------------
# Makefile for building DUKESND on Unix/Cygwin systems.
#
#  Written by Ryan C. Gordon (icculus@linuxgames.com)
#----------------------------------------------------------------------------

#-----------------------------------------------------------------------------#
# If this makefile fails to detect Cygwin correctly, or you want to force
#  the build process's behaviour, set it to "true" or "false" (w/o quotes).
#-----------------------------------------------------------------------------#
#cygwin := true
#cygwin := false
cygwin := autodetect

#-----------------------------------------------------------------------------#
# You only need to set SDL_INC_DIR and SDL_LIB_DIR if you are using cygwin.
#  SDL_INC_DIR is where SDL.h and associated headers can be found, and
#  SDL_LIB_DIR is where SDL.lib and SDL.dll are located. These may be set as
#  environment variables, if you'd prefer to not hack the Makefile.
#
# examples:
#   SDL_INC_DIR := C:/2/SDL-1.1.8/include
#   SDL_LIB_DIR := C:/2/SDL-1.1.8/lib
#-----------------------------------------------------------------------------#
ifeq ($(strip $(SDL_INC_DIR)),)
  SDL_INC_DIR := please_set_me_cygwin_users
endif

ifeq ($(strip $(SDL_LIB_DIR)),)
  SDL_LIB_DIR := please_set_me_cygwin_users
endif


#-----------------------------------------------------------------------------#
# To use a different platform's ASM or portable C, change this.
#  (note that this MUST be -DUSE_I386_ASM right now if you even want a
#   prayer of having a successful compilation.)
#-----------------------------------------------------------------------------#
USE_ASM := -DUSE_I386_ASM


#-----------------------------------------------------------------------------#
# Don't touch this unless you know what you are doing.
#-----------------------------------------------------------------------------#
usedlls := true
#usedlls := false

#-----------------------------------------------------------------------------#
# Everything below this line is probably okay.
#-----------------------------------------------------------------------------#

ifeq ($(strip $(cygwin)),autodetect)
  ifneq ($(strip $(shell gcc -v 2>&1 |grep "cygwin")),)
    cygwin := true
  else
    cygwin := false
  endif
endif


ifeq ($(strip $(cygwin)),true)
  # (no choice on Cygwin right now...)
  usedlls := false

  ifeq ($(strip $(SDL_INC_DIR)),please_set_me_cygwin_users)
    $(error Cygwin users need to set the SDL_INC_DIR envr var.)
  else
    SDL_CFLAGS := -I$(SDL_INC_DIR)
  endif

  ifeq ($(strip $(SDL_LIB_DIR)),please_set_me_cygwin_users)
    $(error Cygwin users need to set the SDL_LIB_DIR envr var.)
  else
    SDL_LDFLAGS := -L$(SDL_LIB_DIR) -lSDL
  endif
else
  SDL_CFLAGS := $(shell sdl-config --cflags)
  SDL_LDFLAGS := $(shell sdl-config --libs)
endif

CC = gcc

ifeq ($(strip $(cygwin)),true)
  ASM = nasmw
  DLL_EXT = .dll
  EXE_EXT = .exe
  ASMOBJFMT = win32
  ASMDEFS = -dC_IDENTIFIERS_UNDERSCORED
  CFLAGS += -DC_IDENTIFIERS_UNDERSCORED
else
  ASM = nasm
  DLL_EXT = .so
  EXE_EXT =
  ASMOBJFMT = elf
endif

ifeq ($(strip $(usedlls)),true)
SNDBASE = dukesnd
SNDDLL = $(strip $(SNDBASE))$(strip $(DLL_EXT))
endif

SNDSRCS = fx_man.c

SNDDIR = .
ASMFLAGS = -f $(ASMOBJFMT) $(ASMDEFS)
LINKER = gcc
CFLAGS += $(USE_ASM) -Werror -funsigned-char -DPLATFORM_UNIX -O2 -g -Wall $(SDL_CFLAGS) -fasm -fno-omit-frame-pointer
LDFLAGS += -g $(SDL_LDFLAGS) -lSDL_mixer

# Rules for turning source files into .o files
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.asm
	$(ASM) $(ASMFLAGS) -o $@ $<

# Rule for getting list of objects from source
SNDOBJS1 := $(SNDSRCS:.c=.o)
SNDOBJS := $(SNDOBJS1:.asm=.o)

CLEANUP = $(SNDOBJS) $(SNDDLL) \
          $(wildcard *.exe) $(wildcard *.obj) \
          $(wildcard *~) $(wildcard *.err) \
          $(wildcard .\#*) core


ifeq ($(strip $(usedlls)),true)

all: $(SNDDLL)

$(SNDDLL) : $(SNDOBJS)
	$(LINKER) -shared -o $(SNDDLL) $(LDFLAGS) $(SNDOBJS)
ifneq ($(strip $(cygwin)),true)
	perl -w ./watcom_sdl_syms.pl $(SNDDLL) > dukesnd_watcom.h
endif

else

all: $(SNDOBJS)

endif


listclean:
	@echo "A 'make clean' would remove" $(CLEANUP)

clean:
	rm -f $(CLEANUP)

# end of Makefile ...

