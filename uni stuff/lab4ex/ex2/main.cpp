#include <iostream>
using namespace std;

class item{
private:
    string contentType;
    string datePurchased;
    int itemID;
    string MediaFormat;
    int numOfItems;
    float price;
    string title;
public:
    item(string cT, string dP, int item,
         string MF, int NOI, float p, string t) {
        contentType = cT;
        datePurchased = dP;
        itemID = item;
        MediaFormat = MF;
        numOfItems = NOI;
        price = p;
        title = t;
    }

    const string &getContentType() const {
        return contentType;
    }

    const string &getDatePurchased() const {
        return datePurchased;
    }

    int getItemId() const {
        return itemID;
    }

    const string &getMediaFormat() const {
        return MediaFormat;
    }

    int getNumOfItems() const {
        return numOfItems;
    }

    float getPrice() const {
        return price;
    }

    const string &getTitle() const {
        return title;
    }

    void setItemId(int itemId) {
        itemID = itemId;
    }
    void toString(){
        cout<< getMediaFormat() << "със заглавие" << getTitle()
        << "е била закупена на цена" << getPrice() <<
        "на дата: " << getDatePurchased() << "\n";
    }
    ~item(){
        cout<<"Destructed";
    }
};

class movie:item {
private:
    int rating;
public:
    void playOnDVD(){
        cout << "Movie is being played on DVD";
    };
};

class game:item {
private:
    string difficulty;
    string game;
public:
    const string &getDifficulty() const {
        return difficulty;
    }
};
int main() {

    return 0;
}
