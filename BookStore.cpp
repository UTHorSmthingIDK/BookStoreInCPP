#include "BookStore.h"
#include <fstream>
#include <iostream>

using std::cin;
using std::cout;
using std::list;
using std::string;
using std::vector;

int main()
{
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif

    int count = 0, choice;
    cout << "\n\n\n\n" <<Color::BLUE
    <<"\t\t██████╗  ██████╗  ██████╗ ██╗  ██╗███████╗████████╗ ██████╗ ██████╗ ███████╗\n"
    <<"\t\t██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗██╔════╝\n"
    <<"\t\t██████╔╝██║   ██║██║   ██║█████╔╝ ███████╗   ██║   ██║   ██║██████╔╝█████╗  \n"
    <<"\t\t██╔══██╗██║   ██║██║   ██║██╔═██╗ ╚════██║   ██║   ██║   ██║██╔══██╗██╔══╝  \n"
    <<"\t\t██████╔╝╚██████╔╝╚██████╔╝██║  ██╗███████║   ██║   ╚██████╔╝██║  ██║███████╗\n"
    <<"\t\t╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚══════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚══════╝\n\n" << Color::RESET;
    cout <<Color::BGREEN<< "\tPress enter to continue" <<Color::RESET<< std::endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    BookStore bookstore;
    char c = cin.get();
    while (true)
    {
        choice = welcome(count++);
        switch (choice)
        {
        case 1:
            bookstore.insertNewAuthor();
            break;
        case 2:
            bookstore.insertNewBook(1);
            break;
        case 3:
            //bookstore.searchAuthorRecord();
            break;
        case 4:
            //bookstore.searchBookRecord();
            break;
        case 5:
            //bookstore.deleteAuthorRecord();
            break;
        case 6:
            //bookstore.deleteBookRecord();
            break;
        case 7:
            //bookstore.clearData();
            break;
        case 8:
            cout <<Color::BGREEN<< "\tThank you for using our services\n\tExiting program"<<Color::RESET<< std::endl;
            return 0;
            break;
        default:
            cout <<Color::RED<<"You made a mistake"<<Color::RESET<< std::endl;
        }
    }
    return 0;
}

std::string Author::toString() const
{
    return std::to_string(writer_id) + ",\n" + surname + ",\n" + name + ",\n" + std::to_string(numOfBooks) + ",\n";
}

std::string Book::toString() const
{
    return title + ",\n" + release_date.toString() + ",\n" + price.toString() + ",\n";
}

std::string Writes::toString() const
{
    return title + ",\n" + std::to_string(writer_id) + ",\n";
}

std::string Date::toString() const
{
    return std::to_string(day) + "-" + std::to_string(month) + "-" + std::to_string(year);
}

std::string Euro::toString() const
{ // I don't think we need to make thi override to_string
    return std::to_string(getIntegerPart()) + "." + std::to_string(getDecimalPart());
}

