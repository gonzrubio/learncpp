#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H

using data_t = double;
data_t getUserInput();
char getMathematicalOperation();
data_t calculateResult(const data_t a, const char c, const data_t b) ;
void printResult(const data_t answer);

#endif // !CALCULATOR_H


