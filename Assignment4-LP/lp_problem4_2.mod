var xij binary;
var xil binary;
var xkj binary;
var xkl binary;
var pijl binary;
var pjil binary;

minimize z: 0;

s.t. con1 : xij + xil = 1;
s.t. con2 : xkj + xkl = 1;
s.t. con3 : xij + xkj = 1;
s.t. con4 : xil + xkl = 1;
s.t. con5 : xij + xkl <= 3 - pijl - pjil;
