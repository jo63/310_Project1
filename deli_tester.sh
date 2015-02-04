#!/bin/bash

clear

echo "Provided SW Test" 
echo

time ./deli 3 sw.in0 sw.in1 sw.in2 sw.in3 sw.in4 > deli_provided_test_res.txt

echo 

./diff deli_provided_test_true.txt deli_provided_test_res.txt

echo
echo 
echo "Provided SW Test With Large Board" 
echo

time ./deli 5 sw.in0 sw.in1 sw.in2 sw.in3 sw.in4 > deli_provided_test_large_board_res.txt

echo 

./diff deli_provided_test_large_board_true.txt deli_provided_test_large_board_res.txt

echo
echo 
echo "Invalid Sandwich Number Entry"
echo 

time ./deli 3 inv.in0 inv.in1 inv.in2 > deli_invalid_res.txt

echo 

./diff deli_invalid_test_true.txt deli_invalid_test_res.txt

