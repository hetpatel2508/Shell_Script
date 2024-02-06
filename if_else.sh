read -p "Enter Number : " num


# if [[ $(($num%2)) == 0 ]]
#or

if [ $(($num%2)) == 0 ]
then 
echo "Even"
else
echo "Odd"
fi