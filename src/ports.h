// Copyright (C) 2014 Sacha Refshauge

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 3.0.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 3.0 for more details.

// A copy of the GPL 3.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official GIT repository and contact information can be found at
// http://github.com/xsacha/Sachesi

#pragma once

// For portability between platforms and Qt versions.
// Clears up the code in the more important files.

#include <QFileDialog>
#include <QListView>
#include <QTreeView>
#include <QDesktopServices>
#include <QSettings>
#include <QUrl>
#ifdef BLACKBERRY
#include <bb/cascades/pickers/FilePicker>
#include <bb/system/Clipboard>
#endif

#if QT_VERSION >= 0x050000
#include <QUrlQuery>
#define encodedQuery query(QUrl::FullyEncoded).toUtf8
#else
typedef QUrl QUrlQuery;
#endif

#ifdef BLACKBERRY
typedef bb::cascades::pickers::FilePicker* FileSelect;
#else
typedef QFileDialog* FileSelect;
#endif

FileSelect selectFiles(QString title, QString dir, QString nameString, QString nameExt);
QString getSaveDir();
void openFile(QString name);