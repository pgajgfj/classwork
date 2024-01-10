#include <iostream>
#include <vector>
using namespace std;

class IDevice {
public:
    virtual void power() = 0;
    virtual void plus() = 0;
    virtual void minus() = 0;
    virtual void next() = 0;
    virtual void prev() = 0;
    virtual void showInfo() = 0;
    virtual ~IDevice() {}
};


class TV : public IDevice {
private:
    bool isOn;
    int volume;
    int currentChannel;
    int maxVolume;
    int maxChannels;

public:
    TV(int maxVol, int maxCh) : isOn(false), volume(0), currentChannel(1), maxVolume(maxVol), maxChannels(maxCh) {}

    void power() override {
        isOn = !isOn;
        if (!isOn) {
            volume = 0;
            currentChannel = 1;
        }
    }

    void plus() override {
        if (isOn && volume < maxVolume) {
            ++volume;
        }
    }

    void minus() override {
        if (isOn && volume > 0) {
            --volume;
        }
    }

    void next() override {
        if (isOn && currentChannel < maxChannels) {
            ++currentChannel;
        }
    }

    void prev() override {
        if (isOn && currentChannel > 1) {
            --currentChannel;
        }
    }

    void showInfo() override {
        cout << "TV - Power: " << (isOn ? "On" : "Off") << ", Volume: " << volume << ", Channel: " << currentChannel << std::endl;
    }
};


enum AirConditionerMode {
    HEAT,
    COOL,
    TURBO,
    SLEEP
};


class AirConditioner : public IDevice {
private:
    bool isOn;
    int temperature;
    AirConditionerMode mode;

public:
    AirConditioner() : isOn(false), temperature(20), mode(AirConditionerMode::COOL) {}

    void power() override {
        isOn = !isOn;
        if (!isOn) {
            temperature = 20;
            mode = AirConditionerMode::COOL;
        }
    }

    void plus() override {
        if (isOn && temperature < 25) {
            ++temperature;
        }
    }

    void minus() override {
        if (isOn && temperature > 16) {
            --temperature;
        }
    }

    void next() override {
        if (isOn) {
            mode = static_cast<AirConditionerMode>((mode + 1) % 4);
        }
    }

    void prev() override {
        if (isOn) {
            mode = static_cast<AirConditionerMode>((mode + 3) % 4);
        }
    }

    void showInfo() override {
        cout << "AirConditioner - Power: " << (isOn ? "On" : "Off") << ", Temperature: " << temperature << ", Mode: ";
        switch (mode) {
        case AirConditionerMode::HEAT:
            cout << "Heat";
            break;
        case AirConditionerMode::COOL:
            cout << "Cool";
            break;
        case AirConditionerMode::TURBO:
            cout << "Turbo";
            break;
        case AirConditionerMode::SLEEP:
            cout << "Sleep";
            break;
        }
        cout << endl;
    }
};

class SmartRemote {
private:
    IDevice* currentDevice;

public:
    SmartRemote(IDevice* device) : currentDevice(device) {}

    void setDevice(IDevice* device) {
        currentDevice = device;
    }

    void power() {
        currentDevice->power();
    }

    void plus() {
        currentDevice->plus();
    }

    void minus() {
        currentDevice->minus();
    }

    void next() {
        currentDevice->next();
    }

    void prev() {
        currentDevice->prev();
    }

    void showInfo() {
        currentDevice->showInfo();
    }
};

int main() {
    
    TV tv(10, 100);
    AirConditioner ac;

    
    SmartRemote remote(&tv);

    remote.power();
    remote.showInfo();
    remote.plus();
    remote.showInfo();
    remote.next();
    remote.showInfo();

    remote.setDevice(&ac);
    remote.power();
    remote.showInfo();
    remote.plus();
    remote.showInfo();
    remote.next();
    remote.showInfo();

    return 0;
}