#include <iostream>
#include <iomanip>

using namespace std;

string board[9] = {"[1]","[2]","[3]","[4]","[5]","[6]","[7]","[8]","[9]"};

// checking if the entered choice by the player is filled or not 
bool check_board(int choice) {
    if (board[choice - 1] == "X" || board[choice - 1] == "O")
        return true;
    return false;
}

// checking which player has won the game 
int isgameOver () {
    if (board[0] == board[1] && board[1]==board[2]) {
        if (board[0] == "X") 
            return 1;
        return 2;
    }
    else if (board[3] == board[4] && board[4]==board[5]) {
        if (board[3] == "X") 
            return 1;
        return 2;
    }
    else if (board[6] == board[7] && board[7]==board[8]) {
        if (board[6] == "X") 
            return 1;
        return 2;
    }
    else if (board[0] == board[3] && board[3]==board[6]) {
        if (board[0] == "X") 
            return 1;
        return 2;
    }
    else if (board[1] == board[4] && board[4]==board[7]) {
        if (board[1] == "X") 
            return 1;
        return 2;
    }
    else if (board[2] == board[5] && board[5]==board[8]) {
        if (board[2] == "X") 
            return 1;
        return 2;
    }
    else if (board[0] == board[4] && board[4]==board[8]) {
        if (board[0] == "X") 
            return 1;
        return 2;
    }
    else if (board[2] == board[4] && board[4]==board[6]) {
        if (board[2] == "X") 
            return 1;
        return 2;
    }
    else
        return 0;
}


// displaying the tic-tac-toe board
void display_board() {
    cout << endl;
    for (int i=0;i<9;i++) {
        cout << setw(2) << board[i] << "\t";
        if (i == 2 || i == 5 || i == 8)
            cout << endl;
    }
}

// assigning values to players
void game(int player,int choice) {
    if (player == 1)
        board[choice - 1] = "X";
    else
        board[choice - 1] = "O";
}

// main function
int main() {
    system("cls");
    string player1, player2;
    cout << "\n---------------------------";
    cout << "\n\tTic-Tac-Toe";
    cout << "\n---------------------------\n";
    cout << "\nNames of Player 1 (X): "; cin >> player1;
    cout << "\nNames of Player 2 (O): "; cin >> player2;
    cout << endl;
    int choice, result=0, flag=0, trigger=0;

    display_board();
    
    // loop until a winner is declared or tie occurs
    for (int i=1;i<5;i++) {
        trigger = 0;
        while (trigger == 0) {
            cout << player1 << " enter your choice : "; cin >> choice;
            if (check_board(choice)) {
                cout << "Invalid Entry please try again !!\n";
                trigger = 0;
            }
            else   
                trigger = 1;       
        }
        game(1,choice);
        display_board();

        result=isgameOver();
        if (result == 1) {
            cout << "\n----------------------------";
            cout << "\n\t" << player1 << " Wins!!";
            cout << "\n----------------------------";
            flag=1;
            break;
        }
        else if (result == 2) {
            cout << "\n----------------------------";
            cout << "\n\t" << player2 << " Wins!!";
            cout << "\n----------------------------";
            flag=1;
            break;
        } 
        
        trigger = 0;
        while (trigger == 0) {
            cout << player2 << " enter your choice : "; cin >> choice;
            if (check_board(choice)) {
                cout << "Invalid Entry please try again !!\n";
                trigger = 0;
            }
            else   
                trigger = 1;       
        }
        game(2,choice);
        display_board();

        result=isgameOver();
        if (result == 1) {
            cout << "\n----------------------------";
            cout << "\n\t" << player1 << " Wins!!";
            cout << "\n----------------------------";
            flag=1;
            break;
        }
        else if (result == 2) {
            cout << "\n----------------------------";
            cout << "\n\t" << player2 << " Wins!!";
            cout << "\n----------------------------";
            flag=1;
            break;
        } 
    }
    if (flag == 0){
        cout << "\n-------------------------";
        cout << "\n\tGame Draw !!";
        cout << "\n-------------------------";
    }
    return 0;
}

// END OF PROGRAM