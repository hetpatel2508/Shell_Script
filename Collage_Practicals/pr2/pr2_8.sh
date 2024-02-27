# Write a script to display the name of all executable files in the given directory.
# Program 

read -p "Enter Directory Name : " directory

if [ -d $directory ]
then
ls -l $directory

else
echo "Directory doesn't exist..!"
fi