myList = [30, 10, 20]
print("처음 리스트 : %s" % myList)
print()

# 01. 반복문 사용해서 [40, 41, 42] 추가
aa = [40, 41, 42]
for i in range(len(aa)):
    myList.append(aa[i])
print("[40, 41, 42]을 추가한 후의 리스트 %s" % myList)
print()

# 02. 리스트에서 마지막 값 제거
myList.pop()
print("리스트에서 마지막 값 제거한 후의 리스트 %s" % myList)
print()

# 03. 리스트 전체 크기 출력
print("현재 리스트 : %s" % myList)
print("리스트의 전체 크기: %d" % len(myList))
print()

# 04. 리스트의 index 2를 1000으로 변경
myList[2] = 1000    # 또는 myList.insert(2,1000)
print("index 2를 1000으로 변경한 후의 리스트 %s" % myList)
print()

# 05. 리스트 전체 삭제
myList.clear()
print("리스트 전체 삭제한 후의 리스트 %s" % myList)
print()
