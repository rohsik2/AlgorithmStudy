import sys
sys.setrecursionlimit(100)
input = sys.stdin.readline

row, col = map(int, input().split())

board = []
for i in range(row):
    board.append(input())


dr = [1,-1,0,0]
dc = [0,0,1,-1]
def is_valid(r, c):
    if r > -1 and c > -1 and r < row and c < col:
        return not visited[ord(board[r][c])-ord('A')]
    return False
visited = [False for _ in range(26)]
def get_max(cur_row, cur_col, times ):
    if visited[ord(board[cur_row][cur_col])-ord('A')]:
        return times
    else:
        visited[ord(board[cur_row][cur_col])-ord('A')] = True
        times += 1
    large = times
    for i in range(4):
        if is_valid(cur_row+dr[i], cur_col+dc[i]):
            large = max(large, get_max(cur_row+dr[i], cur_col+dc[i],times))
    visited[ord(board[cur_row][cur_col])-ord('A')] = False
    return large


print(get_max(0, 0, 0))