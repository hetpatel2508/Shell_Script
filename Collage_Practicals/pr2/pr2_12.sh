read -p "Enter the file name: " fname
echo "Total characters: $(wc -c < $fname)"
echo "Total words: $(wc -w < $fname)"
echo "Total lines: $(wc -l < $fname)"
