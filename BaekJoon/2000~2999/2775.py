test_case = int(input())
table =[]
for i in range(15):
    table.append([0,0,0,0,0,0,0,0,0,0,0,0,0,0,0])
def func(x,y):
  if table[x][y]!=0:
    return table[x][y]
  if x==0:
    table[x][y] = 0
    return y
  if x==1:
    table[x][y] = y*(y+1)//2
    return y*(y+1)//2
  if y==0:
    table[x][y] = 0
    return 0
  if y == 1:
    table[x][y] = 1
    return table[x][y]
  if y==2:
    table[x][y] = x+2
    return x+2
  table[x][y] = func(x,y-1)+func(x-1,y)
  return table[x][y]

def func2(x):
  return int(x)
for i in range(test_case):
  usr1 = int(input())
  usr2 = int(input())
  print(func(usr1,usr2))