int welcome(int count)
{
    int choice, mistakes = 0;
    if (!count)
    {
        cout << Color::CYAN << "<<===================================================>>\n\n"
             << Color::RESET
             << Color::GREEN << "\tWelcome to Our BookStore.\n"
             << Color::RESET << "How would you like us to help you\n"
             << "Type a number from 1 to 8 for the following actions\n"
             << Color::RED << ">>" << Color::RESET <<Color::BOLD<<" 1. Insert new Author "<<Color::RESET<< Color::RED << "<<\n>>" << Color::RESET <<Color::BOLD
             <<" 2. Insert new Book "<<Color::RESET<< Color::RED << "<<\n>>"
             << Color::RESET <<Color::BOLD<<" 3. Search Author record "<<Color::RESET<< Color::RED << "<<\n"
             << Color::RESET
             << Color::RED << ">>" << Color::RESET <<Color::BOLD<<" 4. Search Book record "<<Color::RESET<< Color::RED << "<<\n>>" << Color::RESET 
             <<Color::BOLD
             <<" 5. Delete Author record "<<Color::RESET<< Color::RED << "<<\n>>" << Color::RESET <<Color::BOLD<<" 6. Delete Book Record " <<Color::RESET<<Color::RED << "<<\n"
             << Color::RESET
             << Color::RED << ">>" << Color::RESET <<Color::BOLD<<" 7. Clear All records "<<Color::RESET<< Color::RED << "<<\n>>" << Color::RESET <<Color::BOLD<<" 8. Exit the program "<<Color::RESET<< Color::RED << "<<\n"
             << Color::RESET
             << Color::CYAN << "<<===================================================>>" << Color::RESET << std::endl;
    }
    else
    {
        cout << Color::CYAN << "<<===================================================>>\n\n"
             << Color::RESET
             << "Type a number from 1 to 8 for the following actions\n"
             << Color::RED << ">>" << Color::RESET << " 1. Insert new Author " << Color::RED << "<<\n>>" << Color::RESET << " 2. Insert new Book " << Color::RED << "<<\n>>" << Color::RESET << " 3. Search Author record " << Color::RED << "<<\n"
             << Color::RESET
             << Color::RED << ">>" << Color::RESET << " 4. Search Book record " << Color::RED << "<<\n>>" << Color::RESET << " 5. Delete Author record " << Color::RED << "<<\n>>" << Color::RESET << " 6. Delete Book Record " << Color::RED << "<<\n"
             << Color::RESET
             << Color::RED << ">>" << Color::RESET << " 7. Clear All records " << Color::RED << "<<\n>>" << Color::RESET << " 8. Exit the program " << Color::RED << "<<\n"
             << Color::RESET
             << Color::CYAN << "<<===================================================>>" << Color::RESET << std::endl;
    }
    while (true)
    {
        cin >> choice;
        if (choice >= 1 && choice <= 8)
            return choice;

        cout << Color::RED << "Invalid choice\n"
             << Color::RESET;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return choice;
}

void BookStore::insertNewAuthor()
{
    int numAuthors = Author::readAuthorTxt(authorList);
    if (numAuthors == -1)
    {
        Author::createAuthorTxt();
    }
    if (numAuthors < 0)
    {
        numAuthors = 0;
    }
    Author a;
    a.Author::getInput(numAuthors);
    authorList.push_back(a);
    Author::writeAuthorTxt(authorList); // I think pretty much finished this method
}

void BookStore::insertNewBook(int mode)
{
    Book book;
    int numBooks = Book::readBookTxt(bookList);
    if (numBooks == -1)
    {
        Book::createBookTxt();
    }
    if (numBooks < 0)
    {
        numBooks = 0;
    }
    book.getInput(numBooks, mode);
}

int checkingAscii(string& A, int mode)
{
    for (char &c : A)
    {
        if (mode)
        {
            if ((toupper(c) < 'A' || toupper(c) > 'Z') && toupper(c) != '\'')
            {
                return 0;
            } // this is for names
        }
        else
        {
            if (c < 32 || c > 126)
            {
                return 0;
            } // this is for titles 32-126
        }
    }
    return 1;
}

string split(const string &s, char del, size_t start)
{
    string B = "";
    for (int i = start; i < s.size(); ++i)
    {
        if (s.at(i) == del)
            return B;
        B += s.at(i);
    }
    return "";
}

void Book::getInput(int numBooks, int mode)
{
    string surName, title;
    cout << Color::CYAN << "<<===================================================>>" << Color::RESET << std::endl;
    if (!mode)
    {
        while (1)
        {
            cout << Color::RED << "\t>>" << Color::RESET << "Type the last Name of the Author" << Color::RED << "<<" << Color::RESET << std::endl;
            cin >> surName;
            if (surName.size() == 0 || surName.size() > 15)
            {
                cout << Color::RED << "You made a mistake" << Color::RESET << std::endl;
                continue;
            }
            if (!checkingAscii(surName, 1))
            {
                cout << Color::RED << "You made a mistake" << Color::RESET << std::endl;
                continue;
            }
            break;
        }
        vector<int> pos = Writes::findLName(surName);
        if (pos.at(0) != -1)
        {
            return;
        }
        cout << "He has not written a single book" << std::endl;
    }
    while (1)
    {
        cout << "\t>> Type the Title of the book <<" << std::endl;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, title);
        if (title.size() == 0 || title.size() > 30)
        {
            cout << Color::RED << "You made a mistake" << Color::RESET << std::endl;
            continue;
        }
        if (!checkingAscii(title, 0))
        {
            cout << Color::RED << "You made a mistake" << Color::RESET << std::endl;
            continue;
        }
        break;
    }
    this->setTitle(title);
    string s;
    int day, month, year;
    while (1)
    {
        cout << "Type the datein this format [ddmmyyyy]" << std::endl;
        cin >> s;
        day = stoi(s.substr(0, 2));
        month = stoi(s.substr(2, 2));
        year = stoi(s.substr(4, 4));
        break;
    }
    Date date2;
    date2.setDay(day);
    date2.setMonth(month);
    date2.setYear(year);
    this->setRDate(date2);

    Euro euro;
    string e, b;
    while (1)
    { // not sure about this code
        cout << "Type the price of the book" << std::endl;
        cin >> e;
        b = split(e, '.', 0);
        if (b == "")
        {
            cout << Color::RED << "there was a mistake" << Color::RESET << std::endl;
            continue;
        }
        euro.setIntegerPart(stoi(b));
        int pos = e.find_first_of('.');
        b = split(e, e.at(e.size()), pos);
        if (b == "")
        {
            cout << Color::RED << "there was a mistake" << Color::RESET << std::endl;
            continue;
        }
        euro.setDecimalPart(stoi(b));
        break;
    }
    this->setPrice(euro);
}

