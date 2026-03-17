NAME        = pipex

# Compilateur et flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I./includes

# Répertoires
PRINTF_DIR  = libs/PRINTF
LIBFT_DIR   = libs/Libft
SRC_DIR     = src
INCLUDES    = includes

# Bibliothèques
PRINTF_LIB  = $(PRINTF_DIR)/libftprintf.a
LIBFT_LIB   = $(LIBFT_DIR)/libft.a

# Liste des sources des bibliothèques
PRINTF_SRCS = ft_printf.c ft_print_ptr.c ft_printf_unsigned.c utilis.c ft_printf_hex.c
LIBFT_SRCS  = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
              ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
              ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
              ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
              ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strlcpy.c \
              ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
              ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

# Ajout du préfixe du répertoire
PRINTF_SRC  = $(addprefix $(PRINTF_DIR)/, $(PRINTF_SRCS))
LIBFT_SRC   = $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRCS))

# Fichiers source et objets
SRCS        = $(SRC_DIR)/main.c \
              $(SRC_DIR)/utils.c \
              $(SRC_DIR)/pipex.c

OBJS        = $(SRCS:.c=.o)

# Flags pour le linker
LDFLAGS     = -L$(PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft

# Règle par défaut
all: $(NAME)

# Compilation du binaire
$(NAME): $(OBJS) $(PRINTF_LIB) $(LIBFT_LIB) includes/pipex.h
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

# Compilation des librairies
$(PRINTF_LIB): $(PRINTF_SRC)
	$(MAKE) -C $(PRINTF_DIR)

$(LIBFT_LIB): $(LIBFT_SRC)
	$(MAKE) -C $(LIBFT_DIR)

# Nettoyage des objets
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

# Nettoyage complet
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild complet
re: fclean all

.PHONY: all clean fclean re