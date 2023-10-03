#!//bin/bash

minutes=$(date +%M)
month=$(date +%m)
total=$(( $minutes + $month ))
echo "$total"

for ((i=0; i < $total; i++)); 
do
	echo "Iteration " $(( i + 1 )) " out of " $total  ". " $(( total - i - 1 )) " iterations remaining."
done
