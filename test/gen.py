import random

n = int(input("n:"))
print(n)
for i in range(0, n):
  print(random.randint(0, int(1e9)))