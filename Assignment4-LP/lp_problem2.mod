var x1 binary;
var x2 binary;
var x3 binary;
var x4 binary;
var m = 2;

maximize z: x1 + x2 + x3 + x4;

s.t. con1 : x1 <= m;
s.t. con2 : x1 + x2 <= m;
s.t. con3 : x2 <= m;
s.t. con4 : x2 + x3 <= m;
s.t. con5 : x2 + x3 + x4 <= m;
s.t. con6 : x3 <= m;
