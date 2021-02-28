
test_case = int(input())
for i in range(test_case):
    temp = input()
    temp = temp.split(" ")
    rpt_time = int(temp[0])
    result = temp[1]
    for j in range(len(result)):
        print(result[j]*rpt_time,end="")
    print()