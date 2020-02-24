#!/usr/bin/env bash

echo '
#include <stdio.h>
#include <string.h>

int	decrypt(int param1)		// 0x08048660
{
	int	i = 0;			// ebp - 0x28 -> ebp - 0x24
	char	buff[17] = "Q}|u`sfg~sf{}|a3";	
	
	while (buff[i])
	{
		buff[i] ^= param1;
		i += 1;
	}
	if (!strncmp("Congratulations!", buff, 17))
	{
		printf("%d\n", 322424845 - param1);
		return (1);
	}
	return (0);
}

int	main()
{
	int	i = 0;
	while (!decrypt(i))
		i++;
	return (0);
}
' > /tmp/level03_decrypt.c 

gcc /tmp/level03_decrypt.c -o /tmp/level03_decrypt

/tmp/level03_decrypt > /tmp/level03_res

cat /tmp/level03_res - | ./level03
