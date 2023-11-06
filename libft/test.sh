# **************************************************************************** #
#                                                                              #
#                                                     .--.  _                  #
#    test.sh                                         |o_o || |                 #
#                                                    |:_/ || |_ _   ___  __    #
#    By: houtworm <codam@houtworm.net>              //   \ \ __| | | \ \/ /    #
#                                                  (|     | )|_| |_| |>  <     #
#    Created: 2023/02/20 12:46:46 by houtworm     /'\_   _/`\__|\__,_/_/\_\    #
#    Updated: 2023/03/11 08:08:25 by houtworm     \___)=(___/                  #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

OS=$(uname -s)
FAULTS=0
PNAME=libft.a
VALGRIND=0
which valgrind > /dev/null
if [ $? -eq 0 ]
then
	VALGRIND=1
else
	printf "\n\e[1;31mInstall Valgrind for extra Memory Checking\e[0;00m\n"
fi
mkdir -p tests/tmp
HEADLOC=$(find ./ -name '*libft.h' | grep -v tests | grep -v ccls)
cp $HEADLOC tests/tmp/libft.h

testfunction()
{
	CURFUNERR=0
	rm tests/tmp/binary 2> /dev/null
	gcc -o tests/tmp/binary tests/$1.c libft.a 2> /dev/null
	./tests/tmp/binary
	if [ $? -ne 0 ]
	then
		printf "\n\e[1;31mKO $1 $2 \e[0;00m\n"
		FAULTS=$(($FAULTS+1))
		CURFUNERR=1
	else
		gcc -g -fsanitize=address -o tests/tmp/binary tests/$1.c libft.a 2> /dev/null
		./tests/tmp/binary 2> tests/tmp/memorycheck > /dev/null
		if [ $? -ne 0 ]
		then
			cat tests/tmp/memorycheck | grep "leaked" > /dev/null
			if [ $? -ne 1 ]
			then
				printf "\n\e[1;31mLeaks fsanitize $1 $2\e[0;00m\n"
				cat tests/tmp/memorycheck
				FAULTS=$(($FAULTS+1))
				CURFUNERR=1
			fi
			cat tests/tmp/memorycheck | grep "ABORT" > /dev/null
			if [ $? -ne 1 ]
			then
				printf "\n\e[1;31mError fsanitize $1 $2\e[0;00m\n"
				cat tests/tmp/memorycheck
				FAULTS=$(($FAULTS+1))
				CURFUNERR=1
			fi
		elif [ $VALGRIND -eq 1 ]
		then
			gcc -o tests/tmp/binary tests/$1.c libft.a 2> /dev/null
			valgrind --leak-check=full ./tests/tmp/binary 2> tests/tmp/memorycheck > /dev/null
			cat tests/tmp/memorycheck | grep indirectly | grep "[123456789] bytes" > /dev/null
			if [ $? -eq 0 ]
			then
				printf "\n\e[1;31mLeaks Valgrind $1 $2\e[0;00m\n"
				cat tests/tmp/memorycheck
				FAULTS=$(($FAULTS+1))
				CURFUNERR=1
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
	fi
	if [ $CURFUNERR -eq 0 ]
	then
		printf "\e[1;32mOK \e[0;00m"
	fi
}

expectfsanitize()
{
	CURFUNERR=0
	gcc -o tests/tmp/binary tests/$1.c libft.a 2> /dev/null
	./tests/tmp/binary
	if [ $? -ne 0 ]
	then
		printf "\n\e[1;31mKO $1 $2 \e[0;00m\n"
		FAULTS=$(($FAULTS+1))
		CURFUNERR=1
	else
		gcc -g -fsanitize=address -o tests/tmp/binary tests/$1.c libft.a 2> /dev/null
		./tests/tmp/binary 2> tests/tmp/memorycheck > /dev/null
		if [ $3 ]
		then
			cat tests/tmp/memorycheck | grep "heap-buffer-overflow" > /dev/null
			if [ $? -eq 1 ]
			then
				printf "\n\e[1;31mYour calloc mallocs too much bytes $1 $2\e[0;00m\n"
				FAULTS=$(($FAULTS+1))
				CURFUNERR=1
			fi
		elif [ $? -ne 0 ]
		then
			cat tests/tmp/memorycheck | grep "leaked" > /dev/null
			if [ $? -ne 0 ]
			then
				printf "\n\e[1;31mNo Malloc $1 $2\e[0;00m\n"
				FAULTS=$(($FAULTS+1))
				CURFUNERR=1
			fi
			cat tests/tmp/memorycheck | grep "ABORT" > /dev/null
			if [ $? -ne 1 ]
			then
				printf "\n\e[1;31mError fsanitize $1 $2\e[0;00m\n"
				cat tests/tmp/memorycheck
				FAULTS=$(($FAULTS+1))
				CURFUNERR=1
			fi
		fi
	fi
	if [ $CURFUNERR -eq 0 ]
	then
		printf "\e[1;32mOK \e[0;00m"
	fi
}

testprintstdout()
{
	CURFUNERR=0
	gcc -o tests/tmp/binary tests/$1.c libft.a 2> /dev/null
	./tests/tmp/binary > tests/tmp/output
	#mv tests/tmp/output tests/expected/$1 #write expected files
	diff tests/tmp/output tests/expected/$1
	if [ $? -ne 0 ]
	then
		printf "\n\e[1;31mKO $1 $2 \e[0;00m\n"
		FAULTS=$(($FAULTS+1))
		CURFUNERR=1
	else
		gcc -g -fsanitize=address -o tests/tmp/binary tests/$1.c libft.a 2> /dev/null
		./tests/tmp/binary > /dev/null 2> tests/tmp/memorycheck
		if [ $3 ]
		then
			cat tests/tmp/memorycheck | grep "heap-buffer-overflow" > /dev/null
			if [ $? -eq 1 ]
			then
				printf "\n\e[1;31mYour calloc mallocs too much bytes $1 $2\e[0;00m\n"
				FAULTS=$(($FAULTS+1))
				CURFUNERR=1
			fi
		elif [ $? -ne 0 ]
		then
			cat tests/tmp/memorycheck | grep "leaked" > /dev/null
			if [ $? -ne 1 ]
			then
				printf "\n\e[1;31mLeaks fsanitize $1 $2\e[0;00m\n"
				cat tests/tmp/memorycheck
				FAULTS=$(($FAULTS+1))
				CURFUNERR=1
			fi
			cat tests/tmp/memorycheck | grep "ABORT" > /dev/null
			if [ $? -ne 1 ]
			then
				printf "\n\e[1;31mError fsanitize $1 $2\e[0;00m\n"
				cat tests/tmp/memorycheck
				FAULTS=$(($FAULTS+1))
				CURFUNERR=1
			fi
		fi
	fi
	if [ $CURFUNERR -eq 0 ]
	then
		printf "\e[1;32mOK \e[0;00m"
	fi
}

