// 🎯 LEARNING NOTES for WeakMap (JavaScript)
// --------------------------------------
// ✅ Key–value store where KEYS must be OBJECTS (not primitives)
// ✅ Values can be any type
// ✅ Keys are held "weakly" → if no other reference exists,
//    the key-value pair is garbage-collected
// ✅ Cannot iterate (no keys(), values(), entries(), or forEach)
// ✅ Only these methods are available:
//    - weakMap.set(key, value)
//    - weakMap.get(key)
//    - weakMap.has(key)
//    - weakMap.delete(key)

function basicOfWeakMap() {
  // 👉 Initialization
  let weakMap = new WeakMap();

  // 👉 Create some object keys
  let obj1 = { name: "Alice" };
  let obj2 = { name: "Bob" };

  // 👉 Add key-value pairs
  weakMap.set(obj1, "Engineer");
  weakMap.set(obj2, "Doctor");

  // 👉 Access values
  console.log(weakMap.get(obj1)); // Engineer
  console.log(weakMap.get(obj2)); // Doctor

  // 👉 Check existence
  console.log(weakMap.has(obj1)); // true
  console.log(weakMap.has({})); // false (different object reference)

  // 👉 Delete
  weakMap.delete(obj2);
  console.log(weakMap.has(obj2)); // false

  // 👉 Garbage collection (conceptual)
  obj1 = null;
  // after this, {name: "Alice"} is no longer strongly referenced
  // → weakMap entry will be removed automatically by GC

  // ⚠️ No way to iterate over all keys/values
  // console.log([...weakMap]); ❌ TypeError
}

basicOfWeakMap();
