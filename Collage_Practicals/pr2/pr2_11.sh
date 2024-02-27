# Write a script to make following file and directory management operation.
# 1) Display current directory
# 2) List directory
# 3) Make directory
# 4) Change directory
# 5) Copy directory
# 6) Rename a file
# 7) Delete a file
# 8) Edit a file

echo "1) Display current directory"
echo "2) List directory"
echo "3) Make directory"
echo "4) Change directory"
echo "5) Copy directory"
echo "6) Rename a file"
echo "7) Delete a file"
echo "8) Edit a file"
echo "9) Exit"
read -p " Enter Your Choice : " choice

case $choice in
1) pwd ;;
2) ls -l $(pwd) ;;
3)
    read -p "Enter File Name : " myfile
    mkdir $myfile
    ;;
4)
    read -p "Enter Path : " path
    cd $path
    ;;
5)
    read -p "Enter File Name : " p_name
    read -p "Enter New File Name : " n_name
    cp -r $p_name $n_name
    ;;
6)
    read -p "Enter File Name : " p_name
    read -p "Enter New File Name : " n_name
    mv $p_name $n_name 
    ;;
7)
    read -p "Enter File Name : " fname
    rm -r $fname
    ;;
8)
    read -p "Enter file name to edit: " filename
    vi "$filename"
    ;;
9) exit ;;
*) echo "Wrong Input" ;;
esac
