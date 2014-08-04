#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct candidate
{
    int id;
    int de;
    int cai;
};

bool compare(candidate lhs, candidate rhs)
{
    if ((lhs.cai + lhs.de) < (rhs.de + rhs.cai)){
        return false;
    }
    else if ((lhs.cai + lhs.de) > (rhs.de + rhs.cai)){
        return true;
    }
    else{
        if (lhs.de < rhs.de){
            return false;
        }
        else if (lhs.de > rhs.de){
            return true;
        }
        else{
            if (lhs.id < rhs.id){
                return true;
            }
            else{
                return false;
            }
        }
    }
}

int main()
{
    int n, l, h;
  
    scanf_s("%d%d%d", &n, &l, &h);

    vector<candidate> class1;
    vector<candidate> class2;
    vector<candidate> class3;
    vector<candidate> class4;

    int count = 0;
    for (int i = 0; i < n; ++i){
        candidate can;
        scanf_s("%d%d%d", &can.id, &can.de, &can.cai);
        if (can.de >= l && can.cai >= l){
            ++count;
            if (can.de >= h && can.cai >= h){
                class1.push_back(can);
            }
            else if (can.de >= h && can.cai < h){
                class2.push_back(can);
            }
            else if (can.de < h && can.cai < h && can.de >= can.cai){
                class3.push_back(can);
            }
            else{
                class4.push_back(can);
            }
        }
    }

    printf("%d\n", count);
    sort(class1.begin(), class1.end(), compare);
    sort(class2.begin(), class2.end(), compare);
    sort(class3.begin(), class3.end(), compare);
    sort(class4.begin(), class4.end(), compare);

    vector<candidate>::const_iterator cit1;
    for (cit1 = class1.begin(); cit1 != class1.end(); ++cit1){
        printf("%d %d %d\n", cit1->id, cit1->de, cit1->cai);
    }

    vector<candidate>::const_iterator cit2;
    for (cit2 = class2.begin(); cit2 != class2.end(); ++cit2){
        printf("%d %d %d\n", cit2->id, cit2->de, cit2->cai);
    }

    vector<candidate>::const_iterator cit3;
    for (cit3 = class3.begin(); cit3 != class3.end(); ++cit3){
        printf("%d %d %d\n", cit3->id, cit3->de, cit3->cai);
    }

    vector<candidate>::const_iterator cit4;
    for (cit4 = class4.begin(); cit4 != class4.end(); ++cit4){
        printf("%d %d %d\n", cit4->id, cit4->de, cit4->cai);
    }

    return 0;
}