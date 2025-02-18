/*
** EPITECH PROJECT, 2025
** src
** File description:
** my_putnbr.c
*/

#include "../includes/my.h"

int my_put_nbr(int nb)
{
    int tmp = nb;
    int power = 0;

    if (nb < 0){
        my_putchar(45);
        nb *= -1;
    }
    if (nb == 0) {
        my_putchar('0');
        return 0;
    }
    while (tmp > 0){
        power++;
        tmp = tmp / 10;
    }
    while (power > 0){
        power--;
        my_putchar(nb / my_compute_power_rec(10, power) % 10 + 48);
    }
    return 0;
}
