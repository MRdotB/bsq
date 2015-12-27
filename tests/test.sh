#! bin/sh

GREEN="\\033[1;32m"
RED="\\033[1;31m"
N="\\033[0;39m"
B="\\033[1;34m"
func_cmp() {
	echo "$N""Test: $3"
	if diff $1 $2 >/dev/null ; then
		echo "$GREEN""Success :)""$N"
		cat a | cat -e
	else
		echo "$RED""Fail :(""$N"
		cat a | cat -e
		cat b | cat -e
	fi
}
# Begin tests
echo "$B""_______________Begin tests_______________""$N"
# Errors tests
# test1 if the file doesn't exist
./bsq void_file 2>&1 | cat -e > a
echo "map error" | cat -e > b
func_cmp a b "1.If the file doesn't exist"

# test2 if the file is empty
./bsq empty_file 2>&1 | cat -e > a
func_cmp a b "2.If the file is empty"

# test3 if the file info is invalid
./bsq bad_file_info 2>&1 | cat -e > a
func_cmp a b "3.If the file info is invalid"

# test when file info is valid
# test4 if the map have an invalid sign
./bsq invalid_sign 2>&1 | cat -e > a
func_cmp a b "4.If there is an invalid sign in the map"

# test5 if the map contain more or less than (x + 1) * y
./bsq 2_much 2>&1 | cat -e > a
func_cmp a b "5.If the map contain more or less than (x+1) * y"

# test6 multiple random sh1t
./bsq "random_sh1t" invalid_sign lol 2>&1 | cat -e  > a
printf "%s\n%s\n%s\n" "map error" "map error" "map error" | cat -e > b
func_cmp a b "6. Multiple random sh1t"
# test6 if no file is provied it should read on 0

#delete temp files
rm a b
echo "$B""_______________End tests_______________""$N"

