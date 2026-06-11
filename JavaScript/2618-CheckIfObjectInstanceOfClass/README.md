<div align="center">

# 2618. Check if Object Instance of Class

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-JavaScript-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Prototype_Chain-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)

</div>

---

## Problem

Write a function that checks if a given value is an instance of a given class or superclass - object should have access to that class's methods.

---

## Examples

| Input | Output |
|-------|--------|
| checkIfInstanceOf(new Date(), Date) | true |
| checkIfInstanceOf(new Dog(), Animal) where Dog extends Animal | true |
| checkIfInstanceOf(Date, Date) | false |
| checkIfInstanceOf(5, Number) | true |

---

## Approach - Walk the Prototype Chain

Pehle check karo classFunction actually ek function hai aur value null/undefined nahi hai. Value ko Object() se wrap karo (primitives ke liye, jaise 5 ko Number object banao). Fir prototype chain ko upar tak walk karo - Object.getPrototypeOf() use karke - aur check karo kya kabhi classFunction.prototype mil jata hai. Mile to true, chain khatam ho jaye to false.

---

## Complexity

| | |
|---|---|
| Time | O(n) where n = prototype chain depth |
| Space | O(1) |

---

## Solution

```javascript
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
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/check-if-object-instance-of-class/)
