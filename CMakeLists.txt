cmake_minimum_required(VERSION 3.25)
project(philosophers C)

set(CMAKE_C_STANDARD 11)

include_directories(src/libft)

add_executable(philosophers
        src/libft/ft_atoi.c
        src/libft/ft_bzero.c
        src/libft/ft_calloc.c
        src/libft/ft_free_str.c
        src/libft/ft_isalnum.c
        src/libft/ft_isalpha.c
        src/libft/ft_isascii.c
        src/libft/ft_isdigit.c
        src/libft/ft_isprint.c
        src/libft/ft_itoa.c
        src/libft/ft_memchr.c
        src/libft/ft_memcmp.c
        src/libft/ft_memcpy.c
        src/libft/ft_memmove.c
        src/libft/ft_memset.c
        src/libft/ft_putchar_fd.c
        src/libft/ft_putendl_fd.c
        src/libft/ft_putnbr_fd.c
        src/libft/ft_putstr_fd.c
        src/libft/ft_split.c
        src/libft/ft_strchr.c
        src/libft/ft_strdup.c
        src/libft/ft_striteri.c
        src/libft/ft_strjoin.c
        src/libft/ft_strlcat.c
        src/libft/ft_strlcpy.c
        src/libft/ft_strlen.c
        src/libft/ft_strmapi.c
        src/libft/ft_strncmp.c
        src/libft/ft_strnstr.c
        src/libft/ft_strrchr.c
        src/libft/ft_strtrim.c
        src/libft/ft_substr.c
        src/libft/ft_tolower.c
        src/libft/ft_toupper.c
        src/libft/libft.h src/check_arg.c src/threads_maker.c)
