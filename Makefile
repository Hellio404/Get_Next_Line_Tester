PATH_GNL = ..

NAME = gnl_out
NAME_B = gnl_out
NAME_SUB = run_out
DIR_CPY = gnl_cpy
CC = gcc

all:  
	@echo "use \"bash run.sh\""
	@echo "use \"bash run_bonus.sh\""

$(NAME): cp_f
	@$(CC) main.c -o $(NAME)
bonus: cp_f_b
	@$(CC) main.c -o $(NAME)

f:
	@./$(NAME)
	@rm -rf $(DIR_CPY)
	@rm -rf $(NAME) $(NAME_SUB)

kk: $(NAME) f
kk_b: bonus f

cp_f: main.c gnl_main.c clean
	@mkdir $(DIR_CPY)
	@cp $(PATH_GNL)/get_next_line.c $(DIR_CPY)
	@cp $(PATH_GNL)/get_next_line.h $(DIR_CPY)
	@cp $(PATH_GNL)/get_next_line_utils.c $(DIR_CPY)
cp_f_b: main.c gnl_main.c clean
	@mkdir $(DIR_CPY)
	@cp $(PATH_GNL)/get_next_line_bonus.c $(DIR_CPY)/get_next_line.c
	@cp $(PATH_GNL)/get_next_line_bonus.h $(DIR_CPY)/get_next_line.h
	@cp $(PATH_GNL)/get_next_line_bonus.h $(DIR_CPY)
	@cp $(PATH_GNL)/get_next_line_utils_bonus.c $(DIR_CPY)/get_next_line_utils.c

clean: 
	@rm -rf $(DIR_CPY)
fclean: clean
	@rm -rf $(NAME) $(NAME_SUB)
re: fclean all
