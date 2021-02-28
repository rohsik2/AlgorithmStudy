#n =5
n = int(input())
k = 1

while (k*(k+1)//2) < n:
  k+=1
#k=4
is_odd = 0
if k%2 == 0:
  result = [k,1]
  is_odd = True
else:
  result = [1,k]
  is_odd = False

cnt = k*(k+1)//2
while cnt != n:
  cnt -= 1
  if is_odd:
    result[0] -= 1
    result[1] += 1
  else:
    result[1] -= 1
    result[0] += 1

print(result[0], "/", result[1],sep = "")
