#ifndef KARATSUBA_H
#define KARATSUBA_H

class Karatsuba{
    public:
        int static get_top_half(int x);
        int static get_bot_half(int x);
        int static get_digit_count(int x);
        int static karat_multiply(int x, int y);
        bool static can_split(int x);
        int static can_split_any_var(int x, int y);
        int static get_term(int x, int y);
        int static get_max_digit_count(int x, int y);
        bool static base_case(int x, int y);
        int static get_avg_floor_digit_count(int x, int y);
        int static clean_raw_digits(int raw_digits);
        bool static is_even(int x);
};

#endif