#include <iostream>
#include "Menu.h"
using namespace std;
void Menu::ShowCurentStats(int temp, int humidity)
{
    cout<<"Current temperature : "<<temp<<"°C"<<"\n"<<"Current humidity :"<<humidity<<"%\n";
}
void Menu::SetTemp(int &temp)
{
    cout<<"Please type needed temperature : ";
    cin>>temp;
}

void Menu::SetHumidity(int &humidity)
{
    cout<<"Please type needed humidity : ";
    cin>>humidity;
}