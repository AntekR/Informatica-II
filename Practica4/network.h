#ifndef NETWORK_H
#define NETWORK_H

#include <router.h>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;

class netWork
{
public:

    void addRouter(const string& id);
    void removeRouter(const string& id);
    void updateTopology(const string& router1, const string& router2, int cost);
    void loadTopology(const string& fileName);
    string getShortWay(const string& origin, const string& destination);
    map<string,map<string,int>> buildTopology() const;


    map<string,router> routers;
};


#endif // NETWORK_H
