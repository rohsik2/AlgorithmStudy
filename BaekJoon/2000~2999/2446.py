a = int(input())
for i in range(a):
    print(" "*i,end="")
    print("*"*((a-i)*2-1))

for j in range(1,a):
    print(" "*(a-j-1),end="")
    print("*"*(j*2+1))