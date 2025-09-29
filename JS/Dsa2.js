// 📌 Array & Hashing (Very Common)

//13 Two Sum problem (nums[i] + nums[j] = target).
//14 Move all zeros to the end of array.
//15 Merge two sorted arrays.
//16 Rotate an array by k steps.
//17 Find intersection of two arrays.
//18 Find the subarray with maximum sum (Kadane’s Algorithm).
//19 Find majority element (> n/2 times).
//20 Find missing + repeating numbers in array.

//📌 13. Two Sum problem
function twoSum(nums, target) {
  let map = new Map(); // store number -> index
  for (let i = 0; i < nums.length; i++) {
    let complement = target - nums[i];
    if (map.has(complement)) {
      return [map.get(complement), i];
    }
    map.set(nums[i], i);
  }
  return [];
}

// Example
console.log(twoSum([2, 7, 11, 15], 9)); // [0, 1]

//📌 14. Move all zeros to the end of array
function moveZeros(arr) {
  let index = 0;
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] !== 0) {
      [arr[i], arr[index]] = [arr[index], arr[i]];
      index++;
    }
  }
  return arr;
}

// Example
console.log(moveZeros([0, 1, 0, 3, 12])); // [1,3,12,0,0]

//📌 15. Merge two sorted arrays
function mergeSorted(arr1, arr2) {
  let i = 0,
    j = 0,
    merged = [];
  while (i < arr1.length && j < arr2.length) {
    if (arr1[i] < arr2[j]) merged.push(arr1[i++]);
    else merged.push(arr2[j++]);
  }
  return [...merged, ...arr1.slice(i), ...arr2.slice(j)];
}

// Example
console.log(mergeSorted([1, 3, 5], [2, 4, 6])); // [1,2,3,4,5,6]

//📌 16. Rotate an array by k steps
function rotateArray(arr, k) {
  k = k % arr.length;
  return arr.slice(-k).concat(arr.slice(0, -k));
}

// Example
console.log(rotateArray([1, 2, 3, 4, 5, 6, 7], 3)); // [5,6,7,1,2,3,4]

//📌 17. Find intersection of two arrays
function intersection(arr1, arr2) {
  let set1 = new Set(arr1);
  let set2 = new Set(arr2);
  let result = [];
  for (let num of set1) {
    if (set2.has(num)) result.push(num);
  }
  return result;
}

// Example
console.log(intersection([1, 2, 2, 1], [2, 2])); // [2]

//📌 18. Find subarray with maximum sum (Kadane’s Algorithm)
function maxSubArray(nums) {
  let maxSum = nums[0];
  let currSum = nums[0];
  for (let i = 1; i < nums.length; i++) {
    currSum = Math.max(nums[i], currSum + nums[i]);
    maxSum = Math.max(maxSum, currSum);
  }
  return maxSum;
}

// Example
console.log(maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4])); // 6 (subarray [4,-1,2,1])

//📌 19. Find majority element (> n/2 times)
function majorityElement(nums) {
  let candidate = null,
    count = 0;
  for (let num of nums) {
    if (count === 0) candidate = num;
    count += num === candidate ? 1 : -1;
  }
  return candidate;
}

// Example
console.log(majorityElement([3, 2, 3])); // 3
console.log(majorityElement([2, 2, 1, 1, 1, 2, 2])); // 2

//📌 20. Find missing + repeating numbers in array
function findMissingRepeating(arr, n) {
  let seen = new Set();
  let repeating = -1,
    sum = 0;

  for (let num of arr) {
    if (seen.has(num)) repeating = num;
    seen.add(num);
    sum += num;
  }

  let expectedSum = (n * (n + 1)) / 2;
  let missing = expectedSum - (sum - repeating);

  return { missing, repeating };
}

// Example
console.log(findMissingRepeating([4, 3, 6, 2, 1, 1], 6)); // { missing: 5, repeating: 1 }
