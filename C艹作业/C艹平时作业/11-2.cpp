#include <iostream>
#include <cstring>
using namespace std;

class Vehicle {
public:
    Vehicle( const int doors, const int cylinders,
            char *color, double initialFuel,
            const int transmission );
    ~Vehicle();
    void setColor( char* color );
    void setFuelLevel( double amount );
    const char *getColor() const;
    const double getFuelLevel() const;
    const int getTransmissionType() const;
    const int getNumberOfDoors() const;
    const int getNumberOfCylinders() const;
    void setClassName( const char* );
    const char *getClassName() const;
    virtual void horn() = 0;
    virtual void print();
    /* write declaration for virtual function print     */
      
private:
    const int numberOfDoors;
    const int numberOfCylinders;
    char *vehicleColor;
    double fuelLevel;
    const int transmissionType;
    char *className;
};

Vehicle::Vehicle( const int doors, const int cylinders,
    char *color, double initialFuel,
    const int transmission )
    : numberOfDoors( doors ), numberOfCylinders( cylinders ),
    transmissionType( transmission )
{
    setFuelLevel( initialFuel );

    vehicleColor = 0;
    setColor( color );

    className = 0;
    setClassName( "Vehicle" );
}

Vehicle::~Vehicle()
{
    delete [] vehicleColor;
    delete [] className;
}

void Vehicle::print()
{
    cout << className << "\n"
        << "\tNumber of doors: " << numberOfDoors
        << "\n\tNumber of cylinders: " << numberOfCylinders
        << "\n\tTransmission type: " << transmissionType
        << "\n\tColor: " << vehicleColor
        << "\n\tFuel level: " << fuelLevel << endl;
}

/* write definition for pure virtual function horn */

void Vehicle::setColor( char *color )
{
    if( vehicleColor != 0 )
        delete [] vehicleColor;

    vehicleColor = new char[ strlen( color ) + 1 ];
    strcpy( vehicleColor, color );
}

void Vehicle::setFuelLevel( double amount )
{
    // assume 20 gallons is a full tank
    if( amount > 0.0 && amount <= 20.0 )
        fuelLevel = amount;
    else
        fuelLevel = 5.0;
}

const char* Vehicle::getColor() const
{
    return vehicleColor;
}

const double Vehicle::getFuelLevel() const
{
    return fuelLevel;
}

const int Vehicle::getTransmissionType() const
{
    return transmissionType;
}

const int Vehicle::getNumberOfDoors() const
{
    return numberOfDoors;
}

const int Vehicle::getNumberOfCylinders() const
{
    return numberOfCylinders;
}

void Vehicle::setClassName( const char *n )
{
    if( className != 0 )
        delete [] className;

    className = new char[strlen( n ) + 1];
    strcpy( className, n );
}

const char* Vehicle::getClassName() const
{
    return className;
}

class Taxi : public Vehicle {
public:
    Taxi( double );
    bool hasCustomers( void ) const;
    void setCustomers( bool );
    virtual void horn();
    virtual void print();
      
private:
    bool customers;
};

class Truck : public Vehicle {
public:
    Truck( double );
    bool hasCargo() const;
    void setCargo( bool );
    virtual void horn();
    virtual void print();
    
private:
    bool cargo;
};

Truck::Truck( double f )
    : Vehicle( 2, 16, "black", f, 8 )
{
    cargo = false;
    setClassName( "Truck" );
}

bool Truck::hasCargo() const { return cargo; }

void Truck::setCargo( bool c ) { cargo = c; }

void Truck::print()
{
    cout << getClassName() << "\n"
            << "\tNumber of doors: "
            << getNumberOfDoors()
            << "\n\tNumber of cylinders: "
            << getNumberOfCylinders()
            << "\n\tTransmission type: "
            << getTransmissionType()
            << "\n\tColor: " << getColor()
            << "\n\tFuel level: "
            << getFuelLevel() << "\n";

    if( cargo )
        cout << "\tThe truck is currently carrying cargo.\n";
    else
        cout << "\tThe truck is currently not carrying cargo.\n";
}

void Truck::horn()
{
    cout << "HOOOONK!";
}

Taxi::Taxi( double f )
    : Vehicle( 4, 6, "yellow", f, 5 )
{
    customers = false;
    setClassName( "Taxi" );
}

void Taxi::setCustomers( bool c ) { customers = c; }

bool Taxi::hasCustomers() const { return customers; }

void Taxi::print()
{
    cout << getClassName() << "\n"
            << "\tNumber of doors: "
            << getNumberOfDoors()
            << "\n\tNumber of cylinders: "
            << getNumberOfCylinders()
            << "\n\tTransmission type: "
            << getTransmissionType()
            << "\n\tColor: " << getColor()
            << "\n\tFuel level: "
            << getFuelLevel() << "\n";

    if( customers )
        cout << "\tThe taxi currently has passengers.\n";
    else
        cout << "\tThe taxi currently has no passengers.\n";
}

void Taxi::horn()
{
    cout << "beep beep";
}


int main() 
{
    Taxi cab( 3.3 );
    Truck mack( 7.54 );
    mack.setCargo(1);
    /* write code to indicate that truck is carrying cargo */
    cab.print();
    /* write function call to print Taxi object */
    mack.print();
    /* write function call to print Truck object */
    Vehicle* parkingLot[2];
    parkingLot[0] = &cab;
    parkingLot[1] = &mack;
    
    cout << "\nThe vehicles get stuck in traffic and respond: \n";
    
    for( int i = 0; i < 2; i++ ) {
    	cout << parkingLot[i]->getClassName()
    		<< ": ";
    	parkingLot[i]->horn();
    	cout << endl;
    }
    
    return 0;
}
