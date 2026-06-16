#include <cmath>
#include <ios>
#include <iostream>
#include <memory>
#include <ostream>
#include <vector>
#include <limits>
#include <string>
#include <cstdlib>
//#include <complex>

enum class FunctionType
{
  Linear = 1,
  Quadratic = 2,
  Cubic = 3,
  AbsoluteValue = 4,
  SquareRoot = 5,
  InverseProportion = 6,
  Exponential = 7,
  About = 8,
  Exit = 9
};

class MathFunction
{
  protected:
  std::vector<double> m_coeffs;
  const double EPS = 1e-9;

  public:
  MathFunction(std::vector<double> coeffs) : m_coeffs(std::move(coeffs)) {}

  virtual ~MathFunction() {}

  virtual std::vector<double> Solve() = 0;
  virtual std::vector<double> Derivative() = 0;
  virtual std::vector<double> Integrate() = 0;
  virtual std::vector<double> Analysis() = 0;

};

class LinearFunction : public MathFunction
{
  public:
  LinearFunction(std::vector<double> coeffs) : MathFunction(std::move(coeffs)) {}

  std::vector<double> Solve() override
  {
    double a = m_coeffs[0];
    double b = m_coeffs[1];
    if (std::abs(a) < EPS)
    {
      return {};
    }
    return {-b / a};
  }

  std::vector<double> Derivative() override
  { // тут сделаю логику производной

    return {}; //заглушка
  }

  std::vector<double> Integrate() override
  { // тут сделаю логику интеграла и геометрической площадь

    return {}; //заглушка
  }

  std::vector<double> Analysis() override
  { // тут сделаю логику анализа функции

    return {}; //заглушка
  }

};

class QuadraticFunction : public MathFunction
{
  public:
  QuadraticFunction(std::vector<double> coeffs) : MathFunction(std::move(coeffs)) {}

  std::vector<double> Solve() override
  {
    double a = m_coeffs[0];
    double b = m_coeffs[1];
    double c = m_coeffs[2];
    if (std::abs(a) < EPS)
    {
      return {};
    }
    double D = b * b - 4 * a * c;
    if (std::abs(D) < EPS)
    {
      return {-b / (2 * a)};
    }
    else if (D > 0)
    {
      double x1 = (-b + std::sqrt(D)) / (2 * a);
      double x2 = (-b - std::sqrt(D)) / (2 * a);
      return {x1, x2};
    }
    else
    {
      return {}; // пока что без комплексных чисел
    }
    return {};
  }

  std::vector<double> Derivative() override
  { // тут сделаю логику производной

    return {}; //заглушка
  }

  std::vector<double> Integrate() override
  { // тут сделаю логику интеграла и геометрической площади

    return {}; //заглушка
  }

  std::vector<double> Analysis() override
  { // тут сделаю логику анализа функции

    return {}; //заглушка
  }

};

class FunctionFactory
{
  public:
  
  static std::unique_ptr<MathFunction> CreateFunction(FunctionType type, const std::vector<double> &coefficients)
  {
    switch (type)
    {
    case FunctionType::Linear:
    {
      if (coefficients.size() < 2)
      {
        return nullptr;
      }
      return std::make_unique<LinearFunction>(coefficients);
    }
    case FunctionType::Quadratic:
    {
      if (coefficients.size() < 3)
      {
        return nullptr;
      }
      return std::make_unique<QuadraticFunction>(coefficients);
    }
    case FunctionType::Cubic:
    case FunctionType::AbsoluteValue:
    case FunctionType::SquareRoot:
    case FunctionType::InverseProportion:
    case FunctionType::Exponential:
    default:
      return nullptr;
    }
  }
};

class App
{
  private:
  
  void clearScreen() {
    #if defined (_WIN32) || defined (_WIN64)
    std::system("cls");
    #else
    std::system("clear");
    #endif
  }

