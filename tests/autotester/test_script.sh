let "file_nb = 1"
let "good_tests = 0"

for filename in ./test_files/*.avm; do
    testname=$(echo "$filename" | sed 's:.*/::')
    ../../abstractVM "$filename" > res
    if [ $? = 84 ]
    then
        echo "ERROR" > ./res
    fi
    diff res "test_res/$testname"
    if [ $? = 0 ]
    then
        echo "Test $testname passed"
        let "good_tests = good_tests + 1"
    else
        echo "Test $testname failed"
    fi
    let "file_nb = file_nb + 1"
done
rm res
let "file_nb = file_nb - 1"
echo "$good_tests/$file_nb passed"