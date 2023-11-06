# **************************************************************************** #
#                                                                              #
#                                                     .--.  _                  #
#    test.sh                                         |o_o || |                 #
#                                                    |:_/ || |_ _   ___  __    #
#    By: houtworm <codam@houtworm.net>              //   \ \ __| | | \ \/ /    #
#                                                  (|     | )|_| |_| |>  <     #
#    Created: 2023/02/20 12:46:46 by houtworm     /'\_   _/`\__|\__,_/_/\_\    #
#    Updated: 2023/03/11 08:07:29 by houtworm     \___)=(___/                  #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Vars and Init

PNAME=get_next_line.a
SLEEP=1
FAULTS=0
VALGRIND=0
which valgrind > /dev/null
if [ $? -eq 0 ]
then
	VALGRIND=1
else
	printf "\n\e[1;31mInstall Valgrind for extra Memory Checking\e[0;00m\n"
fi
HEADLOC=$(find ./ -name '*line.h' | grep -v tests | grep -v ccls)
mkdir -p tests/tmp
cp $HEADLOC tests/tmp/get_next_line.h
if [ $1 == "old" ]
then
	SRCPATH="tests/src/old/"
	FILPATH="tests/files/old/"
elif [ $1 == "new" ]
then
	SRCPATH="tests/src/new/"
	FILPATH="tests/files/new/"
else
	printf "\e[1;31mPlease run the tester as follows\n./test.sh [VERSION] [SLEEPTIME]\nold returns an int while new returns the line\nexamples:\n./test.sh old\n./test.sh new\n./test.sh old 5\e[0;00m\n"
	rm -rf tests/tmp
	exit 1
fi
if [ $2 ]
then
	SLEEP=$2
fi

# Functions

getnextline()
{
	gcc -D BUFFER_SIZE=$1 -o tests/tmp/binary ${SRCPATH}$2 get_next_line.a
	./tests/tmp/binary > tests/tmp/output
	diff ${FILPATH}$3 tests/tmp/output > /dev/null
	if [ $? -eq 0 ]
	then
		printf "\e[1;32mOutput OK\e[0;00m\n"
	else
		printf "\e[1;31mOutput is wrong\e[0;00m\n"
		FAULTS=$(($FAULTS+1))
	fi
	gcc -g -fsanitize=address -D BUFFER_SIZE=$1 -o tests/tmp/binary ${SRCPATH}$2 get_next_line.a
	./tests/tmp/binary > tests/tmp/output 2>tests/tmp/memorycheck
	diff ${FILPATH}$3 tests/tmp/output > /dev/null
	if [ $? -eq 0 ]
	then
		cat tests/tmp/memorycheck | grep "leaked" > /dev/null
		if [ $? -eq 1 ]
		then
			printf "\e[1;32mNo Leaks Fsanitize\e[0;00m\n"
		else
			printf "\n\e[1;31mKO found Leaks \e[0;00m\n"
			cat tests/tmp/memorycheck
			FAULTS=$(($FAULTS+1))
		fi
	else
		printf "\e[1;31mKO with fsanitize\e[0;00m\n"
		cat tests/tmp/memorycheck
		FAULTS=$(($FAULTS+1))
	fi
	if [ $VALGRIND -eq 1 ]
	then
		gcc -o tests/tmp/binary ${SRCPATH}$2 get_next_line.a 2> /dev/null
		valgrind --leak-check=full ./tests/tmp/binary 2> tests/tmp/memorycheck > /dev/null
		cat tests/tmp/memorycheck | grep indirectly | grep "[123456789] bytes" > /dev/null
		if [ $? -eq 0 ]
		then
			printf "\n\e[1;31mLeaks Valgrind $1 $2\e[0;00m\n"
			cat tests/tmp/memorycheck
			FAULTS=$(($FAULTS+1))
			CURFUNERR=1
		else
			printf "\e[1;32mNo Leaks Valgrind\e[0;00m\n"
		fi
		cat tests/tmp/memorycheck | grep definitely | grep "[123456789] bytes" > /dev/null
		if [ $? -eq 0 ]
		then
			printf "\n\e[1;31mLeaks Valgrind $1 $2\e[0;00m\n"
			cat tests/tmp/memorycheck
			FAULTS=$(($FAULTS+1))
			CURFUNERR=1
		fi
	fi
}

checkfile()
{
	ls $1 2> /dev/null | grep $1 > /dev/null
	if [ $? -ne $2 ]
	then
		printf "\e[1;31mMakefile does not create $1\e[0;00m\n"
		rm -rf tests/tmp
		exit 1
	fi
}

