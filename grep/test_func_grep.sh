#!/bin/bash
SUCCESS=0
FAIL=0
COUNTER=0
DIFF_RES=""
declare -a tests=(
"VAR s test_0_grep.txt"
"VAR for s21_grep.c s21_grep.h Makefile"
"VAR for s21_grep.c"
"VAR -e for -e ^int s21_grep.c s21_grep.h Makefile"
"VAR -e for -e ^int s21_grep.c"
"VAR -e regex -e ^print s21_grep.c -f test_ptrn_grep.txt"
"VAR -e while -e void s21_grep.c Makefile -f test_ptrn_grep.txt"
)
declare -a extra=(
"-n for test_1_grep.txt test_2_grep.txt"
"-n for test_1_grep.txt"
#"-n -e ^\} test_1_grep.txt"
"-ce ^int test_1_grep.txt test_2_grep.txt"
#" -e ^int test_1_grep.txt"
"-nivh = test_1_grep.txt test_2_grep.txt"
"-ie INT test_5_grep.txt"
"-echar test_1_grep.txt test_2_grep.txt"
#"-ne = -e out test_5_grep.txt"
"-iv int test_5_grep.txt"
"-in int test_5_grep.txt"
"-c -l aboba test_1_grep.txt test_5_grep.txt"
"-v test_1_grep.txt -e ank"
"-l for test_1_grep.txt test_2_grep.txt"
#" -e = -e out test_5_grep.txt"
#" -e four -e friend -e the -e first -e is test_6_grep.txt"
"-l for test_2_grep.txt"
"-f test_3_grep.txt test_5_grep.txt"
)

testing()
{
    t=$(echo -E $@ | sed "s/VAR/$var/")
    ./s21_grep $t > test_s21_grep.log
    grep $t > test_sys_grep.log
    #valgrind ./s21_grep $t
    DIFF_RES="$(diff -s test_s21_grep.log test_sys_grep.log)"
    (( COUNTER++ ))
    if [ "$DIFF_RES" == "Files test_s21_grep.log and test_sys_grep.log are identical" ]
    then
      (( SUCCESS++ ))
      echo "$FAIL/$SUCCESS/$COUNTER [success] grep $t"
    else
      (( FAIL++ ))
      echo "$FAIL/$SUCCESS/$COUNTER [fail] grep $t"
    fi
    rm test_s21_grep.log test_sys_grep.log
}

# специфические тесты
for i in "${extra[@]}"
do
    var="-"
    testing $i
done

# 1 параметр
for var1 in v c l n h o
do
    for i in "${tests[@]}"
    do
        var="-$var1"
        testing $i
    done
done

# 2 параметра
for var1 in v c l n h o
do
    for var2 in v c l n h o
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

# 2 сдвоенных параметра
for var1 in v c l n h o
do
    for var2 in v c l n h o
    do
        if [ $var1 != $var2 ]
        then
            for i in "${tests[@]}"
            do
                var="-$var1$var2"
                testing $i
            done
        fi
    done
done

echo "\033[31mFAIL: $FAIL\033[0m"
echo "\033[32mSUCCESS: $SUCCESS\033[0m"
echo "ALL: $COUNTER"