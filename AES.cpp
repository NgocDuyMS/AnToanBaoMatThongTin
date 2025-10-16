#include<bits/stdc++.h>
using namespace std ;
#define ll long long
//Bai 1 : Chia khoa thanh 4 word w1 w2 w3 w4
// B?ng S-box CHU?N cho mã hóa
unsigned char sbox[16][16] = {
    {0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76},
    {0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0},
    {0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15},
    {0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75},
    {0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84},
    {0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf},
    {0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8},
    {0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2},
    {0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73},
    {0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb},
    {0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79},
    {0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08},
    {0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a},
    {0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e},
    {0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf},
    {0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16}
};
// B?ng h?ng s? vòng Rcon
unsigned int Rcon[10] = {
    0x01000000, 0x02000000, 0x04000000, 0x08000000, 0x10000000,
    0x20000000, 0x40000000, 0x80000000, 0x1b000000, 0x36000000
};
vector<string> chia_khoa(string K)
{
	vector<string> word ; 
	for(int i = 0  ; i<K.size() ;i+=8)
	{
		string tmp = K.substr(i ,8) ;
		word.push_back(tmp) ;
	}
	return word ;
}
string rot_word(string w3)
{
	return w3.substr(2) + w3.substr(0, 2);
}
int hex_char_to_int(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else {
        return toupper(c) - 'A' + 10;
    }
}
string sub_word(string w) {
    string result = "";
    for (int i= 0; i < w.length(); i += 2) {
        int row = hex_char_to_int(w[i]);
        int col = hex_char_to_int(w[i + 1]);
        unsigned char new_byte_val = sbox[row][col];
        stringstream ss;
        ss << hex << setw(2) << setfill('0') << (int)new_byte_val;
        result += ss.str();
    }
    return result;
}
string XOR_Rcon(string sw, int round_index) {
    uint32_t sw_val = stoul(sw, nullptr, 16);
    uint32_t result_val = sw_val ^ Rcon[round_index];
    stringstream ss_res;
    ss_res << hex << setw(8) << setfill('0') << result_val;
    return ss_res.str();
}
string XOR_words(string w1, string w2) {
    uint32_t val1 = stoul(w1, nullptr, 16);
    uint32_t val2 = stoul(w2, nullptr, 16);
    uint32_t result_val = val1 ^ val2;
    stringstream ss;
    ss << hex << setw(8) << setfill('0') << result_val;
    return ss.str();
}
vector<string> khoa(string xcsw ,vector<string> word)
{
	 vector<string> kq ;
	 string w4 = XOR_words(word[0], xcsw) ; // Ðã s?a th? t? cho kh?p công th?c
	 kq.push_back(w4) ;
	 string w5 = XOR_words(word[1], w4) ;
	 kq.push_back(w5) ;
	 string w6 = XOR_words(word[2], w5) ;
	 kq.push_back(w6) ;
	 string w7 = XOR_words(word[3], w6) ;
	 kq.push_back(w7) ;
	 return kq ;
}
#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

using namespace std;

