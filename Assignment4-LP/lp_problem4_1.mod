var xij binary;
var xil binary;
var xkj binary;
var xkl binary;
var Sijkl binary;

minimize z: 0;

s.t. con1 : xij + xil = 1;
s.t. con2 : xkj + xkl = 1;
s.t. con3 : xij + xkj = 1;
s.t. con4 : xil + xkl = 1;
s.t. con5 : xij + xkl <= Sijkl + 1;
