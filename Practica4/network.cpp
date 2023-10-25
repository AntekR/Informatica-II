#include "network.h"


void netWork::addRouter(const string& id){
    routers.insert(make_pair(id,router(id)));
}

void netWork::removeRouter(const string& routerName){
    routers.erase(routerName);
}

//map<string,router> netWork::getRouters(){
//    return routers;
//}

map<string,map<string,int>> netWork::buildTopology() const{
    map<string,map<string, int>> topology;

    for (const auto& data : routers) {
        const string& routerName = data.first;
        const router& router = data.second;
        const map<string, int>& neighbors = router.getLinks();

        topology[routerName] = neighbors;
    }

    return topology;
}

void netWork::updateTopology(const string& router1, const string& router2, int cost){
    if(routers.find(router1)==routers.end() || routers.find(router2)==routers.end()){
        cout<<"Uno o ambos routers no existen en la red"<<endl;
    }

    routers.at(router1).addLink(router2, cost);
    routers.at(router2).addLink(router1, cost);

    for(auto& data : routers){
        data.second.updateRTable(buildTopology());
    }
}

string netWork::getShortWay(const string& origin, const string& destination){
    string way = "";
    string currentRouter = destination;

    if(routers.at(origin).getTable().find(destination)==routers.at(origin).getTable().end()){
        return "Ruta no encontrada";
    }

    while(currentRouter != origin){

        if(currentRouter != destination) way =  currentRouter + " -> " + way;

        currentRouter = routers.at(origin).getTable()[currentRouter];
    }

    way = origin +" -> " + way + destination;

    return way;
}

void netWork::loadTopology(const string& fileName){
    ifstream topology(fileName);
    if(!topology.is_open()){
        cerr << "\tNo se pudo abrir el archivo: " << fileName << endl;
    }

    string line;
    while(getline(topology,line)){
        istringstream lineStream(line);
        string source, destination;
        int cost;

        if(lineStream >> source >> destination >> cost){
            // Se valida si los routers estan en la red
            if(routers.find(source) != routers.end() && routers.find(destination) != routers.end()){
                routers.at(source).addLink(destination,cost);
                routers.at(destination).addLink(source,cost);
                updateTopology(source,destination,cost);
            }else{
                cerr << "\tUno o ambos enrutadores no existen" << endl;
            }
        }else{
            cerr << "\tFormato incorrecto en la linea" << endl;
        }
    }
    topology.close();
}

