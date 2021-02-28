import math
a,b,c = map(int, input().split(" "))
n = math.sqrt(a*a / (b*b+c*c))
print(int(n*b),int(n*c))