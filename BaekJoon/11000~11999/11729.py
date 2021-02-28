def hanoii_n(x):
  if x == 1:
    return 1
  return hanoii_n(x-1)*2+1

def hanoii(strt,dest,temp,length):
    if length == 1:
        print(strt,dest)
    else:
        hanoii(strt,temp,dest,length-1)
        print(strt,dest)
        hanoii(temp,dest,strt,length-1)

a=int(input())
print(hanoii_n(a))
hanoii(1,3,2,a)