#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class movie
{
    public:
        movie();
        movie(int budget, unordered_map<int,string> genres, int id, unordered_map<int,string> keywords, string origLanguage,
              string origTitle, double popularity, unordered_map<int,string> pCompanies, string releaseDate,
              long long int revenue, int runtime, string status, string title, int voteAvg,
              int voteCount);
        string getTitles();
        int getBudget();
        unordered_map<int,string> getGenres();
        unordered_map<int,string> getKeyWords();
        unordered_map<int,string> getCompanies();
        string getOrigLang();
        double getPopularity();
        string getReleaseDate();
        long long int getRevenue();
        int getRunTime();
        string getStatus();
        int getVoteAvg();
        int getVoteCount();

    protected:

    private:
        int budget;
        unordered_map<int,string> genres;
        int id;
        unordered_map<int,string> keywords;
        string origLanguage;
        string origTitle;
        double popularity;
        unordered_map<int,string> pCompanies;
        string releaseDate;
        long long int revenue;
        int runtime;
        string status;
        string title;
        int voteAvg;
        int voteCount;
};

#endif // MOVIE_H
