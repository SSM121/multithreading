#include "../include/Head.hpp"
#include "../include/derivedHead.hpp"
Head::Head()
{
}



std::vector<std::shared_ptr<Head>> Head::makePlatter(int numHeads)
{
std::vector<std::shared_ptr<Head>> l_platter;
for(int i = 0; i < numHeads; i++)
{
  std::shared_ptr<Head> l_Head(new derivedHead(i));
  l_platter.push_back(l_Head);
  derivedHead::Active.push_back(false);
}
//derivedHead::m_platter = l_platter;
derivedHead::m_total = numHeads;
return l_platter;
}

