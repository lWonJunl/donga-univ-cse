import random as rd

player1 = input("player1의 이름 : ")
player2 = input("player2의 이름 : ")

print("......주사위를 굴립니다......")
dice1 = rd.randint(1,6)
dice2 = rd.randint(1,6)

print("%s의 주사위 번호는 %d" % (player1, dice1))
print("%s의 주사위 번호는 %d" % (player2, dice2))

if dice1>dice2:
    print("%s이 이겼습니다." % player1)
elif dice1<dice2:
    print("%s이 이겼습니다." % player2)
else:
    print("비겼습니다.")