  void drawMenu()
  {
    std::cout << "╔═════════════════════════════╗\n";
    std::cout << "║       SolveFunction         ║\n";
    std::cout << "╚═════════════════════════════╝\n";
    std::cout << "Выберите вид функций\n";
    std::cout << "1.Линейная\n";                     //kx+b 2 переменные
    std::cout << "2.Квадратичная\n";                 //ax^2+bx+c 3 переменных
    std::cout << "3.Кубическая\n";                   //ax^3+bx^2+cx+d 4 переменных
    std::cout << "4.Модуль\n";                       //|x| 1 переменная
    std::cout << "5.Корень\n";                       // √x 1 переменная
    std::cout << "6.Обратная пропорциональность\n";  // k/x 2 переменных
    std::cout << "7.Показательная функция\n";        // a^x 2 переменные
    std::cout << "8.About\n";
    std::cout << "9.Выход\n\n";
  }

  void showAbout()
  {
    clearScreen();
    std::cout << "╔═════════════════════════════╗\n";
    std::cout << "║       SolveFunction         ║\n";
    std::cout << "╚═════════════════════════════╝\n\n";
    std::cout << "Author: Nainkoo, 13 y.o\n";
<<<<<<< HEAD
    std::cout << "How project: OOP, Template,  Lambda expression, Factory\n";
    std::cout << "Version: 1.0\n";
=======
    std::cout << "How project: OOP, Template,  Lambda expression, Factory";
    std::cout << "Version: 0.1\n";
>>>>>>> 68c2f9a (fix: minor bug fixes)
    std::cout << "License: MIT\n";
    std::cout << "";
    std::cin.get();
  }

  FunctionType selectFunction()
  {
    drawMenu();
    int choiceOptions = inputAndCheck<int>("Выберете пункт меню: ", "Ошибка! Неверный пункт меню", [](int x) { return x >= 1 && x <= 9; });
    FunctionType choice = static_cast<FunctionType>(choiceOptions);
    return choice;
  }

  template<typename T, typename  Predicate> 
  T inputAndCheck(const std::string& message, const std::string& rangeErrorMessage, Predicate isValid)
  {
    T num;
    while (true)
    {
      std::cout << message;
      if (!(std::cin >> num)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка! Введите число\n" << std::endl;
        continue;
      }
      if (!isValid(num)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << rangeErrorMessage << "\n" << std::endl;
        continue;
      }
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return num;
    }
      }
    
  int getCoeffsCount(FunctionType choice)
  {
    switch (choice)
    {
    case FunctionType::SquareRoot:
    case FunctionType::AbsoluteValue:
      return 1;
    case FunctionType::Linear:
    case FunctionType::Exponential:
    case FunctionType::InverseProportion:
      return 2;
    case FunctionType::Quadratic:
      return 3;
    case FunctionType::Cubic:
      return 4;
    default:
      return 0;
    }
    return 0;
  }
  std::vector<double> collectCoefficients(int count)
  {
    std::vector<double> coefficients;
    for (int i = 0; i < count; i++)
    {
      double item = inputAndCheck<double>("Введите коэффицент: ", "Ошибка! Число должно быть меньше 1е9",[](double val) { return std::abs(val) < 1e9; });
      coefficients.push_back(item);  }
    return coefficients;
  }

  void printResults(const std::vector<double> &roots)
  {
    if (roots.empty())
    {
      std::cout << "Решений нет";
      return;
    }
    else
    {
      for (double root : roots)
      {
        std::cout << "Корень: " << root << "\n";
      }
    }
  }

  public:
  
  void Run()
  {
    FunctionType type = selectFunction();
    if (type == FunctionType::Exit) {
      std::cout << "Нажмите Enter для выхода: " << std::endl;
      std::cin.get();
      return;
    }
    if (type == FunctionType::About)
    {
      showAbout();
      return;
    }
    int count = getCoeffsCount(type);
    std::vector<double> coefficients = collectCoefficients(count);
    std::unique_ptr<MathFunction> func = FunctionFactory::CreateFunction(type, coefficients);
    if (func != nullptr)
    {
      std::vector<double> roots = func->Solve();
      printResults(roots);
    }
    else
    {
      std::cout << "Soon\n";
    }
  }
};

int main()
{
  App app;
  app.Run();
  return 0;
}