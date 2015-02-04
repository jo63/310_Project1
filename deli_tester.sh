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
echo "Provided SW Test With Small Board" 
echo

time ./deli 1 sw.in0 sw.in1 sw.in2 sw.in3 sw.in4 > deli_provided_test_small_board_res.txt

echo 

./diff deli_provided_test_small_board_true.txt deli_provided_test_small_board_res.txt

echo
echo 
echo "Invalid Sandwich Number Entry Test"
echo 

time ./deli 3 inv.in0 inv.in1 inv.in2 > deli_invalid_test_res.txt

echo 

./diff deli_invalid_test_true.txt deli_invalid_test_res.txt

echo
echo 
echo "Non Equal Cashier File Lengths Test"
echo 

time ./deli 3 lengths.in0 lengths.in1 lengths.in2 > deli_lengths_test_res.txt

echo 

./diff deli_lengths_test_true.txt deli_lengths_test_res.txt

echo
echo 
echo "Identical Sandwiches Arbitration"
echo 

time ./deli 3 equal.in0 equal.in1 equal.in2 > deli_equal_test_res.txt

echo 

./diff deli_equal_test_true.txt deli_equal_test_res.txt

echo
echo 