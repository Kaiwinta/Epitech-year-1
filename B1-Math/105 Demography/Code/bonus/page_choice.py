##
## EPITECH PROJECT, 2023
## B-MAT-100-STG-1-1-105demography-titouan.pradoura
## File description:
## demo.py
##

import tkinter as tk
import all_function as af
import parse
import page_result

def page_demo(frame):
    global save
    save = []
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
    
    bot_frame = tk.Frame(frame , bg=palette[1])
    bot_frame.place(rely=0.2,relx=0.1,relheight=0.72,relwidth=0.8)

    labelImagerat = tk.Label(bot_frame,image = imagerat, bg=palette[1])
    labelImagerat.place(relx=0.8, rely=0.7)
    labelImageduck = tk.Label(bot_frame,image = imageduck, bg=palette[1])
    labelImageduck.place(relx=0.05, rely=0.74)

    def actualize(event):
        value = entry_country.get()

        if event.keysym == 'Return':
            if len(value) > 0:
                to_add = parse.get_country_start_with(value)
                if len(to_add) != 1:
                    print("Wrong country code")
                else:
                    list_already_added = list_added_country.get(0, tk.END)
                    if to_add[0] not in list_already_added:
                        list_added_country.insert(tk.END, to_add[0])
            return 0

        if event.keysym != "BackSpace" and event.keysym != "Tab" and event.keysym != 'Return':
            value += event.char

        if event.keysym == "BackSpace":
            value = value[:-1]
        
        list_country.delete(0, tk.END)
        if len(value) > 0:
            liste_to_add = parse.get_country_start_with(value)
            for country in liste_to_add:
                list_country.insert(tk.END, country)

    def save_added(event):
        global save
        save = list(list_added_country.get(0, tk.END))

    def delete_actualize(event):
        value = entry_delete.get()

        if event.keysym == 'Return':
            if len(value) > 0:
                to_add = []
                for index in range(len(save)):
                    if value == save[index][:len(value)]:
                        to_add.append(index)
                if len(to_add) != 1:
                    print("Wrong country code")
                else:
                    save.pop(to_add[0])
                    list_added_country.delete(to_add[0], to_add[0] + 1)
                return 0

        if event.keysym != "BackSpace" and event.keysym != "Tab" and event.keysym != 'Return':
            value += event.char

        if event.keysym == "BackSpace":
            value = value[:-1]
        
        list_added_country.delete(0, tk.END)
        if len(value) > 0:
            list_to_add = []
            for item in save:
                if value == item[:len(value)]:
                    list_to_add.append(item)
            for country in list_to_add:
                list_added_country.insert(tk.END, country)
        else:
            for country in save:
                list_added_country.insert(tk.END, country)


    def add_selected(event):
        for i in list_country.curselection():
            list_already_added = list_added_country.get(0, tk.END)
            if list_country.get(i) not in list_already_added:
                list_added_country.insert(tk.END, list_country.get(i))

    def delete_selected(event):
        for i in list_added_country.curselection():
            list_added_country.delete(i, i + 1)

    label_add = tk.Label(bot_frame , bg= palette[3] ,text='Add country' )
    label_add.place(rely=0.19 , relheight= 0.05 , relx = 0.2 , relwidth= 0.2)
    entry_country = tk.Entry(bot_frame, background=palette[1])
    entry_country.place(rely=0.25,relx=0.2, relwidth=0.2, relheight = 0.1)
    entry_country.bind('<Key>', lambda event: actualize(event))
    list_country = tk.Listbox(bot_frame , bg=palette[3])
    list_country.place(rely=0.4,relx=0.2, relwidth=0.2, relheight = 0.3)
    list_country.bind('<Double-Button-1>', lambda event: add_selected(event))

    label_del = tk.Label(bot_frame, bg= palette[3] ,text='Already added')
    label_del.place(rely=0.19 , relheight= 0.05 , relx = 0.6 , relwidth= 0.2) 
    entry_delete = tk.Entry(bot_frame, background=palette[1])
    entry_delete.place(rely=0.25,relx=0.6, relwidth=0.2, relheight = 0.1)
    entry_delete.bind('<FocusIn>', lambda event: save_added(event))
    entry_delete.bind('<Key>', lambda event: delete_actualize(event))
    list_added_country = tk.Listbox(bot_frame , bg=palette[3])
    list_added_country.place(rely=0.4,relx=0.6, relwidth=0.2, relheight = 0.3)
    list_added_country.bind('<Double-Button-1>', lambda event: delete_selected(event))

    def execute():
        global save
        save_added(None)
        if len(save) > 0:
            af.delete(frame)
            page_result.page(frame, save)
        return 0

    button_execute = tk.Button(bot_frame, command=execute, text="Execute Simulation", bg = palette[0], fg= palette[3])
    button_execute.place(rely=0.75,relx=0.4, relwidth=0.2)

    frame.mainloop()