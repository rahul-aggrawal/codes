#4. Write a shell program to calculate the factorial of a number using while loop.

#!/bin/sh

echo "Enter value of n"
read n

x=1
ans=1
while [ $x -le $n ]
do
	ans=`expr $ans \* $x`
	x=`expr $x + 1`
done
echo "factorial of n is"
echo $ans

