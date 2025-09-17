#include<bits/stdc++.h>

using namespace std ;
#define ll long long 
int mod = 26 ;
int mod1 = 10 ;
char dich_chuyen(char c , ll k)
{
    if(isalpha(c))
    {
        if(isupper(c))
        {
            c = 'A' + ((c - 'A' + k) % mod + mod) % mod;
        }
        if(islower(c))
        {
            c = 'a' + ((c - 'a' +k) % mod +mod) % mod ;
        }
    }
    if(isdigit(c))
    {
        c = '0' + ((c - '0' +k) % mod1 +mod1) %mod1 ;
    }
    return c ;
}


int main()
{
    string p ;
    cout << "Nhập văn bản :" ;
    getline(cin , p) ;
    string kq = "" ;
    vector<ll> khoa ;
    string kq2 = "" ;
    for(int i = 0 ; i<p.size() ; i++)
    {
         ll k ; 
         cout << "Nhập khóa:" ;
         cin >> k ;
         kq += dich_chuyen(p[i] ,k) ;
         khoa.push_back(k) ;
    }
    cout <<"Văn bản mã hóa: "<<kq<<endl ;
    for(int i = 0 ; i < p.size() ; i++)
    {
         kq2 += dich_chuyen(kq[i] ,-khoa[i]) ; 
    }
    cout << "Giải mã: " << kq2 ;



}
