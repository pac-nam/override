#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef	struct s_auth
{
	//	192 bytes
	char	msg[140];	// 0	-> 140
	char	name[40];	// 140	-> 180
	int	nb;		// 180	-> 184
	// align 16		// 184	-> 192
}		t_auth;

void	secret_backdoor(void)
{
	char	buf[512];

	fgets(buf, 512, (FILE*)stdin);
	system(buf);
}

void	set_msg(t_auth *id)
{
	// rsp -= 0x410 (1040 bytes)

	//t_auth	*id2;		// rbp - 0x408	-> rbp - 0x400
	char	buf[1024];		// rbp - 0x400	-> rbp - 0x0
	
	bzero(buf, 1024);		// fake
	puts(">: Msg @Unix-Dude");
	printf(">>: ");
	fgets(buf, 1024, (FILE*)stdin);
	strncpy(id->msg, buf, id->nb);
}

void	set_username(t_auth *id)
{
	// rsp -= 0xac (160 bytes)

	//t_auth	*id2;		// rbp - 0x98	-> rbp - 0x90
	char	buf[128];		// rbp - 0x90	-> rbp - 0x10
	int	i;			// rbp - 0x4	-> rbp - 0x0

	bzero(buf, 128);		// fake
	puts(">: Enter your username");
	printf(">>: ");
	fgets(buf, 128, (FILE *)stdin);
	i = 0;
	while (i <= 40 && buf[i])
	{
		id->name[i] = buf[i];
		i++;
	}
	printf(">: Welcome, %s", id->name);
}

void	handle_msg(void)
{
	// rsp -= 0xc0 (192 bytes)

	t_auth	id;			// rbp - 0xc0	-> rbp - 0x0
	
	bzero(id.name, 40);		// fake
	id.nb = 140;
	set_username(&id);
	set_msg(&id);
	puts(">: Msg sent!");
}

int	main(void)
{
	puts("--------------------------------------------");
	puts("|   ~Welcome to l33t-m$n ~    v1337        |");
	puts("--------------------------------------------");
	handle_msg();
	return (0);
}
