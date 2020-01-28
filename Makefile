# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 18:24:03 by ksharlen          #+#    #+#              #
#    Updated: 2020/01/28 18:24:04 by ksharlen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include vars_makefile

vpath %.o $(DIR_BIN)

NAME	:=	test

all: $(NAME)

$(NAME): $(OBJ)
	gcc -g $(PATH_OBJ) -o $@

$(OBJ): %.o:%.c $(HEADERS) | $(DIR_BIN)
	gcc -c $(CFLAGS) $< -o $(DIR_BIN)/$@

$(DIR_BIN):
	mkdir -p $@

echo:
	echo $(PATH_OBJ)

utest:
	make -f Makefile_test

clean:
	rm -rf $(DIR_BIN)*.o

fclean:
	rm -rf $(DIR_BIN)
	rm -rf $(NAME)

re:	fclean all

.PHONY: utest
.SILENT: all $(NAME) $(OBJ) $(DIR_BIN) echo clean fclean re utest
