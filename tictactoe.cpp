#include<iostream>
#include<string>

using namespace std;
/*
void getPlayerName(string &userX, string &userO);
int getRowColumn(Tictactoe &tic, string UserName, char userInput, int &row, int &column);
int checkValidEntry(Tictactoe &tic, int row, int column);
char checkWinner(Tictactoe &tic, char value);
int declareWinner(string userX, string userO, char checkWinnerSymbol);
*/

class Tictactoe{
    
    char gameBoard[4][4];
    
public:
    Tictactoe();
    void setGameBoard(int row, int column, char value);
    char getGameBoard(int row, int column);
    int fourInRow(char value);
    int fourInColumn(char value);
    int fourInDiagonal1(char value);
    int fourInDiagonal2(char value);
    //int checkWinner();
    void printBoard();
    void resetGameBoard();
};


Tictactoe::Tictactoe(){
    for (int r = 0 ; r < 4 ; r++){
        for (int c = 0 ; c < 4 ; c++){
            gameBoard[r][c] = '-';
        }
    }
}

void Tictactoe::resetGameBoard(){
    for (int r = 0 ; r < 4 ; r++){
        for (int c = 0 ; c < 4 ; c++){
            gameBoard[r][c] = '-';
        }
    }
}

void Tictactoe::setGameBoard(int row, int column, char value){
    gameBoard[row][column] = value;
}
char Tictactoe::getGameBoard(int row, int column){
    return gameBoard[row][column];
}


int Tictactoe::fourInRow(char value){
    for (int r = 0 ; r < 4 ; r++){
        int count = 0;
        for (int c = 0 ; c < 4 ; c++){
            if (gameBoard[r][c] == value) count = count+1;
        }
        if(count == 4) return 1;
    }
    return 0;
}


int Tictactoe::fourInColumn(char value){
    for (int r = 0 ; r < 4 ; r++){
        int count = 0;
        for (int c = 0 ; c < 4 ; c++){
            if (gameBoard[c][r] == value) count = count+1;
        }
        if(count == 4) return 1;
    }
    return 0;
}


int Tictactoe::fourInDiagonal1(char value){
    int count = 0;
    for(int i = 0 ; i < 4 ; i++){
        if(gameBoard[i][i] == value) count = count + 1;
    }
    if(count == 4) return 1;
    else return 0;
}


int Tictactoe::fourInDiagonal2(char value){
    int count = 0;
    for(int r = 0 ; r < 4 ; r++){
        for(int c = 0 ; c < 4 ; c++){
            if (r + c == 3){
                if(gameBoard[r][c] == value) count = count + 1;
            }
        }
    }
    if(count == 4) return 1;
    else return 0;
}

void Tictactoe::printBoard(){
    //cout<<std::setw(5);
    cout<<"\n";
    for(int i=0;i<4; i++)
    {
        for(int j=0;j<4; j++)
        {
            cout << "|" << gameBoard[i][j] << "|";
        }
        cout << "\n";
    }
    cout << "\n";
}

//---------------------------------------------

void getPlayerName(string &userX, string &userO);
int getRowColumn(Tictactoe &tic, string UserName, char userInput, int &row, int &column);
int checkValidEntry(Tictactoe &tic, int row, int column);
char checkWinner(Tictactoe &tic, char value);
int declareWinner(string userX, string userO, char checkWinnerSymbol);


int declareWinner(string userX, string userO, char checkWinnerSymbol){
    if(checkWinnerSymbol == 'x'){
        cout << "Congratulations " << userX << "! You have won" << endl;
        return 1;
    }
    
    else if(checkWinnerSymbol == 'o'){
        cout << "Congratulations " << userO << "! You have won" << endl;
        return 1;
    }
    
    else {
        cout << "Continue Playing"<<endl;
        return 0;
    }
}

