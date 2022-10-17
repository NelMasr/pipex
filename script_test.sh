#! bin/sh

echo "-- Test 01 : cmd1 = ls -la | cmd2 = wc -l --"
./pipex outs/test01/infile "ls -la" "wc -l" outs/test01/outfile
< outs/test01/file1 ls -la | wc -l > outs/test01/file2
diff outs/test01/outfile outs/test01/file2 > outs/test01/diff_file
if [ $? -eq 0 ]
then
	echo -e "\033[0;32mOK.\033[0m\n"
else
	echo -e "\033[0;31mERROR.\033[0m\n"
fi
valgrind --log-file="outs/test01/leak_report" --leak-check=full --show-leak-kinds=all --undef-value-errors=no --errors-for-leak-kinds=all ./pipex outs/test01/infile "ls -la" "wc -l" outs/test01/outfile

echo "-- Test 02 : cmd1 = ls -la | cmd2 = wc -c --"
./pipex outs/test02/infile "ls -la" "wc -c" outs/test02/outfile
< outs/test02/file1 ls -la | wc -c > outs/test02/file2
diff outs/test02/outfile outs/test02/file2 > outs/test02/diff_file
if [ $? -eq 0 ]
then
	echo -e "\033[0;32mOK.\033[0m\n"
else
	echo -e "\033[0;31mERROR.\033[0m\n"
fi
valgrind --log-file="outs/test02/leak_report" --leak-check=full --show-leak-kinds=all --undef-value-errors=no --errors-for-leak-kinds=all ./pipex outs/test02/infile "ls -la" "wc -c" outs/test02/outfile

echo "-- Test 03 : cmd1 = grep who | cmd2 = tr -d 'who' --"
./pipex outs/test03/infile "grep who" "tr -d 'who'" outs/test03/outfile
< outs/test03/file1 grep who | tr -d 'who' > outs/test03/file2
diff outs/test03/outfile outs/test03/file2 > outs/test03/diff_file
if [ $? -eq 0 ]
then
	echo -e "\033[0;32mOK.\033[0m\n"
else
	echo -e "\033[0;31mERROR.\033[0m\n"
fi
valgrind --log-file="outs/test03/leak_report" --leak-check=full --show-leak-kinds=all --undef-value-errors=no --errors-for-leak-kinds=all ./pipex outs/test03/infile "grep who" "tr  -d ''who" outs/test03/outfile

echo "-- Test 04 : cmd1 = cat | cmd2 = hostname --"
./pipex outs/test04/infile "cat" "hostname" outs/test04/outfile
< outs/test04/file1 cat | hostname > outs/test04/file2
diff outs/test04/outfile outs/test04/file2 > outs/test04/diff_file
if [ $? -eq 0 ]
then
	echo -e "\033[0;32mOK.\033[0m\n"
else
	echo -e "\033[0;31mERROR.\033[0m\n"
fi
valgrind --log-file="outs/test04/leak_report" --leak-check=full --show-leak-kinds=all --undef-value-errors=no --errors-for-leak-kinds=all ./pipex outs/test04/infile "cat" "hostname" outs/test04/outfile

echo "-- Test 05 : cmd1 = grep Who | cmd2 = head -2 --"
./pipex outs/test05/infile "grep Who" "head -2" outs/test05/outfile
< outs/test05/file1 grep Who | head -2 > outs/test05/file2
diff outs/test05/outfile outs/test05/file2 > outs/test05/diff_file
if [ $? -eq 0 ]
then
	echo -e "\033[0;32mOK.\033[0m\n"
else
	echo -e "\033[0;31mERROR.\033[0m\n"
fi
valgrind --log-file="outs/test05/leak_report" --leak-check=full --show-leak-kinds=all --undef-value-errors=no --errors-for-leak-kinds=all ./pipex outs/test05/infile "grep Who" "head -2" outs/test05/outfile

echo "-- Test 06 : cmd1 = grep Who | cmd2 = wc -w --"
./pipex outs/test06/infile "grep Who" "wc -w" outs/test06/outfile
< outs/test06/file1 grep Who | wc -w > outs/test06/file2
diff outs/test06/outfile outs/test06/file2 > outs/test06/diff_file
if [ $? -eq 0 ]
then
	echo -e "\033[0;32mOK.\033[0m\n"
else
	echo -e "\033[0;31mERROR.\033[0m\n"
fi
valgrind --log-file="outs/test06/leak_report" --leak-check=full --show-leak-kinds=all --undef-value-errors=no --errors-for-leak-kinds=all ./pipex outs/test06/infile "grep Who" "wc -w" outs/test06/outfile

echo "-- Test 07 : cmd1 = grep Who | cmd2 = cat THEN cmd1 = wc -w | cmd2 = cat --"
./pipex outs/test07/infile "grep Who" "cat" outs/test07/outfile
./pipex outs/test07/infile "wc -w" "cat" outs/test07/outfile
< outs/test07/file1 grep Who | cat > outs/test07/file2
< outs/test07/file1 wc -w | cat > outs/test07/file2
diff outs/test07/outfile outs/test07/file2 > outs/test07/diff_file
if [ $? -eq 0 ]
then
	echo -e "\033[0;32mOK.\033[0m\n"
else
	echo -e "\033[0;31mERROR.\033[0m\n"
fi
valgrind --log-file="outs/test07/leak_report" --leak-check=full --show-leak-kinds=all --undef-value-errors=no --errors-for-leak-kinds=all ./pipex outs/test07/infile "grep Who" "cat" outs/test07/outfile
valgrind --log-file="outs/test07/leak_report" --leak-check=full --show-leak-kinds=all --undef-value-errors=no --errors-for-leak-kinds=all ./pipex outs/test07/infile "wc -w" "cat" outs/test07/outfile

echo "-- Test 08 : cmd1 = volcanicviper | cmd2 = cat --"
./pipex outs/test08/infile "volcanicviper" "cat" outs/test08/outfile &> /dev/null
{
	< outs/test08/file1 volcanicviper | cat > outs/test08/file2
} &> /dev/null
diff outs/test08/outfile outs/test08/file2 > outs/test08/diff_file
if [ $? -eq 0 ]
then
	echo -e "\033[0;32mOK.\033[0m\n"
else
	echo -e "\033[0;31mERROR.\033[0m\n"
fi
{
	valgrind --log-file="outs/test08/leak_report" --leak-check=full --show-leak-kinds=all --undef-value-errors=no --errors-for-leak-kinds=all ./pipex outs/test08/infile "volcanicviper" "cat" outs/test08/outfile
} &> /dev/null

echo "-- Test 09 : cmd1 = cat | cmd2 = pikachu --"
./pipex outs/test09/infile "cat" "pikachu" outs/test09/outfile &> /dev/null
{
	< outs/test09/file1 cat | pikachu > outs/test09/file2
} &> /dev/null
diff outs/test09/outfile outs/test08/file2 > outs/test09/diff_file
if [ $? -eq 0 ]
then
	echo -e "\033[0;32mOK.\033[0m\n"
else
	echo -e "\033[0;31mERROR.\033[0m\n"
fi
{
	valgrind --log-file="outs/test09/leak_report" --leak-check=full --show-leak-kinds=all --undef-value-errors=no --errors-for-leak-kinds=all ./pipex outs/test09/infile "cat" "pikachu" outs/test09/outfile
} &> /dev/null
