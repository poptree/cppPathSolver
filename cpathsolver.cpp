#pragma once

#include "cpathsolver.hpp"

namespace CPS
{
cpathsolver::cpathsolver() : is_backslash(false)
{
}

cpathsolver::cpathsolver(string input) : _filename(input),
                                         is_backslash(false)
{
}

cpathsolver::~cpathsolver()
{
}

void cpathsolver::init()
{
    is_backslash = false;
    size_t pos = _filename.find('\\');
    if (pos != string::npos)
    {
        is_backslash = true;
        _filename = replaceallch('\\', '/');
    }
}

bool cpathsolver::empty()
{
    if (_filename.size() == (size_t)0)
        return true;
    else
        return false;
}

string cpathsolver::replaceallch(char c1, char c2)
{
    size_t pos = 0;
    string tmp = _filename;
    while ((pos = tmp.find(c1, pos)) != string::npos)
    {
        tmp[pos] = c2;
    }
    return tmp;
}

string cpathsolver::path()
{
    string res = _filename;
    if (true == is_backslash)
    {
        res = replaceallch('/', '\\');
    }
    return res;
}

string cpathsolver::path_slash()
{
    return _filename;
}

string cpathsolver::path_bslash()
{
    return replaceallch('/', '\\');
}

size_t cpathsolver::get_ext_pos()
{
    char splitch = '/';
    char extch = '.';
    size_t pos = _filename.rfind(splitch);
    if (pos == string::npos)
    {
        pos = 0;
    }
    return pos;
}

string cpathsolver::get_ext()
{
    char splitch = '/';
    char extch = '.';
    size_t pos = get_ext_pos();
    pos = _filename.find(extch, pos);
    return _filename.substr(pos);
}

bool cpathsolver::set_ext(string newext)
{
    size_t pos = get_ext_pos();
    _filename.replace(pos, get_ext().size(), newext);
}

vector<string> cpathsolver::split(char ch = '/')
{
    vector<string> res;
    size_t pos = _filename.rfind(ch);
    if (pos == string::npos)
    {
        res.push_back(string("./"));
        res.push_back(_filename);
    }
    else
    {
        res.push_back(_filename.substr(0, pos + 1));
        res.push_back(_filename.substr(pos + 1));
    }
}

bool cpathsolver::join(cpathsolver &right)
{
    bool res=false;
    if (empty())
    {
        _filename = right._filename;
    }
    else if (right.empty())
    {
        _filename = _filename;
    }
    else
    {
        if(_filename[_filename.size()-1]!='/')
            _filename = _filename + '/';
        if(right._filename[0]=='/')
            right._filename.erase(0,1);
        _filename = _filename + right._filename;
        res = true;
    }
    init();
    return res;
}
} // namespace CPS