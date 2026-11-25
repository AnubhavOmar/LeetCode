// Solution of LeetCode Problem
// 2703. Return Length of Arguments Passed
// Solution in JavaScript

/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
// Approach - 1
// Using Rest Parameters
// Time Complexity: O(n) - Creating the rest parameter array for n arguments
// Space Complexity: O(n) - The rest parameter stores n arguments in an array
var argumentsLength = function(...args) {
    return args.length;
};

/**
 * argumentsLength(1, 2, 3); // 3
 */