##
## EPITECH PROJECT, 2023
## B-MAT-100-STG-1-1-105demography-titouan.pradoura
## File description:
## result.py
##

import tkinter as tk
import all_function as af
import fit as od
import page_choice

def page(frame, save):
    palette = af.PALETTE
    list_result = od.get_fit(save)

    imagestonks = af.resize_image("Images/stonks.png", 40, 40)
    frameTitre = tk.Frame(frame,bg = palette[0])
    frameTitre.place(rely=0.08, relx=0.1, relheight= 0.1 , relwidth=0.8)
    labelImagestonks = tk.Label(frameTitre, image = imagestonks, bg=palette[0])
    labelImagestonks.place(relx=0, rely=0)
    labelTitre = tk.Label(frameTitre, fg = palette[3], text="𝟏𝟎𝟓 𝐃𝐞𝐦𝐨𝐠𝐫𝐚𝐩𝐡𝐲",font=("actual",16), bg = palette[0])
    labelTitre.place(rely=0.5,relx=0.5, anchor= "center")
    
    bot_frame = tk.Frame(frame , bg=palette[1])
    bot_frame.place(rely=0.2,relx=0.1,relheight=0.72,relwidth=0.8)

    left_frame = tk.Frame(bot_frame , bg=palette[3])
    left_frame.place(rely=0.15,relx=0.1,relheight=0.50,relwidth=0.35)
    left_frameTitre = tk.Frame(left_frame,bg = palette[0])
    left_frameTitre.place(rely=0.08, relx=0.1, relheight= 0.15 , relwidth=0.8)
    labelTitre = tk.Label(left_frameTitre, fg = palette[3], text="Fit 1",font=("actual",16), bg = palette[0])
    labelTitre.place(rely=0.5,relx=0.5, anchor= "center")
    sign = '+'
    if list_result[0][1] < 0 :
        sign = '-'
        list_result[0][1] = list_result[0][1] * (-1)
    fit1_equation_text = f"Y = {list_result[0][0]:.2f} X {sign} {list_result[0][1]:.2f}"
    fit1_rms_text = f"RMS Deviation: {list_result[0][2]:.2f}"
    fit1_pop_text = f"Population in 2050: {list_result[0][3]:.2f}"
    label_fit1_eq = tk.Label(left_frame, bg = palette[3],text=fit1_equation_text ,font =("actual",10))
    label_fit1_eq.place(relheight=0.1,relwidth=0.80,relx=0.1,rely=0.30)
    label_fit1_rms = tk.Label(left_frame, bg = palette[3],text=fit1_rms_text ,font =("actual",10))
    label_fit1_rms.place(relheight=0.1,relwidth=0.80,relx=0.1,rely=0.50)
    label_fit1_pop = tk.Label(left_frame, bg = palette[3],text=fit1_pop_text ,font =("actual",10))
    label_fit1_pop.place(relheight=0.1,relwidth=0.80,relx=0.1,rely=0.70)

    right_frame = tk.Frame(bot_frame , bg=palette[3])
    right_frame.place(rely=0.15,relx=0.55,relheight=0.50,relwidth=0.35)
    right_frameTitre = tk.Frame(right_frame,bg = palette[0])
    right_frameTitre.place(rely=0.08, relx=0.1, relheight= 0.15 , relwidth=0.8)
    labelTitre = tk.Label(right_frameTitre, fg = palette[3], text="Fit 2",font=("actual",16), bg = palette[0])
    labelTitre.place(rely=0.5,relx=0.5, anchor= "center")
    sign = '+'
    if list_result[1][1] < 0 :
        sign = '-'
        list_result[1][1] = list_result[1][1] * (-1)
    fit2_equation_text = f"X = {list_result[1][0]:.2f} Y {sign} {list_result[1][1]:.2f}"
    fit2_rms_text = f"RMS Deviation: {list_result[1][2]:.2f}"
    fit2_pop_text = f"Population in 2050: {list_result[1][3]:.2f}"
    label_fit2_eq = tk.Label(right_frame, bg = palette[3],text=fit2_equation_text ,font =("actual",10))
    label_fit2_eq.place(relheight=0.1,relwidth=0.80,relx=0.1,rely=0.30)
    label_fit2_rms = tk.Label(right_frame, bg = palette[3],text=fit2_rms_text ,font =("actual",10))
    label_fit2_rms.place(relheight=0.1,relwidth=0.80,relx=0.1,rely=0.50)
    label_fit2_pop = tk.Label(right_frame, bg = palette[3],text=fit2_pop_text ,font =("actual",10))
    label_fit2_pop.place(relheight=0.1,relwidth=0.80,relx=0.1,rely=0.70)


    def go_back():
        af.delete(frame)
        page_choice.page_demo(frame)

    last_frame = tk.Frame(bot_frame , bg=palette[3])
    last_frame.place(rely=0.75,relx=0.1,relheight=0.20,relwidth=0.8)
    correlation_text = f"Correlation: {list_result[2][0]:.4f}"
    label_corelation = tk.Label(last_frame, bg = palette[3],text=correlation_text ,font =("actual",10))
    label_corelation.place(relheight=0.5,relwidth=0.80,relx=0.1,rely=0.25)
    button_back = tk.Button(last_frame, command=go_back, text="Go Back", bg = palette[0], fg= palette[3])
    button_back.place(rely=0.25,relx=0.7, relwidth=0.2, relheight=0.5)

    frame.mainloop()