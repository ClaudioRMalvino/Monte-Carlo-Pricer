#include "europeanOption.cpp"
#include "europeanOption.hpp"
#include <format>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, double> getUserParams();

void printPrices(const std::pair<double, double> &optionPrices,
                 std::unordered_map<std::string, double> &paramValues);

int main() {

  std::unordered_map<std::string, double> params = getUserParams();

  EuropeanOption option =
      EuropeanOption{params["Initial Stock Price"], params["Strike Price"],
                     params["Risk-free Interest Rate"], params["Volatility"],
                     params["Time to Expire"]};

  std::pair<double, double> prices =
      option.calculatePrice(params["Number of Simulations"]);

  printPrices(prices, params);

  return 0;
}

std::unordered_map<std::string, double> getUserParams() {

  std::unordered_map<std::string, double> usrParams{
      {"Number of Simulations", 0.0},
      {"Initial Stock Price", 0.0},
      {"Strike Price", 0.0},
      {"Risk-free Interest Rate", 0.0},
      {"Volatility", 0.0},
      {"Time to Expire", 0.0}};

  for (auto &[param, value] : usrParams) {
    std::cout << "Enter value for " << param << " : ";
    double usrInput;
    std::cin >> usrInput;
    usrParams[param] = usrInput;
  }
  std::cout << '\n';
  return usrParams;
}

void printPrices(const std::pair<double, double> &optionPrices,
                 std::unordered_map<std::string, double> &paramValues) {

  std::cout << std::setprecision(4);
  std::cout << "\nMonte Carlo European Option Prices" << std::endl;
  std::cout << "---------------------------------------------" << '\n';

  for (const auto &[key, value] : paramValues) {
    std::string formatted_str = std::format("{} : {}", key, value);
    std::cout << formatted_str << '\n';
  }

  std::cout << "---------------------------------------------" << '\n';
  std::cout << "Option call price : " << optionPrices.first << '\n';
  std::cout << "Option put price : " << optionPrices.second << std::endl;
}
