[[2, 1, 0, 0, 1, 1, 0],
 [1, 0, 1, 0, 1, 2, 0],
 [0, 1, 1, 0, 1, 0, 0],
 [0, 1, 0, 0, 0, 1, 0],
 [0, 0, 0, 0, 0, 1, 1],
 [0, 1, 0, 0, 0, 0, 0],
 [0, 1, 0, 0, 0, 0, 0]]import pprint
from collections import deque
row_size, col_size = map(int ,input().split())
board = []
large = -1

def is_valid(r, c):
    global row_size
    global col_size
    return (0<=r<row_size and 0<=c<col_size)

def simulate(board):
    dq = deque()
    for row in range(len(board)):
        for col in range(len(board[0])):
            if board[row][col] == 2:
                dq.append([row, col])
    dx = [1,-1, 0, 0]
    dy = [0, 0, 1,-1]
    while dq:
        cur = dq.popleft()
        for i in range(4):
            if is_valid(cur[0]+dx[i], cur[1]+dy[i]):
                if board[cur[0]+dx[i]][cur[1]+dy[i]] == 0:
                    board[cur[0]+dx[i]][cur[1]+dy[i]] = 2
                    dq.append([cur[0]+dx[i], cur[1]+dy[i]])
    count = 0
    for row in range(len(board)):
        for col in range(len(board[0])):
            if board[row][col] == 0:
                count+=1
    return count


for i in range(row_size):
    board.append(list(map(int, input().split())))
    
for i in range(row_size*col_size):
    for j in range(i+1, row_size*col_size):
        for k in range(j+1, row_size*col_size):
            if board[i//col_size][i%col_size] == 0 and \
                board[j//col_size][j%col_size] == 0 and \
                board[k//col_size][k%col_size] == 0:
                nboard = [[*row] for row in board]
                nboard[i//col_size][i%col_size] = 1
                nboard[j//col_size][j%col_size] = 1
                nboard[k//col_size][k%col_size] = 1
                large = max(large, simulate(nboard))

print(large)