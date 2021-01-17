/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** BigDecimal
*/

#include "Operand/BigDecimal.hpp"
#include "Core/Factory.hpp"
#include <algorithm>
#include <regex>

VM::BigDecimal::BigDecimal(const std::string &value)
{
    std::string tmp(value);
    int charToCheck = tmp[0] == '-' ? 1 : 0;

    while (tmp[charToCheck] && tmp[charToCheck] != '.')
        if (tmp[charToCheck] == '0')
            tmp.erase(charToCheck, 1);
        else
            break;
    if (tmp.empty()) {
        tmp = "0";
    } else if (tmp[charToCheck] == '.')
        tmp.insert(0, 1, '0');
    if (hasDot(tmp)) {
        for (auto it = value.rbegin(); it != value.rend(); it++) {
            if (*it == '0')
                tmp.pop_back();
            if (*it != '0')
                break;
            else if (*it == '.') {
                tmp.pop_back();
                break;
            }
        }
    }
    if (tmp == "-0")
        tmp = "0";
    this->_value = tmp;
}

std::string VM::BigDecimal::toString() const
{
    return (this->_value);
}

uint8_t VM::BigDecimal::countDigitsAfterDot(const std::string &string) const
{
    std::regex exp("\\.[0-9]+");
    std::smatch match;

    if (std::regex_search(string, match, exp))
        return (match[0]).length() - 1;
    return 0;
}

bool VM::BigDecimal::hasDot(const std::string &s1) const
{
    return s1.find('.') != std::string::npos;
}

void VM::BigDecimal::addDot(std::string &s) const
{
    s += ".0";
}

void VM::BigDecimal::alignDots(std::string &s1, std::string &s2) const
{
    std::regex exp("\\.[0-9]+");
    std::smatch match;

    if (!hasDot(s1) && !hasDot(s2))
        return;
    if (hasDot(s1) ^ hasDot(s2))
        addDot(hasDot(s1) ? s2 : s1);
    int l1 = countDigitsAfterDot(s1);
    int l2 = countDigitsAfterDot(s2);
    (l1 < l2 ? s1 : s2).append(abs(l1 - l2), '0');
}

bool VM::BigDecimal::isNeg(const std::string &str) const
{
    return (str[0] == '-');
}

bool VM::BigDecimal::firstIsGreater(const std::string &s1, const std::string &s2) const
{
    if (s1.length() > s2.length())
        return true;
    else if (s1.length() < s2.length())
        return false;
    return s1.compare(s2) < 0 ? false : true;
}

bool VM::BigDecimal::isNegGreater(const std::string &s1, const std::string &s2) const
{
    bool s1IsNeg = isNeg(s1);
    std::string tmp = std::string(s1IsNeg ? s1 : s2).erase(0, 1);

    if (s1IsNeg)
        return firstIsGreater(tmp, s2);
    else
        return firstIsGreater(tmp, s1);
}


std::string VM::BigDecimal::addToSub(const std::string &s1, const std::string &s2) const
{
    bool s1IsNeg = isNeg(s1);
    std::string tmp = std::string(s1IsNeg ? s1 : s2).erase(0, 1);
    std::string res;

    if (s1IsNeg)
        res = handleSub(tmp, s2);
    else
        res = handleSub(s1, tmp);
    return (isNegGreater(s1, s2) ? "-" : "") + res;
}

std::string VM::BigDecimal::addStrings(const std::string &s1, const std::string &s2) const // short string then long one
{
    auto it2 = s2.rbegin();
    auto it1 = s1.rbegin();
    bool areNeg = isNeg(s1) && isNeg(s2);
    std::string res("");
    uint8_t ret = 0;
    uint8_t tmpRes;

    if (isNeg(s1) ^ isNeg(s2))
        return addToSub(s1, s2);
    for (; it1 != s1.rend(); it1++) {
        if (*it1 == '.')
            res.append(1, '.');
        else if (*it1 == '-')
            break;
        else {
            tmpRes = (*it1 - '0') + (*it2 - '0') + ret;
            ret = tmpRes / 10;
            res.append(std::to_string(tmpRes % 10));
        }
        it2++;
    }
    if ((it2 == s2.rend() || *it2 == '-') && ret)
        res.append(std::to_string(ret));
    for (; it2 != s2.rend(); it2++) {
        if (*it2 == '-')
            break;
        tmpRes = (*it2 - '0') + ret;
        ret = tmpRes / 10;
        res.append(std::to_string(tmpRes % 10));
    }
    if (areNeg)
        res.append(1, '-');
    std::reverse(res.begin(), res.end());
    return res;
}

