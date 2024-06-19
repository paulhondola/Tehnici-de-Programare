import matplotlib.pyplot as plt
import numpy as np

# GAUSSIAN DISTRIBUTION

file = open("gauss.txt", "r")
title_line = file.readline()
title_line = file.readline()
numbers = file.readlines()

arr = []
for num in numbers:
	arr.append(float(num))

gauss_plot = plt.figure(1)
plt.title("GAUSSIAN DISTRIBUTION")
plt.hist(arr)

file.close()

# POISSON DISTRIBUTION

file = open("poisson.txt", "r")
title_line = file.readline()
title_line = file.readline()
numbers = file.readlines()

arr = []
for num in numbers:
	arr.append(float(num))

poisson_plot = plt.figure(2)
plt.title("POISSON DISTRIBUTION")
plt.hist(arr)

plt.show()

file.close()
