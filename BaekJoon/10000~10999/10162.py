a = int(input())
if a % 10 != 0:
    print(-1)
else:
    print(a//300, end = " ")
    a = a%300
    print(a//60, end = " ")
    a = a%60
    print(a//10)