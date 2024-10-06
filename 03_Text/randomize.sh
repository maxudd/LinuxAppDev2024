#!/bin/bash

if [ $# -eq 0 ]
then
  delay=0.05
else
  delay=$1
fi

txt=""
row=0

while IFS="\n" read -r line
do
  for (( col=0; col<${#line}; col++ ))
  do
    current_sym=${line:$col:1}
    if [ "$current_sym" != " " ]
    then
      txt+="$current_sym $row $col \n"
    fi
  done
  row=$((row+1))
done

tput clear

printf "$txt" | shuf | while read -r sym y x
do
  tput cup $y $x
  echo $sym
  sleep $delay
done

tput cup $row 0