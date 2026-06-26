aa = []
bb = []
value = 0

while len(aa)<200:
    aa.append(value)
    value += 3


for i in range(0,200):
    bb.append(aa[199-i])
    
## 또는 bb = aa; bb.reverse() 으로 리스트를 역순으로 만들 수 있다.

print("bb[0]에는 %d이, b[199]에는 %d이 입력됩니다." % (bb[0], bb[199]))