vector<int> Writes::findLName(const string &name)
{
    vector<int> pos;
    int id = -1, count = 0;
    list<Writes> wList;
    list<Author> aList;
    int numWrites = Writes::readWritesTxt(wList);
    if (numWrites <= 0)
    {
        pos.push_back(-1);
        return pos;
    }
    int numAuthors = Author::readAuthorTxt(aList);
    if (numAuthors <= 0)
    {
        pos.push_back(-1);
        return pos;
    }
    for (auto it = aList.begin(); it != aList.end(); ++it)
    {
        if (it->getSurname() == name)
        {
            id = it->getWriterId();
            break;
        } // in case we have multiple people with the same last name well... we don't check that
    } // maybe a future addition
    if (id != -1)
    {
        for (auto it = wList.begin(); it != wList.end(); ++it)
        {
            if (id == it->getWriterId())
            {
                pos.push_back(count++);
            }
        }
    }
    return pos;
}

void Author::getInput(int numAuthors)
{
    list<Book> bList;
    string firstName, surName;
    cout << Color::CYAN << "<<===================================================>>" << Color::RESET << std::endl;
    while (1)
    {
        cout << "\t>> Type the first Name of the Author <<" << std::endl;
        cin >> firstName;
        if (firstName.size() == 0 || firstName.size() > 15)
        {
            cout << Color::RED << "You made a mistake" << Color::RESET << std::endl;
            continue;
        }
        if (!checkingAscii(firstName, 1))
        {
            cout << Color::RED << "You made a mistake" << Color::RESET << std::endl;
            continue;
        }
        break;
    }

    cout << Color::CYAN << "<<===================================================>>" << Color::RESET << std::endl;
    while (1)
    {
        cout << "\t>> Type the last Name of the Author <<" << std::endl;
        cin >> surName;
        if (surName.size() == 0 || surName.size() > 15)
        {
            cout << Color::RED << "You made a mistake" << Color::RESET << std::endl;
            continue;
        }
        if (!checkingAscii(surName, 1))
        {
            cout << Color::RED << "You made a mistake" << Color::RESET << std::endl;
            continue;
        }
        break;
    }
    this->setName(firstName);
    this->setSurname(surName);
    this->setWriterId(numAuthors);
    int numBooks = Book::readBookTxt(bList);
    if (numBooks == -1)
    {
        Book::createBookTxt();
    }
    if (numBooks < 0)
    {
        numBooks = 0;
    }
    if (numBooks)
    {
        vector<int> pos = Writes::findId(this->getWriterId());
        if (!pos.size())
        {
            cout << "You can't be an author if you have not written a book" << std::endl;
            BookStore bs;                   // not needed in the grand scheme of things
            bs.BookStore::insertNewBook(0); // inserts new book since our author has none
        }
        this->setNumOfBooks(pos.size() + 1);
    }

    // a method that reads writetxt to see how many books our author has written
}

vector<int> Writes::findId(int id)
{
    vector<int> pos;
    list<Book> bList;
    list<Writes> wList;
    int numBooks = Book::readBookTxt(bList);
    int numWrites = Writes::readWritesTxt(wList);
    int count = 0;

    for (auto it = wList.begin(); it != wList.end(); ++it)
    {
        if (it->getWriterId() == id)
        {
            pos.push_back(count);
        }
        count++;
    }
    return pos;
}

//void Author::searchAuthorRecord(){
    
//}

void Author::createAuthorTxt()
{
    std::ofstream create(File::AUTHOR);
    create.close();
}
void Book::createBookTxt()
{
    std::ofstream create(File::BOOK);
    create.close();
}
void Writes::createWritesTxt()
{
    std::ofstream create(File::WRITES);
    create.close();
}

int Author::readAuthorTxt(list<Author> &authorList)
{ // reads the author.txt file
    Author author;

    int size = 0;
    std::ifstream inputFile(File::AUTHOR);
    if (!inputFile.is_open())
    {
        std::cerr << Color::RED << "Could not open author.txt" << Color::RESET << std::endl;
        return -1;
    }
    string line;

    if (!getline(inputFile, line))
    {
        cout << Color::RED << "the file had nothing inside" << Color::RESET << std::endl;
        return -2;
    }
    line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
    line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
    try
    {
        size = stoi(line);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid argument: " << e.what() << "\n";
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Out of range: " << e.what() << "\n";
    }
    if (!size)
    {
        cout << Color::RED << "The file has 0 elements inside it" << Color::RESET << std::endl;
        return -2;
    }
    int num;
    for (int i = 0; i < size; ++i)
    {

        getline(inputFile, line);
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        try
        {
            num = std::stoi(line);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid argument: " << e.what() << "\n";
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Out of range: " << e.what() << "\n";
        }
        author.setWriterId(num);

        getline(inputFile, line);
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        author.setSurname(line);

        getline(inputFile, line);
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        author.setName(line);

        getline(inputFile, line);
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        try
        {
            num = std::stoi(line);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid argument: " << e.what() << "\n";
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Out of range: " << e.what() << "\n";
        }
        author.setNumOfBooks(num);

        authorList.push_back(author);
    }

    inputFile.close();
    return size;
}

