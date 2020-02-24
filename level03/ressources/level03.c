#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void		decrypt(int param1)
{
	// esp - 0x40 (64 bytes)
	int	nb = 0xffffffff;		// ebp - 0x2c	-> ebp - 0x28
	int	nb2 = 0;			// ebp - 0x28	-> ebp - 0x24
	int	nb3;				// ebp - 0x24	-> ebp - 0x20
	char	buff[17] = "Q}|u`sfg~sf{}|a3";	// ebp - 0x1d	-> ebp - 0xc
	//int	corrupt = gs:0x14		// ebp - 0xc	-> ebp - 0x8
	
	nb3 = strlen(buff);			// fake
	while (nb2 < nb3)
	{
		buff[nb2] ^= param1;
		nb2 += 1;
	}
	if (!strncmp("Congratulations!", buff, 17))
		system("/bin/sh");
	else
		puts("\nInvalid Password");
	// check corrupted stack
}

void		test(int param1, int param2)
{
	// param1 = ebp + 0x8
	// param2 = ebp + 0xc
	// esp - 0x28 (40 bytes)
	int		tmp;	// ebp - 0xc -> ebp - 0x8

	tmp = param2 - param1;
	if (tmp <= 21)
		decrypt(tmp);
	else
		decrypt(rand());
	return ;
}

int			main(void)
{
	// esp - 0x20 (32 bytes)
	// add 4 (still 28 bytes)
	int	password;	// esp + 0x1c -> esp + 0x20
	
	srand(time(NULL));
	puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");
	printf("Password:");
	scanf("%d", &password);
	test(password, 0x1337d00d);		// 322424845
	return (0);
}
