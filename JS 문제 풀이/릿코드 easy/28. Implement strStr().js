/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    let idx = haystack.indexOf(needle);
    return idx;
};

/*
haystack에 needle이
포함되면 해당 index
포함되지 않으면 -1
*/
