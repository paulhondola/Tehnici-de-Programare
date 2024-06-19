import matplotlib.pyplot as plt
import numpy as np

file = open("gauss.txt", "r")

title_line = file.readline()
title_line = file.readline()
numbers = file.readlines()

arr = []

for num in numbers:
	arr.append(float(num))

plt.hist(arr)
plt.show()

file.close()
