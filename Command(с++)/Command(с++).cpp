#include <iostream>
#include <memory>

// Command Interface
class ICommand {
public:
    virtual void Execute() = 0;
};

// Receiver
class Light {
public:
    void On() {
        std::cout << "Light is On" << std::endl;
    }

    void Off() {
        std::cout << "Light is Off" << std::endl;
    }
};

// Concrete Commands
class LightOnCommand : public ICommand {
private:
    Light& light;
public:
    LightOnCommand(Light& light) : light(light) {}

    void Execute() override {
        light.On();
    }
};

class LightOffCommand : public ICommand {
private:
    Light& light;
public:
    LightOffCommand(Light& light) : light(light) {}

    void Execute() override {
        light.Off();
    }
};

// Invoker
class RemoteControl {
private:
    std::unique_ptr<ICommand> command;
public:
    void SetCommand(std::unique_ptr<ICommand> cmd) {
        command = std::move(cmd);
    }

    void PressButton() {
        if (command) {
            command->Execute();
        }
    }
};

// Usage
int main() {
    Light livingRoomLight;
    RemoteControl remote;

    remote.SetCommand(std::make_unique<LightOnCommand>(livingRoomLight));
    remote.PressButton();

    remote.SetCommand(std::make_unique<LightOffCommand>(livingRoomLight));
    remote.PressButton();

    return 0;
}
