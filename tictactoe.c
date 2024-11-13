// TIC-TAC-TOE GAME

#include <stdio.h>

void display_board(char pt_tic_tac_toe_board[3][3]);
void player_1_turn(int *pt_coordinate_x, int *pt_coordinate_y, char pt_tic_tac_toe_board[3][3]);
void player_2_turn(int *pt_coordinate_x, int *pt_coordinate_y, char pt_tic_tac_toe_board[3][3]);
int check_game_over_player_1(int *pt_coordinate_x, int *pt_coordinate_y, char pt_tic_tac_toe_board[3][3]);
int check_game_over_player_2(int *pt_coordinate_x, int *pt_coordinate_y, char pt_tic_tac_toe_board[3][3]);

//-----------------------------------------------------

int main(void) {

    // Empty board
    char tic_tac_toe_board[3][3] = {
        {'.', '.', '.'},
        {'.', '.', '.'},
        {'.', '.', '.'}
    };
    
    // Coordinates Y, X
    int coordinate_y = 0;
    int coordinate_x = 0;
    int draw_counter = 0;

    display_board(tic_tac_toe_board);

    // Game in progress
    while(1) {
        player_1_turn(&coordinate_x, &coordinate_y, tic_tac_toe_board);
        display_board(tic_tac_toe_board);
        if(!(check_game_over_player_1(&coordinate_x, &coordinate_y, tic_tac_toe_board))) {
            break;
        }
        draw_counter++;
        if (draw_counter == 9 && (check_game_over_player_1 || check_game_over_player_2) == 1) {
            printf("\nDraw!\n");
            break;
        }

        player_2_turn(&coordinate_x, &coordinate_y, tic_tac_toe_board);
        display_board(tic_tac_toe_board);
        if(!(check_game_over_player_2(&coordinate_x, &coordinate_y, tic_tac_toe_board))) {
            break;
        }
        draw_counter++;
        if (draw_counter == 9 && (check_game_over_player_1 || check_game_over_player_2) == 1) {
            printf("\nDraw!\n");
            break;
        }
    }

    return 0;
}

//-----------------------------------------------------

/*
i: Y coordinate
j: X coordinate
*/
void display_board(char pt_tic_tac_toe_board[3][3]) {
    int row_number = 0;
    //printf("  0  1  2 \n");
    for(int i = 0; i < 3; i++) { // Loop for columns
        printf("%d", row_number++);
        for(int j = 0; j < 3; j++) { // Loop for rows
            printf("[%c]", pt_tic_tac_toe_board[i][j]);
        }
        printf("\n");
    }
        printf("  0  1  2 \n");
}

void player_1_turn(int *pt_coordinate_x, int *pt_coordinate_y, char pt_tic_tac_toe_board[3][3]) {
    printf("\n>> Player 1 <<\n");

    int i = 1;
    while(i) {
        printf("Choose the column number of your move: ");
        scanf("%d", pt_coordinate_x);
        printf("Choose the row number of your move: ");
        scanf("%d", pt_coordinate_y);

        // If the cell exists
        if(*pt_coordinate_x < 3 && *pt_coordinate_y < 3) {
            // If the cell is available
            if(pt_tic_tac_toe_board[*pt_coordinate_y][*pt_coordinate_x] == '.') {
                pt_tic_tac_toe_board[*pt_coordinate_y][*pt_coordinate_x] = 'O';
                printf("\n");
                i = 0; // Switch to the next player's turn
            }
            else {
                printf("\nError: this cell is already occupied\n\n");
            }
        }
        else {
            printf("\nError: this cell does not exist\n\n");
        }
    }
}

void player_2_turn(int *pt_coordinate_x, int *pt_coordinate_y, char pt_tic_tac_toe_board[3][3]) {
    printf("\n>> Player 2 <<\n");

    int i = 1;
    while(i) {
        printf("Choose the column number of your move: ");
        scanf("%d", pt_coordinate_x);
        printf("Choose the row number of your move: ");
        scanf("%d", pt_coordinate_y);

        // If the cell exists
        if(*pt_coordinate_x < 3 && *pt_coordinate_y < 3) {
            // If the cell is available
            if(pt_tic_tac_toe_board[*pt_coordinate_y][*pt_coordinate_x] == '.') {
                pt_tic_tac_toe_board[*pt_coordinate_y][*pt_coordinate_x] = 'X';
                printf("\n");
                i = 0; // <-Switch to the next player's turn
            }
            else {
                printf("\nError: this cell is already occupied\n\n");
            }
        }
        else {
            printf("\nError: this cell does not exist\n\n");
        }
    }
}

