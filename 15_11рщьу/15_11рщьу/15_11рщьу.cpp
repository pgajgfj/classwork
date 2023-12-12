#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Shape {
public:
    virtual void Show() const = 0;
    virtual void Save(const string& filename) const = 0;
    virtual void Load(const string& filename) = 0;
    virtual ~Shape() = default;
};

class Square : public Shape {
private:
    double x;
    double y;
    double side;

public:
    Square(double x, double y, double side) : x(x), y(y), side(side) {}

    void Show() const override {
        cout << "Square: Left Top Corner (" << x << ", " << y << "), Side: " << side << endl;
    }

    void Save(const string& filename) const override {
        ofstream file(filename);
        if (file.is_open()) {
            file << "Square " << x << " " << y << " " << side;
            file.close();
        }
        else {
            cerr << "Unable to open file for saving." << endl;
        }
    }

    void Load(const string& filename) override {
        ifstream file(filename);
        if (file.is_open()) {
            file >> x >> y >> side;
            file.close();
        }
        else {
            cerr << "Unable to open file for loading." << endl;
        }
    }
};

class Rectangle : public Shape {
private:
    double x;
    double y;
    double width;
    double height;

public:
    Rectangle(double x, double y, double width, double height) : x(x), y(y), width(width), height(height) {}

    void Show() const override {
        cout << "Rectangle: Left Top Corner (" << x << ", " << y << "), Width: " << width << ", Height: " << height << endl;
    }

    void Save(const string& filename) const override {
        ofstream file(filename);
        if (file.is_open()) {
            file << "Rectangle " << x << " " << y << " " << width << " " << height;
            file.close();
        }
        else {
            cerr << "Unable to open file for saving." << endl;
        }
    }

    void Load(const std::string& filename) override {
        ifstream file(filename);
        if (file.is_open()) {
            file >> x >> y >> width >> height;
            file.close();
        }
        else {
            cerr << "Unable to open file for loading." << endl;
        }
    }
};



int main() {
    std::vector<Shape*> shapes;

    
    Square square(0, 0, 5);
    Rectangle rectangle(1, 1, 6, 4);

    
    shapes.push_back(&square);
    shapes.push_back(&rectangle);

  
    for (const auto& shape : shapes) {
        shape->Save("shape_file.txt");
    }

    
    std::vector<Shape*> loadedShapes;
    for (const auto& shape : shapes) {
        Shape* newShape;
       
       
        
        newShape = new Square(0, 0, 1);
        newShape->Load("shape_file.txt");
        loadedShapes.push_back(newShape);
    }
 
    for (const auto& shape : loadedShapes) {
        shape->Show();
    }

    
    for (const auto& shape : loadedShapes) {
        delete shape;
    }


}
