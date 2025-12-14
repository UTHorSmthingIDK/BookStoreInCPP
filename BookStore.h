#pragma once
#include <string>
#include <list>
#include <vector>
#include <limits>
#include <stdexcept>

#ifdef _WIN32
#include <windows.h>
#endif

namespace Color {
    constexpr const char* RESET   = "\033[0m";

    constexpr const char* BLACK   = "\033[30m";
    constexpr const char* RED     = "\033[31m";
    constexpr const char* GREEN   = "\033[32m";
    constexpr const char* BGREEN  = "\033[92m";
    constexpr const char* YELLOW  = "\033[33m";
    constexpr const char* BLUE    = "\033[34m";
    constexpr const char* MAGENTA = "\033[35m";
    constexpr const char* CYAN    = "\033[36m";
    constexpr const char* WHITE   = "\033[37m";

    constexpr const char* WHITEB = "\033[47m";
    constexpr const char* BOLD = "\033[1m";
    constexpr const char* ULINE = "\033[4m";

}

namespace File {
    inline constexpr const char* AUTHOR = "author.txt";
    inline constexpr const char* BOOK   = "book.txt";
    inline constexpr const char* WRITES = "writes.txt";
}

int checkingAscii(std::string& A, int mode);
std::string split(const std::string& s, char del, size_t start);
int welcome(int count);

class Author;
class Book;
class Writes;

class Date
{
public:
    Date() = default;
    Date(int day, int month, int year) : day(day), month(month), year(year) {}

    Date(const Date&) = default;

    std::string toString() const;

    void setDay(int day)
    {
        this->day = day;
    }
    void setMonth(int month)
    {
        this->month = month;
    }
    void setYear(int year)
    {
        this->year = year;
    }

    int getDay() const
    {
        return day;
    }
    int getMonth() const
    {
        return month;
    }
    int getYear() const
    {
        return year;
    }

private:
    int year;
    int month;
    int day;
};

class Euro
{
public:
    Euro() = default;
    Euro(int integerPart, int decimalPart) : integerPart(integerPart), decimalPart(decimalPart) {}

    Euro(const Euro&) = default;

    std::string toString() const;

    void setIntegerPart(int other)
    {
        integerPart = other;
    }
    void setDecimalPart(int other)
    {
        decimalPart = other;
    }

    int getIntegerPart() const
    {
        return integerPart;
    }
    int getDecimalPart() const
    {
        return decimalPart;
    }

private:
    int integerPart;
    int decimalPart;
};

class BookStore
{
public:
    BookStore() = default;
    explicit BookStore(const std::list<Author>& author, const std::list<Book>& book, const std::list<Writes>& writes) : authorList(author), bookList(book), writesList(writes) {}

    void insertNewAuthor();
    void insertNewBook(int mode);

    std::string toString() const;

    const std::list<Author>& getAuthorList() const {
    return authorList;
    }

    const std::list<Book>& getBookList() const{
        return bookList;
    }
    const std::list<Writes>& getWritesList() const{
        return writesList;
    }

    void setAuthorList(const std::list<Author>& authorList){
        this->authorList = authorList;
    }

    void setBookList(const std::list<Book>& bookList){
        this->bookList = bookList;
    }

    void setWritesList(const std::list<Writes>& writesList){
        this->writesList = writesList;
    }

private:
    std::list<Author> authorList;
    std::list<Book> bookList;
    std::list<Writes> writesList;
};

class Author
{
public:
    Author() = default;
    explicit Author(const std::string& surname, const std::string& name) : surname(surname), name(name)
    {
        // need to check files for numOfAuthors and IDs else create a new id and add a new book updating both books and writes
    }
    Author(const Author&) = default;

    std::string toString() const;

    void setWriterId(int id)
    {
        writer_id = id;
    }
    void setSurname(const std::string& surname)
    {
        this->surname = surname;
    }
    void setName(const std::string& name)
    {
        this->name = name;
    }
    void setNumOfBooks(int num)
    {
        numOfBooks = num;
    }

    int getWriterId() const
    {
        return writer_id;
    }
    std::string getSurname() const
    {
        return surname;
    }
    std::string getName() const
    {
        return name;
    }
    int getNumOfBooks() const
    {
        return numOfBooks;
    }

    static int readAuthorTxt(std::list<Author> &authorList); // this one is done

    static int writeAuthorTxt(std::list<Author> &authorList);

    static void createAuthorTxt();

    void getInput(int numAuthors);

    // more functions to come

private:
    int writer_id;
    std::string surname;
    std::string name;
    int numOfBooks;
};

class Book
{
public:
    Book() = default;

    explicit Book(const std::string& title, const Date& date, const Euro& price) : title(title), release_date(date), price(price) {}

    Book(const Book&) = default;

    std::string toString() const;

    void setTitle(const std::string& title)
    {
        this->title = title;
    }
    void setRDate(const Date& date)
    {
        release_date = date;
    }
    void setPrice(const Euro& price)
    {
        this->price = price;
    }

    std::string getTitle() const
    {
        return title;
    }
    std::string getRDate() const
    {
        return release_date.toString();
    }
    std::string getPrice() const
    {
        return price.toString();
    }

    static int readBookTxt(std::list<Book> &bookList);

    static int writeBookTxt(std::list<Book> &bookList);

    static void createBookTxt();

    void getInput(int numBooks, int mode);

private:
    std::string title;
    Date release_date;
    Euro price;
};

class Writes
{
public:
    Writes() = default;

    /*Writes()
    {
        // opens author.txt and book.txt to find the values
    }*/

    explicit Writes(const Author& author, const Book& book) : title(book.getTitle()), writer_id(author.getWriterId()) {}

    std::string toString() const;

    void setTitle(const std::string& title)
    {
        this->title = title;
    }
    void setWriterId(int id)
    {
        this->writer_id = id;
    }
    std::string getTitle() const
    {
        return title;
    }
    int getWriterId() const
    {
        return writer_id;
    }

    static int readWritesTxt(std::list<Writes> &writesList);

    static void createWritesTxt();

    static std::vector<int> findId(int id);

    static std::vector<int> findLName(const std::string& name);


private:
    std::string title;
    int writer_id;
};