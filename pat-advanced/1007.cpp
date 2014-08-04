#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int* nums = new int[n]; 
    int negcount = 0;
    for (int i = 0; i < n; ++i){
        cin >> nums[i];
        if (nums[i] < 0){
            ++negcount;
        }
    }

    int maxsum = 0;
    int thissum = 0;
    int first = 0;
    int last = 0;
    int maxfirst = 0;
    int maxlast = 0;

    for (int i = 0; i < n; ++i){
        thissum += nums[i];
        ++last;
        if (thissum > maxsum){
            maxsum = thissum;
            maxfirst = first;
            maxlast = last;
        }
        else if (thissum < 0){
            thissum = 0;
            first = last;
        }
    }  

    if (negcount == n){
        cout << 0 << " " << nums[0] << " " << nums[n - 1] << endl;
    }
    else if (maxsum == 0){
        cout << "0 0 0" << endl;
    }
    else{
        cout << maxsum << " " << nums[maxfirst] << " " << nums[maxlast - 1] << endl;
    }

    system("pause");
    return 0;
}