//main programm for TicTacToe
/*Goal: Practice creating classes and functions. 
**Create a program that allows two users to 
**play a 4x4 tic-tac-toe game. 
*/
#include "TicTacToe.hpp"
#include "TicTacToe_function.cpp"

int main()
{
    Board gameBoard;
    string nameX;
    string nameO;

    int tieGame=0;
    char gameWinner='z';
    int numTurns=0;

    //get the names of the players
    getUserNames(nameX, nameO);

    //the game is played for 8 turns maximum
    while(numTurns<8)
    {
        //Player 'x'
        printTheBoard(gameBoard); //print a board that has the positions numbered
        printUserPrompt(nameX, 'x'); //ask player x where they want to put an 'x'
        checkResponse(gameBoard, 'x'); //check that the input is a valid position and that it has not already been taken
        gameWinner=gameBoard.determineWinner();//check to see if player 'x' has four in a row somewhere on the board

        //if player 'x' has won, end the game
        if(gameWinner !='z')
        {
            printTheBoard(gameBoard);
            writeTheBoard(gameBoard);
            printGameWinner(gameBoard, nameX, nameO);
            break;
        }

        //Now do the same for the player 'o'

        //Player 'o'
        printTheBoard(gameBoard);
        writeTheBoard(gameBoard);
        printUserPrompt(nameO, 'o');
        checkResponse(gameBoard, 'o');

        printTheBoard(gameBoard);
        writeTheBoard(gameBoard);
        gameWinner=gameBoard.determineWinner();

        if(gameWinner !='z')
        {
            printTheBoard(gameBoard);
            writeTheBoard(gameBoard);
            printGameWinner(gameBoard, nameX, nameO);
            break;
        }
        numTurns++;
    }
    //if there is no winner at this point, tha game is a tie
    if(numTurns>=8)
        cout<<"Tie game.\n\n";
    return 0;
}