import sys

# DFS 와 DP를 섞는 문제
# 아래 코드를 사용해야만 재귀 깊이를 설정가능하다.
# BOJ 기본값은 1000이므로 Python 사용시 주의할것.

sys.setrecursionlimit(10**6)
n,m = map(int, sys.stdin.readline().split())

def is_valid(x,y):
    if x>=0 and x<n and y>=0 and y<m:
        return True
    return False

# 간단한 방법으로 2중리스트 초기화 가능.
visited = list(list(-1 for __ in range(m)) for _ in range(n))

board =[]

def dfs(x, y):
    if x == 0 and y == 0:
        return 1
    
    if(visited[x][y] != -1):
        return visited[x][y]

    result = 0
    if (is_valid(x+1,y) 
        and board[x+1][y] > board[x][y] 
        ):
           result += dfs(x+1, y) 
        
    if (is_valid(x-1,y) 
        and board[x-1][y] > board[x][y] 
        ):
           result += dfs(x-1, y) 
            
    if (is_valid(x,y+1) 
        and board[x][y+1] > board[x][y] 
        ):
           result += dfs(x, y+1) 
            
    if (is_valid(x,y-1) 
        and board[x][y-1] > board[x][y] 
        ):
           result += dfs(x, y-1) 
    visited[x][y] = result
    return result

for i in range(n):
    board.append(list(map(int, sys.stdin.readline().split())))

print(dfs(n-1,m-1))