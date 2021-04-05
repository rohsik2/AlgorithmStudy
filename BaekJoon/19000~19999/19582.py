import sys
input = sys.stdin.readline
n_data = int(input())

max_idx = -1
max_val = 0
skip_idx = -1

acc = 0
datas = []

def check(skip):
	acc = 0
	for i in range(n_data):
		if i == skip:
			continue
		if acc <= datas[i][0]:
			acc += datas[i][1]
			continue
		return False
	return True

for i in range(n_data):
	limit, price = map(int,input().split())
	datas.append([limit, price])

for i in range(n_data):
	if acc <= datas[i][0]:
		acc += datas[i][1]
		if max_val != max(max_val, datas[i][1]):
			max_val = max(max_val, datas[i][1])
			max_idx = i
	else:
		skip_idx = i
		break
result = check(skip_idx) or check(max_idx)

if result:
	print('Kkeo-eok')
else:
	print('Zzz')
