#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>
#include <iomanip>

#ifndef FIRSTTERMBOOKPROJECT_TEXTBOOK_H
#define FIRSTTERMBOOKPROJECT_TEXTBOOK_H

using namespace std;

class Textbook {
private:
    string title, author, isbn;
    int edition, copies;
    bool isApproved;
    double pricePerCopy;
    string publishDate, approvalDate;

public:
    // Constructor with all parameters
    Textbook(string t, string a, int e, string i, string pd, int c, bool app, string appDate, double price)
            : title(t), author(a), edition(e), isbn(i), publishDate(pd), copies(c), isApproved(app), approvalDate(appDate), pricePerCopy(price) {}

    // Constructor with default values
    Textbook()
            : title("Unknown"), author("Unknown"), edition(1), isbn("000-000-000"), publishDate("N/A"), copies(0), isApproved(false), approvalDate("N/A"), pricePerCopy(0.0) {}

    void setTitle(const string &title) {
        Textbook::title = title;
    }

    const string &getTitle() const {
        return title;
    }

    const string &getAuthor() const {
        return author;
    }

    void setAuthor(const string &author) {
        Textbook::author = author;
    }

    const string &getIsbn() const {
        return isbn;
    }

    void setIsbn(const string &isbn) {
        Textbook::isbn = isbn;
    }

    int getEdition() const {
        return edition;
    }

    void setEdition(int edition) {
        Textbook::edition = edition;
    }

    int getCopies() const {
        return copies;
    }

    void setCopies(int copies) {
        Textbook::copies = copies;
    }

    bool isApproved1() const {
        return isApproved;
    }

    void setIsApproved(bool isApproved) {
        Textbook::isApproved = isApproved;
    }

    const string &getPublishDate() const {
        return publishDate;
    }

    void setPublishDate(const string &publishDate) {
        Textbook::publishDate = publishDate;
    }

    const string &getApprovalDate() const {
        return approvalDate;
    }

    void setApprovalDate(const string &approvalDate) {
        Textbook::approvalDate = approvalDate;
    }

    double getPricePerCopy() const {
        return pricePerCopy;
    }

    void setPricePerCopy(double pricePerCopy) {
        Textbook::pricePerCopy = pricePerCopy;
    }

    friend ostream& operator<<(ostream& out, const Textbook& t) {
        out << "Textbook" << "\n"
            << "Title: " << t.title << "\n"
            << "Author: " << t.author << "\n"
            << "Edition: " << t.edition << "\n"
            << "ISBN: " << t.isbn << "\n"
            << "Print Date: " << t.publishDate << "\n"
            << "Copies: " << t.copies << "\n"
            << "Price per Copy: " << fixed << setprecision(2) << t.pricePerCopy << "\n"
            << "Approved: " << (t.isApproved ? "Yes" : "No") << "\n"
            << "Approval Date: " << t.approvalDate << "\n";
        return out;
    }
};

#endif //FIRSTTERMBOOKPROJECT_TEXTBOOK_H
