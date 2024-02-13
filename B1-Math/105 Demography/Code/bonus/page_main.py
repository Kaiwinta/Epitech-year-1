##
## EPITECH PROJECT, 2023
## B-CPE-110-STG-1-1-settingup-titouan.pradoura
## File description:
## test_bash.py
##

import tkinter as tk
import all_function as af
import page_choice

def main():
    palette = af.PALETTE

    window = tk.Tk()
    window.geometry("800x450+{}+{}".format(int(window.winfo_screenwidth()/2 - 400), int(window.winfo_screenheight()/2 - 225)))
    window.title('𝟏𝟎𝟓 𝐃𝐞𝐦𝐨𝐠𝐫𝐚𝐩𝐡𝐲')
    window.resizable(False,False)
    window.bind('<Escape>',lambda e: window.destroy())
    window.configure(bg=palette[2])

    page1(window)
    window.mainloop()

def page1(frame):
    palette = af.PALETTE

    imagerat = af.resize_image("Images/rat.png", 100, 100)
    imageduck = af.resize_image("Images/duck.png", 259//2, 224//2)
    imagestonks = af.resize_image("Images/stonks.png", 40, 40)
    
    frameTitre = tk.Frame(frame,bg = palette[0])
    frameTitre.place(rely=0.08, relx=0.1, relheight= 0.1 , relwidth=0.8)
    
    labelImagestonks = tk.Label(frameTitre, image = imagestonks, bg=palette[0])
    labelImagestonks.place(relx=0, rely=0)
    
    labelTitre = tk.Label(frameTitre, fg = palette[3], text="𝟏𝟎𝟓 𝐃𝐞𝐦𝐨𝐠𝐫𝐚𝐩𝐡𝐲",font=("actual",16), bg = palette[0])
    labelTitre.place(rely=0.5,relx=0.5, anchor= "center")
    
    frameBas = tk.Frame(frame , bg=palette[1])
    frameBas.place(rely=0.2,relx=0.1,relheight=0.72,relwidth=0.8)

    def gotodemo():
        af.delete(frame)
        page_choice.page_demo(frame)
        return 0

    labelImagerat = tk.Label(frameBas,image = imagerat, bg=palette[1])
    labelImagerat.place(relx=0.8, rely=0.7)
    labelImageduck = tk.Label(frameBas,image = imageduck, bg=palette[1])
    labelImageduck.place(relx=0.05, rely=0.74)

    textebienvenu = "Welcome,\nthis application is an interface for \nthe Epitech Demography."

    labelDesciption = tk.Label(frameBas,fg = palette[3], bg = palette[1],text=textebienvenu ,font =("actual",12))
    labelDesciption.place(relheight=0.4,relwidth=0.80,relx=0.1,rely=0.05)

    buttonPage2 = tk.Button(frameBas, command=gotodemo, text="Go to demography", bg = palette[0], fg= palette[3])
    buttonPage2.place(rely=0.55,relx=0.4, relwidth=0.2)

    frame.mainloop()

if __name__ == "__main__":
    main()