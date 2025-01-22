#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


//vectors to store the patient information
vector<int> patientID;
vector<string> patientName;
vector<int> patientAge;
vector<string> patientGender;
vector<string> patientDiagnosis;
vector<string> patientContact;
int curt = 0;  //'curt' keeps track of the number of patients in the system




// this function helps to add a new patient record
void addPatient() {
    int id, age;
    string name, gender, diagnosis, contact;

    // collects patient info from the user
    cout << "Enter Patient ID: ";
    cin >> id;
    cin.ignore(); 
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Gender: ";
    getline(cin, gender);
    cout << "Enter Diagnosis: ";
    getline(cin, diagnosis);
    cout << "Enter Contact Number: ";
    getline(cin, contact);


// stores patient details in the vectors made in the beginning of code
    patientID.push_back(id);
    patientName.push_back(name);
    patientAge.push_back(age);
    patientGender.push_back(gender);
    patientDiagnosis.push_back(diagnosis);
    patientContact.push_back(contact);
    
    //curt++ just keeps track of the the number of patients 
    curt++;  
    cout << "Patient added!!!" << endl;
}






//
// Function to display all patients
void displayAllPatients() {
    if (curt == 0) {
        cout << "No patients to display" << endl;
        return;
    }



    cout << "\n--- Patient List ---" << endl;
    for (int i = 0; i < curt; ++i) {

        cout << "ID: " << patientID[i] << "\nName: " << patientName[i]
             << "\nAge: " << patientAge[i] << "\nGender: " << patientGender[i]
             << "\nDiagnosis: " << patientDiagnosis[i]
             << "\nContact: " << patientContact[i] << "\n" << endl;


    }
}

// function to search for a patient by ID
void searchPatientByID() {
    int id;
    cout << "Enter Patient ID to search: ";
    cin >> id;
    //this forloop just goes through the patient list and search for a specific id thn displays the info when ID is found
    for (int i = 0; i < curt; ++i) {
        if (patientID[i] == id) {
            cout << "\nPatient found!\n";
            cout << "ID: " << patientID[i] << "\nName: " << patientName[i]
                 << "\nAge: " << patientAge[i] << "\nGender: " << patientGender[i]
                 << "\nDiagnosis: " << patientDiagnosis[i]
                 << "\nContact: " << patientContact[i] << "\n" << endl;
            return;
        }
    }
    // Message if patient is not found
    cout << "Patient not found :(" << endl;
}




void saveToFile() {
    ofstream outFile("patient_records.txt");
    if (!outFile) {
        cout << "Error" << endl;
        return;
    }

    for (int i = 0; i < curt; ++i) {
        outFile << patientID[i] << "\n" << patientName[i] << "\n" << patientAge[i] << "\n"
                << patientGender[i] << "\n" << patientDiagnosis[i] << "\n" << patientContact[i] << "\n";
    }
    outFile.close();
    cout << "Patient records saved to th file!" << endl;
}


void loadFromFile() {
    ifstream inFile("patient_records.txt");

    if (!inFile) {
        cout << "No file found :(" << endl;
        return;
    }




    int id, age;
    string name, gender, diagnosis, contact;
    while (inFile >> id) {




        inFile.ignore();
        getline(inFile, name);
        inFile >> age;
        inFile.ignore();
        getline(inFile, gender);
        getline(inFile, diagnosis);
        getline(inFile, contact);

        patientID.push_back(id);
        patientName.push_back(name);
        patientAge.push_back(age);
        patientGender.push_back(gender);
        patientDiagnosis.push_back(diagnosis);
        patientContact.push_back(contact);



        curt++;  
    }
    inFile.close();
    cout << "Patient records loaded from file!" << endl;
}








int main() {
    loadFromFile(); 
// menu to choose what you want to do in the hospital, it also loops 
    while (true) {
        cout << "\n--- Hospital Patient Management System ---" << endl;
        cout << "1. Add New Patient\n";
        cout << "2. Display All Patients\n";
        cout << "3. Search Patient by ID\n";
        cout << "4. Save Records to File\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
//whatever you choose in the menu, it calls the function to do as requested
        if (choice == 1) {
            addPatient();
        } else if (choice == 2) {
            displayAllPatients();
        } else if (choice == 3) {
            searchPatientByID();
        } else if (choice == 4) {
            saveToFile();
        } else if (choice == 5) {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }


    }

    return 0;
}
