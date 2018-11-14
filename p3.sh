#3. Write a shell program to display the following mark sheets of students by taking the input marks
#of student through the terminal:
#Marks range
#Grade
#90>=M<=100
#A
#70>=M<=89
#B
#40>=M<=69
#C
#M<40
#F

#!/bin/sh
echo "Enter  mark for the student"
read m
echo -n "The grade of the student is:"
if [ $m -ge 90 -a $m -le 100 ]; then
	echo "A"
elif [ $m -ge 70 -a $m -le 89 ]; then
	echo "B"
elif [ $m -ge 40 -a $m -le 69 ]; then
	echo "C"
else
	echo "F"
fi

