n = int(input())
cnt = 1
n = n-1
while n > 0:
  n -= cnt*6
  cnt+=1
print(cnt)