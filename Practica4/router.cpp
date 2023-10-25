#include <router.h>
#include <network.h>

netWork n;
void router::addLink(const string& id,int cost){
    links[id]=cost;
}

void router::removeLink(const string& id){
    links.erase(id);
}


string router::getName() const{
    return id;
}

int router::getCost(const string& id_destination){
    auto found = links.find(id_destination);
    if(found!=links.end()){
        return found->second;
    }else{
        return -1;
    }
    return 0;
}

void router::updateRTable(map<string,map<string,int>> netWork){
    map<string,int> distance;
    map<string,string> previous;

    for(const auto& data : netWork){
        const string& routerName = data.first;
        distance[routerName]=INT_MAX;
        previous[routerName]="";
    }
    distance[getName()]=0;


    for(const auto& data:netWork){
        const string& routerName = data.first;
        const map<string,int>& links = data.second;
        for(const auto& neighbor : links){
            const string& neighborName = neighbor.first;
            int costNeighbor = neighbor.second;

            int alt=distance[routerName]+costNeighbor;
            if(alt<distance[neighborName]){
                distance[neighborName]=alt;
                previous[neighborName]=routerName;
            }else if(alt==distance[routerName]){
                previous[neighborName]=routerName;
            }
        }
    }

    routingTable.clear();
    for(const auto& data:previous){
        const string& destination = data.first;
        string nextHop = data.second;
        routingTable[destination]=nextHop;
    }
}

map<string,int> router::getLinks() const{
    return links;
}

map<string,string> router::getTable() const{
    return routingTable;
}
