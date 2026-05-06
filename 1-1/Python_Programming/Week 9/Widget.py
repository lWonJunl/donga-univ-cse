from tkinter import *
from tkinter import messagebox

window = Tk()
window.title(("2653572"))
window.resizable(width=False, height=False)

def myFunc():
    messagebox.showinfo("강아지 버튼", "강아지가 귀엽죠? ^^")

def myFunc1():
    if chk.get() == 0:
        messagebox.showinfo("", "체크버튼이 꺼졌어요.")
    else:
        messagebox.showinfo("", "체크버튼이 켜졌어요.")

def myFunc2():
    if var.get() == 1:
        label5.configure(text="1학년")
    elif var.get() == 2:
        label5.configure(text="2학년")
    elif var.get() == 3:
        label5.configure(text="3학년")
    else:
        label5.configure(text="4학년")

label1 = Label(window, text = "COOKBOOK ~~~ Python을")
label2 = Label(window, text = "열심히", font = ("궁서체", 30), fg="blue")
label3 = Label(window, text = "공부 중입니다.", bg="magenta", width=20, height=5, anchor=SE)

photo = PhotoImage(file="C:/Users/user/Github/DongA_Univ_CSE/1-1/Python_Programming/Week 9/gif/ch10_Image/dog.gif")
label4 = Label(window, image=photo)

button1 = Button(window, text="파이썬 종료", fg="red", command=quit)
button2 = Button(window, image=photo, command=myFunc)

chk = IntVar()
cb1 = Checkbutton(window, text="클릭하세요", variable=chk, command=myFunc1)

var = IntVar()
rb1 = Radiobutton(window, text="1학년", variable=var, value=1, command=myFunc2)
rb2 = Radiobutton(window, text="2학년", variable=var, value=2, command=myFunc2)
rb3 = Radiobutton(window, text="3학년", variable=var, value=3, command=myFunc2)
rb4 = Radiobutton(window, text="4학년", variable=var, value=4, command=myFunc2)

label5 = Label(window, text="선택한 학년 :", fg="red")

label1.pack()
label2.pack()
label3.pack()
label4.pack()
button1.pack()
button2.pack()
cb1.pack()
rb1.pack(side=LEFT)
rb2.pack(side=LEFT)
rb3.pack(side=LEFT)
rb4.pack(side=LEFT)
label5.pack()

window.mainloop()
