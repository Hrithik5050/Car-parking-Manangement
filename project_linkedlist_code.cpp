#include <iostream>
#include <string>

using namespace std;

// Define the structure for a car
class Car {
    public:
    string brand;
    string model;
    bool available;
    Car* next;
};

//customer info

class user_info
{
    private:
    string customer;
    public:
    user_info()
    {
      customer=" ";
    }
    void userinfo()
{
    
    
    cout << "\t\t\t\tPlease Enter user Name: ";//taking data from the owner
    cin >> customer ;
    cout<<endl;
}
  void showrent(string model)
    {
       
    cout << "\n\t\t                       Car Rental - Customer Invoice                  "<<endl;
    cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout << "\t\t	| Invoice No. :"<<"------------------|"<<"#Cnb81353"<<" |"<<endl;
    cout << "\t\t	| Customer Name:"<<"-----------------|"<<customer<<" |"<<endl;
    cout << "\t\t	| Car Model :"<<"--------------------| "<<model<<endl;
    cout << "\t\t	| Advanced :"<<"---------------------|"<<"0"<<" |"<<endl;
    cout << "\t\t	 ________________________________________________________"<<endl;
    cout <<"\n";
    cout << "\t\t	 ________________________________________________________"<<endl;
    cout << "\t\t	 # This is a computer generated invoce and it does not"<<endl;
    cout << "\t\t	 require an authorised signture #"<<endl;
    cout <<" "<<endl;
    cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout << "\t\t	You are advised to pay up the amount before due date."<<endl;
    cout << "\t\t	Otherwise penelty fee will be applied"<<endl;
    cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
 return ;
    }

};



// Class for Car Rental System
class CarRentalSystem : public user_info  //single inheritance
{
private:
    
    Car* rentedCars; // Stack for rented cars
    Car* head;

public:
    CarRentalSystem() 
    {
        head = NULL;
        rentedCars = NULL;
        
    }

    // Function to add a new car to the rental system
    void addCar(string brand, string model) 
    {
        Car* newCar = new Car;
        Car* temp=head;

        
        newCar->brand = brand;
        newCar->model = model;
        newCar->available = true;
        newCar->next = NULL;
    // insertion of new car given by owner
        if (head == NULL) 
        {   
            head = newCar;
           

        } 
        else 
        {
            
            while (temp->next != NULL) 
            {
                temp = temp->next;
                
            }
            temp->next = newCar;
            

        }
        return;        
        }
//owner info
void owner_login()
{

    string ownername;
    cout << "\t\t\t\tPlease Enter owner Name: "; 
    cin >> ownername;
    cout<<endl;
}



    // Function to rent a car
    void rentCar(string brand, string model) {
        Car* temp = head;
        while (temp != NULL) 
        {
            if (temp->brand == brand && temp->model == model && temp->available) 
            {
                temp->available = false;
                cout << "You have rented a " << temp->brand << " " << temp->model << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Car not available for rent." << endl;
        cout<<"Rented car"<<temp->model<<endl;
    }


    // Function to display available cars
    void displayAvailableCars() 
    {
        Car* temp = head;
        cout << "\t\t\tAvailable cars" << endl;
        while (temp != NULL) {
            if (temp->available) 
            {
               cout<<"Car brand:"<<temp->brand<<" \t\t\t"<<"Car model:"<<temp->model<<endl;
            }
            temp = temp->next;
        }
    }
};
        
    

int main() 
{
    CarRentalSystem rentalSystem;
    rentalSystem.owner_login();
    Car *firstcar;

    // Adding cars to the rental system
    rentalSystem.addCar("Toyota", "Camry");
    rentalSystem.addCar("Honda", "Accord");
    rentalSystem.addCar("Ford", "Mustang");

    rentalSystem.userinfo();

    // Displaying available cars
    rentalSystem.displayAvailableCars();

    // Renting a car
    rentalSystem.rentCar("Toyota", "Camry");
    rentalSystem.showrent("Camary");

    // rentalSystem.displayAvailableCars();
    // rentalSystem.rentCar("Toyota", "Camry");
    
    return 0;
}
