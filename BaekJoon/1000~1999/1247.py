import sys
input = sys.stdin.readline
for i in range(3):
    case = int(input())
    cnt = 0
    for j in range(case):
        cnt += int(input())
    if cnt == 0:
        print('0')
    elif cnt <0:
        print('-')
    else:
        print('+')