testprintstderr()
{
	CURFUNERR=0
	gcc -o tests/tmp/binary tests/$1.c libft.a 2> /dev/null
	./tests/tmp/binary 2> tests/tmp/output
	#mv tests/tmp/output tests/expected/$1 #write expected files
	diff tests/tmp/output tests/expected/$1
	if [ $? -ne 0 ]
	then
		printf "\n\e[1;31mKO $1 $2 \e[0;00m\n"
		FAULTS=$(($FAULTS+1))
		CURFUNERR=1
	else
		gcc -g -fsanitize=address -o tests/tmp/binary tests/$1.c libft.a 2> /dev/null
		./tests/tmp/binary 2> tests/tmp/memorycheck
		if [ $3 ]
		then
			cat tests/tmp/memorycheck | grep "heap-buffer-overflow" > /dev/null
			if [ $? -eq 1 ]
			then
				printf "\n\e[1;31mYour calloc mallocs too much bytes $1 $2\e[0;00m\n"
				FAULTS=$(($FAULTS+1))
				CURFUNERR=1
			fi
		elif [ $? -ne 0 ]
		then
			cat tests/tmp/memorycheck | grep "leaked" > /dev/null
			if [ $? -ne 1 ]
			then
				printf "\n\e[1;31mLeaks fsanitize $1 $2\e[0;00m\n"
				cat tests/tmp/memorycheck
				FAULTS=$(($FAULTS+1))
				CURFUNERR=1
			fi
			cat tests/tmp/memorycheck | grep "ABORT" > /dev/null
			if [ $? -ne 1 ]
			then
				printf "\n\e[1;31mError fsanitize $1 $2\e[0;00m\n"
				cat tests/tmp/memorycheck
				FAULTS=$(($FAULTS+1))
				CURFUNERR=1
			fi
		fi
	fi
	if [ $CURFUNERR -eq 0 ]
	then
		printf "\e[1;32mOK \e[0;00m"
	fi
}

testprintstdin()
{
	CURFUNERR=0
	gcc -o tests/tmp/binary tests/$1.c libft.a 2> /dev/null
	./tests/tmp/binary 0> tests/tmp/output > /dev/null
	#mv tests/tmp/output tests/expected/$1 #write expected files
	diff tests/tmp/output tests/expected/$1
	if [ $? -ne 0 ]
	then
		printf "\n\e[1;31mKO $1 $2 \e[0;00m\n"
		FAULTS=$(($FAULTS+1))
		CURFUNERR=1
	else
		gcc -g -fsanitize=address -o tests/tmp/binary tests/$1.c libft.a 2> /dev/null 
		./tests/tmp/binary 2> tests/tmp/memorycheck 0> /dev/null
		if [ $3 ]
		then
			cat tests/tmp/memorycheck | grep "heap-buffer-overflow" > /dev/null
			if [ $? -eq 1 ]
			then
				printf "\n\e[1;31mYour calloc mallocs too much bytes $1 $2\e[0;00m\n"
				FAULTS=$(($FAULTS+1))
				CURFUNERR=1
			fi
		elif [ $? -ne 0 ]
		then
			cat tests/tmp/memorycheck | grep "leaked" > /dev/null
			if [ $? -ne 1 ]
			then
				printf "\n\e[1;31mLeaks fsanitize $1 $2\e[0;00m\n"
				cat tests/tmp/memorycheck
				FAULTS=$(($FAULTS+1))
				CURFUNERR=1
			fi
			cat tests/tmp/memorycheck | grep "ABORT" > /dev/null
			if [ $? -ne 1 ]
			then
				printf "\n\e[1;31mError fsanitize $1 $2\e[0;00m\n"
				cat tests/tmp/memorycheck
				FAULTS=$(($FAULTS+1))
				CURFUNERR=1
			fi
		fi
	fi
	if [ $CURFUNERR -eq 0 ]
	then
		printf "\e[1;32mOK \e[0;00m"
	fi
}

testprintfd4()
{
	CURFUNERR=0
	gcc -o tests/tmp/binary tests/$1.c libft.a 2> /dev/null
	./tests/tmp/binary 4> tests/tmp/output
	#mv tests/tmp/output tests/expected/$1 #write expected files
	diff tests/tmp/output tests/expected/$1
	if [ $? -ne 0 ]
	then
		printf "\n\e[1;31mKO $1 $2 \e[0;00m\n"
		FAULTS=$(($FAULTS+1))
		CURFUNERR=1
	else
		gcc -g -fsanitize=address -o tests/tmp/binary tests/$1.c libft.a 2> /dev/null
		./tests/tmp/binary 2> tests/tmp/memorycheck 4> /dev/null
		if [ $3 ]
		then
			cat tests/tmp/memorycheck | grep "heap-buffer-overflow" > /dev/null
			if [ $? -eq 1 ]
			then
				printf "\n\e[1;31mYour calloc mallocs too much bytes $1 $2\e[0;00m\n"
				FAULTS=$(($FAULTS+1))
				CURFUNERR=1
			fi
		elif [ $? -ne 0 ]
		then
			cat tests/tmp/memorycheck | grep "leaked" > /dev/null
			if [ $? -ne 1 ]
			then
				printf "\n\e[1;31mLeaks fsanitize $1 $2\e[0;00m\n"
				cat tests/tmp/memorycheck
				FAULTS=$(($FAULTS+1))
				CURFUNERR=1
			fi
			cat tests/tmp/memorycheck | grep "ABORT" > /dev/null
			if [ $? -ne 1 ]
			then
				printf "\n\e[1;31mError fsanitize $1 $2\e[0;00m\n"
				cat tests/tmp/memorycheck
				FAULTS=$(($FAULTS+1))
				CURFUNERR=1
			fi
		fi
	fi
	if [ $CURFUNERR -eq 0 ]
	then
		printf "\e[1;32mOK \e[0;00m"
	fi
}

