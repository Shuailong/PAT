#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    vector<int> nums1;
    int N1;
    cin >> N1;
    for (int i = 0; i < N1; ++i){
        int num;
        //cin >> num;
        scanf("%d", &num);
        nums1.push_back(num);
    }
    vector<int> nums2;
    int N2;
    cin >> N2;
    for (int i = 0; i < N2; ++i){
        int num;
        //cin >> num;
        scanf("%d", &num);
        nums2.push_back(num);
    }
    
    vector<int>merge;
    int i = 0;
    int j = 0;
    while (i < nums1.size() && j < nums2.size()){
        if (nums1[i] < nums2[j]){
            merge.push_back(nums1[i]);
            ++i;
        }
        else{
            merge.push_back(nums2[j]);
            ++j;
        }
    }
    if (i == nums1.size()){
        for (; j < nums2.size(); ++j){
            merge.push_back(nums2[j]);
        }
    }
    else{
        for (; i < nums1.size(); ++i){
            merge.push_back(nums1[i]);
        }
    }
    if (merge.size() % 2 == 1){
        cout << merge[merge.size() / 2] << endl;
    }
    else{
        cout << merge[merge.size() / 2 - 1] << endl;
    }

    system("pause");
    return 0;
}