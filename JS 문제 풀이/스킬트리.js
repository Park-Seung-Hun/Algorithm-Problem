function solution(skill, skill_trees) {
    var answer = 0;

    let filteredTrees = skill_trees.map((tree)=>{
        let splitedTree = tree.split('').filter((char)=>skill.includes(char))

        return splitedTree
    });

      for (let i = 0; i < filteredTrees.length; i++) {
    let isValid = true
    for (let j = 0; j < filteredTrees[i].length; j++) {
      if (skill[j] !== filteredTrees[i][j]) {
        isValid = false
        break
      }
    }

    if (isValid) {
      answer++
    }
  }
    return answer;
}
