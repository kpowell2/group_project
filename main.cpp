#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <stdio.h>
#include <string.h>
#include "movie.h"
#include "database.h"
#include "movie.cpp"
#include "database.cpp"

using namespace std;

movie getStuff(stringstream& str);
unordered_map<int,string> initializeGenres(string str);
unordered_map<int,string> initializeCompanies(string str);


int main()
{
	string fname;
	cout<<"Enter the file name: ";
	cin>>fname;

	vector<movie> content;
	vector<string> row;
	string line, word;


	fstream file (fname, ios::in);
	if(file.is_open())
	{
	    string throwaway;
        getline(file, throwaway);
		while(getline(file, line))
		{
			row.clear();

			stringstream str(line);

			movie curMovie = getStuff(str);//return the movie object and store it in a vector
            content.push_back(curMovie);
		}
		//create a database class with a vector member that holds movie objects
		//add potentially 6 analytic methods for the database class
		//and add sorting algorithms
		database movieDataBase(content);
		movieDataBase.showTitles();
	}
	else
		cout<<"Could not open the file\n";
    system("PAUSE");

	return 0;
}

movie getStuff(stringstream& str){
    string word;
    int budgetValue, movieID, movieRunTime, movieVoteAvg, movieVoteCount;
    double moviePop;
    long long int movieRev;
    //get budget
    getline(str, word, ',');
    string budget = word;
    //cout << budget << endl;

    getline(str,word,'[');
    getline(str,word,']');
    string genres = word;
    unordered_map<int,string> movieGenres = initializeGenres(genres);
    //cout << genres << endl;

    getline(str,word,',');
    getline(str,word,',');
    string id = word;
    //cout << id << endl;

    getline(str,word,'[');
    getline(str,word,']');
    string keywords = word;
    unordered_map<int,string> movieKeyWords = initializeGenres(keywords);
    //cout << keywords << endl;

    getline(str,word,',');
    getline(str,word,',');
    string origLanguage = word;
    //cout << origLanguage << endl;

    getline(str,word,'$');
    string origTitle = word;
    //cout << origTitle << endl;

    getline(str,word,',');
    getline(str,word,',');
    string popularity = word;
    //cout << popularity << endl;

    getline(str,word,'[');
    getline(str,word,']');
    string pCompanies = word;

    //cout << pCompanies << endl;

    getline(str,word,'[');
    getline(str,word,']');
    string pCountries = word;
    unordered_map<int,string> movieComp = initializeCompanies(pCompanies);
    //cout << pCountries << endl;

    getline(str,word,',');
    getline(str,word,',');
    string releaseDate = word;
    //cout << releaseDate << endl;

    getline(str,word,',');
    string revenue = word;
    //cout << revenue << endl;

    getline(str,word,',');
    string runtime = word;
    //cout << runtime << endl;

    getline(str,word,'[');
    getline(str,word,']');
    string spokenLangs = word;
    //cout << spokenLangs << endl;

    getline(str,word,',');
    getline(str,word,',');
    string status = word;
    //cout << status << endl;

    getline(str,word,'$');
    string title = word;
    //cout << title << endl;

    getline(str,word,',');
    getline(str,word,',');
    string voteAvg = word;
    //cout << voteAvg << endl;

    getline(str,word,'\n');
    string voteCount = word;
    //cout << voteCount << endl;


    if(budget != ""){
        budgetValue = stoi(budget);
    }else{
        budgetValue = 0;
    }

    if(id != ""){
        movieID = stoi(id);
    }else{
        movieID = 0;
    }

    if(popularity != ""){
        moviePop = stod(popularity);
    }else{
        moviePop = 0;
    }
    if(revenue != ""){
        movieRev = stoll(revenue);
    }else{
        movieRev = 0;
    }

    if(runtime != ""){
        movieRunTime = stoi(runtime);
    }else{
        movieRunTime = 0;
    }

    if(voteAvg != ""){
        movieVoteAvg = stoi(voteAvg);
    }else{
        movieVoteAvg = 0;
    }

    if(voteCount != ""){
        movieVoteCount = stoi(voteCount);
    }else{
        movieVoteCount = 0;
    }

    movie newMovie(budgetValue, movieGenres, movieID, movieKeyWords, origLanguage, origTitle, moviePop, movieComp, releaseDate, movieRev, movieRunTime,
                   status, title, movieVoteAvg, movieVoteCount);
    return newMovie;
}

unordered_map<int,string> initializeGenres(string str){
    unordered_map<int,string> genreMap;
    vector<string> vec;
    int startIndex, endIndex;
    int length = (int)str.length();

    for(int i = 0; i < length; i++){
        if(str[i]==':'){
            for(int j = i; j < length; j++){
                if(str[j] == ','){
                    startIndex = i+2;
                    endIndex = j;
                    string subStr = "";
                    subStr.append(str,startIndex,endIndex-startIndex);
                    //cout << subStr << endl;
                    vec.push_back(subStr);
                    i = j;
                    break;
                }else if(str[j] == '}' && j+1 == length){
                    startIndex = i+2;
                    endIndex = j;
                    string subStr = "";
                    subStr.append(str,startIndex,endIndex-(startIndex-1));
                    //cout << subStr << endl;
                    vec.push_back(subStr);
                }
            }
        }
    }
    int vecSize = (int)vec.size();
    for(int i = 0; i < vecSize; i++){
        if(i%2 == 1){
            string word = vec[i];
            int start = 0;
            int endI = word.length();
            string subStr = "";
            subStr.append(word,start+2,endI-(start+5));
            vec[i] = subStr;
        }
    }

    for(int i = 0; i < vecSize; i++){
        int num = stoi(vec[i]);
        genreMap[num] = vec[i+1];
        i++;
    }

    return genreMap;
}

unordered_map<int,string> initializeCompanies(string str){
    unordered_map<int,string> genreMap;
    vector<string> vec;
    int startIndex, endIndex;
    int length = (int)str.length();

    for(int i = 0; i < length; i++){
        if(str[i]==':'){
            for(int j = i; j < length; j++){
                if(str[j] == ','){
                    startIndex = i+2;
                    endIndex = j;
                    string subStr = "";
                    subStr.append(str,startIndex,endIndex-startIndex);
                    //cout << subStr << endl;
                    vec.push_back(subStr);
                    i = j;
                    break;
                }else if(str[j] == '}' && j+1 == length){
                    startIndex = i+2;
                    endIndex = j;
                    string subStr = "";
                    subStr.append(str,startIndex,endIndex-(startIndex-1));
                    //cout << subStr << endl;
                    vec.push_back(subStr);
                }
            }
        }
    }
    int vecSize = (int)vec.size();
    for(int i = 0; i < vecSize; i++){
        if(i%2 == 0){
            string word = vec[i];
            int start = 0;
            int endI = word.length();
            string subStr = "";
            subStr.append(word,start+2,endI-(start+5));
            vec[i] = subStr;
        }else{
            string word = vec[i];
            int start = 0;
            int endI = word.length();
            string subStr = "";
            subStr.append(word,start,endI-1);
            vec[i] = subStr;
        }
    }

    for(int i = 0; i < vecSize; i++){
        int num = stoi(vec[i+1]);
        genreMap[num] = vec[i];
        i++;
    }

    return genreMap;
}

//C:\Users\zchai\OneDrive\Desktop\tmdb_5000_movies.csv
