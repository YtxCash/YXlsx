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

#include "zipwriter.h"

QT_BEGIN_NAMESPACE_YXLSX

ZipWriter::ZipWriter(const QString& file_path)
    : writer_ { new QZipWriter(file_path, QIODevice::WriteOnly) }
{
    writer_->setCompressionPolicy(QZipWriter::AutoCompress);
}

ZipWriter::ZipWriter(QIODevice* device)
    : writer_ { new QZipWriter(device) }
{
    writer_->setCompressionPolicy(QZipWriter::AutoCompress);
}

ZipWriter::~ZipWriter() { }

bool ZipWriter::Error() const { return writer_->status() != QZipWriter::NoError; }

void ZipWriter::AddFile(const QString& file_path, QIODevice* device) { writer_->addFile(file_path, device); }

void ZipWriter::AddFile(const QString& file_path, const QByteArray& data) { writer_->addFile(file_path, data); }

void ZipWriter::Close() { writer_->close(); }

QT_END_NAMESPACE_YXLSX