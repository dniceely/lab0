#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define N 4
#define CELL_MAX (N * N - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[N][N])
{
    int cell = 0;

    print_sep(N);
    for (int row = 0; row < N; ++row) {
        for (int column = 0; column < N; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(N);
    }
}

char get_winner(char board[N][N])
{
    char winner = '-';
    int i;
    int j;
    bool es_winner = true;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N-1; j++)
        {
            if (board[i][j] != board[i][j+1])
            {
            es_winner = false;
            break;
            }
        }
    if (es_winner == true)
        {
            winner = board[i][0];
            return winner;
        }
    }

    for (j = 0; j < N; j++)
    {
        es_winner = true;
        for (i = 0; i < N-1; i++)
        {
            if (board[i][j] != board[i+1][j])
        {
            es_winner = false;
            break;
        }
        }
        if (es_winner == true)
    {
        winner = board[0][j];
        return winner;
    }
}
es_winner = true;
    for (i = 0; i < N-1; i++)
    {
        if (board[i][i] != board[i+1][i+1])
        {
            es_winner = false;
            break;
        }
    }
    if (es_winner == true)
        {
            winner = board[0][0];
            return winner;
        }
        es_winner = true;
    for (i = 0, j = N -1; i < N-1; (i++, j--))
    {
        if (board[i][j] != board[i+1][j-1])
        {
            es_winner = false;
            break;
        }
    }
    if (es_winner == true)
    {
        winner = board[0][N-1];
        return winner;
    }
    return winner;
}

bool has_free_cell(char board[N][N])
{
    bool free_cell=false;
    int row = 0;
    int column = 0;
    while (row < N)
    {
        column = 0;
        while (column < N)
        {
            if (board[row][column] == '-')
            {
                free_cell = true;
            }
            column = column + 1;
        }
        row = row + 1;
    }
    return free_cell;
}

int main(void)
{
    printf("TicTacToe\n");

 char board[N][N];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
        board[i][j] = '-';
        }
    }

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posicion (numero del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / N;
            int colum = cell % N;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
