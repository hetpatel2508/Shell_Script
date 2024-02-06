declare -A arr
arr=(
    [id]=2
    [name]="het"
)

echo "id = ${arr[id]}"
echo "name = ${arr[name]}"
echo ""

#or

echo "id = ${arr[id]} name = ${arr[name]}"
echo ""


#or

echo "${arr[*]}"