searchobj()
{
	FILES=$(find ./ -name '*.o' | wc -l)
	if [ $1 -eq 0 ]
	then
		if [ $FILES -ne 0 ]
		then
			printf "\e[1;31mObject files found after clean\e[0;00m\n"
			FAULTS=$(($FAULTS+1))
		fi
	fi
	if [ $1 -eq 1 ]
	then
		if [ $FILES -eq 0 ]
		then
			printf "\e[1;31mObject files not found after make\e[0;00m\n"
			FAULTS=$(($FAULTS+1))
		fi
	fi
}

checkrule()
{
	make $1 > /dev/null 2>&1
	if [ $? -eq 2 ]
	then
		printf "\e[1;31mMissing rule $1\e[0;00m\n"
		FAULTS=$(($FAULTS+1))
	fi
}

relinkcheck()
{
	make $1 2>&1 | grep -v Nothing > tests/tmp/relink && cat tests/tmp/relink | grep -v directory > /dev/null
	if [ $? -eq 0 ]
	then
		printf "\n\e[1;31mMakefile relinks\e\n[0;00m"
		cat tests/tmp/relink
		FAULTS=$(($FAULTS+1))
	else
		printf "\e[1;32mMakefile OK\n\e[0;00m"
	fi
}

# Tests

# Test 1
printf "\e[1;36mTest 1 Checking all source with Norminette\e[0;00m\n"
norminette $(find ./ -name '*.[ch]' | grep -v ./tests/ | grep -v ccls) > tests/tmp/norm
if [ $? -eq 1 ]
then
	printf "\e[1;31mYour shit is not norm!\e[0;00m\n"
	cat tests/tmp/norm
	FAULTS=$(($FAULTS+1))
else
	printf "\e[1;32mNorminette OK\e[0;00m\n"
fi
sleep $SLEEP

# Test 2
printf "\e[1;36mTest 2 Checking all mandatory rules Makefile\e[0;00m\n"
checkrule all
checkfile $PNAME 0
searchobj 1
checkrule clean
searchobj 0
checkfile $PNAME 0
checkrule $PNAME
searchobj 1
checkfile $PNAME 0
checkrule fclean
searchobj 0
checkfile $PNAME 1
checkrule re
searchobj 1
checkfile $PNAME 0
if [ $FAULTS -eq 0 ]
then
	printf "\e[1;32mMakefile rules OK\e[0;00m\n"
fi
sleep $SLEEP

# Test 3
printf "\e[1;36mTest 3 Checking if Makefile relinks\e[0;00m\n"
relinkcheck
sleep $SLEEP

# Test 4
printf "\e[1;36mTest 4 Basic test with Buffer size 0\e[0;00m\n"
getnextline 0 maina.c basic
sleep $SLEEP

# Test 5
printf "\e[1;36mTest 5 Basic test with Buffer size 1\e[0;00m\n"
getnextline 1 maina.c basic
sleep $SLEEP

# Test 6
printf "\e[1;36mTest 6 Basic test with Buffer size 2\e[0;00m\n"
getnextline 2 maina.c basic
sleep $SLEEP

# Test 7
printf "\e[1;36mTest 7 Basic test with Buffer size 3\e[0;00m\n"
getnextline 3 maina.c basic
sleep $SLEEP

# Test 8
printf "\e[1;36mTest 8 Basic test with Buffer size 4\e[0;00m\n"
getnextline 4 maina.c basic
sleep $SLEEP

# Test 9
printf "\e[1;36mTest 9 Basic test with Buffer size 5\e[0;00m\n"
getnextline 5 maina.c basic
sleep $SLEEP

# Test 10
printf "\e[1;36mTest 10 Basic test with Buffer size 6\e[0;00m\n"
getnextline 6 maina.c basic
sleep $SLEEP

# Test 11
printf "\e[1;36mTest 11 Basic test with Buffer size 7\e[0;00m\n"
getnextline 7 maina.c basic
sleep $SLEEP

# Test 12
printf "\e[1;36mTest 12 Basic test with Buffer size 8\e[0;00m\n"
getnextline 8 maina.c basic
sleep $SLEEP

# Test 13
printf "\e[1;36mTest 13 Basic test with Buffer size 9\e[0;00m\n"
getnextline 9 maina.c basic
sleep $SLEEP

# Test 14
printf "\e[1;36mTest 14 Basic test with Buffer size 10\e[0;00m\n"
getnextline 10 maina.c basic
sleep $SLEEP

# Test 15
printf "\e[1;36mTest 15 Basic test with Buffer size 100\e[0;00m\n"
getnextline 100 maina.c basic
sleep $SLEEP

# Test 16
printf "\e[1;36mTest 16 Basic test with Buffer size 1000\e[0;00m\n"
getnextline 1000 maina.c basic
sleep $SLEEP

