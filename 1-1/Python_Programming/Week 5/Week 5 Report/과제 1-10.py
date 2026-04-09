i, j = 0, 0

myList = list(map(str, input("단어를 입력하세요 : ")))

while myList[i] not in ["a","e","i","o","u"] :
    i += 1

for j in range(i):
    print(myList[j], end='')
