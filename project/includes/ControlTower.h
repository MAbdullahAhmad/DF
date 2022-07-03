#ifndef CONTROL_TOWER_H
#define CONTROL_TOWER_H

#include "iostream"
#include "vector"
#include "MasterController.h"
using namespace std;

// Guest Controllers
#include "Controllers/WelcomeController.h"
#include "Controllers/HomepageController.h"
#include "Controllers/AboutController.h"
#include "Controllers/LoginController.h"
#include "Controllers/SignupController.h"

// User Controllers
#include "Controllers/MainFormController.h"
#include "Controllers/ChannelsController.h"
#include "Controllers/NewPostController.h"
#include "Controllers/ViewPostController.h"

// Admin Controllers
#include "Controllers/AdminPanelController.h"
#include "Controllers/AdminUsersController.h"
#include "Controllers/AdminCreateUserController.h"
#include "Controllers/AdminChannelsController.h"
#include "Controllers/AdminCreateChannelController.h"

// Logout Controller
#include "Controllers/LogoutController.h"

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
    bool active = true;

  public:
    //> Constructors
    ControlTower(){}
    ControlTower(
      vector<Route> routes
    ):
      routes(routes){}

    // Set Query
    void query(string q, bool active){
      this->qry = q;
      this->active = active;
    }
    void query(string q){
      this->query(q, true);
    }
    // Set Activity
    void activity(bool active){
      this->active = active;
    }
    // Is Active
    bool is_active(){
      return this->active;
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
        this->active &&
        q.length()!=0
      )

      // Run
      for(Route r : this->routes)
        if(r.match(q)){
          q = "";
          this->qry = r.fire();

          return true;
        }

      // 404
      this->active = false;
      return false;
    }
    bool look_around(){
      return this->look_around(this->qry);
    }
};

// Routing
ControlTower control_tower;

void init_routes(){
  // string start = "welcome";
  string start = "homepage";
  // string start = "main_form";
  control_tower.query(start);

  control_tower.add_route(new Route("welcome",               new WelcomeController()));
  control_tower.add_route(new Route("homepage",              new HomepageController()));
  control_tower.add_route(new Route("about",                 new AboutController()));
  control_tower.add_route(new Route("login",                 new LoginController()));
  control_tower.add_route(new Route("signup",                new SignupController()));
  control_tower.add_route(new Route("main_form",             new MainFormController()));
  control_tower.add_route(new Route("channels",              new ChannelsController()));
  control_tower.add_route(new Route("new_post",              new NewPostController()));
  control_tower.add_route(new Route("view_post",             new ViewPostController()));
  control_tower.add_route(new Route("admin_panel",           new AdminPanelController()));
  control_tower.add_route(new Route("admin_users",           new AdminUsersController()));
  control_tower.add_route(new Route("admin_create_user",     new AdminCreateUserController()));
  control_tower.add_route(new Route("admin_channels",        new AdminChannelsController()));
  control_tower.add_route(new Route("admin_create_channel",  new AdminCreateChannelController()));
  control_tower.add_route(new Route("logout",                new LogoutController()));

  while(control_tower.is_active()){
    control_tower.look_around();
  }
}

#endif