// 🎯 LEARNING NOTES for Object (JavaScript)
// --------------------------------------
// ✅ Key–value store (keys are strings or symbols)
// ✅ Most common data structure in JS
// ✅ Values can be any type (number, string, object, function, etc.)
// ✅ Common utilities:
//    - obj.key or obj["key"] to access
//    - Object.keys(obj) → array of keys
//    - Object.values(obj) → array of values
//    - Object.entries(obj) → array of [key,value]
//    - delete obj.key → remove property
//    - obj.hasOwnProperty(key) → check property existence

function basicOfObject() {
  // 👉 Initialization
  let person = {
    name: "Alice",
    age: 25,
    city: "London",
  };
  console.log(person);
  // { name: 'Alice', age: 25, city: 'London' }

  // 👉 Access values
  console.log(person.name); // Alice
  console.log(person["age"]); // 25

  // 👉 Add / update
  person.country = "UK";
  person.age = 26;
  console.log(person);
  // { name: 'Alice', age: 26, city: 'London', country: 'UK' }

  // 👉 Delete
  delete person.city;
  console.log(person);
  // { name: 'Alice', age: 26, country: 'UK' }

  // 👉 Keys / Values / Entries
  console.log(Object.keys(person));
  // [ 'name', 'age', 'country' ]

  console.log(Object.values(person));
  // [ 'Alice', 26, 'UK' ]

  console.log(Object.entries(person));
  // [ [ 'name', 'Alice' ], [ 'age', 26 ], [ 'country', 'UK' ] ]

  // 👉 Iteration
  for (let [k, v] of Object.entries(person)) {
    console.log(k, "->", v);
  }
  // name -> Alice
  // age -> 26
  // country -> UK

  // 👉 Property check
  console.log(person.hasOwnProperty("name")); // true
  console.log(person.hasOwnProperty("city")); // false
}

basicOfObject();
