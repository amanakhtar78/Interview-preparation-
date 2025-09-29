// 🎯 LEARNING NOTES for Strings in JavaScript
// -----------------------------------------
// ✅ Strings are immutable sequences of characters (UTF-16 encoded).
// ✅ Can be created with '', "", or `` (template literals).
// ✅ Common operations: concatenation, slicing, searching, replacing.
// ✅ Template literals → allow interpolation: `Hello ${name}`
// ✅ Useful properties & methods:
//    - str.length → length of string
//    - str[index] → access character
//    - str.charAt(i), str.charCodeAt(i), str.codePointAt(i)
//    - str.toUpperCase(), str.toLowerCase()
//    - str.trim(), str.trimStart(), str.trimEnd()
//    - str.slice(start, end), str.substring(start, end), str.substr(start, len)
//    - str.includes(sub), str.startsWith(prefix), str.endsWith(suffix)
//    - str.indexOf(sub), str.lastIndexOf(sub)
//    - str.replace(old, new), str.replaceAll(old, new)
//    - str.split(delim), str.concat(other)
//    - str.repeat(n)
//    - String.raw → for raw strings in template literals

function basicOfString() {
  // 👉 Initialization
  let single = "Hello";
  let double = "World";
  let template = `Hi ${single}, ${double}!`; // template literal
  console.log(single, double, template);

  // 👉 Properties
  console.log("Length:", single.length); // 5
  console.log("First char:", single[0]); // H
  console.log("Last char:", single[single.length - 1]); // o

  // 👉 Case conversion
  console.log(single.toUpperCase()); // HELLO
  console.log(double.toLowerCase()); // world

  // 👉 Trimming
  let spaced = "   padded   ";
  console.log(spaced.trim()); // "padded"
  console.log(spaced.trimStart()); // "padded   "
  console.log(spaced.trimEnd()); // "   padded"

  // 👉 Slicing / Substring
  let str = "JavaScript";
  console.log(str.slice(0, 4)); // "Java"
  console.log(str.substring(4, 10)); // "Script"
  console.log(str.substr(4, 6)); // "Script" (legacy)

  // 👉 Search
  console.log(str.includes("Java")); // true
  console.log(str.startsWith("Java")); // true
  console.log(str.endsWith("Script")); // true
  console.log(str.indexOf("a")); // 1
  console.log(str.lastIndexOf("a")); // 3

  // 👉 Replace
  let txt = "I like JS. JS is fun!";
  console.log(txt.replace("JS", "JavaScript")); // first occurrence
  console.log(txt.replaceAll("JS", "JavaScript")); // all occurrences

  // 👉 Split & Join
  let csv = "red,green,blue";
  let arr = csv.split(",");
  console.log(arr); // [ 'red', 'green', 'blue' ]
  console.log(arr.join(" | ")); // "red | green | blue"

  // 👉 Repeat
  console.log("ha".repeat(3)); // "hahaha"

  // 👉 Unicode & Characters
  console.log("A".charCodeAt(0)); // 65
  console.log(String.fromCharCode(65)); // "A"

  // 👉 Raw string (no escape processing)
  let raw = String.raw`Line1\nLine2`;
  console.log(raw); // "Line1\nLine2"
}

basicOfString();
