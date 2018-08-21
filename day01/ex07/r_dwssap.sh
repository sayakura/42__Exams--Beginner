#!/bin/sh
cat  /etc/passwd | grep -v "#"  | sed -n "p;n" | cut -f1 -d":" | rev | sort -r | awk -v l1="$FT_LINE1" -v l2="$FT_LINE2" 'NR>=l1 && NR<=l2' | tr '\n' ',' | sed 's/, */, /g'| rev | cut -c3- | rev | sed 's/$/./'