checkfile()
{
	ls $1 2> /dev/null | grep $1 > /dev/null
	if [ $? -ne $2 ]
	then
		printf "\e[1;31m\nMakefile does not create $1\e[0;00m\n"
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
			printf "\e[1;31m\nObject files found after clean\e[0;00m\n"
			FAULTS=$(($FAULTS+1))
		fi
	fi
	if [ $1 -eq 1 ]
	then
		if [ $FILES -eq 0 ]
		then
			printf "\e[1;31m\nObject files not found after make\e[0;00m\n"
			FAULTS=$(($FAULTS+1))
		fi
	fi
}

checkrule()
{
	make $1 > /dev/null 2>&1
	if [ $? -eq 2 ]
	then
		printf "\e[1;31m\nMissing rule $1\e[0;00m\n"
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
		printf "\e[1;32mOK\e[0;00m"
	fi
}

# Norm Check
printf "\e[1;36mTesting Source with Norminette \e[0;00m"
norminette $(find ./ -name '*.[ch]' | grep -v ./tests/ | grep -v ccls) > tests/tmp/norm
if [ $? -eq 1 ]
then
	printf "\e[1;31m\nYour shit is not norm!\e[0;00m"
	cat tests/tmp/norm | grep Error
	FAULTS=$(($FAULTS+1))
else
	printf "\e[1;32mOK\e[0;00m"
fi
printf "\n"

# Makefile Rule Check
printf "\e[1;36mTesting Makefile Rules \e[0;00m"
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
	printf "\e[1;32mOK\e[0;00m"
fi
printf "\n"

# Makefile Relink Check
printf "\e[1;36mTesting Makefile Relink \e[0;00m"
relinkcheck
printf "\n"

# ft_atoi
printf "\e[1;36mTesting ft_atoi \e[0;00m"
testfunction mandatory/atoi/test1 "Does not work with simple 12345"
testfunction mandatory/atoi/test2 "Does not work with Min int"
testfunction mandatory/atoi/test3 "Does not work with Max int"
testfunction mandatory/atoi/test4 "Does not work with 0"
testfunction mandatory/atoi/test5 "Does not work with Overflow"
testfunction mandatory/atoi/test6 "Does not work with hallo as string"
testfunction mandatory/atoi/test7 "Does not work with Letter in middle string"
testfunction mandatory/atoi/test8 "Does not work with Letter at end of string"
testfunction mandatory/atoi/test9 "Does not work with Minus in middle string"
testfunction mandatory/atoi/test10 "Does not work with Plus in middle string"
testfunction mandatory/atoi/test11 "Does not work with Space in middle string"
testfunction mandatory/atoi/test12 "Does not work with NULL string"
testfunction mandatory/atoi/test13 "Does not work with Plus beginning string"
#testfunction mandatory/atoi/test14 "max int + 1"
#testfunction mandatory/atoi/test15 "min int - 1"
#testfunction mandatory/atoi/test16 "string with only \\0"
#testfunction mandatory/atoi/test17 "\\t\\t1234\\t\\t"
testfunction mandatory/atoi/test18 "\\n654\\n"
testfunction mandatory/atoi/test19 "nothing"
testfunction mandatory/atoi/test20 "c0ngr4tulat1ons"
printf "\n"

# ft_bzero
printf "\e[1;36mTesting ft_bzero \e[0;00m"
testfunction mandatory/bzero/test1 "Does not work with NULL string"
testfunction mandatory/bzero/test2 "Does not work with More bytes than strlen"
testfunction mandatory/bzero/test3 "Does not work with 0 bytes"
testfunction mandatory/bzero/test4 "Does not work with 1 byte"
testfunction mandatory/bzero/test5 "bzero is not writing zeros"
printf "\n"

# ft_calloc
printf "\e[1;36mTesting ft_calloc \e[0;00m"
testfunction mandatory/calloc/test1 'Calloced string is not all \\0'
testfunction mandatory/calloc/test2 "Your size too small"
expectfsanitize mandatory/calloc/test3 "Your size too big" 1
testfunction mandatory/calloc/test4 "first arg 0"
testfunction mandatory/calloc/test5 "second arg 0"
#testfunction mandatory/calloc/test6 "first arg -1"
#testfunction mandatory/calloc/test7 "second arg -1"
testfunction mandatory/calloc/test8 "count is too small"
expectfsanitize mandatory/calloc/test9 "count is too big" 1
printf "\n"

# ft_isalnum
printf "\e[1;36mTesting ft_isalnum \e[0;00m"
testfunction mandatory/isalnum/test1 '0'
testfunction mandatory/isalnum/test2 '9'
testfunction mandatory/isalnum/test3 'a'
testfunction mandatory/isalnum/test4 'A'
testfunction mandatory/isalnum/test5 'z'
testfunction mandatory/isalnum/test6 'Z'
testfunction mandatory/isalnum/test7 '/'
testfunction mandatory/isalnum/test8 ':'
testfunction mandatory/isalnum/test9 '@'
testfunction mandatory/isalnum/test10 '['
testfunction mandatory/isalnum/test11 '{'
testfunction mandatory/isalnum/test12 '`'
testfunction mandatory/isalnum/test13 '~'
testfunction mandatory/isalnum/test14 ','
testfunction mandatory/isalnum/test15 "'"
testfunction mandatory/isalnum/test16 'space'
testfunction mandatory/isalnum/test17 '\0'
testfunction mandatory/isalnum/test18 '128'
testfunction mandatory/isalnum/test19 'newline'
testfunction mandatory/isalnum/test20 '-1'
printf "\n"

# ft_isalpha
printf "\e[1;36mTesting ft_isalpha \e[0;00m"
testfunction mandatory/isalpha/test1 'a'
testfunction mandatory/isalpha/test2 'A'
testfunction mandatory/isalpha/test3 'z'
testfunction mandatory/isalpha/test4 'Z'
testfunction mandatory/isalpha/test5 '0'
testfunction mandatory/isalpha/test6 '9'
testfunction mandatory/isalpha/test7 '@'
testfunction mandatory/isalpha/test8 '['
testfunction mandatory/isalpha/test9 '{'
testfunction mandatory/isalnum/test10 '`'
testfunction mandatory/isalnum/test11 '~'
testfunction mandatory/isalnum/test12 '\\'
testfunction mandatory/isalnum/test13 ';'
testfunction mandatory/isalnum/test14 ','
testfunction mandatory/isalnum/test15 "'"
testfunction mandatory/isalpha/test16 'space'
testfunction mandatory/isalpha/test17 '\\0'
testfunction mandatory/isalpha/test18 '128'
testfunction mandatory/isalpha/test19 'newline'
testfunction mandatory/isalpha/test20 '-1'
printf "\n"

