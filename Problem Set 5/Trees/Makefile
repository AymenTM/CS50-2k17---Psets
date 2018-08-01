
# Makefile

bTrees: bTrees.c tree_lib.h treeQu_lib.h
	clang -fsanitize=integer -fsanitize=undefined -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wshadow -o bTrees bTrees.c -lm
