#include <iostream>
#include <string>

// Product class
class Product {
public:
    std::string PartA;
    std::string PartB;
};

// Abstract Builder
class Builder {
public:
    virtual void BuildPartA() = 0;
    virtual void BuildPartB() = 0;
    virtual Product GetResult() = 0;
};

// Concrete Builder
class ConcreteBuilder : public Builder {
private:
    Product product;
public:
    void BuildPartA() override {
        product.PartA = "PartA";
    }
    void BuildPartB() override {
        product.PartB = "PartB";
    }
    Product GetResult() override {
        return product;
    }
};

// Director
class Director {
public:
    void Construct(Builder& builder) {
        builder.BuildPartA();
        builder.BuildPartB();
    }
};

// Usage
int main() {
    ConcreteBuilder builder;
    Director director;
    director.Construct(builder);
    Product product = builder.GetResult();
    std::cout << "Product parts: " << product.PartA << ", " << product.PartB << std::endl;
    return 0;
}
