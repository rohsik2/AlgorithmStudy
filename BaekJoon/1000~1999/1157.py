bacon = input().upper()
cnt = []
alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
for i in range(26):
    cnt.append(bacon.count(alphabet[i]))
b_max = -1
b_idx = -1
for i in range(26):
    if b_max < cnt[i]:
        b_max = cnt[i]
        b_idx = i
cnt.sort()
if cnt[-1] == cnt[-2]:
    print("?")
else:
    print(alphabet[b_idx])