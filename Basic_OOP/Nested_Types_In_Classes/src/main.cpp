/* Nesting types */
// Unlike functions, which cant be defined inside other functions, types can be defined (nested)
// inside a class. To do so, define the type inside the class under the appropriate acces identifier.
// Classes basically act as namespaces for nested types.
// Note: enum classes also act as namespaces, if we had nested an emum type inside a class as
// an enum class then we need to do the following: ClassName::enumClass::value

/* Othe types can be nested too */
// Although enumerations are probably the most common types nested in a class, there are other possibilities.
// Nested types can't be forward declared. 

#include <iostream>

class Fruit {
public:
    enum FruitType {
        APPLE,
        BANNANA,
        CHERRY
    };
private:
    FruitType m_type;
    int m_percentageEaten;
public:
    Fruit(FruitType type) { m_type = type; }
    FruitType getType() const { return m_type; }
    int getPercentageEaten() const { return m_percentageEaten; }
};

int main()
{
    if (Fruit{ Fruit::APPLE }.getType() == Fruit::APPLE) {
        std::cout << "I am an apple!" << std::endl;
    } else{
        std::cout << "I am not an apple!" << std::endl;
    }
}
