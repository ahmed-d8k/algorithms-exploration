#include <assert.h>
#include <iostream>

#include "test_karatsuba.h"
#include "karatsuba.h"

void Test_Karatsuba::test_split_int_even(){
    int x = 1234;
    int top_half = Karatsuba::get_top_half(x);
    int bot_half = Karatsuba::get_bot_half(x);
    assert(top_half == 12);
    assert(bot_half == 34);
}

void Test_Karatsuba::test_split_int_odd(){
    int x = 12345;
    int top_half = Karatsuba::get_top_half(x);
    int bot_half = Karatsuba::get_bot_half(x);
    assert(top_half == 123);
    assert(bot_half == 45);
}

void Test_Karatsuba::test_karatsuba(int x, int y, int theoretical_answer){
    int answer = Karatsuba::karat_multiply(x,y);
    std::cout << "Answer: " << answer << std::endl;
    assert(answer == theoretical_answer);
}

void Test_Karatsuba::execute_tests(){
    test_split_int_even();
    test_split_int_odd();
    test_karatsuba(1234, 5678, 7006652);
    test_karatsuba(123, 567, 69741);
    test_karatsuba(123, 56, 6888);
    test_karatsuba(123, 5, 615);
    test_karatsuba(1, 5678, 5678);
    std::cout << "All karatsuba tests passed.\n";
    
}