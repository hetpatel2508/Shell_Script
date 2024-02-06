arr=(1 2 3 4 5 6)
echo "${arr[*]}"  
arr+=(7 8 9 10)
echo "${arr[*]}"  
echo "${#arr[*]}"
echo "${arr[*]:2:5}" # 2 is index_number && 5 is total number of values will be taken not index_number