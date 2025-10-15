function phi(n) {
    let kq = n;
    for (let p = 2; p * p <= n; p++) {
        if (n % p === 0) {
            while (n % p === 0) n /= p;
            kq -= Math.floor(kq / p);
        }
    }
    if (n > 1) kq -= Math.floor(kq / n);
    return kq;
}

function main(n) {
    return phi(n);
}

// Xuất hàm main để sử dụng ở nơi khác
module.exports = { main };