#include <QCoreApplication>
#include "stock.h"
#include "stockfactory.h"
#include "stocklist.h"
#include <QTextStream>
#include <QObject>
static QTextStream cout(stdout);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    StockFactory sf;
    Stock* c1 = sf.createStock("Confectionery", "Kit Kat", 12, 65);
    Stock* c2 = sf.createStock("Confectionery", "Bar One", 15, 55);
    Stock* c3 = sf.createStock("Confectionery", "Choclote Log", 11, 70);
    Stock* rm1 = sf.createStock("ReadingMaterial", "The Star", 100, "Daily");
    Stock* rm2 = sf.createStock("ReadingMaterial", "Die Burger", 70, "Daily");
    Stock* rm3 = sf.createStock("ReadingMaterial", "The Times", 100, "Monthly");




    cout << c1->toString() << endl;
    cout << c2->toString() << endl;
    cout << c3->toString() << endl;
    cout << rm1->toString() << endl;
    cout << rm2->toString() << endl;
    cout << rm3->toString() << endl;

    cout << "\n\n" << endl;
    cout << "After calling returnlist from StockList class: \n" << endl;

    StockList* st = StockList::getInstance();
    st->addStock(c1);
    st->addStock(c2);
    st->addStock(c3);
    st->addStock(rm1);
    st->addStock(rm2);
    st->addStock(rm3);

    QList<Stock*> cList = st->returnList("Confectionery");
    for (int i=0; i<cList.size(); i++)
    cout << cList.at(i)->toString() << endl;
    return a.exec();
}
