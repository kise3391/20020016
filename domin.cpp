#include <bits/stdc++.h>

using namespace std;

const int R[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int C[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int update(int& moves, int x, int y, bool isMine[], const int& rows, const int& columns, string currentBoard[]) {

    if (isMine[x * columns + y]) return 0;
    if (currentBoard[x][y] != '+') return 2;

    --moves;
    int mineCount = 0;
    for (int i = 0; i < 8; ++i)  {

        int newX = x + R[i];
        int newY = y + C[i];
        if (newX == -1 || newX == rows || newY == -1 || newY == columns) continue;
        mineCount += isMine[newX * columns + newY];

    }
    currentBoard[x][y] = mineCount ? ((char) '0' + mineCount) : ' ';

    if (mineCount) return 1;
    for (int i = 0; i < 8; ++i) {

        int newX = x + R[i];
        int newY = y + C[i];
        if (newX == -1 || newX == rows || newY == -1 || newY == columns) continue;
        update(moves, x + R[i], y + C[i], isMine, rows, columns, currentBoard);

    }

    return 1;
}

void show(string currentBoard[], bool board[], int r, int c) {
    for (int i = 0; i < r * c; ++i)
        if (board[i]) currentBoard[i] = '*';
}

void print(string currentBoard[], int r) {
    cout << '\n';
    for (int i = 0; i < r; ++i) cout << currentBoard[i] << '\n';
}

int main() {


    while (true) {

        int r, c, mines;
        cout << "\nEnter your board size and mine count: ";
        cin >> r >> c >> mines;
        if (1ll * r * c > 10000) {
            cout << "\nToo big!\n";
            continue;
        }
        if (mines >= r * c || mines < 1) {
            cout << "\nInvalid mine count!\n";
            continue;
        }

        bool board[r * c];
        memset(board, 0, sizeof board);
        vector<int> candidate;
        for (int i = 0; i < r * c; ++i) candidate.push_back(i);
        for (int i = 0; i < mines; ++i) {

            int newMine = rand() % (r * c - i);
            board[newMine] = true;
            candidate.erase(candidate.begin() + newMine);

        }
        string currentBoard[r];
        for (int i = 0; i < r; ++i) {
            currentBoard[i] = "";
            for (int j = 0; j < c; ++j) currentBoard[i] += "+";
        }

        print(currentBoard, r);
        int moves = r * c - mines;
        while (moves) {

            int x, y;
            cout << "\nEnter your move: ";
            cin >> x >> y;
            if (x < 1 || x > r || y < 1 || y > c) {
                cout << "\nInvalid move!\n";
                continue;
            }

            int Q = update(moves, --x, --y, board, r, c, currentBoard);
            if (!Q) {
                show(currentBoard, board, r, c);
                print(currentBoard, r);
                cout << "\nYou lose!\n";
                break;
            }
            if (Q == 2) {
                cout << "\nDon't repeat moves!\n";
                continue;
            }
            print(currentBoard, r);

        }
        if (!moves) cout << "\nYou won!\n";

        cout << "\nPlay again? (Y/N) ";
        char q; cin >> q;
        if (q == 'Y') continue;
        break;
    }

    return 0;
}
