const dut = require('./build/Release/dut.node');

console.log(dut);
console.log(dut.pd1);

dut.pd1 = 2;
console.log(dut.pd1);
