#include "movie.h"

using namespace std;

movie::movie()
{
    unordered_map<int,string> Genres1;
    budget = 0;
    genres = Genres1;
    id = 0;
    keywords = Genres1;
    origLanguage = "";
    origTitle = "";
    popularity = 0;
    pCompanies = Genres1;
    releaseDate = "";
    revenue = 0;
    runtime = 0;
    title = "";
    voteAvg = 0;
    voteCount = 0;
}

movie::movie(int budget1, unordered_map<int,string> genres1, int id1, unordered_map<int,string> keywords1, string origLanguage1,
              string origTitle1, double popularity1, unordered_map<int,string> pCompanies1, string releaseDate1,
              long long int revenue1, int runtime1, string status1, string title1, int voteAvg1,
              int voteCount1)
{
    budget = budget1;
    genres = genres1;
    id = id1;
    keywords = keywords1;
    origLanguage = origLanguage1;
    origTitle = origTitle1;
    popularity = popularity1;
    pCompanies = pCompanies1;
    releaseDate = releaseDate1;
    revenue = revenue1;
    runtime = runtime1;
    status = status1;
    title = title1;
    voteAvg = voteAvg1;
    voteCount = voteCount1;
}

string movie::getTitles(){
    return title;
}

int movie::getBudget(){
    return budget;
}

unordered_map<int,string> movie::getGenres(){
    return genres;
}

unordered_map<int,string> movie::getKeyWords(){
    return keywords;
}

unordered_map<int,string> movie::getCompanies(){
    return keywords;
}

string movie::getOrigLang(){
    return origLanguage;
}

long long int movie::getRevenue(){
    return revenue;
}

double movie::getPopularity(){
    return popularity;
}

string movie::getReleaseDate(){
    return releaseDate;
}

string movie::getStatus(){
    return status;
}

int movie::getVoteAvg(){
    return voteAvg;
}

int movie::getVoteCount(){
    return voteCount;
}
