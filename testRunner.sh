#!/bin/bash
# My first script

make compile

defaultUserFile="TestDefaults/users.txt"
echo $defaultUserFile
defaultItemFile="TestDefaults/item.txt"
echo $defaultItemFile
testTable="TestResults/testTable.csv"
echo "Running Tests..."


for directory in Tests/*/*/ ; do
    >"${directory}testTransactions.txt"
    # runs main using input.txt and and outputs it to testOutputs.txt
    # main.exe user item transaction
    ./main.exe $defaultUserFile $defaultItemFile "${directory}testTransactions.txt" < "${directory}input.txt" > "${directory}testOutput.txt"
    
done
echo "Checking..."
echo "TEST NAME, SUCCESS?" >> $testTable
    
for directory in Tests/*/*/ ; do
    # compare to output files
    if diff -q "${directory}testTransactions.txt" "${directory}transactionoutputs.txt"; then
        #if true check other file
        if diff -q "${directory}output.txt" "${directory}testOutput.txt"; then
            echo "${directory}, true" >> $testTable
        else
        echo "${directory}, false" >> $testTable
        fi
    else
    echo "${directory}, false" >> $testTable
    fi

done
