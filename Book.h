#ifndef BOOK_H
#define BOOK_H

#include "Product.h"
#include <string>

class Book : public Product {
public:
    Book(std::string name, double price, std::string author);
    ~Book() override;

    std::string getCategory() const override;
    bool matchesKeyword(const std::string& keyword) const override;
    void printInfo() const override;

private:
    std::string m_author;
};

#endif // BOOK_H
