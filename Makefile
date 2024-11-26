CC			= 		cc
CCFLAGS		=		-Wall -Wextra -Werror
AR			=		ar -rsc
RM			=		rm -rf

NAME		=		pipex

OBJS_DIR	=		odjs/

LIB_DIR		=		libft/
LIBFT		=		libft/libft.a

GNL_DIR		=		get_next_line/

GNLHEADER	=		get_next_line/get_next_line.h
GNLFILES	=		get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c

GNL_OBJS	=		$(addprefix $(OBJS_DIR), $(GNLFILES:.c=.o))

HEADER		= 		pipex.h
FILES		=		pipex.c

UTILS		=		

FILE_OBJS	=		$(addprefix $(OBJS_DIR), $(FILES:.c=.o)) \
					$(addprefix $(OBJS_DIR), $(UTILS:.c=.o))

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS_DIR) $(LIBFT) $(GNL_OBJS) $(FILE_OBJS) Makefile
	$(CC) $(CCFLAGS) -o $@ $(FILE_OBJS) $(LIBFT) $(GNL_OBJS)

$(OBJS_DIR):
	@mkdir -p $@
	@mkdir -p $@/$(GNL_DIR)

$(LIBFT):
	@make --no-print-directory -C $(LIB_DIR)

$(GNL_OBJS)%o: $(GNLFILES)
	$(CC) $(CCFLAGS) -I $(GNLHEADER) -c $< -o $@

$(OBJS_DIR)%.o: %.c
	$(CC) $(CCFLAGS) -I $(HEADER) -c $< -o $@

clean:
	@make clean -C $(LIB_DIR)
	$(RM) $(OBJS_DIR)

fclean: clean
	@make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re