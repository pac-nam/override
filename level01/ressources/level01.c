#include <stdio.h>
#include <string.h>
#include <strings.h>

char a_user_name[256];

int verify_user_name()
{
	puts("verifying username....");
	return (strncmp("dat_wil", a_user_name, 7));
}

int verify_user_pass(char *pass)
{
	return (strncmp("admin", pass, 5));
}

int main(void)
{
	// esp -= 0x60 (96 bytes)
	int	ret;		// fake
	char	pass[64];	// esp + 0x1c -> esp + 0x5c
	int	nb;		// esp + 0x5c -> esp + 0x60

	bzero(&(pass[0]), 64);	// fake
	nb = 0;
	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(a_user_name, 256, (FILE *)stdin);
	if ((nb = verify_user_name()))
	{
		puts("nope, incorrect username...\n");
		ret = 1;
	}
	else
	{
		puts("Enter Password: ");
		fgets(pass, 100, (FILE *)stdin);
		nb = verify_user_pass(pass);
		if (nb == 0)
		{
			puts("nope, incorrect password...\n");
			ret = 1;
		}
		if (nb == 0)
		{
			ret = 0;
		}
	}
	return (ret);
}
