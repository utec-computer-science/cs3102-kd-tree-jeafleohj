#ifndef KDTREE_HPP
#define KDTREE_HPP

#include  <vector>

template <class T, size_t k>
struct KDTree {
    struct Point{
        std::vector<T> tuple;
        Point() : tuple(k)
        {};
        Point(const Point& point) : tuple(k)
        {
            for(int i = 0; i<k; ++i) {
                tuple[i] = point.tuple[i];
            }
        };
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
        T* value = nullptr;

        for (;*node;) {
            value = (*node)->value.tuple[n_axis];
            if (point.tuple[n_axis] <= value ) {
                node = &(*node)->left;
            }
            else {
                node = &(*node)->right;
            }

            n_axis = (n_axis + 1) % k;
        }

        *node = new Node(point);
    }
    bool find() {
        return true;
    }
};

#endif
