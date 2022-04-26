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

        string getTitles() const; //return the title of the movie
        int getBudget() const; //return the budget
        unordered_map<int, string> getGenres() const; //return the list of genres
        int getID() const; //return the id
        unordered_map<int, string> getKeywords() const; //return the list of keywords
        string getOrigLanguage() const; //return origLanguage
        string getOrigTitle() const; //return origTitle
        double getPopularity() const; //return popularity
        unordered_map<int, string> getPCompanies() const; //return list of pCompanies
        string getRelease() const; //return releaseDate
        long long int getRevenue() const; //return revenue
        int getRuntime() const; //return runtinme
        string getStatus() const; //return status
        int getVoteAvg() const; //return voteAvg
        int getVoteCount() const; //return voteCount


        void setTitle(string newTitle); //newTitle --> title
        void setBudget(int newBudget); //newBudget --> budget
        void setGenres(unordered_map<int, string> newGenres); //newGenres --> genres
        void setID(int newID); //id --> newID
        void setKeywords(unordered_map<int, string> newKeywords); //newKeywords --> keywords
        void setOrigLanguage(string newLang); //newLang --> origLanguage
        void setOrigTitle(string newTitle); //newTitle --> origTitle
        void setPopularity(double newPopularity); //newPopularity --> popularity
        void setPCompanies(unordered_map<int, string> newCompanies); //newCompanies --> pCompanies
        void setRelease(string newRelease); //newRelease --> releaseDate
        void setRevenue(long long int newRevenue); //newRevenue --> revenue
        void setRuntime(int newRuntime); //newRuntime --> runtime
        void setStatus(string newStatus); //newStatus --> status
        void setVoteAvg(int newVoteAvg); //newVoteAvg --> voteAvg
        void setVoteCount(int newVoteCount); //newVoteCount --> voteCount

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
