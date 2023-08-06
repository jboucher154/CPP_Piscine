#!/bin/bash

if [ ! -f sed_is_for_losers ]; then
	echo "sed_is_for_losers not found! Did you MAKE it?"
	exit 1
fi
# Test 1
echo -e "\n Test 1 \n"
echo "TESTING: test_file0.txt replacing log with logg"
./sed_is_for_losers test_file0.txt log logg

# Test 2
echo -e "\n Test 2 \n"
echo "TESTING: test_file1.txt replacing lizard with seal"
./sed_is_for_losers test_file1.txt lizard seal

# Test 3
echo -e "\n Test 3 \n"
echo "TESTING: whiskers.txt replacing cat with dog"
./sed_is_for_losers whiskers.txt cat dog

# Test 4
echo -e "\n Test 4 \n"
echo "changing permissions on output file"
chmod 000 whiskers.txt.replace
echo "TESTING: whiskers.txt replacing delight with plight"
./sed_is_for_losers whiskers.txt delight plight

# Test 5
echo -e "\n Test 5 \n"
touch nope_file.txt
echo "nope_file.txt created"
echo "testing testing" >nope_file.txt
chmod 000 nope_file.txt
echo "changed nope_file.txt to have no permissions"
echo "Now testing file without permissions nope_file.txt testing test"
echo "TESTING: nope_file.txt testing test"
./sed_is_for_losers nope_file.txt testing test