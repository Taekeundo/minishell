#include "../../include/minishell.h"

/*

WHY?

Why check PID when we are sending a hardcoded pid value
Why check this without printing the error
	printf("bash: syntax error near unexpected token `newline'\n");
What about when the first string of node->cmdstr is << or >>

	if first string of node->cmdstr is < or >
		set exit status to 0
	 		if chid process exit g_exit_status
	 		if parent process return 1
	else return 0

exit status in mac is 258 check for linux	

*/


int	redirection_syntax_error(t_cmd *type, pid_t pid)
{
	if (type->cmdstr[0][0] == '<' || type->cmdstr[0][0] == '>')
	{
		g_exit_status = 0;
		if (pid == 0)
		{
			printf("CHILD\n");
			exit (g_exit_status);
		}
		else
		{
			printf("PARENT\n");
			return (1);
		}
	}
	else
		return (0);
}