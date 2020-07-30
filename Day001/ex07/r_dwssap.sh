cat /etc/passwd | sed /#/d | sed -n "n;p" | cut -f 1 -d : | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | tr "\n", "," | rev | cut -c 2- | rev | sed "s/$/./" | sed "s/,/, /g" | cat -e
