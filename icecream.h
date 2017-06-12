/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 14.05.2017
 */

#ifndef icecream_h
#define icecream_h

#include <string> 

using namespace std;

#ifndef dessert_enum
#define dessert_enum
typedef enum Dessert {NONE=0, COOKIE, CANDY, ICECREAM} DESSERT;
#endif

class Icecream {
  private:
    string name;
    float stock;
    float price;	
  public:
    Icecream();
    Icecream(string, float, float);
    Icecream(const Icecream&);
    ~Icecream() {};
    string getName() const;
    float getStock() const;
    float getPrice() const;
    float getCost() const;
    DESSERT getType() const;
    friend ostream& operator<<(ostream&, const Icecream&);
};

#endif
