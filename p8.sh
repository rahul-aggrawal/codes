#Write a shell script which will generate the output as follows:
#(with number of lines taken as input)

#!/bin/bash

#read -p "Enter Number : " n
echo "Enter Number"
read n
s="*"
for((i=1;i<=$n;i++));
do
echo "$s"
s="$s *"
done        
