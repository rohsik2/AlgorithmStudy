x = int(input())
def factorial(x):
    if x==0:
        return 1
    if x == 1:
        return 1
    return factorial(x-1)*x
print(factorial(x))