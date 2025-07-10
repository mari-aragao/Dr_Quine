COLLEEN =	Colleen
GRACE =		Grace
SULLY = 	Sully

COLLEEN_SRC =	Colleen.c
GRACE_SRC = 	Grace.c
SULLY_SRC =		Sully.c

COLLEEN_OBJ =	Colleen.o
GRACE_OBJ = 	Grace.o
SULLY_OBJ =		Sully.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(COLLEEN) $(GRACE) $(SULLY)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

Colleen: $(COLLEEN_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

Grace: $(GRACE_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

Sully: $(SULLY_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(COLLEEN) $(GRACE) $(SULLY)
	rm -f tmp_Colleen Grace_kid.c Sully_*

re: fclean all

.PHONY: all clean fclean re