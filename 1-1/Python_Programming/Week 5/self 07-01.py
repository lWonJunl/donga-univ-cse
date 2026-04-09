aa = []
hap, k = 0, 0

for i in range(10):
    aa.append(int((input("%d번째 숫자 : " % (i+1)))))

while k<10:
    hap += aa[k]
    k += 1

print("합계 ===> %d" % hap)