# Write a script to accept file name & display last modification time if file exists
# otherwise display appropriate massage.

read -p "Enter file name: " fn

if [ -f "$fn" ]; then
    echo -n "Last modification time:  "
    date -r "$fn" +%T
else
    echo "File does not exist."
fi

# Enter file name:
# Array.sh
# Last modification time:
# 17:25:58