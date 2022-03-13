import sys
from collections import deque

sys.setrecursionlimit(10**6)
high, cur, target, up, down = map(int, input().split())

dp = [-1 for x in range(high+1)]

deq = deque()
dp[cur] = 0
deq.append([cur, 0])
while deq:
    head = deq.popleft()
    if head[0]+up <= high and dp[head[0]+up] == -1:
        dp[head[0]+up] = head[1]+1
        deq.append([head[0]+up, head[1]+1])
    if head[0]-down >= 1 and dp[head[0]-down] == -1:
        dp[head[0]-down] = head[1]+1
        deq.append([head[0]-down, head[1]+1])
    if(dp[target]!=-1):
        break

if(dp[target]==-1):
  print("use the stairs")
else:
  print(dp[target])