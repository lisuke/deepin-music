/*
 * Copyright (C) 2016 ~ 2018 Wuhan Deepin Technology Co., Ltd.
 *
 * Author:     Iceyer <me@iceyer.net>
 *
 * Maintainer: Iceyer <me@iceyer.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "libdmusic_global.h"

#include <QObject>
#include <QString>
#include <QSharedPointer>

class QFileInfo;

class LIBDMUSICSHARED_EXPORT MediaMeta
{
public:
    QString hash;
    QString localPath;
    QString cuePath;
    QString title;
    QString artist;
    QString album;

    QString pinyinTitle;
    QString pinyinTitleShort;
    QString pinyinArtist;
    QString pinyinArtistShort;
    QString pinyinAlbum;
    QString pinyinAlbumShort;

    QString filetype;

    qint64  timestamp   = 0;    // addTime;

    qint64  offset      = 0;    //msec
    qint64  length      = 1;    //msec
    qint64  track       = 0;
    qint64  size        = 1;
    QString editor;
    QString composer;
    QString creator;

    QString searchID;

    bool    favourite   = false;
    bool    invalid     = false;

public:
    void updateSearchIndex();
    void updateCodec(const QByteArray &codec);

    static MediaMeta fromLocalFile(const QFileInfo &fileInfo);
};

typedef QSharedPointer<MediaMeta>   MetaPtr;
typedef QList<MetaPtr>              MetaPtrList;

Q_DECLARE_METATYPE(MediaMeta)
Q_DECLARE_METATYPE(MetaPtr)
Q_DECLARE_METATYPE(MetaPtrList)

namespace DMusic
{

QString LIBDMUSICSHARED_EXPORT filepathHash(const QString &filepath);
QString LIBDMUSICSHARED_EXPORT sizeString(qint64 sizeByte);
QString LIBDMUSICSHARED_EXPORT lengthString(qint64 length);
QList<QByteArray> LIBDMUSICSHARED_EXPORT detectMetaEncodings(MetaPtr meta);

}


