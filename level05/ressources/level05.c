int main(void)
{
	// esp -= 0x90 (144 bytes)

				// esp + 0x1c -> esp + 0x20 used for strlen
	char	buf[100]	// esp + 0x28 -> esp + 0x8c
	int	i;		// esp + 0x8c -> esp + 0x90

	fgets(&(buf[0]), 100, (FILE*)stdin);
	i = 0;
	while (i < strlen(buf))	// fake strlen
	{
		if (buf[i] > '@' && buf[i] <= 'Z')
			buf[i] ^= 32;
		i += 1;
	}
	printf(buf);
	exit(0);
}
