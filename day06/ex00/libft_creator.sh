#!/bin/sh
gcc -c *.c 
ar rc libft.a *.o
rm *.o
