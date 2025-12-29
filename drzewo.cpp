#include "drzewo.h"
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

// Porównuje dwa stringi znak po znaku
int porownaj(const char* a, unsigned short la, const char* b, unsigned short lb) {
    if (!a || !b) return 0;
    unsigned short minLen = (la < lb ? la : lb);

    for (unsigned short i = 0; i < minLen; ++i) {
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return 1;
    }
    if (la < lb) return -1;
    if (la > lb) return 1;
    return 0;
}

Drzewo::Drzewo() : l(nullptr), p(nullptr), o(nullptr), data(nullptr) {}

Drzewo::Drzewo(const char* s) {
    data = new weld;
    data->len = strlen(s);
    data->wsp = new char[data->len + 1];
    strcpy(data->wsp, s);
    data->licznik = 1;
    data->l = data->p = data->o = nullptr;
    l = p = o = nullptr;
}

bool Drzewo::operator>(const weld& w) {
    return porownaj(data->wsp, data->len, w.wsp, w.len) > 0;
}

bool Drzewo::operator<(const weld& w) {
    return porownaj(data->wsp, data->len, w.wsp, w.len) < 0;
}

bool Drzewo::operator==(const weld& w) {
    return porownaj(data->wsp, data->len, w.wsp, w.len) == 0;
}

bool Drzewo::operator==(const int& w) {
    string s = to_string(w);
    return porownaj(data->wsp, data->len, s.c_str(), s.length()) == 0;
}

bool Drzewo::operator>(const int& w) {
    string s = to_string(w);
    return porownaj(data->wsp, data->len, s.c_str(), s.length()) > 0;
}

bool Drzewo::operator<(const int& w) {
    string s = to_string(w);
    return porownaj(data->wsp, data->len, s.c_str(), s.length()) < 0;
}

bool Drzewo::operator<=(const weld& w) {
    return porownaj(data->wsp, data->len, w.wsp, w.len) <= 0;
}

bool Drzewo::operator>=(const weld& w) {
    return porownaj(data->wsp, data->len, w.wsp, w.len) >= 0;
}

void Drzewo::DodajD(int dod) {
    if (!data) {
        string s = to_string(dod);
        Drzewo* tmp = new Drzewo(s.c_str());
        data = tmp->data;
        return;
    }
    if (*this > dod) {
        if (!l) {
            l = new Drzewo(to_string(dod).c_str());
            l->o = this;
        } else {
            l->DodajD(dod);
        }
    }
    else if (*this < dod) {
        if (!p) {
            p = new Drzewo(to_string(dod).c_str());
            p->o = this;
        } else {
            p->DodajD(dod);
        }
    }
    else {
        data->licznik++;
    }
}

Drzewo* Drzewo::min() {
    Drzewo* curr = this;
    while (curr->l) curr = curr->l;
    return curr;
}

Drzewo* Drzewo::max() {
    Drzewo* curr = this;
    while (curr->p) curr = curr->p;
    return curr;
}

void Drzewo::Pokaz() {
    if (data && data->wsp) cout << data->wsp << endl;
}

void drukuj(const vector<vector<char*>>& mat) {
    for (auto &row : mat) {
        for (auto &cell : row) {
            if (!cell) cout << "   ";
            else cout << cell << " ";
        }
        cout << "\n";
    }
}

int wysokosc(Drzewo* root) {
    if (!root || !root->data) return -1;
    return max(wysokosc(root->l), wysokosc(root->p)) + 1;
}

void inorder(Drzewo* root, int row, int col, int height, vector<vector<char*>>& out) {
    if (!root || !root->data) return;

    int offset = pow(2, height - row - 1);

    inorder(root->l, row + 1, col - offset, height, out);
    out[row][col] = root->data->wsp;
    inorder(root->p, row + 1, col + offset, height, out);
}

vector<vector<char*>> treeToMatrix(Drzewo* root) {
    int h = wysokosc(root);
    int R = h + 1;
    int C = pow(2, h+1) - 1;

    vector<vector<char*>> mat(R, vector<char*>(C, nullptr));
    inorder(root, 0, (C-1)/2, h, mat);
    return mat;
}

void DrukujDrzewo(Drzewo* d) {
    auto mat = treeToMatrix(d);
    drukuj(mat);
}

Drzewo* Drzewo::poprzednik() {
    
}

Drzewo* Drzewo::poprzednik(Drzewo* d) {
    if(d!= nullptr) {
        Drzewo* t;
        if(d->l != nullptr) return (*d).l->max();
        do {
            t = d;
            d = d->o;
        } while(d!=NULL && d->l == t);
        // i potem tylko ret d->p chyba,
        return d;
    }
    return d;
    // Jesli nie mozemy znalezc poprzednika to zwracamy arg
}

Drzewo* Drzewo::nastepnik(Drzewo* d) {
    if(d!= nullptr) {
        Drzewo* t;
        if(d->l != nullptr) return (*d).p->min();
        do {
            t = d;
            d = d->o;
        } while(d!=NULL && d->p == t);

        return d;
    }
    return d;
}

Drzewo* Drzewo::znajdz(int var) {
    if(*this == var) return this;

     if (*this > var) {
        if (!l) return nullptr;             // Nie jest mozliwe znalezienie tego elementu
          else {
           return l->znajdz(var);
        }
    }

    if (!p) return nullptr;
    return p->znajdz(var);
}