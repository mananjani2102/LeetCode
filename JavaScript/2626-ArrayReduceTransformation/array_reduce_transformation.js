// LeetCode 2626 - Array Reduce Transformation
// Approach: Manual Loop (without built-in Array.reduce)
// Time: O(n) | Space: O(1)

var reduce = function(nums, fn, init) {
    let val = init;

    for (let i = 0; i < nums.length; i++) {
        val = fn(val, nums[i]);
    }

    return val;
};

// Test cases
const sum1 = function(accum, curr) { return accum + curr; };
console.log(reduce([1, 2, 3, 4], sum1, 0)); // 10

const sum2 = function(accum, curr) { return accum + curr * curr; };
console.log(reduce([1, 2, 3, 4], sum2, 100)); // 130

const sum3 = function(accum, curr) { return 0; };
console.log(reduce([], sum3, 25)); // 25
