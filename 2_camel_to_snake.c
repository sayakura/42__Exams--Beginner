/**
 * Assignment name  : camel_to_snake
 * Expected files   : camel_to_snake.c
 * Allowed functions: malloc, free, realloc, write
 * --------------------------------------------------------------------------------
 * 
 * Write a program that takes a single string in lowerCamelCase format
 * and converts it into a string in snake_case format.
 * 
 * A lowerCamelCase string is a string where each word begins with a capital letter
 * except for the first one.
 * 
 * A snake_case string is a string where each word is in lower case, separated by
 * an underscore "_".
 * 
 * Examples:
 * $>./camel_to_snake "hereIsACamelCaseWord"
 * here_is_a_camel_case_word
 * $>./camel_to_snake "helloWorld" | cat -e
 * hello_word$
 * $>./camel_to_snake | cat -e
 * $
*/
#include <unistd.h>

void    putchar(char c)
{
    write(1, &c, 1);
}

int     isUpper(int c)
{
    return (c >= 'A' && c <= 'Z');
}

int     toLower(int c)
{
    if (isUpper(c))
        return (c + 32);
    return (c);
}

int     main(int ac, char **av)
{
    if (ac < 2)
    {
        putchar('\n');
        return (0);
    }
    int     i;

    i = 0;
    while (av[1][i])
    {
        if (isUpper(av[1][i]) && i != 0)
            putchar('_');
        putchar(toLower(av[1][i]));
        i++;
    }
    putchar('\n');
    return (0);
}
