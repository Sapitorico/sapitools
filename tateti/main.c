#include "main.h"
int main(void)
{
	int i = 0;
	int j = 0;
	char board[3][3] = {
		{ ' ', ' ', ' ' },
		{ ' ', ' ', ' ' },
		{ ' ', ' ', ' ' }
	};
	int turn = 1;
	int row = 0, col = 0;
	int result = 0;
	int full = 1;

	while (1)
	{
		printf("\n");
		printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
		printf("---+---+---\n");
		printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
		printf("---+---+---\n");
		printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
		printf("\nPlayer %d, enter your move: ", turn);
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ')
		{
			printf("\nInvalid move. Please try again.\n");
			continue;
		}
		board[row][col] = (turn == 1) ? 'X' : 'O';
		result = checkForWin(board);
		if (result != 0)
		{
			printf("\nPlayer %d wins!\n", result);
			break;
		}
		for (; i < 3; i++)
		{
			for (; j < 3; j++)
			{
				if (board[i][j] == ' ')
				{
					full = 0;
				}
			}
		}
		if (full)
		{
			printf("\nThe board is full. It's a draw.\n");
			break;
		}
		turn = (turn == 1) ? 2 : 1;
	}
	return (0);
}
