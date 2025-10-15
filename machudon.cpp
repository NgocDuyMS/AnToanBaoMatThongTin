#include <iostream>
#include <string>

using namespace std;

string substitutionEncrypt(const string& plaintext, const string& key) {
    string ciphertext = ""; // Chuỗi kết quả

    // Duyệt qua từng ký tự của văn bản gốc
    for (char p_char : plaintext) {
        // Kiểm tra ký tự có phải là chữ cái in hoa không
        if (p_char >= 'A' && p_char <= 'Z') {
            // Xác định vị trí của ký tự trong bảng chữ cái (từ 0 đến 25)
            int position = p_char - 'A';

            // Lấy ký tự tại vị trí tương ứng trong chuỗi key để thay thế
            ciphertext += key[position];
        } else {
            // Nếu ký tự không phải chữ in hoa, giữ nguyên
            ciphertext += p_char;
        }
    }
    return ciphertext;
}

int main() {
    string message = "ONESWALLOWDOESNT";
    string key = "WBXGIHOVSYMFUAKZJNCPQLTRED";


    string encryptedMessage = substitutionEncrypt(message, key);

    cout << "Van ban goc (M): " << message << endl;
    cout << "Khoa         (K): " << key << endl;
    cout << "-------------------------------------" << endl;
    cout << "Van ban ma hoa (C): " << encryptedMessage << endl;

    return 0;
}
