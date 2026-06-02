// Copyright 2022 NNTU-CS
#include "tree.h"
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    vector<char> in = { '1', '2', '3' };
    Tree tree(in);

    vector<vector<char>> all = getAllPerms(tree);
    for (size_t i = 0; i < all.size(); ++i) {
        for (size_t j = 0; j < all[i].size(); ++j) {
            cout << all[i][j];
        }
        cout << " ";
    }
    cout << "\n\n";

    int search_num = 4;
    vector<char> p1 = getPerm1(tree, search_num);
    for (char c : p1) cout << c;
    cout << endl;

    vector<char> p2 = getPerm2(tree, search_num);
    for (char c : p2) cout << c;
    cout << "\n\n";

    vector<int> sizes = { 3, 4, 5, 6, 7, 8 };

    for (int n : sizes) {
        vector<char> test_in;
        for (int i = 0; i < n; ++i) {
            test_in.push_back('A' + i);
        }

        Tree test_tree(test_in);

        int test_num = 1;
        for (int i = 1; i <= n; ++i) test_num *= i;
        test_num = test_num - 1;

        auto start1 = high_resolution_clock::now();
        getPerm1(test_tree, test_num);
        auto stop1 = high_resolution_clock::now();
        auto dur1 = duration_cast<nanoseconds>(stop1 - start1).count();

        auto start2 = high_resolution_clock::now();
        getPerm2(test_tree, test_num);
        auto stop2 = high_resolution_clock::now();
        auto dur2 = duration_cast<nanoseconds>(stop2 - start2).count();

        cout << "N = " << n << "\t|"
            << " getPerm1: " << dur1 << " ns \t|"
            << " getPerm2: " << dur2 << " ns" << endl;
    }

    return 0;
}
