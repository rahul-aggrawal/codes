#2. Write a shell script to modify permission of two files in your present working directory. Use
#command line arguments to enter file names. The files should be blank and you should
#create the files by executing your script. Grant “write” and “execute” permission to all the
#users of those two files.

echo "Enter names of two files"
read first second

cat >$first
cat >$second

chmod 300 $first
chmod 300 $second

ls -l
