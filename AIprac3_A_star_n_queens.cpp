#include <bits/stdc++.h>
using namespace std;

/*
1. Node => 1D array for board state, heuristics (g, h), operator overload
2. Heuristics
3. Printboard
4. solve
*/

struct Node {
    vector<int> board; //for each index, value is column of queen in each row
    int g, h; //heuristics

    bool operator>(Node const &other) const {
        return g + h > other.g + other.h;
    }
};

//Step 2:
int heuristic(vector<int> board) {
    int n = board.size();
    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (board[i] == board[j] // same column
                || abs(board[i] - board[j] == abs(i - j))) { //same diagonal
                    c++;
            }
        }
    }
    return c;
}

//Step 3
void printBoard(vector<int> board) {
    for (int i = 0; i < board.size(); i++) {
        cout << board[i] << " ";
    }
    cout << endl;
}


//Step 4: solve
void solve(int n) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    set<vector<int>> visited;

    vector<int> start(n);
    for (int i = 0; i < n; i++) {
        start[i] = rand()%n;
    }
    pq.push({start, 0, heuristic(start)});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.h == 0) {
            cout << "Solution mil gaya!";
            printBoard(current.board);return;
        }

        if (visited.count(current.board)) {
            continue;
        }
        visited.insert(current.board);

        cout << "\nh = " << current.h << " g = " << current.g << endl;
        printBoard(current.board);

        //generate neighbors
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (current.board[i] != j) {
                    auto next = current.board;
                    next[i] = j;
                    pq.push({next, current.g+1, heuristic(next)});
                }
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;
    cout << endl;
    solve(n);
}
