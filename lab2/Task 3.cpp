#include <iostream>
using namespace std;

class Item
{
public:
    virtual void display() = 0;
};

class Book : public Item
{
private:
    string title, author;
    int pages;

public:
    Book() {}

    Book(string t, string a, int p)
    {
        title = t;
        author = a;
        pages = p;
    }

    string getTitle()
    {
        return title;
    }

    int getPages()
    {
        return pages;
    }

    void display()
    {
        cout << "\nBook: " << title << "\nAuthor: " << author << "\nPages: " << pages << endl;
    }
};

class News : public Item
{
private:
    string name, date, edition;

public:
    News() {}

    News(string n, string d, string e)
    {
        name = n;
        date = d;
        edition = e;
    }

    string getName()
    {
        return name;
    }

    string getEdition()
    {
        return edition;
    }

    void display()
    {
        cout << "\nNews: " << name << "\nDate: " << date << "\nEdition: " << edition << endl;
    }
};

class Library
{
private:
    Book books[10];
    News news[10];
    int bookCount = 0;
    int newsCount = 0;

public:

    void addBook(Book b)
    {
        books[bookCount++] = b;
    }

    void addNews(News n)
    {
        news[newsCount++] = n;
    }

    void displayCollection()
    {
        cout << "\nBooks:\n";
        for (int i = 0;i < bookCount;i++)
            books[i].display();

        cout << "\nNewspapers:\n";
        for (int i = 0;i < newsCount;i++)
            news[i].display();
    }

    void sortBooksByPages()
    {
        for (int i = 0;i < bookCount - 1;i++)
        {
            for (int j = i + 1;j < bookCount;j++)
            {
                if (books[i].getPages() > books[j].getPages())
                {
                    Book temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
    }

    void sortNewsByEdition()
    {
        for (int i = 0;i < newsCount - 1;i++)
        {
            for (int j = i + 1;j < newsCount;j++)
            {
                if (news[i].getEdition() > news[j].getEdition())
                {
                    News temp = news[i];
                    news[i] = news[j];
                    news[j] = temp;
                }
            }
        }
    }

    Book* searchBookByTitle(string t)
    {
        for (int i = 0;i < bookCount;i++)
        {
            if (books[i].getTitle() == t)
                return &books[i];
        }
        return 0;
    }

    News* searchNewsByName(string n)
    {
        for (int i = 0;i < newsCount;i++)
        {
            if (news[i].getName() == n)
                return &news[i];
        }
        return 0;
    }
};

int main()
{
    Book b1("RRR", "XYZ", 111);
    Book b2("AAA", "YYY", 222);

    News n1("JEO NEWS", "2024-10-13", "Morning Edition");
    News n2("ARY NEWS", "2024-10-12", "Weekend Edition");

    Library lib;

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addNews(n1);
    lib.addNews(n2);

    cout << "Before Sorting:\n";
    lib.displayCollection();

    lib.sortBooksByPages();
    lib.sortNewsByEdition();

    cout << "\nAfter Sorting:\n";
    lib.displayCollection();

    Book* fb = lib.searchBookByTitle("The Catcher in the Rye");

    if (fb)
    {
        cout << "\nFound Book:\n";
        fb->display();
    }
    else
        cout << "\nBook not found\n";

    News* fn = lib.searchNewsByName("The Times");

    if (fn)
    {
        cout << "\nFound Newspaper:\n";
        fn->display();
    }
    else
        cout << "\nNewspaper not found\n";

    return 0;
}