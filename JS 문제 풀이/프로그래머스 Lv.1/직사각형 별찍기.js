process.stdin.setEncoding('utf8');
process.stdin.on('data', data => {
    const n = data.split(" ");
    const a = Number(n[0]), b = Number(n[1]);

    let arr = Array.from({length: a},()=>'*');
    let str = arr.join('');

    for(let i=0;i<b;i++) console.log(str);
});
