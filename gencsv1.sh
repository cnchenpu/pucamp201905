#!/bin/bash
for i in `seq 100 5000 1000000`; do
	printf "%d " $i;
	./pi-exp3 $i;
	printf "\n";
done 
