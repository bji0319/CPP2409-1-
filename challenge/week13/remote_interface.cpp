#include<iostream>
using namespace std;

//리모컨 인터페이스 정의
class RemoteControl {
public:
    // 순수 가상 함수 정의
    virtual void TurnOn() =0; // 가전 제품을 켠다
    virtual void TurnOff() = 0;// 가전 제품을 끈다   
};

//Tv 클래스 정의
class Televison : public RemoteControl{
    public:
    void TurnOn() override{
        cout << "티비를 켭니다" << endl;
    }
    void TurnOff() override{
        cout << "티비를 끕니다" << endl;
    }
};

//냉장고 클래스 정의
//Tv 클래스 정의
class Refrigerator : public RemoteControl{
    public:
    void TurnOn() override{
        cout << "냉장고를 켭니다." << endl;
    }
    void TurnOff() override{
        cout << "냉장고를 끕니다" << endl;
    }
};

int main() {
    // Tv를 켜고 끄는 동작을 인터페이스를 통해 수행
    RemoteControl*remoteTv = new Televison();
    remoteTv->TurnOn(); // TV를 켬
    remoteTv->TurnOff(); // TV를 끔

    // Tv를 켜고 끄는 동작을 인터페이스를 통해 수행
    RemoteControl*remoteRefrigerator = new Refrigerator();
    remoteRefrigerator->TurnOn(); // 냉장고를 켬
    remoteRefrigerator->TurnOff(); // 냉장고를 끔

    delete remoteTv , remoteRefrigerator;
}