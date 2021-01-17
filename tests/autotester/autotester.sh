#!/bin/bash
for folder in `find . -type d`
do
    if [ $folder == '.' ]
    then
        continue
    fi
    cd "$folder"
    ./test_script.sh
    echo ""
    echo ""
    cd ..
done