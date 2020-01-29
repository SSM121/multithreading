#ifndef DERIVEDHEAD_HPP
#define DERIVEDHEAD_HPP
#include <condition_variable>
#include <mutex>
#include "Head.hpp"

class derivedHead : public Head
{
public:
  derivedHead(int ID);
  static std::condition_variable m_cv_serve;
  static std::mutex m_lck_serve;
//  static std::vector<std::shared_ptr<head>> m_platter;
  void execute(std::function<void()> action);
  static int m_total;
  static std::vector<bool> Active;
private:
  void check();
  int m_ID;
};

#endif
