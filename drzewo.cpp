#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "drzewo.h"
#include <bits/stdc++.h>

vector<vector<char*>> treeToMatrix(weld* root);

Drzewo::Drzewo()
{
    l = p = o = nullptr;
    licznik = 0;
    x = nullptr;
    len = 0;
}

Drzewo::Drzewo(const char* s)
{
    len = std::strlen(s);
    x = new char[len + 1];
    std::strcpy(x, s);

    l = p = o = nullptr;
    licznik = 1;
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
    return porownaj(x, len, w.wsp, w.len) == 0;
}

bool Drzewo::operator<(const weld& w)
{
    return porownaj(x, len, w.wsp, w.len) < 0;
}

bool Drzewo::operator>(const weld& w)
{
    return porownaj(x, len, w.wsp, w.len) > 0;
}

bool Drzewo::operator<=(const weld& w)
{
    return porownaj(x, len, w.wsp, w.len) <= 0;
}

bool Drzewo::operator>=(const weld& w)
{
    return porownaj(x, len, w.wsp, w.len) >= 0;
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

int wysokosc(weld* root) {
    if (!root) {
        return -1;
    }

    int l = wysokosc(root->l);
    int p = wysokosc(root->p);

    return max(l, p) + 1;
}

// To jest potrzebne do wyswietlania drzewa, output jest w ans
void inorder(weld *root, int row, int col, int height,
             vector<vector<char*>> &ans) {
    if (!root) {
        return;
    }

    int offset = pow(2, height - row - 1);

   // przejdz po lewym drzewie, czyli 
   //lewe <= obecne < Prawe
    if (root->l) {
        inorder(root->l, row + 1, col - offset, height, ans);
    }

    ans[row][col] = root->wsp;

    if (root->p) {
        inorder(root->p, row + 1, col + offset, height, ans);
    }
}



vector<vector<char*>> treeToMatrix(weld* root) {

    int h = wysokosc(root);

    int rows = h + 1;
    int cols = pow(2, h + 1) - 1;

    vector<vector<char*>> ans(rows, vector<char*>());

    inorder(root, 0, (cols - 1) / 2, h, ans);

    return ans;
}


 void DrukujDrzewo(weld* d) {
    std::vector<vector<char*>> ret = treeToMatrix(d);

    drukuj(ret);
}