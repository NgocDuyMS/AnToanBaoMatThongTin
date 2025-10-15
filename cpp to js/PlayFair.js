const tmp = "abcdefghiklmnopqrstuvwxyz";

function taoBang(key) {
    let mark = new Map();
    for (let c of tmp) {
        mark.set(c, 1);
    }

    // Xóa trùng trong key
    let used = "";
    for (let c of key) {
        if (c === 'j') c = 'i';
        if (mark.get(c)) {
            used += c;
            mark.set(c, 0);
        }
    }

    // Thêm ký tự còn thiếu
    for (let c of tmp) {
        if (mark.get(c)) {
            used += c;
            mark.set(c, 0);
        }
    }

    used = "0" + used;

    // Điền vào bảng
    let a = Array(6).fill().map(() => Array(6).fill());
    let pos = new Map();
    let cnt = 1;
    for (let i = 1; i <= 5; i++) {
        for (let j = 1; j <= 5; j++) {
            a[i][j] = used[cnt];
            pos.set(a[i][j], [i, j]);
            cnt++;
        }
    }
    return { a, pos };
}

function chuanHoa(t) {
    let res = "";
    for (let c of t) {
        if (/[a-zA-Z]/.test(c)) {
            c = c.toLowerCase();
            if (c === 'j') c = 'i';
            res += c;
        }
    }

    // Chèn x nếu có cặp trùng
    let fixed = "";
    for (let i = 0; i < res.length; i++) {
        fixed += res[i];
        if (i + 1 < res.length && res[i] === res[i + 1]) {
            fixed += 'x';
        }
    }
    if (fixed.length % 2 !== 0) fixed += 'x';
    return fixed;
}

function maHoaCap(x, y, a, pos) {
    let [r1, c1] = pos.get(x);
    let [r2, c2] = pos.get(y);
    let res = "";
    if (r1 === r2) {
        res += a[r1][(c1 % 5) + 1];
        res += a[r2][(c2 % 5) + 1];
    } else if (c1 === c2) {
        res += a[(r1 % 5) + 1][c1];
        res += a[(r2 % 5) + 1][c2];
    } else {
        res += a[r1][c2];
        res += a[r2][c1];
    }
    return res;
}

function giaiMaCap(x, y, a, pos) {
    let [r1, c1] = pos.get(x);
    let [r2, c2] = pos.get(y);
    let res = "";
    if (r1 === r2) {
        res += a[r1][((c1 + 3) % 5) + 1];
        res += a[r2][((c2 + 3) % 5) + 1];
    } else if (c1 === c2) {
        res += a[((r1 + 3) % 5) + 1][c1];
        res += a[((r2 + 3) % 5) + 1][c2];
    } else {
        res += a[r1][c2];
        res += a[r2][c1];
    }
    return res;
}

function maHoa(t, a, pos) {
    let res = "";
    for (let i = 0; i < t.length; i += 2) {
        res += maHoaCap(t[i], t[i + 1], a, pos);
    }
    return res;
}

function giaiMa(t, a, pos) {
    let res = "";
    for (let i = 0; i < t.length; i += 2) {
        res += giaiMaCap(t[i], t[i + 1], a, pos);
    }
    return res;
}

function main(key, text) {
    let { a, pos } = taoBang(key);
    
    // Tạo bảng khóa dưới dạng chuỗi để hiển thị
    let table = "";
    for (let i = 1; i <= 5; i++) {
        for (let j = 1; j <= 5; j++) {
            table += a[i][j] + " ";
        }
        table += "\n";
    }

    let fixed = chuanHoa(text);
    let cipher = maHoa(fixed, a, pos);
    let plain = giaiMa(cipher, a, pos);

    return {
        table: table,
        fixedText: fixed,
        cipherText: cipher,
        plainText: plain
    };
}

// Xuất hàm main để sử dụng ở nơi khác
module.exports = { main };