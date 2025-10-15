const mod = 26;
const mod1 = 10;

function dich_chuyen(c, k) {
    if (/[a-zA-Z]/.test(c)) {
        if (/[A-Z]/.test(c)) {
            return String.fromCharCode('A'.charCodeAt(0) + ((c.charCodeAt(0) - 'A'.charCodeAt(0) + k) % mod + mod) % mod);
        }
        if (/[a-z]/.test(c)) {
            return String.fromCharCode('a'.charCodeAt(0) + ((c.charCodeAt(0) - 'a'.charCodeAt(0) + k) % mod + mod) % mod);
        }
    }
    if (/[0-9]/.test(c)) {
        return String.fromCharCode('0'.charCodeAt(0) + ((c.charCodeAt(0) - '0'.charCodeAt(0) + k) % mod1 + mod1) % mod1);
    }
    return c;
}

function main(text, keys) {
    let kq = "";
    let kq2 = "";
    
    // Mã hóa
    for (let i = 0; i < text.length; i++) {
        kq += dich_chuyen(text[i], keys[i]);
    }
    
    // Giải mã
    for (let i = 0; i < kq.length; i++) {
        kq2 += dich_chuyen(kq[i], -keys[i]);
    }
    
    return {
        cipherText: kq,
        plainText: kq2
    };
}

// Xuất hàm main để sử dụng ở nơi khác
module.exports = { main };