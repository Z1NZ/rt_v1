#	Library output
NAME = ray-tracer

#	GCC flags
CFLAGS = -Ofast -Wall -Wextra -Werror
#ALL_MLX =
ALL_MLX = -lmlx -framework OpenGL -framework AppKit -Ofast

#	Includes directories
INC_RT = includes
INCLUDES += $(addprefix -iquote , $(INC_RT))

#	Sources
RT_SOURCES = $(shell find lib | grep "\.c$$" | sed "s/\.c$$//g")
SRCS = $(addsuffix .c, $(RT_SOURCES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo ">>>>> Génération de RT"
	@gcc $(OBJS) -o $(NAME) $(ALL_MLX)
	@echo "Terminée"

# To obtain object files
%.o: %.c
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

# To remove generated files
clean:
	@echo "RM\ttous les objects (.o)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "RM\tprojet ($(NAME))"
	@$(RM) $(NAME)

lftclean:
	make -C libft clean

lftfclean:
	make -C libft fclean

re: fclean all

git:
	@git add .
	@echo "Enter Your Commit :"
	@read var1 ; git commit -m "$$var1"
	@git push
