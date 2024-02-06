#List or Array Loop:
num=(1 2 3 4 5 6 7 8 9 10)

for i in ${num[*]}
    do
        echo -n "$i "
    done
    echo ""

    #or

for i in 1 2 3 4 5 6 7 8 9 10
    do
        echo -n "$i "
    done
    echo ""


#Numeric Range Loop:
n=5
for (( i=1; i<=$n; i++ ))
    do
        echo -n "$i"
    done
echo ""


#Command Output Loop:

for i in $(ls)
    do 
        echo "file: $i "
    done