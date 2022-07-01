#ifndef CONTROL_TOWER_H
#define CONTROL_TOWER_H

#include "iostream"
#include "vector"
#include "MasterController.h"

#include "Controllers/WelcomeController.h"


struct Route{
  // Props
  string route_name;
  MasterController* controller;

  //> Constructors
  Route(){}
  Route(
    string rn,
    MasterController* ct
  ){
    route_name = rn;
    controller = ct;
  }

  // Match Route
  bool match(string route){
    return route == route_name;
  }

  // Fire Controller
  string fire(){
    return controller->fire();
  }
};

class ControlTower{
  private:
    // Props
    vector<Route> routes;
    string qry = "";
    bool fired = false;

  public:
    //> Constructors
    ControlTower(){}
    ControlTower(
      vector<Route> routes
    ):
      routes(routes){}

    // Set Query
    void query(string q){
      this->qry = q;
      this->fired = false;
    }

    // Add Route
    void add_route(Route r){
      routes.push_back(r);
    }
    void add_route(Route *r){
      routes.push_back(*r);
    }
    void add_route(string route_name, MasterController* controller){
      Route r(route_name, controller);
      routes.push_back(r);
    }

    // Size : Number of Routes
    int size(){
      return this->routes.size();
    }

    // Exists : Route Exists or Not
    bool exists(string route_name){
      for(Route r : this->routes)
        if(r.match(route_name))
          return true;
      return false;
    }

    // Look Around : Match and Run Specific Route
    bool look_around(string &q){
      // Do not Run Case
      if (
        this->fired ||
        q.length()==0
      ) return false;
        
      // Run
      for(Route r : this->routes)
        if(r.match(q)){
          this->fired = true;
          q = "";
          this->qry = r.fire();
          return true;
        }

      // 404
      return false;
    }
    bool look_around(){
      return this->look_around(this->qry);
    }
};

// Routing
ControlTower control_tower;

void init_routes(){
  control_tower.add_route(new Route("welcome",      new WelcomeController()));
}

using namespace std;

#endif