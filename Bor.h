//Bor..

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;


class node {
public:
    node* next[26];
    int strings;
    int visit;

    node() {
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
        strings = 0;
        visit = 0;
    }
};

void add(const string& s, node* root) {
    node* cur_v = root;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (cur_v->next[c - 'a'] == nullptr) {
            cur_v->next[c - 'a'] = new node();
        }
        cur_v->next[c - 'a']->visit++;
        cur_v = cur_v->next[c - 'a'];
    }
    cur_v->strings++;
}

void remove(const string& s, node* root) {
    node* cur_v = root;
    node* temp = new node();
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        temp = cur_v;
        cur_v = cur_v->next[c - 'a'];

    }
    if (cur_v->visit == 1)
    {
        delete cur_v;
        temp->next[s[s.length() - 1] - 'a'] = NULL;
    }
    if (cur_v->visit > 1)
    {
        cur_v->strings = 0;
    }
}

bool has(const string& s, node* root) {
    node* cur_v = root;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        cur_v = cur_v->next[c - 'a'];
        if (cur_v == nullptr) {
            cout << "Такой строки нет!";
            return false;
        }
    }
    if (cur_v->strings == 0)
    {
        cout << "Такой строки нет!";
        return false;
    }
    else
    {
        cout << "Строка есть!";
        return cur_v->strings > 0;
    }
}

void write(node* v, string cur_str) {
    for (int i = 0; i < v->strings; i++) {
        cout << endl << cur_str << endl;
    }

    for (int i = 0; i < 26; i++) {
        if (v->next[i] != nullptr) {
            cur_str.push_back('a' + i);
            write(v->next[i], cur_str);
            cur_str.pop_back();
        }
    }
}