CC= gcc	#compiler
RM=rm -f	#remove files
SRC= *.c	#files to be compiled
NAME= shell	#executable name
CFLAGS= -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format	#compiler flags
compil:	#compilation 
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
clean:	#delete the executable file
	$(RM) $(NAME)
run: $(NAME)	#run the executable
	./$(NAME)
re: clean all	#recompile
all: compil run	#compile and run
