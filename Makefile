NAME:=libft.a

CC:=gcc
CFLAGS:=-Wall -Wextra -Werror

ifeq ($(DEBUG),yes)
	CFLAGS+=-g3 -fsanitize=address
else ifeq ($(DEBUG),g3)
	CFLAGS+=-g3
endif

OBJ_D:=obj
INC_D:=\
-Iinc

include ft_stdlib/ft_stdlib.mk
include ft_stdio/ft_stdio.mk
include ft_string/ft_string.mk
include array/array.mk

ITEM:=$(OBJ:%.c=%.o)

OBJ:=$(addprefix $(OBJ_D)/,$(ITEM))

vpath %.c $(PATH_C)
vpath %.h inc

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_D)/%.o: %.c $(HEADERS)
	@mkdir -p $(OBJ_D)
	$(CC) $(CFLAGS) -c -o $@ $< $(INC_D)

clean:
	$(RM) -r $(OBJ_D)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug:
	@echo $(OBJ)
	@echo $(PATH_C)