# ft_isascii
printf "\e[1;36mTesting ft_isascii \e[0;00m"
testfunction mandatory/isascii/test1 '1'
testfunction mandatory/isascii/test2 '127'
testfunction mandatory/isascii/test3 'a'
testfunction mandatory/isascii/test4 '\\n'
testfunction mandatory/isascii/test5 '\\0'
testfunction mandatory/isascii/test6 '\\t'
testfunction mandatory/isascii/test7 ' '
testfunction mandatory/isascii/test8 '0'
testfunction mandatory/isascii/test9 '128'
testfunction mandatory/isascii/test10 '255'
testfunction mandatory/isascii/test11 '-1'
printf "\n"

# ft_isdigit
printf "\e[1;36mTesting ft_isdigit \e[0;00m"
testfunction mandatory/isdigit/test1 '0'
testfunction mandatory/isdigit/test2 '1'
testfunction mandatory/isdigit/test3 '2'
testfunction mandatory/isdigit/test4 '3'
testfunction mandatory/isdigit/test5 '4'
testfunction mandatory/isdigit/test6 '5'
testfunction mandatory/isdigit/test7 '6'
testfunction mandatory/isdigit/test8 '7'
testfunction mandatory/isdigit/test9 '8'
testfunction mandatory/isdigit/test10 '9'
testfunction mandatory/isdigit/test11 '\\n'
testfunction mandatory/isdigit/test12 '\\0'
testfunction mandatory/isdigit/test13 '\\t'
testfunction mandatory/isdigit/test14 'a'
testfunction mandatory/isdigit/test15 'z'
testfunction mandatory/isdigit/test16 'A'
testfunction mandatory/isdigit/test17 '/'
testfunction mandatory/isdigit/test18 ':'
testfunction mandatory/isdigit/test19 '+'
testfunction mandatory/isdigit/test20 '-'
printf "\n"

# ft_isprint
printf "\e[1;36mTesting ft_isprint \e[0;00m"
testfunction mandatory/isprint/test1 'a'
testfunction mandatory/isprint/test2 '\\n'
testfunction mandatory/isprint/test3 'space'
testfunction mandatory/isprint/test4 '~'
testfunction mandatory/isprint/test5 '31'
testfunction mandatory/isprint/test6 '127'
testfunction mandatory/isprint/test7 '255'
testfunction mandatory/isprint/test8 '\\'
testfunction mandatory/isprint/test9 '*'
testfunction mandatory/isprint/test10 '%'
testfunction mandatory/isprint/test11 '\\0'
printf "\n"

# ft_itoa
printf "\e[1;36mTesting ft_itoa \e[0;00m"
testfunction mandatory/itoa/test1 '12345'
testfunction mandatory/itoa/test2 'int min'
testfunction mandatory/itoa/test3 'int max'
#expectfsanitize mandatory/itoa/test4 'check if malloced' #instable sometimes
testfunction mandatory/itoa/test5 '0'
testfunction mandatory/itoa/test6 'int max + 1'
testfunction mandatory/itoa/test7 'int min - 1'
printf "\n"

# ft_memccpy
printf "\e[1;36mTesting ft_memccpy \e[0;00m"
testfunction mandatory/memccpy/test1 'write 3 bytes'
testfunction mandatory/memccpy/test2 'write 6 bytes but src[3] = c'
testfunction mandatory/memccpy/test3 'src is only c'
testfunction mandatory/memccpy/test4 'length 0'
#testfunction mandatory/memccpy/test5 'length -1'
testfunction mandatory/memccpy/test6 'no c in src'
testfunction mandatory/memccpy/test7 'length is bigger than src'
testfunction mandatory/memccpy/test8 'lenght is bigger than dst'
testfunction mandatory/memccpy/test9 'check with \\0 in string'
testfunction mandatory/memccpy/test10 'src NULL'
testfunction mandatory/memccpy/test11 'dst NULL'
testfunction mandatory/memccpy/test11 'src & dst NULL'
testfunction mandatory/memccpy/test12 'c = \\0'
printf "\n"

# ft_memchr
printf "\e[1;36mTesting ft_memchr \e[0;00m"
testfunction mandatory/memchr/test1 'Match at third byte'
testfunction mandatory/memchr/test2 'Match at first byte'
testfunction mandatory/memchr/test3 'Match at last byte'
testfunction mandatory/memchr/test4 'Match 1 byte further than length'
testfunction mandatory/memchr/test5 'No match lenght longer than string'
testfunction mandatory/memchr/test6 'string == NULL'
testfunction mandatory/memchr/test7 'lenght = 0'
testfunction mandatory/memchr/test8 'copy over \\0\\0'
testfunction mandatory/memchr/test9 'char = \\0'
printf "\n"

# ft_memcmp
printf "\e[1;36mTesting ft_memcmp \e[0;00m"
testfunction mandatory/memcmp/test1 'Checking if p2 is subtracted from p1'
testfunction mandatory/memcmp/test2 'Diff 1 byte after lenght'
testfunction mandatory/memcmp/test3 'Match at first byte'
testfunction mandatory/memcmp/test4 'Match at last byte of length'
testfunction mandatory/memcmp/test5 'Match 1 byte longer than length'
testfunction mandatory/memcmp/test6 'check with \\0 in string 1'
testfunction mandatory/memcmp/test7 'check with \\0 in string 2'
testfunction mandatory/memcmp/test8 'check with \\n in string 1'
testfunction mandatory/memcmp/test9 'check with \\n in string 2'
testfunction mandatory/memcmp/test10 'int 0'
#testfunction mandatory/memcmp/test11 'int -1'
testfunction mandatory/memcmp/test12 'int longer than first string'
testfunction mandatory/memcmp/test13 'int longer than second string'
testfunction mandatory/memcmp/test14 'int longer than both strings'
testfunction mandatory/memcmp/test15 'First string NULL'
testfunction mandatory/memcmp/test16 'Second string NULL'
testfunction mandatory/memcmp/test17 'both strings NULL'
printf "\n"

