from sys import stdin
A,B,C = stdin.readline().split(" ")
A = int(A)
B = int(B)
C = int(C)
if B >= C:
  print(-1)
else:
  print((A//(C-B))+1)