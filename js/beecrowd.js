// var readline = require('readline');
// var rl = readline.createInterface({
//     input: process.stdin,
//     output: process.stdout
// });
// var pi = 3.14159;
// var answer = parseFloat("");
// rl.question("", function (answer) {
//     answer *= answer * pi;
//     console.log("A=".concat(answer.toFixed(4)));
//     rl.close();
// });
var datas = {
    "nome": "teste",
    "estado": "estado1"
};
var aluno = datas;
aluno.nome = "otavio";
console.log(aluno.nome, aluno.estado);
