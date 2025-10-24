#include <iostream>


long long powMod(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
       
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
       
        base = (base * base) % mod;
       
        exp /= 2;
    }
    return res;
}


long long modInverse(long long n, long long mod) {
    return powMod(n, mod - 2, mod);
}

int main() {
    // -----------------------------------------------------------------
    // PH?N 0: KH?I T?O CÁC THAM S? CÔNG KHAI T? Ð? BÀI
    // -----------------------------------------------------------------
    long long p = 83;
    long long q = 41;
    long long h = 32;

    // Khóa bí m?t c?a An (xA) và s? ng?u nhiên (k)
    long long xA = 2; // Khóa bí m?t c?a An
    long long k = 2;  // S? ng?u nhiên An ch?n cho ch? ký này

    // Gi? s? giá tr? mã bam c?a tin nh?n M là H(M)
    // Ð? bài không cho, ta gi? s? H(M) = 10 d? minh h?a phép tính
    long long H_M = 10;

    std::cout << "Cac gia tri ban dau:\n";
    std::cout << "p = " << p << ", q = " << q << ", h = " << h << "\n";
    std::cout << "Khoa bi mat xA = " << xA << ", so ngau nhien k = " << k << "\n";
    std::cout << "Gia su ma bam H(M) = " << H_M << "\n";
    std::cout << "------------------------------------------------\n\n";

    // -----------------------------------------------------------------
    // TÍNH TOÁN THAM S? CÔNG KHAI 'g'
    // g = h^((p-1)/q) mod p
    // -----------------------------------------------------------------
    long long exp_g = (p - 1) / q; // (83 - 1) / 41 = 82 / 41 = 2
    long long g = powMod(h, exp_g, p); // g = 32^2 mod 83
    std::cout << "Buoc 1: Tinh tham so cong khai g\n";
    std::cout << "g = h^((p-1)/q) mod p = 32^(" << exp_g << ") mod 83 = " << g << "\n\n";

    // -----------------------------------------------------------------
    // a) TÍNH KHÓA CÔNG KHAI yA C?A AN
    // yA = g^(xA) mod p
    // -----------------------------------------------------------------
    long long yA = powMod(g, xA, p); // yA = 28^2 mod 83
    std::cout << "a) Khoa cong khai cua An (yA):\n";
    std::cout << "yA = g^(xA) mod p = " << g << "^" << xA << " mod " << p << " = " << yA << "\n";
    std::cout << "=> Vay, khoa cong khai cua An la: yA = " << yA << "\n";
    std::cout << "------------------------------------------------\n\n";


    // -----------------------------------------------------------------
    // b) TÍNH CH? KÝ S? (r, s) C?A AN
    // -----------------------------------------------------------------
    std::cout << "b) Chu ky so cua An cho ban tin M (r, s):\n";

    // Tính r
    // r = (g^k mod p) mod q
    long long r = powMod(g, k, p); // r_temp = 28^2 mod 83 = 37
    r = r % q;                     // r = 37 mod 41 = 37
    std::cout << "Tinh r = (g^k mod p) mod q = (" << g << "^" << k << " mod " << p << ") mod " << q << " = " << r << "\n";

    // Tính s
    // s = [k^-1 * (H(M) + xA * r)] mod q
    
    // 1. Tìm k^-1 mod q (ngh?ch d?o c?a k=2 mod q=41)
    long long k_inv = modInverse(k, q); // 2^-1 mod 41 = 21
    std::cout << "Tinh k^-1 mod q = " << k << "^-1 mod " << q << " = " << k_inv << "\n";

    // 2. Tính H(M) + xA * r
    long long s_temp = (H_M + xA * r); // 10 + 2 * 37 = 10 + 74 = 84
    
    // 3. Tính s = (k^-1 * s_temp) mod q
    long long s = (k_inv * s_temp) % q; // (21 * 84) mod 41 = 1764 mod 41 = 1
                                       // Ho?c: (21 * (84 mod 41)) mod 41 = (21 * 2) mod 41 = 42 mod 41 = 1
    std::cout << "Tinh s = [k^-1 * (H(M) + xA * r)] mod q\n";
    std::cout << "s = [" << k_inv << " * (" << H_M << " + " << xA << " * " << r << ")] mod " << q << " = " << s << "\n";

    std::cout << "=> Vay, chu ky so la: (r, s) = (" << r << ", " << s << ")\n";
    std::cout << "------------------------------------------------\n\n";


    // -----------------------------------------------------------------
    // c) CÁCH BA XÁC MINH CH? KÝ
    // Ba nh?n du?c (M, r, s) và bi?t các khóa công khai (p, q, g, yA)
    // -----------------------------------------------------------------
    std::cout << "c) Cach Ba xac minh chu ky so:\n";
    std::cout << "Ba (nguoi nhan) thuc hien cac buoc sau:\n";

    // 1. Tính w = s^-1 mod q
    long long w = modInverse(s, q); // w = 1^-1 mod 41 = 1
    std::cout << "1. Tinh w = s^-1 mod q = " << s << "^-1 mod " << q << " = " << w << "\n";

    // 2. Tính u1 = (H(M) * w) mod q
    long long u1 = (H_M * w) % q; // u1 = (10 * 1) mod 41 = 10
    std::cout << "2. Tinh u1 = (H(M) * w) mod q = (" << H_M << " * " << w << ") mod " << q << " = " << u1 << "\n";

    // 3. Tính u2 = (r * w) mod q
    long long u2 = (r * w) % q; // u2 = (37 * 1) mod 41 = 37
    std::cout << "3. Tinh u2 = (r * w) mod q = (" << r << " * " << w << ") mod " << q << " = " << u2 << "\n";

    // 4. Tính v = [(g^u1 * yA^u2) mod p] mod q
    long long v1 = powMod(g, u1, p);      // v1 = g^u1 mod p = 28^10 mod 83 = 30
    long long v2 = powMod(yA, u2, p);     // v2 = yA^u2 mod p = 37^37 mod 83 = 4
    long long v_temp = (v1 * v2) % p;     // v_temp = (30 * 4) mod 83 = 120 mod 83 = 37
    long long v = v_temp % q;             // v = 37 mod 41 = 37
    std::cout << "4. Tinh v = [(g^u1 * yA^u2) mod p] mod q\n";
    std::cout << "   - Tinh g^u1 mod p = " << g << "^" << u1 << " mod " << p << " = " << v1 << "\n";
    std::cout << "   - Tinh yA^u2 mod p = " << yA << "^" << u2 << " mod " << p << " = " << v2 << "\n";
    std::cout << "   - Tinh v = [(" << v1 << " * " << v2 << ") mod " << p << "] mod " << q << " = " << v << "\n";

    // 5. So sánh v và r
    std::cout << "5. So sanh v va r:\n";
    std::cout << "   v = " << v << "\n";
    std::cout << "   r = " << r << "\n";

    if (v == r) {
        std::cout << "=> Ket qua: v == r. Chu ky hop le!.\n";
    } else {
        std::cout << "=> Ket qua: v != r. Chu ky KHONG hop le!.\n";
    }

    return 0;
}
