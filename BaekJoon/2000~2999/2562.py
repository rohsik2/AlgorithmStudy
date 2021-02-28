lista = []
for i in range(9):
	lista.append(int(input()))
listb=lista+[]
lista.sort()
print(lista[-1])
temp = lista[-1]
print(listb.index(temp)+1)