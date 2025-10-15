function tach_modulo(m) {
    let modulo = [];
    let can = Math.floor(Math.sqrt(m));
    for (let i = 2; i <= can; i++) {
        let p = 1;
        if (m % i === 0) {
            while (m % i === 0) {
                m /= i;
                p *= i;
            }
            modulo.push(p);
        }
    }
    if (m > 1) modulo.push(m);
    return modulo;
}

function luy_thua(a, b, mod) {
    if (b === 0) return 1;
    let x = luy_thua(a, Math.floor(b / 2), mod);
    if (b % 2 === 0) {
        return (x * x) % mod;
    } else {
        return ((x * x % mod) * a) % mod;
    }
}

function gcdExtended(a, b, x, y) {
    if (b === 0) {
        x[0] = 1;
        y[0] = 0;
        return a;
    }
    let x1 = [0], y1 = [0];
    let g = gcdExtended(b, a % b, x1, y1);
    x[0] = y1[0];
    y[0] = x1[0] - Math.floor(a / b) * y1[0];
    return g;
}

function modInverse(a, m) {
    let x = [0], y = [0];
    let g = gcdExtended(a, m, x, y);
    return (x[0] % m + m) % m;
}

function CRT(mods, rems) {
    let M = 1;
    for (let m of mods) {
        M *= m;
    }

    let x = 0;
    for (let i = 0; i < mods.length; i++) {
        let Mi = M / mods[i];
        let yi = modInverse(Mi, mods[i]);
        x = (x + rems[i] * Mi % M * yi % M) % M;
    }
    return (x % M + M) % M;
}

function main(m, a, b) {
    // B1: Tách mô-đun thành các thành phần
    let kq = tach_modulo(m);
    
    // B2: Tính a^b mod m_i cho mỗi modulo con
    let luy_thua_nho = [];
    for (let it of kq) {
        let p = luy_thua(a, b, it);
        luy_thua_nho.push(p);
    }
    
    // B3: Áp dụng CRT để ghép kết quả
    let result = CRT(kq, luy_thua_nho);
    
    return {
        modulo: kq,
        luy_thua_nho: luy_thua_nho,
        finalResult: result
    };
}

// Xuất hàm main để sử dụng ở nơi khác
module.exports = { main };