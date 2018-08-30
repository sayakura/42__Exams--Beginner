echo "$(stat -r bomb.txt | cut -d\  -f 9) - 1" | bc
