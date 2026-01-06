#include "Clothing.h"
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>

static std::string toLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return s;
}

Clothing::Clothing(std::string name, double price, std::string size)
    : Product(std::move(name), price), m_size(std::move(size)) {}

Clothing::~Clothing() = default;

std::string Clothing::getCategory() const { return "Clothing"; }

bool Clothing::matchesKeyword(const std::string& keyword) const {
    std::string key = toLower(keyword);
    return toLower(m_name).find(key) != std::string::npos ||
           toLower(m_size).find(key) != std::string::npos;
}

void Clothing::printInfo() const {
    std::cout << "Category: " << getCategory()
              << " | Name: " << m_name
              << " | Price: " << std::fixed << std::setprecision(2) << m_price
              << " | Size: " << m_size << std::endl;
}
