#include <bits/stdc++.h>

//'max' denotes the maximum
//number of candidates
#define max 30

using namespace std;

//Structure containing 
//necessary variables
struct candidate_data
{
  //variable containing candidate name
  string name;
	   
  //semester grade point average (SGPA)
  float semester_grade_point;
	    
  //roll/registration number
  long int reg_roll_no;

  //does the student prefer paperback or sofcopy?
  string preference;
};

//condition for variable (num <= max)
int num;

//DisplayMenu function prototype
void DisplayMenu();

//user defined datatype derived from the above structure
candidate_data candid_container[max];

//function to build the dataframe
void build()
{
	cout << "\nBuild The Table\n";

	cout << "Enter the number of entries required (max "<<max<<"): ";
	cin >> num;

  //to check if number of data inputs cause overflow
	if (num > max)
  {
		cout << "Ooops! The maximum number of entries must be " <<max<<"\n";
    
    //if so, assign max to variable num
		num = max;
	}
  
  //data entry begins here
	cout << "\nEnter the following data: \n";
  
  //enter data untill the iteration ends
	for (int i = 0; i < num; i++)
  {
    //name of candidate
		cout << "\nCandidate Name: ";
		cin >> candid_container[i].name;

    //semester grade point (SGPA)
		cout << "\nSemester GPA: ";
		cin >> candid_container[i].semester_grade_point;

    //candidate registration number
		cout << "\nRegist. No.: ";
		cin >> candid_container[i].reg_roll_no;

    //candidate preference
		cout << "\nMaterial Preference (Softcopy/Paperback): ";
		cin >> candid_container[i].preference;

	}

  //function prototype used
  //to display the data entry
	DisplayMenu();
}

//function to input new data
//updating the previous table
void insert()
{
	if (num < max)
  {
    //update the number
    //w.r.t constraints
		int i = num;
		num++;

    //declaring the data entry
		cout << "\nData Entry:\n";
    
    //name of candidate
		cout << "\nCandidate Name: ";
		cin >> candid_container[i].name;

    //semester grade point (SGPA)
		cout << "\nSemester GPA: ";
		cin >> candid_container[i].semester_grade_point;

    //candidate registration number
		cout << "\nRegist. No.: ";
		cin >> candid_container[i].reg_roll_no;

	//candidate preference
		cout << "\nMaterial Preference (Softcopy/Paperback): ";
		cin >> candid_container[i].preference;
	}
  
	else
  {
    //case when num goes beyond max
		cout << "\nWarning! Data Overflow Detected\n";
	}

  //prototype used to display data
	DisplayMenu();
}

//function to output the table
void  DisplayTable()
{
	cout<<"Candidate Name   Semester GPA   Regist. Number   Preference "<<endl;
	cout<<"-----------------------------------------------------------"<<endl;

	for(int i = 0; i <= num-1; i++)
	{
		cout<<candid_container[i].name;
		cout<<setw(17)<<candid_container[i].semester_grade_point;
		cout<<setw(17)<<candid_container[i].reg_roll_no;
		cout<<setw(17)<<candid_container[i].preference;
		cout<<endl;
	}
    //prototype used to display data
    DisplayMenu();
 }


void searchRecord()
{
  //enter candidate's name to be searched
	cout << "\nEnter The Candidate's Registration Number: ";

	long int reg_num;
	cin >> reg_num;

	for (int i = 0; i < num; i++) {

		// If the name is found in the built record
    //show the candidate's data
		if (candid_container[i].reg_roll_no == reg_num) {
			cout << "\nCandidate Name: "<< candid_container[i].name << "\n";

			cout << "Semester GPA: "<< candid_container[i].semester_grade_point << "\n";

			cout << "Regist. No.: "<< candid_container[i].reg_roll_no << "\n";

			cout << "Material Preference: "<< candid_container[i].preference << "\n";

			break;
		}
	}

  //prototype used to display data
	DisplayMenu();
}

//function used to display menu
void DisplayMenu()
{

	cout << "\n\n-----------------------------------------------------------\n\n";

	cout << "\nWelcome To The Portal:\n";
	cout << "*********************\n\n";
	cout << "To Build Candidate Data           (Press 1)\n";
	cout << "To Insert New Data                (Press 2)\n";
	cout << "To Display The Candidate Data     (Press 3)\n";
	cout << "To Search For A Candidate         (Press 4)\n";
	cout << "For Exit                          (Press 5)\n";
    cout << "\n";

	int option;

	cin >> option;


	if (option == 1)
  {
		build();
	}

	else if (option == 2)
  {
		insert();
	}

	else if (option == 3)
  {
		DisplayTable();
	}

	else if (option == 4)
  {
		searchRecord();
	}

	else if (option == 5)
  {
		return;
	}

	else 
  {
		DisplayMenu();
	}
}

//main function
int main()
{
	//clearscreen function
        //system("cls");
	DisplayMenu();
	return 0;
}
