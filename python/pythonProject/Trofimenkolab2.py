from tkinter import *
from tkinter import filedialog
from tkinter import messagebox

root = Tk()
root.title('Блокнот')
mainmenu = Menu(root)
root.config(menu=mainmenu)
text_editor = Text()
text_editor.grid(column = 0,columnspan = 2 ,row = 0)
filemenu = Menu(mainmenu, tearoff=0)

def open_func():
    file = filedialog.askopenfilename()
    if file !='':
        with open(file,'r') as f:
            text = f.read()
            text_editor.delete('1.0', END)
            text_editor.insert('1.0',text)


filemenu.add_command(label="Открыть...",command = open_func)
def save_func():
    file = filedialog.asksaveasfilename()
    if file != '':
        text = text_editor.get('1.0', END)
        with open(file, 'w') as f:
            f.write(text)
filemenu.add_command(label="Сохранить...",command=save_func)

def exit_func():
    n = messagebox.askokcancel("Выход", "Вы уверены, что хотите выйти?")
    if n:
        root.destroy()

filemenu.add_command(label="Выход",command=exit_func)

helpmenu = Menu(mainmenu, tearoff=0)

def info_func():
    n=messagebox.showinfo("Информация об авторе","Автор Трофименко Александр Романович")

helpmenu.add_command(label="О программе",command=info_func)

mainmenu.add_cascade(label="Файл",
                     menu=filemenu)
mainmenu.add_cascade(label="Помощь",
                     menu=helpmenu)

root.mainloop()