# ft_memcpy
printf "\e[1;36mTesting ft_memcpy \e[0;00m"
testfunction mandatory/memcpy/test1 'Simple writing test'
testfunction mandatory/memcpy/test2 'You write too little'
testfunction mandatory/memcpy/test3 'You write too much'
testfunction mandatory/memcpy/test4 'length longer than src'
testfunction mandatory/memcpy/test5 'lenght longer than dst'
testfunction mandatory/memcpy/test6 'lenght 0'
testfunction mandatory/memcpy/test7 'copy over \\0\\0'
testfunction mandatory/memcpy/test8 'src NULL'
testfunction mandatory/memcpy/test9 'dst NULL'
testfunction mandatory/memcpy/test9 'src & dst NULL'
printf "\n"

# ft_memmove
printf "\e[1;36mTesting ft_memmove \e[0;00m"
testfunction mandatory/memmove/test1 'Basic test moving bytes'
testfunction mandatory/memmove/test2 'Moving 3 bytes'
testfunction mandatory/memmove/test3 'Moving 5 bytes'
testfunction mandatory/memmove/test4 'You move too little'
testfunction mandatory/memmove/test5 'You move too much'
testfunction mandatory/memmove/test6 'Length longer than src'
testfunction mandatory/memmove/test7 'Length longer than dst'
testfunction mandatory/memmove/test8 'Length is 0'
testfunction mandatory/memmove/test9 'Move over \\0\\0'
testfunction mandatory/memmove/test10 'Overlapping char*'
testfunction mandatory/memmove/test11 'Overlapping char*'
testfunction mandatory/memmove/test12 'dst = NULL'
testfunction mandatory/memmove/test13 'src = NULL'
testfunction mandatory/memmove/test14 'src & dst = NULL'
printf "\n"

# ft_memset
printf "\e[1;36mTesting ft_memset \e[0;00m"
testfunction mandatory/memset/test1 'Basic test'
testfunction mandatory/memset/test2 'You write too much'
testfunction mandatory/memset/test3 'You write too little'
testfunction mandatory/memset/test4 'character \\0'
testfunction mandatory/memset/test5 'character \\n'
testfunction mandatory/memset/test6 'character \\t'
testfunction mandatory/memset/test7 'int longer than string'
testfunction mandatory/memset/test8 'int 0'
testfunction mandatory/memset/test9 'string = NULL'
printf "\n"

# ft_putchar_fd
printf "\e[1;36mTesting ft_putchar_fd \e[0;00m"
testprintstdout mandatory/putchar_fd/test1 'a'
testprintstdout mandatory/putchar_fd/test2 'z'
testprintstdout mandatory/putchar_fd/test3 '1'
testprintstdout mandatory/putchar_fd/test4 '0'
testprintstdout mandatory/putchar_fd/test5 '4'
testprintstdout mandatory/putchar_fd/test6 '8'
testprintstdout mandatory/putchar_fd/test7 '7'
testprintstdout mandatory/putchar_fd/test8 '10'
testprintstdout mandatory/putchar_fd/test9 '13'
testprintstdout mandatory/putchar_fd/test10 '24'
testprintstdout mandatory/putchar_fd/test11 '\\n'
testprintstdout mandatory/putchar_fd/test12 '\\0'
testprintstdout mandatory/putchar_fd/test13 255
testprintstdout mandatory/putchar_fd/test14 -1
testprintstdout mandatory/putchar_fd/test15 'all chars'
testprintstderr mandatory/putchar_fd/test16 'a'
testprintstderr mandatory/putchar_fd/test17 '.'
testprintstderr mandatory/putchar_fd/test18 '\\n'
testprintstderr mandatory/putchar_fd/test19 '-1'
testprintstderr mandatory/putchar_fd/test20 '128'
printf "\n"

# ft_putendl_fd
printf "\e[1;36mTesting ft_putendl_fd \e[0;00m"
testprintstdout mandatory/putendl_fd/test1 'a'
testprintfd4 mandatory/putendl_fd/test2 'abc'
testprintstdout mandatory/putendl_fd/test3 'all chars'
testprintstdout mandatory/putendl_fd/test4 'huge fucking string'
testprintstdout mandatory/putendl_fd/test5 '\\0hallo'
testprintstdin mandatory/putendl_fd/test6 'br\\tan\\tdw\\teer'
testprintstdout mandatory/putendl_fd/test7 '\\;'
testprintstdout mandatory/putendl_fd/test8 'hallo\0'
testprintfd4 mandatory/putendl_fd/test9 'hal\\0lo'
testprintstdout mandatory/putendl_fd/test10 '\\n\\t\\0\\n'
testprintstdout mandatory/putendl_fd/test11 '\\n\\n'
testprintstdout mandatory/putendl_fd/test12 '\\0\\0\\0'
testprintstdout mandatory/putendl_fd/test13 'NULL'
testprintstderr mandatory/putendl_fd/test14 'all chars'
testprintstderr mandatory/putendl_fd/test15 '\\0hallo'
testprintstderr mandatory/putendl_fd/test16 'hall\\0o'
testprintstderr mandatory/putendl_fd/test17 '\\n'
testprintstderr mandatory/putendl_fd/test18 '\\n\\t\\0\\n'
testprintstderr mandatory/putendl_fd/test19 '\\0\\0\\0'
testprintstderr mandatory/putendl_fd/test20 'NULL'
printf "\n"

