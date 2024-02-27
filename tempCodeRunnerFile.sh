sum=0;

for ((i=1; i<20; i++))
do
    if [ $((i % 2)) -ne 0 ]
        then 
            sum = $((sum+i));
    fi
done

echo "Sum = $sum"