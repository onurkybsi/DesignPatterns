#include <iostream>
#include <vector>

class Product {
public:
    std::vector<std::string> parts;
    
    void ListParts()const {
        std::cout << "Product parts: ";
        
        for (size_t i = 0; i < parts.size(); i++) {
            if (parts[i] == parts.back()) {
                std::cout << parts[i];
            }
            else {
                std::cout << parts[i] << ", ";
            }
        }

        std::cout << "\n";
    }
};

class Builder {
public:
    virtual ~Builder() {}
    virtual Product* GetProduct() = 0;
    virtual void ProducePartA() const = 0;
    virtual void ProducePartB() const = 0;
    virtual void ProducePartC() const = 0;
};

class BuilderA : public Builder {
private:
    Product* product;
public:

    BuilderA() {
        this->Reset();
    }

    ~BuilderA() {
        delete product;
    }

    void Reset() {
        this->product = new Product();
    }

    void ProducePartA() const override {
        this->product->parts.push_back("PartA by BuilderA");
    }

    void ProducePartB() const override {
        this->product->parts.push_back("PartB by BuilderA");
    }

    void ProducePartC() const override {
        this->product->parts.push_back("PartC by BuilderA");
    }

    Product* GetProduct() override {
        Product* result = this->product;

        this->Reset();
        
        return result;
    }
};

class Director {
private:
    Builder* builder;
public:
    Director(Builder* builder) : builder(builder) {}

    void BuildMVP() {
        this->builder->ProducePartA();
    }

    void BuildFullFeaturedProduct() {
        this->builder->ProducePartA();
        this->builder->ProducePartB();
        this->builder->ProducePartC();
    }
};

int main() {
    Builder* builderA = new BuilderA();

    Director* director = new Director(builderA);

    director->BuildMVP();

    std::cout << "MVP : ";
    builderA->GetProduct()->ListParts();

    director->BuildFullFeaturedProduct();

    std::cout << "Full Featured Product : ";
    builderA->GetProduct()->ListParts();

    return 0;
}