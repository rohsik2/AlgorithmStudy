card_num , target = map(int, input().split(" "))
cards = []
for x in input().split(" "):
    cards.append(int(x))

bacon = target

for i in range(len(cards)-2):
  for j in range(i+1,len(cards)):
    for k in range(j+1,len(cards)):
      made = target - cards[i]-cards[j]-cards[k]
      if made >= 0 and bacon > made:
        bacon = made

print(target-bacon)