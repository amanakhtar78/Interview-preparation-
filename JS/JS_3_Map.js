// 🎯 LEARNING NOTES for Map (JavaScript)
// --------------------------------------
// ✅ Key–value store (like Object but more powerful)
// ✅ Keys can be ANY type (string, number, object, function, etc.)
// ✅ Maintains insertion order
// ✅ Common utilities:
//    - map.set(key, value) → add/update
//    - map.get(key) → get value
//    - map.has(key) → check existence
//    - map.delete(key) → remove entry
//    - map.size → number of entries
//    - map.clear() → remove all entries
// ✅ Iteration methods:
//    - map.keys() → iterator of keys
//    - map.values() → iterator of values
//    - map.entries() → iterator of [key,value]
//    - map.forEach((value, key) => {}) → loop over entries

function basicOfMap() {
  // 👉 Initialization
  let map = new Map([
    ["name", "Alice"],
    ["age", 25],
    ["city", "London"],
  ]);
  console.log(map);
  // Map(3) { 'name' => 'Alice', 'age' => 25, 'city' => 'London' }

  // 👉 Add / update
  map.set("country", "UK");
  map.set("age", 26); // update
  console.log(map);
  // Map(4) { 'name' => 'Alice', 'age' => 26, 'city' => 'London', 'country' => 'UK' }

  // 👉 Access values
  console.log(map.get("name")); // Alice
  console.log(map.get("age")); // 26

  // 👉 Delete
  map.delete("city");
  console.log(map);
  // Map(3) { 'name' => 'Alice', 'age' => 26, 'country' => 'UK' }

  // 👉 Size
  console.log(map.size); // 3

  // 👉 Iteration
  for (let [k, v] of map.entries()) {
    console.log(k, "->", v);
  }
  // name -> Alice
  // age -> 26
  // country -> UK

  // 👉 Keys / Values
  console.log([...map.keys()]); // [ 'name', 'age', 'country' ]
  console.log([...map.values()]); // [ 'Alice', 26, 'UK' ]

  // 👉 forEach
  map.forEach((val, key) => console.log(key, "=", val));
  // name = Alice
  // age = 26
  // country = UK

  // 👉 Special: keys can be objects/functions too
  let objKey = { id: 1 };
  let funcKey = function () {};
  map.set(objKey, "Object as key");
  map.set(funcKey, "Function as key");

  console.log(map.get(objKey)); // Object as key
  console.log(map.get(funcKey)); // Function as key
}

basicOfMap();
