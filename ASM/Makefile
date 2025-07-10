COLLEEN =	Colleen
GRACE =		Grace
SULLY = 	Sully

COLLEEN_SRC =	Colleen.s
GRACE_SRC = 	Grace.s
SULLY_SRC =		Sully.s

COLLEEN_OBJ =	Colleen.o
GRACE_OBJ = 	Grace.o
SULLY_OBJ =		Sully.o

ASM =	nasm
ASMFLAGS = -f elf64

CC =	gcc
CFLAGS = -Wall -Wextra -Werror

all: $(COLLEEN) $(GRACE) $(SULLY)

%.o: %.s
	$(ASM) $(ASMFLAGS) $< -o $@

Colleen: $(COLLEEN_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

Grace: $(GRACE_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

Sully: $(SULLY_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o

fclean: clean
	rm -f $(COLLEEN) $(GRACE) $(SULLY)
	rm -f tmp_Colleen Grace_kid.s Sully_*

re: fclean all

.PHONY: all clean fclean re