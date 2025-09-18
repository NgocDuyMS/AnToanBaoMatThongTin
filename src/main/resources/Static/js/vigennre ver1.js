const readline = require("readline");

const bangChuThuong = "abcdefghijklmnopqrstuvwxyz";
const bangChuHoa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const mod = 26;
const mod1 = 10;
let khoa = new Map();

function xuli() {
  let cnt = 0;
  for (let x of bangChuThuong) {
    khoa.set(x, cnt++);
  }
  cnt = 0;
  for (let x of bangChuHoa) {
    khoa.set(x, cnt++);
  }
}

function dichChuyen(c, k) {
  if (/[A-Z]/.test(c)) {
    return String.fromCharCode(
      "A".charCodeAt(0) +
        (((c.charCodeAt(0) - "A".charCodeAt(0) + k) % mod + mod) % mod)
    );
  } else if (/[a-z]/.test(c)) {
    return String.fromCharCode(
      "a".charCodeAt(0) +
        (((c.charCodeAt(0) - "a".charCodeAt(0) + k) % mod + mod) % mod)
    );
  } else if (/[0-9]/.test(c)) {
    return String.fromCharCode(
      "0".charCodeAt(0) +
        (((c.charCodeAt(0) - "0".charCodeAt(0) + k) % mod1 + mod1) % mod1)
    );
  }
  return c;
}

function maHoa(p, k) {
  let res = p.split("");
  for (let i = 0; i < res.length; i++) {
    res[i] = dichChuyen(res[i], khoa.get(k[i]));
  }
  return res.join("");
}

function giaiMa(p, k) {
  let res = p.split("");
  for (let i = 0; i < res.length; i++) {
    res[i] = dichChuyen(res[i], -khoa.get(k[i]));
  }
  return res.join("");
}

function chuanHoa(p, key) {
  let n = p.length;
  let m = key.length;
  if (n === m) {
    return key;
  } else if (m < n) {
    let newKey = key;
    for (let i = m; i < n; i++) {
      newKey += key[(i - m) % m];
    }
    return newKey;
  } else {
    return key.substring(0, n);
  }
}

// --- Phần nhập xuất ---
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.question("Nhập văn bản: ", function (p) {
  rl.question("Nhập khóa: ", function (c) {
    xuli();
    let key = chuanHoa(p, c);
    let kq = maHoa(p, key);
    console.log("Văn bản mã hóa:", kq);
    console.log("Giải mã:", giaiMa(kq, key));
    rl.close();
  });
});
