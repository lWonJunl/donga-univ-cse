aa = []
i, k, hap = 0, 0, 0

for i in range(3,-1,-1):
    aa.append(int((input("%d번째 숫자 : " % (i+1)))))

while k<4:
    hap += aa[k]
    k += 1

print("합계 ===> %d" % hap)