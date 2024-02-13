##
## EPITECH PROJECT, 2023
## B-MAT-100-STG-1-1-105demography-titouan.pradoura
## File description:
## parse.py
##

import csv
import sys

def parse_file():
    file_path = '105demography_data.csv'
    with open(file_path, newline='') as csvfile:
        spamreader = csv.reader(csvfile, delimiter=';', quotechar='"')
        list_country = []
        next(spamreader)
        for row in spamreader:
            list_country.append(row)
    return list_country


def check_country(code_list):
    list_country = parse_file()
    list_pop = []
    list_name = []

    try:
        for country in code_list:
            founded = 0
            for i in list_country:
                if i[1] == country:
                    founded = 1
                    list_name.append(i[0])
                    if not list_pop:
                        list_pop = i[2:]
                        for t in range(len(list_pop)):
                            if not list_pop[t]:
                                list_pop[t] = '0'
                            list_pop[t] = int(list_pop[t]) 
                    else:
                        for t in range(len(list_pop)):
                            if not i[t + 2]:
                                i[t + 2] = '0'
                            list_pop[t] = int(list_pop[t]) + int(i[t + 2])
            if founded == 0:
                sys.exit(84)
    except:
        sys.exit(84)
    if len(list_name) == 0:
        sys.exit(84)
    list_years = []
    list_name.sort()
    for i in range(1960, 2018):
        list_years.append(i)
    return (list_name, list_years, list_pop)

def get_country_start_with(value):
    list_code = []
    list_country = parse_file()
    for country in list_country:
        if country[1][0:len(value)] == value:
            list_code.append(country[1])
    return list_code