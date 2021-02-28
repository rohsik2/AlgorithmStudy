import re
DATA = input()
ops = []
nums = []
for i in DATA.split("+"):
    for j in i.split("-"):
        nums.append(int(j))
for i in range(len(DATA)):
    if DATA[i] == '+':
        ops.append('+')
    elif DATA[i] == '-':
        ops.append('-')

cnt = nums[0]
walker = 0
for i in range(len(ops)):
    if ops[i] == "+":
        cnt = cnt + nums[i+1]
    else:
        break
    walker = walker+1

for i in range(walker,len(ops)):
    cnt -= nums[i+1]

print(cnt)