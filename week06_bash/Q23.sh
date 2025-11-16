#!/bin/bash

factorial(){
  n=$1
  result=1
  
  for (( i=1; i<=n; i++ ))
  do
    result=$((result * i))
  done

  echo "Factorial of $1 is $result"
}

read -p "Enter a number: " NUM
factorial $NUM
