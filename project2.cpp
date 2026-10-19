// Project 2 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// student
class Student
{
public:
    // Default constructor
    Student()
    {
        firstName      = "Unknown";
        lastName       = "Unknown";
        gpa            = 0.0;
        gradYear       = 0;
        gradSemester   = "Spring";
        enrollYear     = 0;
        enrollSemester = "Fall";
        level          = "Undergrad";
    }

    // Destructor (nothing was allocated inside the class, so it is empty)
    ~Student() {}

    // Setters
    void setName(string first, string last) { firstName = first; lastName = last; }
    void setGPA(double g)                   { gpa = g; }
    void setGradYear(int y)                 { gradYear = y; }
    void setGradSemester(string s)          { gradSemester = s; }
    void setEnrollYear(int y)               { enrollYear = y; }
    void setEnrollSemester(string s)        { enrollSemester = s; }
    void setLevel(string l)                 { level = l; }

    // Getters
    string getFirstName()      { return firstName; }
    string getLastName()       { return lastName; }
    double getGPA()            { return gpa; }
    int    getGradYear()       { return gradYear; }
    string getGradSemester()   { return gradSemester; }
    int    getEnrollYear()     { return enrollYear; }
    string getEnrollSemester() { return enrollSemester; }
    string getLevel()          { return level; }

    // Write the common information to the file
    void write(ofstream &out)
    {
        out << "Name: "       << firstName << " " << lastName << endl;
        out << "GPA: "        << gpa << endl;
        out << "Enrolled: "   << enrollSemester << " " << enrollYear << endl;
        out << "Graduation: " << gradSemester << " " << gradYear << endl;
        out << "Level: "      << level << endl;
    }

private:
    string firstName;
    string lastName;
    double gpa;
    int    gradYear;
    string gradSemester;
    int    enrollYear;
    string enrollSemester;
    string level;        // "Undergrad" or "Grad"
};

// Art students
class Art_Student : public Student
{
public:
    Art_Student()
    {
        art_emphasis = "Art Studio";
    }
    ~Art_Student() {}

    // Only accepts the three allowed values
    void setArtEmphasis(string e)
    {
        if (e == "Art Studio" || e == "Art History" || e == "Art Education")
            art_emphasis = e;
        else
            cout << "Invalid art emphasis: " << e << endl;
    }
    string getArtEmphasis() { return art_emphasis; }

    void write(ofstream &out)
    {
        Student::write(out);                       // common info first
        out << "Art Emphasis: " << art_emphasis << endl;
    }

private:
    string art_emphasis;
};

// Physic Students
class Physics_Student : public Student
{
public:
    Physics_Student()
    {
        concentration = "Biophysics";
    }
    ~Physics_Student() {}

    // Only accepts the two allowed values
    void setConcentration(string c)
    {
        if (c == "Biophysics" || c == "Earth and Planetary Sciences")
            concentration = c;
        else
            cout << "Invalid concentration: " << c << endl;
    }
    string getConcentration() { return concentration; }

    void write(ofstream &out)
    {
        Student::write(out);
        out << "Concentration: " << concentration << endl;
    }

private:
    string concentration;
};

