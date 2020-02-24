#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	unsigned int	i;

	if (ac < 2)
	{
		puts("no arguments");
		return (1);
	}
	while (--ac)
	{
		i = (unsigned int)atoi(*(++av));
		if (i % 3 == 0)
			printf("%s -> %u\n", *av, i ^ (1 << 30));
		else
			printf("%s -> %s\n", *av, *av);
	}
	return (0);
}
