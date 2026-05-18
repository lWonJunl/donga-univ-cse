inFp = None
inStr = ""

inFp = open("C:/Users/user/Github/DongA_Univ_CSE/1-1/Python_Programming/Week 11/data1.txt", "r")

inStr = inFp.readline()
print(inStr, end="")

inStr = inFp.readline()
print(inStr, end="")

inStr = inFp.readline()
print(inStr, end="")

inFp.close()