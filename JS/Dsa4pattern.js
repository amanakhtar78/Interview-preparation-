// -----------------------------
// 📌 1. Square / Rectangle Pattern
// Input: n = 4
// Output:
// ****
// ****
// ****
// ****
function squarePattern(n) {
  for (let i = 0; i < n; i++) {
    console.log("*".repeat(n));
  }
}
squarePattern(4);

// -----------------------------
// 📌 2. Right Triangle Pattern
// Input: n = 5
// *
// **
// ***
// ****
// *****
function rightTriangle(n) {
  for (let i = 1; i <= n; i++) {
    console.log("*".repeat(i));
  }
}
rightTriangle(5);

// -----------------------------
// 📌 3. Inverted Right Triangle
// *****
// ****
// ***
// **
// *
function invertedRightTriangle(n) {
  for (let i = n; i >= 1; i--) {
    console.log("*".repeat(i));
  }
}
invertedRightTriangle(5);

// -----------------------------
// 📌 4. Pyramid Pattern
// Input: n = 5
//     *
//    ***
//   *****
//  *******
// *********
function pyramid(n) {
  for (let i = 1; i <= n; i++) {
    console.log(" ".repeat(n - i) + "*".repeat(2 * i - 1));
  }
}
pyramid(5);

// -----------------------------
// 📌 5. Inverted Pyramid
// *********
//  *******
//   *****
//    ***
//     *
function invertedPyramid(n) {
  for (let i = n; i >= 1; i--) {
    console.log(" ".repeat(n - i) + "*".repeat(2 * i - 1));
  }
}
invertedPyramid(5);

// -----------------------------
// 📌 6. Diamond Pattern
// Input: n = 4
//    *
//   ***
//  *****
// *******
//  *****
//   ***
//    *
function diamond(n) {
  for (let i = 1; i <= n; i++) {
    console.log(" ".repeat(n - i) + "*".repeat(2 * i - 1));
  }
  for (let i = n - 1; i >= 1; i--) {
    console.log(" ".repeat(n - i) + "*".repeat(2 * i - 1));
  }
}
diamond(4);

// -----------------------------
// 📌 7. Number Triangle
// Input: n = 5
// 1
// 12
// 123
// 1234
// 12345
function numberTriangle(n) {
  for (let i = 1; i <= n; i++) {
    let row = "";
    for (let j = 1; j <= i; j++) {
      row += j;
    }
    console.log(row);
  }
}
numberTriangle(5);

// -----------------------------
// 📌 8. Floyd’s Triangle
// Input: n = 5
// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15
function floydsTriangle(n) {
  let num = 1;
  for (let i = 1; i <= n; i++) {
    let row = "";
    for (let j = 1; j <= i; j++) {
      row += num++ + " ";
    }
    console.log(row.trim());
  }
}
floydsTriangle(5);

// -----------------------------
// 📌 9. Pascal’s Triangle
// Input: n = 5
//     1
//    1 1
//   1 2 1
//  1 3 3 1
// 1 4 6 4 1
function pascalsTriangle(n) {
  let arr = [[1]];
  for (let i = 1; i < n; i++) {
    let prev = arr[i - 1];
    let row = [1];
    for (let j = 1; j < prev.length; j++) {
      row.push(prev[j - 1] + prev[j]);
    }
    row.push(1);
    arr.push(row);
  }
  arr.forEach((row) => {
    console.log(" ".repeat(n - row.length) + row.join(" "));
  });
}
pascalsTriangle(5);

// -----------------------------
// 📌 10. Hollow Square
// Input: n = 5
// *****
// *   *
// *   *
// *   *
// *****
function hollowSquare(n) {
  for (let i = 0; i < n; i++) {
    if (i === 0 || i === n - 1) {
      console.log("*".repeat(n));
    } else {
      console.log("*" + " ".repeat(n - 2) + "*");
    }
  }
}
hollowSquare(5);
