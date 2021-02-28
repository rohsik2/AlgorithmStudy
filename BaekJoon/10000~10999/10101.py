import math

a = int(input())
b = int(input())
c = int(input())

if a==b and b==c and a==60:
  print("Equilateral")
elif a+b+c != 180:
  print("Error")
elif a==b or b==c or c==a:
  print("Isosceles")
else:
  print("Scalene")