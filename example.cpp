#include "Ook.h"
#include <iostream>

void load()
{
 
 Ook::File file;
 
 file.unserialise( std::ifstream("cars.ook", std::ios::in | std::ios::binary) );
 
 std::cout << "Name: " << (std::string) file["showroom"]["name"] << "\n";
 std::cout << "Address:- \n" << (std::string) file["showroom"]["address"] << "\n";
 
 std::cout << "\nCars:\n\n";
 Ook::Sets all = file.all();
 
 while(all.hasMore())
 {
  Ook::Set& car = all++;
  
  if (all.key() == "showroom") // Skip over showroom. Just did that.
   continue;
  
  std::cout << "+ " << (std::string) car["type"] << "\n";
  std::cout << "  Colour: " << (std::string) car["colour"] << "\n";
  std::cout << "  Price: " << (float) car["price"] << "\n";
  std::cout << "  Miles: " << (float) car["miles"] << "\n";

  if (all.hasMore())
   std::cout << "\n";
 }
}

void save()
{
 
 Ook::File file;
 
 // Showroom.
 Ook::Set& showroom = file["showroom"];
 showroom["name"] = "Green Cars Ltd.";
 showroom["address"] = "123 Fake Street,\nUptown,\nNorth,\nAB12 3CD";

 // Red Car
 Ook::Set& red_car = file.unnamed();
 red_car["type"] = "hatchback";
 red_car["colour"] = "red";
 red_car["price"] = 14999.45f;
 red_car["miles"] = 35000;
 
 // Blue Car
 Ook::Set& blue_car = file.unnamed();
 blue_car["type"] = "sport";
 blue_car["colour"] = "blue";
 blue_car["price"] = 55000.0f;
 blue_car["miles"] = 5000;
 
 // save to file.
 file.serialise( std::ofstream("cars.ook", std::ios::out | std::ios::binary) );
 
}

void main()
{
 save();
 load();
}
