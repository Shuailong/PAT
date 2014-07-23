#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

// ! better way: use array
// http://hi.baidu.com/i5love1you9/item/1fb2f59e889b84d51f4271c4

// Note the zero term

using namespace std;

struct term{
    int expo;
    double coef;
};
term multiply(term t1, term t2)
{
    term res;
    res.expo = t1.expo + t2.expo;
    res.coef = t1.coef * t2.coef;

    return res;
}

bool comp(term t1, term t2)
{
    return t1.expo < t2.expo;
}
int main()
{
    int k1;
    cin >> k1;
    vector<term> poly1;
    for (int i = 0; i < k1; ++i){
        term t;
        cin >> t.expo >> t.coef;
        poly1.push_back(t);
    }

    int k2;
    cin >> k2;
    vector<term> poly2;
    for (int i = 0; i < k2; ++i){
        term t;
        cin >> t.expo >> t.coef;
        poly2.push_back(t);
    }

    vector<term> product;
    for (int i = 0; i < poly1.size(); ++i){
        for (int j = 0; j < poly2.size(); ++j){
            term t = multiply(poly1[i], poly2[j]);
            vector<term>::iterator it = product.begin();
            for (; it != product.end(); ++it){
                if (it->expo == t.expo){
                    it->coef += t.coef;
                    break;
                }
            }
            if (it == product.end()){
                product.push_back(t);
            }        
        }
    }
    int count = 0;
    for (int i = 0; i < product.size(); ++i){
        if (product[i].coef != 0){
            ++count;
        }
    }

    sort(product.rbegin(), product.rend(), comp);
    cout << count;
    for (int i = 0; i < product.size(); ++i){
        if (product[i].coef){
            cout << " " << product[i].expo << " " << fixed << setprecision(1)
                << product[i].coef;
        }
    }
    cout << endl;

    system("pause");
    return 0;
}