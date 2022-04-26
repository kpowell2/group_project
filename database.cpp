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
    //sort(data.begin(),data.end(), revenueComp);
    cout << "lmaoooo" << endl;
}

void database::sortMoviesRPD() { //sorts data based on its RPD (revenuePerDollar)

    unsigned int i;
    unsigned int j;
    movie temp;

    for (i = 1; 1 < data.size(); i++) { //runs for the length of data, starting at index 1

        j = i;

        while (j > 0 && (data[j - 1].getRevenuePerDollar() <= data[j].getRevenuePerDollar())) { //runs as long as the value in j-1 is less than or equal to the value at j. stop if j <= 0 as this means that there is no index before j 

            temp = data[j]; //stores the values of j in a temp movie object

            data[j] = data[j - 1]; //sets the value at data[j] to be equal to the value at data[j-1]

            data[j - 1] = temp;//sets the value at data[j-1] to be equal to the value of temp

            //after running, data[j] and data[j-1] have swapped values

            j--;

        }

    }
}

void database::printMovies() { //prints out the list of movies. to be called after using sortMoviesRPD
    unsigned int i;

    cout << "Below are the movies, sorted by RPD(revenue per dollar spent on budget)" << endl;

    for (i = 0; i < data.size(); i++) {
        cout << "Title: " << data[i].getTitles() << ", Revenue: " << data[i].getRevenue() << ", Budget: " << data[i].getBudget() << ", RPD: " << data[i].getRevenuePerDollar() << endl;
    }
}

