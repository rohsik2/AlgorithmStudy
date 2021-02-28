from itertools import count
from math import gcd

def get_element(number , x):
    while(number != 1):
        for cycle in count(1):
            y = x
            for i in range(2 ** cycle):
                x = (x * x + 1) % number
                factor = gcd(x - y, number)
                if factor > 1:
                    return number, factor


n = int(input())

def solve(n):
    ans = n
    for i in range(2,int(n**(1/2) + 1)):
        if n % i == 0:
            ans *= (1.0 - 1.0 / float(i))
        while n % i == 0:
            n /= i
    if n > 1:
        ans *= (1.0 - 1.0 / float(n))
    return int(ans)

number, factor = get_element(n, 2)
if number == factor:
    number, factor = get_element(n,3)
if number == factor:
    number, factor = get_element(n,4)

acc = 1;

if gcd(number//factor, factor) == 1:
    print(solve(number//factor) * solve(factor))
else:
    print(solve(number))
    



'''
x = 2

number = int(input())




for cycle in count(1):
    y = x
    if(cycle > 29):
        break
    for i in range(2**cycle):
        x = (x * x + 1) % number
        factor = gcd(x-y,number)
        if x-y > number**(1/2):
            break
        if factor > 1:
            number = number//factor
            acc *= factor-1
            while number % factor == 0:
                number //= factor
                acc *= factor
    
    if(number == 1):
        break

print(acc)
'''