/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 14.05.2017
 */

#include "icecream.h"

Icecream::Icecream() { // Default constructor
	stock = 0;
	price = 0;
}

Icecream::Icecream(string label, float amount, float ppl) {
	name = label;
	stock = amount;
	price = ppl;
}

Icecream::Icecream(const Icecream& copy) { // Copy constructor
	name = copy.name;
	stock = copy.stock;
	price = copy.price;
}

string Icecream::getName() const {
	return name;
}

float Icecream::getStock() const {
	return stock;
}

float Icecream::getPrice() const {
	return price;
}

float Icecream::getCost() const {
	return stock * price;
}

DESSERT Icecream::getType() const { // Get dessert type
	return ICECREAM;
}
