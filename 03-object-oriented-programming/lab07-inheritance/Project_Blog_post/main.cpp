#include <iostream>
#include "bus/GraphPost.h"
#include "ui/PostPrinter.h"
#include "ui/MoneyFormatter.h"

int main() {
    // Dữ liệu ban đầu cho bài viết
    auto author = "Jane";
    auto title = "3 tips to learn English effectively";
    auto content = std::string("To learn English effectively, you can try these 3 tips.\n") 
                   + "1. Practice on a daily basis.\n"
                   + "2. Take time to understand difficult paragraphs\n"
                   + "3. Try new things everyday";
    
    // Tạo đối tượng GraphPost
    GraphPost p(author, title, content, 5);
    
    // Thêm các bình luận
    p.addComment("Anna", "Great work.");
    p.addComment("Blash", "This helps me a lot!");
    p.addComment("Jack", "Thanks for your post.");
    
    // In ra bài viết sử dụng PostPrinter
    PostPrinter::printPost(p);

    return 0;
}
