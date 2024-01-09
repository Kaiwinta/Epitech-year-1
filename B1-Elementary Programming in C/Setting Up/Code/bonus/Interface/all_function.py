##
## EPITECH PROJECT, 2023
## test
## File description:
## all_function.py
##

import tkinter as tk
from tkinter import ttk
from tkinter import filedialog
from PIL import Image, ImageTk

def resize_image(image_path, new_width, new_height):
    original_image = Image.open(image_path)
    resized_image = original_image.resize((new_width, new_height), Image.LANCZOS)
    return ImageTk.PhotoImage(resized_image)

def delete(frame):
    for widget in frame.winfo_children():
        widget.destroy() 

def check_pattern(pattern):
    if len(pattern) <= 0:
        return 0
    for i in pattern:
        if i != '.' and i != 'o':
            return 0
    return 1

def check_param(form, nb_line, size_line):
    if form == 'square':
        if int(nb_line) > 0:
            return 1
        else:
            return 0
    elif form == 'rect':
        if int(nb_line) > 0 and int(size_line) > 0:
            return 1
        else:
            return 0
    return 0