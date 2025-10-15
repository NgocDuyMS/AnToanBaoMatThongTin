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

function ma_hoa(t, k) {
    let result = "";
    for (let c of t) {
        result += dich_chuyen(c, k);
    }
    return result;
}

function giai_ma(t, k) {
    return ma_hoa(t, -k);
}

function main(text, k) {
    let cipher = ma_hoa(text, k);
    let plain = giai_ma(cipher, k);
    return {
        cipherText: cipher,
        plainText: plain
    };
}

// Xuất hàm main để sử dụng ở nơi khác
module.exports = { main };