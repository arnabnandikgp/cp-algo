import numpy as np

# Constants and initial values
R = np.array([96.8, 96.8, 306, 306, 306, 3098, 3098, 3098, 306, 612, 306, 9295, 3098])
Q = np.array([250, 275, 200, 150, 25, 50, 50, 25, 75, 100, 25, 25, 75])
Qc = np.ones(4)  # Correction factors for each loop
H = np.zeros(4)  # Head losses for each loop
tolerance = 0.01  # Convergence criterion

while np.any(np.abs(Qc) >= tolerance):
    # Calculate head losses for each loop
    H[0] = np.sign(Q[1]) * R[1] * Q[1]**2 + np.sign(Q[4]) * R[4] * Q[4]**2 + np.sign(Q[7]) * R[7] * Q[7]**2 - np.sign(Q[9]) * R[9] * Q[9]**2 - np.sign(Q[0]) * R[0] * Q[0]**2
    H[1] = np.sign(Q[2]) * R[2] * Q[2]**2 + np.sign(Q[3]) * R[3] * Q[3]**2 + np.sign(Q[5]) * R[5] * Q[5]**2 - np.sign(Q[4]) * R[4] * Q[4]**2
    H[2] = -np.sign(Q[5]) * R[5] * Q[5]**2 + np.sign(Q[6]) * R[6] * Q[6]**2 - np.sign(Q[8]) * R[8] * Q[8]**2 - np.sign(Q[7]) * R[7] * Q[7]**2
    H[3] = np.sign(Q[9]) * R[9] * Q[9]**2 + np.sign(Q[8]) * R[8] * Q[8]**2 + np.sign(Q[12]) * R[12] * Q[12]**2 + np.sign(Q[11]) * R[11] * Q[11]**2 - np.sign(Q[10]) * R[10] * Q[10]**2

    # Calculate deltaQ for each loop
    sum1 = 2 * (np.abs(R[1] * Q[1]) + np.abs(R[4] * Q[4]) + np.abs(R[7] * Q[7]) + np.abs(R[9] * Q[9]) + np.abs(R[0] * Q[0]))
    sum2 = 2 * (np.abs(R[2] * Q[2]) + np.abs(R[3] * Q[3]) + np.abs(R[5] * Q[5]) + np.abs(R[4] * Q[4]))
    sum3 = 2 * (np.abs(R[5] * Q[5]) + np.abs(R[6] * Q[6]) + np.abs(R[8] * Q[8]) + np.abs(R[7] * Q[7]))
    sum4 = 2 * (np.abs(R[9] * Q[9]) + np.abs(R[8] * Q[8]) + np.abs(R[12] * Q[12]) + np.abs(R[11] * Q[11]) + np.abs(R[10] * Q[10]))

    Qc[0] = H[0] / sum1
    Qc[1] = H[1] / sum2
    Qc[2] = H[2] / sum3
    Qc[3] = H[3] / sum4

    Q[0] = Q[0] + np.sign(Q[0]) * Qc[0]
    Q[1] = Q[1] - np.sign(Q[1]) * Qc[0]
    Q[2] = Q[2] - np.sign(Q[2]) * Qc[1]
    Q[3] = Q[3] - np.sign(Q[3]) * Qc[1]
    Q[4] = Q[4] - np.sign(Q[4]) * Qc[0] + np.sign(Q[4]) * Qc[2]
    Q[5] = Q[5] - np.sign(Q[5]) * Qc[1] + np.sign(Q[5]) * Qc[3]
    Q[6] = Q[6] - np.sign(Q[6]) * Qc[2]
    Q[7] = Q[7] - np.sign(Q[7]) * Qc[0] + np.sign(Q[7]) * Qc[3]
    Q[8] = Q[8] + np.sign(Q[8]) * Qc[2] - np.sign(Q[8]) * Qc[3]
    Q[9] = Q[9] + np.sign(Q[9]) * Qc[0] - np.sign(Q[9]) * Qc[3]
    Q[10] = Q[10] + np.sign(Q[10]) * Qc[3]
    Q[11] = Q[11] - np.sign(Q[11]) * Qc[3]
    Q[12] = Q[12] - np.sign(Q[12]) * Qc[3]
