PATH_GNL = ../

NAME = yf_gnl
NAME_SUB = run_out

CC = gcc

all:  $(NAME) f
f:
	@./$(NAME)
$(NAME): main.c gnl_main.c clean
	@mkdir gnl
	@cp $(PATH_GNL)get_next_line.c ./gnl
	@cp $(PATH_GNL)get_next_line.h ./gnl
	@cp $(PATH_GNL)get_next_line_utils.c ./gnl
	@$(CC) main.c -o $(NAME)
clean: 
	@rm -rf gnl
fclean: clean
	@rm -rf $(NAME) $(NAME_SUB)
re: fclean all
