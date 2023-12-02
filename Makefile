NAME = test

FILES = warning_printf_test.c

SRCS = $(FILES:%.c=$(DIR)/%.c)
OBJS = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror
LIB = ../libftprintf.a
INCLUDE = $(DIR)/test.h

DIR = ./srcs

LIBFTPRINTF = all 
EXEC		= ./test

NO = --no-print-directory

ifdef WARNING
	CFLAGS = 
	SRCS := $(SRCS:%.c=%_warning.c)
	OBJS := $(OBJS:%.o=%.o)
endif

ifdef WITH_BONUS
	LIBFTPRINTF = bonus
endif

all: LIBFTPRINTF $(NAME)

LIBFTPRINTF:
	@make fclean $(LIBFTPRINTF) -C ../ --no-print-directory

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)."
	@cc -o $(NAME) $(OBJS) $(CFLAGS) -Ofast $(LIB) -I ./srcs

%.o: %.c
	@cc -c $< -o $@ $(CFLAGS) -I ./srcs

m:
	@make fclean $(NO)
	@make all $(NO)

me:
	@make fclean $(NO)
	@make all $(NO)
	@./test

b:
	@make fclean $(NO)
	@make WITH_BONUS=TRUE $(NO)

be:
	@make fclean $(NO)
	@make WITH_BONUS=TRUE $(NO)
	@./test "b"

clean:
	@echo "Removing objects."
	@rm -f srcs/*.o

fclean: clean
	@echo "Removing $(NAME)."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
