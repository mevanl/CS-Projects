#!/bin/bash

HI='\033[0;32m' 
NORMAL='\033[0m' 

echo -e "${HI}1. starts or ends with Jose$NORMAL"
grep -E '^Jose|Jose$' phonebook.dat

echo -e "${HI}2. Contain at least 27 upper or lower-case alphabetic characters$NORMAL"
grep -E --color=always '[A-Za-z]{27,}' phonebook.dat

echo -e "${HI}3. Consist of more than 18 characters$NORMAL"
grep -E --color=always '^.{18,}' phonebook.dat

echo -e "${HI}4. Contains exactly 10 characters$NORMAL"
grep -E --color=always '^.{10}$' phonebook.dat

echo -e "${HI}5. Contains a string of between 6 and 8 upper- or lower-case alphabetic characters$NORMAL"
grep -E --color=always '^[A-Za-z]{6,8}$' phonebook.dat

echo -e "${HI}6. Contains a local phone number$NORMAL"
grep -E --color=always '^[0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]{0,8}$' phonebook.dat

echo -e "${HI}7. Contains a valid URL on a line by itself$NORMAL"
grep -E --color=always '^(http|HTTP)://[a-zA-Z]+\.+[a-zA-Z]+\.(com|edu)$' phonebook.dat



