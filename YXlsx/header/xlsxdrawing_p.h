// xlsxdrwaing_p.h

#ifndef XLSX_DRAWING_H
#define XLSX_DRAWING_H

#include <QList>
#include <QString>

#include "xlsxabstractooxmlfile.h"

class QIODevice;
class QXmlStreamWriter;

QT_BEGIN_NAMESPACE_XLSX

class DrawingAnchor;
class Workbook;
class AbstractSheet;
class MediaFile;

class Drawing : public AbstractOOXmlFile {
public:
    Drawing(AbstractSheet* sheet, CreateFlag flag);
    ~Drawing();
    void saveToXmlFile(QIODevice* device) const override;
    bool loadFromXmlFile(QIODevice* device) override;

    AbstractSheet* sheet;
    Workbook* workbook;
    QList<DrawingAnchor*> anchors;
};

QT_END_NAMESPACE_XLSX

#endif // XLSX_DRAWING_H
