.RECIPEPREFIX=:

SRC=esub.c
EXE = esub
CC = cc
CFLAGS = -Wall -Wextra -g

TEST_PATTERN_1 = (regular) (express)ion(s?)
TEST_SUBS_1 = to \2 emotion\3 \1ly
TEST_STRING_1 = "learn regular expressions!"


GENERATES = $(EXE) *.out

all: $(EXE)

check: $(EXE)
: ./$< "$(TEST_PATTERN_1)" "$(TEST_SUBS_1)" $(TEST_STRING_1) > esub.out
: echo $(TEST_STRING_1) | sed -E "s/$(TEST_PATTERN_1)/$(TEST_SUBS_1)/g" > sed.out
: diff esub.out sed.out

clean:
: rm -f $(GENERATES)