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
            c = '0' +((c - '0' + k) % mod1 + mod1) % mod1 ;
        }
    return c ;
}
string ma_hoa(string t , ll k)
{
     for(auto &c:t){
         c = dich_chuyen(c , k) ;
     }
     return t ;
}
string giai_ma(string t , ll k)
{
    return ma_hoa(t , -k) ;
}

int main()
{
    string s ;
     ll k ; 
     cout <<"Nhap van ban can ma hoa:" ;
     getline(cin,s) ;
     cout <<"Nhap khoa k :" ;
     cin >> k ;

     cout << "Sau ma hoa:"; 
     cout << ma_hoa(s ,  k) ;
     cout << endl ;
     cout << "Giai ma:" ;
     cout << giai_ma(ma_hoa(s,k) ,k) ;

}
