CC				= 		cc
# CCFLAGS		=		-Wall -Wextra -Werror
CCFLAGS			=		
AR				=		ar -rsc
RM				=		rm -rf

NAME			=		pipex

# ==== Directories ========================================

OBJS_DIR		=		objs/
OBJS_DIRS		=		$(OBJS_DIR) $(GNL_OBJ_DIR) $(ALL_OBJ_DIR)

# ==== Submodule ==========================================

SUBMD_DIR		=		submodule/

SUBMD			=		$(LIBFT) $(GNL)

# ---- Submodule Libft ------------------------------------

LIBFT			=		$(LIB_DIR)libft.a

LIB_DIR			=		$(SUBMD_DIR)libft/

# ---- Submodule GNL --------------------------------------

GNL_DIR			=		$(SUBMD_DIR)get_next_line/
GNL				=		$(GNL_DIR)get_next_line.a
GNL_OBJ_DIR		=		$(OBJS_DIR)$(GNL_DIR)

GNL_HEADER		=		get_next_line.h
GNL_DIR_HEADER	=		$(GNL_DIR)$(GNL_HEADER)

GNL_FILES		=		get_next_line.c \
						get_next_line_utils.c

GNL_DIR_FILES	=		$(addprefix $(GNL_DIR), $(GNL_FILES))
GNL_OBJ_FILES	=		$(addprefix $(OBJS_DIR), $(GNL_DIR_FILES:.c=.o))

# ==== Header =============================================

HEADER_DIR		=	 	include/

# ==== Source ==============================================

SRC_DIR			=		src/
SRC_OBJ_DIR		=		$(OBJS_DIR)$(SRC_DIR)

SRC_FILE		=		main.c \
						pipex.c

SRC_DIR_FILES	=		$(addprefix $(SRC_DIR), $(SRC_FILE))
SRC_OBJ_FILES	=		$(addprefix $(OBJS_DIR), $(SRC_DIR_FILES:.c=.o))

# ---- Source Utils ----------------------------------------

UTIL_DIR		=		$(SRC_DIR)utils/
UTIL_OBJ_DIR	=		$(OBJS_DIR)$(UTIL_DIR)

UTIL_FILES		=		ft_puterror.c \
						free_pipex.c \
						free_array.c \
						close_fds.c

UTIL_DIR_FILES	=		$(addprefix $(UTIL_DIR), $(UTIL_FILES))
UTIL_OBJ_FILES	=		$(addprefix $(OBJS_DIR), $(UTIL_DIR_FILES:.c=.o))

# ---- Source Initial -------------------------------------

INIT_DIR		=		$(SRC_DIR)initialize/
INIT_OBJ_DIR	=		$(OBJS_DIR)$(INIT_DIR)

INIT_FILES		=		initialize_pipex.c \
						initialize_fds.c \
						initialize_pipe_fds.c \
						initialize_cmd_args.c \
						initialize_cmd_paths.c \
						setup_io_fds.c \
						setup_hdoc_fds.c \
						free_initialize.c

INIT_DIR_FILES	=		$(addprefix $(INIT_DIR), $(INIT_FILES))
INIT_OBJ_FILES	=		$(addprefix $(OBJS_DIR), $(INIT_DIR_FILES:.c=.o))

# ---- Source Processer -------------------------------------

PROC_DIR		=		$(SRC_DIR)process/
PROC_OBJ_DIR	=		$(OBJS_DIR)$(PROC_DIR)

PROC_FILES		=		pipex_process.c

PROC_DIR_FILES	=		$(addprefix $(PROC_DIR), $(PROC_FILES))
PROC_OBJ_FILES	=		$(addprefix $(OBJS_DIR), $(PROC_DIR_FILES:.c=.o))

# ==== ALL ===============================================

ALL_OBJ_DIR		=		$(SRC_OBJ_DIR) \
						$(INIT_OBJ_DIR) \
# 						$(UTIL_OBJ_DIR) \
# 						$(PROC_OBJ_DIR)

ALL_OBJS		=		$(SRC_OBJ_FILES) \
						$(INIT_OBJ_FILES) \
						# $(UTIL_OBJ_FILES) \
						# $(PROC_OBJ_FILES)

COLOUR_GREEN	=		\033[0;32m
COLOUR_RED		=		\033[0;31m
COLOUR_BLUE		=		\033[0;34m
COLOUR_END		=		\033[0m

all: $(NAME)
	@printf "$(COLOUR_GREEN)Complie $@ Completed!!!\n$(COLOUR_END)"

$(NAME): $(OBJS_DIRS) $(SUBMD) $(ALL_OBJS) Makefile
	$(CC) $(CCFLAGS) -I $(HEADER_DIR) $(LIBFT) $(GNL) -o $@ $(ALL_OBJS)
	@printf "$(COLOUR_GREEN)Complie $@ Completed!!!\n$(COLOUR_END)"

$(OBJS_DIRS):
	@mkdir -p $@

$(LIBFT): $(LIB_DIR)
	@make --no-print-directory -C $(LIB_DIR)

$(GNL): $(GNL_OBJ_FILES)
	$(AR) $@ $?
	@printf "$(COLOUR_GREEN)Complie Get_next_line Completed!!!\n$(COLOUR_END)"

$(GNL_OBJ_DIR)%.o: $(GNL_DIR)%.c $(GNL_DIR_HEADER)
	$(CC) $(CCFLAGS) -I $(GNL_DIR_HEADER) -c $< -o $@

$(SRC_OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CCFLAGS) -c $< -o $@

# $(UTIL_OBJ_FILES)%.o: $(UTIL_DIR)%.c
# 	@printf "$(COLOUR_GREEN)Complie Utility Objects Completed!!!\n$(COLOUR_END)"
# 	$(CC) $(CCFLAGS) -c $< -o $@

bonus: all

clean:
	@make clean -C $(LIB_DIR)
	$(RM) $(OBJS_DIR)
	@printf "$(COLOUR_RED)Remove Objects Completed\n$(COLOUR_END)"

fclean: clean
	@make fclean -C $(LIB_DIR)
	$(RM) $(GNL)
	@printf "$(COLOUR_RED)Remove Get_next_line Completed\n$(COLOUR_END)"
	$(RM) $(NAME)
	@printf "$(COLOUR_RED)Remove pipex Completed\n$(COLOUR_END)"
	

re: fclean all

.PHONY: all clean fclean re bonus

.SILENT: fclean clean $(NAME) $(ALL_OBJS) $(GNL) $(GNL_OBJ_FILES)