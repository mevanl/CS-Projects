#!/bin/bash

x=$(date +%M)

if [ $((x%2)) -eq 0 ]; 
then
	echo "The time is even.";
else
	echo "The time is odd.";
fi


