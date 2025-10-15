const mod = 287;

function luy_thua(a, b) {
    if (b === 0) return 1;
    let x = luy_thua(a, Math.floor(b / 2));
    if (b % 2 === 0) {
        return ((x % mod) * (x % mod)) % mod;
    } else {
        return ((((x % mod) * (x % mod)) % mod) * (a % mod)) % mod;
    }
}

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

function gcd(a, b) {
    if (b === 0) return a;
    return gcd(b, a % b);
}

function check(a, n) {
    return gcd(a, n) === 1;
}

function main(a, m) {
    if (check(a, mod)) {
        return luy_thua(a, m % phi(mod));
    } else {
        return luy_thua(a, m);
    }
}

// Xuất hàm main để sử dụng ở nơi khác
module.exports = { main };