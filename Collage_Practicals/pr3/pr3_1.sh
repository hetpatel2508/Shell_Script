read -p "Enter Number : " num

remainder=0
temp=0

while [ $num -ne 0 ]
do
  remainder=$((num % 10))
  temp=$((temp * 10 + remainder))
  num=$((num / 10))
done

echo "Reverse Number = $temp"
