/**
 * Assignment name  : snake_to_camel
 * Expected files   : snake_to_camel.c
 * Allowed functions: malloc, free, realloc, write
 * --------------------------------------------------------------------------------
 * 
 * Write a program that takes a single string in snake_case format
 * and converts it into a string in lowerCamelCase format.
 * 
 * A snake_case string is a string where each word is in lower case, separated by
 * an underscore "_".
 * 
 * A lowerCamelCase string is a string where each word begins with a capital letter
 * except for the first one.
 * 
 * Examples:
 * $>./camel_to_snake "here_is_a_snake_case_word"
 * hereIsASnakeCaseWord
 * $>./camel_to_snake "hello_world" | cat -e
 * helloWorld$
 * $>./camel_to_snake | cat -e
 * $
*/
#include <unistd.h>

void    putchar(char c)
{
    write(1, &c, 1);
}

int     isLower(int c)
{
    return (c >= 'a' && c <= 'z');
}

int     toUpper(int c)
{
    if (isLower(c))
        return (c - 32);
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
        if (av[1][i] == '_')
        {
            i++;
            putchar(toUpper(av[1][i]));
        }
        else 
            putchar(av[1][i]);
        i++;
    }
    putchar('\n');
    return (0);
}
