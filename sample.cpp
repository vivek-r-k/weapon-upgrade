#include <iostream>
#include<cstring>
using namespace std;

// class STUDENT{
//     private:
//         int marks;
//         string USN;
//     public:
//         // Constructor
//         STUDENT(string OUSN){
//             strcpy(USN,OUSN);
//             cout<<"Student "<<USN<<" is created"<<endl;
//         }
//         // Distructor
//         ~STUDENT(){
//             cout<<"Student "<<USN<<" is deleted"<<endl;
//         }

//         void readMarks(){
//             cout<<"Enter the marks of "<<USN<<endl;
//             cin>>marks;
//         }
//         void showMarks(){
//             cout<<"Marks of "<<USN<<" is "<<marks<<endl;
//         }
// };

int main() {
    char st[5][2];
    string usn;
    cout<<"Enter usn for each 10 student and enter the marks\n";
    for(int i=0;i<5;i++){
        for(int j=0;j<2;j++)
        {
            cin>>usn;
        }
        cout<<st[i];
        // STUDENT STU(i);
    }

    // for(int j=0;j<1;j++){
    //     for(int i=0;i<12;i++){
    //         cin>>usn[i];
    //     }
    //     // strcpy(st[j],usn);
    //     cout<<usn<<endl;
    //     st[j] = usn;
    //     cout<<st[j];
    // }

    // cout<<st[1];

    // st.readMarks();
    // st.showMarks();
    return 0;
}
