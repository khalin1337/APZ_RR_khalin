# Шаблоны проектирования

## 1. Builder
### Призначення
Шаблон Builder використовується для покрокового створення складних об'єктів.

### UML-диаграмма
```mermaid
classDiagram
    class Builder {
        +buildPartA()
        +buildPartB()
        +getResult(): Product
    }
    class ConcreteBuilder {
        +buildPartA()
        +buildPartB()
        +getResult(): Product
    }
    class Product {
        -partA: String
        -partB: String
    }
    Builder <|-- ConcreteBuilder
    ConcreteBuilder --> Product
```
## 2.Front Controller
### Призначення
Шаблон Front Controller використовується для централізованого керування обробкою запитів у веб-додатках.
### UML-диаграмма
```mermaid
classDiagram
    class FrontController {
        +DispatchRequest(request: String)
    }
    class Dispatcher {
        +Dispatch(request: String)
    }
    class HomeView {
        +Show()
    }
    class StudentView {
        +Show()
    }
    FrontController --> Dispatcher
    Dispatcher --> HomeView
    Dispatcher --> StudentView
```
## 3. Command
### Призначення
Шаблон "Command" перетворює запити на об'єкти, дозволяючи передавати їх як параметри методу
### UML-диаграмма
```mermaid
classDiagram
    class ICommand {
        +Execute()
    }
    class LightOnCommand {
        +Execute()
    }
    class LightOffCommand {
        +Execute()
    }
    class Light {
        +On()
        +Off()
    }
    class RemoteControl {
        +SetCommand(command: ICommand)
        +PressButton()
    }
    ICommand <|-- LightOnCommand
    ICommand <|-- LightOffCommand
    LightOnCommand --> Light
    LightOffCommand --> Light
    RemoteControl --> ICommand
```
## 4. Readers-writer lock
### Призначення
Шаблон "Readers-writer lock" використовується для управління доступом до ресурсу, який може читати багато потоків одночасно, але писати в нього може тільки один потік.
### UML-диаграмма
```mermaid
classDiagram
    class ReadersWritersLock {
        +Read(readAction: Action)
        +Write(writeAction: Action)
    }
```
