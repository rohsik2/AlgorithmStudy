n_people, n_party = map(int,input().split())

arr = [x for x in map(int,input().split()[1:])]
p_arr = []
for i in range(n_party):
	p_arr.append([x for x in map(int,input().split()[1:])])

truth_arr = [False for x in range(n_people+1)]
for x in arr:
	truth_arr[x] = True

cnt = 0
for _ in range(50):
	for party in p_arr:
		is_true_party = False
		for people in party:
			if truth_arr[people] :
				is_true_party = True
				break
		if is_true_party:
			for people in party:
				truth_arr[people] = True

for party in p_arr:
	is_true_party = False
	for people in party:
		if truth_arr[people] :
			is_true_party = True
			break
	if is_true_party:
		for people in party:
			truth_arr[people] = True
	else:
		cnt+=1
print(cnt)