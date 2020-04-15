#ifndef KDTREE_HPP
#define KDTREE_HPP

#include  <vector>
#include  <iostream>

template <class T, size_t k>
struct KDTree {
    struct Point{
        std::vector<T> tuple;
        Point() : tuple(k)
        {}

        Point(const Point& point) : tuple(k)
        {
            for(int i = 0; i<k; ++i) {
                tuple[i] = point.tuple[i];
            }
        }

        Point(const std::vector<T> _tuple) : tuple(k)
        {
            for(int i = 0; i<k; ++i) {
                tuple[i] = _tuple[i];
            }
        }

        bool operator==(const Point point) const {
            for(int i = 0; i<k; ++i) {
                if(tuple[i] != point.tuple[i])
                    return false;
            }
            return true;
        }
    };
    struct Node{
        Point point;
        Node* left;
        Node* right;
        Node(const Point& point)
            : point(point), left(nullptr), right(nullptr)
        {}
    };
    Node* root;
    KDTree(): root{nullptr}{}
    void insert(const Point& point){
        if(root == nullptr) {
            root = new Node(point);
            return;
        }

        unsigned n_axis = 0;
        Node **node = &root;
        T value;

        for (;*node;) {
            value = (*node)->point.tuple[n_axis];
            if(point.tuple[n_axis] <= value ){
                node = &(*node)->left;
            }else{
                node = &(*node)->right;
            }
            n_axis = (n_axis + 1)%k;
        }

        *node = new Node(point);
    }

    bool find(const Point& point) {
        if(root == nullptr) return false;
        Node **node = &root;
        T value;
        unsigned n_axis = 0;

        for (;*node;) {
            if((*node)->point == point) return true;

            value = (*node)->point.tuple[n_axis];

            if(point.tuple[n_axis] == value ){
                node = &(*node)->left;
            }
            else {
                node = &(*node)->right;
            }
            n_axis = (n_axis + 1)%k;
        }

        return false;
    }
};

#endif
