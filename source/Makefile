#-----------------------------------------------------------------------------#
# Duke3D makefile.
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

# check out buildengine in this directory:
#  cvs -z3 -d:pserver:anonymous@cvs.icculus.org:/cvs/cvsroot login
#   (password is "anonymous", without the quotes.)
#  cvs -z3 -d:pserver:anonymous@cvs.icculus.org:/cvs/cvsroot co buildengine
#  cd buildengine
#  make
#  cd ..
#  This sucks. We'll figure out something better.
BUILDOBJS := \
	buildengine/a_gnu.o \
	buildengine/a_nasm.o \
	buildengine/cache1d.o \
	buildengine/engine.o \
	buildengine/sdl_driver.o \
	buildengine/mmulti.o \
	buildengine/unix_compat.o

CC = gcc
CFLAGS = -g $(SDL_CFLAGS) -DUSE_SDL=1 -DPLATFORM_UNIX=1 -DUSE_I386_ASM=1 -W -Wall -Wno-unused $(EXTRACFLAGS) -DVOLUMEONE=1
LDLIBS = $(SDL_LDFLAGS) -lSDL -lSDL_mixer $(EXTRALDFLAGS) -Wl,-E

all: duke3d

duke3d: 	\
	actors.o \
	animlib.o \
	control.o \
	config.o \
	game.o \
	gamedef.o \
	global.o \
	keyboard.o \
	menues.o \
	player.o \
	premap.o \
	rts.o \
	scriplib.o \
	sector.o \
	sounds.o \
	fx_man.o \
	pragmas_gnu.o
	$(CC) $^ $(BUILDOBJS) $(LDLIBS) -o $@

clean:
	rm -rf duke3d *.o

distclean: clean
	rm -rf *~
