#5. Write a menu program with following options
#1. Make a file
#2. Display contents
#3. Rename the file
#4. Delete the file
#5. Exit

#!/bin/sh
PS3='Please enter your choice: '
options=("Make a file" "Display contents" "Rename a file" "Delete a file" "Quit")
select opt in "${options[@]}"
do
    case $opt in
        "Make a file")
            echo "Enter file name"
            read name
            cat >$name
            ;;
        "Display contents")
            echo "Enter file name"
            read name
            cat $name
            ;;
        "Rename a file")
            echo "Enter old name and new name"
            read name new
            mv $name $new
            ;;
        "Delete a file")
			echo "Enter file name"
			read name
			rm $name
            ;;
        "Quit")
            break
            ;;
        *) echo "invalid option $REPLY";;
    esac
done
