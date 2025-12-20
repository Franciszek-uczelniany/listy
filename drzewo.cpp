#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "drzewo.h"
#include <bits/stdc++.h>

vector<vector<char*>> treeToMatrix(Drzewo* root);


void Drzewo::DodajD(int dod) {
    if((*this).data == nullptr) {
        string buff = std::to_string(dod);
        Drzewo* t = new Drzewo(buff.c_str());
        this->data = t->data;
        return ;
    }

if (*this > dod) {
    if (!l) {
        l = new Drzewo(std::to_string(dod).c_str());
        l->o = this;
    } else {
        l->DodajD(dod);
    }
    return;
}

if (*this < dod) {
    if (!p) {
        p = new Drzewo(std::to_string(dod).c_str());
        p->o = this;
    } else {
        p->DodajD(dod);
    }
    return;
}


    this->data->licznik++;
}


Drzewo::Drzewo()
{
    l = p = o = nullptr;
    data = nullptr;
}

Drzewo::Drzewo(const char* s)
{
    data = new struct weld;
    data->len = std::strlen(s);
    data->wsp = new char[data->len + 1];
    std::strcpy(data->wsp, s);

    l = p = o = nullptr;
    data->licznik = 1;
}

// 1 - A jest wieksze od B
// 0, A == B
// -1 A<B
int porownaj(const char* a, unsigned short la,
             const char* b, unsigned short lb)
{
    if (a == nullptr || b == nullptr) return -3;
    if (la < lb) return -1;
    if (la > lb) return 1;
    unsigned short min = (la < lb) ? la : lb;

    for (unsigned short i = 0; i < min; ++i)
    {
        // 9 to 71 miejsce w ascii, 0 przed nim
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return 1;
    }


    return 0;
}

bool Drzewo::operator==(const weld& w)
{
    return porownaj(data->wsp, data->len, w.wsp, w.len) == 0;
}

bool Drzewo::operator<(const weld& w)
{
    return porownaj(data->wsp, data->len, w.wsp, w.len) < 0;
}

bool Drzewo::operator>(const weld& w)
{
    return porownaj(data->wsp, data->len, w.wsp, w.len) > 0;
}

bool Drzewo::operator>(const int& w) {
    std::string s = std::to_string(w);
    return porownaj(
        data->wsp, data->len,
        s.c_str(), s.length()
    ) > 0;
}

bool Drzewo::operator<(const int& w) {
    std::string s = std::to_string(w);
    return porownaj(
        data->wsp, data->len,
        s.c_str(), s.length()
    ) < 0;
}


bool Drzewo::operator<=(const weld& w)
{
    return (data->wsp, data->len, w.wsp, w.len) <= 0;
}

bool Drzewo::operator>=(const weld& w)
{
    return porownaj(data->wsp, data->len, w.wsp, w.len) >= 0;
}


void drukuj(vector<vector<char*>> &arr) {
    for (auto &row : arr) {
        for (auto &cell : row) {
            if (cell == nullptr) {
                cout << " ";
            }
            else {
                cout << cell;
            }
        }
        cout << endl;
    }
}

int wysokosc(Drzewo* root) {
    if (!root) return -1;
    return max(wysokosc(root->l), wysokosc(root->p)) + 1;
}

void inorder(Drzewo* root, int row, int col, int height,
             vector<vector<char*>> &ans)
{
    if (!root || !root->data) return;

    int offset = pow(2, height - row - 1);
    inorder(root->l, row + 1, col - offset, height, ans);
    ans[row][col] = root->data->wsp;
    inorder(root->p, row + 1, col + offset, height, ans);
}


vector<vector<char*>> treeToMatrix(Drzewo* root)
{
    int h = wysokosc(root);
    int rows = h + 1;
    int cols = pow(2, h + 1) - 1;

    vector<vector<char*>> ans(rows, vector<char*>(cols, nullptr));

    inorder(root, 0, (cols - 1) / 2, h, ans);
    return ans;
}


void DrukujDrzewo(Drzewo* d) {
    auto ret = treeToMatrix(d);
    drukuj(ret);
}
