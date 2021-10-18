./build.sh
function assert () {
    input=$1
    expected=$2
    actual=`echo $input | ./main.bin 2>&1`
    if [ "$actual" != "$expected" ]
    then 
        echo "Expected '$expected' for '$input', got '$actual'"
    fi
}

function assert_raw () {
    input=$1
    expected=$2
    actual=`echo -n $input | ./main.bin 2>&1`
    if [ "$actual" != "$expected" ]
    then 
        echo "Expected '$expected' for '$input', got '$actual'"
    fi
}

assert 0 0
assert -1 -1
assert 1 1
assert -100500 -100500
assert 100500 100500
assert 9223372036854775807 9223372036854775807
assert -9223372036854775808 -9223372036854775808
assert_raw "" "Invalid input"
assert -1234567890123456789123 "Invalid input"
assert "abc" "Invalid input"
assert ':' 'Invalid input'
assert "123abc" "Invalid input"
assert "/" "Invalid input"
assert "asd-4" "Invalid input"
assert "3-" "Invalid input"
assert 9223372036854775808 "Invalid input"
assert -9223372036854775809 "Invalid input"
assert "" "Invalid input"

