#include <iostream>
#include <cmath>

// Function to calculate signum of a number
template <typename T>
int signum(T val) {
    return (T(0) < val) - (val < T(0));
}

int main() {
    // Constants and initial values
    double R[] = {95.9, 95.9, 305, 305, 305, 3097, 3097, 3097, 305, 611, 305, 9294, 3097};
    double Q[] = {250, 275, 200, 150, 25, 50, 50, 25, 75, 100, 25, 25, 75};
    double Qc[4] = {1, 1, 1, 1};  // Correction factors for each loop
    double H[4] = {0};  // Head losses for each loop
    double tolerance = 0.01;  // Convergence criterion

    while (fabs(Qc[0]) >= tolerance || fabs(Qc[1]) >= tolerance || fabs(Qc[2]) >= tolerance || fabs(Qc[3]) >= tolerance) {
        // Calculate head losses for each loop
        H[0] = signum(Q[1]) * R[1] * pow(Q[1], 2) + signum(Q[4]) * R[4] * pow(Q[4], 2) + signum(Q[7]) * R[7] * pow(Q[7], 2) - signum(Q[9]) * R[9] * pow(Q[9], 2) - signum(Q[0]) * R[0] * pow(Q[0], 2);
        H[1] = signum(Q[2]) * R[2] * pow(Q[2], 2) + signum(Q[3]) * R[3] * pow(Q[3], 2) + signum(Q[5]) * R[5] * pow(Q[5], 2) - signum(Q[4]) * R[4] * pow(Q[4], 2);
        H[2] = -signum(Q[5]) * R[5] * pow(Q[5], 2) + signum(Q[6]) * R[6] * pow(Q[6], 2) - signum(Q[8]) * R[8] * pow(Q[8], 2) - signum(Q[7]) * R[7] * pow(Q[7], 2);
        H[3] = signum(Q[9]) * R[9] * pow(Q[9], 2) + signum(Q[8]) * R[8] * pow(Q[8], 2) + signum(Q[12]) * R[12] * pow(Q[12], 2) + signum(Q[11]) * R[11] * pow(Q[11], 2) - signum(Q[10]) * R[10] * pow(Q[10], 2);

        // Calculate deltaQ for each loop
        double sum1 = 2 * (fabs(R[1] * Q[1]) + fabs(R[4] * Q[4]) + fabs(R[7] * Q[7]) + fabs(R[9] * Q[9]) + fabs(R[0] * Q[0]));
        double sum2 = 2 * (fabs(R[2] * Q[2]) + fabs(R[3] * Q[3]) + fabs(R[5] * Q[5]) + fabs(R[4] * Q[4]));
        double sum3 = 2 * (fabs(R[5] * Q[5]) + fabs(R[6] * Q[6]) + fabs(R[8] * Q[8]) + fabs(R[7] * Q[7]));
        double sum4 = 2 * (fabs(R[9] * Q[9]) + fabs(R[8] * Q[8]) + fabs(R[12] * Q[12]) + fabs(R[11] * Q[11]) + fabs(R[10] * Q[10]));

        Qc[0] = H[0] / sum1;
        Qc[1] = H[1] / sum2;
        Qc[2] = H[2] / sum3;
        Qc[3] = H[3] / sum4;

        Q[0] = Q[0] + signum(Q[0]) * Qc[0];
        Q[1] = Q[1] - signum(Q[1]) * Qc[0];
        Q[2] = Q[2] - signum(Q[2]) * Qc[1];
        Q[3] = Q[3] - signum(Q[3]) * Qc[1];
        Q[4] = Q[4] - signum(Q[4]) * Qc[0] + signum(Q[4]) * Qc[2];
        Q[5] = Q[5] - signum(Q[5]) * Qc[1] + signum(Q[5]) * Qc[3];
        Q[6] = Q[6] - signum(Q[6]) * Qc[2];
        Q[7] = Q[7] - signum(Q[7]) * Qc[0] + signum(Q[7]) * Qc[3];
        Q[8] = Q[8] + signum(Q[8]) * Qc[2] - signum(Q[8]) * Qc[3];
        Q[9] = Q[9] + signum(Q[9]) * Qc[0] - signum(Q[9]) * Qc[3];
        Q[10] = Q[10] + signum(Q[10]) * Qc[3];
        Q[11] = Q[11] - signum(Q[11]) * Qc[3];
        Q[12] = Q[12] - signum(Q[12]) * Qc[3];

        //print value of Qc[1]
        std::cout<<Qc[2]<<'\n';
    }

    // Print the final Q values
    for (int i = 0; i < 13; ++i) {
        std::cout << "Q[" << i << "] = " << Q[i] << std::endl;
    }

    return 0;
}