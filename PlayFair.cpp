#include<bits/stdc++.h>
using namespace std;

string s;
char a[6][6]; 
map<char, pair<int,int>> pos; 
string tmp = "abcdefghiklmnopqrstuvwxyz";


void taoBang(string key) {
    map<char,int> mark;
    for (auto c : tmp) mark[c] = 1;

    // xóa trùng trong key
    string used = "";
    for (auto c : key) {
        if (c == 'j') c = 'i';
        if (mark[c]) {
            used += c;
            mark[c] = 0;
        }
    }
    // thêm ký tự còn thiếu
    for (auto c : tmp) {
        if (mark[c]) {
            used += c;
            mark[c] = 0;
        }
    }

    used = "0" + used;

    // điền vào bảng
    int cnt = 1;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            a[i][j] = used[cnt];
            pos[a[i][j]] = {i, j};
            cnt++;
        }
    }
}

// chuẩn hóa văn bản: loại ký tự lạ, gộp i/j, thêm x nếu trùng
string chuanHoa(string t) {
    string res = "";
    for (char c : t) {
        if (isalpha(c)) {
            c = tolower(c);
            if (c == 'j') c = 'i';
            res += c;
        }
    }
    // chèn x nếu có cặp trùng
    string fixed = "";
    for (int i = 0; i < res.size(); i++) {
        fixed += res[i];
        if (i + 1 < res.size() && res[i] == res[i+1]) {
            fixed += 'x';
        }
    }
    if (fixed.size() % 2 != 0) fixed += 'x';
    return fixed;
}

// mã hóa 1 cặp
string maHoaCap(char x, char y) {
    auto [r1, c1] = pos[x];
    auto [r2, c2] = pos[y];
    string res = "";
    if (r1 == r2) {
        res += a[r1][(c1 % 5) + 1];
        res += a[r2][(c2 % 5) + 1];
    } else if (c1 == c2) {
        res += a[(r1 % 5) + 1][c1];
        res += a[(r2 % 5) + 1][c2];
    } else {
        res += a[r1][c2];
        res += a[r2][c1];
    }
    return res;
}

// giải mã 1 cặp
string giaiMaCap(char x, char y) {
    auto [r1, c1] = pos[x];
    auto [r2, c2] = pos[y];
    string res = "";
    if (r1 == r2) {
        res += a[r1][(c1 + 3) % 5 + 1];
        res += a[r2][(c2 + 3) % 5 + 1];
    } else if (c1 == c2) {
        res += a[(r1 + 3) % 5 + 1][c1];
        res += a[(r2 + 3) % 5 + 1][c2];
    } else {
        res += a[r1][c2];
        res += a[r2][c1];
    }
    return res;
}


string maHoa(string t) {
    string res = "";
    for (int i = 0; i < t.size(); i += 2) {
        res += maHoaCap(t[i], t[i+1]);
    }
    return res;
}


string giaiMa(string t) {
    string res = "";
    for (int i = 0; i < t.size(); i += 2) {
        res += giaiMaCap(t[i], t[i+1]);
    }
    return res;
}

int main() {
    cout << "Nhap tu khoa: ";
    getline(cin, s);
    taoBang(s);

   
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    string t;
    cout << "\nNhap van ban: ";
    getline(cin, t);

    string fixed = chuanHoa(t);
    cout << "Van ban sau khi chuan hoa: " << fixed << "\n";

    string cipher = maHoa(fixed);
    cout << "Ban ma: " << cipher << "\n";

    string plain = giaiMa(cipher);
    cout << "Giai ma: " << plain << "\n";

    return 0;
}
