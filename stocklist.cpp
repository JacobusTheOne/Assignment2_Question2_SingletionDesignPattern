#include "stocklist.h"
#include <QMetaProperty>
#include <QTextStream>
#include <QObjectList>

QTextStream cout(stdout);


StockList* StockList::m_Instance = nullptr;

StockList* StockList::getInstance()
{
    if(!m_Instance)
    {
        m_Instance = new StockList();
    }
    return m_Instance;
}

void StockList::addStock(Stock *st)
{

    if(st->objectName()=="Confectionery")
    {
       confList.append(st);
    }
    else if(st->objectName()=="ReadingMaterial")
    {
       readList.append(st);
    }

}

QList<Stock *> StockList::returnList(QString stockType)
{
    if(stockType=="Confectionery")
    {
        return confList;
    }
    else
    {
        return readList;
    }


}
