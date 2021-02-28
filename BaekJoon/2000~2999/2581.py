import math
def is_prime(x):
  if x==1:
    return False
  if x==2:
    return True
  if x%2==0:
    return False
  for i in range(3,math.ceil(math.sqrt(x))+1,2):
    if x % i == 0:
      return False
  return True
  
a = int(input())
b = int(input())
min = -1
cnt = 0
for i in range(a,b+1):
    if is_prime(i):
        if min== -1:
            min = i
        cnt += i
        
if min == -1:
    print(min)
else:
    print(cnt)
    print(min)