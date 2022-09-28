//
// Created by Мария Ульянова on 24.09.2022.
//
#include <iostream>
#include <cmath>
using namespace std;

bool area_determination()
{
    float x, y;
    float radius = 2;
    float center_x = 0, center_y = 0;
    cout<<"Enter coordinates"<<endl;
    cin>>x>>y;
    if (fabs(x - center_x)<=2 && fabs(y - center_y) <= 2)
    {
        if (sqrt(x - center_x) + sqrt(y - center_y) > sqrt(radius))
        {
            return true;
        }
        else {return false;}
    }
    else {return false;}
}

void result_func(bool result_value)
{
    if (result_value == true)
    {
        cout<<"belong"<<endl;
    }
    else
    {
        cout<<"do not belong"<<endl;
    }
}
int main()
{
    while (true) {
        bool result;
        result = area_determination();
        result_func(result) ;
// there is 'if' operator to continue process
        int x;
        cout<<"Do you want to check coordinates again? Y - 1, N - 0"<<endl;
        cin>>x;
        //if no : break
        if (x==0){
            break;
        }
    }
    return 0;
}