#include <bits/stdc++.h>
using namespace std;

long long p = 7057, a = 5, x = 463, k = 973, y, M = 402;

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n, long long mod) {
    return power(n, mod - 2, mod);
}


void encrypt(long long msg, long long &c1, long long &c2) {
    c1 = power(a, k, p);
    long long K = power(y, k, p);
    c2 = (msg * K) % p;
}

long long decrypt(long long c1, long long c2) {
    long long K = power(c1, x, p);
    long long K_inv = modInverse(K, p);
    long long msg = (c2 * K_inv) % p;
    return msg;
}

int main(){
	

	cout<<"\nGiai doan : SINH KHOA"<<endl;
	y = power(a,x,p);
	cout<<"y = a^x mod p = " << y;	
	cout<<"\nKhoa cong khai Kp = (p,a,y) = (" << p << "," << a << "," << y << ")";
	cout<<"\nKhoa bi mat Ks = x = " << x <<endl;
	
	cout<<"\nGiai doan : MA HOA";
	long long c1, c2;
	encrypt(M, c1, c2);
	long long temp = power(y,k,p);
	cout<<"\nKhoa ma hoa K = y^k mod p = " <<temp;
	cout<<"\nC1 = a^k mod p = " << c1;
	cout<<"\nC2 = K*M mod p = " << c2;
	cout<<"\nBan ma C = (C1,C2) = (" << c1 << "," << c2 << ")"<<endl;
	
	
	cout << "\nGiai doan : GIAI MA" << endl;
	long long Mnew = decrypt(c1,c2);
	cout << "Khoa phien K = C1^x mod p = " << power(c1,x,p) << endl;
    cout << "Nghich dao cua K = K^-1 mod p = " << modInverse(power(c1,x,p), p) << endl;
    cout << "Giai ma M = C2 * K^-1 mod p = " << Mnew << endl;

}

