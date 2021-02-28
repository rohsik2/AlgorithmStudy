test_case = int(input())
cnt = 0
for i in range(test_case):
  string = input()

  def remove_dup(string, idx):
    if idx+1>=len(string):
      return string
    if string[idx] == string[idx+1]:
      string = string[:idx]+string[idx+1:]
      return remove_dup(string, idx)
    return string
  idx = 0
  while idx < len(string):
    string = remove_dup(string,idx)
    idx += 1
  for j in range(len(string)):
    if string.count(string[j]) != 1:
      cnt+=1
      break
print(test_case - cnt)