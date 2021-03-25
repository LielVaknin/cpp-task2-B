#include "Board.hpp"
#include <string>
#include <iostream>

using namespace std;
using namespace ariel;

void Board::post(unsigned int row, unsigned int col, Direction direction, const string &message) {
    if (!message.empty()) {
        if (col < minCol) {
            minCol = col;
        }
        if (row < minRow) {
            minRow = row;
        }
    }
    switch (direction) {
        case Direction::Vertical:
            for (char ch : message) {
                messageBoard[row][col] = ch;
                row++;
            }
            row -= 1; // Fix row
            break;
        case Direction::Horizontal:
            for (char ch : message) {
                messageBoard[row][col] = ch;
                col++;
            }
            col -= 1; // Fix col
            break;
    }
    if (!message.empty()) {
        if (col > maxCol) {
            maxCol = col;
        }
        if (row > maxRow) {
            maxRow = row;
        }
    }
}

string Board::read(unsigned int row, unsigned int col, Direction direction, unsigned int length) {
    string message;
    switch (direction) {
        case Direction::Vertical:
            for (int i = 0; i < length; i++) {
                if (messageBoard.count(row) != 0 && messageBoard[row].count(col) != 0) {
                    message += messageBoard[row][col];
                    row++;
                } else {
                    message += "_";
                    row++;
                }
            }
            break;
        case Direction::Horizontal:
            for (int i = 0; i < length; i++) {
                if (messageBoard.count(row) != 0 && messageBoard[row].count(col) != 0) {
                    message += messageBoard[row][col];
                    col++;
                } else {
                    message += "_";
                    col++;
                }
            }
            break;
    }
    return message;
}

void Board::show() {
    map<unsigned int, map<unsigned int, char> >::iterator row;
    map<unsigned int, char>::iterator col;
    if (minRow == 0 && minCol == 0) {
        for (unsigned int i = minRow; i <= maxRow + extraFiveChars; i++) {
            for (unsigned int j = minCol; j <= maxCol + extraTenChars; j++) {
                if (messageBoard.count(i) == 0 || messageBoard[i].count(j) == 0) {
                    messageBoard[i][j] = '_';
                }
            }
        }
    } else if (maxRow == UINT_MAX || maxCol == UINT_MAX) {
        for (unsigned int i = minRow; i < maxRow; i++) {
            for (unsigned int j = minCol; j < maxCol; j++) {
                if (messageBoard.count(i) == 0 || messageBoard[i].count(j) == 0) {
                    messageBoard[i][j] = '_';
                }
            }
        }
    } else {
        for (unsigned int i = minRow - 1; i <= maxRow + 1; i++) {
            for (unsigned int j = minCol - extraTenChars; j <= maxCol + extraTenChars; j++) {
                if (messageBoard.count(i) == 0 || messageBoard[i].count(j) == 0) {
                    messageBoard[i][j] = '_';
                }
            }
        }
    }
    cout << "Welcome to our neighborhood message board!" << endl << "  ------- Put your message here! -------  "
         << endl;
    string maxRowString = to_string(maxRow);
    size_t sizeOfMaxRow = maxRowString.size();
    for (row = messageBoard.begin(); row != messageBoard.end(); row++) {
        string currRowString = to_string(row->first);
        size_t sizeOfCurrRow = currRowString.size();
        cout << row->first << ": ";
        size_t spacesToAdd = sizeOfMaxRow - sizeOfCurrRow;
        for (size_t i = 0; i < spacesToAdd; i++) {
            cout << " ";
        }
        for (col = row->second.begin(); col != row->second.end(); col++) {
            cout << col->second;
        }
        cout << endl;
    }
}


