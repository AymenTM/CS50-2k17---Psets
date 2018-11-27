# * * * * * * * * * * * * * * * * * * * #
#                                       #
#     PROJECT MAKEFILE FRAMEWORK V3     #
#                                       #
# * * * * * * * * * * * * * * * * * * * #

# COMPILER & MAIN FLAGS =======================================================

CC             =       gcc

CFLAGS         =       -Wall -Wextra -Werror $(ADD_FLAGS)

WFLAGS         =       -Wshadow-all                                          \
                       -Wno-sign-compare

OPTM_FLAGS     =       -O3

DBUG_FLAGS     =       -O0 -ggdb

FSAN_FLAGS     =       -fsanitize=address                                    \
                       -fsanitize=undefined                                  \
                       -fno-omit-frame-pointer                               \
                       -fsanitize-address-use-after-scope

ADD_FLAGS      =       $(WFLAGS) $(DBUG_FLAGS) $(FSAN_FLAGS)



# FILES =======================================================================

NAME      =     a

SOURCES   =     test_main.c


# MAIN ========================================================================

all: $(NAME)

$(NAME): $(SOURCES)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo && echo "   [√] 	[Compilation Successful]"
	@echo && ls "./"


# HOUSE KEEPING ===============================================================

DEL 	= rm -rf
JUNK 	= *.dSYM .DS_store ._DS*

.PHONY: all clean fclean dclean re c d x

clean:
	@echo
	@$(DEL) $(OBJECTS)
	@echo "   [√] 	[Objects Cleared]"

fclean: clean
	@$(DEL) $(NAME)
	@echo "   [√] 	[Binaries Cleared]"

dclean: clean
	@$(DEL) $(JUNK)
	@echo "   [√] 	[Debugger Info Cleared]"

re: fclean all


# CLEANING SHORTCUTS ==========================================================

c: clean

d: clean dclean
	@echo && echo "Sources/" 	&& ls "Sources/" && echo

x: fclean dclean
	@echo && echo "Pwd/" 		&& 	ls "./"
	@echo && echo "Sources/" 	&& 	ls "Sources/"
	@echo && echo "Includes/" 	&& 	ls "Includes/"
	@echo


# OTHER FSANITIZE FLAGS =======================================================

LVL2           =       -fsanitize=integer                                    \
                       -fsanitize=object-size                                \
                       -fsanitize=bounds-strict                              \
                       -fsanitize=nullability-arg                            \
                       -fsanitize=nullability-return                         \
                       -fsanitize=nullability-assign

LVL3           =       -fsanitize=thread
                       # (cannot be used in combination with =address, =leak)

-fsanitize=leak
#  clang: error: unsupported option '-fsanitize=leak' for target
#  'x86_64-apple-darwin16.7.0'

# =============================================================================

ALLFLAGS       =       $(CFLAGS)                                             \
                       $(CFLAGS2)                                            \
                       $(FSAN_FLAGS)                                         \
                       $(DBUG_FLAGS)                                         \
                       $(PROF_FLAGS)

# =============================================================================
