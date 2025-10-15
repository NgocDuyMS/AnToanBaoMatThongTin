const mod = 3739;

function gcd(a, b, x, y) {
    if (b === 0) {
        x[0] = 1;
        y[0] = 0;
        return a;
    }
    let x1 = [0], y1 = [0];
    let d = gcd(b, a % b, x1, y1);
    x[0] = y1[0];
    y[0] = x1[0] - Math.floor(a / b) * y1[0];
    return d;
}

function inverse(a, p) {
    let x = [0], y = [0];
    let g = gcd(a, p, x, y);
    if (g !== 1) {
        return -1; // Không tồn tại nghịch đảo modulo
    }
    return (x[0] % p + p) % p;
}

function main(a) {
    let inv = inverse(a, mod);
    if (inv !== -1) {
        return `Nghịch đảo của ${a} mod ${mod} = ${inv}`;
    } else {
        return "Không tồn tại nghịch đảo modulo!";
    }
}

// Xuất hàm main để sử dụng ở nơi khác
module.exports = { main };