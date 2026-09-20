#include "lexer.hpp"
#include <cctype>

Lexer::Lexer(const std::string &source)
    : source(source), position(0), line(1), column(1) {}

char Lexer::current() const {
  if (position < source.size()) {
    return source[position];
  }
  return '\0';
}

char Lexer::peek() const {
  if (position + 1 < source.size()) {
    return source[position + 1];
  }
  return '\0';
}

char Lexer::peekNext() const {
  if (position + 2 < source.size()) {
    return source[position + 2];
  }
  return '\0';
}

char Lexer::advance() {
  char c = current();
  if (c == '\n') {
    line++;
    column = 1;
  } else {
    column++;
  }
  if (position < source.size()) {
    position++;
  }
  return c;
}

void Lexer::skipWhitespace() {
  char c = current();
  while (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
    c = advance();
  }
}

void Lexer::skipComment() {
  if (current() == '-' && peek() == '-' && peekNext() == '-') {
    advance();
    advance();
    advance();
    while (current() != '\0') {
      if (current() == '-' && peek() == '-' && peekNext() == '-') {
        advance();
        advance();
        advance();
      }
      advance();
    }
  }
}

Token Lexer::readNumber() {
  char c = current();
  std::size_t sLine = line;
  std::size_t sColumn = column;
  std::string number = "";
  while (std::isdigit(c)) {
    number += c;
    c = advance();
  }
  if (c == '.') {
    number += '.';
    c = advance();
    while (std::isdigit(c)) {
      number += c;
      c = advance();
    }
    return Token{TokenType::literal_float, number, sLine, sColumn};
  }
  return Token{TokenType::literal_integer, number, sLine, sColumn};
}
