# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acyrenna <acyrenna@school21.ru>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 23:41:19 by acyrenna          #+#    #+#              #
#    Updated: 2021/01/09 15:32:37 by acyrenna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

LIB = ./libft.a
LIB_DYNAMIC = libft.so
DEBUGLIB = ./libftdebug.a
TEST = ./test/test
CMAKEDIR = ./tmp/

all: $(NAME)
so: cmake_so

$(NAME): callcmake

callcmake: $(CMAKEDIR) $(CMAKEDIR)Makefile
	make -C $(CMAKEDIR)

$(CMAKEDIR):
	mkdir -p $(CMAKEDIR)

cmake: $(CMAKEDIR)
	cd $(CMAKEDIR); cmake ../

cmake_so: $(CMAKEDIR)
	cd $(CMAKEDIR); cmake -DCOMPILE_SO:BOOL=ON ../
	make -C $(CMAKEDIR)
	mv $(CMAKEDIR)lib$(LIB_DYNAMIC) $(LIB_DYNAMIC)

$(CMAKEDIR)Makefile:
	cd $(CMAKEDIR); cmake ../

clean:
	rm -r -f $(DEBUGLIB)
	rm -r -f $(CMAKEDIR)
	rm -r -f $(TEST)

fclean: clean
	rm -r -f $(LIB)
	rm -r -f ${LIB_DYNAMIC}

re: fclean all

debug: $(CMAKEDIR) $(CMAKEDIR)Makefile
	$(MAKE) -C $(CMAKEDIR) libftdebug

test: all
