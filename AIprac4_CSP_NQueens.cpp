#include <bits/stdc++.h>
using namespace std;

class NQueens {
    private:
    int N;
    vector<vector<int>> board;

    vector<bool> column;
    vector<bool> diag1;
    vector<bool> diag2;

    int totalSolutions = 0;
    vector<vector<vector<int>>> allSolutions;
    vector<vector<int>> bestSolution;

    public:
    NQueens (int n) {
        N = n;
        board.resize(N, vector<int>(N, 0));
        column.resize(N, false);
        diag1.resize(2*N - 1, false);
        diag2.resize(2* N-1, false);
    }

    void solve(int row) {
        if (row == N) {
            totalSolutions++;

            allSolutions.push_back(board);

            if (bestSolution.empty()) {
                bestSolution = board;
            }

            return;
        }

        for (int col = 0; col < N; col++) {

            if (!column[col] && !diag1[row - col + N - 1] && !diag2[row+col]) {
                board[row][col] = 1;
                column[col] = true;
                diag1[row - col + N - 1] = 1;
                diag2[row+col] = 1;

                solve(row+1);

                //Backtrack
                board[row][col] = 0;
                column[col] = false;
                diag1[row - col + N - 1] = 0;
                diag2[row+col] = 0;
            }
        }
        return;
    }

  void printBoard() {
        for (int k = 0; k < allSolutions.size(); k++) {
            cout << "\nSolution " << k << endl;
          for (int i = 0; i < N; i++) {
              for (int j = 0; j < N; j++) {
                  if (allSolutions[k][i][j] == true) {
                      cout << "Q ";
                  } else {
                      cout << ". ";
                  }
              }
              cout << endl;
          }
        }
  }
};

int main() {
	// your code goes here
	int n;
	cin >> n;

	NQueens queens(n);

	queens.solve(0);
	queens.printBoard();

}

