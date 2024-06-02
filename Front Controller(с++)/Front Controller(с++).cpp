#include <iostream>
#include <string>
#include <algorithm>

// View classes
class HomeView {
public:
    void Show() {
        std::cout << "Displaying Home Page" << std::endl;
    }
};

class StudentView {
public:
    void Show() {
        std::cout << "Displaying Student Page" << std::endl;
    }
};

// Dispatcher class
class Dispatcher {
private:
    HomeView homeView;
    StudentView studentView;
public:
    void Dispatch(const std::string& request) {
        if (request == "HOME") {
            homeView.Show();
        }
        else {
            studentView.Show();
        }
    }
};

// FrontController class
class FrontController {
private:
    Dispatcher dispatcher;
    bool IsAuthenticUser() {
        std::cout << "User is authenticated successfully." << std::endl;
        return true;
    }
    void TrackRequest(const std::string& request) {
        std::cout << "Page requested: " << request << std::endl;
    }
public:
    void DispatchRequest(const std::string& request) {
        TrackRequest(request);
        if (IsAuthenticUser()) {
            dispatcher.Dispatch(request);
        }
    }
};

// Usage
int main() {
    FrontController frontController;
    frontController.DispatchRequest("HOME");
    frontController.DispatchRequest("STUDENT");
    return 0;
}
