classDiagram
    class Product {
        +string ID
        +string Name
        +float Price
        
        class Date {
            +int Day
            +int Month
            +int Year
            +Date(int day, int month, int year)
            +void print()
        }
        
        +Date ExpiryDate
        +Product(string id, string name, float price, Date expiryDate)
        +void print()
    }