# ft_putnbr_fd
printf "\e[1;36mTesting ft_putnbr_fd \e[0;00m"
testprintstdout mandatory/putnbr_fd/test1 '12345'
testprintstdout mandatory/putnbr_fd/test2 'min int'
testprintstdout mandatory/putnbr_fd/test3 'max int'
testprintstdout mandatory/putnbr_fd/test4 '0'
testprintstdout mandatory/putnbr_fd/test5 'Max int + 1'
testprintstdout mandatory/putnbr_fd/test6 'min int - 1'
testprintstdout mandatory/putnbr_fd/test7 'numbers 1 - 10.000'
testprintstdout mandatory/putnbr_fd/test8 'numbers 100.000 to 110.000'
testprintstdout mandatory/putnbr_fd/test9 'numbers 500.000 to 520.000'
testprintstdout mandatory/putnbr_fd/test10 'numbers 1M to 1.01M'
testprintstderr mandatory/putnbr_fd/test11 '12345'
testprintstderr mandatory/putnbr_fd/test12 'min int'
testprintstderr mandatory/putnbr_fd/test13 'max int'
testprintstderr mandatory/putnbr_fd/test14 '0'
testprintstderr mandatory/putnbr_fd/test15 'max int + 1'
testprintstderr mandatory/putnbr_fd/test16 'min int -1'
testprintstderr mandatory/putnbr_fd/test17 'numbers 70.000 - 80.000'
testprintstderr mandatory/putnbr_fd/test19 'numbers 200.000 to 210.000'
testprintstderr mandatory/putnbr_fd/test18 'numbers 700.000 to 720.000'
testprintstderr mandatory/putnbr_fd/test20 'numbers 2M to 2.01M'
printf "\n"

# ft_putstr_fd
printf "\e[1;36mTesting ft_putstr_fd \e[0;00m"
testprintstdout mandatory/putstr_fd/test1 'a'
testprintfd4 mandatory/putstr_fd/test2 'abc'
testprintstdout mandatory/putstr_fd/test3 'all chars'
testprintstdout mandatory/putstr_fd/test4 'huge fucking string'
testprintstdout mandatory/putstr_fd/test5 '\\0hallo'
testprintstdin mandatory/putstr_fd/test6 'br\\tan\\tdw\\teer'
testprintstdout mandatory/putstr_fd/test7 '\\;'
testprintstdout mandatory/putstr_fd/test8 'hallo\\0'
testprintfd4 mandatory/putstr_fd/test9 'hal\\0lo'
testprintstdout mandatory/putstr_fd/test10 '\\n\\t\\0\\n'
testprintstdout mandatory/putstr_fd/test11 '\\n\\n'
testprintstdout mandatory/putstr_fd/test12 '\\0\\0\\0'
testprintstdout mandatory/putstr_fd/test13 'NULL'
testprintstderr mandatory/putstr_fd/test14 'all chars'
testprintstderr mandatory/putstr_fd/test15 '\\0hallo'
testprintstderr mandatory/putstr_fd/test16 'hall\\0o'
testprintstderr mandatory/putstr_fd/test17 '\\n'
testprintstderr mandatory/putstr_fd/test18 '\\n\\t\\0\\n'
testprintstderr mandatory/putstr_fd/test19 '\\0\\0\\0'
testprintstderr mandatory/putstr_fd/test20 'NULL'
printf "\n"

# ft_split
printf "\e[1;36mTesting ft_split \e[0;00m"
testfunction mandatory/split/test1 'Does not work with Basic Input'
testfunction mandatory/split/test2 'Does not work without delimiter in string'
testfunction mandatory/split/test3 'Does not work with \\0 character in string'
testfunction mandatory/split/test4 'Does not work with \\n character in string'
testfunction mandatory/split/test5 'Does not work with delimiter at end and begin'
testfunction mandatory/split/test6 'Does not work with tabs'
testfunction mandatory/split/test7 'Does not place \\0 at end of splitted strings'
testfunction mandatory/split/test8 'Does not work with \\0 as delimiter'
testfunction mandatory/split/test9 'Does not place NULL at end of array'
testfunction mandatory/split/test10 'Does not work with delimiter at end'
testfunction mandatory/split/test11 'Does not work with delimiter at begin'
testfunction mandatory/split/test12 'Does not work with only delimiters in string'
testfunction mandatory/split/test13 'non ascii delimiter'
testfunction mandatory/split/test14 'string = NULL'
printf "\n"

# ft_strchr
printf "\e[1;36mTesting ft_strchr \e[0;00m"
testfunction mandatory/strchr/test1 'Match at third byte'
testfunction mandatory/strchr/test2 'Match at first byte'
testfunction mandatory/strchr/test3 'Match at last byte'
testfunction mandatory/strchr/test4 'string == NULL'
testfunction mandatory/strchr/test5 'make sure it stops at \\0'
testfunction mandatory/strchr/test6 'char = \\0'
testfunction mandatory/strchr/test7 'check if it places \\0 at end'
printf "\n"

# ft_strdup
printf "\e[1;36mTesting ft_strdup \e[0;00m"
testfunction mandatory/strdup/test1 'basic test'
testfunction mandatory/strdup/test2 'You need to stop at \\0'
testfunction mandatory/strdup/test3 'Test with \\t'
testfunction mandatory/strdup/test4 'Test with \\n'
testfunction mandatory/strdup/test5 'You need to terminate string with \\0'
testfunction mandatory/strdup/test6 'str = "\\0\\0"'
testfunction mandatory/strdup/test7 'str = NULL'
printf "\n"

# ft_strjoin
printf "\e[1;36mTesting ft_strjoin \e[0;00m"
testfunction mandatory/strjoin/test1 'Basic test'
testfunction mandatory/strjoin/test2 'check /0 at end'
testfunction mandatory/strjoin/test3 'test with \\n'
testfunction mandatory/strjoin/test4 'test with \\t'
testfunction mandatory/strjoin/test5 'string 1 is \\0\\0'
testfunction mandatory/strjoin/test6 'string 2 is \\0\\0'
testfunction mandatory/strjoin/test7 'Both strings are \\0\\0'
testfunction mandatory/strjoin/test8 'String 1 is NULL'
testfunction mandatory/strjoin/test9 'String 2 is NULL'
testfunction mandatory/strjoin/test10 'Both strings are NULL'
printf "\n"

# ft_strlcat
printf "\e[1;36mTesting ft_strlcat \e[0;00m"
testfunction mandatory/strlcat/test1 'Basic test'
testfunction mandatory/strlcat/test2 'Return values'
testfunction mandatory/strlcat/test3 'check \\0 at end'
testfunction mandatory/strlcat/test4 'Check return value if not writing whole src'
testfunction mandatory/strlcat/test5 'half src'
testfunction mandatory/strlcat/test6 'string 1 is \\0\\0'
testfunction mandatory/strlcat/test7 'string 2 is \\0\\0'
testfunction mandatory/strlcat/test8 'Both strings are \\0\\0'
testfunction mandatory/strlcat/test9 'String 1 is NULL'
testfunction mandatory/strlcat/test10 'String 2 is NULL'
testfunction mandatory/strlcat/test11 'Both strings are NULL'
printf "\n"

