#include "expr.hh"

#include <string>
#include <sstream>

std::string
IntExpr::toString() const
{
  std::stringstream s;
  s << value;
  return s.str();
}

static std::string
binaryExprToString(std::string op, ExprPtr left, ExprPtr right)
{
  std::stringstream s;
  s << "(" << *left << ") " << op << " (" << *right << ")";
  return s.str();
}

std::string
AddExpr::toString() const
{
  return binaryExprToString("+", left, right);
}

std::string
SubExpr::toString() const
{
  return binaryExprToString("-", left, right);
}

std::string
MulExpr::toString() const
{
  return binaryExprToString("*", left, right);
}

std::string
DivExpr::toString() const
{
  return binaryExprToString("/", left, right);
}
std::string
IntExpr::dcCode() const{
  std::stringstream s;
  s << this->value << " ";
  return s.str();
}

std::string
DivExpr::dcCode() const{
  std::stringstream s;
  s << this->left->dcCode() << this->right->dcCode() << "/ ";
  return s.str();
}

std::string
MulExpr::dcCode() const{
  std::stringstream s;
  s << this->left->dcCode() << this->right->dcCode() << "* ";
  return s.str();
}

std::string
AddExpr::dcCode() const{
  std::stringstream s;
  s << this->left->dcCode() << this->right->dcCode() << "+ ";
  return s.str();
}

std::string
SubExpr::dcCode() const{
  std::stringstream s;
  s << this->left->dcCode() << this->right->dcCode() << "- ";
  return s.str();
}

