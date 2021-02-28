def gcd(a,b):
	a,b = max(a,b), min(a,b)
	if a%b == 0:
		return b
	else:
		return gcd(a%b, b)

n = int(input())
for i in range(n):
	lista = list(map(int, input().split()))
	n2 = lista[0]
	lista = lista[1:]
	sum = 0
	for i in range(len(lista)):
		for j in range(i+1, len(lista)):
			sum += gcd(lista[i], lista[j])
	print(sum)