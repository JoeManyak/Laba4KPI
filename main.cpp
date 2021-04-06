#include <bits/stdc++.h>

using namespace std;

const float CURRENT_TEMPERATURE = 18.2 ;
const float CURRENT_HUMIDITY = 52.3 ;

class Stats{
private:
    float temperature = CURRENT_TEMPERATURE ; \
    float humidity = CURRENT_HUMIDITY ;
public:
    float MeasureTemp(){
        return temperature ;
    }
    float MeasureHumidity(){
        return humidity ;
    }
};


class ChangeTemperature: public Stats{
public:
    void TurnOnCooler(float changeTo){
        Stats stats ;
        float From = stats.MeasureTemp() ;
        for(float j = From ; j >= changeTo ; j -= 0.1 ){
            system("CLS") ;
            cout << "Current temperature: " << j << " C\n" ;
        }
        cout << "Done!\n" ;
    }
    void TurnOnHeater(float changeTo){
        Stats stats ;
        float From = stats.MeasureTemp() ;
        for(float j = From ; j <= changeTo ; j += 0.1 ){
            system("CLS") ;
            cout << "Current temperature: " << j << " C\n" ;
        }
        cout << "Done!\n" ;
    }
    void TurnOffDevices(){
        return ;
    }
};

class ChangeHumidity: public Stats{
public:
    void TurnOnHumidifier(float changeTo){
        Stats stats ;
        float From = stats.MeasureHumidity() ;
        for(float j = From ; j >= changeTo ; j -= 1 ){
            system("CLS") ;
            cout << "Current humidity: " << j << " C\n" ;
        }
        cout << "Done!\n" ;
    }
    void TurnOnDehumidifier(float changeTo){
        Stats stats ;
        float From = stats.MeasureHumidity() ;
        for(float j = From ; j <= changeTo ; j += (changeTo - j <= 2) ? 0.1 : 1 ){
            system("CLS") ;
            cout << "Current humidity: " << j << " C\n" ;
        }
        cout << "Done!\n" ;
    }
    void TurnOffDevices(){
        return ;
    }
};

class Menu{
public:
    int choice ;

    Menu(){}
    void makeChoice(int choice){
        if( choice == 1 ){
            SetTemp() ;
        } else if( choice == 2 ){
            SetHumidity() ;
        } else if( choice == 3 ){
            ShowCurrentStats() ;
        } else {
            cout << "Error!" ;
        }
    }
    void SetTemp(){
        cout << "Enter the temperature : " ;
        float temperature ;
        cin >> temperature ;

        if( temperature > 35 || temperature < 5 ){
            cout << "Ooops! Sorry, we can't do that\n" ;
            return ;
        }

        ChangeTemperature changer ;
        if( temperature > changer.MeasureTemp() ){
            changer.TurnOnHeater(temperature) ;
        } else {
            changer.TurnOnCooler(temperature) ;
        }
    }
    void SetHumidity(){
        cout << "Enter the humidity : " ;
        float humidity ;
        cin >> humidity ;

        if( humidity > 99 || humidity < 10 ){
            cout << "Ooops! Sorry, we can't do that\n" ;
            return ;
        }

        ChangeHumidity changer ;
        if( humidity < changer.MeasureHumidity() ){
            changer.TurnOnHumidifier(humidity) ;
        } else {
            changer.TurnOnDehumidifier(humidity) ;
        }
    }
    void ShowCurrentStats(){
        Stats currentStats ;
        cout << "==================" ;
        cout << "Temperature: " << currentStats.MeasureTemp() << '\n' ;
        cout << "Humidity: " << currentStats.MeasureHumidity() << '\n' ;
        cout << "==================" ;
    }

    void showMenu(){
        cout << "(1) - set temperature\n" ;
        cout << "(2) - set humidity\n" ;
        cout << "(3) - show stats\n" ;
        cin >> choice ;
        makeChoice(choice) ;
    }
};


int main()
{

    Menu menu ;
    menu.showMenu() ;


    return 0 ;
}

