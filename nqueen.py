from queue import PriorityQueue

N = int(input("Enter the N value for nxn board"))

def heuristic(board):

    attacks = 0
    
    for i in range(N):
        for j in range(i+1,N):

            if(board[i]==board[j]):
                attacks += 1

            if(abs(board[i]-board[j])==abs(i-j)):
                attacks += 1
    
    return attacks

def print_board(board):
    for i in range(N):
        for j in range(N):

            if(board[i]==j):
                print("Q",end=" ")
            else:
                print(".",end=" ")

        print()

    print("-x-x-x-x-x-x-x-x-")

def solve():
    pq = PriorityQueue()
    start = [0]*N
    h = heuristic(start)

    pq.put((h,start))
    visited = set()

    while not pq.empty():

        f,board = pq.get()
        key = str(board)

        if key in visited:
            continue

        visited.add(key)
        print("Board : ",board)
        print_board(board)

        if(heuristic(board)==0):
            print("Solution found")
            return
        
        for row in range(N):
            for col in range(N):

                new_board = board[:]
                new_board[row] = col
                h = heuristic(new_board)
                g = sum(new_board)
                f = g+h
                pq.put((f,new_board))

solve()