void AddRoundKey(unsigned char state[4][4], const vector<string>& round_key) {
    // L?p qua 4 c?t (c = 0, 1, 2, 3)
    for (int c = 0; c < 4; ++c) {
        string key_word_str = round_key[c]; // L?y word c?a khóa, vd: "AADE12F3"
        
        // L?p qua 4 hàng trong m?i c?t (r = 0, 1, 2, 3)
        for (int r = 0; r < 4; ++r) {
            // 1. C?t 2 ký t? hex (1 byte) t? word c?a khóa
            // Ví d?: "AA", "DE", "12", "F3"
            string key_byte_str = key_word_str.substr(r * 2, 2);
            
            // 2. Chuy?n 2 ký t? hex dó thành giá tr? byte
            unsigned char key_byte_val = stoul(key_byte_str, nullptr, 16);
            
            // 3. Th?c hi?n XOR
            state[r][c] ^= key_byte_val;
        }
    }
}
// Hàm SubBytes phiên b?n don gi?n, không dùng d?ch bit
void SubBytes(unsigned char state[4][4]) {
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            // 1. L?y giá tr? byte hi?n t?i
            unsigned char byte_val = state[r][c];

            // 2. Chuy?n byte dó thành chu?i hex 2 ký t? (ví d?: 0xCF -> "CF")
            stringstream ss;
            ss << hex << setw(2) << setfill('0') << (int)byte_val;
            string hex_str = ss.str();

            // 3. Dùng 2 ký t? hex làm ch? s? hàng và c?t
            int row = hex_char_to_int(hex_str[0]);
            int col = hex_char_to_int(hex_str[1]);

            // 4. Tra S-box và c?p nh?t l?i state
            state[r][c] = sbox[row][col];
        }
    }
}
// Hàm th?c hi?n ShiftRows
void ShiftRows(unsigned char state[4][4]) {
    unsigned char temp;

    // Hàng 1: d?ch vòng trái 1 byte
    temp = state[1][0];
    state[1][0] = state[1][1];
    state[1][1] = state[1][2];
    state[1][2] = state[1][3];
    state[1][3] = temp;

    // Hàng 2: d?ch vòng trái 2 byte
    temp = state[2][0];
    state[2][0] = state[2][2];
    state[2][2] = temp;
    temp = state[2][1];
    state[2][1] = state[2][3];
    state[2][3] = temp;

    // Hàng 3: d?ch vòng trái 3 byte (tuong duong d?ch ph?i 1 byte)
    temp = state[3][3];
    state[3][3] = state[3][2];
    state[3][2] = state[3][1];
    state[3][1] = state[3][0];
    state[3][0] = temp;
}
// Hàm ph? th?c hi?n phép nhân trong tru?ng GF(2^8)
unsigned char gmul(unsigned char a, unsigned char b) {
    unsigned char p = 0;
    for (int i = 0; i < 8; i++) {
        if (b & 1) {
            p ^= a;
        }
        bool hi_bit_set = (a & 0x80);
        a <<= 1;
        if (hi_bit_set) {
            a ^= 0x1b; // Ða th?c x^8 + x^4 + x^3 + x + 1
        }
        b >>= 1;
    }
    return p;
}

