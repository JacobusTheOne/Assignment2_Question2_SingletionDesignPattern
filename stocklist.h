#ifndef STOCKLIST_H
#define STOCKLIST_H
#include <QList>
#include <QObject>
#include "stock.h"

class StockList
{
public:
    static StockList* getInstance();
    void addStock(Stock* st);
    QList<Stock *> returnList(QString stockType);
private:
    StockList(){};
    static StockList* m_Instance;
    QList<Stock*> confList;
    QList<Stock*> readList;

};

#endif // STOCKLIST_H
