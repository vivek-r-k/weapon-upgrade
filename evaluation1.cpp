#include <iostream>
using namespace std;
class delivery_app          // Class creation
{
  private:                  // Access specifiers for inserting various objects
  string customer;
  int items;
  public:
  int price;
  bool availability;

  delivery_app()                   // input the necessary details
  {
      cout<<"Customer name? \n";
      cin>>customer;
      cout<<"Number of items? \n";
      cin>>items;
      cout<<"Price? \n";
      cin>>price;
      cout<<"Available? \n";
      cin>>availability;
  }
};
void delivery_app::display()
{
    cout<<"Name: "<<customer<<"\n"<<items<<" items"<<endl;
}
void delivery_app::display()
{
    cout<<"Rs "<<price<<endl;
      if(availability==true)
      {
          cout<<"Product is available \n";
      }
      else{
          cout<<"Product not available \n";
      }
}

//Creating another class "deliver" from the above class delivery_app" using inheritance
class deliver:public delivery_app
{
    private:
    string address;
    int distance;
    public:
    deliver()     //Constructor usage
    {
        cout<<"Enter the address? \n";
        cin>>address;
        cout<<"Enter the distance to reach the destination \n";
        cin>>distance;
    }
    // Calling the first class function for inheriting the its respective details
    void print()
    {
        display();
        cout<<address<<endl;
        cout<<distance<<" kilometers"<<endl;
    }
    ~deliver()    //Destructor usage
    {
        cout<<"Can't be delivered \n";
    }
    protected:
    int numlogins;
};
//Third class "rating"inherited from the "deliver"class
class rating:public deliver
{
    private:
    int customer_rating;
    bool satisfactory;
    public:
    void review(int l)
    {
        numlogins = l;
        cout<<"Enter the number of logins? \n";
        cin>>numlogins;
        cout<<"What is the customer rating? \n";
        cin>>customer_rating;
        cout<<"Was the experience satisfactory? \n";
        cin>>satisfactory;
    }
    void show()
    {
        print(); // Calling the "print" function from the above class
        cout<<numlogins<<" logins"<<"\n"<<customer_rating<<" rating"<<endl;
        if(satisfactory==true)
        cout<<"Yes very satisfied!!! \n";
        else
        cout<<"not satisfied!!! \n";
    }
    ~rating()
    {
        cout<<"No activity \n";
    }
};
int main()
{
    int r;
    deliver obj_1;//Assigning an object to deliver class, to access its values
    rating obj_2;//Assigning an object to rating class, to access its values
    obj_1.print();
    obj_2.review(r); //accessing the attributes from rating class
    obj_2.show();
    return 0;
}
