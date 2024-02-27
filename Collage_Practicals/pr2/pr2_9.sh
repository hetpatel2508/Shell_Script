#  Write a script to display the date, time & a welcome massage (like Good Morning etc.)
# the time should be displayed with ‘a.m’ or ‘p.m’ & not in 24 hours notation.

sudo wall "Date = $(date +"%A, %B %d,%G")"
sudo wall "Time = $(date +"%H : %M  : %S")"

if [ $(date +%H) -ge 0 ] && [ $(date +%H) -lt 16 ]
then 
sudo wall "Good Morning...!"

elif [ $(date +%H) -ge 16 ] && [ $(date +%H) -lt 20 ] 
then
sudo wall "Good Afternoon...! "

else
sudo wall "Good Night...!"
fi