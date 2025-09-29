// 🎯 LEARNING NOTES for Array (JavaScript)
// --------------------------------------
// ✅ Ordered, indexed collection of values
// ✅ Can store mixed types
// ✅ Dynamic size (unlike C++ arrays)
// ✅ Common methods:
//    - push, pop, shift, unshift (add/remove)
//    - slice, splice (copy/modify parts)
//    - map, filter, reduce, forEach (iteration)
//    - some, every, find, findIndex (search)
//    - sort, reverse, includes, indexOf (utilities)

function basicOfArray() {
  // 👉 Initialization
  let arr = [1, 2, 3, "apple"];
  console.log(arr);
  // [1, 2, 3, 'apple']

  // 👉 Access by index
  console.log(arr[0], arr[3]);
  // 1 apple

  // 👉 Adding/removing
  arr.push("banana"); // add to end
  arr.unshift(0); // add to start
  console.log(arr);
  // [0, 1, 2, 3, 'apple', 'banana']

  arr.pop(); // remove last
  arr.shift(); // remove first
  console.log(arr);
  // [1, 2, 3, 'apple']

  // 👉 Iteration
  arr.forEach((v, i) => console.log(i, v));
  // 0 1
  // 1 2
  // 2 3
  // 3 apple

  // 👉 Transform
  let squared = arr.map((x) => (typeof x === "number" ? x * x : x));
  console.log(squared);
  // [1, 4, 9, 'apple']

  // 👉 Filter
  let numbers = arr.filter((x) => typeof x === "number");
  console.log(numbers);
  // [1, 2, 3]

  // 👉 Reduce
  let sum = numbers.reduce((a, b) => a + b, 0);
  console.log(sum);
  // 6
}

basicOfArray();
