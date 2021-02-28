import sys
input = sys.stdin.readline

num = int(input())
for i in range(num):
  s = input().split()
  for word in s:
    print(word[::-1],end=' ')
  if i != num-1:
    print()