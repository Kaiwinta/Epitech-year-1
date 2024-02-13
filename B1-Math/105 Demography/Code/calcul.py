##
## EPITECH PROJECT, 2023
## B-MAT-100-STG-1-1-105demography-titouan.pradoura
## File description:
## test.py
##

def linear_least_squares_regression(X, Y):
    x_bar = sum(X) / len(X)
    y_bar = sum(Y) / len(Y)

    #Calculs for fit 1
    a = sum((xi - x_bar) * (yi - y_bar) for xi, yi in zip(X, Y)) / sum((xi - x_bar)**2 for xi in X)
    b = y_bar - a * x_bar
    Y_pred = [a * x + b for x in X]
    rmsd_Y = (sum((yi - ŷ)**2 for yi, ŷ in zip(Y, Y_pred)) / len(Y))**0.5

    #Calculs for fit 2
    c = 1 / a
    d = -b / a
    X_pred = [c * y + d for y in Y]
    rmsd_X = (sum((xi - x̂)**2 for xi, x̂ in zip(X, X_pred)) / len(X))**0.5

    correlation = sum((xi - x_bar) * (yi - y_bar) for xi, yi in zip(X, Y)) / ((sum((xi - x_bar)**2 for xi in X) * sum((yi - y_bar)**2 for yi in Y))**0.5)
    return a, b, rmsd_Y, c, d, rmsd_X, correlation


