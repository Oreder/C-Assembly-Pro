# Compiler
CC := gcc

# Compiler options
FLAGS := -std=c99 -Wall -Werror

# Dependency
DEPS := 

# Object files
OBJS := 05.o

%.o: %.c $(DEPS)
	$(CC) $(FLAGS) -c $<

main.exe: $(OBJS)
	$(CC) -o $@ $^
	
clean:
	$(RM) *.o *.exe