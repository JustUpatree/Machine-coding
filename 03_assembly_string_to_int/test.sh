./build.sh
function assert () {
    input=$1
    expected=$2
    actual=`echo $input | ./main.bin`
    if [ $actual != $expected ]
    then 
        echo "Expected $expected for $input, got $actual"
    fi
}

assert 0 0
assert -1 -1
assert 1 1
assert -100500 -100500
assert 100500 100500
assert 9223372036854775807 9223372036854775807
assert -9223372036854775808 -9223372036854775808



