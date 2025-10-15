function sang_so() {
    const maxN = 1000001;
    let sang = new Array(maxN).fill(true);
    sang[0] = sang[1] = false;
    for (let i = 2; i * i < maxN; i++) {
        if (sang[i]) {
            for (let j = i * i; j < maxN; j += i) {
                sang[j] = false;
            }
        }
    }
    return sang;
}

function gcd(a, b) {
    if (b === 0) return a;
    return gcd(b, a % b);
}

function luy_thua(a, b, mod) {
    if (b === 0) return 1;
    let x = luy_thua(a, Math.floor(b / 2), mod);
    let res = (x * x) % mod;
    if (b % 2 === 1) {
        res = (res * (a % mod)) % mod;
    }
    return res;
}

function main(a, m, n) {
    let sang = sang_so();
    
    if (gcd(a, n) === 1 && sang[n]) {
        let exp = m % (n - 1);
        let kq = luy_thua(a, exp, n);
        return `Kết quả (áp dụng định lý Fermat nhỏ): ${kq}`;
    } else {
        let kq = luy_thua(a, m, n);
        return `Kết quả (không áp dụng Fermat): ${kq}`;
    }
}

// Xuất hàm main để sử dụng ở nơi khác
module.exports = { main };