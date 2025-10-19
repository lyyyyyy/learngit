#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#include <windows.h>
class Student{
    private:
    const string Name;
    int ID;
    double Grade;
    static int IDcount;
    public:
    Student(const string name,int id,double grade):Name(name),ID(id),Grade(grade){ IDcount++;}
    static void showcount(){cout<<"班级总人数"<<IDcount<<endl;
    }
};
int Student::IDcount=0;
int main() {
    SetConsoleOutputCP(65001);  // 输出编码（关键）
    SetConsoleCP(65001);        // 输入编码（可选，如需读取中文输入）
    bool ifcomplete=false;
   
    vector<Student> student; 
    do{
    
    bool Inputvalid=false;
    string name;int id;double grade;
    //处理错误输入
    while(!Inputvalid){
    cout<<"输入学生姓名、编号、成绩"<<endl;
    cin>>name>>id>>grade;
    if(cin.fail()){
        cin.clear();//清除
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"请重新输入"<<endl;
                  }
    else{Inputvalid=true;}
                }
    student.emplace_back(name,id,grade);
    cout<<"确认是否完成输入"<<endl;
    cin>>ifcomplete;
    }while(!ifcomplete);
    Student::showcount();

  
  

    return 0;
}


