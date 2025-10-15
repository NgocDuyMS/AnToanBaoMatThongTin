function chuan_hoa(p, row, k) {
    let s = row * k;
    while (p.length < s) {
        p += "x"; // Thêm ký tự 'x' nếu chuỗi chưa đủ độ dài
    }
    return p;
}

function nhap(kq, row, k, p) {
    let cnt = 0;
    for (let i = 0; i < row; i++) {
        for (let j = 0; j < k; j++) {
            kq[i][j] = p[cnt++];
        }
    }
}

function ma_hoa(kq, row, k) {
    let result = "";
    for (let j = 0; j < k; j++) {
        for (let i = 0; i < row; i++) {
            result += kq[i][j];
        }
    }
    return result;
}

function giai_ma(kq, row, k) {
    let result = "";
    for (let i = 0; i < row; i++) {
        for (let j = 0; j < k; j++) {
            result += kq[i][j];
        }
    }
    return result;
}

function main(plaintext, key) {
    let p = plaintext;
    let k = key;
    let n = p.length;
    let row = Math.ceil(n / k);
    
    p = chuan_hoa(p, row, k);
    
    let x = Array(row).fill().map(() => Array(k).fill());
    nhap(x, row, k, p);
    
    let encoded = ma_hoa(x, row, k);
    let decoded = giai_ma(x, row, k);
    
    return {
        encoded: encoded,
        decoded: decoded
    };
}

// Xuất hàm main để sử dụng ở nơi khác
module.exports = { main };
