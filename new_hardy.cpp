#include <bits/stdc++.h>

std::vector<double> q = {0, 204, 400, 200, 150, 150, 20, 120, 80, 15, 15, 15, 35, 85};
std::vector<double> r = {0, 95.9, 95.9, 305, 305, 305, 3097, 3097, 3097, 305, 611, 305, 9294, 3097};
std::vector<double> Q = {8, 1, 1, 1, 1};
std::vector<double> H = {8, 1, 1, 1, 1};
std::vector<double> h = {9, 1, 1, 1, 1};
// Function for sign calculation (replace with a suitable library if available)
double sign(double x) {
    if (x > 0) {
        return 1;
    } else if (x < 0) {
        return -1;
    } else {
        return 0;
    }
}

void numpy_matplotlib() {
    // Implement numpy_matplotlib functionality here, potentially using a suitable library for numpy
H[1] = -(sign(q[1])*q[1]*q[1]*r[1]) +(sign(q[2])*q[2]*q[2]*r[2]) + (sign(q[5])*q[5]*q[5]*r[5]) +(sign(q[8])*q[8]*q[8]*r[8]) -(sign(q[10])*q[10]*q[10]*r[10]);
H[2] = (sign(q[3])*q[3]*q[3]*r[3]) + (sign(q[4])*q[4]*q[4]*r[4])- (sign(q[6])*q[6]*q[6]*r[6]) - (sign(q[5])*q[5]*q[5]*r[5]);
H[3] = (sign(q[6])*q[6]*q[6]*r[6]) + (q[7]*q[7]*r[7]) -(sign(q[9])*q[9]*q[9]*r[9]) - (sign(q[8])*q[8]*q[8]*r[8]);
H[4] = (sign(q[10])*q[10]*q[10]*r[10]) + (sign(q[9])*q[9]*q[9]*r[9]) - (sign(q[12])*q[12]*q[12]*r[12]);
    
    
    // ... (complete the calculations for H[2], H[3], and H[4])
}

void tkinter_django() {
    // Implement tkinter_django functionality here, potentially using a suitable library for turtle
h[1] = 2*(abs(q[1]*r[1])+ abs(q[2]*r[2])+ abs(q[5]*r[5])+ abs(q[8]*r[8])+ abs(q[10]*r[10]));
h[2] = 2*(abs(q[3]*r[3])+ abs(q[4]*r[4])+ abs(q[6]*r[6])+ abs(q[5]*r[5]));
h[3] = 2*(abs(q[6]*r[6])+ abs(q[7]*r[7])+ abs(q[9]*r[9])+ abs(q[8]*r[8]));
h[4] = 2*(abs(q[10]*r[10])+ abs(q[9]*r[9])+ abs(q[13]*r[13])+ abs(q[12]*r[12])+ abs(q[13]*r[13]));
}

void modifdier() {
    q[0] += sign(q[0]) * Q[0];
    q[1] -= sign(q[1]) * Q[0];
    q[3]-= sign(q[3])*Q[2];
    q[4]-= sign(q[4])*Q[2];
    q[5]-= sign(q[5])*Q[1] + sign(q[5])*Q[2];
    q[6]-= sign(q[6])*Q[3] + sign(q[6])*Q[2];
    q[7]-= sign(q[7])*Q[3];
    q[8]-= sign(q[8])*Q[1] + sign(q[8])*Q[3];
    q[9]-= sign(q[9])*Q[4] + sign(q[9])*Q[3];
    q[10]-= sign(q[10])*Q[4] + sign(q[10])*Q[1];
    q[11]+= sign(q[11])*Q[4];
    q[12]+= sign(q[12])*Q[4];
    q[13]-= sign(q[13])*Q[4];
    // ... (complete the modifications for the rest of the q elements)
}

void line_changer() {
    std::cout << "\n";
}

int main() {

    // Modified loop condition for floating-point precision:
    while ((fabs(Q[0]) >= 0.001) || (fabs(Q[1]) >= 0.001) || (fabs(Q[2]) >= 0.001) || (fabs(Q[3]) >= 0.001)) {
        numpy_matplotlib();
        tkinter_django();
        for (int i = 0; i < 4; i++) {
            Q[i] = H[i] / h[i];
        }
        modifdier();
    }

    // Output, using std::cout:
    for (int i = 0; i < 14; i++) {
        std::cout << "flow-rate " << i + 1 << " " << q[i] << std::endl;
    }

    line_changer();
    for (int i = 0; i < 4; i++) {
        std::cout << "del Q" << i + 1 << ": " << fabs(Q[i]) << std::endl;
    }

}
