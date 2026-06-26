## 반복문 continue 사용
hap, i = 0, 0

for i in range(1,101):
    if i%3==0:
        print("i = %d 제외" % i)
        continue
    print("i = %d" % i)
    hap += i
print("합계(3의 배수 제외) : %d" % hap)
print("===================")

## list
aa = [0, 0, 0, 0]
hap = 0

for i in range(4):
    aa[i] = int((input("%d번째 숫자 : " % (i+1))))
    hap += aa[i]

print("합계 ===> %d" % hap)
print("===================")

## list.append
aa = []
hap = 0

for i in range(4):
    aa.append(int((input("%d번째 숫자 : " % (i+1)))))
    hap += aa[i]

print("합계 ===> %d" % hap)
print("===================")

## 