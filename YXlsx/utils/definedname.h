/*
 * MIT License
 *
 * Copyright (c) 2024 YTX
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef YXLSX_DEFINEDNAME_H
#define YXLSX_DEFINEDNAME_H

#include "namespace.h"
QT_BEGIN_NAMESPACE_YXLSX

struct DefinedName {
    DefinedName()
        : sheet_id { -1 }
    {
    }

    DefinedName(const QString& name, const QString& formula, const QString& comment, int sheet_id = -1)
        : name { name }
        , formula { formula }
        , comment { comment }
        , sheet_id { sheet_id }
    {
    }

    QString name {};
    QString formula {};
    QString comment {};
    // using internal sheet_id, instead of the localSheetId(order in the workbook)
    int sheet_id {};
};

QT_END_NAMESPACE_YXLSX
#endif // YXLSX_DEFINEDNAME_H