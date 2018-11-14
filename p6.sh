#1. Show how we can calculate the following expression in the terminal of UNIX
#A=5, b=6, z=9
#Total = (A*b) + (z/A)
#Display the total.

#!/bin/sh

A=5
b=6
z=9

Total=`expr $A \* $b + $z / $A`

echo $Total
