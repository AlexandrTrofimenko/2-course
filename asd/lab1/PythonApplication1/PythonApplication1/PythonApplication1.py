def check(s):
    result = 0
    result1 = 0
    result2 = 0
    for a in s:
        if "(" in a:
            result +=1
        elif ")" in a:
            result -= 1
        if "{" in a:
            result1 +=1
        elif "}" in a:
            result1 -= 1
        if "[" in a:
            result2 +=1
        elif "]" in a:
            result2 -= 1
 
        if result < 0:
            return"NO"
    if result > 0:
        return"NO"
    if result1<0:
        return"NO"
    if result1>0:
        return "NO"
    if result2<0:
        return "NO"
    if result2>0:
        return "NO"
    return "YES"


print(check(input()))
