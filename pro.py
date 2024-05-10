# Functions for critical depth calculation
def calculate_critical_depth(q, b, m, y):
    numerator = (b + m*y) * y
    numerator = pow(numerator, 3/2)

    denominator = pow(b + 2*m*y, 1/2)

    g = 10
    return numerator / denominator - q/(g**0.5)

def calculate_derivative_critical(b, m, y):
    u = b*y + m*(y**2)
    du = 3/2 * pow(u, 1/2) * (b + 2*m*y)
    u = pow(u, 3/2)

    v = b + 2*m*y
    v = pow(v, 1/2)
    dv = m / v

    return (v*du - u*dv) / v**2

# Functions for normal depth calculation
def calculate_normal_depth(q, s, n, b, m, y):
    numerator = (b + m*y) * y
    numerator = pow(numerator, 5/3) * (s ** 0.5)

    denominator = pow(b + 2*y*((1+m)**0.5), 2/3) * n

    return numerator / denominator - q

def calculate_derivative_normal(s, n, b, m, y):
    k = s**0.5 / n
    
    u = b*y + m*(y**2)
    du = 5/3 * pow(u, 2/3) * (b + 2*m*y)
    u = pow(u, 5/3)

    v = b + 2*y*((1+m**2)**0.5)
    dv = 2/3 * pow(v, -1/3) * (2*((1+m**2)**0.5))
    v = pow(v, 2/3)

    return k * (v*du - u*dv) / v**2

# Using the Newton-Raphson iterative algorithm for calculation of critical and normal depths
def solve_newton_raphson(q, s, n, b, m):
    max_iterations = 1000
    tol = 0.01  # The covergence tolerance

    y_critical_prev = 5
    #calcualtion for the critical value
    for _ in range(max_iterations):
        y_critical = y_critical_prev - calculate_critical_depth(q, b, m, y_critical_prev) / calculate_derivative_critical(b, m, y_critical_prev)
        diff = abs(y_critical_prev - y_critical)

        if diff < tol:
            break

        y_critical_prev = y_critical
    
    y_normal_prev = 10 
    #calcualtion for the normal value
    for _ in range(max_iterations):
        y_normal = y_normal_prev - calculate_normal_depth(q, s, n, b, m, y_normal_prev) / calculate_derivative_normal(s, n, b, m, y_normal_prev)
        diff = abs(y_normal_prev - y_normal)

        if diff < tol:
            break

        y_normal_prev = y_normal

    return y_normal, y_critical

# Constants
q = 37.5  # flow rate for 21CE3009
l = 4000  # the length of the channel 
b = 10  # Bottom width (for both the trapezoidal and rectangular cross-sections)
m = 1.5  # slope (for both the trapezoidal and triangular cross-sections)
s = 0.001  # the slope of Longitudinal Bed 
n = 0.02  # Manning's coefficient of friction


#Printing the final reults

# Triangular cross section
n_depth, c_depth = solve_newton_raphson(q, s, n, 0, m)
print('Results for the triangular cross section')
print(f'Critical Depth = {c_depth}, Normal Depth= {n_depth}\n')

# Trapezoidal cross section
n_depth, c_depth = solve_newton_raphson(q, s, n, b, m)
print('Results for the trapezoidal cross section')
print(f'Critical Depth = {c_depth}, Normal Depth= {n_depth}\n')

# Rectangular cross section
n_depth, c_depth = solve_newton_raphson(q, s, n, b, 0)
print('Results for the rectangular cross section')
print(f'Critical Depth = {c_depth}, Normal Depth= {n_depth}\n')