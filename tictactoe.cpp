#include<iostream>
using namespace std;

int currentPlayer;
char currentMarker;
char board[3][3] ={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void drawBoard() {
    cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"---|---|---\n";
    cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<"---|---|---\n";
    cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
}

bool placemarker(int slot) {
    int row=(slot-1)/3;
    int col=(slot-1)%3;

    if(board[row][col]!='X' && board[row][col]!='O') {
        board[row][col]=currentMarker;
        return true;
    }
    else {
        return false;
    }
}

int winner() {
    // Check rows
    for(int i=0;i<3;i++) {
        if (board[i][0]==board[i][1] && board[i][1]==board[i][2]) {
            return (board[i][0] == 'X') ? 1 : 2;
        }
    }
    // Check columns
    for(int i=0;i<3;i++) {
        if (board[0][i]==board[1][i] && board[1][i]==board[2][i]) {
            return (board[0][i] == 'X') ? 1 : 2;
        }
    }
    // Check diagonals
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2]) {
        return (board[0][0] == 'X') ? 1 : 2;
    }
    if (board[0][2]==board[1][1] && board[1][1]==board[2][0]) {
        return (board[0][2] == 'X') ? 1 : 2;
    }

    return 0; // koi winner nahi
}

void swapPlayerandmarker(char markerP1, char markerP2) {
    if(currentPlayer==1) {
        currentPlayer=2;
        currentMarker=markerP2;
    }
    else {
        currentPlayer=1;
        currentMarker=markerP1;
    }
}

void game() {
    char markerP1, markerP2;
    cout<<"Player1 choose your marker : X or O: ";
    cin>>markerP1;

    if(markerP1=='X' || markerP1=='x')
        markerP2='O';
    else
        markerP2='X';

    currentPlayer=1;
    currentMarker=markerP1;
    drawBoard();
    int playerwon=0;

    for(int i=0;i<9;i++) {
        cout<<"It's Player "<<currentPlayer<<"'s turn. Enter your slot: ";
        int slot;
        cin>>slot;

        if(slot<1 || slot>9) {
            cout<<"Not a valid slot, try again\n";
            i--; 
            continue;
        }
        if(!placemarker(slot)) {
            cout<<"Slot occupied! Try again\n";
            i--;
            continue;
        }
        drawBoard();
        playerwon=winner();

        if(playerwon==1) {
            cout<<"PLAYER 1 WINS!"<<endl;
            return;
        }
        if(playerwon==2) {
            cout<<"PLAYER 2 WINS!"<<endl;
            return;
        }
        swapPlayerandmarker(markerP1, markerP2);
    }
    if(playerwon==0)
        cout<<"IT'S A TIE"<<endl;
}

int main() {
    game();
    return 0;
}