int check_game_over_player_1(int *pt_coordinate_x, int *pt_coordinate_y, char pt_tic_tac_toe_board[3][3]) {
    if((pt_tic_tac_toe_board[0][0] == 'O') && (pt_tic_tac_toe_board[1][0] == 'O') && (pt_tic_tac_toe_board[2][0] == 'O')) {
        printf("\nPlayer 1 wins!\n");
        return 0;
    }
    else if((pt_tic_tac_toe_board[0][1] == 'O') && (pt_tic_tac_toe_board[1][1] == 'O') && (pt_tic_tac_toe_board[2][1] == 'O')) {
        printf("\nPlayer 1 wins!\n");
        return 0;
    }
    else if((pt_tic_tac_toe_board[0][2] == 'O') && (pt_tic_tac_toe_board[1][2] == 'O') && (pt_tic_tac_toe_board[2][2] == 'O')) {
        printf("\nPlayer 1 wins!\n");
        return 0;
    }
    else if((pt_tic_tac_toe_board[0][0] == 'O') && (pt_tic_tac_toe_board[0][1] == 'O') && (pt_tic_tac_toe_board[0][2] == 'O')) {
        printf("\nPlayer 1 wins!\n");
        return 0;
    }
    else if((pt_tic_tac_toe_board[1][0] == 'O') && (pt_tic_tac_toe_board[1][1] == 'O') && (pt_tic_tac_toe_board[1][2] == 'O')) {
        printf("\nPlayer 1 wins!\n");
        return 0;
    }
    else if((pt_tic_tac_toe_board[2][0] == 'O') && (pt_tic_tac_toe_board[2][1] == 'O') && (pt_tic_tac_toe_board[2][2] == 'O')) {
        printf("\nPlayer 1 wins!\n");
        return 0;
    }
    else if((pt_tic_tac_toe_board[0][0] == 'O') && (pt_tic_tac_toe_board[1][1] == 'O') && (pt_tic_tac_toe_board[2][2] == 'O')) {
        printf("\nPlayer 1 wins!\n");
        return 0;
    }
    else if((pt_tic_tac_toe_board[2][0] == 'O') && (pt_tic_tac_toe_board[1][1] == 'O') && (pt_tic_tac_toe_board[0][2] == 'O')) {
        printf("\nPlayer 1 wins!\n");
        return 0;
    }
    else return 1;
}

int check_game_over_player_2(int *pt_coordinate_x, int *pt_coordinate_y, char pt_tic_tac_toe_board[3][3]) {
    if((pt_tic_tac_toe_board[0][0] == 'X') && (pt_tic_tac_toe_board[1][0] == 'X') && (pt_tic_tac_toe_board[2][0] == 'X')) {
        printf("\nPlayer 2 wins!\n");
        return 0;
    }
    else if((pt_tic_tac_toe_board[0][1] == 'X') && (pt_tic_tac_toe_board[1][1] == 'X') && (pt_tic_tac_toe_board[2][1] == 'X')) {
        printf("\nPlayer 2 wins!\n");
        return 0;
    }
    else if((pt_tic_tac_toe_board[0][2] == 'X') && (pt_tic_tac_toe_board[1][2] == 'X') && (pt_tic_tac_toe_board[2][2] == 'X')) {
        printf("\nPlayer 2 wins!\n");
        return 0;
    }
    else if((pt_tic_tac_toe_board[0][0] == 'X') && (pt_tic_tac_toe_board[0][1] == 'X') && (pt_tic_tac_toe_board[0][2] == 'X')) {
        printf("\nPlayer 2 wins!\n");
        return 0;
    }
    else if((pt_tic_tac_toe_board[1][0] == 'X') && (pt_tic_tac_toe_board[1][1] == 'X') && (pt_tic_tac_toe_board[1][2] == 'X')) {
        printf("\nPlayer 2 wins!\n");
        return 0;
    }
    else if((pt_tic_tac_toe_board[2][0] == 'X') && (pt_tic_tac_toe_board[2][1] == 'X') && (pt_tic_tac_toe_board[2][2] == 'X')) {
        printf("\nPlayer 2 wins!\n");
        return 0;
    }
    else if((pt_tic_tac_toe_board[0][0] == 'X') && (pt_tic_tac_toe_board[1][1] == 'X') && (pt_tic_tac_toe_board[2][2] == 'X')) {
        printf("\nPlayer 2 wins!\n");
        return 0;
    }
    else if((pt_tic_tac_toe_board[2][0] == 'X') && (pt_tic_tac_toe_board[1][1] == 'X') && (pt_tic_tac_toe_board[0][2] == 'X')) {
        printf("\nPlayer 2 wins!\n");
        return 0;
    }
    else return 1;
}
