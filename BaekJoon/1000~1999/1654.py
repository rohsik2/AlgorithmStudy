import sys

input = sys.stdin.readline
n_pipe, target = map(int,input())
pipes = []
for i in range(n_pipe):
    pipes.append(int(input()))

def is_possible(length):
    global pipes
    global target
    total = 0
    for pipe in pipes:
        total += pipe//length
    if total >= target:
        return True
    return False

def find_best(strt, end):
    mid = (strt+end)//2
    print(mid)
    if strt >= end-1:
        return mid
    if is_possible(mid):
        return find_best(mid, end)
    return find_best(strt,mid)

print(find_best(0, max(pipes)))