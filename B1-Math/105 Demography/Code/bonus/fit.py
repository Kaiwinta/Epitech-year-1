##
## EPITECH PROJECT, 2024
## B-MAT-100-STG-1-1-105demography-titouan.pradoura
## File description:
## 105demography
##

import parse, calcul

def get_fit(list_code):
    value = []
    input = parse.check_country(list_code)
    ax, bx, rmsd_Y, ay, by, rmsd_X, correlation = calcul.linear_least_squares_regression(input[1], input[2])
    value.append([ax / 1000000, bx / 1000000, rmsd_Y / 1000000,  (ax * 2050 + bx) / 1000000])
    ax, bx, rmsd_Y, ay, by, rmsd_X, correlation = calcul.linear_least_squares_regression(input[2], input[1])
    value.append([ax * 1000000 , bx , rmsd_X / 1000000,  (ay * 2050 + by) / 1000000])
    value.append([correlation])
    return value
