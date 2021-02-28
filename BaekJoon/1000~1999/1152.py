wow = input()
result = len(wow.split(" "))
if wow[0] == " ":
  result-=1
if wow[-1] == " ":
  result-=1
print(result)