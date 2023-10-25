#ifndef ROUTER_H
#define ROUTER_H

#include <string>
#include <map>
#include <list>
#include <vector>
using namespace std;

class router
{
public:

    router(const string& id) : id(id) {};

    void addLink(const string& id, int cost);
    void removeLink(const string& id);
    void updateRTable(map<string,map<string,int>> netWorkTopology);
    string getName() const;
    int getCost(const string& id_destination);
    map<string,int> getLinks() const;
    map<string,string> getTable() const;

private:
    string id;
    map<string,int> links;        //Enlaces del router con otros
    map<string,string> routingTable; //Guardar los costos segun los caminos más cortos para los destinos.
};

#endif // ROUTER_H
