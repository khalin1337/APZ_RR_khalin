using System;
using System.Collections.Generic;

// FrontController class
public class FrontController
{
    private Dispatcher dispatcher;

    public FrontController()
    {
        dispatcher = new Dispatcher();
    }

    private bool IsAuthenticUser()
    {
        Console.WriteLine("User is authenticated successfully.");
        return true;
    }

    private void TrackRequest(string request)
    {
        Console.WriteLine("Page requested: " + request);
    }

    public void DispatchRequest(string request)
    {
        TrackRequest(request);
        if (IsAuthenticUser())
        {
            dispatcher.Dispatch(request);
        }
    }
}

// Dispatcher class
public class Dispatcher
{
    private HomeView homeView;
    private StudentView studentView;

    public Dispatcher()
    {
        homeView = new HomeView();
        studentView = new StudentView();
    }

    public void Dispatch(string request)
    {
        if (request.Equals("HOME", StringComparison.InvariantCultureIgnoreCase))
        {
            homeView.Show();
        }
        else
        {
            studentView.Show();
        }
    }
}

// View classes
public class HomeView
{
    public void Show()
    {
        Console.WriteLine("Displaying Home Page");
    }
}

public class StudentView
{
    public void Show()
    {
        Console.WriteLine("Displaying Student Page");
    }
}

// Usage
class Program
{
    static void Main(string[] args)
    {
        FrontController frontController = new FrontController();
        frontController.DispatchRequest("HOME");
        frontController.DispatchRequest("STUDENT");
    }
}
