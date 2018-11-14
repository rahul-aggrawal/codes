#1. Create a file “First.txt” using ‘vi’ editor where the contents are:
#Dog is domestic animal
#Dog hates cat
#Cat drinks milk
#Dog is bigger than cat
#Cat is also a domestic animal
#Find the total number of lines that does not contain the word ‘dog’ in “First.txt”.


echo "enter contents of file"
cat >first.txt

grep -v -w Dog first.txt -c