IOperand *VM::BigDecimal::operator+(const IOperand &rhs) const
{
        IOperand *tmp = Factory::createOperand(eOperandType::BigDecimal, "0");
    std::string s1 = toString();
    std::string s2 = rhs.toString();

    alignDots(s1, s2);
    if (s1.length() < s2.length())
        return Factory::createOperand(eOperandType::BigDecimal, addStrings(s1, s2));
    else
        return Factory::createOperand(eOperandType::BigDecimal, addStrings(s2, s1));
}

std::string VM::BigDecimal::subStrings(const std::string &s1, const std::string &s2) const
{
    auto bigIt = s1.rbegin();
    auto smallIt = s2.rbegin();
    int tmpRes = 0;
    int ret = 0;
    std::string res;

    for (; bigIt != s1.rend(); bigIt++) {
        if (*bigIt == '.') {
            ++smallIt;
            res.insert(0, 1, '.');
            continue;
        }
        tmpRes = (*bigIt - '0') - (*smallIt - '0' + ret); 
        ret = tmpRes < 0 ? 1 : 0;
        if (tmpRes >= 0)
            res.insert(0, std::to_string(tmpRes));
        else
            res.insert(0, std::to_string(10 - (tmpRes * (-1))));
        ++smallIt;
    }
    return res;
}

std::string &VM::BigDecimal::doSameLen(std::string &s1, const std::string &s2) const
{
    int len = s2.length() - s1.length();

    s1.insert(s1.begin(), len, '0');
    return s1;
}

std::string VM::BigDecimal::handleSub(const std::string &s1, const std::string &s2) const
{
    std::string big = "0" + getGreater(s1, s2);
    std::string small = std::string(getSmaller(s1, s2));
    small = doSameLen(small, "0" + big);

    std::cerr << s1 << " - " << s2 << std::endl;
    return subStrings(big, small);
}

IOperand *VM::BigDecimal::operator-(const IOperand &rhs) const
{
        std::string s1 = toString();
    std::string s2 = rhs.toString();
    std::string res;

    alignDots(s1, s2);
    if (isNeg(s1) ^ isNeg(s2)) {
        if (isNeg(s2)) {
            s2.erase(std::remove(s2.begin(), s2.end(), '-'), s2.end());    
            if (firstIsGreater(s2, s1))
                res = addStrings(s1, s2);
            else
                res = addStrings(s2, s1);            
        } if (isNeg(s1)) {
            s1.erase(std::remove(s1.begin(), s1.end(), '-') , s1.end());
            if (firstIsGreater(s1, s2))
                res = addStrings(s2, s1);
            else
                res = addStrings(s1, s2);
            if (res[0] == '.')
                res.insert(0, 1, '0');
            res.insert(res.begin(), 1, '-');
        }
    } else if (isNeg(s1) && isNeg(s2)) {
        s1.erase(std::remove(s1.begin(), s1.end(), '-'), s1.end());
        s2.erase(std::remove(s2.begin(), s2.end(), '-'), s2.end());    
        res = handleSub(s1, s2);
        if (firstIsGreater(s1, s2)) {
            if (res[0] == '.')
                res.insert(0, 1, '0');
            res.insert(res.begin(), 1, '-');
        }
    } else {
        res = handleSub(s1, s2);
        if (firstIsGreater(s2, s1)) {
            if (res[0] == '.')
                res.insert(0, 1, '0');
            res.insert(res.begin(), 1, '-');
        }
    }
    return Factory::createOperand(eOperandType::BigDecimal, res);
}

/* Multiplication */