char checkWinner(Tictactoe &tic, char value){
    switch(value)
    {
        case 'x':
        if(tic.fourInRow(value) == 1) return 'x';
        else if(tic.fourInColumn(value) == 1) return 'x'; 
        else if(tic.fourInDiagonal1(value) == 1) return 'x';
        else if(tic.fourInDiagonal2(value) == 1) return 'x';
        else return 'z';
        
        case 'o':
        if(tic.fourInRow(value) == 1) return 'o';
        else if(tic.fourInColumn(value) == 1) return 'o'; 
        else if(tic.fourInDiagonal1(value) == 1) return 'o';
        else if(tic.fourInDiagonal2(value) == 1) return 'o';
        else return 'z';
        
        default:
        return 'z';
    }
}

int checkValidEntry(Tictactoe &tic, int row, int column){
    if(row >=0 && row <4 && column >=0 && column <4){
        char boardValue = tic.getGameBoard(row, column);
        
        
        if (boardValue == 'x' || boardValue == 'o')
        {   cout << "Invalid character" << endl;
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        cout << "Invalid row and column index" << endl;
        return 0;
    } 
    
}

void getPlayerName(string &userX, string &userO)
{
    cout << "Player name for 'x' : "<< endl;
    cin >> userX;
    cin.clear();
    cout << "Player name for 'o' : " << endl;
    cin >> userO;
}

int getRowColumn(Tictactoe &tic, string userName, char userInput, int &row, int &column)
{
    
    int check;
    switch(userInput)
    {
        
        case 'x':
        do
        {
            cout << userName <<  " Please input row and column between 0-3 for placing 'x'"<<endl;
            cin >> row;
            cin >> column;
            
            check = checkValidEntry(tic, row, column);
            //cout << check << endl;
        }
        while(check == 0);

        tic.setGameBoard(row, column, userInput);
        break;
        
        case 'o':
        do
        {
            cout << userName <<  " Please input row and column between 0-3 for placing 'o'"<<endl;
            cin >> row;
            cin >> column;
            
            check = checkValidEntry(tic, row, column);
            // cout << check << endl;
        }
        while(check == 0);

        tic.setGameBoard(row, column, userInput);
        break;
        
        default:
        break;
    }
    return 0;
}


//----------------------------------

int main(){
    Tictactoe tic;
    string userX, userO;
    char checkWinnerSymbol;
/*    
    getPlayerName(userX, userO); //Take inputs for Player Name
    
    cout << userX << " will play 'x'" << endl;
    cout << userO << " will play 'o'"  << endl;
    
    
    tic.printBoard();
*/
    
    int row =0 ;
    int column = 0;
    int count = 0;
    int winStatus=0;
    //do
    do{
    getPlayerName(userX, userO); //Take inputs for Player Name
    cout << userX << " will play 'x'" << endl;
    cout << userO << " will play 'o'"  << endl;
    tic.printBoard();
    count = 0;
    do {
    getRowColumn(tic, userX, 'x', row, column); //Function to take input from userX
                                                // and updating the gameBoard with rows and columns
                                                // input by userO
                                                
    checkWinnerSymbol = checkWinner(tic,'x');
    //cout << checkWinnerSymbol<<endl;
    tic.printBoard();
    winStatus = declareWinner(userX, userO, checkWinnerSymbol);
    if(winStatus == 1) break;
    
    
    getRowColumn(tic, userO, 'o', row, column); //Function to take input from userO
                                                // and updating the gameBoard with rows and columns
                                                // input by userO
                                                
    checkWinnerSymbol = checkWinner(tic,'o');
    // cout << checkWinnerSymbol<<endl;
    tic.printBoard();
    winStatus = declareWinner(userX, userO, checkWinnerSymbol);
    if(winStatus == 1) break;
    
    
    // cout << !(checkWinnerSymbol == 'x' || checkWinnerSymbol == 'o')<<endl;
    count = count + 1;
    
    } 
    while(count <= 7);
    
    if (count == 8){
        cout << "No one won! Play Again" << endl;
        tic.resetGameBoard();
    }
    
    if(winStatus == 1) break;
    }
    while(true);
    cout << "Game Complete!" << endl;
    
    return 0;
    
}