# ft_strlcpy
printf "\e[1;36mTesting ft_strlcpy \e[0;00m"
testfunction mandatory/strlcpy/test1 'Simple writing test'
testfunction mandatory/strlcpy/test2 'You write too little'
testfunction mandatory/strlcpy/test3 'You write too much'
testfunction mandatory/strlcpy/test4 'Return values write more than src'
testfunction mandatory/strlcpy/test5 'Return values write less than src'
testfunction mandatory/strlcpy/test6 'length longer than src'
testfunction mandatory/strlcpy/test7 'lenght longer than dst'
testfunction mandatory/strlcpy/test8 'lenght 0'
testfunction mandatory/strlcpy/test9 'stop at \\0'
testfunction mandatory/strlcpy/test10 'src = \\0\\0'
testfunction mandatory/strlcpy/test11 'dst = \\0\\0'
testfunction mandatory/strlcpy/test12 'src NULL'
testfunction mandatory/strlcpy/test13 'dst NULL'
testfunction mandatory/strlcpy/test14 'src and dst NULL'
printf "\n"

# ft_strlen
printf "\e[1;36mTesting ft_strlen \e[0;00m"
testfunction mandatory/strlen/test1 'Basic test'
testfunction mandatory/strlen/test2 'Length 1'
testfunction mandatory/strlen/test3 'Length 50'
testfunction mandatory/strlen/test4 '\\n'
testfunction mandatory/strlen/test5 '\\t'
testfunction mandatory/strlen/test6 'making sure it stops at \\0'
testfunction mandatory/strlen/test7 'str = \\0'
testfunction mandatory/strlen/test8 'str = NULL'
printf "\n"

# ft_strmapi
printf "\e[1;36mTesting ft_strmapi \e[0;00m"
testfunction mandatory/strmapi/test1 'basic test'
testfunction mandatory/strmapi/test2 'basic test with toupper'
testfunction mandatory/strmapi/test3 'basic test with tolower'
testfunction mandatory/strmapi/test4 'basic test with isdigit'
testfunction mandatory/strmapi/test5 'Function = NULL'
testfunction mandatory/strmapi/test6 'string = NULL'
printf "\n"

# ft_strncmp
printf "\e[1;36mTesting ft_strncmp \e[0;00m"
testfunction mandatory/strncmp/test1 'basic test'
testfunction mandatory/strncmp/test2 'diff at first char'
testfunction mandatory/strncmp/test3 'comparing too much'
testfunction mandatory/strncmp/test4 'comparing too little'
testfunction mandatory/strncmp/test5 'stop at \\0 str1'
testfunction mandatory/strncmp/test6 'stop at \\0 str2'
testfunction mandatory/strncmp/test7 'checking that p2 is subtracted from p1'
testfunction mandatory/strncmp/test8 'length is 0'
testfunction mandatory/strncmp/test9 'string 1 is \\0\\0'
testfunction mandatory/strncmp/test10 'string 2 is \\0\\0'
testfunction mandatory/strncmp/test11 'Both strings are \\0\\0'
testfunction mandatory/strncmp/test12 'String 1 is NULL'
testfunction mandatory/strncmp/test13 'String 2 is NULL'
testfunction mandatory/strncmp/test14 'Both strings are NULL'
printf "\n"

# ft_strnstr
printf "\e[1;36mTesting ft_strnstr \e[0;00m"
testfunction mandatory/strnstr/test1 'basic test'
testfunction mandatory/strnstr/test2 'looking too far'
testfunction mandatory/strnstr/test3 'not looking far enough'
testfunction mandatory/strnstr/test4 'str not in str'
testfunction mandatory/strnstr/test5 'str at end'
testfunction mandatory/strnstr/test6 'str at beginning'
testfunction mandatory/strnstr/test7 'lenght reaches half of str'
testfunction mandatory/strnstr/test8 '\\n in str'
testfunction mandatory/strnstr/test9 '\\t in str'
testfunction mandatory/strnstr/test10 '\\0 in str'
testfunction mandatory/strnstr/test11 'string 1 is \\0\\0'
testfunction mandatory/strnstr/test12 'string 2 is \\0\\0'
testfunction mandatory/strnstr/test13 'Both strings are \\0\\0'
testfunction mandatory/strnstr/test14 'String 1 is NULL'
testfunction mandatory/strnstr/test15 'String 2 is NULL'
testfunction mandatory/strnstr/test16 'Both strings are NULL'
printf "\n"

# ft_strrchr
printf "\e[1;36mTesting ft_strrchr \e[0;00m"
testfunction mandatory/strrchr/test1 'Match at second byte'
testfunction mandatory/strrchr/test2 'Match at first byte'
testfunction mandatory/strrchr/test3 'Match at last byte'
testfunction mandatory/strrchr/test4 'reverse test'
testfunction mandatory/strrchr/test5 'string == NULL'
testfunction mandatory/strrchr/test6 'make sure it stops at \\0'
testfunction mandatory/strrchr/test7 'char = \\0'
testfunction mandatory/strrchr/test8 'check if it places \\0 at end'
printf "\n"

# ft_strtrim
printf "\e[1;36mTesting ft_strtrim \e[0;00m"
testfunction mandatory/strtrim/test1 'set at the very end'
testfunction mandatory/strtrim/test2 'set in begin'
testfunction mandatory/strtrim/test3 'set at begin and end'
testfunction mandatory/strtrim/test4 'space before set in begin'
testfunction mandatory/strtrim/test5 'space after set at the very end'
testfunction mandatory/strtrim/test6 'set at begin and end'
testfunction mandatory/strtrim/test7 'wrong char in middle of set end'
testfunction mandatory/strtrim/test8 'wrong char in middle of set begin'
testfunction mandatory/strtrim/test9 'set not in string'
testfunction mandatory/strtrim/test10 'test with \\n'
testfunction mandatory/strtrim/test11 'test with \\t'
testfunction mandatory/strtrim/test12 'set = \\0\\0'
testfunction mandatory/strtrim/test13 'str = \\0\\0'
testfunction mandatory/strtrim/test14 'set & str = \\0\\0'
testfunction mandatory/strtrim/test15 'set = NULL'
testfunction mandatory/strtrim/test16 'str = NULL'
testfunction mandatory/strtrim/test17 'set & str = NULL'
printf "\n"

