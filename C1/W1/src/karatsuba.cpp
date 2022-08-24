#include "karatsuba.h"
#include "math.h"

int Karatsuba::get_digit_count(int x){
    int digits = 0;
    while(x > 0){
        x = x/10;
        digits++;
    }
    return digits;
}

int Karatsuba::get_bot_half(int x){
    int digits = get_digit_count(x);
    int half_digits = digits/2;
    int top_half = get_top_half(x);
    int bot_half = x - top_half*pow(10, half_digits);
    return bot_half;
}

int Karatsuba::get_top_half(int x){
    int digits = get_digit_count(x);
    int half_digits = digits/2;
    for(int i = 0; i < half_digits; i++){
        x = x/10;
    }
    return x;
}

bool Karatsuba::can_split(int x){
    int digits = get_digit_count(x);
    if(digits > 1){
        return true;
    }
    else{
        return false;
    }

}

int Karatsuba::get_max_digit_count(int x, int y){
    int digits_x = get_digit_count(x);
    int digits_y = get_digit_count(y);

    if(digits_x > digits_y){
        return digits_x;
    }
    else{
        return digits_y;
    }
}

int Karatsuba::get_avg_floor_digit_count(int x, int y){
    int digits_x = get_digit_count(x);
    int digits_y = get_digit_count(y);
    return (digits_x+digits_y)/2;

}

int Karatsuba::clean_raw_digits(int raw_digits){
    if(is_even(raw_digits)){
        return raw_digits;
    }
    else{
        return raw_digits-1;
    }
}

bool Karatsuba::is_even(int x){
    if(x % 2 == 0){
        return true;
    }
    else{
        return false;
    }
}

int Karatsuba::karat_multiply(int x, int y){
    if(base_case(x,y)){
        return x*y;
    }

    int raw_digits = get_max_digit_count(x, y);
    int digits = clean_raw_digits(raw_digits);
    int half_digits = digits/2;

    int a = get_top_half(x);
    int b = get_bot_half(x);
    int c = get_top_half(y);
    int d = get_bot_half(y);

    int term_one = get_term(a, c);
    int term_two = get_term(b, d);
    int term_three = get_term(a+b, c+d);

    int term_four = term_three - term_two - term_one;
    int answer = term_one*pow(10, digits) + term_four*pow(10, half_digits) + term_two; 

    return answer;
}

int Karatsuba::get_term(int x, int y){
    return karat_multiply(x, y);
}

bool Karatsuba::base_case(int x, int y){
    if((x < 10) || (y < 10)){
        return true;
    }
    else{
        return false;
    }
}