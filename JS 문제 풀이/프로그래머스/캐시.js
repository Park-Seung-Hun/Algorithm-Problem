function solution(cacheSize, cities) {
    let answer = 0;
    let i;
    let cache = [];
    if(cacheSize===0 ) return cities.length*5;
    for(i=0;i<cities.length;i++){
        let city = cities[i].toLowerCase();

        if(cache.indexOf(city) === -1){ // cache에 해당 city가 없을 경우 (cache Miss)
            if(cache.length === cacheSize){ // cache가 꽉 찬 경우
                cache.shift();
            }

            cache.push(city);
            answer+=5;
        }
        else{ // cache에 해당 city가 있는 경우 (cache Hit)
            cache.splice(cache.indexOf(city),1);
            cache.push(city);
            answer+=1;
        }
    }


    return answer;
}
