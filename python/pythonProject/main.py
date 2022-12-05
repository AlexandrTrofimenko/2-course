from tkinter import *
from tkinter import filedialog
from tkinter import messagebox

root = Tk()
root.title('Text Editor')
mainmenu = Menu(root)
root.config(menu=mainmenu)
text_editor = Text()
root.geometry('600x600')
filemenu = Menu(mainmenu, tearoff=0)

def open_func():
    file = filedialog.askopenfilename()
    if file !='':
        with open(file,'r') as f:
            text = f.read()
            text_editor.delete('1.0', END)
            text_editor.insert('1.0',text)

def save_func():
    file = filedialog.asksaveasfilename()
    if file != '':
        text = text_editor.get('1.0', END)
        with open(file, 'w') as f:
            f.write(text)

def exit_func():
    exit = messagebox.askokcancel("Exit", "Are you sure?")
    if exit:
        root.destroy()

def info_func():
    message=messagebox.showinfo("Author","Бычкова Полина Викторовна")

filemenu.add_command(label="Open",command = open_func)
filemenu.add_command(label="Save",command=save_func)
filemenu.add_separator()
filemenu.add_command(label="Exit",command=exit_func)
helpmenu = Menu(mainmenu, tearoff=0)
helpmenu.add_command(label="About",command=info_func)

mainmenu.add_cascade(label="File",
                     menu=filemenu)
mainmenu.add_cascade(label="Help",
                     menu=helpmenu)

root.mainloop()
