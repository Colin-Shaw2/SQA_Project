#!/bin/bash
# My first script

defaultUserFile="TestDefaults/users.txt"
echo $defaultUserFile
defaultItemFile="TestDefaults/item.txt"
echo $defaultItemFile
testTable="TestResults/testTable.csv"
echo "Running Tests..."

# for debugging
# directory="Tests/Logout/logout1/"
# echo ""
# echo "Current Directory is"
# echo "$directory"

for directory in Tests/*/*/ ; do #in Tests/*/*/ ; do
    echo ""
    echo "Current Directory is"
    echo "$directory"
    # runs main using input.txt and and outputs it to testOutputs.txt
    # main.exe user item transaction
    ./main.exe $defaultUserFile $defaultItemFile "${directory}testTransactions.txt" < "${directory}input.txt" > "${directory}testOutput.txt"
    
    echo "TEST NAME, SUCCESS?" >> testTable
    # compare to output files
    if diff -q "${directory}testTransactions.txt" "${directory}transactionoutputs.txt"; then
        #if true check other file
        if diff -q "${directory}output.txt" "${directory}testOutput.txt"; then
            echo "${directory}, true" >> testTable
        else
        echo "${directory}, false" >> testTable
        fi
    else
    echo "${directory}, false" >> testTable
    fi

done


# if diff -q "test.txt" "test.txt"; then
#     #if true check other file
#     if diff -q "test.txt" "testout.txt"; then
#         echo "test1, true" >> testTable.csv
#     else
#     echo "test1, false on second check" >> testTable.csv
#     fi
# else
# echo "test1, false" >> testTable.csv
# fi

