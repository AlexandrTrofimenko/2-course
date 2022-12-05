import math
isPrime=[]
def check(a):
    for x in range(2,a):
        k = 0
        if x < 2:
            k+=1
        for i in range(2, math.isqrt(x)+1):
            if x % i == 0:
                k+=1
        if k == 0:
            isPrime.append(x)
    return isPrime

x = int(input())
print(check(x))