# ft_substr
printf "\e[1;36mTesting ft_substr \e[0;00m"
testfunction mandatory/substr/test1 'count start too little'
testfunction mandatory/substr/test2 'count start too far'
testfunction mandatory/substr/test3 'copy too little'
testfunction mandatory/substr/test4 'copy too much'
testfunction mandatory/substr/test5 'start past strlen'
testfunction mandatory/substr/test6 'len bigger than strlen'
testfunction mandatory/substr/test7 'start 0'
testfunction mandatory/substr/test8 'start 1'
testfunction mandatory/substr/test9 'len 0'
testfunction mandatory/substr/test10 'len 1'
testfunction mandatory/substr/test11 'string = \\0'
testfunction mandatory/substr/test12 'string = NULL'
printf "\n"

# ft_tolower
printf "\e[1;36mTesting ft_tolower \e[0;00m"
testfunction mandatory/tolower/test1 'A'
testfunction mandatory/tolower/test2 'a'
testfunction mandatory/tolower/test3 'N'
testfunction mandatory/tolower/test4 'n'
testfunction mandatory/tolower/test5 'Z'
testfunction mandatory/tolower/test6 'z'
testfunction mandatory/tolower/test7 '1'
testfunction mandatory/tolower/test8 '9'
testfunction mandatory/tolower/test9 '@'
testfunction mandatory/tolower/test10 '['
testfunction mandatory/tolower/test11 '{'
testfunction mandatory/tolower/test12 '`'
printf "\n"

# ft_toupper
printf "\e[1;36mTesting ft_toupper \e[0;00m"
testfunction mandatory/toupper/test1 'A'
testfunction mandatory/toupper/test2 'a'
testfunction mandatory/toupper/test3 'N'
testfunction mandatory/toupper/test4 'n'
testfunction mandatory/toupper/test5 'Z'
testfunction mandatory/toupper/test6 'z'
testfunction mandatory/toupper/test7 '1'
testfunction mandatory/toupper/test8 '9'
testfunction mandatory/toupper/test9 '@'
testfunction mandatory/toupper/test10 '['
testfunction mandatory/toupper/test11 '{'
testfunction mandatory/toupper/test12 '`'
printf "\n"

# Bonus Rule Check
printf "\e[1;36mTesting Makefile Rule bonus \e[0;00m"
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
printf "\e[1;32mOK\e[0;00m"
printf "\n"

# Bonus Relink Check
printf "\e[1;36mTesting Makefile Relink bonus \e[0;00m"
relinkcheck bonus
printf "\n"

# ft_lstnew
printf "\e[1;36mTesting ft_lstnew \e[0;00m"
testfunction bonus/lstnew/test1 'String as content'
testfunction bonus/lstnew/test2 'int as content'
testfunction bonus/lstnew/test3 'NULL content'
printf "\n"

# ft_lstadd_front
printf "\e[1;36mTesting ft_lstadd_front \e[0;00m"
testfunction bonus/lstadd_front/test1 'check if adds to front'
testfunction bonus/lstadd_front/test2 'add 2, check both positions'
testfunction bonus/lstadd_front/test3 'list = next before add'
testfunction bonus/lstadd_front/test4 '*lst = NULL'
testfunction bonus/lstadd_front/test5 'lst = NULL'
printf "\n"

# ft_lstsize
printf "\e[1;36mTesting ft_lstsize \e[0;00m"
testfunction bonus/lstsize/test1 'give size 2'
testfunction bonus/lstsize/test2 'give size 3'
testfunction bonus/lstsize/test3 'give second count - 1'
#testfunction bonus/lstsize/test4 'del middle'
testfunction bonus/lstsize/test5 'lst = NULL'
printf "\n"

# ft_lstlast
printf "\e[1;36mTesting ft_lstlast \e[0;00m"
testfunction bonus/lstlast/test1 'give 2'
#testfunction bonus/lstlast/test2 'add empty in between'
testfunction bonus/lstlast/test3 'give 1'
#testfunction bonus/lstlast/test4 'give 0'
#testfunction bonus/lstlast/test5 'lst = NULL'
printf "\n"

# ft_lstadd_back
printf "\e[1;36mTesting ft_lstadd_back \e[0;00m"
testfunction bonus/lstadd_back/test1 'check if adds back'
testfunction bonus/lstadd_back/test2 'add 2 check positions'
#testfunction bonus/lstadd_back/test3 'delete second then add third'
testfunction bonus/lstadd_back/test4 '*lst = NULL'
#testfunction bonus/lstadd_back/test5 'lst = null'
printf "\n"

# ft_lstdelone
printf "\e[1;36mTesting ft_lstdelone \e[0;00m"
testfunction bonus/lstdelone/test1 'del at end check'
testfunction bonus/lstdelone/test2 'del at front check'
testfunction bonus/lstdelone/test3 'del in middle check'
testfunction bonus/lstdelone/test4 'del = NULL'
testfunction bonus/lstdelone/test5 'del with &free'
printf "\n"

# ft_lstclear
printf "\e[1;36mTesting ft_lstclear \e[0;00m"
testfunction bonus/lstclear/test1 'clear 1'
testfunction bonus/lstclear/test2 'clear 2'
#testfunction bonus/lstclear/test3 'clear with empty in between'
testfunction bonus/lstclear/test4 'clear with &free'
testfunction bonus/lstclear/test5 'lst = NULL'
printf "\n"

# ft_lstiter
printf "\e[1;36mTesting ft_lstiter \e[0;00m"
testfunction bonus/lstiter/test1 'iterate 1'
testfunction bonus/lstiter/test2 'iterate 2'
#testfunction bonus/lstiter/test3 'iterate with empty in between'
testfunction bonus/lstiter/test4 'func = NULL'
testfunction bonus/lstiter/test5 'lst = NULL'
printf "\n"

# ft_lstmap
printf "\e[1;36mTesting ft_lstmap \e[0;00m"
testfunction bonus/lstmap/test1 'map and check contents'
testfunction bonus/lstmap/test2 'map 2'
#testfunction bonus/lstmap/test3 'map with empty in between'
testfunction bonus/lstmap/test4 'func = NULL'
testfunction bonus/lstmap/test5 'lst = NULL'
testfunction bonus/lstmap/test6 'del = NULL'
printf "\n"

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
