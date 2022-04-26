#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <stdio.h>
#include <string.h>
#include "movie.h"

using namespace std;

class database
{
    public:
        database();
        database(vector<movie>);
        void showTitles();
        movie getMovie(string name);

    protected:

    private:
        vector<movie> data;
};

#endif // DATABASE_H
