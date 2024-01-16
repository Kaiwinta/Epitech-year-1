awk "NR%2==0"| cut -d":" -f 1 | rev | sort -r | sed -n "${MY_LINE1}, ${MY_LINE2}p" |  sed -e 's/$/,/' -e '$s/,$/./' | sed ':a;N;$!ba;s/\n/ /g'
