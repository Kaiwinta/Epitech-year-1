##
## EPITECH PROJECT, 2023
## test
## File description:
## all_function.py
##

from PIL import Image, ImageTk

PALETTE = ["#090C9B","#3D52D5","#DCC48E","#B4C5E4"]

def resize_image(image_path, new_width, new_height):
    original_image = Image.open(image_path)
    resized_image = original_image.resize((new_width, new_height), Image.LANCZOS)
    return ImageTk.PhotoImage(resized_image)

def delete(frame):
    for widget in frame.winfo_children():
        widget.destroy()
