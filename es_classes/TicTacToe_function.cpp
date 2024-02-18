//Function file .cpp
#include <fstream>

void getUserNames(string &, string &);
void printBlankBoard(string);
void printTheBoard(Board, string);
void printUserPrompt(string, char);
void printGameWinner(Board, string, string);
int getUserResponse();
void checkResponse(Board&, char);
void writeTheBoard(Board);

using namespace std;

void checkResponse(Board &boardIn, char input)
{
    int position;
    int userInput;
    do
    {
        position=getUserResponse();
        userInput=boardIn.setPosition(position, input);
        if(userInput==-1)
        {
            cout<<"That position is taken.";
        }
    }while(userInput==-1);
}

void getUserNames(string &userX, string &userY)
{
    std::cout<<"Name of user to be 'x': ";
    std::cin>>userX;
    std::cout<<"Name of user to be 'o': ";
    std::cin>>userY;
}

void printBlankBoard()
{//print a black board, with numbered squares
    for(int i=0; i<16; i++)
    {
        std::cout<<"|"<<i<<":";
        if(i<=9)
            cout<<" ";
        if(i%4==3)
            std::cout<<"|\n";
    }
    cout<<"\n\n\n";
}

void printTheBoard(Board boardIn)
{//print the board with player moves
    printBlankBoard();

    for(int i=0; i<16; i++)
    {
        std::cout<<"|"<<boardIn.getPositions()[i];
        if(i%4==3)
            std::cout<<"\n";
    }
    cout<<"\n\n\n";
}

void writeTheBoard(Board boardIn)
{
    cout<<"\n\n";
    for(int i=0; i<16; i++)
    {
        cout<<"|"<<boardIn.getPositions()[i];
        if(i%4==3)
            cout<<"\n";
    }
    cout<<"|\n";
}

void printUserPrompt(string nameIn, char letter)
{
    cout<<nameIn<<" where would you like to place an "<<letter<<"?: ";
    cout<<"\n\n";
    cout<<" where would you like to place an "<<letter<<"?: ";
}

void printGameWinner(Board boardIn, string nameX, string nameO)
{
    char winner;
    winner=boardIn.determineWinner();
    if(winner=='x')
        cout<<"Congrats "<<nameX<<" you won!\n\n";
    if(winner=='o')
        cout<<"Congrats "<<nameO<<" you won!\n\n";
}

int getUserResponse()
{//get the chosen user position, check that it is an integer
 //check that it is between 0 and 15 inclusive
    int position = -1;
    cout<<"Enter an integer between 0 and 15: ";
    cin>>position;

    while(position>15 || position<0 || !cin) //!cin: or if there's an error in the input stream
    {
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(), '\n'); ???
        /*
            It is used to clear the input buffer in case there is any invalid input. 
            This line is typically used to discard the remaining characters in the input buffer up to the next newline character. 
            It can be useful to prevent an infinite loop if there is non-numeric input, as it discards the invalid characters.
            However, whether or not you should use cin.ignore depends on your specific use case. 
            If you find that the loop is not working as expected and you're getting stuck in an infinite loop, uncommenting and using cin.ignore may help.
            Keep in mind that uncommenting this line may cause the program to ignore the invalid input and continue.
            So make sure it aligns with your desired behavior.
       */

        cout<<"That is not a valid position\n";
        cout<<"Enter an integer between 0 and 15: ";
        cin.clear();
        cin>>position; 
    }
    return position;
}