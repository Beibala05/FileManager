#pragma once

#include <QApplication>
#include <QListWidget>
#include <QMainWindow>
#include <QWidget>
#include <QListWidgetItem>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QMouseEvent>
#include <QEvent>
#include <QTextBrowser>
#include <QDebug>
#include <QString>
#include <QFileInfo>
#include <QObject>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QFileInfoList>
#include <QLineEdit>
#include <QClipboard>
#include <QResizeEvent>
#include <QIcon>
#include <QPixmap>
#include <QSize>
#include <QFont>

#include <iostream>
#include <vector>
#include <cstdlib>

#define UI_MINIMUM_WIDTH            1400
#define UI_MINIMUM_HEIGHT           800
#define TEXT_EDITOR_START_WIDTH     1200
#define TEXT_EDITOR_START_HEIGHT    800
#define MESSAGE_START_WIDTH         410
#define MESSAGE_START_HEIGHT        150

using App               = QApplication;
using Window            = QMainWindow;
using ListWidget        = QListWidget;
using FileInfo          = QFileInfo;
using Dir               = QDir;
using LineEdit          = QLineEdit;
using FileInfoList      = QFileInfoList;
using File              = QFile;
using ListWidgetItem    = QListWidgetItem;
using Widget            = QWidget;
using Button            = QPushButton;
using Text              = QLabel;
using TextEdit          = QTextEdit;
using TextBrowser       = QTextBrowser;
using String            = QString;
using ResizeEvent       = QResizeEvent;
using Icon              = QIcon;
using Pixmap            = QPixmap;
using Font              = QFont;
using Size              = QSize;

#include "../../icons/icons_pack.h"