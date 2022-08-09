#include <iostream>
using namespace std;

// class Patient
class Patient
{
private:
    string Name;
    bool Status;
    int NumberOfDays;

public:
    // setters
    void setName(string);
    void setStatus(bool);
    void setNumberOfDays(int);

    // getters
    string getName();
    bool getStatus();
    int getNumberOfDays();

    // default constructor
    Patient();
};
// outline Functions of Patient
// setters
void Patient ::setName(string name)
{
    Name = name;
}
void Patient ::setStatus(bool st)
{
    Status = st;
}
void Patient ::setNumberOfDays(int nodays)
{
    NumberOfDays = nodays;
}
// default constructor
Patient ::Patient()
{
}

// Class Hospital
class Hospital
{
private:
    Patient *patient; // Composition
    int MeditationCharges;
    double DailyRate;
    int HospitalCharges;
    int HospitalService;
    int TotalCharges;

public:
    // default constructor
    Hospital();

    // functions
    void InPatient();
    void OutPatient();

    // destructor
    ~Hospital();
};
// Outline Functions of Hospital
Hospital ::Hospital()
{
    // Allocating Dynamic Memory in Heap for Patient
    patient = new Patient;

    cout << "Enter Name of Patient: ";
    string name;
    cin >> name;
    patient->setName(name);

    cout << "\nPress: " << endl;
    cout << "1: For In-Patient" << endl;
    cout << "2: For Out-Patient" << endl;
    cout << "Enter: ";
    int chk;
    cin >> chk;

    while (true)
    {
        // In-Patient
        if (chk == 1)
        {
            patient->setStatus(true);
            InPatient();
            break;
        }
        // Out-Patient
        else if (chk == 2)
        {
            patient->setStatus(false);
            OutPatient();
            break;
        }
        // Invalid
        else
        {
            cout << "Invalid Input. Try Again!" << endl;
        }
    }
}
// functions
void Hospital ::InPatient()
{
    cout << "\nKindly Enter the Details for In-Patient: \n"
         << endl;
    cout << "Number of Days Spent: ";
    int nodays;
    cin >> nodays;
    patient->setNumberOfDays(nodays);

    cout << "Daily Rate: ";
    int dailyrate;
    cin >> dailyrate;
    DailyRate = dailyrate;

    cout << "Medication Charges: ";
    int meditationcharges;
    cin >> meditationcharges;
    MeditationCharges = meditationcharges;

    cout << "Hospital Charges: ";
    int hospitalcharges;
    cin >> hospitalcharges;
    HospitalCharges = hospitalcharges;
    
    cout << "Hospital Service: ";
    int hospitalservice;
    cin >> hospitalservice;
    HospitalService = hospitalservice;

    TotalCharges = DailyRate * HospitalCharges + MeditationCharges + HospitalService;
    cout << "\nTotal Charges: " << TotalCharges << "\n" << endl;
}

void Hospital ::OutPatient()
{
    cout << "\nKindly Enter the Details for Out-Patient: \n"
         << endl;

    cout << "Hospital Service: ";
    int hospitalservice;
    cin >> hospitalservice;
    HospitalService = hospitalservice;
   
    cout << "Medication Charges: ";
    int meditationcharges;
    cin >> meditationcharges;
    MeditationCharges = meditationcharges;

    TotalCharges = MeditationCharges + HospitalService;
    cout << "\nTotal Charges: " << TotalCharges << "\n" << endl;

}
// destructor
Hospital ::~Hospital()
{
    // DeAllocating dynamic Memory from heap for Patient Object
    delete patient;
}
int main()
{
    Hospital h1;

    return 0;
}