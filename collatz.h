#ifndef COLLATZ_H
#define COLLATZ_H

#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cstdint>
#include "counting_iterator.h"
#include "transformreduce.h"

// Do not add any extra #includes without asking on the KEATS discussion forum

using std::accumulate;
using std::pair;
using std::make_pair;

uint64_t collatz(uint64_t n) {

    if(n == 1){
        return 1;
    }
    else{

        if(n % 2 == 1){
            return collatz(n * 3 + 1) + 1;
        }

        else{
            return collatz(n / 2) + 1;
        }


    }
}

/*

pair<uint64_t, uint64_t> collatz_max(uint64_t bound) {

    counting_iterator<uint64_t> itr(1);
    counting_iterator<uint64_t> itrEnd(bound);
    pair<uint64_t, uint64_t> start = make_pair(1, 1);

    pair<uint64_t, uint64_t> toReturn = accumulate(itr, itrEnd, start , [itr](pair<uint64_t, uint64_t> result){

        uint64_t longestCollatz = 1;


        if (collatz(* itr) > longestCollatz) {

            longestCollatz = collatz(* itr);

            result = make_pair(longestCollatz, * itr);

            return result;
        }
    });

    return toReturn;





}
*/
// Do not edit anything below this line

#endif
