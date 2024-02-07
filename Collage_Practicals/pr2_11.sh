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
1) pwd;;
2) ls -l;;
3) mkdir myfile;;
4) cd ~/Desktop;;
5) cp -r myfile mynewfile;;
6) mv myfile mytempfile;;
7) rm -r mynewfile rm -r mytempfile;;
8) read -p "Enter file name to edit: " filename
   vi "$filename" ;;
9) exit;;
*) echo "Wrong Input"
esac
