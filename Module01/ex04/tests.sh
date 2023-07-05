#!/bin/bash

if [ ! -f sed_is_for_losers ]; then
	echo "sed_is_for_losers not found! Did you MAKE it?"
	exit 1
fi
# Test 1
echo "Test 1"
echo "test_file0.txt replacing log with cow"
./sed_is_for_losers test_file0.txt log cow

# Test 2
echo "Test 2"
echo "test_file1.txt replacing lizard with seal"
./sed_is_for_losers test_file1.txt lizard seal

# Test 3
echo "Test 3"
echo "whiskers.txt replacing cat with dog"
./sed_is_for_losers whiskers.txt cat dog
