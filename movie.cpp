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

string movie::getTitles() const{
    return title;
}
int movie::getBudget() const {
    return budget;
}
unordered_map<int, string> movie::getGenres() const {
    return genres;
}
int movie::getID() const {
    return id;
}
unordered_map<int, string> movie::getKeywords() const {
    return keywords;
}
string movie::getOrigLanguage() const {
    return origLanguage;
}
string movie::getOrigTitle() const {
    return origTitle;
}
double movie::getPopularity() const {
    return popularity;
}
unordered_map<int, string> movie::getPCompanies() const {
    return pCompanies;
}
string movie::getRelease() const {
    return releaseDate;
}
long long int movie::getRevenue() const {
    return revenue;
}
int movie::getRuntime() const {
    return runtime;
}
string movie::getStatus() const {
    return status;
}
int movie::getVoteAvg() const {
    return voteAvg;
}
int movie::getVoteCount() const {
    return voteCount;
}


void movie::setTitle(string newTitle) {
    title = newTitle;
}
void movie::setBudget(int newBudget) {
    budget = newBudget;
}
void movie::setGenres(unordered_map<int, string> newGenres) {
    genres = newGenres;
}
void movie::setID(int newID) {
    id = newID;
}
void movie::setKeywords(unordered_map<int, string> newKeywords) {
    keywords = newKeywords;
}
void movie::setOrigLanguage(string newLang) {
    origLanguage = newLang;
}
void movie::setOrigTitle(string newTitle) {
    origTitle = newTitle;
}
void movie::setPopularity(double newPopularity) {
    popularity = newPopularity;
}
void movie::setPCompanies(unordered_map<int, string> newCompanies) {
    pCompanies = newCompanies;
}
void movie::setRelease(string newRelease) {
    releaseDate = newRelease;
}
void movie::setRevenue(long long int newRevenue) {
    revenue = newRevenue;
}
void movie::setRuntime(int newRuntime) {
    runtime = newRuntime;
}
void movie::setStatus(string newStatus) {
    status = newStatus;
}
void movie::setVoteAvg(int newVoteAvg) {
    voteAvg = newVoteAvg;
}
void movie::setVoteCount(int newVoteCount) {
    voteCount = newVoteCount;
}
