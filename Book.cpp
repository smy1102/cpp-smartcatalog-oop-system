#include "Book.h"
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>

static std::string toLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return s;
}

Book::Book(std::string name, double price, std::string author)
    : Product(std::move(name), price), m_author(std::move(author)) {}

Book::~Book() = default;

std::string Book::getCategory() const { return "Book"; }

bool Book::matchesKeyword(const std::string& keyword) const {
    std::string key = toLower(keyword);
    return toLower(m_name).find(key) != std::string::npos ||
           toLower(m_author).find(key) != std::string::npos;
}

void Book::printInfo() const {
    std::cout << "Category: " << getCategory()
              << " | Name: " << m_name
              << " | Price: " << std::fixed << std::setprecision(2) << m_price
              << " | Author: " << m_author << std::endl;
}
