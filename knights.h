#ifndef KNIGHTS_H
#define KNIGHTS_H

#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cstdint>

// Do not add any extra #includes without asking on the KEATS discussion forum

using std::pair;
using std::make_pair;
using std::vector;
using std::endl;
using std::cout;

typedef vector<pair<int,int> > Path;

/** Helper function: adds two pairs of ints */
pair<int,int> operator+(const pair<int,int> & a, const pair<int,int> & b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

vector<pair<int, int> > moves (pair<int, int> currentPos){

    pair<int , int> first (1 , -2);
    pair<int , int> second (2, -1);
    pair<int , int> third (2, 1);
    pair<int , int> fourth (1 , 2);
    pair<int , int> fifth (-1 , 2);
    pair<int , int> sixth (-2, 1);
    pair<int , int> seventh (-2, -1);
    pair<int , int> eighth (-1, -2);

    vector<pair<int, int> > toReturn = {currentPos + first,
                                        currentPos + second,
                                        currentPos + third,
                                        currentPos + fourth,
                                        currentPos + fifth,
                                        currentPos + sixth,
                                        currentPos + seventh,
                                        currentPos + eighth};

    return toReturn;

};

bool is_legal (int boardSize, Path path, pair<int, int> currentPos){

    if(find(path.begin(), path.end(), currentPos) != path.end()){
        return false;
    }
    else if (currentPos.first > boardSize - 1){
        return false;
    }
    else if(currentPos.second > boardSize - 1){
        return false;
    }
    else if (currentPos.first < 0){
        return false;
    }
    else if(currentPos.second < 0){
        return false;
    }
    else{
        return  true;
    }
}

vector<pair<int, int> > legal_moves(int boardSize, Path path, pair<int, int> currentPos){

    vector<pair<int, int> > allMoves = moves(currentPos);
    vector<pair<int, int> > legalMoves;


    if(is_legal(boardSize, path, allMoves[0])){legalMoves.push_back(allMoves[0]);}

    if(is_legal(boardSize, path, allMoves[1])){legalMoves.push_back(allMoves[1]);}

    if(is_legal(boardSize, path, allMoves[2])){legalMoves.push_back(allMoves[2]);}

    if(is_legal(boardSize, path, allMoves[3])){legalMoves.push_back(allMoves[3]);}

    if(is_legal(boardSize, path, allMoves[4])){legalMoves.push_back(allMoves[4]);}

    if(is_legal(boardSize, path, allMoves[5])){legalMoves.push_back(allMoves[5]);}

    if(is_legal(boardSize, path, allMoves[6])){legalMoves.push_back(allMoves[6]);}

    if(is_legal(boardSize, path, allMoves[7])){legalMoves.push_back(allMoves[7]);}

    cout << legalMoves[0].first << endl;
    cout << legalMoves[0].second << endl;
    cout << " " << endl;
    cout << legalMoves[1].first << endl;
    cout << legalMoves[1].second << endl;
    cout << " " << endl;
    cout << legalMoves[2].first << endl;
    cout << legalMoves[2].second << endl;
    cout << " " << endl;
    cout << legalMoves[3].first << endl;
    cout << legalMoves[3].second << endl;
    cout << " " << endl;
    cout << legalMoves[4].first << endl;
    cout << legalMoves[4].second << endl;
    cout << " " << endl;

    return legalMoves;


};






// Do not edit below this line

#endif
