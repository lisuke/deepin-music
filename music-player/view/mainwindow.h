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

#include <DWindow>
#include <QScopedPointer>

#include "../core/playlist.h"
#include "widget/thinwindow.h"

class Presenter;
class MusicListWidget;
class MainWindowPrivate;
class MainWindow : public ThinWindow
{
    Q_OBJECT
    Q_PROPERTY(QString coverBackground READ coverBackground WRITE setCoverBackground)
    Q_PROPERTY(QString viewname READ viewname WRITE setViewname NOTIFY viewnameChanged)


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initUI();

    void initMusiclist(PlaylistPtr allmusic, PlaylistPtr last);
    void initPlaylist(QList<PlaylistPtr > playlists, PlaylistPtr last);
    void initFooter(PlaylistPtr current, int mode);
    void binding(Presenter *presenter);

    QString viewname() const;

signals:
    void addPlaylist(bool editmode);
    void importSelectFiles(const QStringList &filelist);
    void viewnameChanged(QString viewname);

public slots:
    void onSelectImportFiles();
    void onCurrentPlaylistChanged(PlaylistPtr playlist);
    void toggleLyricView();
    void togglePlaylist();
    void showLyricView();
    void showMusicListView();
    void showImportView();
    void showTips(QPixmap icon, QString text);
    void setPlaylistVisible(bool visible);
    void setViewname(QString viewname);

protected:
    virtual bool eventFilter(QObject *obj, QEvent *e) Q_DECL_OVERRIDE;
    virtual void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    virtual void resizeEvent(QResizeEvent *e) Q_DECL_OVERRIDE;
    virtual void paintEvent(QPaintEvent *e) Q_DECL_OVERRIDE;

private:
    void changeToMusicListView(bool keepPlaylist);

    void disableControl(int delay = 350);
    void updateViewname(const QString &vm);

    QScopedPointer<MainWindowPrivate> d;
};
