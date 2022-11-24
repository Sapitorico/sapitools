#include "main.h"
int checkForWin(char board[3][3])
{
	int i = 0;
	int j = 0;

	for (; i < 3; i++)
	{
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			if (board[i][0] == 'X')
				return (1);
			else
				return (2);
		}
	}
	for (; j < 3; j++)
	{
		if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j])
		{
			if (board[0][j] == 'X')
				return (1);
			else
				return (2);
		}
	}
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[0][0] == 'X')
			return (1);
		else
			return (2);
	}
	if (board[2][0] != ' ' && board[2][0] == board[1][1] && board[1][1] == board[0][2])
	{
		if (board[2][0] == 'X')
			return (1);
		else
			return (2);
	}
	return (0);
}
