#!/bin/bash

echo "========================================="
echo "  C++ Compiler - Complete Test Suite"
echo "========================================="
echo ""

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

PASSED=0
FAILED=0

# Function to run a test
run_test() {
    local test_name=$1
    local test_file=$2
    local expected_output=$3
    
    echo -n "Running: $test_name ... "
    
    output=$(./cpp_compiler "$test_file" 2>&1)
    
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}PASS${NC}"
        echo "$output"
        echo ""
        ((PASSED++))
    else
        echo -e "${RED}FAIL${NC}"
        echo "$output"
        echo ""
        ((FAILED++))
    fi
}

# Check if compiler exists
if [ ! -f "./cpp_compiler" ]; then
    echo -e "${RED}Error: cpp_compiler not found!${NC}"
    echo "Please build the compiler first using: ./build.sh"
    exit 1
fi

echo "=== Example Programs ==="
echo ""

run_test "Test 1: Hello World" "examples/hello.cpp"
run_test "Test 2: Variables" "examples/variables.cpp"
run_test "Test 3: Conditionals" "examples/conditionals.cpp"
run_test "Test 4: Loops" "examples/loops.cpp"
run_test "Test 5: Functions" "examples/functions.cpp"
run_test "Test 6: Fibonacci" "examples/fibonacci.cpp"

echo "========================================="
echo "  Test Results"
echo "========================================="
echo -e "Passed: ${GREEN}$PASSED${NC}"
echo -e "Failed: ${RED}$FAILED${NC}"
echo "Total:  $((PASSED + FAILED))"
echo ""

if [ $FAILED -eq 0 ]; then
    echo -e "${GREEN}All tests passed! ✓${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed! ✗${NC}"
    exit 1
fi
