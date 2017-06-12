/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 14.05.2017
 */

#include "sweeties.h"

Sweeties::Sweeties() { // Default constructor
	stock = 0;
	price = 0;
	type = NONE;
}

Sweeties::Sweeties(string label, float amount, float priceTag, int dessert) {
	name = label;
	stock = amount;
	price = priceTag;
	// |type| is an integer and |dessert| is a DESSERT so casting needed.
	type = static_cast<DESSERT>(dessert); 
}

Sweeties::Sweeties(const Sweeties& copy) { // Copy constructor
	name = copy.name;
	stock = copy.stock;
	price = copy.price;
	type = copy.type;
}

string Sweeties::getName() const {
	return name;
}

float Sweeties::getStock() const {
	return stock;
}

float Sweeties::getPrice() const {
	return price;
}

float Sweeties::getCost() const {
	// Cost of cookies is measured for dozen. 
	if (type == COOKIE) {
		float dozen = static_cast<float>(stock) / 12;
		return dozen * price;
	}
	// Candies and icecream is measured for amount or litre.
	return stock * price;
}

DESSERT Sweeties::getType() const { // Get dessert type.
	return type; 
}
