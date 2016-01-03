#! bin/sh

GREEN="\\033[1;32m"
RED="\\033[1;31m"
N="\\033[0;39m"
B="\\033[1;34m"
func_cmp() {
	echo "$N""Test: $3"
	if diff $1 $2 >/dev/null ; then
		echo "$GREEN""Success :)""$N"
	else
		echo "$RED""Fail :(""$N"
		cat a | cat -e
		cat b | cat -e
	fi
}
# Begin tests
echo "$B""_______________Begin tests_______________""$N"
# Errors tests
echo "Errors tests"
# test1 if the file doesn't exist
./bsq errors_files/void_file 2>&1 | cat -e > a
echo "map error" | cat -e > b
func_cmp a b "1.If the file doesn't exist"

# test2 if the file is empty
./bsq errors_files/empty_file 2>&1 | cat -e > a
func_cmp a b "2.If the file is empty"

# test3 if the file info is invalid
./bsq errors_files/bad_file_info 2>&1 | cat -e > a
func_cmp a b "3.If the file info is invalid"

# test when file info is valid
# test4 if the map have an invalid sign
./bsq errors_files/invalid_sign 2>&1 | cat -e > a
func_cmp a b "4.If there is an invalid sign in the map"

# test5 if the map contain more or less than (x + 1) * y
./bsq errors_files/2_much 2>&1 | cat -e > a
func_cmp a b "5.If the map contain more or less than (x+1) * y"

# test6 multiple random sh1t
./bsq errors_files/randomsh1t errors_files/invalid_sign errors_files/lol 2>&1 | cat -e  > a
printf "%s\n%s\n%s\n" "map error" "map error" "map error" | cat -e > b
func_cmp a b "6. Multiple random sh1t"
# test6 if no file is provied it should read on 0

#functional test
echo "Functional tests"
# test1 Normal test
./bsq map/valid_x20_y20 > a
func_cmp a map/valid_x20_y20_solved "1.map 20*20"

# test2 Harder test
./bsq map/valid_x50_y50 > a
func_cmp a map/valid_x50_y50_solved "2.map 50*50"

# test3 edge case 1
./bsq map/edge_case_1 > a
func_cmp a map/edge_case_1_solved "3.edge case 1"

# test4 edge case 2
./bsq map/edge_case_2 > a
func_cmp a map/edge_case_2_solved "3.edge case 2"

# test5 edge case 3
./bsq map/edge_case_3 > a
func_cmp a map/edge_case_3_solved "3.edge case 3"

# test6 
#delete temp files
rm a b
echo "$B""_______________End tests_______________""$N"

