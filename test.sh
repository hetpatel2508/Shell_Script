#!/bin/bash

read -p "Enter Password : " pass
original_pass="hetpatel"

if [ "$pass" == "$original_pass" ]
then
    echo "Correct Password"
else
    echo "Incorrect Password"
fi
