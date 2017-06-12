/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 14.05.2017
 */

#ifndef cookie_h
#define cookie_h

#include <string> 

using namespace std;

#ifndef dessert_enum
#define dessert_enum
typedef enum Dessert {NONE=0, COOKIE, CANDY, ICECREAM} DESSERT;
#endif

class Cookie {
  private:
    string name;
    int stock;
    float price;
  public:
    Cookie();
    Cookie(string, int, float);
    Cookie(const Cookie&);
    ~Cookie() {};
    string getName() const;
    int getStock() const;
    float getPrice() const;
    float getCost() const;
    DESSERT getType() const;
    friend ostream& operator<<(ostream&, const Cookie&);
};

#endif
