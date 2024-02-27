read -p "Enter the file name: " filename;

if [ -f "$filename" ]; 
then
    echo "Contents of $filename:"
    echo "";

    while read line
    do
        echo "$line"
    done < "$filename"
    
else
    echo "File not found."
fi
