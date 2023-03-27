
/* ********************** Includes Section Start ********************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ********************** Includes Section End   ********************** */
/* ********************** Macro Section Start ************************* */
#define size 9
#define PLAYER_ONE_ID    1U
#define PLAYER_TWO_ID    2U
#define NUM_OF_PLAYERS   2U

#define WIN              0U
#define DRAW             1U
#define CONTINUE_PLAYING 2U
/* ********************** Macro Section End   ************************* */
typedef unsigned char uint8_t;
/* ********************** Global Data Defintion Start ************************* */

/*global array to store the board elemnts*/
uint8_t g_board[size] = {'1','2','3',
                         '4','5','6',
                         '7','8','9'};
/*global variable to store the game state [WIN or LOSE or CONTINUE_PLAYING]*/
uint8_t g_gameState ;
/*global variable to count number of move for player 1*/
uint8_t g_playerOneMoveCount=0;
/*global variable to count number of move for player 1*/
uint8_t g_playerTwoMoveCount=0;
/*global array to store players configures symbol where g_configArray[0] for PLAYER_ONE_ID and g_configArray[1] for PLAYER_TWO_ID*/
uint8_t g_configArray[NUM_OF_PLAYERS];
/* ********************** Global Data declarations End ************************* */

/* ********************** Functions declarations Start ************************* */

/*function will take a board as an input and prints it on the console*/
void drawBoard(uint8_t *board);
/*function will take the board, position to update and value to set in this position*/
void updateBoard (uint8_t *board, uint8_t position, uint8_t value);
/*This function will take the player's number and asks the player to choose between X and O*/
uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t * symbol);
/*This function will prompt and asks each user about their preferred symbols and saves it in the configArray*/
void setPlayerConfig(uint8_t *configArray);
/*This function will take the player's number then load his config, ask him for the position then updates the board*/
void loadAndUpdate(uint8_t playerNumber);
/*This function will check after each move if there is a win, draw or continue playing*/
void getGameState(uint8_t *board, uint8_t *gameState);
/*helper static function to check for wining*/
static uint8_t sf_is_Win(uint8_t *board);
/*helper static function to check for drawing*/
static uint8_t sf_is_draw(uint8_t a_playerOneCount,uint8_t a_playerTwoCount);
/*helper static function to check if the game over*/
static uint8_t sf_game_over(uint8_t *board);
/*helper static function to make a new board*/
static void sf_New_Game(uint8_t *board);

/* ********************** Functions declarations Section End   ************************* */

/* ********************** Main Program Start   ******************************/
int main()
{
    while(1)
    {
        uint8_t l_flag = 0;
        setPlayerConfig(g_configArray);
        drawBoard(g_board);
        while(!sf_game_over(g_board))
        {
            if(!l_flag)
            {
                printf("Player one ");
                loadAndUpdate(PLAYER_ONE_ID);
                drawBoard(g_board);
                g_playerOneMoveCount++;
                if(g_playerOneMoveCount>=3)
                {
                    getGameState(g_board,&g_gameState);
                    if(WIN==g_gameState)
                    {
                        printf("player One wins !!\n");
                        break;
                    }
                    else
                    {
                        //do nothing
                    }
                }
                l_flag = 1;
            }
            else
            {
                printf("Player two your turn ");
                loadAndUpdate(PLAYER_TWO_ID);
                drawBoard(g_board);
                g_playerTwoMoveCount++;
                if(g_playerTwoMoveCount>=3)
                {
                    getGameState(g_board,&g_gameState);
                    if(WIN==g_gameState)
                    {
                        printf("player Two wins !!\n");
                        break;
                    }
                    else
                    {
                        //do nothing
                    }
                }
                l_flag = 0;
            }
        }
        getGameState(g_board,&g_gameState);
        if(DRAW==g_gameState)
        {
            printf("The two players have drawed !!\n");
        }
        else
        {
            //do nothing
        }
        sf_New_Game(g_board);
    }

    return 0;
}
/* ********************** main program end   ********************************************** */

/* ********************** Functions Definition Start ************************* */
void drawBoard(uint8_t *board)
{
    uint8_t i = 0;
    if(board)
    {
        for(i=0; i<size; i++)
        {
            printf("%c",board[i]);
            if(!((i+1)%3))
            {
                printf("\n");
            }
        }
    }
    else
    {
        // do nothing
    }
}
void updateBoard (uint8_t *board, uint8_t position, uint8_t value)
{
    uint8_t i = 0;
    if(board)
    {
        for(i=0; i<size; i++)
        {
            if(position==board[i])
            {
                board[i] = value;
            }
        }
    }
    else
    {
        // do nothing
    }
}

uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t * symbol)
{
    uint8_t temp = 0;

    fflush(stdin);
    printf("Please enter your symbol (X or O) \n");
    temp = getchar();

    if(('o'==temp) || ('x'==temp) || ('O'==temp) || ('X'==temp))
    {
        if((PLAYER_ONE_ID==playerNumber) && (temp==g_configArray[1]))
        {
            return 1;
        }
        else if((PLAYER_TWO_ID==playerNumber) && (temp==g_configArray[0]))
        {
            return 1;
        }
        else
        {
            *symbol = temp;
        }
    }
    else
    {
        return 1;
    }
    return 0;
}
void setPlayerConfig(uint8_t *configArray)
{
    uint8_t status = 1;
    if(configArray)
    {
        printf("user one ");
        status = getPlayerSymbol(PLAYER_ONE_ID,&configArray[0]);
        if(status)
        {
            while(status)
            {
                printf("invalid Symbol ");
                status = getPlayerSymbol(PLAYER_ONE_ID,&configArray[0]);
            }
        }
        printf("user two ");
        status = getPlayerSymbol(PLAYER_TWO_ID,&configArray[1]);
        if(status)
        {
            while(status)
            {
                printf("invalid Symbol ");
                status = getPlayerSymbol(PLAYER_TWO_ID,&configArray[1]);
            }
        }
    }
    else
    {
        // do nothing
    }
}
void loadAndUpdate(uint8_t playerNumber)
{
    uint8_t l_position = 0;
    uint8_t temp = 0;
    if(PLAYER_ONE_ID==playerNumber)
    {

        fflush(stdin);
        printf("Please enter the position of your symbol\n");
        l_position = getchar();
        /*to get the numeric value */
        temp = (l_position - '0');
        while(('o'==g_board[temp-1]) || ('x'==g_board[temp-1]) ||('O'==g_board[temp-1]) || ('X'==g_board[temp-1])
              || (!(temp >=1) && !(temp<=9)))
        {
            fflush(stdin);
            printf("Invalid position please choose only from the available number from the board \n");
            l_position = getchar();
            temp = (l_position - '0');
        }

        updateBoard(g_board,l_position,g_configArray[0]);
    }
    else if(PLAYER_TWO_ID==playerNumber)
    {
        fflush(stdin);
        printf("Please enter the position of your symbol\n");
        l_position = getchar();
        temp = (l_position - '0');
        while(('o'==g_board[temp-1]) || ('x'==g_board[temp-1]) ||('O'==g_board[temp-1]) || ('X'==g_board[temp-1])
              || (!(l_position >=1) && !(l_position<=9)))
        {
            fflush(stdin);
            printf("Invalid position please choose only from the available number from the board \n");
            l_position = getchar();
            temp = (l_position - '0');
        }
        updateBoard(g_board,l_position,g_configArray[1]);
    }
    else
    {
        // do nothing
    }
}
void getGameState(uint8_t *board, uint8_t *gameState)
{
    uint8_t i = 0;
    if(board && gameState)
    {
        if(sf_is_Win(board))
        {
            *gameState = WIN;
        }
        else if(sf_is_draw(g_playerOneMoveCount,g_playerTwoMoveCount))
        {
            *gameState = DRAW;
        }
        else
        {
            *gameState = CONTINUE_PLAYING;
        }
    }
    else
    {
        // do nothing
    }
}
static uint8_t sf_is_Win(uint8_t *board)
{
    uint8_t l_is_Win = 0;
    /*check row one*/
    if((board[0]==board[1]) && (board[0]==board[2]))
    {
        l_is_Win=1;
    }
    /*check row two*/
    else if((board[3]==board[4]) && (board[3]==board[5]))
    {
        l_is_Win=1;
    }
    /*check row three*/
    else if((board[6]==board[7]) && (board[6]==board[8]))
    {
        l_is_Win=1;
    }
    /*check column one*/
    else if((board[0]==board[3]) && (board[0]==board[6]))
    {
        l_is_Win=1;
    }
    /*check column two*/
    else if((board[1]==board[4]) && (board[1]==board[7]))
    {
        l_is_Win=1;
    }
    /*check column three*/
    else if((board[2]==board[5]) && (board[2]==board[8]))
    {
        l_is_Win=1;
    }
    /*check Diagonal left*/
    else if((board[0]==board[4]) && (board[0]==board[8]))
    {
        l_is_Win=1;
    }
    /*check Diagonal right*/
    else if((board[2]==board[4]) && (board[2]==board[6]))
    {
        l_is_Win=1;
    }
    else
    {
        // do nothing
    }
    return l_is_Win;
}
static uint8_t sf_is_draw(uint8_t a_playerOneCount,uint8_t a_playerTwoCount)
{
    uint8_t l_is_Draw = 0;
    if((a_playerOneCount>4) && (a_playerTwoCount>3))
    {
        l_is_Draw = 1;
    }
    else
    {
        // do nothing
    }
    return l_is_Draw;
}
static uint8_t sf_game_over(uint8_t *board)
{
    uint8_t i = 0;
    uint8_t l_cnt = 0;
    uint8_t l_game_over = 0;
    if(board)
    {
        for(i=0; i<size; i++)
        {
            if(('o'==board[i]) || ('x'==board[i]) || ('O'==board[i]) || ('X'==board[i]))
            {
                l_cnt++;
            }
        }
        l_game_over = (l_cnt==9)? 1 : 0;
    }
    else
    {
        // do nothing
    }
    return l_game_over;
}
static void sf_New_Game(uint8_t *board)
{
    uint8_t i = 0;
    if(board)
    {
        for(i=0; i<size; i++)
        {
            board[i] ='1'+ i;
        }

    }
    else
    {
        // do nothing
    }
}
/* ********************** Functions Definition End ************************* */
