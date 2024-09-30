#include <iostream>
#include <cmath>
long double M_PI = 3.1415926535897;
double sin_taylor(double x) {
    // Chuyen x ve khoang [-pi, pi]
    x = fmod(x, 2 * M_PI);
    if (x > M_PI) x -= 2 * M_PI;
    if (x < -M_PI) x += 2 * M_PI;

    long double sin_x = 0.0;
    long double term = x; // So hang dau tien
    int n = 1; // Chi so hang

    while (fabs(term) > 0.00001) {
        sin_x += term;
        term *= -x * x / (2 * n * (2 * n + 1)); // Cong thuc cho so hang tiep theo
        n++;
    }

    return sin_x;
}

int main() {
    long double x;
    std::cout << "Nhap gia tri x (don vi radian): ";
    std::cin >> x;

    long double result = sin_taylor(x);
    std::cout << "Gia tri cua sin(" << x << ") voi do chinh xac 0.00001 la :  " << result << "." << std::endl;

    return 0;
}
