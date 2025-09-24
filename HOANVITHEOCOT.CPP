#include<bits/stdc++.h>
using namespace std ; 
string chuan_hoa(string p , int row , int k){
	int s = row * k ;
	while(p.size() < s)
	{
		p += "x" ;
	}
	return p ;
}


int main()
{
     string p ; 
     cout << "Plaintext: " ; 
     getline(cin , p) ;
	 int n = p.size() ; 
     int k ; cin >> k  ; //Khoa k , so cot cua ma tran ma hoa
     int row = (n+k-1) / k ; //So hang cua ma tran
     char x[row][k] ;
     p = chuan_hoa(p,row,k) ;
     int cnt = 0 ;
     for(int i = 0 ; i < row  ;i++)
     {
     	for(int j = 0 ; j < k ;j++)
     	{
     	   x[i][j] = p[cnt++] ;
		}
	 }
	 cout << "Van ban sau ma hoa:" ; 
	 for(int j = 0 ; j < k ;j++)
	 {
	 	for(int i = 0 ; i< row ; i++)
	 	{
	 		cout << x[i][j] ;
		}
	 }
	 cout <<endl ;
	 cout << "Van ban giai ma:" ;
	 for(int i = 0 ; i < row ; i++)
	 {
	 	for(int j = 0 ; j< k ;j++)
	 	{
	 	    if(x[i][j] != 'x'){
	 	    	cout << x[i][j] ;
			 }
		}
	 }
	 

	 
        	
	
}
