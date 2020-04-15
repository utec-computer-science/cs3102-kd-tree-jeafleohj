/*
 * file: test.cpp
 * author: Jhony Angulo
 * date: 12-04-2020
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <random>
#include "kdtree.hpp"
using namespace std;
typedef KDTree<int,3>::Point point;
int main(){
    KDTree<int,3> T; 
    KDTree<int,3>::Point p({1,2,3});
    random_device rd;
    vector<KDTree<int,3>::Point> m;
    for(int i=0;i<100;i++) {
        int x,y,z;
        x = rd()%10000+100;
        y = rd()%10000+100;
        z = rd()%10000+100;
        m.push_back(point({x,y,z}));
        T.insert(m[i]);
    }
    //Test de 10 inserciones
    for(int i=10; i<20;i++) {
        cout<<T.find(m[0])<<" ";
    }
    putchar(10);
    //Test de 10 inserciones que no existen
    for(int i=0; i<10;i++) {
        int x,y,z;
        x = rd()%100;
        y = rd()%100;
        z = rd()%100;
        cout<<T.find(point({x,y,z}))<<" ";
    }
}
