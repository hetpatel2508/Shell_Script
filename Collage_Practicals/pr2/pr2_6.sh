# Write a script for accept a string and check whether it is file or directory if it exists.
# (null string is not allowed)

read -p "Enter String : " s

if [ -f $s ]
then 
echo "$s is File";

elif [ -d $a ]
then 
echo "$s is Directory";

else
echo "The file or directory does not exist";
fi

# Enter String : Array.sh
# Array.sh is File

# Enter String : Collage Practicals
# Collage Practicals is Directory