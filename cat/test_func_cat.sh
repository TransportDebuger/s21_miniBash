#!/bin/bash

SUCCESS=0
FAIL=0
COUNTER=0
DIFF_RES=""

tests=(
"VAR test_1_cat.txt"
"VAR test_2_cat.txt"
"VAR test_case_cat.txt"
)

extra=(
"-vETns test_3_cat.txt"
"-vETbs test_5_cat.txt"
"-vETns test_1_cat.txt test_2_cat.txt test_3_cat.txt test_4_cat.txt test_5_cat.txt"
"-vETbs test_1_cat.txt test_2_cat.txt test_3_cat.txt test_4_cat.txt test_5_cat.txt"
"-Ans test_1_cat.txt test_2_cat.txt test_3_cat.txt test_4_cat.txt test_5_cat.txt"
"-Abs test_1_cat.txt test_2_cat.txt test_3_cat.txt test_4_cat.txt test_5_cat.txt"

"-b -n test_1_cat.txt"
"-s -n -e test_4_cat.txt"

)
testing() 
{
    t=$(echo $i | sed "s/VAR/$var/")
    ./s21_cat $t > test_s21_cat.log
    cat $t > test_sys_cat.log
   #valgrind --leak-check=yes ./s21_cat $t
    DIFF_RES="$(diff -s test_s21_cat.log test_sys_cat.log)"
    (( COUNTER++ ))
    if [ "$DIFF_RES" == "Files test_s21_cat.log and test_sys_cat.log are identical" ]
    then
      (( SUCCESS++ ))
        echo "$FAIL/$SUCCESS/$COUNTER [success] cat $t"
    else
      (( FAIL++ ))
        echo "$FAIL/$SUCCESS/$COUNTER [fail] cat $t"
    fi
    rm test_s21_cat.log test_sys_cat.log
}

# специфические тесты
for i in "${extra[@]}"
do
    var="-"
    testing $i
done

# 1 параметр
for var1 in b e n s t v
do
    for i in "${tests[@]}"
    do
        var="-$var1"
        testing $i
    done
done

# 2 параметра
for var1 in b e n s t v
do
    for var2 in n s t v
    do
        if [ $var1 != $var2 ]
        then
            for i in "${tests[@]}"
            do
                var="-$var1 -$var2"
                testing $i
            done
        fi
    done
done

echo "\033[31mFAIL: $FAIL\033[0m"
echo "\033[32mSUCCESS: $SUCCESS\033[0m"
echo "ALL: $COUNTER"
