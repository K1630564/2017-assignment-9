#ifndef KNIGHTS_H
#define KNIGHTS_H

#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>


// Do not add any extra #includes without asking on the KEATS discussion forum


using std::pair;
using std::make_pair;
using std::vector;
using std::endl;
using std::cout;
using std::sort;

typedef vector<pair<int,int> > Path;
int number = 0;

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


    return legalMoves;


};

pair<Path, bool> first_tour(int boardSize, Path path){


    pair<int, int> next_move;

    pair<int, int> currentPos = path.back();

    vector<pair<int, int> > lMoves = legal_moves(boardSize, path, currentPos);

    vector<pair<int, int> > sMoves;

    if(path.size() == boardSize*boardSize){

        return make_pair(path, true);
    }


    int smallest = 10000;

    for(int j = 0; j < lMoves.size(); j++){

        vector<pair<int, int> > temp0 = path;
        temp0.push_back(lMoves[j]);

        vector<pair<int, int> > temp = legal_moves(boardSize, temp0, lMoves[j]);
        int temp2 = temp.size();

        if(temp2 < smallest){

            sMoves.insert(sMoves.begin(), lMoves[j]);

            smallest = temp2;
        }
        else{
            sMoves.push_back(lMoves[j]);
        }

    }

    for(int i = 0; i < sMoves.size(); i++) {
        next_move = make_pair(sMoves[i].first, sMoves[i].second);
        Path temp = path;
        temp.push_back(next_move);

        pair<Path, bool> search = first_tour(boardSize, temp);

        if (search.second == true) {
            return make_pair(search.first, true);
        }
    }
    return make_pair(path, false);
};







// Do not edit below this line

#endif
