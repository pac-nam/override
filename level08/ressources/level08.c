#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void			log_wrapper(FILE *fd, char *permissions, char* file)
{
	// rsp -= 0x130 (304 bytes)
	
	//uint64_t	x;				// rbp - 0x130	-> rbp - 0x128	used for rep
	//char		*file2 = file;			// rbp - 0x128	-> rbp - 0x120
	//char		*permission2 = permission;	// rbp - 0x120	-> rbp - 0x118
	//uint64_t	fd2 = fd;			// rbp - 0x118	-> rbp - 0x110
	char		buf[264];			// rbp - 0x110	-> rpb - 0x8

							// rbp - 0x8	-> rbp - 0x0 check stack corrupt
	strcpy(buf, file);
	snprintf(buf + strlen(buf), 254 - strlen(buf), file);	// like strcat
	buf[strcspn(buf, "\n")] = '\0';
	fprintf(fd, "LOG: %s\n", buf);
	// check stack corrupt
}

int				main(int ac, char **av)
{
	// rsp -= 0xb0 (176 bytes)

	//uint64_t	x;			// rbp - 0xa8	-> rbp - 0xa0 use for rep
	//char		**av2 = av;		// rbp - 0xa0	-> rbp - 0x98
	//int		ac2 = ac;		// rbp - 0x94	-> rbp - 0x90
	FILE		*log;			// rbp - 0x88	-> rbp - 0x80
	FILE		*src;			// rbp - 0x80	-> rbp - 0x78
	int			dst = -1;		// rbp - 0x78	-> rbp - 0x74
	char		c = -1;			// rbp - 0x71	-> rbp - 0x70
	char		buff[100];		// rbp - 0x70	-> rbp - 0xc
						// rbp - 0x8	-> rbp - 0x0 check stack corrupt

	if (ac != 2)
		printf("Usage: %s filename\n", *av);
	if (!(log = fopen("./backups/.log", "w")))
	{
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}
	log_wrapper(log, "Starting back up: ", av[1]);
	if (!(src = fopen(av[1], "r")))
	{
		printf("ERROR: Failed to open %s\n", av[1]);
		exit(1);
	}
	strcpy(buff, "./backups/");		// fake
	strncat(buff, av[1], 99 - strlen(buff));
	if ((dst = open(buff,  O_WRONLY | S_IWUSR | S_IXUSR, 432)) < 0)
	{
		printf("ERROR: Failed to open %s%s\n", "./backups/", av[1]);
		exit(1);
	}
	while ((c = fgetc(src)) != -1)
		write(dst, &c, 1);
	log_wrapper(log, "Finished back up: ", av[1]);
	fclose(src);
	close(dst);
	// check stack corrupt;
	return (0);
}
