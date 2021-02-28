code = input()
alphabet = ["ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"]
time = 0
for i in range(len(code)):
  for j in range(len(alphabet)):
    if alphabet[j].find(code[i]) != -1:
      time += 3 + j
      break
print(time)