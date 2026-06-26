def multi(v1, v2):
    hap = v1 + v2
    sub = v1 - v2
    return hap, sub

hap, sub = 0, 0

hap, sub = multi(100, 200)
print(f"mulit()에서 돌려준 값 ==> {hap}, {sub}")