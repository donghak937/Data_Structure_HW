struct Cafe
{

    Menu* menu_list;
};

struct Menu
{
    /* data */
};

void func1(string* f){
    cout << *f;
}

void func2(string& f){
    cout << f;
}

void addCafe(Cafe &r1);
void addMenu(Menu &m1);
void displayMenus(Cafe &r1);


int main(){
    Cafe* my_cafe = new Cafe;

    addCafe(*my_cafe);
    displayMenus(*my_cafe);

    delete[] my_cafe->menu_list;
    delete my_cafe;
}

void addCafe(Cafe &r1)
    getline(Cin, r1.name);

    r1.menu_list = new Menu[r1.menu_size];