// Hàm th?c hi?n MixColumns
void MixColumns(unsigned char state[4][4]) {
    unsigned char temp[4];
    for (int c = 0; c < 4; ++c) {
        // Sao chép c?t ra bi?n t?m
        for (int r = 0; r < 4; ++r) {
            temp[r] = state[r][c];
        }

        // Th?c hi?n phép nhân ma tr?n (dã du?c d?nh nghia s?n)
        state[0][c] = gmul(2, temp[0]) ^ gmul(3, temp[1]) ^ temp[2] ^ temp[3];
        state[1][c] = temp[0] ^ gmul(2, temp[1]) ^ gmul(3, temp[2]) ^ temp[3];
        state[2][c] = temp[0] ^ temp[1] ^ gmul(2, temp[2]) ^ gmul(3, temp[3]);
        state[3][c] = gmul(3, temp[0]) ^ temp[1] ^ temp[2] ^ gmul(2, temp[3]);
    }
}
void in(unsigned char state[4][4])
{
    for (int i = 0; i < 4; i++) // Vòng l?p hàng
    {
        for (int j = 0; j < 4; j++) // Vòng l?p c?t
        {
            // Thêm d?nh d?ng hexa và ép ki?u sang int
            cout << hex <<uppercase<< setw(2) << setfill('0') << (int)state[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
  	string K = "AADE12F39F579A5A49845A7797FE9146" ;
  	string M = "BC3034B5D3677672E290C28DC16922FB" ;
  	
    //Bai 1 :Chia khoa thanh 4 word w0 w1 w2 w3
  	cout<<"Bai 1:\n" ;
    vector<string> word ;
    word = chia_khoa(K) ;
    for(auto it : word)
    {
    	cout<< it << endl ;
	}
	
    //Bai 2:dich vong trai 1 byte doi voi w3
	cout<<"Bai 2:\n" ;
	string R3 ; // rot word 3
	R3 = rot_word(word[3]) ;
    transform(R3.begin(), R3.end(), R3.begin(), ::toupper);
	cout << R3 << endl ;
	
    //Bai 3:thay the tung byte trong rw = bang S-box
	cout << "Bai 3:\n" ;
	string SW = sub_word(R3) ;
    transform(SW.begin(), SW.end(), SW.begin(), ::toupper);
	cout << SW << endl ;
	
    //Bai 4 :
	cout << "Bai 4:\n" ;
	string XCSW = XOR_Rcon(SW ,0) ;
    transform(XCSW.begin(), XCSW.end(), XCSW.begin(), ::toupper);
	cout << XCSW << endl ;
	
    //Bai 5:Tinh khoa K1 = (w4 , w5 , w6 , w7)
	cout << "\nBai 5:\n" ;
	vector<vector<string>> key ;
    vector<string> K1 = khoa(XCSW, word);
	key.push_back(K1) ;
	for(auto it : key[0]) // Ch? in K1
	{
        transform(it.begin(), it.end(), it.begin(), ::toupper);
        cout << it << endl;
	}

    // === BAT DAU PHAN CODE MOI ===
    
    for (int i = 1; i < 10; i++) {
        vector<string> prev_key = key.back(); // L?y khóa con tru?c dó (K1, K2,...)
        
        // T?o word t?m t? word cu?i (w[3]) c?a b? khóa tru?c
        string temp = sub_word(rot_word(prev_key[3]));
        
        // XOR word t?m v?i Rcon tuong ?ng
        string xcsw_loop = XOR_Rcon(temp, i);
        
        // Tính 4 word m?i và luu vào vector new_key
        vector<string> new_key;
        new_key.push_back(XOR_words(prev_key[0], xcsw_loop));
        new_key.push_back(XOR_words(prev_key[1], new_key[0]));
        new_key.push_back(XOR_words(prev_key[2], new_key[1]));
        new_key.push_back(XOR_words(prev_key[3], new_key[2]));
        
        // Thêm b? khóa m?i vào danh sách t?ng
        key.push_back(new_key);
    }


    cout << "\n===== DANH SACH CAC KHOA CON (K1 - K10)=====" << endl;
    for (size_t i = 0; i < key.size(); ++i) {
        cout << "K" << (i + 1) << ": ";
        for (string& k_word : key[i]) {
            transform(k_word.begin(), k_word.end(), k_word.begin(), ::toupper);
            cout << k_word << " ";
        }
        cout << endl;
    }
    //Bai 6
    // CÁCH S?A L?I
   unsigned char state[4][4];
    for (int j = 0; j < 4; j++) // C?t
    {
      for (int i = 0; i < 4; i++) // Hàng
       {
        int index = j * 4 + i;
        // L?y chu?i con t? v? trí dã tính
        string tmp = M.substr(index * 2, 2);
        state[i][j] = stoul(tmp, nullptr, 16);
       }
    }
    AddRoundKey(state ,word) ;
    in(state) ; 


    for (int round = 1; round <= 9; ++round) {
        SubBytes(state);
        ShiftRows(state);
        MixColumns(state);
        AddRoundKey(state, key[round - 1]); // key[0] là K1, key[1] là K2,...
    }

    // G?n gi?ng vòng chính nhung KHÔNG CÓ MixColumns
    cout << "\n--- Vong Cuoi Cung (10) ---" << endl;
    SubBytes(state);
    ShiftRows(state);
    AddRoundKey(state, key[9]); // key[9] là K10

    cout << "\n\n===== CIPHERTEXT (KET QUA MA HOA) =====" << endl;
    in(state); 
	
	return 0;
}
