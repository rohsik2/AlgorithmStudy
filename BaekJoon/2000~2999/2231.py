target = int(input())
found = False
result = 0
for i in range(target):
    numbers = []
    temp = i
    while temp > 0:
        numbers.append(temp%10)
        temp //= 10
    cnt = i
    for num in numbers:
        cnt += num
    if cnt == target:
        found = True
        result = i
        break
print(result)