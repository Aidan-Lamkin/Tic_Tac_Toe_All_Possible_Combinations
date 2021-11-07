#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

bool win(string board){
    string new_board = board;
    if((new_board[0] == new_board[1]  && new_board[1] == new_board[2] ) && new_board[0] != ' '){
        return true;
    }
    else if((new_board[3] == new_board[4]  && new_board[4] == new_board[5] ) && new_board[3] != ' '){
        return true;
    }
    else if((new_board[6] == new_board[7]  && new_board[7] == new_board[8] ) && new_board[6] != ' '){
        return true;
    }
    else if((new_board[0] == new_board[3]  && new_board[3] == new_board[6] ) && new_board[0] != ' '){
        return true;
    }
    else if((new_board[1] == new_board[4]  && new_board[4] == new_board[7] ) && new_board[1] != ' '){
        return true;
    }
    else if((new_board[2] == new_board[5]  && new_board[5] == new_board[8] ) && new_board[2] != ' '){
        return true;
    }
    else if((new_board[0] == new_board[4]  && new_board[4] == new_board[8] ) && new_board[0] != ' '){
        return true;
    }
    else if((new_board[2] == new_board[4]  && new_board[4] == new_board[6] ) && new_board[2] != ' '){
        return true;
    }
    else {
        return false;
    }
}

bool is_valid(string board){
    if ((count(board.begin(), board.end(), 'X') - count(board.begin(), board.end(), 'O')) != 1 &&
        (count(board.begin(), board.end(), 'X') - count(board.begin(), board.end(), 'O')) != 0) {
        return false;
    }
    else if(count(board.begin(), board.end(), 'O') > count(board.begin(), board.end(), 'X')){
        return false;
    }
    return true;
}

set<string> fill_boards(set<string>& boards,string board){
    if (win(board) == true) {
        return boards;
    }
    int count = 0;
    for(int i = 0; i < board.size(); i++){
        if(board[i] == ' '){
            count++;
        }
    }
    if(count == 9 || count == 7 || count == 5 || count == 3) {
        for (int i = 0; i < board.size(); i++) {
            if(board[i] == ' ') {
                string new_board = board.substr(0, i) + 'X' + board.substr(i + 1, 8 - i);
                if(boards.count(new_board) == 0) {
                    if (is_valid(new_board)) {
                        boards.insert(new_board);
                        fill_boards(boards, new_board);
                    } else {
                        return boards;
                    }
                }
            }
        }
    }
    if(count == 8 || count == 6 || count == 4 || count == 2) {
        for (int i = 0; i < board.size(); i++) {
            if(board[i] == ' ') {
                string new_board = board.substr(0, i) + 'O' + board.substr(i + 1, 8 - i);
                if(boards.count(new_board) == 0) {
                    if (is_valid(new_board)) {
                        boards.insert(new_board);
                        fill_boards(boards, new_board);
                    } else {
                        return boards;
                    }
                }
            }
        }
    }
    else if(count == 1){
        int i = board.find(' ');
        string new_board = board.substr(0, i) + 'X' + board.substr(i + 1, 8 - i);
        if(boards.count(new_board) == 0) {
            boards.insert(new_board);
        }
    }
    return boards;
}
int count_X_wins(set<string> boards){
    int count = 0;
    for(auto new_board: boards) {
        if ((new_board[0] == new_board[1] && new_board[1] == new_board[2]) && new_board[0] == 'X') {
            count++;
        }
        else if ((new_board[3] == new_board[4] && new_board[4] == new_board[5]) && new_board[3] == 'X') {
            count++;
        }
        else if ((new_board[6] == new_board[7] && new_board[7] == new_board[8]) && new_board[6] == 'X') {
            count++;
        }
        else if ((new_board[0] == new_board[3] && new_board[3] == new_board[6]) && new_board[0] == 'X') {
            count++;
        }
        else if ((new_board[1] == new_board[4] && new_board[4] == new_board[7]) && new_board[1] == 'X') {
            count++;
        }
        else if ((new_board[2] == new_board[5] && new_board[5] == new_board[8]) && new_board[2] == 'X') {
            count++;
        }
        else if ((new_board[0] == new_board[4] && new_board[4] == new_board[8]) && new_board[0] == 'X') {
            count++;
        }
        else if ((new_board[2] == new_board[4] && new_board[4] == new_board[6]) && new_board[2] == 'X') {
            count++;
        }
    }
    return count;
}
int count_O_wins(set<string> boards) {
    int count = 0;
    for (auto new_board: boards) {
        if ((new_board[0] == new_board[1] && new_board[1] == new_board[2]) && new_board[0] == 'O') {
            count++;
        }
        else if ((new_board[3] == new_board[4] && new_board[4] == new_board[5]) && new_board[3] == 'O') {
            count++;
        }
        else if ((new_board[6] == new_board[7] && new_board[7] == new_board[8]) && new_board[6] == 'O') {
            count++;
        }
        else if ((new_board[0] == new_board[3] && new_board[3] == new_board[6]) && new_board[0] == 'O') {
            count++;
        }
        else if ((new_board[1] == new_board[4] && new_board[4] == new_board[7]) && new_board[1] == 'O') {
            count++;
        }
        else if ((new_board[2] == new_board[5] && new_board[5] == new_board[8]) && new_board[2] == 'O') {
            count++;
        }
        else if ((new_board[0] == new_board[4] && new_board[4] == new_board[8]) && new_board[0] == 'O') {
            count++;
        }
        else if ((new_board[2] == new_board[4] && new_board[4] == new_board[6]) && new_board[2] == 'O') {
            count++;
        }
    }
    return count;
}
int count_ties(set<string> boards){
    int count = 0;
    for(auto board: boards){
        if(board.find(' ') == string::npos && !win(board)){
            count++;
        }
    }
    return count;
}
int main() {
    set<string>boards;
    boards.insert("         ");
    fill_boards(boards, "         ");
    cout << "total boards: " << boards.size() << ", wins for 'O': " << count_O_wins(boards) << ", wins for 'X': "
    << count_X_wins(boards) << ", ties: " << count_ties(boards) << endl;
    for(auto board: boards){
        cout << board << endl;
    }
    return 0;
}
