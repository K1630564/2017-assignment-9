#ifndef TRADE_H
#define TRADE_H

#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cstdint>


// Do not add any extra #includes without asking on the KEATS discussion forum

using std::accumulate;

template<typename T>

int bestProfit (T const start , T const end){

    int toReturn = accumulate(start, end, 0, [start](int priceDifference, int price){

        int temp = price - * start;

        if((temp) > priceDifference) priceDifference = temp;

        if(price < * start) * start = price;

        return priceDifference;
    });

    return toReturn;


}




// Don't write any code below this line

#endif
