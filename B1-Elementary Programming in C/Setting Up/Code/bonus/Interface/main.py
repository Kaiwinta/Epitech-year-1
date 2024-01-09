##
## EPITECH PROJECT, 2023
## B-CPE-110-STG-1-1-settingup-titouan.pradoura
## File description:
## test_bash.py
##

import tkinter as tk
import page_opening as po
import subprocess
import page_gene as pg
import all_function as af

def main():
    
    global palette
    palette = ["#12100E","#30321C","#4A4B2F","#F4F1DE"]
    subprocess.run("make re", shell = True, executable="/bin/bash")

    window = tk.Tk()
    window.geometry("800x450+{}+{}".format(int(window.winfo_screenwidth()/2 - 400), int(window.winfo_screenheight()/2 - 225)))
    window.title('Setting up')
    # window.iconbitmap("bonus/Images/flask.ico")
    window.resizable(False,False)
    window.bind('<Escape>',lambda e: window.destroy())
    window.configure(bg=palette[2])

    page1(window)
    window.mainloop()

def page1(frame):
    global palette

    imagecat = af.resize_image("Images/cat.png", 100, 100)
    imagedino = af.resize_image("Images/dinosaur.png", 259//2, 224//2)
    imagefrog = af.resize_image("Images/frog.png", 40, 40)
    
    frameTitre = tk.Frame(frame,bg = palette[0])
    frameTitre.place(rely=0.08, relx=0.1, relheight= 0.1 , relwidth=0.8)
    
    labelImagefrog = tk.Label(frameTitre, image = imagefrog, bg=palette[0])
    labelImagefrog.place(relx=0, rely=0)
    
    labelTitre = tk.Label(frameTitre, fg = palette[3], text="̠S̠̠e̠̠t̠̠t̠̠i̠̠n̠̠g̠ ̠u̠̠p̠",font=("actual",16), bg = palette[0])
    labelTitre.place(rely=0.5,relx=0.5, anchor= "center")
    
    frameBas = tk.Frame(frame , bg=palette[1])
    frameBas.place(rely=0.2,relx=0.1,relheight=0.72,relwidth=0.8)

    def gotopage2():
        af.delete(frameBas)
        pg.page_gene(frame, palette, page1)

    def gotopageopen():
        af.delete(frameBas)
        po.page_opening(frame, palette, page1)

    labelImagecat = tk.Label(frameBas,image = imagecat, bg=palette[1])
    labelImagecat.place(relx=0.8, rely=0.7)
    labelImagedino = tk.Label(frameBas,image = imagedino, bg=palette[1])
    labelImagedino.place(relx=0.05, rely=0.66)

    textebienvenu = "Welcome,\nthis application is an interface for the Epitech Setting up.\n\nChoose the task that you want to perform"

    labelDesciption = tk.Label(frameBas,fg = palette[3], bg = palette[1],text=textebienvenu ,font =("actual",12))
    labelDesciption.place(relheight=0.4,relwidth=0.80,relx=0.1,rely=0.05)

    buttonPage2 = tk.Button(frameBas, command=gotopageopen, text="Open file", bg = palette[0], fg= palette[3])
    buttonPage2.place(rely=0.55,relx=0.6, relwidth=0.2)

    buttonPage2 = tk.Button(frameBas, command=gotopage2, text="Generate", bg = palette[0], fg=palette[3])
    buttonPage2.place(rely=0.55,relx=0.25, relwidth=0.2)

    frame.mainloop()

if __name__ == "__main__":
    main()
