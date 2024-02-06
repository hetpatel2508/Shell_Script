str="Patel Het Rajeshkumar"

echo $str

echo "${#str}"

echo "${str:6:3}"  #output : het

echo "${str:10}"   #output : rajeshkumar

echo "${str/"het"/"dev"}" #output patel dev rajeshkumar

echo "${str^^}"  #upper case

echo "${str,,}"  #lower case

