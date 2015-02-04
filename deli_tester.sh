#!/bin/bash

clear

echo "Provided SW Test" 
echo

./deli 3 sw.in0 sw.in1 sw.in2 sw.in3 sw.in4 > deli_provided_test_res.txt

echo 

./diff deli_provided_test_true.txt deli_provided_test_res.txt

echo
echo 
echo

./deli 3 inv.in0 inv.in1 inv.in2 > deli_invalid_res.txt

echo 

./diff deli_invalid_test_true.txt deli_invalid_test_res.txt

