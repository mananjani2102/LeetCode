// LeetCode 2618 - Check if Object Instance of Class
// Approach: Walk the Prototype Chain
// Time: O(n) where n = prototype chain depth | Space: O(1)

var checkIfInstanceOf = function(value, classFunction) {
    if (typeof classFunction !== 'function') return false;
    if (value === null || value === undefined) return false;

    let proto = Object(value);

    while (proto !== null) {
        if (proto === classFunction.prototype) return true;
        proto = Object.getPrototypeOf(proto);
    }

    return false;
};

// Test cases
console.log(checkIfInstanceOf(new Date(), Date));  // true

class Animal {}
class Dog extends Animal {}
console.log(checkIfInstanceOf(new Dog(), Animal)); // true

console.log(checkIfInstanceOf(Date, Date));         // false

console.log(checkIfInstanceOf(5, Number));           // true