# Test 17
printf "\e[1;36mTest 17 Basic test with Buffer size 10000\e[0;00m\n"
getnextline 10000 maina.c basic
sleep $SLEEP

# Test 18
printf "\e[1;36mTest 18 Basic test with Buffer size 100000\e[0;00m\n"
getnextline 100000 maina.c basic
sleep $SLEEP

# Test 19
printf "\e[1;36mTest 19 Basic test with Buffer size 1000000\e[0;00m\n"
getnextline 1000000 maina.c basic
sleep $SLEEP

# Test 20
printf "\e[1;36mTest 20 Basic test with Buffer size 10000000\e[0;00m\n"
getnextline 10000000 maina.c basic
sleep $SLEEP

# Test 21
printf "\e[1;36mTest 21 300.000 character line with buffer size 1\e[0;00m\n"
getnextline 1 mainb.c extreme1
sleep $SLEEP

# Test 22
printf "\e[1;36mTest 22 300.000 character line with buffer size 100.000\e[0;00m\n"
getnextline 100000 mainb.c extreme1
sleep $SLEEP

# Test 23
printf "\e[1;36mTest 23 300.000 empty lines with buffer size 1\e[0;00m\n"
getnextline 1 mainc.c extreme2
sleep $SLEEP

# Test 24
printf "\e[1;36mTest 24 300.000 empty lines with buffer size 100.000\e[0;00m\n"
getnextline 100000 mainc.c extreme2
sleep $SLEEP

# Test 25
printf "\e[1;36mTest 25 All unicode characters with buffer size 1\e[0;00m\n"
getnextline 1 maine.c unicode
sleep $SLEEP

# Test 26
printf "\e[1;36mTest 26 All unicode characters with buffer size 100.000\e[0;00m\n"
getnextline 100000 maine.c unicode
sleep $SLEEP

# Test 27
printf "\e[1;36mTest 27 Reading from stdin buffer size 1\e[0;00m\n"
printf "Please type Hello, Press Enter and hit CTRL+D with every empty line\n"
getnextline 1 mainf.c hello
sleep $SLEEP

# Test 28
printf "\e[1;36mTest 28 Reading from stdin buffer size 100.000\e[0;00m\n"
printf "Please type Hello, Press Enter and hit CTRL+D with every empty line\n"
getnextline 100000 mainf.c hello
sleep $SLEEP

# Test 29
find ./ -name '*bonus.h' | grep bonus > /dev/null
if [ $? -eq 0 ]
then
	HEADLOC=$(find ./ -name '*bonus.h')
	cp $HEADLOC tests/tmp/get_next_line.h
fi
printf "\e[1;36mTest 29 Checking if Makefile bonus rule exists\e[0;00m\n"
make fclean > /dev/null
make bonus >/dev/null 2>&1
if [ $? -eq 2 ]
then
	printf "\e[1;31mNo bonus? I am a little dissapointed...\e[0;00m\n"
	if [ $FAULTS -eq 0 ]
	then
		printf "\e[1;35mBut we got no errors, Congratulations\e[0;00m\n"
		make fclean > /dev/null
		rm -rf tests/tmp
		exit 0
	else
		printf "\e[1;31mAnd we got $FAULTS errors\nSo that's a bummer\e[0;00m\n"
		make fclean > /dev/null
		rm -rf tests/tmp
		exit 1
	fi
fi
printf "\e[1;32mbonus rule OK\e[0;00m\n"
sleep $SLEEP

# Test 30
printf "\e[1;36mTest 30 Checking if Makefile relinks for bonus\e[0;00m\n"
relinkcheck bonus
sleep $SLEEP

# Test 31
printf "\e[1;36mTest 31 Reading from 2 files at once buffer size 1\e[0;00m\n"
getnextline 1 maind.c resd
sleep $SLEEP

# Test 32
printf "\e[1;36mTest 32 Reading from 2 files at once buffer size 100.000\e[0;00m\n"
getnextline 100000 maind.c resd
sleep $SLEEP

# Test 33
printf "\e[1;36mTest 33 Reading from 5 files at once buffer size 1\e[0;00m\n"
getnextline 1 maing.c resg
sleep $SLEEP

# Test 34
printf "\e[1;36mTest 34 Reading from 5 files at once buffer size 100.000\e[0;00m\n"
getnextline 100000 maing.c resg
sleep $SLEEP

# Conclusion
if [ $FAULTS -eq 0 ]
then
	printf "\e[1;35mwe got no errors, Congratulations\e[0;00m\n"
else
	printf "\e[1;31mwe got $FAULTS errors\nSo that's a bummer\e[0;00m\n"
	make fclean > /dev/null
	rm -rf tests/tmp
	exit 1
fi
make fclean > /dev/null
rm -rf tests/tmp
exit 0
