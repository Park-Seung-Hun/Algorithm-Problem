function solution(arr) {
    const result = arr.reduce(function add(sum, currValue) {
      return sum + currValue;
    }, 0);
    const average = result / arr.length;
    return average;
}
