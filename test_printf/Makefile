CC= gcc
LBY=ar
RM=rm -f
SRC= *.c
OBJ= $(SRC:%.c=%.o)
NAME= printf
LBYNM= libyli
LFLAGS=scr
CFLAGS= -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format
%.o:%.c m.h
	$(CC) $(CFLAGS) -c -o $@ $<
compil: $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
lib: compil
	$(LBY) $(LFLAGS) $(LBYNM) $(OBJS)
clean: 
	$(RM) *~ $(NAME) $(LBYNM)
oclean: 
	$(RM) $(OBJ)
fclean: clean oclean
re: oclean compil
run: $(NAME)
	./$(NAME)
all: compil run lib oclean
