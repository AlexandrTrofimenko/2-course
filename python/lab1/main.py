s=['abc','bca','abc','asd','asd']
d={}
def counts(list):
    for a in list:
        if d.get(a,None):
            d[a]+=1
        else:
            d[a]=1
    return d

print(counts(s))

import random
g = []
for i in range(10):
    g.append(random.randrange(1, 1000))
g.sort()
print(g)