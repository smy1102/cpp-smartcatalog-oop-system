#ifndef CLOTHING_H
#define CLOTHING_H

#include "Product.h"
#include <string>

class Clothing : public Product {
public:
    Clothing(std::string name, double price, std::string size);
    ~Clothing() override;

    std::string getCategory() const override;
    bool matchesKeyword(const std::string& keyword) const override;
    void printInfo() const override;

private:
    std::string m_size;
};

#endif // CLOTHING_H
