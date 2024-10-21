classDiagram
    class Student {
        +string ID
        +string Fullname
        +string Address
        +string Email
        
        class Date {
            +int Day
            +int Month
            +int Year
            +Date(int day, int month, int year)
            +void print()
        }
        
        +Date DOB
        +Student(string id, string fullname, string address, string email, Date dob)
        +void print()
    }
