var readline = require('readline');

var rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout

});

const pi = 3.14159;
let answer = parseFloat("")

rl.question("", function(answer) {
    answer *= answer * pi;
    console.log(`A=${answer.toFixed(4)}`);
    rl.close();
})