/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 14.05.2017
 */
 
 /* IMPORTANT NOTE: Compile command should denote it is a c++11 
  * compilation. The reason is the usage of 'stof' to convert string 
  * to float. Hence, compile command is:
  * 
  * g++ -std=c++11 DessertShop.cpp -o DessertShop
  * 
  * */

#include <iostream>
#include <cstdlib>
#include <string>

#include <iomanip> // setprecision
#include <fstream> // file operations

#include "shop.h"
#include "candy.h"
#include "cookie.h"
#include "icecream.h"
#include "operators.h" // operator << overloading

using namespace std;

int main() {
    Cookie cookie1("Chocolate Chip Cookies",10, 180); //(name, pieces, priceperdozen)
	Cookie cookie2("Cake Mix Cookies", 16, 210);
	
	Shop<Cookie> cookieShop(cookie1);
	cookieShop.add(cookie2);
	cout<<cookieShop<<endl;

	//Catch an exception here while trying to access the element at(2)
    try { 
		cout << cookieShop[2] << endl;
	}
	catch (const char* error) {
		cout << error << endl;
	}

	Icecream icecream1("Chocolate ice cream",1.5, 170); //(name, litre, priceperlitre)
	Shop<Icecream> icecreamShop(icecream1); 
	cout<<icecreamShop<<endl;

	//Catch an exception here while trying to set the discount to(50)  
	try {     
		icecreamShop.setDiscount(50);
	}
	catch (const char* error) {
		cout << error << endl;
	}

	Candy candy2("Gummi bears",12,89); //(name, weight, priceperkg)
	Candy candy3("Hanukkah gelt",8,110);

	Shop<Candy> candyShop(candy2);
	candyShop.add(candy3);
    
    candyShop.setDiscount(15);
    cout<<candyShop<<endl;
	
	/* FILE OPERATIONS */
	
	// Open files.
	ifstream stock("stock.txt", ifstream::in); // Read
	ifstream order("order.txt", ifstream::in); // Read
	ofstream checkout("checkout.txt", ofstream::out); // Write
	
	string line;
	getline(stock, line); // Skip the header line of "stock.txt".
	
	int type = 0, itemCount = 0, price = 0, tail, tabCounter; 
	string name;
	
	// Create object of type Shop<Sweeties>. This object can keep all 
	// types of product types: Cookie, Candy, Icecream.
	Shop<Sweeties> stocks; 
	while(!stock.eof()) {
		tabCounter = 0; // Will keep tab number of line.
		getline(stock, line); // Read the line.
		
		// If line is empty, no need to take action.
		if(line.empty()) break;
	
		// Extract information from read line.
		for(int counter = 0; counter < line.length(); counter++) {
			// If it reaches to first tab, it is |name| of the product.
			if(line[counter] == '\t' && tabCounter == 0) {
				// Get the substring that contains name.
				name = line.substr(0, counter);
				tabCounter++;
			}
			
			// If it reaches to second tab, it is |type| of the product.
			else if(line[counter] == '\t' && tabCounter == 1) {
				// Get type by converting the character to the integer.	
				type = line[counter-1] - '0';
				// Tail stores start position of next information.
				tail = counter+1;
				tabCounter++;
			}
			
			// It is |itemCount| of the product.
			else if(line[counter] == '\t' && tabCounter == 2) {
				// Convert substring to float.
				itemCount = stof(line.substr(tail, counter-tail));
				// Tail stores start position of next information.
				tail = counter+1;
				tabCounter++;
			}
			
			// After the |itemCount|, rest of the line will be price.
			else if(counter == (line.length()-1) && tabCounter == 3) {
				// Convert substring to float.
				price = stof(line.substr(tail));
				tabCounter++;
			}
		}
		
		// Store the information in the object of Sweeties.
		Sweeties new_stock(name, itemCount, price, type);
		stocks.add(new_stock);
	}
	
	int orderCount = 0; // Number of orders
	// Create object of type Shop<Sweeties>. This object can keep all 
	// types of product types: Cookie, Candy, Icecream.
	Shop<Sweeties> orders;
	orders.setDiscount(10); // Set discount to %10.
	
	while(!order.eof()) {
		tabCounter = 0;
		getline(order, line); // Get the line.
		
		// If the line is empty, no need to take action.
		if(line.empty()) break; 
	
		// Extract information from read line.
		for(int counter = 0; counter < line.length(); counter++) {
			// If it reaches to first tab, it is |name| of the order.
			if(line[counter] == '\t' && tabCounter == 0) {
				name = line.substr(0, counter);
				tabCounter++;
			}
			
			// If it reaches to second tab, it is |type| of the order.
			else if(line[counter] == '\t' && tabCounter == 1) {
				// Get type by converting the character to the integer.	
				type = line[counter-1] - '0';
				// Tail stores start position of next information.
				tail = counter+1;
				tabCounter++;
			}
			
			// After the |type|, rest of the line will be itemCount.
			else if(counter == (line.length()-1) && tabCounter == 2) {
				// Convert substring to float.
				itemCount = stof(line.substr(tail));
				tabCounter++;
			}
		}
		
		orderCount++; // Increment number of orders.
		
		// Find order in stock by name and get informations.
		float stock = stocks.getStock(name);
		float price = stocks.getPrice(name);
		// If stock is not enough to meet the order write error to the
		// file. 
		if (itemCount > stocks.getStock(name)) {
			checkout << "!!! We don't have " << itemCount;
			checkout << " (" << name << ")s." << endl;
			// If there is stock but not enough, just give as much as 
			// the stock.
			if (stocks.getStock(name) > 0) {
				Sweeties new_order(name, stock, price, type);
				orders.add(new_order);
			}
		}
		// If stock is enough to fullfill order, give order.
		else {
			Sweeties new_order(name, itemCount, price, type);
			orders.add(new_order);
		}
	}
	
	// Get total cost of orders including tax.
	float totalCost = orders.getCost();
	// Get discounted cost.
	float discountedCost = orders.getDiscountedCost();
	// Calculate amount of discount.
	float discountAmount = discountedCost - totalCost;
	
	// Write informations to file |checkout|.
	checkout << "-----------------------" << endl;
	checkout << "Number of items:" << orderCount << endl;
	for (int i = 0; i < orderCount; i ++)
		checkout << orders[i];
	checkout << "**********************" << endl;
	checkout << "Total cost: " << setprecision(6) << totalCost << endl;
	checkout << "Discount: %10" << endl;
	checkout << "Discount amount: " << discountAmount << endl;
	checkout << "Discounted cost: " << discountedCost << endl;
	checkout << "**********************" << endl;
	
	// Close all files.
	stock.close();
	order.close();
	checkout.close();
	return 0;
}