// main
int main()
{
    vector<Art_Student *>     art_students;
    vector<Physics_Student *> physics_students;

    // Allocate 5 of each with new
    for (int i = 0; i < 5; i++)
    {
        art_students.push_back(new Art_Student);
        physics_students.push_back(new Physics_Student);
    }

    // ----- Art students -----
    art_students[0]->setName("Maria", "Lopez");
    art_students[0]->setGPA(3.9);
    art_students[0]->setEnrollYear(2023);
    art_students[0]->setEnrollSemester("Fall");
    art_students[0]->setGradYear(2027);
    art_students[0]->setGradSemester("Spring");
    art_students[0]->setLevel("Undergrad");
    art_students[0]->setArtEmphasis("Art Studio");

    art_students[1]->setName("James", "Chen");
    art_students[1]->setGPA(3.4);
    art_students[1]->setEnrollYear(2022);
    art_students[1]->setEnrollSemester("Spring");
    art_students[1]->setGradYear(2026);
    art_students[1]->setGradSemester("Fall");
    art_students[1]->setLevel("Undergrad");
    art_students[1]->setArtEmphasis("Art History");

    art_students[2]->setName("Aisha", "Patel");
    art_students[2]->setGPA(3.7);
    art_students[2]->setEnrollYear(2025);
    art_students[2]->setEnrollSemester("Fall");
    art_students[2]->setGradYear(2027);
    art_students[2]->setGradSemester("Spring");
    art_students[2]->setLevel("Grad");
    art_students[2]->setArtEmphasis("Art Education");

    art_students[3]->setName("Tyler", "Brooks");
    art_students[3]->setGPA(3.1);
    art_students[3]->setEnrollYear(2024);
    art_students[3]->setEnrollSemester("Spring");
    art_students[3]->setGradYear(2028);
    art_students[3]->setGradSemester("Spring");
    art_students[3]->setLevel("Undergrad");
    art_students[3]->setArtEmphasis("Art Studio");

    art_students[4]->setName("Sofia", "Romero");
    art_students[4]->setGPA(3.95);
    art_students[4]->setEnrollYear(2024);
    art_students[4]->setEnrollSemester("Fall");
    art_students[4]->setGradYear(2026);
    art_students[4]->setGradSemester("Summer");
    art_students[4]->setLevel("Grad");
    art_students[4]->setArtEmphasis("Art History");

    // ----- Physics students -----
    physics_students[0]->setName("Daniel", "Kim");
    physics_students[0]->setGPA(3.8);
    physics_students[0]->setEnrollYear(2023);
    physics_students[0]->setEnrollSemester("Fall");
    physics_students[0]->setGradYear(2027);
    physics_students[0]->setGradSemester("Spring");
    physics_students[0]->setLevel("Undergrad");
    physics_students[0]->setConcentration("Biophysics");

    physics_students[1]->setName("Emily", "Nguyen");
    physics_students[1]->setGPA(3.6);
    physics_students[1]->setEnrollYear(2022);
    physics_students[1]->setEnrollSemester("Fall");
    physics_students[1]->setGradYear(2026);
    physics_students[1]->setGradSemester("Fall");
    physics_students[1]->setLevel("Undergrad");
    physics_students[1]->setConcentration("Earth and Planetary Sciences");

    physics_students[2]->setName("Omar", "Hassan");
    physics_students[2]->setGPA(3.2);
    physics_students[2]->setEnrollYear(2025);
    physics_students[2]->setEnrollSemester("Spring");
    physics_students[2]->setGradYear(2029);
    physics_students[2]->setGradSemester("Spring");
    physics_students[2]->setLevel("Grad");
    physics_students[2]->setConcentration("Biophysics");

    physics_students[3]->setName("Rachel", "Goldberg");
    physics_students[3]->setGPA(3.9);
    physics_students[3]->setEnrollYear(2021);
    physics_students[3]->setEnrollSemester("Fall");
    physics_students[3]->setGradYear(2026);
    physics_students[3]->setGradSemester("Spring");
    physics_students[3]->setLevel("Grad");
    physics_students[3]->setConcentration("Earth and Planetary Sciences");

    physics_students[4]->setName("Carlos", "Mendez");
    physics_students[4]->setGPA(2.9);
    physics_students[4]->setEnrollYear(2024);
    physics_students[4]->setEnrollSemester("Fall");
    physics_students[4]->setGradYear(2028);
    physics_students[4]->setGradSemester("Spring");
    physics_students[4]->setLevel("Undergrad");
    physics_students[4]->setConcentration("Biophysics");

    //  everything to one file 
    ofstream outfile("student_info.dat");

    outfile << "===== Art Students =====" << endl << endl;
    for (int i = 0; i < art_students.size(); i++)
    {
        art_students[i]->write(outfile);
        outfile << endl;
    }

    outfile << "===== Physics Students =====" << endl << endl;
    for (int i = 0; i < physics_students.size(); i++)
    {
        physics_students[i]->write(outfile);
        outfile << endl;
    }

    outfile.close();
    cout << "Wrote student_info.dat" << endl;

    // ----- Free the memory -----
    for (int i = 0; i < art_students.size(); i++)
        delete art_students[i];

    for (int i = 0; i < physics_students.size(); i++)
        delete physics_students[i];

    return 0;
}