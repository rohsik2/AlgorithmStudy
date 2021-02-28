x = int(input())
def fibonacci(x):
    if x == 0:
      return 0
    if x == 1:
      return 1
    if x == 2:
      return 1
    return fibonacci(x-1)+fibonacci(x-2)
print(fibonacci(x))