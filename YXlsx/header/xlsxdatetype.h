// xlsxdatetype.h

#ifndef XLSX_XLSXDATETYPE_H
#define XLSX_XLSXDATETYPE_H

#include <QDate>
#include <QDateTime>
#include <QObject>
#include <QString>
#include <QStringList>
#include <QTime>

#include "xlsxglobal.h"

QT_BEGIN_NAMESPACE_XLSX

class QXLSX_EXPORT DateType {
public:
    DateType();
    /*
        DateType(bool is1904 = false);
        DateType(double d, bool is1904 = false);
        DateType(QDateTime qdt, bool is1904 = false);
        DateType(QDate qd, bool is1904 = false);
        DateType(QTime qt, bool is1904 = false);
    public:
        enum currentDateType { DateAndTimeType, OnlyDateType, OnlyTimeType };
    public:
        currentDateType getType();
        bool getValue(QDateTime* pQdt);
        bool getValue(QDate* pQd);
        bool getValue(QTime* pQt);
        bool getValue(double* pD);

    protected:

    protected:
        bool isSet;
        double dValue;
        bool is1904Type;
        currentDateType dType;
    */
};

QT_END_NAMESPACE_XLSX
#endif
