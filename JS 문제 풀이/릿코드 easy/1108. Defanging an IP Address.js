/**
 * @param {string} address
 * @return {string}
 */
var defangIPaddr = function(address) {
    let arr =address.split('.');
    let answer = arr.join('[.]');
    return answer;
};
