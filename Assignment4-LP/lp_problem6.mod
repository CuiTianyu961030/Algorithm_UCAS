var y1;
var y2;
var y3;

maximize z: -3 * y1 + 4 * y2 + 12 * y3;

s.t. con1 : 3 * y1 + 2 * y2 - y3 <= -7;
s.t. con2 : -1 * y1 + y2 + 3 * y3 <= 7;
s.t. con3 : y1 <= -2;
s.t. con4 : -2 * y1 + y2 - 3 * y3 <= -1;
s.t. con5 : y2 <= -6;
s.t. con6 : y3 <= 0;
