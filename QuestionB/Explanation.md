The Fast Inverse Square Method is a clever algorithm. Instead of calculating the exact square root and dividing 1 by it takes time to compute i.e, calculationg x^0.5 (square root of x) using sqrt(x) funcion dividing 1 by it that reversing sqrt(x) takes more time to compute which may also has not accurate value. But Using this Fast Inverse Square algorithm which take guess using bit manipulating with Newton,s method formula.

float xhalf = 0.5f * x; half of the inut value is stored in xhalf variable which can be later used in code.
int i = *(int*)&x; here the x value is not changed this line of code tells the computer to look into the bit value same appeared as integer.
i = 0x5f3759df - (i >> 1); here the 0x5f3759df is the magic number choosen which gives starting occurance for approximation.
i>>1 shifts the all i bits to 1 step right which is similar to dividing by 2 now i has exact value of 1/sqrt(x)

x = *(float*)&i; computer looks those bits of value but this time as a float value whcih is an approximate value

x = x * (1.5f - xhalf * x * x); this is the accuarte value estimated or computed using Newton's Method.

This is very fast because of bit manipulation/ computing at bitwise level which is easier for the computer to uderstand and proceed.


