#
# Makefile
#
# Computer Science 50
# Problem Set 5
#


# compiler to use
CC = clang

# flags to pass compiler
CFLAGS = -Wall -Werror -Wextra -O3 $(DBUG_FLAGS) $(FSAN_FLAGS)



# name for executable
EXE = speller

# space-separated list of header files
HDRS = dictionary.h \
       utils.h

# space-separated list of source files
SRCS = speller.c \
       dictionary.c \
       utils.c

# automatically generated list of object files
OBJS = $(SRCS:.c=.o)

# space-separated list of libraries, if any,
# each of which should be prefixed with -l
LIBS =



# default target
$(EXE): $(OBJS) $(HDRS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

# # dependencies 
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@



# housekeeping
clean:
	rm -f core $(EXE) *.o *.dSYM*

DBUG_FLAGS     =       -O0 -ggdb

FSAN_FLAGS     =       -fsanitize=address                                    \
                       -fsanitize=undefined                                  \
                       -fno-omit-frame-pointer                               \
                       -fsanitize-address-use-after-scope
