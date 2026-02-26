NAME			=	Animal
CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98

SRCDIR  = srcs
OBJDIR  = obj


SRCS     		= main.cpp\
					Animal.cpp\
					Dog.cpp\
					Cat.cpp\
					WrongAnimal.cpp\
					WrongCat.cpp
				
OBJS    = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

					
all			:	$(NAME)

clean		:
		@rm -rf $(OBJ_DIR)

fclean		:	clean
		@rm -rf $(NAME)

re			:	fclean	all

.PHONY		:	all clean fclean re