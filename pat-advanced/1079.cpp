#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstdio>
using namespace std;

int dep(int node, int* suppliers)
{
    int supply = suppliers[node];
    int depth = 0;
    while (supply != -1){
        supply = suppliers[supply];
        ++depth;
    }
    return depth;
}

int dep2(int node, int* depth, int* suppliers)
{
    int d = depth[node];
    if (d < 0){
        return dep(node, suppliers);
    }
    else{
        return d;
    }
}

int main()
{
    int n;
    double  p, r;
    scanf("%d%lf%lf", &n, &p, &r);

    int* suppliers = new int[n];
    for (int i = 0; i < n; ++i){
        suppliers[i] = -1;
    }
    
    int* products = new int[n];
    for (int i = 0; i < 0; ++i){
        products[i] = 0;
    }

    vector<int> retailors;
    int* depth = new int[n];
    depth[0] = 0;
    for (int i = 1; i < n; ++i){
        depth[i] = -100000;
    }    

    int k;
    for (int i = 0; i < n; ++i){
        scanf("%d", &k);
        if (k != 0){
            int dist;
            for (int j = 0; j < k; ++j){
                scanf("%d", &dist);
                suppliers[dist] = i;
                depth[dist] = depth[i] + 1;
            }
        }
        else{
            retailors.push_back(i);
            int product;
            scanf("%d", &product);
            products[i] = product;
        }
    }

    double total = 0;
    for (int i = 0; i != retailors.size(); ++i){
        int d = dep2(retailors[i], depth, suppliers);
        total += products[retailors[i]] * pow(1 + r/100.0, d);
    }

    printf("%.1lf\n", total*p);

    delete[] suppliers;
    delete[] products;
    system("pause");

    return 0;
}