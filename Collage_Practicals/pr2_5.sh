# Write a script to accept number and perform addition, subtraction, multiplication & division.

read -p "Enter num1 : " num1
read -p "Enter num2 : " num2

echo "1) addition"
echo  "2) subtraction"
echo "3) multiplication"
echo "4) division"

read -p "Enter Your Choice : " choice

case $choice in 
    1) echo "$num1 + $num2 = $(($num1+$num2))" ;;
    2) echo "$num1 - $num2 = $(($num1-$num2))" ;;
    3) echo "$num1 * $num2 = $(($num1*$num2))" ;;
    4) echo "$num1 / $num2 = $(($num1/$num2))" ;;
    *) echo "Wrong Input";;
esac