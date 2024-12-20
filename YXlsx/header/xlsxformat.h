// xlsxformat.h

#ifndef XLSX_FORMAT_H
#define XLSX_FORMAT_H

#include <QByteArray>
#include <QColor>
#include <QExplicitlySharedDataPointer>
#include <QFont>
#include <QList>
#include <QVariant>

#include "xlsxglobal.h"

class FormatTest;

QT_BEGIN_NAMESPACE_XLSX

class Worksheet;
class WorksheetPrivate;
class RichStringPrivate;
class SharedStrings;

class FormatPrivate;

class Format {
public:
    enum FontScript { FontScriptNormal, FontScriptSuper, FontScriptSub };

    enum FontUnderline { FontUnderlineNone, FontUnderlineSingle, FontUnderlineDouble, FontUnderlineSingleAccounting, FontUnderlineDoubleAccounting };

    enum HorizontalAlignment { AlignHGeneral, AlignLeft, AlignHCenter, AlignRight, AlignHFill, AlignHJustify, AlignHMerge, AlignHDistributed };

    enum VerticalAlignment { AlignTop, AlignVCenter, AlignBottom, AlignVJustify, AlignVDistributed };

    enum BorderStyle {
        BorderNone,
        BorderThin,
        BorderMedium,
        BorderDashed,
        BorderDotted,
        BorderThick,
        BorderDouble,
        BorderHair,
        BorderMediumDashed,
        BorderDashDot,
        BorderMediumDashDot,
        BorderDashDotDot,
        BorderMediumDashDotDot,
        BorderSlantDashDot
    };

    enum DiagonalBorderType { DiagonalBorderNone, DiagonalBorderDown, DiagonalBorderUp, DiagnoalBorderBoth };

    enum FillPattern {
        PatternNone,
        PatternSolid,
        PatternMediumGray,
        PatternDarkGray,
        PatternLightGray,
        PatternDarkHorizontal,
        PatternDarkVertical,
        PatternDarkDown,
        PatternDarkUp,
        PatternDarkGrid,
        PatternDarkTrellis,
        PatternLightHorizontal,
        PatternLightVertical,
        PatternLightDown,
        PatternLightUp,
        PatternLightTrellis,
        PatternGray125,
        PatternGray0625,
        PatternLightGrid
    };

    Format();
    Format(const Format& other);
    Format& operator=(const Format& rhs);
    ~Format();

    int numberFormatIndex() const;
    void setNumberFormatIndex(int format);
    QString numberFormat() const;
    void setNumberFormat(const QString& format);
    void setNumberFormat(int id, const QString& format);
    bool isDateTimeFormat() const;

    int fontSize() const;
    void setFontSize(int size);
    bool fontItalic() const;
    void setFontItalic(bool italic);
    bool fontStrikeOut() const;
    void setFontStrikeOut(bool);
    bool fontBold() const;
    void setFontBold(bool bold);
    FontScript fontScript() const;
    void setFontScript(FontScript);
    FontUnderline fontUnderline() const;
    void setFontUnderline(FontUnderline);
    bool fontOutline() const;
    void setFontOutline(bool outline);
    QString fontName() const;
    void setFontName(const QString&);
    QFont font() const;
    void setFont(const QFont& font);

    HorizontalAlignment horizontalAlignment() const;
    void setHorizontalAlignment(HorizontalAlignment align);
    VerticalAlignment verticalAlignment() const;
    void setVerticalAlignment(VerticalAlignment align);
    bool textWrap() const;
    void setTextWrap(bool textWrap);
    int rotation() const;
    void setRotation(int rotation);
    int indent() const;
    void setIndent(int indent);
    bool shrinkToFit() const;
    void setShrinkToFit(bool shink);

    void setBorderStyle(BorderStyle style);
    BorderStyle leftBorderStyle() const;
    void setLeftBorderStyle(BorderStyle style);
    BorderStyle rightBorderStyle() const;
    void setRightBorderStyle(BorderStyle style);
    BorderStyle topBorderStyle() const;
    void setTopBorderStyle(BorderStyle style);
    BorderStyle bottomBorderStyle() const;
    void setBottomBorderStyle(BorderStyle style);
    BorderStyle diagonalBorderStyle() const;
    void setDiagonalBorderStyle(BorderStyle style);
    DiagonalBorderType diagonalBorderType() const;
    void setDiagonalBorderType(DiagonalBorderType style);

    FillPattern fillPattern() const;
    void setFillPattern(FillPattern pattern);

    bool locked() const;
    void setLocked(bool locked);
    bool hidden() const;
    void setHidden(bool hidden);

    void mergeFormat(const Format& modifier);
    bool isValid() const;
    bool isEmpty() const;

    bool operator==(const Format& format) const;
    bool operator!=(const Format& format) const;

    QVariant property(int propertyId, const QVariant& defaultValue = QVariant()) const;
    void setProperty(int propertyId, const QVariant& value, const QVariant& clearValue = QVariant(), bool detach = true);
    void clearProperty(int propertyId);
    bool hasProperty(int propertyId) const;

    bool boolProperty(int propertyId, bool defaultValue = false) const;
    int intProperty(int propertyId, int defaultValue = 0) const;
    double doubleProperty(int propertyId, double defaultValue = 0.0) const;
    QString stringProperty(int propertyId, const QString& defaultValue = QString()) const;

    bool hasNumFmtData() const;
    bool hasFontData() const;
    bool hasFillData() const;
    bool hasBorderData() const;
    bool hasAlignmentData() const;
    bool hasProtectionData() const;

    bool fontIndexValid() const;
    int fontIndex() const;
    QByteArray fontKey() const;
    bool borderIndexValid() const;
    QByteArray borderKey() const;
    int borderIndex() const;
    bool fillIndexValid() const;
    QByteArray fillKey() const;
    int fillIndex() const;

    QByteArray formatKey() const;
    bool xfIndexValid() const;
    int xfIndex() const;
    bool dxfIndexValid() const;
    int dxfIndex() const;

    void fixNumberFormat(int id, const QString& format);
    void setFontIndex(int index);
    void setBorderIndex(int index);
    void setFillIndex(int index);
    void setXfIndex(int index);
    void setDxfIndex(int index);

private:
    friend class ::FormatTest;
    friend QDebug operator<<(QDebug, const Format& f);

    int theme() const;

    QExplicitlySharedDataPointer<FormatPrivate> d;
};

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug dbg, const Format& f);
#endif

QT_END_NAMESPACE_XLSX

#endif // XLSX_FORMAT_H
