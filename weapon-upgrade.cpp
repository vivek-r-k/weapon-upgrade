#include <iostream>
using namespace std;

class Weapon{
  protected: 
    int damageValue,durability,range;
  public:
    virtual void Values() = 0;
    friend class upgrade;
    
    friend int friendFunction(Weapon& t);
    
    Weapon(int DamageValue, int Durability, int Range) {
        damageValue = DamageValue;
        durability = Durability;
        range = Range;
    }
    ~Weapon(){
        cout<<"NOTE: Upgrade the weapons to increase the stability\n";
    }
};

class Shotgun : public Weapon
{
    string name;
    public:
    Shotgun(string Name, int DamageValue, int Durability, int Range):Weapon(DamageValue,Durability,Range) {
        name = Name;
        try{
            if(!(range >=35 && range <=45))throw range;
        }
        catch(int range) {
            cout<<"Range of shot gun "<<name<<" must be between 35 and 45\n";
        }
    }
    void Values() { 
        cout << "Name of weapon = " << name << endl << "Damage = " <<damageValue <<'\n'<< "Durability = "<<durability<<endl<<"Range = "<<range<<endl;
    }
    ~Shotgun(){
        cout<<name<<" is used for short range\n";
    }
};

class LightMachineGun : public Weapon
{
    string name;
    public:
    LightMachineGun(string Name, int DamageValue, int Durability, int Range):Weapon(DamageValue,Durability,Range) {
        name = Name;
        try{
            if(!(range >=70 && range <=80))throw range;
        }
        catch(int range) {
             cout<<"Range of light machine gun "<<name<<" must be between 700 and 800\n";
        }
    }
    void Values() { 
        cout << "Name of weapon = " << name << endl << "Damage = " <<damageValue <<'\n'<< "Durability = "<<durability<<endl<<"Range = "<<range<<endl;
    }
    ~LightMachineGun(){
        cout<<name<<" has good firing rate\n";
    }
};

class Sniper : public Weapon
{
    string name;
    public:
    Sniper(string Name, int DamageValue, int Durability, int Range):Weapon(DamageValue,Durability,Range) {
        name = Name;
        try{
            if(!(range >=90 && range <=100))throw range;
        }
        catch(int range) {
             cout<<"Range of sniper "<<name<<" must be between 900 and 1200\n";
        }
    }
    void Values() { 
        cout << "Name of weapon = " << name << endl << "Damage = " <<damageValue <<'\n'<< "Durability = "<<durability<<endl<<"Range = "<<range<<endl;
    }
    ~Sniper(){
        cout<<name<<" is used for long range\n";
    }
};

int friendFunction(Weapon &t)
{
    cout<<endl;
    if(t.damageValue >= 99 || t.durability >= 80 || t.range >= 95)
        return 0;
    return 1;
}

class upgrade{
    public:
        void operate(Weapon *t){
            // cout<<"Damage (before) "<<t->damageValue;
            t->damageValue = t->damageValue+10;
            t->durability = t->durability+7;
            t->range = t->range+4;
            // cout<<"Damage (after) "<<t->damageValue;
        }
};

int main() {
    string n,ans;
    int dv,option,du,r,canUpgrade;
    while(1)
    {
        cout<<"Choose Weapon(1.Shotgun/2.LightMachineGun/3.Sniper)\n";
        cin>>option;
        Weapon *obj; //The scope of each object created inside the case statement is limited to that particular case.
            cout<<"Enter sub-weapon name, damage value, durability and range\n";
            cin>>n>>dv>>du>>r;
        switch(option){
            case 1:
                obj = new Shotgun(n,dv,du,r);
                break;
            case 2:
                obj = new LightMachineGun(n,dv,du,r);
                break;
            case 3:
                obj = new Sniper(n,dv,du,r);
                break;
            default: cout<<"Invalid\n";
                break;
        }
        if(option == 1 || option == 2 || option == 3){
            obj->Values();
            canUpgrade = friendFunction(*obj);
            // cout<<"canUpgrade = "<<canUpgrade<<endl;
            if(canUpgrade == 1){
                cout<<"Do you want to upgrade the stability?\n";
                cin>>ans;
                if(ans == "YES"){
                    upgrade fri;
                    fri.operate(obj);
                    obj->Values();   
                }
            }
            else{
                cout<<"Cannot upgrade the wepon\n";
            }
            delete obj;   
        }
        
    }

    return 0;
}
