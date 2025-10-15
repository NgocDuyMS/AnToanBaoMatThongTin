#include <iostream>
#include <string>



using namespace std;


string substitutionEncrypt(const string& plaintext, const string& key) {
    // Kiểm tra xem khóa có đủ 26 ký tự không
    if (key.length() != 26) {
        throw invalid_argument("Loi: Khoa phai co du 26 ky tu.");
    }

    string ciphertext = ""; // Chuỗi kết quả

    // Duyệt qua từng ký tự của văn bản gốc
    for (char p_char : plaintext) {
        // Kiểm tra ký tự có phải là chữ cái in hoa không
        if (p_char >= 'A' && p_char <= 'Z') {
            // Xác định vị trí của ký tự trong bảng chữ cái (từ 0 đến 25)
            // Ví dụ: 'A' -> 0, 'B' -> 1, 'C' -> 2, ...
            int position = p_char - 'A';

            // Lấy ký tự tại vị trí tương ứng trong chuỗi key để thay thế
            // Đây chính là logic cốt lõi của mã hóa thay thế
            ciphertext += key[position];
        } else {
            // Nếu ký tự không phải chữ in hoa (ví dụ: số, dấu cách), giữ nguyên
            ciphertext += p_char;
        }
    }

    return ciphertext;
}

int main() {
  
  
    string message = "ONESWALLOWDOESNT";
    string key = "WBXGIHOVSYMFUAKZJNCPQLTRED";

    try {
        string encryptedMessage = substitutionEncrypt(message, key);

        // In kết quả ra màn hình
        cout << "Van ban goc (M): " << message << endl;
        cout << "Khoa         (K): " << key << endl;
        cout << "-------------------------------------" << endl;
        cout << "Van ban ma hoa (C): " << encryptedMessage << endl;


    return 0;
}
