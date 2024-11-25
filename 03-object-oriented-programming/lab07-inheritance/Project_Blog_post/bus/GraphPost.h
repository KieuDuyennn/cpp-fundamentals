#ifndef GRAPHPOST_H
#define GRAPHPOST_H

#include "Post.h"
#include <vector>

class GraphPost : public Post {
private:
    int _likes;
    std::vector<std::pair<std::string, std::string>> _comments; // pair(commenter, content)

public:
    GraphPost() : Post(), _likes(0) {}

    GraphPost(std::string author, std::string title, std::string content, int likes) 
        : Post(author, title, content), _likes(likes) {}

    void addComment(const std::string& commenter, const std::string& commentContent) {
        _comments.push_back({commenter, commentContent});
    }

    virtual std::string toString() const override {
        std::string postString = Post::toString() + "\n\n" + 
                                 "Likes: " + std::to_string(_likes) + "\n" + 
                                 "Comments: " + std::to_string(_comments.size()) + "\n";
        
        for (const auto& comment : _comments) {
            postString += "- " + comment.first + ": " + comment.second + "\n";
        }

        return postString;
    }
};

#endif // GRAPHPOST_H
