#include "Electronics.h"
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>

static std::string toLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return s;
}

Electronics::Electronics(std::string name, double price, int warrantyMonths)
    : Product(std::move(name), price), m_warrantyMonths(warrantyMonths) {}

Electronics::~Electronics() = default;

std::string Electronics::getCategory() const { return "Electronics"; }

bool Electronics::matchesKeyword(const std::string& keyword) const {
    std::string key = toLower(keyword);
    std::ostringstream oss;
    oss << m_warrantyMonths;
    return toLower(m_name).find(key) != std::string::npos ||
           oss.str().find(key) != std::string::npos;
}

void Electronics::printInfo() const {
    std::cout << "Category: " << getCategory()
              << " | Name: " << m_name
              << " | Price: " << std::fixed << std::setprecision(2) << m_price
              << " | Warranty: " << m_warrantyMonths << " months" << std::endl;
}
