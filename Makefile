NAME:=libft.a

CC:=gcc
CFLAGS:=-Wall -Wextra -Werror

ifeq ($(DEBUG),yes)
	CFLAGS+=-g3 -fsanitize=address
else ifeq ($(DEBUG),g3)
	CFLAGS+=-g3
endif

OBJ_D:=obj
INC_D:=-Iinc
SRC_D:=src

include src/ft_astr/ft_astr.mk
include src/ft_list/ft_list.mk
include src/ft_printf/ft_printf.mk
include src/ft_stdlib/ft_stdlib.mk
include src/ft_stdio/ft_stdio.mk
include src/ft_string/ft_string.mk
include src/array/array.mk
include src/qbuf/qbuf.mk
include src/ft_hashset/ft_hashset.mk

VPATH_C:=$(addprefix $(SRC_D)/, $(PATH_C))

ITEM:=$(OBJ:%.c=%.o)

OBJ:=$(addprefix $(OBJ_D)/,$(ITEM))

vpath %.c $(VPATH_C)
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
	@echo $(VPATH_C)
