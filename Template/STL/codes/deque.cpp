#include <iostream>
#include <deque>
 
int main()
{
    std::deque<int> d = { 7, 5, 16, 8 };
 
    d.push_front(13);
    d.pop_back();
    d.push_back(25);
    d.pop_front();
 	
    for(int n : d) {
        std::cout << n << '\n';
    }
}