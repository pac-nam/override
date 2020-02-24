#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int ac, char **av)
{
	// rsp -= 0x120 (288 bytes)
	//char	**av2 = av;		// rbp - 0x120	-> rbp - 0x118		
	//int	ac2 = ac;		// rbp - 0x118	-> rbp - 0x114
	char	pass[100];		// rbp - 0x110	-> rbp - 0xac
	char	verif[41];		// rbp - 0xa0	-> rbp - 0x77
	char	user[100];		// rbp - 0x70	-> rbp - 0xc
	size_t	len;			// rbp - 0xc	-> rbp - 0x8
	FILE	*fd_pass;		// rbp - 0x8	-> rbp

	bzero(&(user[0]), 100);		// fake
	bzero(&(verif[0]), 41);		// fake
	bzero(&(pass[0]), 100);		// fake
	fd_pass = fopen("/home/users/level03/.pass", "r");
	if (fd_pass == 0)
	{
		fwrite("ERROR: failed to open password file\n", 1, 36, (FILE*)stderr);
		exit(1);
	}
	len = fread(&(verif[0]), 1, 41, fd_pass);
	verif[strcspn(&(verif[0]), "\n")] = '\0';
	if (len != 41)
	{
		fwrite("ERROR: failed to read password file\n", 1, 36, (FILE*)stderr);
		fwrite("ERROR: failed to read password file\n", 1, 36, (FILE*)stderr);
		exit(1);
	}
	fclose(fd_pass);
	puts("===== [ Secure Access System v1.0 ] =====");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	
	printf("--[ Username: ");
	fgets(&(user[0]), 100, (FILE*)stdin);
	user[strcspn(&(user[0]), "\n")] = '\0';
	
	printf("--[ Password: ");
	fgets(&(pass[0]), 100, (FILE*)stdin);
	pass[strcspn(&(pass[0]), "\n")] = '\0';
	
	puts("*****************************************");
	if (!strncmp(verif, pass, 41))
	{
		printf("Greetings, %s!\n", user);
		system("/bin/sh");
		return (0);
	}
	printf(user);
	puts(" does not have access!");
	exit(1);
}
