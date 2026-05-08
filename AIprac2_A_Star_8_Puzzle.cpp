
#include <bits/stdc++.h>
using namespace std;

/*
1. Struct Node: state, heuristics, position of 0, operator overload
2. Goal state => vector<vector<int>> goal = {{1,2,3}, {4,5,6}, {7,8,0}}
3. Heuristics: if not zero -> val = a[i][j] - 1, d+= i - val/3  + j - val%3
4. serialize: string += to_string(x) after two for loops. Also declare directions
5. solve => priority queue, visited set, push in queue, while pq not empty, for i = 0 to 4, if in board, copy, swap and push.
*/

//Step 1
struct Node {
    vector<vector<int>> state;//current state of board
    int g, h;//heuristics: distance from initialstate and to end goal
    int x, y;//position of 0 in state

    //compare two nodes
    bool operator>(const Node &other) const {
        return g + h > other.g + other.h;
    }
};

//Step 2: goal
vector<vector<int>> goal = {{1,2,3}, {4,5,6}, {7,8,0}};

//Step 3:
int heuristic(vector<vector<int>> &a) {
    int h = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] != 0) { //ignore blank space (0)
                int val = a[i][j] - 1;
                h += abs(i - val/3) + abs(j - val%3);
            }
        }
    }
    return h;
}

//step 4: convert vector vector to string for ez adding in set
string serialize(vector<vector<int>> &a) {
    string s = "";
    for (auto r: a) {
        for (int x : r) {
            s += to_string(x);
        }
    }
    return s;
}

//directions
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

//to print board
void printboard(vector<vector<int>> board) {
    for (auto &row : board) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << "_________________";
}

//Step 5
void solve(vector<vector<int>> start, int x, int y) {
    //remember the following:
    //priority_queue<type_of_element, Container, Comparator>
    //basically default is max heap so we use greater<Node> to make it a min heap.
    priority_queue<Node, vector<Node>,greater<Node>> pq;
    set<string> visited;

    //write in sequence of how you initialized struct
    pq.push({start, 0, heuristic(start), x, y});

    while (!pq.empty()) {
        //get top node (minimum heuristic
        Node current = pq.top();
        pq.pop();

        //check if already visited (set mei daalke)
        string key = serialize(current.state);
        if (visited.count(key)) {
            continue;
        }
        visited.insert(key);

        cout << "Current: g = " << current.g << " h = " << current.h << endl;
        printboard(current.state);



        if (current.state == goal) {
            cout << "Target reached\n";
            printboard(current.state);
            cout << "Total moves: " << current.g << endl;
            return;
        }

        //check for 4 directions
        for (int i = 0; i < 4; i++) {
                //provide new position for zero
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            //if new position in board ki limit
            if (nx >= 0 && ny >= 0 && nx < 3 && ny < 3) {
                //store current state
                auto b = current.state;
                //swap element at new position with zero ki current pos
                //hence zero at new position
                swap(b[current.x][current.y], b[nx][ny]);
                //push this new node with new zero position in pq.
                pq.push({b, current.g+1, heuristic(b), nx, ny});
            }
        }
    }
}

int main() {
    //Here, if no of times bigger number comes before smaller number is odd, the puzzle is NOT solvable!!!!!
    //1 2 3 4 0 6 8 7 5
    //(8, 7), (8,5), (6,5), (7,5) => 4 => even => solvable
    vector<vector<int>> start = {
        {1,2,3},
        {4,0,6},
        {8,7,5}};

    int x = 1, y = 1; //position of zero

    solve(start, x, y);

    return 0;
}
