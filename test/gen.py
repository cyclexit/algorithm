import random

n = int(input())
print(n)
for i in range(0, n):
  print(random.randint(0, int(1e9)))