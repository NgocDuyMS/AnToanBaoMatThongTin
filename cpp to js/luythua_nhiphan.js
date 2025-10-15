const mod = 6221;

function luy_thua(a, b) {
    if (b === 0) {
        return 1;
    }
    let x = luy_thua(a, Math.floor(b / 2));
    if (b % 2 === 0) {
        return (x % mod * x % mod) % mod;
    } else {
        return ((x % mod * x % mod) % mod * (a % mod)) % mod;
    }
}

function main(a, m) {
    return luy_thua(a, m);
}

// Xuất hàm main để sử dụng ở nơi khác
module.exports = { main };