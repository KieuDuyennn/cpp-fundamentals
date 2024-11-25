#ifndef POST_H
#define POST_H

#include <string>
#include <iostream>

class Post {
protected:
    std::string _author;
    std::string _title;
    std::string _content;

public:
    Post() {}
    Post(std::string author, std::string title, std::string content) 
        : _author(author), _title(title), _content(content) {}

    virtual std::string toString() const {
        return "Author: " + _author + "\n" + 
               "Title: " + _title + "\n" + 
               "Content: \n" + _content;
    }
};

#endif // POST_H
