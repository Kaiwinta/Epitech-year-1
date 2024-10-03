##
## EPITECH PROJECT, 2023
## B-MAT-200-STG-2-1-110borwein-titouan.pradoura
## File description:
## compute.py
##

import math

def borwein(x :float, n: float) -> float:
    result = 1.0
    if (x == 0):
        return result
    for k in range(0, n + 1):
        result = result * (math.sin(x / (2 * k + 1)) / (x / (2 * k + 1)))
    return result

def compute_midpoint(n : int) -> float:
    result = 0.0
    for i in range(10000):
        result += 0.5 * borwein((i + 0.5) / 2, n)
    return result

def compute_trapeze(n :int) -> float:
    result = 0.25 * (1 + borwein(5000, n))
    for i in range(1, 10000):
        result += 0.5 * borwein(i / 2, n)
    return result

def compute_simpson(n :int) -> float:
    result = 0.5 / 6 * (1 + borwein(5000, n) + 4 * borwein(0.25, n))
    for i in range(1, 10000):
        result += (2 * borwein(i / 2, n) + 4 * borwein(i / 2 + 0.25, n)) * 0.5 / 6
    return result

def compute_dif(value :float, index :int) -> list:
    result = []
    if index == 0:
        result.append("Midpoint:")
    elif index == 1:
        result.append("\nTrapezoidal:")
    elif index == 2:
        result.append("\nSimpson:")
    result.append(value)
    result.append(math.fabs((math.pi / 2) - value))
    return result