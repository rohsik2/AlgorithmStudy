import math
test_case = int(input())
for i in range(test_case):
  def func(x):
    return int(x)
  height, room, c_num = map(func, input().split(" "))
  if math.ceil(c_num/height) <10:
    if(c_num%height == 0):
      print(str(height)+"0"+str(math.ceil(c_num/height)))
    else:
      print(str(c_num%height)+"0"+str(math.ceil(c_num/height)))
  else:
    if(c_num%height == 0):
      print(str(height)+str(math.ceil(c_num/height)))
    else:
      print(str(c_num%height)+str(math.ceil(c_num/height)))
