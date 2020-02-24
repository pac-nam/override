#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int password;

	puts("***********************************");
	puts("* \t    -level00 - \t\t  *");
	puts("***********************************");
	printf("Password: ");
	scanf("%d", &password);
	if (password != 5276)
	{
		puts("\nInvalid Password!");
		return (1);
	}
	puts("\nAuthenticated!");
	system("/bin/sh");
}
