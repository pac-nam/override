#include <stdio.h>
#include <string.h>

int	decrypt(int param1)
{
	int	i = 0;
	char	buff[17] = "Q}|u`sfg~sf{}|a3";	
	
	while (buff[i])
	{
		buff[i] ^= param1;
		i += 1;
	}
	if (!strncmp("Congratulations!", buff, 17))
	{
		printf("0x1337d00d - %d = %d\n", param1, 322424845 - param1);
		return (1);
	}
	return (0);
}

int	main()
{
	int	i = 0;
	while (!decrypt(i++))
		if (i > 21)
		{
			printf("no answer\n");
			break ;
		}
	return (0);
}
