#include <iostream>
#include <set>
struct FatKey   { int x; int data[1000]; };
struct LightKey { int x; };
bool operator<(const FatKey& fk, const LightKey& lk) { return fk.x < lk.x; }
bool operator<(const LightKey& lk, const FatKey& fk) { return lk.x < fk.x; }
bool operator<(const FatKey& fk1, const FatKey& fk2) { return fk1.x < fk2.x; }
int main()
{  
// simple comparison demo
    std::set<int> example = {1, 2, 3, 4};
 
    auto search = example.find(2);
    if (search != example.end()) {
        std::cout << "Found " << (*search) << '\n';
    } else {
        std::cout << "Not found\n";
    }
 
// transparent comparison demo
    std::set<FatKey, std::less<>> example2 = { {1, {} }, {2, {} }, {3, {} }, {4, {} } };
 
    LightKey lk = {2};
    auto search2 = example2.find(lk);
    if (search2 != example2.end()) {
        std::cout << "Found " << search2->x << '\n';
    } else {
        std::cout << "Not found\n";
    }
}