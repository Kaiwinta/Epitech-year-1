##
## EPITECH PROJECT, 2023
## B-MAT-200-STG-2-1-109titration-titouan.pradoura
## File description:
## calcul.py
##

import math

def equilavence_one(list_derive, list_vol, disp):
    id_max = 0
    for i in range(1, len(list_derive)):
        if list_derive[i] > list_derive[id_max]:
            id_max = i
    if (disp):
        print(f"\nEquivalence point at {list_vol[id_max]:.1f} ml")
    return id_max

def calcul_slope(ph1, ph2, vol1, vol2):
    temp = (ph2 - ph1) / (vol2 - vol1)
    return temp

def derive(next_vol, next_ph, vol, ph, prec_vol, prec_ph):
    slope1 = calcul_slope(next_ph, ph, next_vol, vol)
    weighted1 = slope1 * (vol - prec_vol) / ((next_vol - vol) + (vol - prec_vol))
    slope2 = calcul_slope(ph, prec_ph, vol, prec_vol)
    weighted2 = slope2 * (next_vol - vol) / ((next_vol - vol) + (vol - prec_vol))
    return (weighted1 + weighted2)

def compute_derive(list_vol, list_ph, sec):
    list_deriv = [0]
    i = 1
    if (sec):
        print("\nSecond derivative:")
    else:
        print("Derivative:")
    while i < len(list_ph) - 1 - sec:
        tmp = derive(list_vol[i + 1 + sec], list_ph[i + 1 + sec], list_vol[i + sec], list_ph[i + sec], list_vol[i - 1 + sec], list_ph[i - 1 + sec])
        list_deriv.append(tmp)
        print(f"{list_vol[i + sec]:.1f} ml -> {list_deriv[i]:.2f}")
        i += 1
    if not sec:
        equilavence_one(list_deriv, list_ph, 1)
    return list_deriv

def compute_slope_change(slope1, slope2, key, list_vol):
    slope_change = (slope2 - slope1)
    slope_change /= (10 * (list_vol[key] - list_vol[key - 1]))
    return slope_change

def update_derivatives(list_deriv, slope_change, equi_index, list_vol):
    if math.fabs(list_deriv[1]) > math.fabs(list_deriv[2]) and equi_index + 3 < len(list_vol):
        list_deriv[1] = list_deriv[2]
        list_deriv[4] = list_deriv[0]
    list_deriv[2] += slope_change
    list_deriv[0] += 0.1

def display_estimed(list_deriv, list_vol, equi_index, slope_change):
    print("\nSecond derivative estimated:")
    while list_deriv[0] - 0.05 < list_vol[equi_index]:
        print(f"{list_deriv[0]:.1f} ml -> {list_deriv[2]:.2f}")
        update_derivatives(list_deriv, slope_change, equi_index, list_vol)

def second_estimed(deriv, list_vol):
    equi_index = equilavence_one(deriv, list_vol, 0)
    recursive_vol = list_vol[equi_index]
    equi_vol= list_vol[equi_index - 1]
    list_deriv = [equi_vol]

    if not equi_index - 2 < 0:
        slope1 = derive(list_vol[equi_index], deriv[equi_index], list_vol[equi_index - 1], deriv[equi_index - 1], list_vol[equi_index - 2], deriv[equi_index - 2])
    else:
        slope1 = 0
    list_deriv.append(slope1)
    list_deriv.append(slope1)

    slope2 = derive(list_vol[equi_index + 1], deriv[equi_index + 1], list_vol[equi_index], deriv[equi_index], list_vol[equi_index - 1], deriv[equi_index - 1])
    list_deriv.append(slope2)
    slope_change = compute_slope_change(slope1, slope2, equi_index, list_vol)
    list_deriv.append(recursive_vol)

    display_estimed(list_deriv, list_vol, equi_index, slope_change)
    compute_last_segment(list_deriv, deriv, list_vol, equi_index)

def compute_last_segment(list_deriv, deriv, list_vol, equi_index):
    actual_vol = list_deriv[0]
    actual_ph = list_deriv[1]
    slope1 = list_deriv[2]
    slope2 = list_deriv[3]
    recursive_vol = list_deriv[4]
    
    result = 0
    if equi_index + 3 >= len(deriv):
        result = -slope2 / 10
    else:
        slope1 = derive(list_vol[equi_index + 2], deriv[equi_index + 2], list_vol[equi_index + 1], deriv[equi_index + 1], list_vol[equi_index], deriv[equi_index])
        result = (slope1 - slope2)
        result /= (10 * (list_vol[equi_index + 1] - list_vol[equi_index]))
    slope2 += result

    for _ in range(int((list_vol[equi_index + 1] - actual_vol) / 0.1) + 1):
        print(f"{actual_vol:.1f} ml -> {slope2:.2f}")
        slope2 += result
        actual_vol += 0.1
        if math.fabs(actual_ph) > math.fabs(slope2) and equi_index + 3 < len(list_vol):
            recursive_vol = actual_vol
    print(f"\nEquivalence point at {recursive_vol - 0.1:.1f} ml")