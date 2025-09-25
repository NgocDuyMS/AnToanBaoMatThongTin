#include <bits/stdc++.h>
using namespace std;

string chuan_hoa(string p, int row, int k) {
    int s = row * k;
    while (p.size() < s) {
        p += "x"; //them ki tu neu chua du so luong kis tu cua ma tran ma hoa
    }
    return p;
}

void nhap(vector<vector<char>> &kq, int row, int k, string p) {
    int cnt = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < k; j++) {
            kq[i][j] = p[cnt++];
        }
    }
}
void ma_hoa(vector<vector<char>> kq , int row , int k )
{
	for(int j = 0 ; j<k ; j++)
	{
		for(int i = 0 ; i< row ;i++)
		{
			cout << kq[i][j] ;
		}
	}
}
void giai_ma(vector<vector<char>> kq , int row , int k )
{
	for(int i = 0 ; i<row ; i++)
	{
		for(int j = 0 ; j< k ;j++)
		{
			cout << kq[i][j] ;
		}
	}
	
}

int main() {
    string p;
    cout << "Plaintext: ";
    getline(cin, p);

    int n = p.size();
    int k;
    cout << "Nhap key: ";
    cin >> k;

    int row = (n + k - 1) / k; 
    vector<vector<char>> x(row, vector<char>(k));

    p = chuan_hoa(p, row, k);
    nhap(x, row, k, p);
    cout << "Ma hoa: " ;
    ma_hoa(x , row , k) ;
	cout << endl ;
	cout <<"Giai ma: " ; 
    giai_ma(x , row ,k) ;

   
}
