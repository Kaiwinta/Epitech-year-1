##
## EPITECH PROJECT, 2023
## 109_temp
## File description:
## parse.py
##

import csv
import sys, os

def parse_file(filename):
    if not os.path.exists(filename) or not filename.lower().endswith('.csv'):
        sys.exit(84)
    with open(filename, newline='') as csvfile:
        spamreader = csv.reader(csvfile, delimiter=';', quotechar='"')
        list_vol = []
        list_ph = []
        for row in spamreader:
            if (len(row) != 2):
                sys.exit(84)
            try:
                list_vol.append(float(row[0]))
                if (list_vol[-1] < 0.0):
                    sys.exit(84)
                list_ph.append(float(row[1]))
                if (list_ph[-1] < 0.0):
                    sys.exit(84)
            except ValueError:
                sys.exit(84)
    if (len(list_vol) < 5):
        sys.exit(84)
    return (list_vol, list_ph)