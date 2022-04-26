#include "database.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <stdio.h>
#include <string.h>
#include "database.h"

using namespace std;

database::database()
{
    vector<movie> blankData;
    data = blankData;//ctor
}

database::database(vector<movie> movieData){
    data = movieData;
}

void database::showTitles(){
    vector<movie>movieData = data;
    int vecSize = (int)movieData.size();
    for(int i = 0; i < vecSize; i++){
        movie myMovie = movieData[i];
        string temp = movieData[i].getTitles();
        cout <<  "title: " << temp << endl;
    }
}

bool iequals(const string& a, const string& b)
{
    unsigned int sz = a.size();
    if (b.size() != sz)
        return false;
    for (unsigned int i = 0; i < sz; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}

movie database::getMovie(string name){
    int vecSize = (int)data.size();
    movie curMovie;
    for(int i = 0; i < vecSize; i++){
        curMovie = data[i];
        string curTitle = curMovie.getTitles();
        if(iequals(name, curTitle)){
            cout << "found" << endl;
            return curMovie;
        }
    }
    return curMovie;
}

int database::getPosition(movie check){
    movie curMovie;
    int vecSize = (int)data.size();
    string name = curMovie.getTitles();
    for(int i = 0; i < vecSize; i++){
        curMovie = data[i];
        string curTitle = curMovie.getTitles();
        if(iequals(name, curTitle)){
            return i;
        }
    }
    return -1;
}

void database::analyze(){
    sort(data.begin(),data.end(), revenueComp);
}

