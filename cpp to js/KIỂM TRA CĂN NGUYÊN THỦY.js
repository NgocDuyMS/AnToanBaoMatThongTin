function luy_thua(a, b, mod) {
    if (b === 0) {
        return 1;
    }
    let x = luy_thua(a, Math.floor(b / 2), mod);
    if (b % 2 === 0) {
        return ((x % mod) * (x % mod)) % mod;
    } else {
        return (((x % mod) * (x % mod)) % mod * (a % mod)) % mod;
    }
}

function phi(n) {
    let kq = n;
    for (let p = 2; p * p <= n; p++) {
        if (n % p === 0) {
            while (n % p === 0) {
                n /= p;
            }
            kq -= Math.floor(kq / p);
        }
    }
    if (n > 1) {
        kq -= Math.floor(kq / n);
    }
    return kq;
}

function phan_tich(phi) {
    let factor = [];
    for (let p = 2; p * p <= phi; p++) {
        if (phi % p === 0) {
            factor.push(p);
            while (phi % p === 0) {
                phi /= p;
            }
        }
    }
    if (phi > 1) {
        factor.push(phi);
    }
    return factor;
}

function check(factor, a, fi, mod) {
    for (let it of factor) {
        let b = Math.floor(fi / it);
        if (luy_thua(a, b, mod) === 1) {
            return false;
        }
    }
    return true;
}

function main(a, n) {
    let fi = phi(n);
    let factor = phan_tich(fi);
    let isPrimitiveRoot = check(factor, a, fi, n);
    return isPrimitiveRoot
        ? `${a} là căn nguyên thủy của ${n}`
        : `${a} không là căn nguyên thủy của ${n}`;
}

// Xuất hàm main để sử dụng ở nơi khác
module.exports = { main };