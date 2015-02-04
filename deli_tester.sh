#!/bin/bash

clear

echo "Provided SW Test" 
echo

./deli 3 sw.in0 sw.in1 sw.in2 sw.in34 > deli_provided_test_res.txt

echo
echo 

./diff deli_provided_test_true.txt deli_provided_test_res.txt



