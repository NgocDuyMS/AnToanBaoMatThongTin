const mod = 26;
const bang_chu_thuong = "abcdefghijklmnopqrstuvwxyz";
const bang_chu_hoa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

function xuli() {
    let khoa = new Map();
    let cnt = 0;
    for (let x of bang_chu_thuong) {
        khoa.set(x, cnt++);
    }
    cnt = 0;
    for (let x of bang_chu_hoa) {
        khoa.set(x, cnt++);
    }
    return khoa;
}

function dich_chuyen(c, k) {
    if (/[a-zA-Z]/.test(c)) {
        if (/[A-Z]/.test(c)) {
            return String.fromCharCode('A'.charCodeAt(0) + ((c.charCodeAt(0) - 'A'.charCodeAt(0) + k) % mod + mod) % mod);
        }
        if (/[a-z]/.test(c)) {
            return String.fromCharCode('a'.charCodeAt(0) + ((c.charCodeAt(0) - 'a'.charCodeAt(0) + k) % mod + mod) % mod);
        }
    }
    return c;
}

function ma_hoa(p, k, khoa) {
    let result = "";
    for (let i = 0; i < p.length; i++) {
        result += dich_chuyen(p[i], khoa.get(k[i]));
    }
    return result;
}

function giai_ma(p, k, khoa) {
    let result = "";
    for (let i = 0; i < p.length; i++) {
        result += dich_chuyen(p[i], -khoa.get(k[i]));
    }
    return result;
}

function chuan_hoa(p, key) {
    let n = p.length;
    let m = key.length;
    
    if (m === n) {
        return key;
    } else if (m > n) {
        return key.slice(0, n);
    } else {
        let newkey = key;
        for (let i = m; i < n; i++) {
            newkey += p[(i - m) % n];
        }
        return newkey;
    }
}

function main(p, c) {
    let khoa = xuli();
    let key = chuan_hoa(p, c);
    let cipher = ma_hoa(p, key, khoa);
    let plain = giai_ma(cipher, key, khoa);
    return {
        cipherText: cipher,
        plainText: plain
    };
}

// Xuất hàm main để sử dụng ở nơi khác
module.exports = { main };