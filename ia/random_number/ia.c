#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

char board[MAX_ROWS][MAX_COLS];

void init_board();
void print_board();
int rand_num(int, int);
int check_winner();

int main(int argc, char *argv[]) {
  int row, col;
  int winner;

  srand((unsigned int)time(NULL));

  init_board();
  print_board();

  do {
    row = rand_num(0, MAX_ROWS-1);
    col = rand_num(0, MAX_COLS-1);

    if(board[row][col] != ' ') {
      continue;
    }

    board[row][col] = 'X';

    print_board();
    winner = check_winner();
  } while(winner == 0);

  if(winner == 1) {
    printf("You won!\n");
  } else {
    printf("I won!\n");
  }

  return 0;
}

void init_board() {
  int i, j;

  for(i=0; i<MAX_ROWS; i++) {
    for(j=0; j<MAX_COLS; j++) {
      board[i][j] = ' ';
    }
  }
}

void print_board() {
  int i, j;

  printf("\n");

  for(i=0; i<MAX_ROWS; i++) {
    for(j=0; j<MAX_COLS; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

int rand_num(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

int check_winner() {
  int i, j;
  int row_sum, col_sum;
  int diag_sum1, diag_sum2;

  row_sum = 0;
  col_sum = 0;
  diag_sum1 = 0;
  diag_sum2 = 0;

  for(i=0; i<MAX_ROWS; i++) {
    row_sum = 0;
    col_sum = 0;

    for(j=0; j<MAX_COLS; j++) {
      row_sum += board[i][j];
      col_sum += board[j][i];
    }

    if(row_sum == 264 || col_sum == 264) {
      return 1;
    } else if(row_sum == 237 || col_sum == 237) {
      return 2;
    }

    diag_sum1 += board[i][i];
    diag_sum2 += board[i][MAX_ROWS-i-1];
  }

  if(diag_sum1 == 264 || diag_sum2 == 264) {
    return 1;
  } else if(diag_sum1 == 237 || diag_sum2 == 237) {
    return 2;
  }

  return 0;
}
