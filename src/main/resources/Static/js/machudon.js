const readline = require("readline");

const mod = 26;
const mod1 = 10;

function dichChuyen(c, k) {
  if (/[A-Z]/.test(c)) {
    return String.fromCharCode(
      "A".charCodeAt(0) +
        (((c.charCodeAt(0) - "A".charCodeAt(0) + Number(k)) % mod + mod) % mod)
    );
  } else if (/[a-z]/.test(c)) {
    return String.fromCharCode(
      "a".charCodeAt(0) +
        (((c.charCodeAt(0) - "a".charCodeAt(0) + Number(k)) % mod + mod) % mod)
    );
  } else if (/[0-9]/.test(c)) {
    return String.fromCharCode(
      "0".charCodeAt(0) +
        (((c.charCodeAt(0) - "0".charCodeAt(0) + Number(k)) % mod1 + mod1) % mod1)
    );
  } else {
    return c;
  }
}

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.question("Nhập văn bản: ", function (p) {
  let kq = "";
  let khoa = [];
  let i = 0;

  function nhapKhoa() {
    if (i < p.length) {
      rl.question(`Nhập khóa cho ký tự '${p[i]}': `, function (k) {
        k = BigInt(k); // long long tương tự
        kq += dichChuyen(p[i], k);
        khoa.push(k);
        i++;
        nhapKhoa();
      });
    } else {
      console.log("Văn bản mã hóa: " + kq);

      // Giải mã
      let kq2 = "";
      for (let j = 0; j < p.length; j++) {
        kq2 += dichChuyen(kq[j], -khoa[j]);
      }
      console.log("Giải mã: " + kq2);
      rl.close();
    }
  }

  nhapKhoa();
});
