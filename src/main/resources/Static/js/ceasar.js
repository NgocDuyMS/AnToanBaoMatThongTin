const readline = require("readline");

const mod = 26;
const mod1 = 10;

function dichChuyen(c, k) {
  if (/[A-Z]/.test(c)) {
    return String.fromCharCode(
      "A".charCodeAt(0) + (((c.charCodeAt(0) - "A".charCodeAt(0) + k) % mod + mod) % mod)
    );
  } else if (/[a-z]/.test(c)) {
    return String.fromCharCode(
      "a".charCodeAt(0) + (((c.charCodeAt(0) - "a".charCodeAt(0) + k) % mod + mod) % mod)
    );
  } else if (/[0-9]/.test(c)) {
    return String.fromCharCode(
      "0".charCodeAt(0) + (((c.charCodeAt(0) - "0".charCodeAt(0) + k) % mod1 + mod1) % mod1)
    );
  } else {
    return c; // Giữ nguyên nếu không phải chữ hoặc số
  }
}

function maHoa(t, k) {
  return t
    .split("")
    .map((c) => dichChuyen(c, k))
    .join("");
}

function giaiMa(t, k) {
  return maHoa(t, -k);
}

// Phần nhập xuất trong Node.js
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.question("Nhap van ban can ma hoa: ", function (s) {
  rl.question("Nhap khoa k: ", function (k) {
    k = BigInt(k); // giống long long trong C++
    console.log("Sau ma hoa: " + maHoa(s, k));
    console.log("Giai ma: " + giaiMa(maHoa(s, k), k));
    rl.close();
  });
});
