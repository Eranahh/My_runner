/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** do the fonction to convert in a number
*/

int my_getnbr(char *str)
{
    int i = 0;
    int vari = 1;
    int vara = 0;
    int last = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i++] == '-')
            vari = vari * -1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        vara = vara * 10;
        vara = vara + str[i++] - '0';
        if (last > 8)
            return (0);
        last++;
    }
    return (vara * vari);
}
