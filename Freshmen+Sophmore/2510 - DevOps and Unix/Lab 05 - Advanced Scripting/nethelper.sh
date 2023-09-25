#!/bin/bash

function read_hosts {
	hosts=$(cat $1)
	count=1

	for host in $hosts; do
		hosts_array[$count]="$host"
		count=$(( $count + 1 ))
	done

}

read_hosts $@

function pick_host {
	count=1

	for host in $(cat $1); do
		echo "$count) $host"
		count=$(( $count + 1 ))
	done

	read -p "Enter a number to select a host: " which_host
	
	validChoice=0

	while [ $validChoice -eq 0 ]; do
		if [[ $which_host -ge 1 && $which_host -lt $count ]]; then
			validChoice=1
		else
			read -p "Invalid Input, Please Enter a valid number: " which_host
		fi
	done

	recievingHost=${hosts_array[$which_host]}
}

while true; do
	echo "(P) for ping"
	echo "(N) for nslookup"
	echo "(H) for hostname"
	echo "(S) for ssh"
	echo "(I) for ifconfig"
	echo "(Q) for quit"
	read -p "Select one of the above: " cmd

	case $cmd in 
		[Pp])
			pick_host $@
			echo "after function call, $recievingHost"
			ping -c 1 $recievingHost
			;;
		[Nn])
			pick_host $@
			nslookup $recievingHost
			;;
		[Ss])
			read -p "What is your username? " user
			ssh $user@shell.csc.tntech.edu 
			;;
		[Hh])
			hostname
			;;
		[Ii])
			ifconfig -a
			;;
		[Qq])
			exit 1
			;;
	esac
done




