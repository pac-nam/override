#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

void	clear_stdin(void)
{
	// esp -= 0x18 (20 bytes)
	char	c = 0;			// ebp - 0x9	-> ebp - 0x8

	c = getchar();
	while ((c = getchar()) != -1)
		if (c == '\n')
			break ;
}

unsigned int	get_unum()
{
	// esp -= 0x29 (40 bytes)
	
	unsigned int	nb;		// ebp - 0xc	-> ebp - 0x8

	fflush((FILE*)stdin);
	scanf("%u", &nb);
	clear_stdin();
	return (nb);
}


int		read_number(int *buf)
{
	// esp -= 0x28 (40 bytes)

	unsigned int	index;		// ebp - 0xc	-> ebp - 0x8

	printf(" Index: ");
	index = get_unum();
	printf(" Number at data[%u] is %u\n", index, buf[index << 2]);
	return (0);
}

int		store_number(int *buf)
{
	// esp -= 0x28 (40 bytes)

	int	number = 0;		// ebp - 0x10	-> ebp - 0xc
	int	index = 0;		// ebp - 0xc	-> ebp - 0x8

	printf (" Number: ");
	number = get_unum();
	printf(" Index: ");
	index = get_unum();
	if (index % 3 != 0 && number >> 24 != 183)	// 0xb7 | 0xb7000 | 749568
	{
		buf[index << 2] = number;
		return (0);
	}
	puts(" *** ERROR! ***");
	puts("   This index is reserved for wil!");
	puts(" *** ERROR! ***");
	return (1);
}

int		main(int ac, char **av, char **env)
{
	// esp -= 0x1d0 (464 bytes)
					// esp + 0x14	-> esp + 0x18 used for rep
	//char	**env = env;		// esp + 0x18	-> esp + 0x1c
	//char	**av = av;		// esp + 0x1c	-> esp + 0x20

	int		buf[100];		// esp + 0x24	-> esp + 0x1b4
	int		success = 0;		// esp + 0x1b4	-> esp + 0x1b8
	char	buf2[20];		// esp + 0x1b8	-> esp + 0x1d0
					// esp + 0x1cc	-> esp + 0x1d0 check stack corruption
	
	bzero(&(buf[0]), 400);		// fake
	bzero(&(buf2[0]), 20);		// fake
	while (*av)
	{
		memset(*av, 0, strlen(*av) - 1);
		(*av)++;
	}
	while (*env)
	{
		memset(*env, 0, strlen(*env) - 1);
		(*env)++;
	}
	puts("----------------------------------------------------");	// really: one puts
	puts("  Welcome to wil's crappy number storage service!   ");	// really: one puts
	puts("----------------------------------------------------");	// really: one puts
	puts(" Commands:                               ");		// really: one puts
	
	while (1)
	{
		printf ("Input command: ");
		fgets(buf2, 20, (FILE*)stdin);
		buf2[strlen(buf2) - 2] = '\0';
		if (!strncmp("store", buf2, 5))
			success = store_number(&(buf[0]));
		else if (!strncmp("read", buf2, 4))
			success = read_number(&(buf[0]));
		else if (!strncmp("quit", buf2, 4))
			break ;
		if (success == 0)
			printf(" Completed %s command successfully\n", buf2);
		else
			printf(" Failed to do %s command\n", buf2);
		bzero(&(buf2[0]), 20);
	}
	// check stack corruption
	return (0);
	
}
