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
# Create files for test
./game_generator 10 10 5 | > f1
./game_generator 10 10 5 | tail -n +2 | > bm

# Errors tests
# test1 if the file doesn't exist
./bsq void_file 2>&1 | cat -e > a
echo "map error" | cat -e > b
func_cmp a b
# test2 if the file is an invalid map
./bsq bm 2>&1 | cat -e > a
echo "map error" | cat -e > b
func_cmp a b

# delete files
rm a b f1
echo "$B""_______________End tests_______________""$N"

