// xlsxzipreader_p.h

#ifndef XLSX_XLSXZIPREADER_P_H
#define XLSX_XLSXZIPREADER_P_H

#include <QIODevice>
#include <QScopedPointer>
#include <QStringList>
#include <QVector>

#include "xlsxglobal.h"

class QZipReader;

QT_BEGIN_NAMESPACE_XLSX

class ZipReader {
public:
    explicit ZipReader(const QString& fileName);
    explicit ZipReader(QIODevice* device);
    ~ZipReader();
    bool exists() const;
    QStringList filePaths() const;
    QByteArray fileData(const QString& fileName) const;

private:
    Q_DISABLE_COPY(ZipReader)
    void init();
    QScopedPointer<QZipReader> m_reader;
    QStringList m_filePaths;
};

QT_END_NAMESPACE_XLSX

#endif // XLSX_XLSXZIPREADER_P_H
