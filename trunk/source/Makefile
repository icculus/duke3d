#-----------------------------------------------------------------------------#
# ROTT makefile.
#-----------------------------------------------------------------------------#


#-----------------------------------------------------------------------------#
# If this makefile fails to detect Cygwin correctly, or you want to force
#  the build process's behaviour, set it to "true" or "false" (w/o quotes).
#-----------------------------------------------------------------------------#
#cygwin := true
#cygwin := false
cygwin := autodetect

# you only need to set these for Cygwin at the moment.
SDL_INC_DIR = /cygdrive/c/SDL/include
SDL_LIB_DIR = /cygdrive/c/SDL/lib


# Don't touch anything below this line unless you know what you're doing.

ifeq ($(strip $(cygwin)),autodetect)
  ifneq ($(strip $(shell gcc -v 2>&1 |grep "cygwin")),)
    cygwin := true
  else
    cygwin := false
  endif
endif


ifeq ($(strip $(cygwin)),true)
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
  EXTRACFLAGS += -DUSE_EXECINFO=1
endif


CC = gcc
CFLAGS = -g $(SDL_CFLAGS) -DUSE_SDL=1 -DPLATFORM_UNIX=1 -W -Wall -Wno-unused $(EXTRACFLAGS)
LDLIBS = $(SDL_LDFLAGS) -lSDL -lSDL_mixer $(EXTRALDFLAGS) -Wl,-E

all: rott

rott: 	\
	actors.o \
	animlib.o \
	config.o \
	game.o \
	gamedef.o \
	global.o \
	menues.o \
	player.o \
	premap.o \
	rts.o \
	sector.o \
	sounds.o \
	pragmas_gnu.o
	$(CC) $^ $(LDLIBS) -o $@

clean:
	rm -rf *.o

distclean: clean
	rm -rf *~
