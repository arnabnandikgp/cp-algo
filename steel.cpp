import numpy as np
# Constants
initial_curvature = 0.01
yield_stress = 250
E = 200000
# Initial curvature assumption (in m^-1)
# Yield stress of the material (in MPa)
# Modulus of elasticity (in MPa)
yield_strain = yield_stress / E
A = [860.6, 110, 110, 110, 110, 110, 110, 110, 110, 860.6]
#
Cross-sectional areas of different sections (in mm^2)
# Lists to store calculated values
curvatures = []
moments = []
# Iterating over a range of curvature values
for i in np.linspace(0, 1, num=10000):
curvature = 0.1 + i
# Incremental curvature starting from initial
curvature (in m^-1)
curvatures.append(curvature)
R = 1 / curvature
# Radius of curvature (in meters)
outermost_strain = 100 / (R * 1000)
# Strain in the outermost fiber
(y=100mm) (in strain units)
y = [90, 70, 50, 30, 10, 10, 30, 50, 70, 90]
# Distances of centers
of different sections from the neutral axis (in mm)
# Checking if strain in outermost fiber exceeds 0.014
if outermost_strain > 0.014:
print("The value of curvature is:", curvature)
print("The strain in outermost fiber is:", outermost_strain)
break
else:
strain = []
# Calculating strains for each section
for j in range(5):