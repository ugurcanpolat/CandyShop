/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 14.05.2017
 */

#include "cookie.h"

Cookie::Cookie() { // Default constructor
	stock = 0;
	price = 0;
}

Cookie::Cookie(string label, int amount, float ppd) {
	name = label;
	stock = amount;
	price = ppd;
}

Cookie::Cookie(const Cookie& copy) { // Copy constructor
	name = copy.name;
	stock = copy.stock;
	price = copy.price;
}

string Cookie::getName() const {
	return name;
}

int Cookie::getStock() const {
	return stock;
}

float Cookie::getPrice() const {
	return price;
}

float Cookie::getCost() const {
	// Cost is measured for price for dozen (12).
	float dozen = static_cast<float>(stock) / 12;
	return dozen * price;
}

DESSERT Cookie::getType() const { // Get dessert type
	return COOKIE;
}
