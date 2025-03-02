#include<iostream>
using namespace std;
class Engine{
    bool isRunning;
    public:
    void start(){
        cout<<"Engine Started"<<endl;
    }
    void stop(){
        cout<<"Engine Stopped"<<endl;
    }
};
class Car{
    Engine engine;
    public:
    void startCar(){
        engine.start();
    }
    void stopCar(){
        engine.stop();
    }
};
int main(){
    Car car1;
    car1.startCar();
    car1.stopCar();
}
