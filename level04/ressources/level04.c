#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/prctl.h>

int			main(void)
{
	// esp -= 0xb0 (176 bytes)
	
	int	y = 0;		// esp + 0x1c -> esp + 0x20
	char	str[128];	// esp + 0x20 -> esp + 0xa0
	//int	y_copy;		// esp + 0xa0 -> esp + 0xa4
	//int	y_copy2;	// esp + 0xa4 -> esp + 0xa8
	//int	ptrace_return;	// esp + 0xa8 -> esp + 0xac
	pid_t	pid;		// esp + 0xac -> esp + 0xb0

	pid = fork();
	bzero(&(str[0]), 128);	// fake
	if (pid == 0)
	{
		prctl(1, 1);
		ptrace(0, 0, 0, 0);
		puts("Give me some shellcode, k");
		gets(&(str[0]));
		return (0);
	}
	do
	{
		wait(&y);
		if ((y & 127) == 0 || ((y & 127) + 1) / 2 > 0)
		{
			puts("child is exiting...");
			return (0);
		}
	} while (ptrace(3, pid, 44, 0) != 11);
	puts("no exec() for you");
	kill(pid, 9);
	return (0);
}
