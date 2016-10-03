
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// константы
#define BOARD_SIZE_MIN 3
#define BOARD_SIZE_MAX 9

int board[BOARD_SIZE_MAX][BOARD_SIZE_MAX];
int board_size;
FILE* file;
int emptyX, emptyY;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void _log(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    board_size = atoi(argv[1]);
    if (board_size < BOARD_SIZE_MIN || board_size > BOARD_SIZE_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            BOARD_SIZE_MIN, BOARD_SIZE_MIN, BOARD_SIZE_MAX, BOARD_SIZE_MAX);
        return 2;
    }

    // open log
    file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();
    
    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        _log();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            //usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

void _log(void) {
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            fprintf(file, "%i", board[i][j]);
            if (j < board_size - 1)
            {
                fprintf(file, "|");
            }
        }
        fprintf(file, "\n");
    }
    fflush(file);
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int value = board_size * board_size - 1;
    emptyX = emptyY = board_size - 1;
    
    for (int y = 0; y < board_size; ++y) {
        for (int x = 0; x < board_size; ++x) {
            board[y][x] = value--;
        }
    }
    
    if (board_size % 2 == 0) {
        int temp = board[board_size - 1][board_size - 2];                    
        board[board_size - 1][board_size - 2] = board[board_size - 1][board_size - 3];      
        board[board_size - 1][board_size - 3] = temp;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int y = 0; y < board_size; ++y) {
        for (int x = 0; x < board_size; ++x) {
            int tile = board[y][x];
            
            if (!tile) {
                printf(" _ ");
            } else if (tile < 10) {
                printf(" %i ", tile);
            } else {
                printf("%i ", tile);
            }
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    for (int y = 0; y < board_size; ++y) {
        for (int x = 0; x < board_size; ++x) {
            if (
                board[y][x] == tile &&
                (abs(emptyY - y) == 1 && emptyX == x) ^ (abs(emptyX - x) == 1 && emptyY == y)
            ) {
                board[emptyY][emptyX] = tile;
                board[y][x] = 0;
                emptyY = y;
                emptyX = x;
                return true;
            }
        }
    }
    
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    if (board[board_size - 1][board_size - 1] == 0) {
        for (int y = 0, c = 1; y < board_size; ++y) {
            for (int x = 0; x < ((y == board_size - 1) ? board_size - 1 : board_size); ++x) {
                if (board[y][x] != c++) {
                    return false;
                }
                if (c == board_size * board_size - 1) {
                    return true;
                }
            }
        }
    }
    return false;
}