function solution(answers) {
    var answer = [];
    
    let a = [1, 2, 3, 4, 5]; 
    let b = [2, 1, 2, 3, 2, 4, 2, 5];
    let c = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];
    var cnt = [0, 0, 0];
    
    var i = 0;
    for (i = 0; i<answers.length; i++){

        if(answers[i] == a[i%5]) cnt[0]++;
        if(answers[i] == b[i%8]) cnt[1]++;
        if(answers[i] == c[i%10]) cnt[2]++;
    }
    var mmax = 0;
    for (var j of cnt){
        if(mmax < j) mmax = j;
    }
    for (i = 0; i<3;i++){
        if(cnt[i] == mmax) answer.push(i+1);
    }
    return answer;
}

var answers = [1,2,3,4,5];
var res = solution(answers);
console.log(res);