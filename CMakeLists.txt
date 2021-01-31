cmake_minimum_required(VERSION 3.17)
project(ft_printf C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)

add_executable(ft_printf.c
        main.c
        ft_printf.h
        ft_isdigit.c
        ft_itoa.c
        itoa_for_xx.c
        ft_putchar.c
        ft_strlen.c
        print_c.c
        print_s.c
        ft_printf.c
        parser.c
        print_xX.c
        print_dd.c
        itoa_dd.c
        ft_itoa_p.c
        print_p.c
        print_u.c
        itoa_u.c
        print_prec.c)
