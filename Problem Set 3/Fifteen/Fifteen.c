/*

Program: Implements Game of Fifteen (generalized to d x d).

Usage: fifteen d

Note: Whereby the board's dimensions are to be d x d,
      where d must be in [DIM_MIN,DIM_MAX].

*/


#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constants
#define DIM_MIN 3
#define DIM_MAX 9

// Board
int board[DIM_MAX][DIM_MAX];

// Dimensions
int d;

// Blank Character Position
int blankRow;
int blankColumn;

// Prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

// Helper
void swap(int *elementA, int *elementB);

// Main
int main(int argc, string argv[]) {

    // ensure proper usage
    if (argc != 2) {

        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX) {

        printf("Board must be between %i x %i and %i x %i, inclusive.\n", DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL) {

        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true) {

        // clear the screen
        clear();

        // draw the current state of the board
        draw();

// Logging - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < d; j++) {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1) {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        // check for win
        if (won()) {

            printf("You win !\n\n");
            break;
        }

        // prompt for move
        printf("\nTile to move: ");
        int tile = get_int();

        // quit if user inputs 0 (for testing)
        if (tile == 0) {

            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile)) {

            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}



// Clears screen using ANSI escape sequences.
void clear(void) {

    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}



// Greets player.
void greet(void) {

    clear();
    printf("\nWELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
    printf("\nEnter '0' in case you want to stop the game.\n");
    usleep(4000000);
}



/* Initializes the game's board with tiles numbered 1 through d*d - 1
   (i.e., fills 2D array with values but does not actually print them). */
void init(void) {

    int num = (d*d)-1,
        row,
        column;

    // Iterate through positions of the board
    for (row = 0; row < d; row++)
        for (column = 0; column < d; column++) {

                board[row][column] = num;
                num--;
            }

    // If the dimensions are even --> Overwrite   2 | 1 | 0   to   1 | 2 | 0
    if (d%2 == 0) {

        board[d-1][d-3] = 1;
        board[d-1][d-2] = 2;
    }

    // Remember the blank tile position
    blankRow = d-1;
    blankColumn = d-1;

    return;
}



// Prints the board in its current state.
void draw(void) {

    int row, column;

    // For Aesthetics
    printf("\n"); for (int count = 0; count < d; count++) printf("----"); printf("-\n");

    for (row = 0; row < d; row++) {

        // For Aesthetics
        printf("|");

        for (column = 0; column < d; column++) {

            // Puts the blank character OR the value currently found at that position
            (board[row][column] == 0) ? printf(" _") : printf("%2i", board[row][column]);

            // For Aesthetics
            if (column < d-1) printf(" |");
        }

        // For Aesthetics
        printf(" |"); printf("\n"); for (int count = 0; count < d; count++) printf("----"); printf("-\n");
    }

    return;
}



// If tile borders empty space, moves tile and returns true, else returns false.
bool move(int tile) {

        // Go through each element of the array individually
        for (int row = 0; row < d; row++)
            for (int column = 0; column < d; column++) {

                // Check if Element Matches Tile
                if (board[row][column] == tile)

                    // If tile is Adjacent to 'blankTile'
                    if (((column == blankColumn) && (row == blankRow+1 || row == blankRow-1))
                    || ((row == blankRow) && (column == blankColumn+1 || column == blankColumn-1))) {

                        // Swap Tile & BlankTile Positions --> Return True Signaling a Legal Move Was Preformed
                        swap(&board[row][column], &board[blankRow][blankColumn]),
                        blankRow = row;
                        blankColumn = column;
                        return true;
                    }
            }

    return false;
}



// Returns true if game is won (i.e., board is in winning configuration), else false.
bool won(void) {

    int num = 1,
        row,
        column;

        // Iterate through board
        for (row = 0; row < d; row++)
            for (column = 0; column < d && num < (d*d); column++) {

                // Check if tiles are in correct order
                if (board[row][column] != num) return false;
                num++;
            }

    return true;
}



// Swap function to facilitate life.
void swap(int *elementA, int *elementB) { int temporary = *elementA; *elementA = *elementB; *elementB = temporary; return; }
