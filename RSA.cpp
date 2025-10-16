#include <bits/stdc++.h>+

using namespace std;

// Hàm kiểm tra số nguyên tố (kiểm tra Miller-Rabin đơn giản hóa)
bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// Hàm tìm ước chung lớn nhất (GCD) sử dụng thuật toán Euclid
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Hàm tính (a * b) % mod để tránh tràn số
long long multiply(long long a, long long b, long long mod) {
    long long res = 0;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1) res = (res + a) % mod;
        a = (a * 2) % mod;
        b /= 2;
    }
    return res;
}

// Hàm tính (a^b) % mod bằng thuật toán bình phương và nhân
long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = multiply(res, base, mod);
        base = multiply(base, base, mod);
        exp /= 2;
    }
    return res;
}

// Hàm tìm nghịch đảo modular d sao cho (e * d) % phi_n = 1
long long modInverse(long long e, long long phi_n) {
    long long m0 = phi_n, t, q;
    long long x0 = 0, x1 = 1;
    if (phi_n == 1) return 0;
    while (e > 1) {
        q = e / m0;
        t = m0;
        m0 = e % m0, e = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += phi_n;
    return x1;
}

// Hàm tạo khóa
void generateKeys(long long &n, long long &e, long long &d) {
    long long p = 47, q = 53;
    e = 71;
    
    cout << "Chon hai so nguyen to:" << endl;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;

    n = p * q;
    cout << "n = p * q = " << n << endl;

    long long phi_n = (p - 1) * (q - 1);
    cout << "phi(n) = " << phi_n << endl;
    
    cout << "Khoa cong khai Kp = (e, n) = (" << e << ", " << n << ")" << endl;

    d = modInverse(e, phi_n);
    cout << "Khoa bi mat Ks = (d, n) = (" << d << ", " << n << ")" << endl;
}

// Hàm mã hóa
long long encrypt(long long message, long long e, long long n) {
    return power(message, e, n);
}

// Hàm giải mã
long long decrypt(long long encrypted_message, long long d, long long n) {
    return power(encrypted_message, d, n);
}

int main() {
    long long n, e, d;

    // Tạo khóa
    cout << "Giai doan : KHOI TAO KHOA  " << endl;
    generateKeys(n, e, d);

    // Nhập thông điệp cần mã hóa (phải là một số)
    long long message;
    cout << "Nhap thong diep (so) can ma hoa: ";
    cin >> message;

    if (message >= n) {
        cout << "Loi: Thong diep phai nho hon n (" << n << ")." << endl;
        return 1;
    }

    // Mã hóa
    cout << "\nGiai doan : MA HOA " << endl;
    long long encrypted_message = encrypt(message, e, n);
    cout << "Thong diep ban dau: " << message << endl;
    cout << "Ma hoa C = M^e mod N : " << encrypted_message << endl;
    cout << endl << endl;

    // Giải mã
    cout << "Giai doan : GIAI DOAN " << endl;
    long long decrypted_message = decrypt(encrypted_message, d, n);
    cout << "Ban ma can giai ma: " << encrypted_message << endl;
    cout << "Giai ma M = C^d mod N : " << decrypted_message << endl;
    cout << endl;

    return 0;
}