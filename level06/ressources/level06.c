#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <stdlib.h>

int	auth(char *login, unsigned int serial)
{
	// esp -= 0x28 (40 bytes)

	int	i;		// ebp - 0x14 -> ebp - 0x10
	int	key;		// ebp - 0x10 -> ebp - 0xc
	int	len;		// ebp - 0xc  -> ebp - 0x8


	login[strcspn(login, "\n")] = '\0';
	len = strnlen(login, 32);
	if (len <= 5)
		return (1);
	if (ptrace(0, 0, 1, 0) == -1)
	{
		puts("\033[32m.---------------------------.");
		puts("\033[31m| !! TAMPERING DETECTED !!  |");
		puts("\033[32m'---------------------------'");
		return (1);
	}
	key = (login[3] ^ 0x1337) + 0x5eeded;
	i = 0;
	while (i < len)
	{
		if (login[i] < ' ')
			return (1);	
		key += /* algorithm */ - (login[i] ^ key);
		i++;
	}
	if (serial == key)
		return (0);
	return (1);
}

int			main(int ac, char **av)
{
	// esp -= 0x50 (80 bytes)
	
	char		*prog_name = av[0];	// esp + 0x1c -> esp + 0x20
	unsigned int	serial;			// esp + 0x28 -> esp + 0x2c
	char		login[32];		// esp + 0x2c -> esp + 0x4c
						// esp + 0x4c -> esp + 0x50 check corrupt
	int		ret;			// fake
	
	puts("***********************************");
	puts("*\t\tlevel06\t\t  *");
	puts("***********************************");
	printf("-> Enter Login: ");
	fgets(&(login[0]), 32, (FILE*)stdin);
	
	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");
	scanf("%u", &serial);
	
	if (auth(login, serial))
		ret = 1;
	else
	{
		puts("Authenticated!");
		system("/bin/sh");
		ret = 0;
	}
	// check corrupt stack
	return (ret);
}
