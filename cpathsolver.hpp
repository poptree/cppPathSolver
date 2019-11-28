#pragma once

#include <string>
#include <cstring>
#include <string.h>
#include <cstdio>
#include <vector>

#ifndef __CPP_PATH_SOLVER__
#define __CPP_PATH_SOLVER__

using namespace std;

namespace CPS
{
    class cpathsolver
    {
    private:
        string _filename;
        bool is_backslash;
    public:
        cpathsolver();
        cpathsolver(string input);
        ~cpathsolver();

        void init();

        bool empty();

        string replaceallch(char c1, char c2);

        string path();
        string path_slash();
        string path_bslash();

        size_t get_ext_pos();
        string get_ext();
        bool set_ext(string newext);

        vector<string>split(char ch='/');
        bool join(cpathsolver &right);
    };
}

#endif