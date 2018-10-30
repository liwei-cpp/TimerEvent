#include <shared_timer.h>
#include <iostream>
#include <thread>

void fun()
{
    std::cout << "fun called\n";
}

void fun2()
{
    std::cout << "fun2 called\n";
}

int main(int argc, char **argv)
{
    using namespace std::chrono_literals;
    
    TimerEvent::SharedTimer timer1(fun);
    TimerEvent::SharedTimer timer2(fun2, true);
    
    timer2.Schedule(10ms);
    timer1.Schedule(1s);

    std::this_thread::sleep_for(15s);
    
	return 0;
}
