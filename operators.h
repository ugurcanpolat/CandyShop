/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 14.05.2017
 */

#include "shop.cpp"
#include "candy.cpp"
#include "cookie.cpp"
#include "icecream.cpp"
#include "sweeties.cpp"

// Template function for operator << overloading. This will be used
// when output stream called with Shop<> object.
template <class type>
ostream& operator<<(ostream& os, const Shop<type>& shop) {
	// Add number of products to the output stream with precision 6.
	// Precision will be used further floating point numbers as well.
	os << "**********************" << endl << "Number of items:";
	os << setprecision(6) << shop.numberOfProducts << endl;
	
	// Add names and stock information with cost of all products.
	for (int i = 0; i < shop.numberOfProducts; i++) {
		os << i+1 << ": " << (shop.product+i)->getName() << " #";
		os << (shop.product+i)->getStock();
		os << " Cost: " << (shop.product+i)->getCost() << endl << endl;
	}
	
	// Add total cost of all products in the shop.
	float cost = shop.getCost();
	os << "**********************" << endl;
	os << "Total cost: " << cost << endl;
	
	// If discount has been set, discount the price add to the ostream.
	if (shop.discount > 0) {
		os << "Discount: " << shop.discount << "%" << endl;
		float discAmount = (cost * shop.discount) / 100; // Discount
		cost -= discAmount; // Discounted cost.
		os << "Discount amount: -" << discAmount << endl;
		os << "Discounted cost: " << cost << endl;
	}
	os << "**********************";
	return os;
}

// Following operator << overloadings will be used when output stream
// called with Candy/Cookie/Icecream/Sweeties object. I could not 
// manage to use template here because when I use template I got an 
// error "overloading is ambiguous" whick makes sense considering any 
// data type can be used in this template.

ostream& operator<<(ostream& os, const Candy& candy) {
	// Set precision and give information to the output stream.
	os << setprecision(6);
	os << candy.getName() << " #" << candy.getStock() << " Cost: ";
	os << candy.getCost() << endl;	
	return os;
}

ostream& operator<<(ostream& os, const Cookie& cookie) {
	// Set precision and give information to the output stream.
	os << setprecision(6);
	os << cookie.getName() << " #" << cookie.getStock() << " Cost: ";
	os << cookie.getCost() << endl;	
	return os;
}

ostream& operator<<(ostream& os, const Icecream& icecream) {
	// Set precision and give information to the output stream.
	os << setprecision(6);
	os << icecream.getName() << " #" << icecream.getStock() << " Cost: ";
	os << icecream.getCost() << endl;	
	return os;
}

ostream& operator<<(ostream& os, const Sweeties& sweet) {
	// Set precision and give information to the output stream.
	os << setprecision(6);
	os << sweet.getName() << " #" << sweet.getStock() << " Cost: ";
	os << sweet.getCost() << endl;	
	return os;
}
