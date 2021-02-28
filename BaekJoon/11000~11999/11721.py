str1 = input()

for i in range(0,len(str1)//10+1):
    for j in range(i*10,i*10+10):
        if j < len(str1):
            print(str1[j],end="")
        else:
            break
    print()
