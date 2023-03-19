#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define CELL_MAX (5 * 5 - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[5][5])
{
    int cell = 0;

    print_sep(5);
    for (int row = 0; row < 5; ++row) {
        for (int column = 0; column < 5; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(5);
    }
}

char get_winner(char board[5][5])
{
    char winner = '-';
    int i = 0;
    int j = 0;
    while (i < 5)
    {
        if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X' && board[i][3] == 'X' && board[i][4] == 'X')
        {
            winner = 'X'; 
        }
        if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O' && board[i][3] == 'O' && board[i][4] == 'O')
        {
            winner = 'O';
        }
        i = i +1;
    }
    while (j < 5)
    {
        if (board[0][j] == 'X' && board[1][j] == 'X' && board[2][j] == 'X' && board[3][j] == 'X'  && board[4][j] == 'X')
        {
            winner = 'X';
        }
        if (board[0][j] == 'O' && board[1][j] == 'O' && board[2][j] == 'O' && board[3][j] == 'O' && board[4][j] == 'O')
        {
            winner = 'O';
        }
        j = j +1;
    }
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X' && board[3][3] == 'X' && board[4][4] == 'X')
    {
        winner = 'X';
    }
    if (board[0][4] == 'X' && board[1][3] == 'X' && board[2][2] == 'X' && board[3][1] == 'X' && board[4][0] == 'X')
    {
        winner = 'X';
    }
        if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O' && board[3][3] == 'O' && board[4][4] == 'O')
    {
        winner = 'O';
    }
    if (board[0][4] == 'O' && board[1][3] == 'O' && board[2][2] == 'O' && board[3][1] == 'O' && board[4][0] == 'O')
    {
        winner = 'O';
    }
    
    return winner;
}

bool has_free_cell(char board[5][5])
{
    bool free_cell=false;
    int row = 0;
    int column = 0;
    while (row < 5)
    {
        column = 0;
        while (column < 5)
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
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[5][5] = {
        { '-', '-', '-', '-', '-' },
        { '-', '-', '-', '-', '-' },
        { '-', '-', '-', '-', '-' },
        { '-', '-', '-', '-', '-' },
        { '-', '-', '-', '-', '-' }
    };

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
            int row = cell / 5;
            int colum = cell % 5;
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
