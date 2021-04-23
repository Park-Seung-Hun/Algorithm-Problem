/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */
var divide = function(dividend, divisor) {
    console.log(dividend/divisor);
    if(dividend/divisor<0) return Math.ceil(dividend/divisor);
    if(Math.floor(dividend/divisor)>2147483647) return 2147483647;
    return Math.floor(dividend/divisor)
};
