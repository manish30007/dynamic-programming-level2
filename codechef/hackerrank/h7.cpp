#include <iostream>
#include <string>
using namespace std;
class Student{
    int age,standard;
    string first_name;
    string last_name;
    public:
    void set_age(int a){age=a;}
    void set_standard(int s){standard=s;}
    void set_first_name(string fn){first_name=fn;}
    void set_last_name(string ln){last_name=ln;}
    int get_age(){return age;}
    int get_standard(){return standard;}
    string get_first_name(){return first_name;}
   string get_last_name(){return last_name;}
   



void To_string(){
    string s1=to_string(age);
   string s2=to_string(standard);
   cout<<s1<<","<<first_name<<","<<last_name<<","<<s2;

    }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
  st.To_string();
    
    return 0;
}