function phi(n) {
    let kq = n;
    let can = Math.floor(Math.sqrt(n));
    for (let p = 2; p <= can; p++) {
        if (n % p === 0) {
            while (n % p === 0) {
                n /= p;
            }
            kq -= Math.floor(kq / p);
        }
    }
    if (n > 1) kq -= Math.floor(kq / n);
    return kq;
}

function chia_du(n, m) {
    let res = 0;
    for (let c of n) {
        res = res * 10 + (c.charCodeAt(0) - '0'.charCodeAt(0));
        res %= m;
    }
    return res;
}

function main(m, n) {
    let p = phi(n);
    let kq = chia_du(m, p);
    return kq;
}

// Xuất hàm main để sử dụng ở nơi khác
module.exports = { main };