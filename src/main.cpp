#include "../include/Head.hpp"

#include <mutex>
#include <unistd.h>
#include <iostream>
#include <thread>

#define HEADS 4

int main()
{
std::mutex mtx;

auto action = [&mtx](){
sleep(1);
std::unique_lock<std::mutex> lock(mtx);
std::cout << "here" << std:: endl;

};

std::vector<std::shared_ptr<std::thread>> threads;
std::vector<std::shared_ptr<Head>> heads = Head::makePlatter(HEADS);

for(int i = 0; i < HEADS; ++i)
{
  threads.push_back(std::make_shared<std::thread>([i, &heads, action](){
      heads[i]->execute(action);
}));
}
for (int i = 0; i < HEADS; ++i)
{
  threads[i]->join();
}
}
