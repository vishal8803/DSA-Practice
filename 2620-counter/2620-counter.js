/**
 * @param {number} n
 * @return {Function} counter
 */

var createCounter = function(n) {
    var counter = n;
    return function() {
        let res = counter;
        counter = counter + 1;
        return res;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */