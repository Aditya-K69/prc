from queue import PriorityQueue

# Goal State
goal = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 0]
]

# Heuristic Function (Manhattan Distance)
def heuristic(board):

    h = 0

    for i in range(3):
        for j in range(3):

            if board[i][j] != 0:

                val = board[i][j] - 1

                goal_x = val // 3
                goal_y = val % 3

                h += abs(i - goal_x) + abs(j - goal_y)

    return h


# Print Board
def print_board(board):

    for row in board:
        print(*row)

    print("---------")


# A* Algorithm
def solve(start, x, y):

    pq = PriorityQueue()

    # (heuristic value, board, x, y)
    pq.put((heuristic(start), start, x, y))

    visited = set()

    # Directions
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    while not pq.empty():

        h, board, x, y = pq.get()

        key = str(board)

        if key in visited:
            continue

        visited.add(key)

        print_board(board)

        # Goal Check
        if board == goal:
            print("Goal Reached!")
            return

        # Move blank space
        for i in range(4):

            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < 3 and 0 <= ny < 3:

                # Copy board
                new_board = [row[:] for row in board]

                # Swap
                new_board[x][y], new_board[nx][ny] = new_board[nx][ny], new_board[x][y]

                pq.put((
                    heuristic(new_board),
                    new_board,
                    nx,
                    ny
                ))


# Initial State
start = [
    [1, 2, 3],
    [4, 0, 6],
    [7, 5, 8]
]

# Position of 0
x = 1
y = 1

solve(start, x, y)