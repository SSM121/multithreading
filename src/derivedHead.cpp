#include "../include/derivedHead.hpp"


derivedHead::derivedHead(int ID)
: Head(), m_ID(ID)
{

}

void derivedHead::execute(std::function<void()> action)
{
  std::unique_lock<std::mutex> lck(derivedHead::m_lck_serve);
  m_cv_serve.wait(lck);
  check();
  action();
  derivedHead::Active[m_ID] = 0;
  
}

void derivedHead::check()
{
  std::unique_lock<std::mutex> lck(m_lck_serve);
  while(true)
  {
    if(derivedHead::Active[(m_ID - 1) % m_total] = 0)
    {
      if(derivedHead::Active[(m_ID + 1) % m_total] = 0)
      {
        break;
      }
    }
  }
  derivedHead::Active[m_ID] = 1;
}


   std::condition_variable derivedHead::m_cv_serve;
   std::mutex derivedHead::m_lck_serve;
   int derivedHead::m_total;
   std::vector<bool> derivedHead::Active;
