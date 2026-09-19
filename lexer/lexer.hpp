#pragma once

#include "tokens.hpp"
#include <string>
#include <vector>

class Lexer {
public:
  explicit Lexer(const std::string &source);

  std::vector<Token> tokenize();

private:
  std::string source;
  std::size_t position = 0;
  std::size_t line = 1;
  std::size_t column = 1;

  char current() const;
  char peek() const;
  char peekNext() const;
  char advance();

  void skipWhitespace();
  void skipComment();

  Token readNumber();
  Token readIdentifier();
  Token readString();
  Token readChar();

  Token nextToken();
};
