# Paths
DIR_BIN = bin

# Application meta
EXE_NAME = bank


# Compilation options
CC = gcc
CFLAGS = -fPIC




#
#	Util targets
#


.PHONY: default
default: $(DIR_BIN)/$(EXE_NAME)


.PHONY: clean
clean:
	@rm -vf '$(DIR_BIN)/$(EXE_NAME)'




#
#	Building targets
#

$(DIR_BIN)/$(EXE_NAME): LandingPage.c
	@mkdir -vp '$(dir $(@))'
	$(CC) -o '$(@)' -fPIE $(CFLAGS) $(^) -lncurses
