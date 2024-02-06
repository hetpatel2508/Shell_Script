read -p "Enter Number : " num

case $num in
1) cal ;;
2) pwd ;;
3) hostname ;;
4) ls ;;
*) echo "wrong input ...!" ;;
esac