# Write a script which reads a text file & output the following count of character , words
# & lines

# Count the number of characters, words, and lines in the file
# num_chars=$(wc -m)
# num_words=$(wc -w)
# num_lines=$(wc -l)

read -p "Enter the file name " fname
echo "Total character : $(wc -m <"$fname")" 
echo "Total words : $(wc -w <"$fname")" 
echo "Total line : $(wc -l <"$fname")" 