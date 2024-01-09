##
## EPITECH PROJECT, 2023
## test
## File description:
## page_opening.py
##

import tkinter as tk
from tkinter import ttk
from tkinter import filedialog
import all_function as af
import subprocess
import os

def page_opening(frame, palette, page1):

    current_dir = os.path.dirname(os.path.realpath(__file__))
    imagerat = af.resize_image("Images/rat.png", 100, 100)
    imagefrog = af.resize_image("Images/frog.png", 40, 40)
    imageback = af.resize_image("Images/button.png", 25, 25)
    textwelcome = "Welcome to the files opener part.\n\nChoose the files that you want to analyze\nAnd then select the path of the output.\nThe file need to follow the setting up rules in order to have an output."
    textpath = tk.StringVar()
    textpath.set("Path")
    text_dest = tk.StringVar()
    text_dest.set("Destination")

    frameTitre = tk.Frame(frame,bg = palette[0])
    frameTitre.place(rely=0.08, relx=0.1, relheight= 0.1 , relwidth=0.8)
    frameBas = tk.Frame(frame , bg=palette[1])
    frameBas.place(rely=0.2,relx=0.1,relheight=0.72,relwidth=0.8)
    
    labelTitre = tk.Label(frameTitre, fg = palette[3], text="Open Files",font=("actual",16), bg = palette[0])
    labelTitre.place(rely=0.5,relx=0.5, anchor= "center")
    labelImagefrog = tk.Label(frameTitre, image = imagefrog, bg=palette[0])
    labelImagefrog.place(relx=0, rely=0)
    labelImagerat = tk.Label(frameBas,image = imagerat, bg=palette[1])
    labelImagerat.place(relx=0.8, rely=0.7)
    labelDesciption = tk.Label(frameBas,fg = palette[3], bg = palette[1],text=textwelcome ,font =("actual",12))
    labelDesciption.place(relheight=0.4,relwidth=1,relx=0,rely=0.05)

    def goback():
        af.delete(frameBas)
        page1(frame)

    def choose_path():
        path = filedialog.askopenfilename(title="Select a File", filetypes=(("Text files", "*.txt"), ("All files", "*")))
        if path:
            path = os.path.relpath(path, current_dir)
            path = path[3:]
            textpath.set(path)

    def choose_dest():
        pathdest = filedialog.askdirectory(title="Select a Destination Folder")
        if pathdest:
            if pathdest[len(pathdest) - 1] == "/":
                pathdest += "output.txt"
            else:
                pathdest += "/output.txt"
            pathdest = os.path.relpath(pathdest, current_dir)
            pathdest = pathdest[3:]
            text_dest.set(pathdest)

    def solve():
        path = textpath.get()
        pathdest = text_dest.get()
        if path != "Path" and pathdest != "Destination":
            command = "./setting_up " + path + " 1>" + pathdest
            subprocess.run(command, shell = True, executable="/bin/bash")
            print(command)
            print(": done")

    labelpath = tk.Label(frameBas,fg = palette[3], bg = palette[1],textvariable=textpath ,font =("actual",8))
    labelpath.place(relheight=0.1,relwidth=0.5,relx=0,rely=0.45)
    labelDest = tk.Label(frameBas,fg = palette[3], bg = palette[1],textvariable=text_dest ,font =("actual",8))
    labelDest.place(relheight=0.1,relwidth=0.5,relx=0.5,rely=0.45)
    buttonBack = tk.Button(frameBas, image=imageback,borderwidth=0,relief="flat" ,bg = palette[1], activebackground = palette[1], activeforeground= palette[3], command=goback)
    buttonBack.place(rely=0.8,relx=0.1, relwidth= 0.05)
    buttonSolve = tk.Button(frameBas, text= "Solve", fg = palette[3], bg = palette[1], relief= "groove", activebackground = palette[0], activeforeground= palette[3], command=solve)
    buttonSolve.place(rely=0.7,relx=0.4, relwidth= 0.2)
    buttonFile= tk.Button(frameBas, text= "Update File", fg = palette[3], bg = palette[0], relief= "groove", activebackground = palette[0], activeforeground= palette[3], command=choose_path)
    buttonFile.place(rely=0.55,relx=0.15, relwidth= 0.2)
    buttonFolder = tk.Button(frameBas, text= "Update Dest", fg = palette[3], bg = palette[0], relief= "groove", activebackground = palette[0], activeforeground= palette[3], command=choose_dest)
    buttonFolder.place(rely=0.55,relx=0.65, relwidth= 0.2)

    
    frame.mainloop()