std::string VM::BigDecimal::placeDot(std::string &s, int dotPlacement) const
{
    if (dotPlacement == 0)
        return s;
    std::reverse(s.begin(), s.end());
    s.insert(dotPlacement, ".");
    std::reverse(s.begin(), s.end());
    return s;
}

std::string VM::BigDecimal::multStrings(const std::string &s1, const std::string &s2) const
{
    const std::string &big = firstIsGreater(s1, s2) ? s1 : s2;
    const std::string &small = firstIsGreater(s1, s2) ? s2 : s1;
    std::stack<std::string> subMulResults;
    int i = 0;

    for(auto it2 = small.rbegin() ;it2 != small.rend(); it2++) {
        std::string res("");
        int tmpRes = 0;
        int ret = 0;

        for (auto it1 = big.rbegin(); it1 != big.rend(); it1++) {
            tmpRes = (*it2 - '0') * (*it1 - '0') + ret;
            ret = tmpRes / 10;
            res.append(std::to_string(tmpRes % 10));
        }
        if (ret)
            res.append(std::to_string(ret));
        std::reverse(res.begin(), res.end());
        res.append(i, '0');
        subMulResults.push(res);
        ++i;
    }
    std::string res("0");
    while (!subMulResults.empty()) {
        auto cur = subMulResults.top();
        subMulResults.pop();
        if (firstIsGreater(res, cur))
            res = addStrings(cur, res);
        else
            res = addStrings(res, cur);
    }
    return res;
}

IOperand *VM::BigDecimal::operator*(const IOperand &rhs) const
{
    std::string s1 = toString();
    std::string s2 = rhs.toString();
    std::string res("");
        int afterDotNumbers = countDigitsAfterDot(s1) + countDigitsAfterDot(s2);
    bool neg = isNeg(s1) ^ isNeg(s2);

    s1.erase(std::remove(s1.begin(), s1.end(), '.'), s1.end());    
    s2.erase(std::remove(s2.begin(), s2.end(), '.'), s2.end());    
    s1.erase(std::remove(s1.begin(), s1.end(), '-'), s1.end());    
    s2.erase(std::remove(s2.begin(), s2.end(), '-'), s2.end());    
    res = multStrings(s1, s2);
    res = placeDot(res, afterDotNumbers);
    if (neg)
        res.insert(res.begin(), 1, '-');
    return Factory::createOperand(eOperandType::BigDecimal, res);
}

IOperand *VM::BigDecimal::operator/(const IOperand &rhs) const
{
    IOperand *tmp;

    throw MyException("BigDecimal operator /");
    return (tmp);
}


void VM::BigDecimal::removeIntPart(std::string &s) const
{
    if (!hasDot(s))
        return;
    while (s[0] != '.')
        s.erase(0, 1);
    s.insert(0, 1, '0');
}

IOperand *VM::BigDecimal::operator%(const IOperand &rhs) const
{
    IOperand *a = Factory::createOperand(eOperandType::BigDecimal, toString());
    IOperand *b = Factory::createOperand(eOperandType::BigDecimal, rhs.toString());

    if (isNeg(a->toString()) ^ isNeg(b->toString())) {
        if (isNeg(a->toString())) {
            std::string adivb = (*(*a / *b)).toString();
            removeIntPart(adivb);
            IOperand *adb = Factory::createOperand(eOperandType::BigDecimal, adivb);
            return *(*(*adb * *b) - *b) * *Factory::createOperand(eOperandType::BigDecimal, "-1");
        } else {
            std::string adivb = (*(*a / *b)).toString();
            removeIntPart(adivb);
            IOperand *adb = Factory::createOperand(eOperandType::BigDecimal, adivb);
            return *(*adb * *b) - *b;
        }
    } else {
        std::string adivb = (*(*a / *b)).toString();
        removeIntPart(adivb);
        if (isNeg(a->toString()) && isNeg(b->toString()))
            adivb.insert(0, 1, '-');
        IOperand *adb = Factory::createOperand(eOperandType::BigDecimal, adivb);
        return *adb * *b;
    }
}