int Author::writeAuthorTxt(list<Author> &authorList)
{
    if (!authorList.size())
        return -1;
    std::ofstream write(File::AUTHOR);
    if (!write)
    {
        std::cerr << Color::RED << "Error opening file" << Color::RESET << std::endl;
        return -1;
    }
    write << authorList.size() + "," << std::endl;
    for (auto it = authorList.begin(); it != authorList.end(); ++it)
    {
        write << (*it).toString();
    }
    write.close();
    cout << Color::BGREEN << "The file was written successfully" << Color::RESET << std::endl;
    return 1;
}

int Book::readBookTxt(list<Book> &bookList)
{ // reads the book.txt file
    Book book;
    Date d;
    Euro e;

    int size = 0;
    std::ifstream inputFile(File::BOOK);
    if (!inputFile.is_open())
    {
        std::cerr << Color::RED << "Could not open book.txt" << Color::RESET << std::endl;
        return -1;
    }
    string line;

    if (!getline(inputFile, line))
    {
        cout << Color::RED << "the file had nothing inside" << Color::RESET << std::endl;
        return -1;
    }
    line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
    line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
    try
    {
        size = stoi(line);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid argument: " << e.what() << "\n";
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Out of range: " << e.what() << "\n";
    }

    if (!size)
    {
        cout << Color::RED << "The file has 0 elements inside it" << Color::RESET << std::endl;
        return -2;
    }
    int day, month, year;
    string b;
    for (int i = 0; i < size; ++i)
    {

        getline(inputFile, line);
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        book.setTitle(line);

        getline(inputFile, line);
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        try
        {
            day = stoi(line.substr(0, 2));
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid argument: " << e.what() << "\n";
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Out of range: " << e.what() << "\n";
        }
        try
        {
            month = stoi(line.substr(2, 2));
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid argument: " << e.what() << "\n";
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Out of range: " << e.what() << "\n";
        }
        try
        {
            year = stoi(line.substr(4, 4));
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid argument: " << e.what() << "\n";
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Out of range: " << e.what() << "\n";
        }
        d.setDay(day);
        d.setMonth(month);
        d.setYear(year);
        book.setRDate(d);

        getline(inputFile, line);
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        auto pos = b.find('.');
        if (pos == string::npos)
            std::cerr << "error" << std::endl;
        try
        {
            e.setIntegerPart(stoi(b.substr(0, pos)));
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid argument: " << e.what() << "\n";
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Out of range: " << e.what() << "\n";
        }
        try
        {
            e.setDecimalPart(stoi(b.substr(pos + 1)));
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid argument: " << e.what() << "\n";
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Out of range: " << e.what() << "\n";
        }

        book.setPrice(e);

        bookList.push_back(book);
    }

    inputFile.close();
    return size;
}

int Book::writeBookTxt(list<Book> &bookList)
{
    if (!bookList.size())
        return -1;
    std::ofstream write(File::BOOK);
    if (!write)
    {
        std::cerr << Color::RED << "Error opening file" << Color::RESET << std::endl;
        return -1;
    }
    write << bookList.size() + "," << std::endl;
    for (auto it = bookList.begin(); it != bookList.end(); ++it)
    {
        write << (*it).toString();
    }
    write.close();
    cout << Color::BGREEN << "The file was written successfully" << Color::RESET << std::endl;
    return 1;
}

int Writes::readWritesTxt(list<Writes> &writesList)
{ // reads the writes.txt file
    Writes writes;

    int size = 0;
    std::ifstream inputFile(File::WRITES);
    if (!inputFile.is_open())
    {
        std::cerr << Color::RED << "Could not open Writes.txt" << Color::RESET << std::endl;
        return -1;
    }
    string line;

    if (!getline(inputFile, line))
    {
        cout << Color::RED << "the file had nothing inside" << Color::RESET << std::endl;
        return -2;
    }
    line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
    line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
    size = stoi(line);
    if (!size)
    {
        cout << Color::RED << "The file has 0 elements inside it" << Color::RESET << std::endl;
        return -2;
    }
    int num;
    for (int i = 0; i < size; ++i)
    {

        getline(inputFile, line);
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        writes.setTitle(line);

        getline(inputFile, line);
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        writes.setWriterId(stoi(line));

        writesList.push_back(writes);
    }

    inputFile.close();
    return size;
}