import sys
a = input()
arr1 = ["0","1","10","11","100","101","110","111"]
arr = ["000","001","010","011","100","101","110","111"]

sys.stdout.write(arr1[int(a[0])%8])
for i in range(1, len(a)):
  sys.stdout.write(arr[int(a[i])%8])