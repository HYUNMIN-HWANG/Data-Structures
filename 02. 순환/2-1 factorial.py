import math

n = 5
result = 0

if n <= 1 :
    result = 1
else :
    result = n * math.factorial (n-1) 

print(result)