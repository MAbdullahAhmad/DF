void init(){
  this->active = true;
  this->functional = false;
  this->label = "";
  this->menu_name = "";
}
void init(
  string label,
  string menu_name
){
  this->active = true;
  this->functional = false;
  this->label = label;
  this->menu_name = menu_name;
  this->action = action;
}
void init(
  string label,
  string menu_name,
  function<void()> action
){
  this->active = true;
  this->functional = true;
  this->label = label;
  this->menu_name = menu_name;
  this->action = action;
}
void init(
  bool active,
  string label,
  string menu_name
){
  this->active = active;
  this->functional = true;
  this->label = label;
  this->menu_name = menu_name;
}
void init(
  bool active,
  string label,
  string menu_name,
  function<void()> action
){
  this->active = active;
  this->functional = true;
  this->label = label;
  this->menu_name = menu_name;
  this->action = action;
}
void init(
  string label,
  string menu_name,
  function<void()> action,
  bool functional
){
  this->active = true;
  this->functional = functional;
  this->label = label;
  this->menu_name = menu_name;
  this->action = action;
}
void init(
  bool active,
  string label,
  string menu_name,
  function<void()> action,
  bool functional
){
  this->active = active;
  this->functional = functional;
  this->label = label;
  this->menu_name = menu_name;
  this->action = action;
}