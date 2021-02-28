import math
a,b,c,d = map(int, input().split())
print(min(d-b,c-a,a,b))