day_up,night_down,target = input().split(" ")
day_up = int(day_up)
night_down = int(night_down)
target = int(target)
if target < day_up:
  print(1)
else:
  target -= day_up
  if(target%(day_up-night_down) == 0):
      print(target//(day_up-night_down)+1)
  else:
      print(target//(day_up-night_down)+2)
