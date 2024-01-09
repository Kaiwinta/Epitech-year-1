##
## EPITECH PROJECT, 2023
## test
## File description:
## Untitled-1
##

import tkinter as tk
from tkinter import ttk
from tkinter import filedialog
import subprocess
import all_function as af

def page_gene(frame, palette, page1):

    imagerat = af.resize_image("Images/cat.png", 100, 100)
    imagefrog = af.resize_image("Images/frog.png", 40, 40)
    imageback = af.resize_image("Images/button.png", 25, 25)
    textwelcome = "Welcome to the generation part.\n\nChoose if you want to generate a square or a rectangle.\nAnd then select his size and the pattern that he muss follow.\nThe pattern can only be composed of '.' and 'o'."

    frameTitre = tk.Frame(frame,bg = palette[0])
    frameTitre.place(rely=0.08, relx=0.1, relheight= 0.1 , relwidth=0.8)
    frameBas = tk.Frame(frame , bg=palette[1])
    frameBas.place(rely=0.2,relx=0.1,relheight=0.72,relwidth=0.8)
    
    labelTitre = tk.Label(frameTitre, fg = palette[3], text="Generating",font=("actual",16), bg = palette[0])
    labelTitre.place(rely=0.5,relx=0.5, anchor= "center")
    labelImagefrog = tk.Label(frameTitre, image = imagefrog, bg=palette[0])
    labelImagefrog.place(relx=0, rely=0)
    labelImagerat = tk.Label(frameBas,image = imagerat, bg=palette[1])
    labelImagerat.place(relx=0.8, rely=0.7)
    labelDesciption = tk.Label(frameBas,fg = palette[3], bg = palette[1], text=textwelcome ,font =("actual",12))
    labelDesciption.place(relheight=0.3,relwidth=1,relx=0,rely=0.05)

    def callback(event):
        value = selected_value.get()
        if value == "rect":
            height.state(['!disabled'])
            width.state(['!disabled'])
        if value == "square":
            height.state(['!disabled'])
            width.state(['disabled'])
            width.set(0)

    def goback():
        af.delete(frameBas)
        page1(frame)

    def generate():
        patterncall = pattern.get()
        form = selected_value.get()
        nb_line = height_value.get()
        size_line = width_value.get()
        if af.check_pattern(patterncall) and af.check_param(form, nb_line, size_line):
            path = filedialog.askdirectory(title="Select a Destination Folder")
            if path[len(path) - 1] == "/":
                path += "output.txt"
            else:
                path += "/output.txt"
            if form == "rect":
                command = "./setting_up " +  nb_line + " " + size_line + " " + patterncall + " 1>" + path
                subprocess.run(command, shell = True, executable="/bin/bash")
                print(command)
                print(": done")
            if form == "square":
                command = "./setting_up " + nb_line + " " + patterncall + " 1>" + path
                subprocess.run(command, shell = True, executable="/bin/bash")
                print(command)
                print(": done")

    pattern = tk.StringVar()
    entrypattern = tk.Entry(frameBas , bg=palette[2], fg=palette[3], textvariable=pattern, justify='center')
    entrypattern.place(rely =  0.59, relx = 0.1 , relheight = 0.1 , relwidth = 0.8)
    entrypattern.insert(tk.END, "Pattern")

    buttonBack = tk.Button(frameBas, image=imageback,borderwidth=0,relief="flat" ,bg = palette[1], activebackground = palette[1], activeforeground= palette[3], command=goback)
    buttonBack.place(rely=0.8,relx=0.1, relwidth= 0.05)
    buttonPage2 = tk.Button(frameBas, text= "Generate", fg = palette[3], bg = palette[0], relief= "groove", activebackground = palette[0], activeforeground= palette[3], command=generate)
    buttonPage2.place(rely=0.7,relx=0.4, relwidth= 0.2)

    selected_value = tk.StringVar()
    combobox = ttk.Combobox(frameBas, values= ("rect", "square"), textvariable=selected_value,  font=('actual', 12))
    combobox.place(relwidth=0.2, relx=0.2, rely=0.42)
    combobox.set("Type")
    combobox.bind('<<ComboboxSelected>>', callback)

    width_value = tk.StringVar()
    width = ttk.Spinbox(frameBas, from_=0, to= 10000, wrap= True, textvariable=width_value, font=('actual', 12))
    width.place(relwidth=0.15, relx=0.7, rely=0.42)
    width.set(0)
    width.state(['disabled'])

    height_value = tk.StringVar()
    height = ttk.Spinbox(frameBas, from_=0, to= 10000, wrap= True, textvariable=height_value, font=("actual", 12))
    height.place(relwidth= 0.15, relx= 0.5, rely= 0.42)
    height.set(0)
    height.state(['disabled'])
    
    frame.mainloop()