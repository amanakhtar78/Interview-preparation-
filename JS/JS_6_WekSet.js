// 🎯 LEARNING NOTES for WeakSet (JavaScript)
// --------------------------------------
// ✅ Collection of OBJECTS only (no primitives allowed)
// ✅ Each object appears only once (no duplicates)
// ✅ Objects are held "weakly" → if no other reference exists,
//    the object is garbage-collected
// ✅ Not iterable (no forEach, no size, no keys/values/entries)
// ✅ Only these methods are available:
//    - weakSet.add(obj)
//    - weakSet.has(obj)
//    - weakSet.delete(obj)

function basicOfWeakSet() {
  // 👉 Initialization
  let weakSet = new WeakSet();

  // 👉 Create some objects
  let obj1 = { id: 1, name: "Alice" };
  let obj2 = { id: 2, name: "Bob" };

  // 👉 Add objects
  weakSet.add(obj1);
  weakSet.add(obj2);
  weakSet.add(obj1); // duplicate ignored

  // 👉 Check existence
  console.log(weakSet.has(obj1)); // true
  console.log(weakSet.has({ id: 1 })); // false (different object ref)

  // 👉 Delete
  weakSet.delete(obj2);
  console.log(weakSet.has(obj2)); // false

  // 👉 Garbage collection (conceptual)
  obj1 = null;
  // after this, {id:1, name:"Alice"} can be garbage-collected
  // and auto-removed from WeakSet

  // ⚠️ Not iterable
  // console.log([...weakSet]); ❌ TypeError
}

basicOfWeakSet();
